/*
 * EEPROM.h
 *
 * Created: 2022-12-15 8:29:53 AM
 *  Author: pc
 */ 

#include "../../Utilities/Bit_Math.h"
#include "../../Utilities/REG.h"
#include "../../Utilities/typedefs.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h> 

#ifndef EEPROM_H_
#define EEPROM_H_

uint8_t EEPROM_read (const unsigned short addr) ;



#endif /* EEPROM_H_ */