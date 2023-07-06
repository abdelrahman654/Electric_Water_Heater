/*
 * Timer2.c
 *
 * Created: 04/07/2023 04:59:33 م
 *  Author: ascom
 */ 
#include "Timer2.h"
u32 Timer2_u32_NumOfOverFlows = 0;
u8  Timer2_u8_RemTicks        = 0;
void (*T2CallBack)(void);
void M_Timer2_Init(void)
{
	ClrBit(TCCR2,3);
	ClrBit(TCCR2,6);
	SetBit(TIMSK,6);    // to enable timer2 overflow int
	SetBit(SREG,7);     // to enable global int
}
void M_Timer2_SetTime(u32 Local_u8_DesiredTime)
{
	u32 Local_u32_TickTime        = TIMER2_PRESCALER / F_OSC;                            // result will be in micro second
	u32 Local_u32_Total_Ticks     = (Local_u8_DesiredTime * 1000) / Local_u32_TickTime;
	Timer2_u32_NumOfOverFlows = Local_u32_Total_Ticks / 256;
	Timer2_u8_RemTicks        = Local_u32_Total_Ticks % 256;
	if(Timer2_u8_RemTicks != 0)
	{
		TCNT2                     = 256 - Timer2_u8_RemTicks;
		Timer2_u32_NumOfOverFlows++;
	}
}
void M_Timer2_Start(void)
{
	SetBit(TCCR2,0);
	SetBit(TCCR2,1);
	SetBit(TCCR2,2);         //to select timer2 prescaler 1024
}

void M_Timer2_Stop(void)
{
	ClrBit(TCCR2,0);
	ClrBit(TCCR2,1);
	ClrBit(TCCR2,2);
}
void M_Timer2_SetCallBack(void (*Ptr)(void))
{
	T2CallBack = Ptr;
}
ISR(TIMER2_OVF_vect)
{
	static u32 Local_u32_Counter = 0;
	Local_u32_Counter++;
	if( Local_u32_Counter == Timer2_u32_NumOfOverFlows)
	{
		T2CallBack();
		Local_u32_Counter = 0;
		TCNT2             =   256 - Timer2_u8_RemTicks;
	}
}
