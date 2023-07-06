/*
 * TempSensor.c
 *
 * Created: 10/06/2023 04:00:29 م
 *  Author: ascom
 */ 
#include "TempSensor.h"

void H_TempSensor_Init(void)
{
	M_Adc_Init();
}
u16  H_TempSensor_Read(void)
{
	u16 Local_u16_AdcValue = M_Adc_Read();
	u16 Local_u16_Temp      = ((u32)Local_u16_AdcValue * 500) / 1023;
	return Local_u16_Temp;
}