/////Includes/////

#include "LCD.h"

/////Class Function Definitions/////

LCDScreen::write4bits(){
    //Wait 1e-3 seconds
    
    //Set D7,D6,D5,D4 to Bit3, Bit2, Bit1, Bit0

    //Pulse EN
}

LCDScreen::clearDisplay(){
    //WriteCharacter (00000001) -> Clear Display
}

LCDScreen::pulseEn(){
    //EN Pin Low

    //Wait >450 ns

    //EN Pin High

    //Wait >450 ns

    //EN Pin Low

    //Wait >37ms -> prior to sending commands
}

LCDScreen::initializeLCD(){
    //Pull RS Pin Low

    //Write4Bit (0011)

    //Pulse EN

    //Write4Bit (0011)

    //Pulse EN

    //Write4Bit (0011)

    //Pulse EN

    //Write4Bit (0010)

    //WriteCharacter (00101100) -> LCD Function Setup

    //WriteCharacter (00001111) -> Display Format

    //Clear Display

    //WriteCharacter (00000110) -> Entry Mode
}

LCDScreen::writeCharacter(){
    //RS Pin Goes High
    
    //Wait 1e-3 seconds

    //Set D7,D6,D5,D4 to Bit7, Bit6, Bit5, Bit4 respectibly

    //Pulse EN

    //Set D7,D6,D5,D4 to Bit3, Bit2, Bit1, Bit0 respectibly

    //Pulse EN

}
