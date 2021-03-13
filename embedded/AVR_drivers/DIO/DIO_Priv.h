/*
 * DIO_Priv.h
 *
 *  Created on: Dec 6, 2019
 *      Author: Shourouk
 */
#include "../Common/Std_Types.h"
#include "dio_cfg.h"
#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

//#define PORTA_DIRECTION (DIO_PIN7_DIR)##(DIO_PIN6_DIR)##(DIO_PIN5_DIR)##(DIO_PIN4_DIR)##(DIO_PIN3_DIR)##(DIO_PIN2_DIR)##(DIO_PIN1_DIR)##(DIO_PIN0_DIR)
//#define PORTB_DIRECTION DIO_PIN15_DIR,DIO_PIN14_DIR ,DIO_PIN13_DIR ,DIO_PIN12_DIR ,DIO_PIN11_DIR ,DIO_PIN10_DIR ,DIO_PIN9_DIR ,DIO_PIN8_DIR)
//#define PORTC_DIRECTION DIO_PIN23_DIR,DIO_PIN22_DIR ,DIO_PIN21_DIR ,DIO_PIN20_DIR ,DIO_PIN19_DIR ,DIO_PIN18_DIR ,DIO_PIN17_DIR ,DIO_PIN16_DIR)
//#define PORTD_DIRECTION DIO_PIN31_DIR,DIO_PIN30_DIR ,DIO_PIN29_DIR ,DIO_PIN28_DIR ,DIO_PIN27_DIR ,DIO_PIN26_DIR ,DIO_PIN25_DIR ,DIO_PIN24_DIR)

void DIO_VoidINit();
void DIO_VidSetPinDir(u8 ,u8 );
void DIO_VidWritePin(u8  ,u8 );
u8 DIO_VidReadPin(u8 );

#define IN 0
#define OUT 1

#define DDRA  *(u8 *)(0x3A)
#define PORTA *(u8 *)(0x3B)
#define PINA  *(u8 *)(0x39)

#define DDRB  *(u8 *)(0x37)
#define PORTB *(u8 *)(0x38)
#define PINB  *(u8 *)(0x36)

#define DDRC *(u8 *)(0x34)
#define PORTC *(u8 *)(0x35)
#define PINC *(u8 *)(0x33)

#define DDRD *(u8 *)(0x31)
#define PORTD *(u8 *)(0x32)
#define PIND *(u8 *)(0x30)
#endif /* DIO_PRIV_H_ */
