/*
 * SPI_API.h
 *
 *  Created on: Feb 8, 2020
 *      Author: Shourouk
 */

#ifndef SPI_API_H_
#define SPI_API_H_

#define SPCR *(u8 *)(0x2D)
#define SPSR *(u8 *)(0x2E)
#define SPDR *(u8 *)(0x2F)


#define SPE 6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0
#define SPI2X 0
#define SPIF 7

#define SPI0 0
#define SPI1 1
#define SPI2 2
#define SPI3 3



#define LSB 1
#define MSB 0

#define MASTER 1
#define SLAVE 0




#endif /* SPI_API_H_ */
