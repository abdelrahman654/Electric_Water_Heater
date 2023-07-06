/*
 * Twi.h
 *
 * Created: 24/06/2022 10:03:46 م
 *  Author: dell
 */ 


#ifndef TWI_H_
#define TWI_H_


/*************************************************_INCLUDES_********************************************/
#include "TwiCfg.h"
#include "StdTypes.h"
#include "Reg.h"
#include "BitMath.h"
/**************************************************_MACROS_*********************************************/
#define TWI_MASTER              1
#define TWI_SLAVE               2
#define TWINT                   7
#define TWEA                    6
#define TWSTA                   5
#define TWSTO                   4
#define TWWC                    3
#define TWEN                    2
//#define TWBR1                 1
#define TWIE                    0
#define TWPS1                   1
#define TWPS0                   0
#define True                    1
#define False                   0
#define START_ACK                     0x08		// start has been sent
#define REP_START_ACK                 0x10		// repeated start
#define SLAVE_AD_AND_WR_ACK           0x18		// master transmit [ slave address + write request ] ACK
#define SLAVE_AD_AND_RD_ACK           0x40		// master transmit [ slave address + read  request ] ACK
#define WR_BYTE_ACK                   0x28		// master transmit data ACK
#define WR_BYTE_NACK                  0x30		// master transmit data NACK
#define RD_BYTE_WITH_ACK			  0x50		// master received data with  ACK
#define RD_BYTE_WITH_NACK			  0x58		// master received data with NACK
#define SLAVE_ADD_REC_RD_REQ		  0xA8		// slave address received with write request
#define SLAVE_ADD_REC_WR_REQ          0x60		// slave address received with read  request
#define SLAVE_DATA_REC                0x80		// read  byte request received
#define SLAVE_BYTE_TRANSMITTED        0xC0		// write byte request received
/************************************************_PROTOTYPES_********************************************/
void M_Twi_Init(void);
void M_Twi_StartCondition(void);
void M_Twi_SetSlaveAddress(u8);
void M_Twi_SendByte(u8);
u8   M_Twi_ReadByteWithAck(void);
u8   M_Twi_ReadByteWithNoAck(void);
void M_Twi_StopCondition(void);
u8  M_Twi_CheckStatus(u8);
#endif /* TWI_H_ */