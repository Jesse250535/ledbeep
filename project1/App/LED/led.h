#ifndef _led_H
#define _led_H

#include "public.h"

sbit led2 = P2^1;
sbit led1 = P2^0;

sbit led7 = P2^6;
sbit led8 = P2^7;

void led2_on();
void led2_off();

void led1_on();
void led1_off();

void led7_on();
void led7_off();

void led8_on();
void led8_off();



#endif