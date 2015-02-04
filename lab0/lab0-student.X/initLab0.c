/*
* File:   initLab0.c
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#include "p24fj64ga002.h"
#include "initLab0.h"

#define FCY 14745600.0
#define ONE_MILLISECOND 57
#define TIME_DELAY 2

void initLEDs(){
    //TODO: Initialize the pin connected to the LEDs as outputs
    TRISBbits.TRISB15 = 0;
    TRISBbits.TRISB14 = 0;
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB12 = 0;

    LATBbits.LATB15 = OFF;
    LATBbits.LATB14 = OFF;
    LATBbits.LATB13 = OFF;
    LATBbits.LATB12 = OFF;
    //TODO: Turn each LED OF
}

void initSW1(){
    //TODO: Initialize the pin connected to the switch as an input.
    TRISBbits.TRISB5 = 1;
    IFS1bits.CNIF = 0;
    IEC1bits.CNIE = 1;
    CNEN2bits.CN27IE = 1;
}


void initTimer1(){
    unsigned int prVal = (FCY*TIME_DELAY)/256.0 - 1;
    PR1 = prVal;
    T1CONbits.TCKPS = 0b11; //prescalar 256
    IEC0bits.T1IE = 1; // Enable the interrupt
    IFS0bits.T1IF = 0; // Put the interrupt flag down
    T1CONbits.TON = 1; // Turn the timer 1 on
    
}