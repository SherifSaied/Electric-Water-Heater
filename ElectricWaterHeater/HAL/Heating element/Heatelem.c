/*
 * Heatelem.c
 *
 * Created: 2022-12-03 2:11:44 AM
 *  Author: pc
 */ 

#include "Heatelem.h"
#include <avr/io.h>

void Heat_init (void)
{
	DDRD |=(1<<0); // set heater as output
	PORTD &=(~(1<<0));  //intialization to port by zero
}
