#include "beep.h"

void beep_on()
{
	beep=!beep;
	delay_10us(60);
}

void beep_off()
{
	beep=0;
	delay_10us(60);

}