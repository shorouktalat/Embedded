/*
 * TIMER_CFG.h
 *
 *  Created on: Dec 10, 2019
 *      Author: Shourouk
 */

#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_
/*PLEASE CHOOSE
 * 0 NORMAL MODE
 * 1 CTC
 * 2 PWM
 * 3 FAST_PWM
 */
#define TIM_MODE CTC
/*PLEASE CHOOSE
 *
 TIM0_u16_DIV_1		1
 TIM0_u16_DIV_8		8
 TIM0_u16_DIV_64		64
TIM0_u16_DIV_256	256
 TIM0_u16_DIV_1024	1024
 *
 */
#define TIM0_u16_PRESCALLER TIM0_u16_DIV_8


/*please choose
 * Clock8HZ 8
 * CLOCK16HZ 16
 *
 *
 */
#define External_ClockFreq  Clock8HZ
/*
 * normal 0
 * toggle 1
 * clear 2
 * set 3
 */
#define CTC_output toggle

#endif /* TIMER_CFG_H_ */
