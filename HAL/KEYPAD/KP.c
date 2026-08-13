/*
 * KP.c
 *
 *  Created on: ???/???/????
 *      Author: youss
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO.h"

#include "KP.h"
#include <util/delay.h>
u8 GR_u8KpData [4][4] =
{
		{'7' , '4' , '1' , 'C'} ,
		{'8' , '5' , '2' , '0'} ,
		{'9' , '6' , '3' , '='} ,
		{'/' , '*' , '-' , '+'}
};
void HKP_voidInit (u8 A_u8KpPort)
{
	MDIO_voidInitPort(A_u8KpPort, 0xF0) ;
	MDIO_voidSetPortValue(A_u8KpPort, 0xFF) ;
}
u8   HKP_u8GetValue (u8 A_u8KpPort)
{
	u8 L_u8Col , L_u8Row ;
	u8 L_u8KpPressedValue = 255 ;
	for (L_u8Col = 0 ; L_u8Col < 4 ; L_u8Col ++)
	{
		MDIO_voidSetPinValue(A_u8KpPort, L_u8Col + 4, DIO_LOW) ;
		for (L_u8Row = 0 ; L_u8Row < 4 ; L_u8Row ++)
		{
			if (MDIO_u8ReadPinValue(A_u8KpPort, L_u8Row) == 0)
			{
				_delay_ms(20) ;
				if (MDIO_u8ReadPinValue(A_u8KpPort, L_u8Row) == 0)
				{
					L_u8KpPressedValue = GR_u8KpData [L_u8Col] [L_u8Row] ;
					while (MDIO_u8ReadPinValue(A_u8KpPort, L_u8Row) == 0) ;
					_delay_ms(20) ;
					MDIO_voidSetPinValue(A_u8KpPort, L_u8Col + 4, DIO_HIGH);
					return L_u8KpPressedValue ;
				}
				else
				{
					L_u8KpPressedValue = 255 ;
				}
			}
			else
			{
				L_u8KpPressedValue = 255 ;
			}
		}
		MDIO_voidSetPinValue(A_u8KpPort, L_u8Col + 4, DIO_HIGH) ;
	}
	return L_u8KpPressedValue ;
}


