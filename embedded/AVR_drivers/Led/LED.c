/*
 * LED.c
 *
 *  Created on: Apr 5, 2020
 *      Author: shorouk
 */


#include "LED_LOCAL.h"
#include "../DIO/DIO_Priv.h"
#include "../DIO/DIO_init.h"

static u8 state[LED_COUNT]={DIO_LOW,DIO_LOW,DIO_LOW};
static	u8 LEDS[LED_COUNT] = {LED_PIN1,LED_PIN2,LED_PIN3};


void LED_vidToggle(u8 Index)
{
	DIO_VidWritePin(LEDS[Index%LED_COUNT],state[Index%LED_COUNT]=!state[Index%LED_COUNT]);
}

void LED_vidInit(u8 LED_Index)
{

	DIO_VidSetPinDir(LEDS[LED_Index%LED_COUNT],OUT);

	 DIO_VidWritePin(LEDS[LED_Index%LED_COUNT],state[LED_Index%LED_COUNT]);
}
void LED_vidSet(u8 LED_Index)
{
	DIO_VidWritePin(LEDS[LED_Index%LED_COUNT],state[LED_Index%LED_COUNT]=DIO_HIGH);
}
void LED_vidClear(u8 LED_Index)
{
	state[LED_Index%LED_COUNT]=!state[LED_Index%LED_COUNT];
	DIO_VidWritePin(LEDS[LED_Index%LED_COUNT],state[LED_Index%LED_COUNT]=DIO_LOW);
}
