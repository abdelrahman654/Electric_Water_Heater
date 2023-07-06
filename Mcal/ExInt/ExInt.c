/*
 * ExInt.c
 *
 * Created: 08/06/2023 09:38:17 م
 *  Author: ascom
 */ 

#include "ExInt.h"
void (*INT0_CallBack)(void);
void (*INT1_CallBack)(void);
void (*INT2_CallBack)(void);

void M_ExtInt_Int0Init(void)
{
	#if    SENSE_CONTROL    ==    RISING_EDGE
	SetBit(MCUCR,0);
	SetBit(MCUCR,1);
	#elif  SENSE_CONTROL    ==    FAILLING_EDGE
	ClrBit(MCUCR,0);
	SetBit(MCUCR,1);
	#elif  SENSE_CONTROL    ==    LOGICAL_CHANGE
	SetBit(MCUCR,0);
	ClrBit(MCUCR,1);
	#elif  SENSE_CONTROL    ==    LOW_LEVEL
	ClrBit(MCUCR,0);
	ClrBit(MCUCR,1);
	#endif
	SetBit(GICR,6);     // to enable local  interrupt
	SetBit(SREG,7);     // to enable global interrupt
}
void M_ExtInt_Int1Init(void)
{
	#if    SENSE_CONTROL    ==    RISING_EDGE
	SetBit(MCUCR,2);
	SetBit(MCUCR,3);
	#elif  SENSE_CONTROL    ==    FAILLING_EDGE
	ClrBit(MCUCR,2);
	SetBit(MCUCR,3);
	#elif  SENSE_CONTROL    ==    LOGICAL_CHANGE
	SetBit(MCUCR,2);
	ClrBit(MCUCR,3);
	#elif  SENSE_CONTROL    ==    LOW_LEVEL
	ClrBit(MCUCR,2);
	ClrBit(MCUCR,3);
	#endif
	SetBit(GICR,7);     // to enable local  interrupt
	SetBit(SREG,7);     // to enable global interrupt
}
void M_ExtInt_Int2Init(void)
{
	
	#if    SENSE_CONTROL    ==    RISING_EDGE
	SetBit(MCUCSR,6);
	#elif  SENSE_CONTROL    ==    FAILLING_EDGE
	ClrBit(MCUCSR,6);
	#endif
	SetBit(GICR,5);     // to enable local  interrupt
	SetBit(SREG,7);     // to enable global interrupt
}

void M_ExtInt0_SetCallBack(void (*Ptr)(void))
{
	INT0_CallBack = Ptr;
}
void M_ExtInt1_SetCallBack(void(*Ptr)(void))
{
	INT1_CallBack = Ptr;
}
void M_ExtInt2_SetCallBack(void(*Ptr)(void))
{
	INT2_CallBack = Ptr;
}

ISR(INT0_vect)
{
	INT0_CallBack();
}

ISR(INT1_vect)
{
	INT1_CallBack();
}

ISR(INT2_vect)
{
	INT2_CallBack();
}