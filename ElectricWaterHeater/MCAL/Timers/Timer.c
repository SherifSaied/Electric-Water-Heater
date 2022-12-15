/*
 * Timer.c
 *
 * Created: 2022-12-04 10:37:29 AM
 *  Author: pc
 */ 

#include "Timer.h"
/*******************************************************************************/
/*timer0_init() : to initialize timer(0) to trigger INT every 100ms to get Temp.                                                               */
/*******************************************************************************/
void timer0_init(void)
{
	//choose normal ovf mode
	TCCR0 &= (~(1<<6)) ;
	TCCR0 &= (~(1<<3)) ;
	TCCR0 &= (~(1<<5)) ;
	TCCR0 &= (~(1<<4)) ;

	//set prescaler to 64
	TCCR0 |= (1<<0) ;
	TCCR0 |= (1<<1) ;
	TCCR0 &= (~(1<<2)) ;

	//SREG |= (1<<7); // enable global interrupt
	sei(); // enable global interrupt
	TIMSK |= (1<<0); // enable overflow interrupt
	
	/*//choose mode CTC for generate interrupt each time the cnt value reaches the TOP value by using OCF0 flag
	TCCR0 |= (1<<WGM01) ;
	TCCR0 &= ~(1<<WGM00) ;
	
	//choose prescaler 1024 with 16Mhz freq. system
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS00);
	
	//load value for OCR0 from 
	OCR0=250 // kda no of overflow eli 3ayzo for 100ms is 4
	
	//enable Timer INT
	//compare match interrupt enable
	sei();
	SET_BIT(TIMSK,OCIE0) ;*/
	
}

void timer1_init(void)
{
	// normal ovf mode
	TCCR1A &= (~(1<<4)) ;
	TCCR1A &= (~(1<<5)) ;
	TCCR1A &= (~(1<<6)) ;
	TCCR1A &= (~(1<<7)) ;
	TCCR1A &= (~(1<<0)) ;
	TCCR1A &= (~(1<<1)) ;
	TCCR1B &= (~(1<<3)) ;
	TCCR1B &= (~(1<<4)) ;

	// prescaler 1024
	TCCR1B |=(1<<0);
	TCCR1B &= (~(1<<1));
	TCCR1B |= (1<<2);

}

void timer2_init(void)
{
	// normal mode
	TCCR2 &=(~(1<<3)) ;
	TCCR2 &=(~(1<<6));

	//oc2 disconnected
	TCCR2 &=(~(1<<4));
	TCCR2 &=(~(1<<5));

	// prescaler 1024
	TCCR2 |= (1<<0);
	TCCR2 |= (1<<1);
	TCCR2 |= (1<<2);
}

