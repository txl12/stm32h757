/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    i2c.h
  * @brief   This file contains all the function prototypes for
  *          the i2c.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __I2C_H__
#define __I2C_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern I2C_HandleTypeDef hi2c2;

/* USER CODE BEGIN Private defines */
#define		GT911_DIV_ID	0XBA	//设备地址 //0X28 //0XBA

#define 	GT911_DIV_W		(GT911_DIV_ID | 0)	//写地址
#define 	GT911_DIV_R		(GT911_DIV_ID | 1)	//读地址



//GT911 部分寄存器定义 
#define GT_CTRL_REG 	0X8040   	//GT911控制寄存器
#define GT_CFGS_REG 	0X8047   	//GT911配置起始地址寄存器
#define GT_CHECK_REG 	0X80FF   	//GT911校验和寄存器
#define GT_PID_REG 		0X8140   	//GT911产品ID寄存器
 
#define GT_GSTID_REG 	0X814E   	//GT911当前检测到的触摸情况,第7位是触摸标志位，低4位是触摸点数个数

#define GT_TPD_Sta		0X8150		//触摸点起始数据地址
#define GT_TP1_REG 		0X8150  	//第一个触摸点数据地址
#define GT_TP2_REG 		0X8158		//第二个触摸点数据地址
#define GT_TP3_REG 		0X8160		//第三个触摸点数据地址
#define GT_TP4_REG 		0X8168		//第四个触摸点数据地址
#define GT_TP5_REG 		0X8170		//第五个触摸点数据地址
#define GT_TOUCH_MAX			5			//对于gt911，最多同时获取5个触摸点的数据


typedef enum
{
	X_L = 0,
	X_H = 1,
	Y_L = 2,
	Y_H = 3,
	S_L	= 4,
	S_H = 5
}Data_XYS_P;	//数据X、Y、触摸大小数据偏移量

typedef enum
{
	TOUCH__NO		= 0x00,	//没有触摸
	TOUCH_ING		= 0x80	//被触摸	
}TOUCH_STATE_enum;	//触摸状态

typedef struct
{
	uint16_t	X_Point;	//X坐标
	uint16_t	Y_Point;	//Y坐标
	uint16_t	S_Point;	//触摸点大小
}XY_Coordinate;	//触摸点坐标


/*触摸结构体*/
typedef struct 
{
    uint8_t Touch_Interrpute; //触摸中断
	uint8_t Touch_State;	//触摸状态
	uint8_t Touch_Number;	//触摸数量
	XY_Coordinate Touch_XY[GT_TOUCH_MAX];	//触摸的x坐标，对于gt911最多5个点的坐标
}Touch_Struct;	//触摸信息结构体

/*外部变量区*/
extern Touch_Struct	User_Touch;
/* USER CODE END Private defines */

void MX_I2C2_Init(void);

/* USER CODE BEGIN Prototypes */
void gt911_Scanf(void);
void gt911_Init(void);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __I2C_H__ */

