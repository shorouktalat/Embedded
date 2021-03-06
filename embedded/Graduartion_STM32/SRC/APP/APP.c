/** @file APP.c
 *  @brief This file contains the Source Code of the APP Driver
 *  @author  
 */

#include "APP_LOCAL.h"

typedef struct {
	uint16_t      SOIL_TEMP;
	uint8_t 	  MOISTURE;
	uint8_t		  DHT11_TEMP;
	uint8_t		  DHT11_HUMID;
} APP_DATA_t;
struct STATUS {
	uint8_t TEMP_STATUS:1;
	uint8_t MOIST_STATUS:1;
	uint8_t DHT11_STATUS:1;
	uint8_t SEND_REQUEST:1;
}SENSOR_STATUS ={0,0,0,1};


enum APP_STATE{
	APP_STATE_INIT =0,
	APP_STATE_TEMP,
	APP_STATE_MOIST,
	APP_STATE_DHT11,
	APP_STATE_SEND,
	APP_STATE_SLEEP,
	APP_STATE_WAIT,
	APP_STATE_MAX
};
enum APP_INIT_STATE{
	APP_INIT_STATE_TEMP =0,
	APP_INIT_STATE_DHT11,
	APP_INIT_STATE_MOIST,
	APP_INIT_STATE_WIFI,
	APP_INIT_STATE_MAX
};
enum APP_TEMP_STATE{
	APP_TEMP_STATE_START =0,
	APP_TEMP_STATE_WAIT,
	APP_TEMP_STATE_READ,
	APP_TEMP_STATE_MAX

};
enum APP_MOIST_STATE{
	APP_MOIST_STATE_START =0,
	APP_MOIST_STATE_WAIT,
	APP_MOIST_STATE_READ,
	APP_MOIST_STATE_MAX

};
enum APP_DHT11_STATE{
	APP_DHT11_STATE_START =0,
	APP_DHT11_STATE_WAIT,
	APP_DHT11_STATE_READ,
	APP_DHT11_STATE_MAX

};
enum APP_WAIT_STATE{
	APP_WAIT_STATE_TEMP =0,
	APP_WAIT_STATE_MOIST,
	APP_WAIT_STATE_DHT11,
	APP_WAIT_STATE_SEND,
	APP_WAIT_STATE_MAX

};


static APP_DATA_t APP_DATA_CURRENT;
static uint8_t APP_WAIT_STATE_CURRENT = APP_WAIT_STATE_MAX;


static uint8_t APP_STATE_CURRENT = 	APP_STATE_MAX;

static void APP_vidInitTask()
{
	static uint8_t APP_INIT_STATE_CURRENT = APP_INIT_STATE_TEMP;
	switch (APP_INIT_STATE_CURRENT)
	{
	case APP_INIT_STATE_TEMP :
		SOIL_TEMP_vidInit();
		APP_INIT_STATE_CURRENT = APP_INIT_STATE_DHT11 ;
		break;
	case APP_INIT_STATE_DHT11 :
		DHT11_vidInit();
		APP_INIT_STATE_CURRENT = APP_INIT_STATE_MOIST;
		break;
	case APP_INIT_STATE_MOIST :
		MOISTURE_vidInit();
		APP_INIT_STATE_CURRENT = APP_INIT_STATE_WIFI ;
		break;
	case APP_INIT_STATE_WIFI :

		APP_INIT_STATE_CURRENT = APP_INIT_STATE_MAX;
		APP_STATE_CURRENT = APP_STATE_WAIT;
		//APP_STATE_CURRENT = APP_STATE_DHT11 ;
		break;
	default:
		break;
	}
}

