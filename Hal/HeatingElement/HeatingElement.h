/*
 * HeatingElement.h
 *
 * Created: 04/07/2023 02:08:18 م
 *  Author: ascom
 */ 


#ifndef HEATINGELEMENT_H_
#define HEATINGELEMENT_H_

/*********************************************************_INCLUDES_*******************************************************/
#include "HeatingElementCfg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
#include "Dio.h"
/**********************************************************_MACROS_********************************************************/

/********************************************************_PROTOTYPES_******************************************************/
void H_HeatingElement_Init(void);
void H_HeatingElement_On(void);
void H_HeatingElementOff(void);


#endif /* HEATINGELEMENT_H_ */