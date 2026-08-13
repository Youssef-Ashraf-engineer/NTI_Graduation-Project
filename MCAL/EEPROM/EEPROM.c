/*
 * EEPROM.c
 *
 *  Created on: ???/???/????
 *      Author: youss
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "EEPROM.h"

void MEEPROM_voidWriteData (u16 A_u8Address , u8 A_u8Data)
{
	/*Wait for any previous writes to finish FIRST*/

	    EEAR = A_u8Address;
	    EEDR = A_u8Data;

	    EECR = (1 << 2);
	    EECR = (1 << 2) | (1 << 1);
	    while (READ_BIT(EECR, 1) == 1);

}
u8   MEEPROM_u8ReadData    (u16 A_u8Address)
{
	EEAR = A_u8Address ;
	SET_BIT(EECR , 0) ;

	return EEDR ;
}
