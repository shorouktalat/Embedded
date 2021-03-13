/*
 * ADC_CFG.h
 *
 *  Created on: Mar 14, 2020
 *      Author: Ahmed Rashad
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

enum ADC_CHANNELS{
	ADC0= 0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6, ADC7,
	ADC00_10x,  ADC01_10x, ADC00_200x, ADC01_200x,
	ADC22_10x,  ADC23_10x, ADC22_200x, ADC23_200x,
	ADC10, ADC11, ADC12, ADC13, ADC14, ADC15, ADC16, ADC17,
	ADC20, ADC21, ADC22, ADC23, ADC24, ADC25,
	ADC_1_22v,ADC_ov
};
enum REFRENCES {
	AREF=0,
	AVCC=1,
	I2_56v=3
};

enum PRESCALARS {
	ADC_PRESC_2 = 0,
	ADC_PRESC_4 = 2,
	ADC_PRESC_8 = 3,
	ADC_PRESC_16= 4,
	ADC_PRESC_32= 5,
	ADC_PRESC_64= 6,
	ADC_PRESC_128=7
};

enum ADC_TRIGGERS{
	FREE_RUNNING =0,
	ANALOG_COMPARATOR,
	EXT_INT0,
	TIMER0_COMP,
	TIMER0_OVF,
	TIMER1_COMP_B,
	TIMER1_OVF,
	TIMER1_CAPTURE
};
#define ADC_0 				PORTA_0
#define ADC_1 				PORTA_1
#define ADC_2 				PORTA_2
#define ADC_3 				PORTA_3
#define ADC_4 				PORTA_4
#define ADC_5 				PORTA_5
#define ADC_6 				PORTA_6
#define ADC_7 				PORTA_7



#define ADC_REFRENCE		AVCC
#define ADC_ADLAR			1
#define ADC_AUTO_TRIGGER 	0
#define ADC_INTERRUPT	 	0
#define ADC_PRESCALAR   	ADC_PRESC_128
#define ADC_TRIGGER			FREE_RUNNING

#endif /* ADC_CFG_H_ */
