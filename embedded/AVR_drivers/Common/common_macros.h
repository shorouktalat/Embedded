/*
 * common_macros.h
 *
 *  Created on: Nov 12, 2019
 *      Author: Shourouk Talaat
 */


#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_


#define Set_Bit(R,BitNo) 				((R)|=(1<<BitNo))
#define Clear_Bit(R,BitNo) 				((R)&=~(1<<BitNo))
#define Toggle_Bit(R,BitNo) 			(R)^=(1<<BitNo)
#define RotateRight(R,BitNo) 			R=((R>>BitNo)|(R<<(RegBit-BitNO)))
#define RotateLeft(R,BitNo)			 	R=((R<<BitNo)|(R>>(RegBit-BitNO)))
#define Get_BIT(R,BitNo) 				(R>>(BitNo))&1
#define Asssign_Bit(R,BitNo,Value) 		R=((~(1<<BitNo))&R)|(Value<<BitNo)

#define Clr_Low_Nibble(R)  				R&=~15
#define Set_Low_Nibble(R)  				R|=15
#define Toggle_Low_Nibble(R) 			R^=15
#define Assign_Low_Nibble(R,Value) 		R=((R&~15)|(Value))
#define Get_Low_Nibble(R) 				(R)&1

#define Clr_High_Nibble(R)  			((R)&=~(0xf0))
#define Set_High_Nibble(R)  			R|=0xf0
#define Toggle_High_Nibble(R)  			R^=0xf0
#define Assign_High_Nibble(R,Value)		R=R&~(0xf0)|(Value<<4)
#define Get_High_Nibble(R) 				(R>>(4))&15
#define CONCBIT(B7,B6,B5,B4,B3,B2,B1,B0) 0b##(B7)##(B6)##(B5)##(B4)##(B3)##(B2)##(B1)##(B0)
#endif /* COMMON_MACROS_H_ */
