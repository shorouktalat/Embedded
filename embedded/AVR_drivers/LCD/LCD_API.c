/*

 * LCD_API.C
 *
 *  Created on: Dec 19, 2019
 *      Author: Shourouk
 */
#include "../Common/Std_Types.h"
#include "../Common/common_macros.h"
#include "../DIO/Dio_Priv.h"
#include <util/delay.h>
#include "LCD_API.h"
#include "LCD_CFG.h"
//#include "TIMER_API.h"
//#include "deb.h"

#define Latch_Low 2
#define STATE_1 1
#define STATE_2 2
#define STATE_3 3
#define Latch_High 1
u8 LATCH_State=Latch_Low;
u8 Counter=0;
u8 LCD_State=STATE_1;
u8 U8LCD_Count=0;
u8 LCD_Length=0;
u8 LCD_Buffer[16]={0};
u8 U8WriteStr=0;
u8 i=0;
//u8 U8DigitFlag=0;
u8 Digit_Num=0;



u8 DataFalg=0;
u8 CommandFalg=0;
u8 Init_Falg=0;
//u8 END_digit=1;
//u8 second=0;
void LCD_VoidInit(void)
{


	Init_Falg=1;
	LCD_State=STATE_1;


	//_Debug("anaaaa");


}

 void LCD_Void_WriteData(u8 U8Data)
{
	Set_Bit(PORTA,0); //RS
	Clear_Bit(PORTA,1);//R/W
	DataFalg=1;
	PORTB=U8Data;

}

void LCD_MainFunction(void)
{

//	_Debug_value(DataFalg);
	if (Init_Falg==1)
	{

		Init_StateMachine();
	}
	if(DataFalg ||CommandFalg)
	{
	//	_Debug("<2");
		Set_Bit(PORTA,2);
		if(Counter++>=2 )
		{
		//	_Debug(">2");
			Clear_Bit(PORTA,2);
			Counter=0;
			DataFalg=0;
			CommandFalg=0;
		}
	}
	else if(U8WriteStr&&Init_Falg==0)
		{
	//	_Debug("init");
			static u8 j=0;
			if (j<LCD_Length)
			{
				LCD_Void_WriteData(LCD_Buffer[j++]);
			}
			else
			{
				U8WriteStr=0;
				//i=0;
			}

		}


		}


void LCD_Void_WriteCommand(u8 U8Command)
{
	Clear_Bit(PORTA,0); //RS

	Clear_Bit(PORTA,1);//R/W

	PORTB=U8Command;
	CommandFalg=1;

	LATCH_State=Latch_High;


}

void Init_StateMachine()
{
	U8LCD_Count++;
	switch (LCD_State)
	{

	case STATE_1:
		State1_Func();

		break;
	case STATE_2:

		State2_Func();
		break;
	case STATE_3:
		State3_Func();
		Init_Falg=0;
		break;
	}
}

void State1_Func()

{
	if (U8LCD_Count == 35 )
	{
		//_debug("init 1");
		LCD_Void_WriteCommand (0x3c);
	}

	if (U8LCD_Count == 38 )
	{
		LCD_State= STATE_2;
		U8LCD_Count= 0;
	}
}

void State2_Func()

{

	if (U8LCD_Count == 2 )
	{
		LCD_Void_WriteCommand (0x0c);
	}

	if (U8LCD_Count == 4 )
	{
		LCD_State= STATE_3;
		U8LCD_Count= 0;
	}

}

void State3_Func()

{

	if (U8LCD_Count == 2 )
	{
		LCD_Void_WriteCommand  (0x01);
	}



}
void LCD_VoidGotoxy(u8 x, u8 y)
{
	u8 address;
	if(y==0)
	{
		//	LCD_Void_WriteCommand(0x80);
		address=0x80+x;
		LCD_Void_WriteCommand(address);

	}
	else if(y==1)
	{
		//LCD_Void_WriteCommand(0xc0);
		address=0xc0+x;
		LCD_Void_WriteCommand(address);
	}

}
u8 LCD_VoidWriteStr(u8 string[],u8 Len)

{

	u8 z=0;

while(string[z]&&z!=Len)
	{
	LCD_Length++;
	//_Debug_value(z);

	LCD_Buffer[i++]=*(string+(z++));

	}

	 U8WriteStr=1;


	return 1;


}

//void LCD_void_Customchar(u8 loc,u8* msg)
//{
//	u8 i;
//	if(loc<8)
//	{
//	LCD_Void_WriteCommand(0x40+(loc*8));
//
//	for(i=0;i<8;i++)
//
//		LCD_Void_WriteData(msg[i]);
//
//
//	}
//}

void LCD_DisplayDigit(u8 Num )

{
	u8 Numbers[2]="00";


	//Numbers[0]+=Num/100; //temp=Num%100;
	Numbers[0]+=Num/10; //temp=temp%10;
	Numbers[1]+=Num%10;///1; //temp=temp%1;
//	Numbers[0]+=0;
	//Numbers[4]+=temp%10;



	LCD_VoidWriteStr(Numbers,2);







	// _Debug("init 1");
}

void LCD_VidClear()
{
	LCD_Void_WriteCommand(0x01);
}