static void APP_vidTempTask()
{
	static uint8_t APP_TEMP_STATE_CURRENT = APP_TEMP_STATE_START;
	switch (APP_TEMP_STATE_CURRENT)
	{
	case APP_TEMP_STATE_START :
		SOIL_TEMP_vidStartReading();
		APP_TEMP_STATE_CURRENT = APP_TEMP_STATE_WAIT;
		break;
	case APP_TEMP_STATE_WAIT :
		if (SOIL_TEMP_u8ReadingStatus())
		{
			APP_TEMP_STATE_CURRENT = APP_TEMP_STATE_READ;
		}
		break;
	case APP_TEMP_STATE_READ :
		APP_DATA_CURRENT.SOIL_TEMP = SOIL_TEMP_u16GetData();
	APP_DATA_CURRENT=APP_DATA_CURRENT;
		APP_TEMP_STATE_CURRENT = APP_TEMP_STATE_START;
		APP_STATE_CURRENT = APP_STATE_WAIT;
		SENSOR_STATUS.TEMP_STATUS=1;
		break;
	default :
		break;
	}

}

static void APP_vidMoistTask()
{
	static uint8_t APP_MOIST_STATE_CURRENT = APP_MOIST_STATE_START;
	switch (APP_MOIST_STATE_CURRENT)
	{
	case APP_MOIST_STATE_START :
		MOISTURE_vidStartReading();
		APP_MOIST_STATE_CURRENT = APP_MOIST_STATE_WAIT;
		break;
	case APP_MOIST_STATE_WAIT :
		if (MOISTURE_u8ReadingStatus())
		{
			APP_MOIST_STATE_CURRENT = APP_MOIST_STATE_READ;
		}
		break;
	case APP_MOIST_STATE_READ :
		APP_DATA_CURRENT.MOISTURE = MOISTURE_u16GetData();
		APP_MOIST_STATE_CURRENT = APP_MOIST_STATE_START;
		APP_STATE_CURRENT = APP_STATE_WAIT;
		SENSOR_STATUS.MOIST_STATUS=1;
		break;
	default :
		break;
	}
}

static void APP_vidDHT11Task()
{
	static uint8_t APP_DHT11_STATE_CURRENT = APP_DHT11_STATE_START;
	switch (APP_DHT11_STATE_CURRENT)
	{
	case APP_DHT11_STATE_START :
		DHT11_vidStartReading();
		APP_DHT11_STATE_CURRENT = APP_DHT11_STATE_WAIT;
		break;
	case APP_DHT11_STATE_WAIT :
		if (DHT11_u8ReadingStatus())
		{
			APP_DHT11_STATE_CURRENT = APP_DHT11_STATE_READ;
		}
		break;
	case APP_DHT11_STATE_READ :
		APP_DATA_CURRENT.DHT11_HUMID = DHT11_u8GetHumid();
		APP_DATA_CURRENT.DHT11_TEMP  = DHT11_u8GetTemp();
		APP_DHT11_STATE_CURRENT = APP_DHT11_STATE_START;
		APP_STATE_CURRENT = APP_STATE_WAIT;
		SENSOR_STATUS.DHT11_STATUS=1;
		break;
	default :
		break;
	}
}



enum APP_SEND_STATE{
	APP_SEND_STATE_START =0,
	APP_SEND_STATE_SEND
};



static void itoa (uint8_t num , uint8_t arr[])
{
	//1234
	arr[0]= '0'+(num/1000);//1
	arr[1]= '0'+(num%1000)/100;//234/100  2
	arr[2]= '0'+(num/10)%10;//123 3
	arr[3]= '0'+(num%10);//4
	arr[4]= 0;
}
static void APP_vidSendTask()
{
	static uint8_t APP_SEND_STATE_CURRENT = APP_SEND_STATE_START;
	static uint8_t moi[5],temp[5],dtemp[5],dhumid[5];
	switch (APP_SEND_STATE_CURRENT)
	{
	case APP_SEND_STATE_START :
		//ESP_RESET();
		itoa(APP_DATA_CURRENT.DHT11_HUMID,dhumid);
		itoa(APP_DATA_CURRENT.DHT11_TEMP,dtemp);
		itoa(APP_DATA_CURRENT.SOIL_TEMP,temp);
		itoa(APP_DATA_CURRENT.MOISTURE,moi);
//		setSensorData( uint8_t * SoilMois,uint8_t * SoilTemp,uint8_t * AirTemp,uint8_t * AirHumidity)
		setSensorData(moi ,temp,dtemp,dhumid);
		APP_SEND_STATE_CURRENT = APP_SEND_STATE_SEND;
		break;
	case APP_SEND_STATE_SEND :
	if(ESP8266_Example())
		{
			APP_SEND_STATE_CURRENT = APP_SEND_STATE_START;
			APP_STATE_CURRENT = APP_STATE_WAIT;
		}
	break;
	}
}



