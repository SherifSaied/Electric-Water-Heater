/*
 * _7seg.c
 *
 * Created: 2022-11-15 11:46:33 PM
 *  Author: pc
 */ 
#include "sevenseg.h"

void seven_init (void) 
{
	DDRA|=(1<<0); // tens digit bit output
	DDRA|=(1<<1); // tens digit bit
	DDRA|=(1<<2); // tens digit bit
	DDRA|=(1<<3); // tens digit bit
	DDRA|=(1<<4); // toggling bit
	DDRC|=(1<<0); // unit digit bit
	DDRC|=(1<<1); // unit digit bit
	DDRC|=(1<<2); // unit digit bit
	DDRC|=(1<<3); // unit digit bit
}
void disp (uint8_t temp)
{
	PORTA |=(1<<4);
	char left= temp / 10;
	char right= temp % 10;
	PORTA|=left ;
	PORTC|=right ;

}