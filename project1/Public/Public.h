#ifndef _public_H
#define _public_H

#include "reg52.h"


typedef unsigned int u16;	//对系统默认数据类型进行重定义
typedef unsigned char u8;



void delay_10us(u16 a);
void delay_ms(u16 ms);

#endif