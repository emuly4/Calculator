/////Includes/////

#include "LCD.h"

/////Class Function Definitions/////

LCDScreen::LCDScreen(){
    /////Character Definitions/////
    zero = 0b00110000;
    one = 0b00110001;
    two = 0b00110010;
    three = 0b00110011;
    four = 0b00110100;
    five = 0b00110101;
    six = 0b00110110;
    seven = 0b00110111;
    eight = 0b00111000;
    nine = 0b00111001;
    plus = 0b00101011;
    minus = 0b00101101;
    divide1 = 0b00101111;
    multiply = 0b00101010;
    exponent = 0b01011110;
    equal = 0b00111101;
    divide2 = 0b11111101;
    space = 0b11111110;
    a = 0b01100001;
    b = 0b01100010;
    c = 0b01100011;
    e = 0b01100101;
    l = 0b01101100;
    o = 0b01101111;
    r = 0b01110010;
    t = 0b01110100;
    k = 0b01101011;
}

void LCDScreen::write4bits(uint8_t fourBit){
    //Wait 1e-3 seconds
    
    //Set D7,D6,D5,D4 to Bit3, Bit2, Bit1, Bit0
    if(((fourBit & (1 << 3)) >> 3) == 1){
        OutputHigh(ButtonP_F, LCD_D7);
    }else{
        OutputLow(ButtonP_F, LCD_D7);
    }
    if(((fourBit & (1 << 2)) >> 2) == 1){
        OutputHigh(ButtonP_F, LCD_D6);
    }else{
        OutputLow(ButtonP_F, LCD_D6);
    }
    if(((fourBit & (1 << 1)) >> 1) == 1){
        OutputHigh(ButtonP_F, LCD_D5);
    }else{
        OutputLow(ButtonP_F, LCD_D5);
    }
    if(((fourBit & (1 << 0)) >> 0) == 1){
        OutputHigh(ButtonP_F, LCD_D4);
    }else{
        OutputLow(ButtonP_F, LCD_D4);
    }
    //Pulse EN
    pulseEn();
}

void LCDScreen::clearDisplay(){
    //WriteCharacter (00000001) -> Clear Display
    writeCharacter(0b00000001);
}

void LCDScreen::pulseEn(){
    //EN Pin Low
    OutputLow(ButtonP_F, LCD_EN);
    //Wait >450 ns

    //EN Pin High
    OutputHigh(ButtonP_F, LCD_EN);
    //Wait >450 ns

    //EN Pin Low
    OutputLow(ButtonP_F, LCD_EN);
    //Wait >37ms -> prior to sending commands
}

void LCDScreen::initializeLCD(){
    //Pull RS Pin Low
    OutputLow(ButtonP_F, LCD_RS);
    //Write4Bit (0011)
    write4bits(0b00000011);
    //Pulse EN
    pulseEn();
    //Write4Bit (0011)
    write4bits(0b00000011);
    //Pulse EN
    pulseEn();
    //Write4Bit (0011)
    write4bits(0b00000011);
    //Pulse EN
    pulseEn();
    //Write4Bit (0010)
    write4bits(0b00000010);
    //WriteCharacter (00101100) -> LCD Function Setup
    writeCharacter(0b00101100);
    //WriteCharacter (00001111) -> Display Format
    writeCharacter(0b00001111);
    //Clear Display
    clearDisplay();
    //WriteCharacter (00000110) -> Entry Mode
    writeCharacter(0b00000110);
}

void LCDScreen::writeCharacter(uint8_t eightBit){
    //RS Pin Goes High
    OutputHigh(ButtonP_F, LCD_RS);
    //Wait 1e-3 seconds

    //Set D7,D6,D5,D4 to Bit7, Bit6, Bit5, Bit4 respectibly
    if(((eightBit & (1 << 7)) >> 7) == 1){
        OutputHigh(ButtonP_F, LCD_D7);
    }else{
        OutputLow(ButtonP_F, LCD_D7);
    }
    if(((eightBit & (1 << 6)) >> 6) == 1){
        OutputHigh(ButtonP_F, LCD_D6);
    }else{
        OutputLow(ButtonP_F, LCD_D6);
    }
    if(((eightBit & (1 << 5)) >> 5) == 1){
        OutputHigh(ButtonP_F, LCD_D5);
    }else{
        OutputLow(ButtonP_F, LCD_D5);
    }
    if(((eightBit & (1 << 4)) >> 4) == 1){
        OutputHigh(ButtonP_F, LCD_D4);
    }else{
        OutputLow(ButtonP_F, LCD_D4);
    }
    //Pulse EN
    pulseEn();
    //Set D7,D6,D5,D4 to Bit3, Bit2, Bit1, Bit0 respectibly
    if(((eightBit & (1 << 3)) >> 3) == 1){
        OutputHigh(ButtonP_F, LCD_D7);
    }else{
        OutputLow(ButtonP_F, LCD_D7);
    }
    if(((eightBit & (1 << 2)) >> 2) == 1){
        OutputHigh(ButtonP_F, LCD_D6);
    }else{
        OutputLow(ButtonP_F, LCD_D6);
    }
    if(((eightBit & (1 << 1)) >> 1) == 1){
        OutputHigh(ButtonP_F, LCD_D5);
    }else{
        OutputLow(ButtonP_F, LCD_D5);
    }
    if(((eightBit & (1 << 0)) >> 0) == 1){
        OutputHigh(ButtonP_F, LCD_D4);
    }else{
        OutputLow(ButtonP_F, LCD_D4);
    }
    //Pulse EN
    pulseEn();
}

void LCDScreen::wait(int time){
    //While time hasn't been reached ->timing get time since
}