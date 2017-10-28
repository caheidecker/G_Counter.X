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
#include <pic18f26k22.h>

//@TODO add counters set to 0
int counter = 0;
//array to store int to then write to lcd
char array[100];

//@TODO Make Interrupt Function
void interrupt Timer0_ISR(void)
{
    
    if (T0IE && T0IF)
    {
        //Possibly needed to clear the lcd everytime it is pushed before rewriting
        //Lcd_Clear();
        T0IF = 0;
        counter++;
    }
}

int main(int argc, char** argv) 
{
    Lcd_Init();
    Lcd_Clear();
    //@TODO Set up configs
    ANSELB=0;//PORTB digital
    ANSELC=0;//PORTC digital
    ANSELA = 0xFB;//Configure T0CKI/AN2 as a digital I/O
    TRISA = 1;
    TRISB= 0;
    TRISC= 0;
    
    TMR0 = 0;
    //@TODO Fix interrupt configs
    //OPTION = 0x28; external clock source
    //T0IE = 1;
    //GIE = 1;
    
    while(1)
    {
        Lcd_Set_Cursor(1,1);
        //@TODO send count to array
        //I Think this is right double check; Assign it to a new variable 
        itoa(counter,array,10);
        //@TODO send array to lcd
        Lcd_Write_String(array);
        //@TODO just chill till interrupt is triggered again
        //__delay_ms(100);//Lcd Refresh
        
        /*
         * Plan B
         * Convert the into to ASCII by counter + 48 = newVal
         * then just send newVal directly to lcd as it will read the correct value
         */
    }
    return (EXIT_SUCCESS);
}

