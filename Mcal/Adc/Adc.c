/*
 * Adc.c
 *
 * Created: 10/06/2023 03:10:11 م
 *  Author: ascom
 */ 
#include "Adc.h"
void (*CallBack)(void);
//u16 x = 0;
void M_Adc_Init(void)
{
	#if   VREF   ==   AVCC
	SetBit(ADMUX,6);
	ClrBit(ADMUX,7);
	#elif VREF   ==   AREF_PIN
	ClrBit(ADMUX,6);
	ClrBit(ADMUX,7);
	#elif VREF   ==   _2V56
	SetBit(ADMUX,6);
	SetBit(ADMUX,7);
	#endif
	ClrBit(ADMUX,5);     // to select right adjust
	
	// to select channel -> ADC7
	ClrBit(ADMUX,4);
	ClrBit(ADMUX,3);
	SetBit(ADMUX,2);
	SetBit(ADMUX,1);
	SetBit(ADMUX,0);
	// to select 128 as devision factor -> ADC circuit -> 125 Khz
	SetBit(ADCSRA,0);
	SetBit(ADCSRA,1);
	SetBit(ADCSRA,2);
	SetBit(ADCSRA,5);   // to enable auto trigger
	#if    ADC_OPERATION_MODE   ==   ADC_INT
	SetBit(ADCSRA,3);   // to enable local int
	SetBit(SREG,7);     // to enable global int
	SetBit(ADCSRA,6);   // to start conversion
	#endif
	SetBit(ADCSRA,7);   // to enable ADC circuit
}
#if   ADC_OPERATION_MODE   ==   ADC_POL
u16  M_Adc_Read(void)
{
	SetBit(ADCSRA,6);   // to start conversion
	while ((GetBit(ADCSRA,4)) == 0);
	return ADC_VALUE;
}
#elif   ADC_OPERATION_MODE   ==   ADC_INT
void M_AdcInt_SetCallBack(void (*Ptr)(void))
{
	CallBack = Ptr;
}

ISR(ADC_vect)
{
	CallBack();
}
//ISR(ADC_vect)
//{
//	x = ADC_VALUE;
//}
#endif