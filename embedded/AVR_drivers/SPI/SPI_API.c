/*
 * SPI_API.c
 *
 *  Created on: Feb 8, 2020
 *      Author: Shourouk
 */

#include "../Common/common_macros.h"
#include "../Common/Std_Types.h"
#include "SPI_CFG.h"
void SPI_VidMasterInit()
{

	 SPCR|=SPI_MODE<<CPHA | OPERATION<<MSTR |1<<SPE |DATA_ORDER<<DORD; //SPI MODE,MASTER, ENABLE SPI, DATA ORDER

	 SPCR|=1; //FOSC/16

	 //SPSR|=0;



}

void SPI_VidSalveInit()
{

	 SPCR|=SPI_MODE<<CPHA | OPERATION<<MSTR |1<<SPE |DATA_ORDER<<DORD;
}

void SPI_VidMasterTransmit(u8 Data)
{


}
 u8 SPI_U8SlaveRecive()
{
	 while(!Get_BIT(SPSR,SPIF));

	 return SPDR;
}
