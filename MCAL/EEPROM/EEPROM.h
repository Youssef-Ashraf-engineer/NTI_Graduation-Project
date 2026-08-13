/*
 * EEPROM.h
 *
 *  Created on: ???/???/????
 *      Author: youss
 */

#ifndef MCAL_EEPROM_EEPROM_H_
#define MCAL_EEPROM_EEPROM_H_

#include "../../LIB/STD_TYPES.h"

#define EEAR    (*(volatile u16*)(0x3E))
#define EEDR    (*(volatile u8* )(0x3D))
#define EECR    (*(volatile u8* )(0x3C))

#define EERE    0
#define EEWE    1
#define EEMWE   2

void MEEPROM_voidWriteData (u16 A_u16Address , u8 A_u8Data) ;
u8   MEEPROM_u8ReadData    (u16 A_u16Address) ;

#endif /* MCAL_EEPROM_EEPROM_H_ */
