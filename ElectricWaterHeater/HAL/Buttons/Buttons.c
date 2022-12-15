/*
 * Buttons.c
 *
 * Created: 2022-12-15 5:37:06 PM
 *  Author: pc
 */ 
#include "Buttons.h"
#include <avr/io.h>

void Button_init (void)
{
	DDRB &=(~(1<<2)); //set on/off button as input
	DDRD &=(~(1<<2)); //set " up " button as input
	DDRD &=(~(1<<3)); //set " down " button as input
	
}