static void APP_vidWaitTask()
{
	switch (APP_WAIT_STATE_CURRENT)
	{
	case APP_WAIT_STATE_TEMP :
		if (SENSOR_STATUS.TEMP_STATUS==0)
		{
			APP_STATE_CURRENT = APP_STATE_TEMP;
		}
		else
		{
			APP_WAIT_STATE_CURRENT = APP_WAIT_STATE_MOIST;
		}
		break ;
	case APP_WAIT_STATE_MOIST :
		if (SENSOR_STATUS.MOIST_STATUS==0)
		{
			APP_STATE_CURRENT = APP_STATE_MOIST;
		}
		else
		{
			APP_WAIT_STATE_CURRENT = APP_WAIT_STATE_DHT11;
		}
		break ;
	case APP_WAIT_STATE_DHT11 :
		if (SENSOR_STATUS.DHT11_STATUS==0)
		{
			APP_STATE_CURRENT = APP_STATE_DHT11;
		}
		else
		{
			APP_WAIT_STATE_CURRENT = APP_WAIT_STATE_SEND;
		}
		break ;
	case APP_WAIT_STATE_SEND :
		if (SENSOR_STATUS.SEND_REQUEST)
		{
			APP_STATE_CURRENT = APP_STATE_SEND;
		}
		else
		{
			APP_WAIT_STATE_CURRENT = APP_WAIT_STATE_MAX;
		}
		break ;
	default:
		if(*(uint8_t *)&SENSOR_STATUS)
		{
			APP_WAIT_STATE_CURRENT = APP_WAIT_STATE_TEMP;
		}
		
		 
		
		break;
	}
}


void APP_vidInit ()
{
	APP_STATE_CURRENT = APP_STATE_INIT;
}
void APP_vidSend()
{
	SENSOR_STATUS.SEND_REQUEST=1;
}
void APP_vidUpdate()
{
	SENSOR_STATUS.DHT11_STATUS=0;
	SENSOR_STATUS.TEMP_STATUS=0;
	SENSOR_STATUS.MOIST_STATUS=0;
}
void APP_vidUpdateTEMP()
{
	SENSOR_STATUS.TEMP_STATUS=0;
}
void APP_vidUpdateDHT11()
{
	SENSOR_STATUS.DHT11_STATUS=0;
}
void APP_vidUpdateMOIST()
{
	SENSOR_STATUS.MOIST_STATUS=0;
}
void APP_vidTask ()
{
	
	switch (APP_STATE_CURRENT)
	{
	case APP_STATE_INIT :
		APP_vidInitTask();
		break;
	case APP_STATE_TEMP :
		APP_vidTempTask();
		break;
	case APP_STATE_MOIST :
		APP_vidMoistTask();
		break;
	case APP_STATE_DHT11 :
		APP_vidDHT11Task();
		break;
	case APP_STATE_SEND  :
		APP_vidSendTask();
		APP_STATE_CURRENT=APP_STATE_SLEEP;

		break;
	case APP_STATE_SLEEP:
		//sleep but before sleeping value added to RTC alarm register

		 //_WFI();
		SENSOR_STATUS.DHT11_STATUS=0;
		SENSOR_STATUS.MOIST_STATUS=0;
		SENSOR_STATUS.TEMP_STATUS=0;
		SENSOR_STATUS.SEND_REQUEST=1;
		APP_STATE_CURRENT=APP_STATE_WAIT;

		break;
	case APP_STATE_WAIT:
		APP_vidWaitTask();
		break;

	default :
		break;
	}
}
