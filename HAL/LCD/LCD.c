/*
 * LCD.c
 *
 *  Created on: ???/???/????
 *      Author: youss
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO.h"

#include "LCD.h"
#include <util/delay.h>

void HLCD_voidInit     (void)
{
#if LCD_MODE == 8
	_delay_ms(50) ;
	MDIO_voidInitPort(LCD_PORT, 0xff) ;
	MDIO_voidInitPin(LCD_RS_PORT, LCD_RS_PIN, DIO_OUTPUT) ;
	MDIO_voidInitPin(LCD_RW_PORT, LCD_RW_PIN, DIO_OUTPUT) ;
	MDIO_voidInitPin(LCD_E_PORT, LCD_E_PIN, DIO_OUTPUT) ;

	HLCD_voidSendCmd(0x38) ;
	_delay_ms(1) ;
	HLCD_voidSendCmd(0x0E) ;
	_delay_ms(1) ;
	HLCD_voidSendCmd(0x01) ;
	_delay_ms(3) ;
	HLCD_voidSendCmd(0x06) ;
	_delay_ms(1) ;
#elif LCD_MODE == 4
	_delay_ms(50) ;
	MDIO_voidInitPin(LCD_PORT, DIO_PIN4, DIO_OUTPUT) ;
	MDIO_voidInitPin(LCD_PORT, DIO_PIN5, DIO_OUTPUT) ;
	MDIO_voidInitPin(LCD_PORT, DIO_PIN6, DIO_OUTPUT) ;
	MDIO_voidInitPin(LCD_PORT, DIO_PIN7, DIO_OUTPUT) ;
	MDIO_voidInitPin(LCD_RS_PORT, LCD_RS_PIN, DIO_OUTPUT) ;
	MDIO_voidInitPin(LCD_RW_PORT, LCD_RW_PIN, DIO_OUTPUT) ;
	MDIO_voidInitPin(LCD_E_PORT, LCD_E_PIN, DIO_OUTPUT) ;

	HLCD_voidSendCmd(0x02) ;
	_delay_ms(1) ;
	HLCD_voidSendCmd(0x28) ;
	_delay_ms(1) ;
	HLCD_voidSendCmd(0x0E) ;
	_delay_ms(1) ;
	HLCD_voidSendCmd(0x01) ;
	_delay_ms(4) ;
	HLCD_voidSendCmd(0x06) ;
	_delay_ms(1) ;

#else
#error "invalid LCD Mode"
#endif
}
void HLCd_voidSendData (u8 A_u8Data)
{
#if LCD_MODE == 8
	MDIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_HIGH) ;
	MDIO_voidSetPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_LOW) ;
	MDIO_voidSetPortValue(LCD_PORT, A_u8Data) ;

	MDIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_HIGH) ;
	_delay_ms(1) ;
	MDIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_LOW) ;
	_delay_ms(1) ;
#elif LCD_MODE == 4
	MDIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_HIGH) ;
	MDIO_voidSetPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_LOW) ;

	MDIO_voidSetPinValue(LCD_PORT, DIO_PIN4, READ_BIT(A_u8Data , 4 )) ;
	MDIO_voidSetPinValue(LCD_PORT, DIO_PIN5, READ_BIT(A_u8Data , 5 )) ;
	MDIO_voidSetPinValue(LCD_PORT, DIO_PIN6, READ_BIT(A_u8Data , 6 )) ;
	MDIO_voidSetPinValue(LCD_PORT, DIO_PIN7, READ_BIT(A_u8Data , 7 )) ;

	MDIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_HIGH) ;
	_delay_ms(1) ;
	MDIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_LOW) ;
	_delay_ms(1) ;

	MDIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_HIGH) ;
	MDIO_voidSetPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_LOW) ;

	MDIO_voidSetPinValue(LCD_PORT, DIO_PIN4, READ_BIT(A_u8Data , 0 )) ;
	MDIO_voidSetPinValue(LCD_PORT, DIO_PIN5, READ_BIT(A_u8Data , 1 )) ;
	MDIO_voidSetPinValue(LCD_PORT, DIO_PIN6, READ_BIT(A_u8Data , 2 )) ;
	MDIO_voidSetPinValue(LCD_PORT, DIO_PIN7, READ_BIT(A_u8Data , 3 )) ;

	MDIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_HIGH) ;
	_delay_ms(1) ;
	MDIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_LOW) ;
	_delay_ms(1) ;
#else
#error "invalid LCD Mode"
#endif
}
void HLCD_voidSendCmd  (u8 A_u8Cmd)
{
#if LCD_MODE == 8
	MDIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_LOW) ;
	MDIO_voidSetPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_LOW) ;
	MDIO_voidSetPortValue(LCD_PORT, A_u8Cmd) ;

	MDIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_HIGH) ;
	_delay_ms(1) ;
	MDIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_LOW) ;
	_delay_ms(1) ;
#elif LCD_MODE == 4
	MDIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_LOW) ;
	MDIO_voidSetPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_LOW) ;

	MDIO_voidSetPinValue(LCD_PORT, DIO_PIN4, READ_BIT(A_u8Cmd , 4 )) ;
	MDIO_voidSetPinValue(LCD_PORT, DIO_PIN5, READ_BIT(A_u8Cmd , 5 )) ;
	MDIO_voidSetPinValue(LCD_PORT, DIO_PIN6, READ_BIT(A_u8Cmd , 6 )) ;
	MDIO_voidSetPinValue(LCD_PORT, DIO_PIN7, READ_BIT(A_u8Cmd , 7 )) ;

	MDIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_HIGH) ;
	_delay_ms(1) ;
	MDIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_LOW) ;
	_delay_ms(1) ;

	MDIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_LOW) ;
	MDIO_voidSetPinValue(LCD_RW_PORT, LCD_RW_PIN, DIO_LOW) ;

	MDIO_voidSetPinValue(LCD_PORT, DIO_PIN4, READ_BIT(A_u8Cmd , 0 )) ;
	MDIO_voidSetPinValue(LCD_PORT, DIO_PIN5, READ_BIT(A_u8Cmd , 1 )) ;
	MDIO_voidSetPinValue(LCD_PORT, DIO_PIN6, READ_BIT(A_u8Cmd , 2 )) ;
	MDIO_voidSetPinValue(LCD_PORT, DIO_PIN7, READ_BIT(A_u8Cmd , 3 )) ;

	MDIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_HIGH) ;
	_delay_ms(1) ;
	MDIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_LOW) ;
	_delay_ms(1) ;
#else
#error "invalid LCD Mode"
#endif
}
void HLCD_voidDisplayStr (u8* AP_u8Str)
{
	u8 L_u8Iterator  = 0;
	while (AP_u8Str[L_u8Iterator] != '\0')
	{
		HLCd_voidSendData(AP_u8Str[L_u8Iterator]) ;
		L_u8Iterator ++ ;
	}
}
void HLCD_voidClrDisplay        (void)
{
	HLCD_voidSendCmd(0x01) ;
	_delay_ms(4) ;
}
void HLCD_voidShiftDisplayLeft  (void)
{
	HLCD_voidSendCmd(0x18) ;
		_delay_ms(1) ;
}
void HLCD_voidShiftDisplayRight (void)
{
	HLCD_voidSendCmd(0x1C) ;
		_delay_ms(1) ;
}
void HLCD_voidMoveCursor        (u8 A_u8Row , u8 A_u8Col)
{
	u8 L_u8AC ;
	if (A_u8Row == LCD_ROW0)
	{
		L_u8AC = A_u8Col ;
	}
	else if (A_u8Row == LCD_ROW1)
	{
		L_u8AC = A_u8Col+0x40 ;
	}
	HLCD_voidSendCmd(L_u8AC+0x80) ;
}

