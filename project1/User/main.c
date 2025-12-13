#include "smg.h"
#include "ired.h"
#include "lcd1602.h"
#include "public.h"


void main()
{
	u8 ired_buf[3];
	u8 key = 0;

	ired_init();//红外初始化
	lcd1602_init();//LCD1602初始化
	lcd1602_show_string(0,0,"Hello World!");//第一行显示
	lcd1602_show_string(0,1,"0123456789");//第二行显示

	while(1)
	{
		ired_buf[0]=gsmg_code[gired_data[2]/16];//将控制码高 4 位转换为数码
		ired_buf[1]=gsmg_code[gired_data[2]%16];//将控制码低 4 位转换为数码
		ired_buf[2]=0x76;//显示 H 的段码
		smg_display(ired_buf,6);
		if((ired_buf[0]==0x3f)&&(ired_buf[1]==0x39))
		{
			beep_on();
		}else{
			led2_off();
		}


		if((ired_buf[0]==0x3f)&&(ired_buf[1]==0x5b))
		{
			led2_on();
		}else{
			led2_off();
		}

		if((ired_buf[0]==0x3f)&&(ired_buf[1]==0x06))
		{
			led1_on();
		}else{
			led1_off();
		}

		if((ired_buf[0]==0x3f)&&(ired_buf[1]==0x07))
		{
			led7_on();
		}else{
			led7_off();
		}
		
		if((ired_buf[0]==0x3f)&&(ired_buf[1]==0x7f))
		{
			led8_on();
		}else{
			led8_off();
		}

		if((ired_buf[0]==0x3f)&&(ired_buf[1]==0x7d))
		{
			led8_on();
			delay_10us(100000);
			led8_off();
			delay_10us(100000);
		}


	}

}