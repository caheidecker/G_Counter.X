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

#define _XTAL_FREQ 16000000

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

#define SWITCH PORTAbits.RA4

#pragma config FOSC=INTIO67
#pragma config WDTEN=OFF
#pragma config PWRTEN=ON
#pragma config LVP = OFF

#include <xc.h>			
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LCD.h"
#include <p18f26k22.h>



//@TODO add counters set to 0
unsigned int counter, x;
char array[25];
//@TODO Make Interrupt Function

void interrupt Timer0_ISR(void)
{
    if (INTCONbits.TMR0IF == 1)
    {   
        //counter++;
    }
    INTCONbits.TMR0IF = 0;
}

int main(int argc, char** argv) 
{
    counter = 0;
    //@TODO Set up configs
    OSCCON = 0x72;
    ANSELB = 0;//PORTB digital
    ANSELC = 0;//PORTC digital
    ANSELA = 0;//PORTA digital
    TRISB = 0xC0;
    TRISC = 0;
    TRISAbits.RA4 = 1; //RA4 as input
    T0CON = 0x68;
    TMR0L = 246;
    
    INTCONbits.TMR0IE = 1;//enable timer interrupt
    INTCONbits.TMR0IF = 0;//clear flag
    INTCONbits.PEIE = 1;//enable peripheral interrupt
    INTCONbits.GIE = 1; //global interrupt
    
    T0CONbits.TMR0ON = 1; //timer 0 on
    
    Lcd_Init();
    Lcd_Clear();
    Lcd_Write_String("0");
    while(1)
    {
        if (!SWITCH)
        {
        TMR0L = counter;
        counter++;
        Lcd_Set_Cursor(1,1);
        utoa(array,counter,10);
        Lcd_Write_String(array);
        __delay_ms(250);
        break;
        }
    }
    return (EXIT_SUCCESS);
}

