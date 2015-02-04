// ******************************************************************************************* //
//
// File:         lab0.c
// Date:         
// Authors:      Ben Yates
//
// Description:  Lab 0 assignment for ECE 372 Spring 2015.
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include "initLab0.h"
#include <stdio.h>

// ******************************************************************************************* //
// Configuration bits for CONFIG1 settings.
//
// These settings are appropriate for debugging the PIC microcontroller. If you need to
// program the PIC for standalone operation, change the COE_ON option to COE_OFF.

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF &
          BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )



typedef enum stateTypeEnum{

    led4,
    led5,
    led6,
    led7
} stateType;

volatile stateType curState;
volatile int count = 0;
int main(void)
{

    //TODO: Finish these functions in the provided c files
    initLEDs();
    initTimer1();
    initSW1();
    curState = led4;
    while(1)
    {
        //Use a switch statement to define the behavior based on the state
//        switch(){
//
//        }
        switch(curState){
            case led4:
                turnOnLED(4);
                break;
            case led5:
                turnOnLED(5);
                break;
            case led6:
                turnOnLED(6);
                break;
            case led7:
                turnOnLED(7);
                break;
    }
    
}
return 0;
}

void _ISR _T1Interrupt(void){
    //TODO: Put down the timer 1 flag first!
    IFS0bits.T1IF = 0;
    count = count +1;

    //TODO: Change states if necessary.
    //Make sure if you use any variables that they are declared volatile!
}

void _ISR _CNInterrupt(void){
    IFS1bits.CNIF = 0;//puts the sw1 interrupt down
    //need to turn the timer on
    if(PORTBbits.RB5 == PRESSED ){
    T1CONbits.TON = 1;//this should turn the timer2 on
    TMR1 = 0;
    }
    if(PORTBbits.RB5 == RELEASED && count >= 4){//this if statement should check
        if(curState == led4) {  //that count =4=2seconds and that the button was
            curState = led7;    //released when these conditions are met it
            count = 0;
            T1CONbits.TON = 0;  //should turn on the previous LED and turn off
        }                       //the current LED and turn off the timer
        else if(curState == led5){
            curState = led4;
            count = 0;
            T1CONbits.TON = 0;
        }
        else if(curState == led6){
            curState = led5;
            count = 0;
            T1CONbits.TON = 0;
        }
        else if(curState == led7){
            curState = led6;
            count = 0;
            T1CONbits.TON = 0;
        }
    }else if (PORTBbits.RB5 == RELEASED){
        if(curState == led4) {
            curState = led5;
            count = 0;
            T1CONbits.TON = 0;
        }
        else if(curState == led5){
            curState = led6;
            count = 0;
            T1CONbits.TON = 0;
        }
        else if(curState == led6) {
            curState = led7;
            count = 0;
            T1CONbits.TON = 0;
        }
        else if(curState == led7) {
            curState = led4;
            count = 0;
            T1CONbits.TON = 0;
        }
    }
    
}
