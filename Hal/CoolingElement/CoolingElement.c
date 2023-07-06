/*
 * CoolingElement.c
 *
 * Created: 04/07/2023 02:12:01 م
 *  Author: ascom
 */ 
#include "CoolingElement.h"

void H_CoolingElement_Init(void)
{
	M_Dio_PinMode(COOLING_ELEMENT_PIN,OUTPUT);
}
void H_CoolingElement_On(void)
{
	M_Dio_PinWrite(COOLING_ELEMENT_PIN,HIGH);
}
void H_CoolingElementOff(void)
{
	M_Dio_PinWrite(COOLING_ELEMENT_PIN,LOW);
}