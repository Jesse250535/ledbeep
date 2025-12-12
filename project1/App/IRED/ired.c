#include "ired.h"

void ired_init0(void)
{
	IT0=1;	
	EX0=1;
	EA=1;
	ired1=1;

}

void ired() interrupt 0
{

	u8 ired_high_time = 0;
	u16 time_cnt = 0;
	u8 i=0,j=0;
	
	if(ired1==0)
	{
		time_cnt=1000;
		while((!ired1)&&(time_cnt))
		{
			delay_10us(1);
			time_cnt--;
			if(time_cnt == 0) return;
		}

		if(ired1)
		{
			time_cnt=500;
			while(ired1&&time_cnt)
			{
				delay_10us(1);
				time_cnt--;
				if(time_cnt==0) return;
			}

			for(i=0;i<4;i++)
			{
				for(i=0;i<8;i++)
				{
					time_cnt=600;
					while((ired==0)&&time_cnt)
					{
						delay_10us(1);
						time_cnt--;
						if(time_cnt==0) return;
					}

					time_cnt=20;
					while(ired)
					{
						delay_10us(10);
						ired_high_time++;
						if(ired_high_time>20) return;
					}
					gired_data[i]>>=1;
					if(ired_high_time>=8)
					gired_data[i]|=0x80;
					ired_high_time=0;		
				}	
			}
		
		}
		if(gired_data[2]!=~gired_data[3])
		{
			for(i=0;i<4;i++)
			{
				gired_data[i]=0;
				return;
			}
		}
			
	}	

}