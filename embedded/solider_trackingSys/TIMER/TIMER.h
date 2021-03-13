/*
 * TIMER.h
 *
 *  Created on: Dec 10, 2019
 *      Author: Ahmed Rashad
 */

#ifndef TIMER_H_
#define TIMER_H_



void TIMER_vidInit();
void _delay_ms(uint16 U16Time);
uint32 updatetime();
uint32 millis();
void _wait(uint32 mils);

#include "TIMER_CFG.h"

#endif /* TIMER_H_ */
