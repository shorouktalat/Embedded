/*
 * SPI_CFG.h
 *
 *  Created on: Feb 8, 2020
 *      Author: Shourouk
 */
#include "SPI_API.h"
#include "../DIO/DIO_init.h"
#ifndef SPI_CFG_H_
#define SPI_CFG_H_

#define MISO DIO_PIN13
#define MOSI DIO_PIN12

#define SCK DIO_PIN14

#define SS DIO_PIN11

#define SPI_MODE SPI3
#define DATA_ORDER LSB

#define OPERATION SLAVE


#endif /* SPI_CFG_H_ */
