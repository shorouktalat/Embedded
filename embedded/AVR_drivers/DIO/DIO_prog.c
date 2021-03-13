/*
 * DIO_prog.c
 *
 *  Created on: Dec 6, 2019
 *      Author: Shourouk
 */
#include "../Common/Std_Types.h"
#include "../Common/common_macros.h"
#include "DIO_Priv.h"
#include "dio_cfg.h"
#include "DIO_init.h"



void DIO_VoidINit()
{




}
void DIO_VidSetPinDir(u8 U8PinNum,u8 U8Dir)
{
	if(U8PinNum<8)
	{
	if (U8Dir==OUT)
		Set_Bit(DDRA,U8PinNum);
	else
		Clear_Bit(DDRA,U8PinNum);

	}

	else if(U8PinNum<16)
	{
	if (U8Dir==OUT)
		Set_Bit(DDRB,(U8PinNum-8));
	else
		Clear_Bit(DDRB,(U8PinNum-8));

	}

	else if(U8PinNum<24)
	{
	if (U8Dir==OUT)
		Set_Bit(DDRC,(U8PinNum-16));
	else
		Clear_Bit(DDRC,(U8PinNum-16));

	}

	else if(U8PinNum<32)
	{
	if (U8Dir==OUT)
		Set_Bit(DDRD,(U8PinNum-24));
	else
		Clear_Bit(DDRD,(U8PinNum-24));

	}
}

 void DIO_VidWritePin(u8 Pin_Number ,u8 local_value)
{
	if (Pin_Number<8)
	{
		if(local_value==DIO_HIGH)


			Set_Bit(PORTA,Pin_Number);
		else

			Clear_Bit(PORTA,Pin_Number);


	}

	else if (Pin_Number<16)
		{
			if(local_value==DIO_HIGH)


				Set_Bit(PORTA,Pin_Number-8);
			else

				Clear_Bit(PORTA,Pin_Number-8);


		}
	else if (Pin_Number<24)
		{
			if(local_value==DIO_HIGH)


				Set_Bit(PORTA,Pin_Number-16);
			else

				Clear_Bit(PORTA,Pin_Number-16);


		}
		else if (Pin_Number<32)
			{
				if(local_value==DIO_HIGH)


					Set_Bit(PORTA,Pin_Number-24);
				else

					Clear_Bit(PORTA,Pin_Number-24);


			}

}

u8 DIO_VidReadPin(u8 U8Pin_Number )
{
	u8 Ret;
	if(U8Pin_Number<8)
	{
		if(Get_BIT(PINA,U8Pin_Number)==1)
			Ret=DIO_HIGH;
		else
			Ret=DIO_LOW;

	}
	else if(U8Pin_Number<16)
	{
		if(Get_BIT(PINB,U8Pin_Number-8)==1)
			Ret=DIO_HIGH;
		else
			Ret=DIO_LOW;
	}
	else if(U8Pin_Number<24)
	{
		if(Get_BIT(PINC,U8Pin_Number-16)==1)
			Ret=DIO_HIGH;
		else
			Ret=DIO_LOW;
	}
	else if(U8Pin_Number<32)
	{
		if(Get_BIT(PIND,U8Pin_Number-24)==1)
			Ret=DIO_HIGH;
		else
			Ret=DIO_LOW;
	}
 return Ret;
}
