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
#define		GT911_DIV_ID	0XBA	//�豸��ַ //0X28 //0XBA

#define 	GT911_DIV_W		(GT911_DIV_ID | 0)	//д��ַ
#define 	GT911_DIV_R		(GT911_DIV_ID | 1)	//����ַ



//GT911 ���ּĴ������� 
#define GT_CTRL_REG 	0X8040   	//GT911���ƼĴ���
#define GT_CFGS_REG 	0X8047   	//GT911������ʼ��ַ�Ĵ���
#define GT_CHECK_REG 	0X80FF   	//GT911У��ͼĴ���
#define GT_PID_REG 		0X8140   	//GT911��ƷID�Ĵ���
 
#define GT_GSTID_REG 	0X814E   	//GT911��ǰ��⵽�Ĵ������,��7λ�Ǵ�����־λ����4λ�Ǵ�����������

#define GT_TPD_Sta		0X8150		//��������ʼ���ݵ�ַ
#define GT_TP1_REG 		0X8150  	//��һ�����������ݵ�ַ
#define GT_TP2_REG 		0X8158		//�ڶ������������ݵ�ַ
#define GT_TP3_REG 		0X8160		//���������������ݵ�ַ
#define GT_TP4_REG 		0X8168		//���ĸ����������ݵ�ַ
#define GT_TP5_REG 		0X8170		//��������������ݵ�ַ
#define GT_TOUCH_MAX			5			//����gt911�����ͬʱ��ȡ5�������������


typedef enum
{
	X_L = 0,
	X_H = 1,
	Y_L = 2,
	Y_H = 3,
	S_L	= 4,
	S_H = 5
}Data_XYS_P;	//����X��Y��������С����ƫ����

typedef enum
{
	TOUCH__NO		= 0x00,	//û�д���
	TOUCH_ING		= 0x80	//������	
}TOUCH_STATE_enum;	//����״̬

typedef struct
{
	uint16_t	X_Point;	//X����
	uint16_t	Y_Point;	//Y����
	uint16_t	S_Point;	//�������С
}XY_Coordinate;	//����������


/*�����ṹ��*/
typedef struct 
{
    uint8_t Touch_Interrpute; //�����ж�
	uint8_t Touch_State;	//����״̬
	uint8_t Touch_Number;	//��������
	XY_Coordinate Touch_XY[GT_TOUCH_MAX];	//������x���꣬����gt911���5���������
}Touch_Struct;	//������Ϣ�ṹ��

/*�ⲿ������*/
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

