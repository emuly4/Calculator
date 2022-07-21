#ifndef LCD_H
#define LCD_H
/////Includes/////
#include "DigitalIO.h"
#include "Timing.h"

class LCDScreen
{
private:
    // /////Character Definitions/////
    uint8_t zero, one, two, three, four, five, 
            six, seven, eight, nine, plus,
            minus, divide1, multiply, exponent, 
            equal, divide2, space, a, b, c, e, 
            l, o, r, t, k;

public:

    Time_t timer;

    LCDScreen();

    /*
    Write 4 Bits is a function only used in initialization of the screen before
    the screen is offically set to operate in 4-bit digital mode (which requires only 4 of the 8 digital pins on the LCD Screen)
    */
    void write4bits(uint8_t);

    void clearDisplay();
    
    void initializeLCD();
    
    void writeCharacter(uint8_t);

    void pulseEn();

    void wait(int);
    
};

#endif /*LCD_H*/