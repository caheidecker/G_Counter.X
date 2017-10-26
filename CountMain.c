/* 
 * File:   CountMain.c
 * Author: caheidecker
 *
 * Created on October 26, 2017, 6:25 PM
 */

#define _XTAL_FREQ 8000000

#define D0 PORTBbits.RB0
#define D1 PORTBbits.RB1
#define D2 PORTBbits.RB2
#define D3 PORTBbits.RB3
#define D4 PORTBbits.RB4
#define D5 PORTBbits.RB5 
#define D6 PORTCbits.RC2
#define D7 PORTCbits.RC3

#define RS PORTCbits.RC0
#define EN PORTCbits.RC1

#pragma config FOSC=INTIO67
#pragma config WDTEN=OFF
#pragma config PWRTEN=ON

#include <xc.h>			
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LCD.h"

int main(int argc, char** argv) 
{
    Lcd_Init();
    Lcd_Clear();
    while(1)
    {
        
    }
    return (EXIT_SUCCESS);
}

