/*
 * TempSens.c
 *
 * Created: 2022-12-03 2:07:51 AM
 *  Author: pc
 */ 
#include <avr/io.h>
#include "TempSens.h"


void adc_init()
{
	DDRA &=~(1<<7) ;
	// AREF = AVcc
	ADMUX = (1<<REFS0);

	// ADC Enable and prescaler of 128

	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

uint8_t adc_read()
{
	// select the corresponding channel 0~7
	uint8_t ch = 7;
	ADMUX = (ADMUX & 0xF8)|ch;

	// start single conversion
	// write '1' to ADSC
	ADCSRA |= (1<<ADSC);

	// wait for conversion to complete
	// ADSC becomes '0' again
	while(ADCSRA & (1<<ADSC));

	return (ADC);
}


/*
void ADC_init(void)
{
	//choose voltage reference (AVCC with external capacitor at AREF pin from datasheet)
	SET_BIT(ADMUX,REFS0);
	//choose right adjust for ADLAR so remain 0
	//gain selections single ended input 00111 for A7 pin
	SET_BIT(ADMUX,MUX0);
	SET_BIT(ADMUX,MUX1);
	SET_BIT(ADMUX,MUX2);
	//Enable ADC
	SET_BIT(ADCSRA,ADEN);
	//auto triggering so take at fixed times (100ms)
	SET_BIT(ADCSRA,ADATE);
	//ADC prescaler will be 128 as adc freq lies between 50kHZ and 200kHZ then 125kHZ
	ADCSRA = (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2) ;
	
	
	
	
	
	
	
}

uint16_t ADC_read (void)
{
	//start conversion
	SET_BIT(ADCSRA,ADSC);
	//wait until flag to be set for indication of finished conversion
	while (BIT_IS_CLEAR(ADCSRA,ADIF));
	//read data from the ADC data register
	//read low register first
	uint16_t data ;
	data =ADCL ;
	data |= (ADCH<<8) ;
	//clear flag
	// it won't clear automatically!
	ADCSRA |= (1<<ADIF) ;
	return data ;
}
*/
