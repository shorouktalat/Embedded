/*
 * TIMER_API.h
 *
 *  Created on: Dec 10, 2019
 *      Author: Shourouk
 */

#ifndef TIMER_API_H_
#define TIMER_API_H_

void TIM0_VidInit();
void TIM0_VidEnableInterrupt();
#define  OCR0 *(u8 *)(0x5C)
#define SREG  *(u8 *)(0x5F)
#define TCCR0 *(u8 *)(0x53)
#define TIMSK *(u8 *)(0x59)
#define TCNT0 *(u8 *)(0x52)
#define TIFR *(u8 *)(0x58)
#define SREG *(u8 *)(0x5F)

#define  NORMAL_MODE 0
#define  CTC 1
#define	 PWM 2
#define FAST_PWM 3


#define Clock8HZ 8
#define CLOCK16HZ 16

#define WGM00 6
#define WGM01 3

#define normal 0
#define toggle 1
#define clear 2
#define  set 3

#define TIM0_u16_DIV_1		1
#define TIM0_u16_DIV_8		8
#define TIM0_u16_DIV_64		64
#define TIM0_u16_DIV_256	256
#define TIM0_u16_DIV_1024	1024


extern u16 LED_Flag;
#endif /* TIMER_API_H_ */
