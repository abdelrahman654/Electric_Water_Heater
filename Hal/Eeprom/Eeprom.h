/*
 * Eeprom.h
 *
 * Created: 25/06/2022 08:03:27 م
 *  Author: dell
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_



/*************************************************_INCLUDES_********************************************/
#include "EepromCfg.h"
#include "Twi.h"
#include "BitMath.h"
#define F_CPU 16000000UL
#include <util/delay.h>
/**************************************************_MACROS_*********************************************/

/************************************************_PROTOTYPES_********************************************/
void H_Eeprom_Init(void);
void H_Eeprom_Write(u16,u8);
u8   H_Eeprom_Read(u16);

#endif /* EEPROM_H_ */