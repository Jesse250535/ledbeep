#ifndef _beep_H
#define _beep_H

#include "public.h"

sbit beep = P2^5;
void beep_on();
void beep_off();

#endif