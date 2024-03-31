/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    i2c.c
  * @brief   This file provides code for the configuration
  *          of the I2C instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "i2c.h"

/* USER CODE BEGIN 0 */
#define		GT911_DIV_ID	0XBA	//???? //0X28 //0XBA

#define 	GT911_DIV_W		(GT911_DIV_ID | 0)	//???
#define 	GT911_DIV_R		(GT911_DIV_ID | 1)	//???



//GT911 ??????? 
#define GT_CTRL_REG 	0X8040   	//GT911?????
#define GT_CFGS_REG 	0X8047   	//GT911?????????
#define GT_CHECK_REG 	0X80FF   	//GT911??????
#define GT_PID_REG 		0X8140   	//GT911??ID???
 
#define GT_GSTID_REG 	0X814E   	//GT911??????????,?7???????,?4????????

#define GT_TPD_Sta		0X8150		//?????????
#define GT_TP1_REG 		0X8150  	//??????????
#define GT_TP2_REG 		0X8158		//??????????
#define GT_TP3_REG 		0X8160		//??????????
#define GT_TP4_REG 		0X8168		//??????????
#define GT_TP5_REG 		0X8170		//??????????
#define GT_TOUCH_MAX			5			//??gt911,??????5???????
typedef enum
{
	X_L = 0,
	X_H = 1,
	Y_L = 2,
	Y_H = 3,
	S_L	= 4,
	S_H = 5
}Data_XYS_P;	//??X?Y??????????
uint8_t touchpad_get_xy(int32_t * x, int32_t * y)
{
    /*Your code comes here*/
			int32_t x_temp;
		int32_t y_temp;
		uint8_t _temp;
		HAL_I2C_Mem_Read(&hi2c2, GT911_DIV_R, GT_GSTID_REG, I2C_MEMADD_SIZE_16BIT, &_temp, 1, 0xff);
	if(_temp&0x80){
		HAL_I2C_Mem_Read(&hi2c2, GT911_DIV_R, (GT_TPD_Sta  + X_L), I2C_MEMADD_SIZE_16BIT, &_temp, 1, 0xff);
		x_temp  = _temp;
		HAL_I2C_Mem_Read(&hi2c2, GT911_DIV_R, (GT_TPD_Sta  + X_H), I2C_MEMADD_SIZE_16BIT, &_temp, 1, 0xff);
		x_temp |= (_temp<<8);

		HAL_I2C_Mem_Read(&hi2c2, GT911_DIV_R, (GT_TPD_Sta  + Y_L), I2C_MEMADD_SIZE_16BIT, &_temp, 1, 0xff);
		y_temp  = _temp;
		HAL_I2C_Mem_Read(&hi2c2, GT911_DIV_R, (GT_TPD_Sta  + Y_H), I2C_MEMADD_SIZE_16BIT, &_temp, 1, 0xff);
		y_temp |= (_temp<<8);
			_temp=0;
		HAL_I2C_Mem_Write(&hi2c2, GT911_DIV_W, GT_GSTID_REG, I2C_MEMADD_SIZE_16BIT, &_temp, 1, 0xff);
		(*x) = x_temp;
		(*y) = y_temp;
			return 1;
	}else
	{
	return 0;
	}
}
/* USER CODE END 0 */

I2C_HandleTypeDef hi2c2;

/* I2C2 init function */
void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.Timing = 0x00B03FDB;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */
    HAL_GPIO_WritePin(LCD_TOUCH_RES_GPIO_Port, LCD_TOUCH_RES_Pin, GPIO_PIN_RESET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(LCD_TOUCH_RES_GPIO_Port, LCD_TOUCH_RES_Pin, GPIO_PIN_SET);
  /* USER CODE END I2C2_Init 2 */

}

void HAL_I2C_MspInit(I2C_HandleTypeDef* i2cHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(i2cHandle->Instance==I2C2)
  {
  /* USER CODE BEGIN I2C2_MspInit 0 */

  /* USER CODE END I2C2_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_I2C2;
    PeriphClkInitStruct.I2c123ClockSelection = RCC_I2C123CLKSOURCE_D2PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_RCC_GPIOH_CLK_ENABLE();
    /**I2C2 GPIO Configuration
    PH4     ------> I2C2_SCL
    PH5     ------> I2C2_SDA
    */
    GPIO_InitStruct.Pin = LCD_TOUCH_SCL_Pin|LCD_TOUCH_SDA_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C2;
    HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

    /* I2C2 clock enable */
    __HAL_RCC_I2C2_CLK_ENABLE();
  /* USER CODE BEGIN I2C2_MspInit 1 */

  /* USER CODE END I2C2_MspInit 1 */
  }
}

void HAL_I2C_MspDeInit(I2C_HandleTypeDef* i2cHandle)
{

  if(i2cHandle->Instance==I2C2)
  {
  /* USER CODE BEGIN I2C2_MspDeInit 0 */

  /* USER CODE END I2C2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C2_CLK_DISABLE();

    /**I2C2 GPIO Configuration
    PH4     ------> I2C2_SCL
    PH5     ------> I2C2_SDA
    */
    HAL_GPIO_DeInit(LCD_TOUCH_SCL_GPIO_Port, LCD_TOUCH_SCL_Pin);

    HAL_GPIO_DeInit(LCD_TOUCH_SDA_GPIO_Port, LCD_TOUCH_SDA_Pin);

  /* USER CODE BEGIN I2C2_MspDeInit 1 */

  /* USER CODE END I2C2_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
