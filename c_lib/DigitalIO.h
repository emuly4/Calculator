#ifndef DIGITAL_IO_H
#define DIGITAL_IO_H
/////Includes/////
#include <avr/io.h>
//////Defines/////
//LCD Pin Definitions
#define LCD_D4 PINF7
#define LCD_D5 PINF6
#define LCD_D6 PINF5
#define LCD_D7 PINF4
#define LCD_RS PINF1
#define LCD_EN PINF0
//Button Pin Definitions
//Input
#define Button_D0 PIND2
#define Button_D1 PIND3
#define Button_D4 PIND4
#define Button_D5 PINC6
#define Button_D6 PIND7
#define Button_D7 PINE6
//Output
#define Button_D9 PINB5
#define Button_D10 PINB6
#define Button_D11 PINB7
#define Button_D12 PIND6
//DDRx Definitions
#define ButtonDDR_B DDRB
#define ButtonDDR_C DDRC
#define ButtonDDR_D DDRD
#define ButtonDDR_E DDRE
#define ButtonDDR_F DDRF
//PORT Definitions
#define ButtonP_B PORTB
#define ButtonP_C PORTC
#define ButtonP_D PORTD
#define ButtonP_E PORTE
#define ButtonP_F PORTF

//Functions
#define setOuput(ddr, port)  ddr |= (1 << port)    // Set Digital Output
#define OutputLow(port, pin)  port &= ~(1 << pin)    // Set Digital Output Low (Sink)
#define OutputHigh(port, pin)  port |= (1 << pin)    // Set Digital Output High (Source)
#define setInput(ddr, pin)  ddr &= ~(1 << pin)    // Set Digital Input
#define ToggleOutput(port, pin)  port ^= (1 << pin)    // Toggle Output High/Low (Source/Sink)
//static inline bool readInputs(Button_D0, Button_D10)   { return bit_is_set(PIND, PIND2) != 0 ? true: false; } // Read Inputs

class DigitalIO
{
public:

bool buttonPressed;

int prevButton;

int newButton;

DigitalIO();

uint8_t readInputs();

void toggleOutputs();

bool isButtonPressed();

void writeOutput();

};
#endif /* DIGITAL_IO_H */