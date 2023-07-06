/*
 * Timer2.h
 *
 * Created: 04/07/2023 04:59:50 م
 *  Author: ascom
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

/*************************************************_INCLUDES_********************************************/
#include "Timer2Cfg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
#include <avr/interrupt.h>
/************************************************_PROTOTYPES_********************************************/
void M_Timer2_Init(void);
void M_Timer2_SetTime(u32);
void M_Timer2_Start(void);
void M_Timer2_Stop(void);
void M_Timer2_SetCallBack(void (*)(void));




#endif /* TIMER2_H_ */