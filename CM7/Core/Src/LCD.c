#include "stm32h7xx_hal.h"
#include "LCD.h"
 void LCD_delay(volatile int time)  //�������ʱ
{
HAL_Delay(time);
}
void GPIO_RGB_INIT(void)
{

}
static void LCD_Reset(void)
{
	//ע�⣬���ڿ�ѧ����е������ø�λҲ��
		LCD_RST(0);
//    LCD_delay(200);					   
    LCD_RST(1);		 	 
//    LCD_delay(200);					   

}
void LCD_WriteByteSPI(unsigned char byte)
{
//	HAL_SPI_Transmit(&hspi4,&byte,1,100);
	    unsigned char n;
   
    for(n=0; n<8; n++)			
    {  
        if(byte&0x80) SPI_SDA(1);
        else SPI_SDA(0);
        byte<<= 1;
        SPI_DCLK(0);
        SPI_DCLK(1);
    }
}
void SPI_WriteComm(u16 CMD)//3��8bit ���нӿ�
{			
	LCD_SPI_CS(0);
	LCD_WriteByteSPI(0x70);
	LCD_WriteByteSPI(CMD);
	LCD_SPI_CS(1);
}
void SPI_WriteData(u16 tem_data)
{			
	LCD_SPI_CS(0);
	LCD_WriteByteSPI(0x72);
	LCD_WriteByteSPI(tem_data);
	LCD_SPI_CS(1);
}
void Lcd_Initialize(void)	//LCD��ʼ������
{
    LCD_SPI_CS(1);
//    LCD_delay(20);
    LCD_SPI_CS(0);
    LCD_Reset();

		SPI_WriteComm(0x20);//exit_invert_mode
		SPI_WriteComm(0x29);//set_display_on

		SPI_WriteComm(0xB1);//RGB Interface Setting
		SPI_WriteData(0x00);
		SPI_WriteData(0x14);
		SPI_WriteData(0x06);

		SPI_WriteComm(0xB2);//Panel Characteristics Setting
		SPI_WriteData(0x10);//480 pixels
		SPI_WriteData(0xC8);//800 pixels

		SPI_WriteComm(0xB3);//Panel Drive Setting    Set the inversion mode


		SPI_WriteData(0x00);//1-dot inversion 0x01

		SPI_WriteComm(0xB4);//Display Mode Control
		SPI_WriteData(0x04);//Dither disable.

		SPI_WriteComm(0xB5);//Display Mode and Frame Memory Write Mode Setting
		SPI_WriteData(0x10);
		SPI_WriteData(0x30);
		SPI_WriteData(0x30);
		SPI_WriteData(0x00);
		SPI_WriteData(0x00);

		SPI_WriteComm(0xB6);//Display Control 2 ( GIP Specific )
		SPI_WriteData(0x01);
		SPI_WriteData(0x18);
		SPI_WriteData(0x02);
		SPI_WriteData(0x40);
		SPI_WriteData(0x10);
		SPI_WriteData(0x00);

		SPI_WriteComm(0xc0);
		SPI_WriteData(0x01);
		SPI_WriteData(0x18);


		SPI_WriteComm(0xC3); 
		SPI_WriteData(0x03);
		SPI_WriteData(0x04);
		SPI_WriteData(0x03);
		SPI_WriteData(0x03);
		SPI_WriteData(0x03);

//		LCD_delay(10);

		SPI_WriteComm(0xC4);//VDD Regulator setting
		SPI_WriteData(0x02);
		SPI_WriteData(0x23);//GDC AP
		SPI_WriteData(0x11);//VRH1  Vreg1out=1.533xVCI(10)
		SPI_WriteData(0x12);//VRH2  Vreg2out=-1.533xVCI(10)
		SPI_WriteData(0x02);//BT 5 VGH/VGL  6/-4
		SPI_WriteData(0x77);//DDVDH 6C//0x56
		LCD_delay(10);

		SPI_WriteComm(0xC5);
		SPI_WriteData(0x73);
		LCD_delay(10);

		SPI_WriteComm(0xC6);
		SPI_WriteData(0x24);//VCI 23
		SPI_WriteData(0x60);//RESET RCO 53
		SPI_WriteData(0x00);//SBC GBC
//		LCD_delay(10);
		//GAMMA SETTING
		SPI_WriteComm(0xD0);
		SPI_WriteData(0x14);
		SPI_WriteData(0x01);
		SPI_WriteData(0x53);
		SPI_WriteData(0x25);
		SPI_WriteData(0x02);
		SPI_WriteData(0x02);
		SPI_WriteData(0x66);
		SPI_WriteData(0x14);
		SPI_WriteData(0x03);

		SPI_WriteComm(0xD1);
		SPI_WriteData(0x14);
		SPI_WriteData(0x01);
		SPI_WriteData(0x53);
		SPI_WriteData(0x07);
		SPI_WriteData(0x02);
		SPI_WriteData(0x02);
		SPI_WriteData(0x66);
		SPI_WriteData(0x14);
		SPI_WriteData(0x03);



		SPI_WriteComm(0xD2);
		SPI_WriteData(0x14);
		SPI_WriteData(0x01);
		SPI_WriteData(0x53);
		SPI_WriteData(0x25);
		SPI_WriteData(0x02);
		SPI_WriteData(0x02);
		SPI_WriteData(0x66);
		SPI_WriteData(0x14);
		SPI_WriteData(0x03);

		SPI_WriteComm(0xD3);
		SPI_WriteData(0x14);
		SPI_WriteData(0x01);
		SPI_WriteData(0x53);
		SPI_WriteData(0x07);
		SPI_WriteData(0x02);
		SPI_WriteData(0x02);
		SPI_WriteData(0x66);
		SPI_WriteData(0x14);
		SPI_WriteData(0x03);


		SPI_WriteComm(0xD4);
		SPI_WriteData(0x14);
		SPI_WriteData(0x01);
		SPI_WriteData(0x53);
		SPI_WriteData(0x25);
		SPI_WriteData(0x02);
		SPI_WriteData(0x02);
		SPI_WriteData(0x66);
		SPI_WriteData(0x14);
		SPI_WriteData(0x03);

		SPI_WriteComm(0xD5);
		SPI_WriteData(0x14);
		SPI_WriteData(0x01);
		SPI_WriteData(0x53);
		SPI_WriteData(0x07);
		SPI_WriteData(0x02);
		SPI_WriteData(0x02);
		SPI_WriteData(0x66);
		SPI_WriteData(0x14);
		SPI_WriteData(0x03);
		SPI_WriteComm(0x11);

//		LCD_delay(10);

		SPI_WriteComm(0x3A); SPI_WriteData(0x60);//set_pixel_format 0X60 26k 01010000
		SPI_WriteComm(0x29);SPI_WriteComm(0x2c);
		
		SPI_WriteComm(0x36);
#if LCD_RGB_ORIENTATION //�Ƿ���ת90��
 SPI_WriteData(0x02);
#else
 SPI_WriteData(0x00);
#endif
}
void LTDC_Clock_Set(void)	//����LTDCʱ��
{

}

