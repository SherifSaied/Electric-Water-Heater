/*
 * ElectricWaterHeater.c
 *
 * Created: 2022-11-15 11:42:29 PM
 * Author : Sherif Ahmed
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "App/App.h"


/*----------------------------------------------------------------------------*-

-*----------------------------------------------------------------------------*/
ISR(TIMER0_COMP_vect)
{
	counter_timer0++;
	if(counter_timer0 %6 == 0)
	{
		actual_temp = adc_read();
		add_new_temp(temp_arr , actual_temp);
		avg_temp = calc_avg_temp(temp_arr);
	}
}

ISR(INT0_vect) //int0 " up button " instructions declaration
{
	if (SetTemp <= 70 ) // check if set temp is <= 70
	{
		SetTemp = SetTemp + 5 ;
	}

	// increase set temp by 5 degrees

	ovf = 0 ; // reset timer
}

ISR(INT1_vect) //int1 " down Button " instructions declaration
{

	if ( SetTemp >= 40 ) // check if set temp is >= 40
	{
		SetTemp = SetTemp - 5 ;
	}
	// decrease set temp by 5 degrees
	ovf = 0 ;	// reset timer

}

ISR(INT2_vect) //int2 " on/ff " instructions declaration
{
	state = 0 ;
}

ISR(TIMER1_COMPA_vect)
{
	counter_timer1++;
	if(counter_timer1 %4 == 0)  // toggle led while heating mode
	{
		PORTB ^=(1<<3);
	}
}

ISR(TIMER2_COMP_vect)
{
	if(ovf < 19 ) // 19 overflow simulates 5 seconds on 1M clk with 1024 prescaler
	{ ovf ++ ; }

	else
	{
		end =1 ;
		ovf =0;
	}
}



int main(void)
{
	Button_init () ;
	DDRB |=(1<<3); //set " led " as output
	Heat_init () ;
	cooling_init () ;
	seven_init () ;
    SetTemp = 60 ;
	timer0_init();
	timer1_init();
	timer2_init();
	adc_init();
	temp_arr_init();
	EEPROM_write(0x0000,SetTemp);

    while (1) 
    {
		if (PINB && (1<<2)) //check for on/off button state
		{
			state =1;
			Enable_INT2 () ;
			SetTemp = EEPROM_read(0x0000); // read set temp from eeprom
			while (state)
			{

				if (PIND && (1<<2)) //check for up button state
				{ 
					while( PIND && (1<<2) ) ; // waiting button to be released
					Enable_INT0 () ;
					Enable_INT1 () ;
					TempSetMod(&SetTemp); // function to enter temperature setting mode
				}



				if (PIND && (1<<3)) //check for down button state
				{
					while( PIND && (1<<3) ) {} // waiting button to be released
					Enable_INT1 () ;
					Enable_INT0 () ;
				TempSetMod(&SetTemp); // function to enter temperature setting mode*/
				}
				CrrTemp=avg_temp;// function to read registered temperature
				disp(CrrTemp); //display current temp value
				Operation();// function to compare sensor temp with set temp & decide state
				}
				EEPROM_write(0x0000,SetTemp); 	// send set temp value to EEPROM
				closed(); // function to shut the system condition
				}

	}

     
}

