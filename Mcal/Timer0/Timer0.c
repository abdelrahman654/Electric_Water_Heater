/*
 * Timer0.c
 *
 * Created: 04/06/2022 08:04:40 م
 *  Author: dell
 */ 
#include "Timer0.h"
u32 Timer0_u32_NumOfOverFlows = 0;
u8  Timer0_u8_RemTicks        = 0;
u32 Timer0_NumOfCompareMatch  = 0;
void (*CallBack)(void);
void M_Timer0_Init(void)
{
	#if   TIMER0_MODE   ==   NORMAL_MODE
	ClrBit(TCCR0,3);
	ClrBit(TCCR0,6);
	SetBit(TIMSK,0);    // to enable timer0 overflow int
	#elif TIMER0_MODE   ==   CTC_MODE
	SetBit(TCCR0,3);
	ClrBit(TCCR0,6);
	SetBit(TIMSK,1);    // to enable timer0 compare match int
	#endif
	SetBit(SREG,7);     // to enable global int
}
void M_Timer0_SetTime(u32 Local_u8_DesiredTime)
{
	#if   TIMER0_MODE   ==   NORMAL_MODE
	u32 Local_u32_TickTime        = TIMER0_PRESCALER / F_OSC;                            // result will be in micro second
	u32 Local_u32_Total_Ticks     = (Local_u8_DesiredTime * 1000) / Local_u32_TickTime;
	    Timer0_u32_NumOfOverFlows = Local_u32_Total_Ticks / 256;
	    Timer0_u8_RemTicks        = Local_u32_Total_Ticks % 256;
	if(Timer0_u8_RemTicks != 0)
	{
		TCNT0                     = 256 - Timer0_u8_RemTicks;
		Timer0_u32_NumOfOverFlows++;
	}
	#elif TIMER0_MODE   ==   CTC_MODE
	u32 Local_u32_TickTime        = TIMER0_PRESCALER / F_OSC;
	u32 Local_u32_Total_Ticks     = (Local_u8_DesiredTime * 1000) / Local_u32_TickTime;
	u8  Local_u8_DevisionFactor   = 255;
	while(Local_u32_Total_Ticks % Local_u8_DevisionFactor)
	{
		Local_u8_DevisionFactor--;
	}
	    Timer0_NumOfCompareMatch  = Local_u32_Total_Ticks / Local_u8_DevisionFactor;
	OCR0                          = Local_u8_DevisionFactor - 1 ;
	#endif
}
void M_Timer0_Start(void)
{
	#if   TIMER0_PRESCALER   ==   1024
	SetBit(TCCR0,0);
	ClrBit(TCCR0,1);
	SetBit(TCCR0,2);
	#elif TIMER0_PRESCALER   ==   256
	ClrBit(TCCR0,0);
	ClrBit(TCCR0,1);
	SetBit(TCCR0,2);
	#endif
}

void M_Timer0_Stop(void)
{
	ClrBit(TCCR0,0);
	ClrBit(TCCR0,1);
	ClrBit(TCCR0,2);
}
void M_Timer0_Pwm0Init(void)
{
	SetBit(DDRB,3);             // to make PB3 -> output
	#if   PWM0_MODE   ==   FAST_PWM0
	SetBit(TCCR0,3);
	SetBit(TCCR0,6);
		#if   FAST_PWM_MODE   ==   NON_INVERTED
		ClrBit(TCCR0,4);
		SetBit(TCCR0,5);
		#elif FAST_PWM_MODE   ==   INVERTED
		SetBit(TCCR0,4);
		SetBit(TCCR0,5);
		#endif
	#elif PWM0_MODE   ==   PHASE_CORRECT_PWM0
	ClrBit(TCCR0,3);
	SetBit(TCCR0,6);
		#if  PHASE_CORRECT_PWM_MODE   ==   NON_INVERTED
		ClrBit(TCCR0,4);
		SetBit(TCCR0,5);
		#elif PHASE_CORRECT_PWM_MODE   ==   INVERTED
		SetBit(TCCR0,4);
		SetBit(TCCR0,5);
		#endif
	#endif
}
void M_Timer0_Pwm0SetDutyCycle(u8 Local_u8_DutyCycle)
{
	#if   PWM0_MODE   ==   FAST_PWM0
		#if   FAST_PWM_MODE   ==   NON_INVERTED
		OCR0 = (((Local_u8_DutyCycle * 256 ) / 100) - 1);
		#elif FAST_PWM_MODE   ==   INVERTED
		
		#endif
	#elif PWM0_MODE   ==   PHASE_CORRECT_PWM0
			#if  PHASE_CORRECT_PWM_MODE   ==   NON_INVERTED
		    OCR0 = ((Local_u8_DutyCycle * 255 ) / 100);
			#elif PHASE_CORRECT_PWM_MODE   ==   INVERTED
			//OCR0 = 100;
			#endif
	#endif
}
void M_Timer0_Pwm0Start(void)
{
	M_Timer0_Start();
}
void M_Timer0_Pwm0Stop(void)
{
	M_Timer0_Stop();
}

void M_Timer0_SetCallBack(void (*Ptr)(void))
{
	CallBack = Ptr;
}
#if   TIMER0_MODE   ==   NORMAL_MODE
ISR(TIMER0_OVF_vect)
{
	static u32 Local_u32_Counter = 0;
	Local_u32_Counter++;
	if( Local_u32_Counter == Timer0_u32_NumOfOverFlows)
	{
		CallBack();
		Local_u32_Counter = 0;
		TCNT0             =   256 - Timer0_u8_RemTicks;
	}
}
#elif TIMER0_MODE   ==   CTC_MODE
ISR(TIMER0_COMP_vect)
{
	static u32 Local_u32_Counter = 0;
	Local_u32_Counter++;
	if( Local_u32_Counter == Timer0_NumOfCompareMatch)
	{
		CallBack();
		Local_u32_Counter = 0;
	}
}
#endif