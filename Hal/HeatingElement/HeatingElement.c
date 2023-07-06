/*
 * HeatingElement.c
 *
 * Created: 04/07/2023 02:07:50 م
 *  Author: ascom
 */ 

#include "HeatingElement.h"

void H_HeatingElement_Init(void)
{
	M_Dio_PinMode(HEATING_ELEMENT_PIN,OUTPUT);
}
void H_HeatingElement_On(void)
{
	M_Dio_PinWrite(HEATING_ELEMENT_PIN,HIGH);
}
void H_HeatingElementOff(void)
{
	M_Dio_PinWrite(HEATING_ELEMENT_PIN,LOW);
}