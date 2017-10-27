/* 
 * File:   CountMain.c
 * Author: caheidecker
 *
 * Created on October 26, 2017, 6:25 PM
 http://microchipdeveloper.com/8bit:timer0count
 https://electrosome.com/switch-debouncing/
 https://electrosome.com/wp-content/uploads/2012/12/Hardware-Switch-Debouncing.jpg
 http://www.eng.utah.edu/~cs5780/debouncing.pdf
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

//@TODO add counters set to 0
//@TODO Make Interrupt Function
void interrupt Timer0_ISR(void)
{
    if (T0IE && T0IF)
    {
        T0IF = 0;
        ++counter;
    }
}

//are TMR0 interrupts enabled and
//is the TMR0 interrupt flag set?
//TMR0 interrupt flag must be
//cleared in software
//to allow subsequent interrupts
//increment the counter variable
//by 1
int main(int argc, char** argv) 
{
    Lcd_Init();
    Lcd_Clear();
    //@TODO Set up configs
    //ANSEL = 0xFB;//Configure T0CKI/AN2 as a digital I/O
    TMR0 = 0;
    //OPTION = 0x28; external clock source
    T0IE = 1;
    GIE = 1;
    
    while(1)
    {
        //@TODO Add handler for button push
        //@TODO On push increment count
        //@TODO send count to array
        //@TODO send array to lcd
        //@TODO just chill till interrupt is triggered again
    }
    return (EXIT_SUCCESS);
}

