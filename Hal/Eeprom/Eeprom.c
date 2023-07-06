/*
 * Eeprom.c
 *
 * Created: 25/06/2022 08:03:16 م
 *  Author: dell
 */ 
#include "Eeprom.h"

void H_Eeprom_Init(void)
{
	M_Twi_Init();
	_delay_ms(2000);
}
//0b11100000000
//0b00000p2p1p0  000000000
void H_Eeprom_Write(u16 Local_u16_Location,u8 Local_u8_Data)
{
	u8 Local_u8_WriteSlaveAddress = 0b10100000;
	u8 Local_u8_P0 = GetBit(Local_u16_Location,8);
	u8 Local_u8_P1 = GetBit(Local_u16_Location,9);
	u8 Local_u8_P2 = GetBit(Local_u16_Location,10);
	Local_u8_WriteSlaveAddress |= ((Local_u8_P0<<1) | (Local_u8_P1<<2)  |  (Local_u8_P2<<3));
	//0b10101110
	M_Twi_StartCondition();
	if(True == M_Twi_CheckStatus(START_ACK))
	{
		M_Twi_SendByte(Local_u8_WriteSlaveAddress);
		if(True == M_Twi_CheckStatus(SLAVE_AD_AND_WR_ACK))
		{
			M_Twi_SendByte((u8)Local_u16_Location);
			if(True == M_Twi_CheckStatus(WR_BYTE_ACK))
			{
				M_Twi_SendByte(Local_u8_Data);
				if(True == M_Twi_CheckStatus(WR_BYTE_ACK))
				{
					M_Twi_StopCondition();
				}
			}
		}
	}
}
u8   H_Eeprom_Read(u16 Local_u16_Location)
{
	u8 Local_u8_Reading = 0;
	u8 Local_u8_ReadSlaveAddress = 0;
	u8 Local_u8_WriteSlaveAddress = 0b10100000;
	u8 Local_u8_P0 = GetBit(Local_u16_Location,8);
	u8 Local_u8_P1 = GetBit(Local_u16_Location,9);
	u8 Local_u8_P2 = GetBit(Local_u16_Location,10);
	Local_u8_WriteSlaveAddress |= ((Local_u8_P0<<1) | (Local_u8_P1<<2)  |  (Local_u8_P2<<3));
	Local_u8_ReadSlaveAddress = Local_u8_WriteSlaveAddress + 1;
	//0b10101110
	M_Twi_StartCondition();
	if(True == M_Twi_CheckStatus(START_ACK))
	{
		M_Twi_SendByte(Local_u8_WriteSlaveAddress);
		if(True == M_Twi_CheckStatus(SLAVE_AD_AND_WR_ACK))
		{
			M_Twi_SendByte((u8)Local_u16_Location);
			if(True == M_Twi_CheckStatus(WR_BYTE_ACK))
			{
				M_Twi_StartCondition();
				if(True == M_Twi_CheckStatus(REP_START_ACK))
				{
					M_Twi_SendByte(Local_u8_ReadSlaveAddress);
					if(True == M_Twi_CheckStatus(SLAVE_AD_AND_RD_ACK))
					{
						Local_u8_Reading = M_Twi_ReadByteWithNoAck();
						M_Twi_StopCondition();
					}
				}
			}
		}
	}
	return Local_u8_Reading;
}