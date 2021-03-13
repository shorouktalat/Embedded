/*
 * LCD_API.h
 *
 *  Created on: Dec 19, 2019
 *      Author: Shourouk
 */

#ifndef LCD_API_H_
#define LCD_API_H_

void LCD_VoidInit();
 void LCD_Void_WriteData(u8 );
void LCD_Void_WriteCommand(u8 );
void LCD_MainFunction(void);
void LCD_DisplayDigit(u8 );
void LCD_VidClear();
u8 LCD_VoidWriteStr(u8 string[],u8 Len);
void Init_StateMachine();
void State1_Func();
void State2_Func();
void State3_Func();
#define FourBit 4
#define EightBit 8


#endif /* LCD_API_H_ */
