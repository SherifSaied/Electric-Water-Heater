/*
 * App.h
 *
 * Created: 2022-12-03 2:14:34 AM
 *  Author: pc
 */ 

#include "../Utilities/Bit_Math.h"
#include "../Utilities/REG.h"
#include "../Utilities/typedefs.h"
#include "App_Config.h"

#ifndef APP_H_
#define APP_H_

uint8_t SetTemp ; //= 60 ;
uint8_t CrrTemp;
uint8_t end ;
uint8_t right ;
uint8_t left ;
uint8_t state;
uint8_t ovf;
uint8_t heat;
uint8_t temp_arr[NUM_OF_TEMP_MEASURES];
uint8_t counter_timer0;
uint8_t counter_timer1 ;
uint8_t temp_measure_f;
uint8_t actual_temp;
uint8_t avg_temp;
uint8_t arr_counter;

uint8_t calc_avg_temp(uint8_t * arr) ;
void temp_arr_init(void) ;
void add_new_temp(uint8_t * arr , uint8_t new_val) ;
void closed(void) ;
void Operation(void) ;
/*uint16_t temp_arr[NUM_OF_TEMP_MEASURES];
uint16_t counter_timer0;
uint8_t temp_measure_f;
uint16_t actual_temp;
uint16_t avg_temp;
uint8_t arr_counter;*/




#endif /* APP_H_ */