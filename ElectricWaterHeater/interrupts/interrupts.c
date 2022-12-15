/*
 * CFile1.c
 *
 * Created: 2022-12-15 5:49:38 PM
 *  Author: pc
 */ 

#include "interrupts.h"


void Enable_INT2 (void)
{
	SREG |=(1<<7); // enable global interrupt
	GICR |=(1<<5);   // enable module int 2
	MCUCSR &=(~(1<<6)); // " on/off " button  status register set ( data sheet)
}
void Enable_INT0 (void)
{
	SREG |=(1<<7); // enable global interrupt
	GICR |=(1<<6);   // enable module int 0
	MCUCR |=(1<<1);      // " UP " button  status register set ( data sheet)
	MCUCR &=(~(1<<0));   // " UP " button  status register set ( data sheet)
}

void Enable_INT1 (void)
{
	SREG |=(1<<7); // enable global interrupt
	GICR |=(1<<7);   // enable module int 1
	MCUCR |=(1<<3);      // " DOWN " button  status register set ( data sheet)
	MCUCR &=(~(1<<2));   // " DOWN " button  status register set ( data sheet)
}

