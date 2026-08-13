/*
 * DIO.c
 *
 *  Created on: ???/???/????
 *      Author: youss
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "DIO.h"


void MDIO_voidInitPin      (u8 A_u8PortName , u8 A_u8PinNumber , u8 A_u8PinMode)
{
	switch (A_u8PortName)
	{
	case DIO_PORTA :
		if (A_u8PinMode == DIO_INPUT)
		{
			CLR_BIT(DDRA , A_u8PinNumber) ;
		}
		else if (A_u8PinMode == DIO_OUTPUT)
		{
			SET_BIT(DDRA , A_u8PinNumber) ;
		}
		break ;
	case DIO_PORTB :
		if (A_u8PinMode == DIO_INPUT)
		{
			CLR_BIT(DDRB , A_u8PinNumber) ;
		}
		else if (A_u8PinMode == DIO_OUTPUT)
		{
			SET_BIT(DDRB , A_u8PinNumber) ;
		}
		break ;
	case DIO_PORTC :
		if (A_u8PinMode == DIO_INPUT)
		{
			CLR_BIT(DDRC , A_u8PinNumber) ;
		}
		else if (A_u8PinMode == DIO_OUTPUT)
		{
			SET_BIT(DDRC , A_u8PinNumber) ;
		}
		break ;
	case DIO_PORTD :
		if (A_u8PinMode == DIO_INPUT)
		{
			CLR_BIT(DDRD , A_u8PinNumber) ;
		}
		else if (A_u8PinMode == DIO_OUTPUT)
		{
			SET_BIT(DDRD , A_u8PinNumber) ;
		}
		break ;
	}
}
void MDIO_voidSetPinValue  (u8 A_u8PortName , u8 A_u8PinNumber , u8 A_u8PinValue)
{
	switch (A_u8PortName)
	{
	case DIO_PORTA :
		if (A_u8PinValue == DIO_LOW)
		{
			CLR_BIT(PORTA , A_u8PinNumber) ;
		}
		else if (A_u8PinValue == DIO_HIGH)
		{
			SET_BIT(PORTA , A_u8PinNumber) ;
		}
		break ;
	case DIO_PORTB :
		if (A_u8PinValue == DIO_LOW)
		{
			CLR_BIT(PORTB , A_u8PinNumber) ;
		}
		else if (A_u8PinValue == DIO_HIGH)
		{
			SET_BIT(PORTB , A_u8PinNumber) ;
		}
		break ;
	case DIO_PORTC :
		if (A_u8PinValue == DIO_LOW)
		{
			CLR_BIT(PORTC , A_u8PinNumber) ;
		}
		else if (A_u8PinValue == DIO_HIGH)
		{
			SET_BIT(PORTC , A_u8PinNumber) ;
		}
		break ;
	case DIO_PORTD :
		if (A_u8PinValue == DIO_LOW)
		{
			CLR_BIT(PORTD , A_u8PinNumber) ;
		}
		else if (A_u8PinValue == DIO_HIGH)
		{
			SET_BIT(PORTD , A_u8PinNumber) ;
		}
		break ;
	}
}
u8   MDIO_u8ReadPinValue   (u8 A_u8PortName , u8 A_u8PinNumber)
{
	u8 L_u8PinValue ;
	switch (A_u8PortName)
	{
	case DIO_PORTA :
		L_u8PinValue = READ_BIT(PINA , A_u8PinNumber) ;
		break ;
	case DIO_PORTB :
		L_u8PinValue = READ_BIT(PINB , A_u8PinNumber) ;
		break ;
	case DIO_PORTC :
		L_u8PinValue = READ_BIT(PINC , A_u8PinNumber) ;
		break ;
	case DIO_PORTD :
		L_u8PinValue = READ_BIT(PIND , A_u8PinNumber) ;
		break ;
	}
	return L_u8PinValue ;
}
void MDIO_voidTogPinValue  (u8 A_u8PortName , u8 A_u8PinNumber)
{
	switch (A_u8PortName)
	{
	case DIO_PORTA :
		TOG_BIT(PORTA , A_u8PinNumber) ;
		break ;
	case DIO_PORTB :
		TOG_BIT(PORTB , A_u8PinNumber) ;
		break ;
	case DIO_PORTC :
		TOG_BIT(PORTC , A_u8PinNumber) ;
		break ;
	case DIO_PORTD :
		TOG_BIT(PORTD , A_u8PinNumber) ;
		break ;
	}
}
void MDIO_voidInitPort      (u8 A_u8PortName , u8 A_u8PortMode)
{
	switch (A_u8PortName)
	{
	case DIO_PORTA :
		DDRA = A_u8PortMode ;
		break ;
	case DIO_PORTB :
		DDRB = A_u8PortMode ;
		break ;
	case DIO_PORTC :
		DDRC = A_u8PortMode ;
		break ;
	case DIO_PORTD :
		DDRD = A_u8PortMode ;
		break ;
	}
}
void MDIO_voidSetPortValue  (u8 A_u8PortName , u8 A_u8PortValue)
{
	switch (A_u8PortName)
	{
	case DIO_PORTA :
		PORTA = A_u8PortValue ;
		break ;
	case DIO_PORTB :
		PORTB = A_u8PortValue ;
		break ;
	case DIO_PORTC :
		PORTC = A_u8PortValue ;
		break ;
	case DIO_PORTD :
		PORTD = A_u8PortValue ;
		break ;
	}
}
u8   MDIO_u8ReadPortValue   (u8 A_u8PortName )
{
	u8 L_u8PortValue ;
	switch (A_u8PortName)
	{
	case DIO_PORTA :
		L_u8PortValue = PINA ;
		break ;
	case DIO_PORTB :
		L_u8PortValue = PINB ;
		break ;
	case DIO_PORTC :
		L_u8PortValue = PINC ;
		break ;
	case DIO_PORTD :
		L_u8PortValue = PIND ;
		break ;
	}
	return L_u8PortValue ;
}
void MDIO_vodiTogPortValue  (u8 A_u8PortName )
{
	switch (A_u8PortName)
	{
	case DIO_PORTA :
		PORTA = ~PORTA ;
		break ;
	case DIO_PORTB :
		PORTB = ~PORTB ;
		break ;
	case DIO_PORTC :
		PORTC = ~PORTC ;
		break ;
	case DIO_PORTD :
		PORTD = ~PORTD ;
		break ;
	}
}

