/*
 * APP.c
 *
 *  Created on: Apr 4, 2020
 *      Author: shena
 */


#include "../COMMON/Std_Types.h"
#include "../COMMON/Utils.h"
#include "../COMMON/INTERRUPT.h"

#include "../LCD/LCD.h"
#include "../TIMER/TIMER.h"
#include "../DIO/DIO.h"
#include "../TEMP_SENSOR/TEMP_SENSOR.h"

#include "../GSM/GSM.h"
#include "../GPS/GPS.h"
#include "../SWITCH/SWITCH.h"

#define Selector PORTC_0
#define Select_GSM LOW
#define Select_GPS HIGH
#define NAM_LENGTH 	15
#define TMP_LENGTH	4


//#define APP_update 0
//#define APP_uptodate 1
//uint8 APP_state=APP_update;

static uint8 str_concat (int8 str1[],int8 str2[])
{
	uint8 i=0,j=0;
	while (str1[i])
	{
		i++;
	}
	while (str2[j])
	{
		str1[i++]=str2[j++];
	}
	str1[i]=0;
	return i;
}



typedef struct {
	int8 Name[NAM_LENGTH];
	int8 TEMP[TMP_LENGTH];
	int8 LON [LON_LENGTH];
	int8 LAT [LAT_LENGTH];
	uint8 FIX;
}SOLDIER;

int8 mobile_number[15]="+0201553130804";

SOLDIER x={"Mr. XYZ","XXX","NOT Valid","NOT Valid",0};
int8 message[50]={0};
static void APP_send (uint8 i)
{
	GSM_vidSelect();
	GPS_vidDisAttach();
	message[0]=0;
	str_concat(message,"Name: ");
	str_concat(message,x.Name);
	str_concat(message,"\r");
	switch (i)
	{
	case 0:
		LCD_vidString(" DATA\n");
		str_concat(message,"Temp:");
		str_concat(message,x.TEMP);
		str_concat(message,"\r");
		str_concat(message,"LAT: ");
		str_concat(message,x.LAT);
		str_concat(message,"\r");
		str_concat(message,"LON: ");
		str_concat(message,x.LON);
		str_concat(message,"\r");

		break;
	case 1:
		LCD_vidString(" HELP\n");
		str_concat(message,"Need more TROOPS\r");
		break;
	case 2:
		LCD_vidString(" ABORTING\n");
		str_concat(message,"Aborting The Mission\r");
		break;
	default:
		break;
	}

	GSM_vidSendSMS(message,mobile_number);
	GPS_vidSelect();
}




int main(void)
{
	//	int8 message[50]={0};
	GPS Data ;

	_delay_ms(100);
	LCD_vidInit();

	TIMER_vidInit();
	Enable_Global_Interrupt();
	TEMP_SENSOR_vidInit();
	GPS_vidInit();
	GSM_vidInit();

	GSM_vidSelect();
	while(!GSM_u8Startup());


	GPS_vidSelect();
	Data = GPS_READ();

	GSM_vidSelect();
	GPS_vidDisAttach();


	x.FIX=1;
	x.FIX&=GPS_u8GetLat(x.LAT);
	x.FIX&=GPS_u8GetLon(x.LON);
	TEMP_SENSOR_u16GetData(x.TEMP);



	//	DIO_u8SetPinDir(PORTB_5,INPUT_PULLUP);
	SW_vidInit();
	uint8 arr[3]={0};
	for(uint8 j=0;j<3;j++)
		SW_vidFlag(j,arr+j);
	GPS_vidSelect();
	while(1)
	{
		LCD_vidString("LAT:");
		LCD_vidString(x.LAT);
		LCD_vidString("LON:");
		LCD_vidString(x.LON+1);
		LCD_vidString("TEMPERATURE: ");
		LCD_vidString(x.TEMP);
		Data = GPS_READ();
		GPS_u8GetLat(x.LAT);
		GPS_u8GetLon(x.LON);
		TEMP_SENSOR_u16GetData(x.TEMP);
		x.FIX=Data.FIX;
		LCD_vidClear();

		for(uint8 j=0;j<3;j++)
			if (arr[j]) // active low
			{
//				LCD_vidClear();
				LCD_vidString("SENDING MESSAGE");

				arr[j]=0;
				APP_send(j);

			}

	}

}

void (*fun[])()={LCD_vidTask,SW_vidTask};
//uint32 update_time=0;
ISR(TIMER0_COMP_VECTOR_NUM )
{
	//	if((update_time++)>20000)
	//	{
	//		update_time=0;
	//		APP_state=APP_update;
	//	}
	LCD_vidTask();
	SW_vidTask();
//	fun[(updatetime())%2]();

}

