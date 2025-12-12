#include "beep.h"

void beep_on()
{
	beep=!beep;
	delay_10us(60);
}