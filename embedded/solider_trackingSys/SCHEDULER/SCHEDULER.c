/*
 * SCHEDULER.c
 *
 *  Created on: Mar 17, 2020
 *      Author: Ahmed Rashad
 */

#include "SCHEDULER_LOCAL.h"
static Task_Holder Task[Task_Count];
void SCHEDULER_vidInit ()
{

	Task[0].status=1;Task[0].periodicity=0;Task[0].fun=LCD_vidTask;
	Task[1].status=1;Task[1].periodicity=0;Task[1].fun=GPS_vidTask;

	Enable_Global_Interrupt();

}



