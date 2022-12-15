/*
 * App.c
 *
 * Created: 2022-12-03 2:14:15 AM
 *  Author: pc
 */ 
#include "App.h"
#include "App_Config.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

 /*counter_timer0=0;
 arr_counter=0;*/
 
 /*----------------------------------------------------------------------------*-
 temp_array_initialization : This function is a part of the Sys_init. function
 that reads the first actual temperature and put it at all elements in the
 temperature array.
 -*----------------------------------------------------------------------------*/
void temp_arr_init(void)
{
	unsigned char first_temp = adc_read();
	unsigned char i ;

	for (i = 0; i<NUM_OF_TEMP_MEASURES; i++)
	{
		temp_arr[i]= first_temp;
	}

	avg_temp = calc_avg_temp(temp_arr);
	arr_counter = 0;
}

 /*void temp_arr_init(void)
 {
	 uint16_t first_temp = ADC_read();
	 
	 for (uint8_t i = 0; i<NUM_OF_TEMP_MEASURES; i++){
		 temp_arr[i]= first_temp;
	 }
	 
	 avg_temp = calc_avg_temp(temp_arr);
	 arr_counter = 0;
 }*/
 
 /*----------------------------------------------------------------------------*-
 add_new_temp : This function is used to add the new measured temperature to
 the temperature array that will have its average during the code.
 -*----------------------------------------------------------------------------*/
 void add_new_temp(uint8_t * arr , uint8_t new_val)
 {
	 arr[arr_counter] = new_val;
	 arr_counter ++;

	 if (arr_counter == 9)
	 {
		 arr_counter = 0;
	 }
 }

 
 /*void add_new_temp(uint16_t * arr , uint16_t new_val){
	 arr[arr_counter] = new_val;
	 arr_counter ++;
	 
	 if (arr_counter == 9)
	 {
		 arr_counter = 0;
	 }
 }*/
 
 /*----------------------------------------------------------------------------*-
ON_state : This is the working state where it does the following:
	- waits for the timer to measure temperature using ADC every 100ms.
	- checks for the UP and DOWN buttons to switch to the SETTING mode.
-*----------------------------------------------------------------------------*/
 
 /*if (temp_measure_f==1)
 {
	 actual_temp = ADC_read();
	 add_new_temp(temp_arr , actual_temp);
	 
	 temp_measure_f = 0;
	 
 }*/
 
 /*----------------------------------------------------------------------------*-
 Calculate_Average_Temp.: to calculate the last 10 measured temperatures.
 -*----------------------------------------------------------------------------*/
uint8_t calc_avg_temp(uint8_t * arr)
{
	unsigned int sum = 0;
	unsigned int avg;
	uint8_t i ;

	for( i=0; i<NUM_OF_TEMP_MEASURES; i++){
		sum = sum + arr[i];
	}
	avg =  sum / NUM_OF_TEMP_MEASURES;

	return (uint8_t)avg ;
}

 /*uint16_t calc_avg_temp(uint16_t * arr){
	 uint16_t sum = 0;
	 uint16_t avg;
	 
	 for(uint8_t i=0; i<NUM_OF_TEMP_MEASURES; i++)
	 {
		 sum = sum + arr[i];
	 }
	 avg = (uint16_t) sum / NUM_OF_TEMP_MEASURES;
	 return avg;
 }*/
 
 void closed(void)
 {
	 PORTA &=(~(1<<4)) ; // shut 7 segment
	 SREG &=(~(1<<7)); // disable global interrupt
	 PORTD &=(~(1<<1)); // shut fan
	 PORTD &=(~(1<<0));//shut heat
	 PORTB &=(~(1<<3)); // shut led
 }
 
 void TempSetMod (uint8_t* Temp)
 {
	 SREG |=(1<<7); // enable global interrupt
	 TIMSK |=(1<<6); // enable timer2 overflow interrupt



	 end=0;
	 ovf=0;
	 while( (!(end)) && state )
	 {

		 right= (*Temp) % 10;
		 left= (*Temp) / 10;
		 PORTA|=(left<<0);
		 PORTC|=(right<<0);
		 PORTA |=(1<<4);
		 _delay_ms(500);
		 PORTA &=(~(1<<4));
		 _delay_ms(500);

	 }

	 TIMSK &=(~(1<<6)); // disable timer2 overflow intrupt
	 GICR &=(~(1<<6));   // disable module int 0
	 GICR &=(~(1<<7));   // disable module int 1
 }

void Operation(void)
{
	if ( CrrTemp <= (SetTemp-5) ) // Check if temp is lower Set temp
	{
		PORTD &=(~(1<<1)); // shut fan
		PORTD |= (1<<0);  // turn heat on
		TIMSK |= (1<<2); // enable timer1

	}

	else if (CrrTemp >=(SetTemp +5)) // Check if temp is higher than Set temp
	{
		PORTD &=(~(1<<0)); //shut heat
		PORTD |= (1<<1); // turn fan on
		TIMSK &= (~(1<<2)); // disable timer1
		PORTB |= (1<<3); // turn led on
	}

	else
	{
		TIMSK &= (~(1<<2)); // disable timer1
		PORTD &=(~(1<<1));  // shut fan
		PORTD &=(~(1<<0)); //shut heat
		PORTB &=(~(1<<3)); // shut led
	}

}