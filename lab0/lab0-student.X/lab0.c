// ******************************************************************************************* //
//
// File:         lab0.c
// Date:         
// Authors:      
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
    //TODO: Define states by name
    led4,
    led5,
    led6,
    led7
} stateType;

volatile stateType curState;

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

    //TODO: Change states if necessary.
    //Make sure if you use any variables that they are declared volatile!
}