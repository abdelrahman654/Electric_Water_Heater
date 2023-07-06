/*
 * CoolingElement.h
 *
 * Created: 04/07/2023 02:12:25 م
 *  Author: ascom
 */ 


#ifndef COOLINGELEMENT_H_
#define COOLINGELEMENT_H_

/*********************************************************_INCLUDES_*******************************************************/
#include "CoolingElementCfg.h"
#include "StdTypes.h"
#include "BitMath.h"
#include "Reg.h"
#include "Dio.h"
/**********************************************************_MACROS_********************************************************/

/********************************************************_PROTOTYPES_******************************************************/
void H_CoolingElement_Init(void);
void H_CoolingElement_On(void);
void H_CoolingElementOff(void);


#endif /* COOLINGELEMENT_H_ */