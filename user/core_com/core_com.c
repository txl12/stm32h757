#include "core_com/core_com.h"
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#ifndef HSEM_ID_1
#define HSEM_ID_1 (1U) /* HW semaphore 0*/
#endif
static __IO uint8_t Notif_Recieved=0;
static const struct share_mem mem = {.share_mem_add = 0x38000000,.share_mem_size = 32*1024,.end_offset = 0};
void HSEM1_IRQHandler(void)
{
  HAL_HSEM_IRQHandler();	  
}

void HAL_HSEM_FreeCallback(uint32_t SemMask)
{
  Notif_Recieved = 1;
//my_printf("HAL_HSEM_FreeCallback\n");
} 
#include "adc.h"
void StartDefaultTask(void *argument)
{

static	unsigned int adc_v;
static double adcx;
static double temp;
 	HAL_ADCEx_Calibration_Start(&hadc3,ADC_CALIB_OFFSET,ADC_SINGLE_ENDED);
  for(;;)
  {
    osDelay(2000);
HAL_ADC_Start(&hadc3);
adc_v = HAL_ADC_GetValue(&hadc3);
		adcx = (110.0-30.0)/(*(unsigned short*)(0x1FF1E840) - *(unsigned short*)(0x1FF1E820));
		temp = adcx*(adc_v - *(unsigned short*)(0x1FF1E820))+30;
		my_printf("cm7 tick %d,temp %lf C\n",HAL_GetTick(),temp);
  }
  /* USER CODE END StartDefaultTask */
}

 void core_com(void *argument)
{
  /* USER CODE BEGIN core_com */
	Notif_Recieved =0;
	__HAL_HSEM_CLEAR_FLAG(__HAL_HSEM_SEMID_TO_MASK(HSEM_ID_1));
	  HAL_NVIC_SetPriority(HSEM1_IRQn, 10, 0);
  HAL_NVIC_EnableIRQ(HSEM1_IRQn);  
	
	    HAL_HSEM_ActivateNotification(__HAL_HSEM_SEMID_TO_MASK(HSEM_ID_1));
  /* Infinite loop */
  for(;;)
  {
		if(Notif_Recieved == 1){
			if(HAL_HSEM_Take(HSEM_ID_1,2) == HAL_OK){

				my_printf("recieve cm4 msg:%s\n",(char*) mem.share_mem_add);
HAL_HSEM_DeactivateNotification(__HAL_HSEM_SEMID_TO_MASK(HSEM_ID_1));

				HAL_HSEM_Release(HSEM_ID_1,2);
__HAL_HSEM_CLEAR_FLAG(__HAL_HSEM_SEMID_TO_MASK(HSEM_ID_1));
				HAL_HSEM_ActivateNotification(__HAL_HSEM_SEMID_TO_MASK(HSEM_ID_1));
				Notif_Recieved=0;
			}
		}
    osDelay(50);
  }
  /* USER CODE END core_com */
}
