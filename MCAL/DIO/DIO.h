/*
 * DIO.h
 *
 *  Created on: ???/???/????
 *      Author: youss
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include "../../LIB/STD_TYPES.h"

#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3

#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7

#define DIO_INPUT  0
#define DIO_OUTPUT 1

#define DIO_HIGH   1
#define DIO_LOW    0


#define DDRA    (*(volatile u8*)(0X3A))
#define PORTA   (*(volatile u8*)(0X3B))
#define PINA    (*(volatile u8*)(0X39))

#define DDRB    (*(volatile u8*)(0X37))
#define PORTB   (*(volatile u8*)(0X38))
#define PINB    (*(volatile u8*)(0X36))

#define DDRC    (*(volatile u8*)(0X34))
#define PORTC   (*(volatile u8*)(0X35))
#define PINC    (*(volatile u8*)(0X33))

#define DDRD    (*(volatile u8*)(0X31))
#define PORTD   (*(volatile u8*)(0X32))
#define PIND    (*(volatile u8*)(0X30))

void MDIO_voidInitPin      (u8 A_u8PortName , u8 A_u8PinNumber , u8 A_u8PinMode) ;
void MDIO_voidSetPinValue  (u8 A_u8PortName , u8 A_u8PinNumber , u8 A_u8PinValue) ;
u8   MDIO_u8ReadPinValue   (u8 A_u8PortName , u8 A_u8PinNumber) ;
void MDIO_voidTogPinValue  (u8 A_u8PortName , u8 A_u8PinNumber) ;

void MDIO_voidInitPort      (u8 A_u8PortName , u8 A_u8PortMode) ;
void MDIO_voidSetPortValue  (u8 A_u8PortName , u8 A_u8PortValue) ;
u8   MDIO_u8ReadPortValue   (u8 A_u8PortName ) ;
void MDIO_vodiTogPortValue  (u8 A_u8PortName ) ;

#endif /* MCAL_DIO_DIO_H_ */
