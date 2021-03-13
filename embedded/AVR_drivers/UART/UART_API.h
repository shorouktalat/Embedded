/*
 * UART_API.h
 *
 *  Created on: Feb 7, 2020
 *      Author: Shourouk
 */
#include "../Common/common_macros.h"
#ifndef UART_API_H_
#define UART_API_H_

#define BaudRate9600 1

#define TWo_STOPBit 1
#define One_STOPBIT 0

#define  Even_Pairty 2
#define  Odd_Parity 3
#define  No_Parity  0


#define ASYNC 0
#define SYNC 1

#define FIVE_Char 0
#define SIX_Char 1
#define Seven_Char 2

#define EIGHT_Char 3
#define NINE_Char 7

#define  UMSEL 6
#define UPM0 4
#define UPM1 5
#define USBS 3
#define UCSZ0 1
#define UCSZ1 2
#define UCSZ2 2
#define URSEL 7
#define UDRE 5
#define RXEN 4
#define TXEN 3


#define UART_TX 25//PD1
#define UART_RX 24//PD0
#define UART_CLK 0//PB0

#define UDR *(u8 *)(0x2C)
#define UCSRA *(u8 *)(0x2B)
#define UCSRB *(u8 *)(0x2A)
#define UCSRC *(u8 *)(0x40)
#define UBRRH *(u8 *)(0x40)
#define UBRRL *(u8 *)(0x29)
void UART_VidInit(void);
void UART_VidSendChar(u8 Data );
u8 UART_U8_RecieveChar(void);

#endif /* UART_API_H_ */
