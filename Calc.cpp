/*
Calculator Project
Author: Emil Muly
Date Created: 7/12/2022

Date Last Edited: 7/20/2022
Version 1

Description:
This file contains the main loop for the calculator program.
*/

//Headers
#include "Calculator.h"

//Initializations
    //LCD Screen
    LCDScreen DisplayScreen;
    //Keypad Matrix

//Main Loop
int main(void){
    initialize_LED(DEBUG_DDR, DEBUG_REDLED);
    DisplayScreen.initializeLCD();
    //Infinite While
    while(1){
        //Read Key Value Pressed
        LED_OFF(PORTC, DEBUG_REDLED);
        //Perform Operation
            //Deal With Errors
    }

    return 0;
}
