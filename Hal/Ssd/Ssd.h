/*
 * Ssd.h
 *
 * Created: 02/07/2023 04:36:29 م
 *  Author: ascom
 */ 


#ifndef SSD_H_
#define SSD_H_

/********************************************************_INCLUDES_********************************************************/
#include "SsdCfg.h"
#include "StdTypes.h"
#include "Reg.h"
#include "Dio.h"
/*********************************************************_MACROS_*********************************************************/
#define FIRST_DIGIT        1
#define SECOND_DIGIT       2
#define THIRD_DIGIT        3
#define FOURTH_DIGIT       4
#define FIFTH_DIGIT        5
#define SIXTH_DIGIT        6
/********************************************************_PROTOTYPES_****************************************************/
void H_Ssd_Init(void);
void H_Ssd_DisplayNumber(u8,u8);
void H_Ssd_Disable(void);



#endif /* SSD_H_ */