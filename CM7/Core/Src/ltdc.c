/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    ltdc.c
  * @brief   This file provides code for the configuration
  *          of the LTDC instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "ltdc.h"

/* USER CODE BEGIN 0 */
#define HBP  20 // ???????????
#define VBP  3
#define HSW  4
#define VSW  3
#define HFP  20
#define VFP  3
#define XSIZE_PHYS 480
#define YSIZE_PHYS 800
/* USER CODE END 0 */

LTDC_HandleTypeDef hltdc;

/* LTDC init function */
void MX_LTDC_Init(void)
{

  /* USER CODE BEGIN LTDC_Init 0 */

  /* USER CODE END LTDC_Init 0 */

  LTDC_LayerCfgTypeDef pLayerCfg = {0};

  /* USER CODE BEGIN LTDC_Init 1 */

  /* USER CODE END LTDC_Init 1 */
  hltdc.Instance = LTDC;
  hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
  hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
  hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
  hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
  hltdc.Init.HorizontalSync = 7;
  hltdc.Init.VerticalSync = 7;
  hltdc.Init.AccumulatedHBP = 167;
  hltdc.Init.AccumulatedVBP = 17;
  hltdc.Init.AccumulatedActiveW = 1191;
  hltdc.Init.AccumulatedActiveH = 617;
  hltdc.Init.TotalWidth = 1351;
  hltdc.Init.TotalHeigh = 637;
  hltdc.Init.Backcolor.Blue = 0;
  hltdc.Init.Backcolor.Green = 0;
  hltdc.Init.Backcolor.Red = 0;
  if (HAL_LTDC_Init(&hltdc) != HAL_OK)
  {
    Error_Handler();
  }
  pLayerCfg.WindowX0 = 0;
  pLayerCfg.WindowX1 = 1024;
  pLayerCfg.WindowY0 = 0;
  pLayerCfg.WindowY1 = 600;
  pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_RGB565;
  pLayerCfg.Alpha = 255;
  pLayerCfg.Alpha0 = 0;
  pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
  pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
  pLayerCfg.FBStartAdress = 0xc0000000;
  pLayerCfg.ImageWidth = 1024;
  pLayerCfg.ImageHeight = 600;
  pLayerCfg.Backcolor.Blue = 0;
  pLayerCfg.Backcolor.Green = 0;
  pLayerCfg.Backcolor.Red = 0;
  if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN LTDC_Init 2 */

  /* USER CODE END LTDC_Init 2 */

}

void HAL_LTDC_MspInit(LTDC_HandleTypeDef* ltdcHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(ltdcHandle->Instance==LTDC)
  {
  /* USER CODE BEGIN LTDC_MspInit 0 */

  /* USER CODE END LTDC_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LTDC;
    PeriphClkInitStruct.PLL3.PLL3M = 25;
    PeriphClkInitStruct.PLL3.PLL3N = 200;
    PeriphClkInitStruct.PLL3.PLL3P = 2;
    PeriphClkInitStruct.PLL3.PLL3Q = 2;
    PeriphClkInitStruct.PLL3.PLL3R = 3;
    PeriphClkInitStruct.PLL3.PLL3RGE = RCC_PLL3VCIRANGE_0;
    PeriphClkInitStruct.PLL3.PLL3VCOSEL = RCC_PLL3VCOWIDE;
    PeriphClkInitStruct.PLL3.PLL3FRACN = 0;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* LTDC clock enable */
    __HAL_RCC_LTDC_CLK_ENABLE();

    __HAL_RCC_GPIOK_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();
    __HAL_RCC_GPIOJ_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOI_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    /**LTDC GPIO Configuration
    PK5     ------> LTDC_B6
    PG10     ------> LTDC_G3
    PK4     ------> LTDC_B5
    PJ15     ------> LTDC_B3
    PD3     ------> LTDC_G7
    PK6     ------> LTDC_B7
    PK3     ------> LTDC_B4
    PK7     ------> LTDC_DE
    PA8     ------> LTDC_R6
    PI11     ------> LTDC_G6
    PC6     ------> LTDC_HSYNC
    PG7     ------> LTDC_CLK
    PI13     ------> LTDC_VSYNC
    PK0     ------> LTDC_G5
    PJ11     ------> LTDC_G4
    PJ9     ------> LTDC_G2
    PJ0     ------> LTDC_R7
    PA5     ------> LTDC_R4
    PJ2     ------> LTDC_R3
    PJ4     ------> LTDC_R5
    */
    GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_3
                          |LTDC_DE_Pin|GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOK, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_LTDC;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_15|GPIO_PIN_11|GPIO_PIN_9|GPIO_PIN_2
                          |GPIO_PIN_4;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOJ, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_3;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_LTDC;
    HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF14_LTDC;
    HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_LTDC;
    HAL_GPIO_Init(GPIOJ, &GPIO_InitStruct);

    /* LTDC interrupt Init */
    HAL_NVIC_SetPriority(LTDC_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(LTDC_IRQn);
  /* USER CODE BEGIN LTDC_MspInit 1 */
//HAL_LTDC_ProgramLineEvent(&hltdc, 0 );			// 设置行中断，第0行
  /* USER CODE END LTDC_MspInit 1 */
  }
}

void HAL_LTDC_MspDeInit(LTDC_HandleTypeDef* ltdcHandle)
{

  if(ltdcHandle->Instance==LTDC)
  {
  /* USER CODE BEGIN LTDC_MspDeInit 0 */

  /* USER CODE END LTDC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_LTDC_CLK_DISABLE();

    /**LTDC GPIO Configuration
    PK5     ------> LTDC_B6
    PG10     ------> LTDC_G3
    PK4     ------> LTDC_B5
    PJ15     ------> LTDC_B3
    PD3     ------> LTDC_G7
    PK6     ------> LTDC_B7
    PK3     ------> LTDC_B4
    PK7     ------> LTDC_DE
    PA8     ------> LTDC_R6
    PI11     ------> LTDC_G6
    PC6     ------> LTDC_HSYNC
    PG7     ------> LTDC_CLK
    PI13     ------> LTDC_VSYNC
    PK0     ------> LTDC_G5
    PJ11     ------> LTDC_G4
    PJ9     ------> LTDC_G2
    PJ0     ------> LTDC_R7
    PA5     ------> LTDC_R4
    PJ2     ------> LTDC_R3
    PJ4     ------> LTDC_R5
    */
    HAL_GPIO_DeInit(GPIOK, GPIO_PIN_5|GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_3
                          |LTDC_DE_Pin|GPIO_PIN_0);

    HAL_GPIO_DeInit(GPIOG, GPIO_PIN_10|GPIO_PIN_7);

    HAL_GPIO_DeInit(GPIOJ, GPIO_PIN_15|GPIO_PIN_11|GPIO_PIN_9|GPIO_PIN_0
                          |GPIO_PIN_2|GPIO_PIN_4);

    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_3);

    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_8|GPIO_PIN_5);

    HAL_GPIO_DeInit(GPIOI, GPIO_PIN_11|GPIO_PIN_13);

    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_6);

    /* LTDC interrupt Deinit */
    HAL_NVIC_DisableIRQ(LTDC_IRQn);
  /* USER CODE BEGIN LTDC_MspDeInit 1 */

  /* USER CODE END LTDC_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
