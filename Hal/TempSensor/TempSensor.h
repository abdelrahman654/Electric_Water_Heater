/*
 * TempSensor.h
 *
 * Created: 10/06/2023 04:00:50 م
 *  Author: ascom
 */ 


#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_

/*************************************************_INCLUDES_********************************************/
#include "TempSensorCfg.h"
#include "Adc.h"
/**************************************************_MACROS_*********************************************/

/************************************************_PROTOTYPES_********************************************/
void H_TempSensor_Init(void);
u16  H_TempSensor_Read(void);



#endif /* TEMPSENSOR_H_ */