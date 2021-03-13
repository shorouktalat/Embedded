/*
 * UART_API.c

 *
 *  Created on: Feb 7, 2020
 *      Author: Shourouk
 */

#include "../Common/Std_Types.h"
#include "../Common/common_macros.h"
#include "../UART/UART_API.h"
#include "../UART/UART_confg.h"
#include "../DIO/DIO_Priv.h"
#include "../DIO/DIO_init.h"

void UART_VidInit(void)
{
	DIO_VidSetPinDir(UART_TX,OUT);
	DIO_VidSetPinDir(UART_RX,IN);
	Set_Bit(UCSRB,RXEN);
	Set_Bit(UCSRB,TXEN);
	Set_Bit(UCSRC,URSEL); //to acess ucsrc
	#if Character_Size==FIVE_Char
		Clear_Bit(UCSRC,UCSZ0);
		Clear_Bit(UCSRC,UCSZ1);
		Clear_Bit(UCSRB,UCSZ2);
	#elif Character_Size==SIX_Char
	 	Set_Bit(UCSRC,UCSZ0);
	 	Clear_Bit(UCSRC,UCSZ1);
		Clear_Bit(UCSRB,UCSZ2);
	#elif Character_Size==Seven_Char
		Clear_Bit(UCSRC,UCSZ0);
		Set_Bit(UCSRC,UCSZ1);
		Clear_Bit(UCSRB,UCSZ2);

	#elif Character_Size==EIGHT_Char
		Set_Bit(UCSRC,UCSZ0);
		Set_Bit(UCSRC,UCSZ1);
		Clear_Bit(UCSRB,UCSZ2);

	#elif Character_Size==NINE_Char
		Set_Bit(UCSRC,UCSZ0);
		Set_Bit(UCSRC,UCSZ1);
		Set_Bit(UCSRB,UCSZ2);
	#endif


	UCSRC|=UART_Mode<<UMSEL; //async or sync
	//Clear_Bit(UCSRC,6);


	//#if StopBit== One_STOPBIT
	UCSRC|=StopBit<<USBS;
		//Clear_Bit(UCSRC,3);
	//#endif

	#if Parity_Check==No_Parity

		Clear_Bit(UCSRC,UPM0);
		Clear_Bit(UCSRC,UPM1);

	#elif Parity_Check==Even_Pairty

		Clear_Bit(UCSRC,UPM0);
		Set_Bit(UCSRC,UPM1);
	#elif Parity_Check==Odd_Parity

		Set_Bit(UCSRC,UPM0);
		Set_Bit(UCSRC,UPM1);

	#endif
		Clear_Bit(UCSRC,URSEL); //to acess  UBRRH

	#if BaudRate== BaudRate9600
		//BR=(Osc_Freq/16*BaudRate)-1
	UBRRH=0;
	UBRRL=51;

	#endif





}
void UART_VidSendChar(u8 Data )
{
	//Set_Bit(UCSRB,TXEN);


	while(Get_BIT(UCSRA,UDRE)==0);

		UDR=Data;

}
u8 UART_U8_RecieveChar(void)
{


	//Set_Bit(UCSRB,RXEN);


	while(Get_BIT(UCSRA,7)==0);

		return UDR;

}

