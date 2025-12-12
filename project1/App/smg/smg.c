#include "smg.h"

//共阴极数码管显示0~F的段码数据
u8 gsmg_code[17]={0x3f/*0*/,0x06/*1*/,0x5b/*2*/,0x4f/*3*/,
				0x66/*4*/,0x6d/*5*/,0x7d/*6*/,0x07/*7*/,
				0x7f/*8*/,0x6f/*9*/,0x77/*a*/,0x7c/*b*/,
				0x39/*c*/,0x5e/*d*/,0x79/*e*/,0x71/*f*/};

void smg_display(u8 dat[],u8 pos)
{
	u8 i=0;
	u8 pos_temp=pos-1;

	for(i=pos_temp;i<8;i++)
	{
	   	switch(i)//位选
		{
			case 0: LSC=1;LSB=1;LSA=1;break;
			case 1: LSC=1;LSB=1;LSA=0;break;
			case 2: LSC=1;LSB=0;LSA=1;break;
			case 3: LSC=1;LSB=0;LSA=0;break;
			case 4: LSC=0;LSB=1;LSA=1;break;
			case 5: LSC=0;LSB=1;LSA=0;break;
			case 6: LSC=0;LSB=0;LSA=1;break;
			case 7: LSC=0;LSB=0;LSA=0;break;
		}
		SMG_A_DP_PORT=dat[i-pos_temp];//传送段选数据
		delay_10us(100);//延时一段时间，等待显示稳定
		SMG_A_DP_PORT=0x00;//消音
	}
}
