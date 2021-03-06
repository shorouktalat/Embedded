/** @file SOIL_TEMP.h
 *  @brief This file contains the Prototypes of the SOIL_TEMP Driver
 *  @author  
 */
#ifndef SOIL_TEMP_H_
#define SOIL_TEMP_H_

#include "SOIL_TEMP_CFG.h"

/** @brief  SOIL_TEMP Sensor initialization function.
 *
 *
 *  @param 
 *  @return Void
 */
void SOIL_TEMP_vidInit (void);

/** @brief  Read analog value from SOIL_TEMP pin.
 *
 *  called once to read from the SOIL_TEMP sensor 
 *  it uses Busy wait.
 *
 *  @param 
 *  @return the analog value on the Sensor
 */ 
uint16_t SOIL_TEMP_u16Read(void);

/** @brief  start reading of the sensor value
 *  
 *
 *  @param 
 *  @return Void
 */ 
void SOIL_TEMP_vidStartReading(void);

/** @brief  Check the status of the reading process
 *  
 *  poll  on this function to know if the reading has ended
 *
 *  @param 
 *  @return the reading status
 */ 
 
uint8_t SOIL_TEMP_u8ReadingStatus(void);

/** @brief  Read the value of the last read sensor value
 *  
 *  use this function after you checked that the conversion has ended
 *
 *  @param  
 *  @return The last read sensor values
 */ 
uint16_t SOIL_TEMP_u16GetData(void);


#endif /* SOIL_TEMP_H_ */
