/*
 * Twi.c
 *
 * Created: 24/06/2022 10:03:36 م
 *  Author: dell
 */ 
#include "Twi.h"

void M_Twi_Init(void)
{
	#if TWI_MODE  ==  TWI_MASTER
	TWCR = (1<<TWEN);         //Enable Twi
	TWBR = 10;                //bit rate
	SetBit(TWSR,TWPS0);
	ClrBit(TWSR,TWPS1);       //prescaler 
	#elif TWI_MODE  ==  TWI_SLAVE
	TWAR = 2;
	#endif
}
void M_Twi_StartCondition(void)
{
	TWCR = (1<<TWSTA)  |  (1<<TWEN)  |  (1<<TWINT);
	while(GetBit(TWCR,TWINT) == 0);
}
void M_Twi_SetSlaveAddress(u8 Local_u8_Address)  
{
	TWAR = TWAR & 0x01; //clear old address 
	TWAR = TWAR | (Local_u8_Address << 1);
}
void M_Twi_SendByte(u8 Local_u8_Data)
{
	TWDR = Local_u8_Data;
	TWCR = (1<<TWINT)  |  (1<<TWEN);         //clear flag
	while(GetBit(TWCR,TWINT) == 0);
}
u8   M_Twi_ReadByteWithAck(void)
{
	TWCR = (1<<TWINT)  |  (1<<TWEN)  |  (1<<TWEA);
	while(GetBit(TWCR,TWINT) == 0);
	return TWDR;
}
u8   M_Twi_ReadByteWithNoAck(void)
{
	TWCR = (1<<TWINT)  |  (1<<TWEN);
	while(GetBit(TWCR,TWINT) == 0);
	return TWDR;
}
void M_Twi_StopCondition(void)
{
	TWCR = (1<<TWINT)  |  (1<<TWEN)  |  (1<<TWSTO);
}
u8  M_Twi_CheckStatus(u8 Local_u8_Status)
{
	if(Local_u8_Status == (TWSR & 0xF8))
	{
		return True;
	}
	else
	{
		return False;
	}
}
