/*
 * Ssd.c
 *
 * Created: 02/07/2023 04:36:13 م
 *  Author: ascom
 */ 
#include "Ssd.h"

void H_Ssd_Init(void)
{
	M_Dio_PinMode(SSD_PIN1,OUTPUT);
	M_Dio_PinMode(SSD_PIN2,OUTPUT);
	M_Dio_PinMode(SSD_PIN3,OUTPUT);
	M_Dio_PinMode(SSD_PIN4,OUTPUT);
	M_Dio_PinMode(SSD_PIN5,OUTPUT);
	M_Dio_PinMode(SSD_PIN6,OUTPUT);
	M_Dio_PinMode(SSD_PIN7,OUTPUT);
	M_Dio_PinMode(EN_1,OUTPUT);
	M_Dio_PinMode(EN_2,OUTPUT);
}
void H_Ssd_DisplayNumber(u8 Local_u8_Number,u8 Local_u8_Digit)
{
	if(Local_u8_Digit == FIRST_DIGIT)
	{
		M_Dio_PinWrite(EN_1,HIGH);
		M_Dio_PinWrite(EN_2,LOW);
		switch(Local_u8_Number)
		{
			case 0: PORTA = ((PORTA & 0b10000000) | 0b11000000);break;
			case 1: PORTA = ((PORTA & 0b10000000) | 0b11111001);break;
			case 2: PORTA = ((PORTA & 0b10000000) | 0b10100100);break;
			case 3: PORTA = ((PORTA & 0b10000000) | 0b10110000);break;
			case 4: PORTA = ((PORTA & 0b10000000) | 0b10011001);break;
			case 5: PORTA = ((PORTA & 0b10000000) | 0b10010010);break;
			case 6: PORTA = ((PORTA & 0b10000000) | 0b10000010);break;
			case 7: PORTA = ((PORTA & 0b10000000) | 0b11011000);break;
			case 8: PORTA = ((PORTA & 0b10000000) | 0b10000000);break;
			case 9: PORTA = ((PORTA & 0b10000000) | 0b10010000);break;
			default:                                            break;
		}
	}
	if(Local_u8_Digit == SECOND_DIGIT)
	{
		M_Dio_PinWrite(EN_1,LOW);
		M_Dio_PinWrite(EN_2,HIGH);
		switch(Local_u8_Number)
		{
			case 0: PORTA = ((PORTA & 0b10000000) | 0b11000000);break;
			case 1: PORTA = ((PORTA & 0b10000000) | 0b11111001);break;
			case 2: PORTA = ((PORTA & 0b10000000) | 0b10100100);break;
			case 3: PORTA = ((PORTA & 0b10000000) | 0b10110000);break;
			case 4: PORTA = ((PORTA & 0b10000000) | 0b10011001);break;
			case 5: PORTA = ((PORTA & 0b10000000) | 0b10010010);break;
			case 6: PORTA = ((PORTA & 0b10000000) | 0b10000010);break;
			case 7: PORTA = ((PORTA & 0b10000000) | 0b11011000);break;
			case 8: PORTA = ((PORTA & 0b10000000) | 0b10000000);break;
			case 9: PORTA = ((PORTA & 0b10000000) | 0b10010000);break;
			default:                                            break;
		}
	}
}
void H_Ssd_Disable(void)
{
	M_Dio_PinWrite(EN_1,LOW);
	M_Dio_PinWrite(EN_2,LOW);
}