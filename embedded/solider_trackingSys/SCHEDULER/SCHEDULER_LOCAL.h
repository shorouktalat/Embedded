/*
 * SCHEDULER_LOCAL.h
 *
 *  Created on: Mar 17, 2020
 *      Author: Ahmed Rashad
 */

#ifndef SCHEDULER_LOCAL_H_
#define SCHEDULER_LOCAL_H_

#include "../COMMON/INTERRUPT.h"
#include "../COMMON/Std_Types.h"
#include "../COMMON/Utils.h"

#include "SCHEDULER_CFG.h"


#include "../LCD/LCD.h"
#include "../GPS/GPS.h"

typedef struct {
    uint8 periodicity;
    void (* fun)(void);
    uint8 status;

}Task_Holder;

#endif /* SCHEDULER_LOCAL_H_ */
