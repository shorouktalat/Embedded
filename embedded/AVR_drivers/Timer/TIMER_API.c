/*
 * TIMER_API.c
 *
 *  Created on: Dec 10, 2019
 *      Author: Shourouk
 */
#include "../Common/Std_Types.h"
#include "../Common/common_macros.h"
#include "../DIO/DIO_init.h"
#include "TIMER_CFG.h"
#include "TIMER_API.h"

static u16 u16Counter=0;
u16 LED_Flag=0;
static u8 U8OverFlow=0;
void TIM0_VidInit()
{
	/* Set mode  */
#if TIM_MODE==NORMAL_MODE

	/*Disable Interrupt        */

	//Clear_Bit(TIMSK,0);
	/*Clear Flag      OV FLAG         */
	//Set_Bit(TIFR,0);

	Clear_Bit(TCCR0,WGM00); //WAVe form generator bits
	Clear_Bit(TCCR0,WGM01);

#elif  TIM_MODE==CTC
	OCR0=255;
	Clear_Bit(TCCR0,WGM00);
	Set_Bit(TCCR0,WGM01);

#elif TIM_MODE==PWM
	Clear_Bit(TCCR0,WGM00);
	SET_Bit(TCCR0,WGM01);
#elif TIM_MODE==FAST_PWM
	SET_Bit(TCCR0,WGM00);
	SET_Bit(TCCR0,WGM01);
#endif
/*  set prescaler  */
#if	TIM0_u16_PRESCALLER == TIM0_u16_DIV_1
	TCCR0 |= 0b00000001;

#elif TIM0_u16_PRESCALLER == TIM0_u16_DIV_8
	TCCR0 |= 0b00000010;

#elif TIM0_u16_PRESCALLER == TIM0_u16_DIV_64
	TCCR0 |= 0b00000011;

#elif TIM0_u16_PRESCALLER == TIM0_u16_DIV_256
	TCCR0 |= 0b00000100;

#elif TIM0_u16_PRESCALLER == TIM0_u16_DIV_1024
	TCCR0 |= 0b00000101;
#endif


#if CTC_output==normal
	TCCR0|=normal;
#elif CTC_output==toggle
	Set_Bit(TCCR0,5);
	Clear_Bit(TCCR0,4);
#elif CTC_output==set
	TCCR0|=set;
#elif CTC_output==clear
	TCCR0|=clear;

#endif

}
void TIM0_VidEnableInterrupt()

{
	Set_Bit(SREG,7);
#if TIM_MODE==NORMAL_MODE
	Set_Bit(TIMSK,0);
#elif TIM_MODE==CTC
	Set_Bit(TIMSK,1);

#endif

}
void Delay__ms(u8 U8Msecs)
{

	u8 U8OverFlow=((U8Msecs/TIM0_u16_PRESCALLER*External_ClockFreq)-1)/256;



}

void __vector_10 (void) __attribute__((signal,used));	// CTC interrupt
void __vector_10 (void)
{

  u16Counter ++;
if (u16Counter%500==0) //100
{
	LED_Flag|=1;
}
if (u16Counter%1000==0) //200
{
	LED_Flag|=2;
}
if (u16Counter%1500==0)
{
	LED_Flag|=4;
	u16Counter=0;
}

}