/**********************************************
��������Lcd������亯��

��ڲ�����xStart x�������ʼ��
          ySrart y�������ֹ��
          xLong Ҫѡ�����ε�x���򳤶�
          yLong  Ҫѡ�����ε�y���򳤶�
����ֵ����
***********************************************/
//void Lcd_ColorBox(u16 xStart,u16 yStart,u16 xLong,u16 yLong,u16 Color)
//{
//#if LCD_RGB_ORIENTATION //�Ƿ���ת90��
////  u16 i,j;
////	u32 temp;
////	temp = YSIZE_PHYS*xStart;
////	for(i=0;i<yLong;i++)
////	{
////		for(j=0;j<xLong;j++)
////		LTDC_Buf[yStart+i+YSIZE_PHYS*j+temp]=Color;
////	}
//#else
//	u16*LTDC_Buf=0x24000000;
//  u16 i,j;
//	u32 temp;
//	temp = XSIZE_PHYS*yStart;
//	for(i=0;i<yLong;i++)
//	{
//		for(j=0;j<xLong;j++)
//		LTDC_Buf[xStart+j+XSIZE_PHYS*i+temp]=Color;
//	}
//#endif
//}
void LCD_Initial(void)
{
	GPIO_RGB_INIT();//��ʼ��Һ�������GPIO
	LTDC_Clock_Set();
	Lcd_Initialize();
	LCD_SPI_CS(1);
	Lcd_Light_ON;//�򿪱���
}
///******************************************
//��������Lcdͼ�����100*100
//���ܣ���Lcdָ��λ�����ͼ��
//��ڲ�����
//******************************************/
//void LCD_Fill_Pic(u16 x, u16 y,u16 pic_H, u16 pic_V, u16* pic)
//{
//#if LCD_RGB_ORIENTATION //�Ƿ���ת90��
////  u16 i,j;
////	u32 Xstart,k=0;
////	Xstart = YSIZE_PHYS*x;
////	for(i=0;i<pic_V;i++)
////	{
////		for(j=0;j<pic_H;j++)
////		LTDC_Buf[Xstart+i+YSIZE_PHYS*j+y]=pic[k++];
////	}
//#else
//	u16*LTDC_Buf=0x24000000;
//  u16 i,j;
//	u32 Ystart,k=0;
//	Ystart = XSIZE_PHYS*y;
//	for(i=0;i<pic_V;i++)
//	{
//		for(j=0;j<pic_H;j++)
//		LTDC_Buf[x+j+XSIZE_PHYS*i+Ystart]=pic[k++];
//	}
//#endif
//}
////=============== ��x��y �����ϴ�һ����ɫΪColor�ĵ� ===============
//void DrawPixel(u16 x, u16 y, int Color)
//{
//#if LCD_RGB_ORIENTATION //�Ƿ���ת90��
// LTDC_Buf[y+YSIZE_PHYS*x] = Color;
//#else
// LTDC_Buf[x+XSIZE_PHYS*y] = Color;
//#endif
//}
////------------------------------------------------------------------------------------------------------------
////------------------------------------------------------------------------------------------------------------
////8*16���� ASCII�� ��ʾ
////��������SPILCD_ShowChar
////��  ����
////(x,y):
////num:Ҫ��ʾ���ַ�:" "--->"~"
////flag:�б���ɫ(1)�ޱ���ɫ(0)
//void SPILCD_ShowChar(unsigned short x,unsigned short y,unsigned char num, unsigned int fColor, unsigned int bColor,unsigned char flag)
//{
//	unsigned char temp;
//	unsigned int pos,i,j;
//
//	num=num-' ';//�õ�ƫ�ƺ��ֵ
//	i=num*16;
//	for(pos=0;pos<16;pos++)
//		{
//			temp=nAsciiDot[i+pos];	//��ͨ����ASCII����
//			for(j=0;j<8;j++)
//		   {
//		        if(temp&0x80)
//							DrawPixel(x+j,y,fColor);
//						else
//							if(flag) DrawPixel(x+j,y,bColor); //�������ɫ��־flagΪ1
//							temp<<=1;
//		    }
//			 y++;
//		}
//}

