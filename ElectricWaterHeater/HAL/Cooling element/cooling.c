/*
 * cooling.c
 *
 * Created: 2022-12-15 5:41:53 PM
 *  Author: pc
 */ 

#include "cooling.h"
#include <avr/io.h>
void cooling_init (void)
{
	DDRD |= (1<<1); // set fan as output
	
	
	PORTD &=(~(1<<1));  //intialization to port by zero
}