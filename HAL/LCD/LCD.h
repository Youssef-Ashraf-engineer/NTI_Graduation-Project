/*
 * LCD.h
 *
 *  Created on: ???/???/????
 *      Author: youss
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"

#define LCD_PORT  DIO_PORTA

#define LCD_RS_PORT DIO_PORTB
#define LCD_RS_PIN  DIO_PIN0

#define LCD_RW_PORT DIO_PORTB
#define LCD_RW_PIN  DIO_PIN1

#define LCD_E_PORT DIO_PORTB
#define LCD_E_PIN  DIO_PIN2

#define LCD_MODE    4

#define LCD_ROW0    0
#define LCD_ROW1    1

#define LCD_COL0    0
#define LCD_COL1    1
#define LCD_COL2    2
#define LCD_COL3    3
#define LCD_COL4    4
#define LCD_COL5    5
#define LCD_COL6    6
#define LCD_COL7    7
#define LCD_COL8    8
#define LCD_COL9    9
#define LCD_COL10   10
#define LCD_COL11   11
#define LCD_COL12   12
#define LCD_COL13   13
#define LCD_COL14   14
#define LCD_COL15   15

void HLCD_voidInit              (void) ;
void HLCd_voidSendData          (u8 A_u8Data) ;
void HLCD_voidSendCmd           (u8 A_u8Cmd) ;
void HLCD_voidDisplayStr        (u8* AP_u8Str) ;
void HLCD_voidClrDisplay        (void) ;
void HLCD_voidShiftDisplayLeft  (void) ;
void HLCD_voidShiftDisplayRight (void) ;
void HLCD_voidMoveCursor        (u8 A_u8Row , u8 A_u8Col) ;

#endif /* HAL_LCD_LCD_H_ */