//дһ��16x16�ĺ���
//void PutGB1616(unsigned short x, unsigned short  y, unsigned char c[2], unsigned int fColor,unsigned int bColor,unsigned char flag)
//{
//	unsigned int i,j,k;
//	unsigned short m;
//	for (k=0;k<64;k++) { //64��ʾ�Խ����ֿ��еĸ�����ѭ����ѯ����
//	  if ((codeGB_16[k].Index[0]==c[0])&&(codeGB_16[k].Index[1]==c[1]))
//			{ 
//    	for(i=0;i<32;i++) 
//			{
//				m=codeGB_16[k].Msk[i];
//				for(j=0;j<8;j++) 
//				{		
//					if((m&0x80)==0x80) {
//						DrawPixel(x+j,y,fColor);
//						}
//					else {
//						if(flag) DrawPixel(x+j,y,bColor);
//						}
//					m=m<<1;
//				} 
//				if(i%2){y++;x=x-8;}
//				else x=x+8;
//		  }
//		}  
//	  }	
//	}

////��ʾһ����
//void LCD_PutString(unsigned short x, unsigned short y, char *s, unsigned int fColor, unsigned int bColor,unsigned char flag) 
//	{
//		unsigned char l=0;
//		while(*s) 
//			{
//				if( *s < 0x80) 
//						{
//							SPILCD_ShowChar(x+l*8,y,*s,fColor,bColor,flag);
//							s++;l++;
//						}
//				else
//						{
//							PutGB1616(x+l*8,y,(unsigned char*)s,fColor,bColor,flag);
//							s+=2;l+=2;
//						}
//			}
//	}
////дһ��n*n�ĺ���
//void Put_GB_n(unsigned short x, unsigned short y, unsigned char c[2], unsigned int fColor,unsigned int bColor,unsigned char flag,unsigned int n)
//{
//	unsigned int i,j,k,a=0;
//	unsigned short m;
//	for (k=0;k<12;k++) { //12��ʾ�Խ����ֿ��еĸ�����ѭ����ѯ����
//	  if ((codeGB_48[k].Index[0]==c[0])&&(codeGB_48[k].Index[1]==c[1]))
//			{ 
//    	for(i=0;i<((n*n)>>3);i++) 
//			{
//				for(a=0;a<(n>>3);a++)
//				{
//					m=codeGB_48[k].Msk[i+a];
//					for(j=0;j<8;j++) 
//					{		
//						if((m&0x80)==0x80) {
//							DrawPixel(x+j,y,fColor);
//							}
//						else {
//							if(flag) DrawPixel(x+j,y,bColor);
//							}
//						m=m<<1;
//					} 
//					 x=x+8;
//				}
//				i = i+a-1;
//				y++;x=x-8*a;
//		  }
//		}  
//	  }	
//	}
////��ʾһ�����֣��ֺ�Ϊn
//void LCD_PutString_GB_n(unsigned short x, unsigned short y, char *s, unsigned int fColor, unsigned int bColor,unsigned char flag,unsigned int n) 
//	{
//		unsigned int l=0;
//		while(*s) 
//			{
//				Put_GB_n(x+l,y,(unsigned char*)s,fColor,bColor,flag,n);
//				s+=2;l+=n;;
//			}
//	}
