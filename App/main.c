/*
 * ElectricWaterHeater.c
 *
 * Created: 05/07/2023 12:35:14 م
 * Author : ascom
 */ 

//#include <avr/io.h>
#include "StdTypes.h"
#include "BitMath.h"
#include "Ssd.h"
#include "TempSensor.h"
#include "Eeprom.h"
#include "ExInt.h"
#include "Timer0.h"
#include "Timer2.h"
#include "HeatingElement.h"
#include "CoolingElement.h"
#define F_CPU 16000000UL
#include <util/delay.h>
volatile u8 SystemStateFlag = 0;
volatile u8 SetTempModeFlag = 0;
volatile u8 SetTempValue =0;
volatile u8 Arr[10] = {0};
volatile u8 ArrCounter = 0;
volatile u8 TempAvr = 0;
volatile u8 TempReading = 0;
volatile u16 BlinkingCounter = 0;
volatile u8 SetTempMedeTimeCounter = 0;


void A_Int0_Execution(void);
void A_Int1_Execution(void);
void A_Int2_Execution(void);
void A_Timer0_Execution(void);
void A_Timer2_Execution(void);


int main(void)
{
	M_ExtInt_Int0Init();
	M_ExtInt_Int1Init();
	M_ExtInt_Int2Init();
	M_Timer0_Init();
	M_Timer2_Init();
	H_Eeprom_Init();
	H_Ssd_Init();
	H_HeatingElement_Init();
	H_CoolingElement_Init();
	H_TempSensor_Init();
	M_ExtInt0_SetCallBack(A_Int0_Execution);
	M_ExtInt1_SetCallBack(A_Int1_Execution);
	M_ExtInt2_SetCallBack(A_Int2_Execution);
	M_Timer0_SetCallBack(A_Timer0_Execution);
	M_Timer2_SetCallBack(A_Timer2_Execution);
    while (1) 
    {
		if(SystemStateFlag == 1)
		{
			TempReading = H_TempSensor_Read();
			H_Ssd_DisplayNumber((TempReading % 10),SECOND_DIGIT);
			_delay_us(200);
			H_Ssd_Disable();
			H_Ssd_DisplayNumber((TempReading / 10),FIRST_DIGIT);
			_delay_us(200);
			H_Ssd_Disable();
			_delay_us(200);
		}
    }
}

void A_Int0_Execution(void)
{
	SetTempMedeTimeCounter = 0;
	SetTempModeFlag++;
	if(SetTempModeFlag == 1)
	{
		M_Timer2_SetTime(1000);
		M_Timer2_Start();
	}
	if(SetTempModeFlag >= 2)
	{
		SetTempValue = H_Eeprom_Read(0x0000);
		if(SetTempValue <= 70)
		{
			H_Eeprom_Write(0x0000,(SetTempValue + 5));
			_delay_ms(20);
		}
	}
}
void A_Int1_Execution(void)
{
	SetTempMedeTimeCounter = 0;
	SetTempModeFlag++;
	if(SetTempModeFlag == 1)
	{
		M_Timer2_SetTime(1000);
		M_Timer2_Start();
	}
	if(SetTempModeFlag >= 2)
	{
		SetTempValue = H_Eeprom_Read(0x0000);
		if(SetTempValue >= 40)
		{
			H_Eeprom_Write(0x0000,(SetTempValue - 5));
			_delay_ms(20);
		}
	}
}
void A_Int2_Execution(void)
{
	SystemStateFlag ^= 1;
	if(SystemStateFlag == 1)
	{
		M_Timer0_SetTime(500);
		M_Timer0_Start();
	}
	if(SystemStateFlag == 0)
	{
		M_Timer0_Stop();
		M_Timer2_Stop();
		H_Ssd_Disable();
		H_HeatingElementOff();
		H_CoolingElementOff();
	}
}
void A_Timer0_Execution(void)
{
	    Arr[ArrCounter] = H_TempSensor_Read();
	    ArrCounter++;
	    if(ArrCounter == 10)
	    {
		    TempAvr  = (u16)(Arr[0]+Arr[1]+Arr[2]+Arr[3]+Arr[4]+Arr[5]+Arr[6]+Arr[7]+Arr[8]+Arr[9])/10;
			SetTempValue = H_Eeprom_Read(0x0000);
		    if(TempAvr <= (SetTempValue - 5))
		    {
			    H_HeatingElement_On();
			    H_CoolingElementOff();
		    }
		    if(TempAvr >= (SetTempValue +5))
		    {
			    H_HeatingElementOff();
			    H_CoolingElement_On();
		    }
		    ArrCounter = 0;
	    }
}
void A_Timer2_Execution(void)
{
	SetTempMedeTimeCounter++;
	SetTempValue = H_Eeprom_Read(0x0000);
	for(BlinkingCounter =0;BlinkingCounter<500;BlinkingCounter++)
	{
		H_Ssd_DisplayNumber((SetTempValue % 10),SECOND_DIGIT);
		_delay_us(200);
		H_Ssd_Disable();
		H_Ssd_DisplayNumber((SetTempValue / 10),FIRST_DIGIT);
		_delay_us(200);
		H_Ssd_Disable();
		_delay_us(200);
	}
	if(SetTempMedeTimeCounter == 5)
	{
		SetTempModeFlag = 0;
		M_Timer2_Stop();
	}
}