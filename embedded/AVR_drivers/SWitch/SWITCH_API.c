/*
 * SWITCH_API.c
 *
 *  Created on: Dec 21, 2019
 *      Author: Shourouk
 */

#include "../Common/Std_Types.h"
#include "../Common/common_macros.h"
#include "../Switch/SWITCH_API.h"
#include "../DIO/dio_cfg.h"
#include "../DIO/DIO_Priv.h"
#include "../DIO/DIO_init.h"
#include "Switch_cfg.h"
//#include "deb.h"
u8 State=Released;
u8	U8Counter=0;
void SW_VidInit()
{
	DIO_VidSetPinDir(Switch1,IN);
	DIO_VidWritePin(Switch1,DIO_HIGH);
}
int SW_VidTask()
{
	//_Debug_value(State);
switch (State )
{

case Released:
	if (DIO_VidReadPin(Switch1)==0)

		{
		//_Debug("s");
		State=Prepushed;

		}
		break;
case Prepushed:

	if (DIO_VidReadPin(Switch1)==0)

		{
		U8Counter++;
		if (U8Counter>=5)
			{
			U8Counter=0;
			State=Pushed;

			}


		}
	else
		U8Counter=0;

break;
	case Pushed:

	if(DIO_VidReadPin(Switch1)==1)
		State=PreReleased;



	break;
case PreReleased:

	if(DIO_VidReadPin(Switch1)==1)
		{
		U8Counter++;
		if (U8Counter>=5)
			{
			U8Counter=0;
			State=Released;
			}

		}
	else
		{
		U8Counter=0;
		}


	break;

}
return State;
}
