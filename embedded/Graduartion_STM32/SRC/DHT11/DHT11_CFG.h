/** @file DHT11_CFG.h
 *  @brief This file contains the Constants of the DHT11 Driver
 *  @author  
 */
#ifndef DHT11_CFG_H_
#define DHT11_CFG_H_

/** @brief  A user defined data type that caries the 
 *          senser data.
 */
//integral RH data + 8 bit decimal RH data + 8 bit integral T data+8 bit decimal T data + 8 bit checksum
typedef struct {
/** @brief The relative humidity value */ 
	uint8_t  Humidity_int;
	uint8_t  Humidity_float;
/** @brief The temperature value */
	uint8_t  Temperature_int;
	uint8_t  Temperature_float;
/** @brief The CheckSum of the sensor readings */
	uint8_t  CheckSum;
/** @brief The validity of the reading */
	uint8_t  validity;
} DHT11_Data_t;

#define DHT11_PIN  PORTA_4



#endif /* DHT11_H_ */
