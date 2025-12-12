#include "smg.h"
#include "ired.h"
#include "public.h"


void main()
{
	u8 ired_buf[3];

	ired_init();//红外初始化

	while(1)
	{
		ired_buf[0]=gsmg_code[gired_data[2]/16];//将控制码高 4 位转换为数码
		ired_buf[1]=gsmg_code[gired_data[2]%16];//将控制码低 4 位转换为数码
		ired_buf[2]=0x76;//显示 H 的段码
		smg_display(ired_buf,6);
		if((ired_buf[0]==0x71)&&(ired_buf[1]==0x71))
		{
			beep_on();
			delay_10us(60);
		}
		if((ired_buf[0]==0x06)&&(ired_buf[1]==0x39))
		{
			led2_on();
		}else{
			led2_off();
		}


	}

}