/*
 * ExInt.h
 *
 * Created: 08/06/2023 09:38:41 م
 *  Author: ascom
 */ 


#ifndef EXINT_H_
#define EXINT_H_

/*************************************************_INCLUDES_********************************************/
#include "ExIntCfg.h"
#include "BitMath.h"
#include "StdTypes.h"
#include "Reg.h"
#include <avr/interrupt.h>
/**************************************************_MACROS_*********************************************/
#define RISING_EDGE           1
#define FAILLING_EDGE         2
#define LOGICAL_CHANGE        3
#define LOW_LEVEL             4
/************************************************_PROTOTYPES_********************************************/
void M_ExtInt_Int0Init(void);
void M_ExtInt_Int1Init(void);
void M_ExtInt_Int2Init(void);
void M_ExtInt0_SetCallBack(void(*)(void));
void M_ExtInt1_SetCallBack(void(*)(void));
void M_ExtInt2_SetCallBack(void(*)(void));



#endif /* EXINT_H_ */