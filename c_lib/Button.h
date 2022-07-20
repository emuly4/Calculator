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
#define Button_D0 PIND2
#define Button_D1 PIND3
#define Button_D4 PIND4
#define Button_D5 PINC6
#define Button_D6 PIND7
#define Button_D7 PINE6
#define Button_D9 PINB5
#define Button_D10 PINB6
#define Button_D11 PINB7
#define Button_D12 PIND6

//Functions
#define initialize_LED(ddr, pin)  ddr |= (1 << pin)    // Set Digital Output
#define initialize_LED(ddr, pin)  ddr |= (1 << pin)    // Set Digital Input
#define initialize_LED(ddr, pin)  ddr |= (1 << pin)    // Toggle Output
static inline bool Left_A()   { return bit_is_set(PIND, PIND2) != 0 ? true: false; } // 

class Button
{
public:

bool buttonPressed;

int prevButton;

int newButton;

initializeButtons();

readInputs();

toggleOutputs();

isButtonPressed();
};