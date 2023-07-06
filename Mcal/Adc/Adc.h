/*
 * Adc.h
 *
 * Created: 10/06/2023 03:11:03 م
 *  Author: ascom
 */ 


#ifndef ADC_H_
#define ADC_H_

/*************************************************_INCLUDES_********************************************/
#include "AdcCfg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
#include <avr/interrupt.h>
/**************************************************_MACROS_*********************************************/
#define AVCC         1
#define AREF_PIN     2
#define _2V56        3
#define ADC_INT      1
#define ADC_POL      2
/************************************************_PROTOTYPES_********************************************/
void M_Adc_Init(void);
u16  M_Adc_Read(void);
void M_AdcInt_SetCallBack(void(*)(void));




#endif /* ADC_H_ */