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
/* IIC???? */
#define FT5206_CMD_WR               0X70
#define FT5206_CMD_RD               0X71 

/* FT5206 ???????  */
#define FT5206_DEVIDE_MODE          0x00        /* FT5206??????? */
#define FT5206_REG_NUM_FINGER       0x02        /* ??????? */

#define FT5206_TP1_REG              0X03        /* ?????????? */
#define FT5206_TP2_REG              0X09        /* ?????????? */
#define FT5206_TP3_REG              0X0F        /* ?????????? */
#define FT5206_TP4_REG              0X15        /* ?????????? */
#define FT5206_TP5_REG              0X1B        /* ?????????? */


#define FT5206_ID_G_LIB_VERSION     0xA1        /* ?? */
#define FT5206_ID_G_MODE            0xA4        /* FT5206?????????160 */
#define FT5206_ID_G_THGROUP         0x80        /* ?????????? */
#define FT5206_ID_G_PERIODACTIVE    0x88        /* ??????????? */
uint8_t ft5206_wr_reg(uint16_t reg, uint8_t *buf, uint8_t len)
{

//		HAL_I2C_Master_Transmit(&hi2c2,FT5206_CMD_WR,buf,len,100);
	HAL_I2C_Mem_Write(&hi2c2, FT5206_CMD_WR, reg, I2C_MEMADD_SIZE_8BIT,buf,len, 1000);
    return 0;
}
void ft5206_rd_reg(uint16_t reg, uint8_t *buf, uint8_t len)
{
//	HAL_I2C_Master_Receive(&hi2c2,FT5206_CMD_RD,buf,len,100);
	HAL_I2C_Mem_Read(&hi2c2, FT5206_CMD_WR, reg, I2C_MEMADD_SIZE_8BIT,buf,len, 1000);
		
}
uint8_t touchpad_get_xy(uint16_t * x, uint16_t * y)
{
    /*Your code comes here*/
	 uint8_t status = 0;
	uint8_t ret=0;
    ft5206_rd_reg(0x02, &status, 1);
    if ( status ){
				HAL_GPIO_TogglePin(LCD_BLK_GPIO_Port,LCD_BLK_Pin);
			uint8_t buf[4];
    ft5206_rd_reg(0x03, buf, 4);
    (*y) = ((uint16_t)(buf[0] & 0X0F) << 8) + buf[1];
    (*x) = (((uint16_t)(buf[2] & 0X0F) << 8) + buf[3]);
			
        ret= 1;
		}
		
    return ret;
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
  hi2c2.Init.Timing = 0x307075B1;
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
  HAL_GPIO_WritePin(LCD_TOUCH_RES_GPIO_Port, LCD_TOUCH_RES_Pin, GPIO_PIN_SET);
			uint8_t temp[1];

    temp[0] = 0;
        ft5206_wr_reg(FT5206_DEVIDE_MODE, temp, 1); /* ???????? */
        ft5206_wr_reg(FT5206_ID_G_MODE, temp, 1);   /* ???? */
        temp[0] = 12;                               /* ?????,22,????? */
        ft5206_wr_reg(FT5206_ID_G_THGROUP, temp, 1);/* ??????? */
        temp[0] = 12;                               /* ????,????12,??14 */
        ft5206_wr_reg(FT5206_ID_G_PERIODACTIVE, temp, 1);
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
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
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
