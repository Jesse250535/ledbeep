#ifndef _beep_H
#define _beep_H

#include "reg52.h"

sbit beep = P2^5;
void beep_on();

#endif