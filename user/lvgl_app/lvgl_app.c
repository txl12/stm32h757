#include "lvgl_app/lvgl_app.h"
#include <lvgl.h>
#include "porting/lv_port_disp_template.h"
#include "porting/lv_port_indev_template.h"
#include "main.h"
#include "lv_demos.h"
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#define LVGL_TICK 	10
void lvgl_init( void ) 
{
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();
    // lv_port_indev_init();
    // lv_port_fs_init();
    lv_demo_benchmark();
//	lv_demo_keypad_encoder();
//	lv_demo_music();
//	lv_demo_stress();
//	lv_demo_widgets();
//	lv_demo_render();
}

int lvgl_app(void)
{
	lvgl_init();

	while(1) {
		lv_timer_handler();
		HAL_Delay(LVGL_TICK);
	}
}
void lvgl_timer_callback(void *argument)
{
		lv_tick_inc(5);
}
void lvgl_task(void *argument)
{
  /* USER CODE BEGIN lvgl_task */
		lvgl_init();
	
  /* Infinite loop */
  for(;;)
  {

lv_timer_handler();
osDelay(LVGL_TICK);
  }
  /* USER CODE END lvgl_task */
}










