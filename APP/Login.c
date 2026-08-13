/*
 * Login.c
 *
 *  Created on: ???/???/????
 *      Author: youss
 */
#include "../LIB/STD_TYPES.h"

#include "../HAL/LCD/LCD.h"
#include "../HAL/KEYPAD/KP.h"

#include "../MCAL/EEPROM/EEPROM.h"

#include "Login.h"

#include <util/delay.h>


#define LOGIN_KP_PORT        DIO_PORTD

#define PASSWORD_LENGTH      4

#define EEPROM_FLAG_ADDRESS  0
#define EEPROM_PASS_ADDRESS  1

#define PASSWORD_SAVED       0xAA


static u8 G_u8Password[PASSWORD_LENGTH];


/*Get one key from keypad*/

static u8 APP_u8GetKey(void)
{
    u8 L_u8Key;

    do
    {
        L_u8Key = HKP_u8GetValue(LOGIN_KP_PORT);

    } while (L_u8Key == 255);

    return L_u8Key;
}


/*Read password until '=' is pressed*/

static void APP_voidReadPassword(u8 *A_u8Password)
{
    u8 L_u8Index = 0;
    u8 L_u8Key;

    while (1)
    {
        L_u8Key = APP_u8GetKey();

        /* Accept digits only */
        if ((L_u8Key >= '0') && (L_u8Key <= '9'))
        {
            if (L_u8Index < PASSWORD_LENGTH)
            {
                A_u8Password[L_u8Index] = L_u8Key;

                HLCd_voidSendData('*');

                L_u8Index++;
            }
        }

        /* '=' acts as ENTER */
        else if (L_u8Key == '=')
        {
            /* Accept only if exactly 4 digits were entered */
            if (L_u8Index == PASSWORD_LENGTH)
            {
                break;
            }
        }

        /* 'ON/C' Button clears the current password */
        else if (L_u8Key == 'C')
        {
            L_u8Index = 0;

            HLCD_voidMoveCursor(LCD_ROW1, LCD_COL0);

            HLCD_voidDisplayStr((u8*)"                ");

            HLCD_voidMoveCursor(LCD_ROW1, LCD_COL0);
        }
    }
}


/*Comparing two passwords*/

static u8 APP_u8ComparePasswords(
        u8 *A_u8Password1,
        u8 *A_u8Password2)
{
    u8 L_u8Index;

    for (L_u8Index = 0;
         L_u8Index < PASSWORD_LENGTH;
         L_u8Index++)
    {
        if (A_u8Password1[L_u8Index] !=
            A_u8Password2[L_u8Index])
        {
            return 0;
        }
    }

    return 1;
}


/*Save password into EEPROM*/

static void APP_voidSavePassword(u8 *A_u8Password)
{
    u8 L_u8Index;

    for (L_u8Index = 0;
         L_u8Index < PASSWORD_LENGTH;
         L_u8Index++)
    {
        MEEPROM_voidWriteData(
            EEPROM_PASS_ADDRESS + L_u8Index,
            A_u8Password[L_u8Index]
        );
    }

    /* Mark EEPROM as initialized */
    MEEPROM_voidWriteData(
        EEPROM_FLAG_ADDRESS,
        PASSWORD_SAVED
    );
}


/*First run*/

static void APP_voidFirstRun(void)
{
    u8 L_u8Password[PASSWORD_LENGTH];
    u8 L_u8ConfirmPassword[PASSWORD_LENGTH];

    while (1)
    {
        /*Enter New Password*/
        HLCD_voidClrDisplay();

        HLCD_voidDisplayStr((u8*)"Enter New Pass");

        HLCD_voidMoveCursor(
            LCD_ROW1,
            LCD_COL0
        );

        APP_voidReadPassword(L_u8Password);


        /*Confirm Password*/
        HLCD_voidClrDisplay();

        HLCD_voidDisplayStr((u8*)"Confirm Pass");

        HLCD_voidMoveCursor(
            LCD_ROW1,
            LCD_COL0
        );

        APP_voidReadPassword(L_u8ConfirmPassword);


        /*Compare*/
        if (APP_u8ComparePasswords(
                L_u8Password,
                L_u8ConfirmPassword))
        {
            /* Save only when both are identical */
            APP_voidSavePassword(L_u8Password);

            HLCD_voidClrDisplay();

            HLCD_voidDisplayStr(
                (u8*)"Saved Pass"
            );

            _delay_ms(1500);

            break;
        }
        else
        {
            HLCD_voidClrDisplay();

            HLCD_voidDisplayStr(
                (u8*)"Try Again"
            );

            _delay_ms(1500);

            /* Repeat first-run process */
        }
    }
}


/*Load password from EEPROM*/

static void APP_voidLoadPassword(void)
{
    u8 L_u8Index;

    for (L_u8Index = 0;
         L_u8Index < PASSWORD_LENGTH;
         L_u8Index++)
    {
        G_u8Password[L_u8Index] =
            MEEPROM_u8ReadData(
                EEPROM_PASS_ADDRESS + L_u8Index
            );
    }
}


/*Normal Login*/

static void APP_voidLogin(void)
{
    u8 L_u8EnteredPassword[PASSWORD_LENGTH];

    HLCD_voidClrDisplay();

    HLCD_voidDisplayStr(
        (u8*)"Enter Pass"
    );

    HLCD_voidMoveCursor(
        LCD_ROW1,
        LCD_COL0
    );

    APP_voidReadPassword(
        L_u8EnteredPassword
    );


    /*Compare with saved password*/
    if (APP_u8ComparePasswords(
            G_u8Password,
            L_u8EnteredPassword))
    {
        HLCD_voidClrDisplay();

        HLCD_voidDisplayStr(
            (u8*)"Right Pass"
        );

        _delay_ms(1500);
    }
    else
    {
        HLCD_voidClrDisplay();

        HLCD_voidDisplayStr(
            (u8*)"Wrong Pass"
        );

        _delay_ms(1500);
    }
}


/*Initialize Login System*/

void APP_voidLoginInit(void)
{
    HLCD_voidInit();

    HKP_voidInit(LOGIN_KP_PORT);
}


/*Start Login System*/

void APP_voidLoginStart(void)
{
    u8 L_u8Flag;

    /* Read initialization flag */
    L_u8Flag =
        MEEPROM_u8ReadData(
            EEPROM_FLAG_ADDRESS
        );


    /*First run*/
    if (L_u8Flag != PASSWORD_SAVED)
    {
        APP_voidFirstRun();
    }


    /*Password already exists*/
    APP_voidLoadPassword();


    /*Login loop*/
    while (1)
    {
        APP_voidLogin();
    }
}
