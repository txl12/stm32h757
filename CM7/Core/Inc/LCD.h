//#include "HAL_conf.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#define LCD_RGB_ORIENTATION      0  //ORIENTATION=1��ת90��   Ϊ1�Ǻ�����Ϊ0������

#if LCD_RGB_ORIENTATION //�Ƿ���ת90��
	#define XSIZE_PHYS 800
	#define YSIZE_PHYS 480
#else
	#define XSIZE_PHYS 480
	#define YSIZE_PHYS 800
#endif

#define SPI_SDA(a)	HAL_GPIO_WritePin(GPIOH, GPIO_PIN_5, (GPIO_PinState)(a))
#define SPI_DCLK(a)	HAL_GPIO_WritePin(GPIOH, GPIO_PIN_4, (GPIO_PinState)(a))

#define LCD_SPI_CS(a)	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (GPIO_PinState)(a))

#define LCD_RST(a)	HAL_GPIO_WritePin(GPIOJ, GPIO_PIN_5, (GPIO_PinState)(a))

#define Lcd_Light_ON   HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_SET)
#define Lcd_Light_OFF HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, GPIO_PIN_RESET)

//*************  24λɫ��1600��ɫ������ *************//
//#define WHITE          0xFFFFFF
//#define BLACK          0x000000
//#define BLUE           0x0000FF
//#define BLUE2          0x3F3FFF
//#define RED            0xFF0000
//#define MAGENTA        0xFF00FF
//#define GREEN          0x00FF00
//#define CYAN           0x00FFFF
//#define YELLOW         0xFFFF00					

//*************  16λɫ���� *************//
//#define White          0xFFFF
//#define Black          0x0000
//#define Blue           0x001F
//#define Blue2          0x051F
//#define Red            0xF800
//#define Magenta        0xF81F
//#define Green          0x07E0
//#define Cyan           0x7FFF
//#define Yellow         0xFFE0
						
						

void LCD_Initial(void); //LCD��ʼ������ʱ��
void Lcd_Initialize(void); //LCD��ʼ������
 void LCD_delay(volatile int time);
void WriteComm(unsigned char CMD);
void WriteData(u32 dat);
void LCD_WR_REG(u16 Index,u16 CongfigTemp);
void Lcd_ColorBox(u16 xStart,u16 yStart,u16 xLong,u16 yLong,u16 Color);
//void SPILCD_DrawLine(unsigned short x1,unsigned short y1,unsigned short x2,unsigned short y2,unsigned short color);
//void SPILCD_ShowChar(unsigned short x,unsigned short y,unsigned char num, unsigned int fColor, unsigned int bColor,unsigned char flag) ;
void LCD_PutString(unsigned short x, unsigned short y, char *s, unsigned int fColor, unsigned int bColor,unsigned char flag);
void LCD_Fill_Pic(u16 x, u16 y,u16 pic_H, u16 pic_V, u16* pic);
void LCD_PutString_GB_n(unsigned short x, unsigned short y, char *s, unsigned int fColor, unsigned int bColor,unsigned char flag,unsigned int n);

