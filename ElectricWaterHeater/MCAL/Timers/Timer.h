/*
 * Timer.h
 *
 * Created: 2022-12-04 10:37:20 AM
 *  Author: pc
 */ 
#include "../../Utilities/Bit_Math.h"
#include "../../Utilities/REG.h"
#include "../../Utilities/typedefs.h"


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>

void timer0_init(void);
void timer1_init(void);
void timer2_init(void) ;
/*void timer1_INT_disable();
void timer1_INT_enable();*/

#endif /* TIMER_H_ */