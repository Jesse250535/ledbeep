#ifndef _ired_H
#define _ired_H

#include "public.h"

sbit ired1 = P3^2;

extern u8 gired_data[4];

void ired_init0(void);

#endif