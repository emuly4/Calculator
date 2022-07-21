/////Includes/////
#include "DigitalIO.h"

DigitalIO::DigitalIO(){
    //Initialize Inputs
    setInput(ButtonDDR_D, Button_D0); // Sets pin as an Input on the Data Direction Register
    //
    setInput(ButtonDDR_D, Button_D1); // Sets pin as an Input on the Data Direction Register
    //
    setInput(ButtonDDR_D, Button_D4); // Sets pin as an Input on the Data Direction Register
    //
    setInput(ButtonDDR_C, Button_D5); // Sets pin as an Input on the Data Direction Register
    //
    setInput(ButtonDDR_D, Button_D6); // Sets pin as an Input on the Data Direction Register
    //
    setInput(ButtonDDR_E, Button_D7); // Sets pin as an Input on the Data Direction Register
    //Initialize Outputs
    /* Initialize LCD Digital IO Pins*/
    setOuput(ButtonDDR_F, LCD_D4); //Sets pin as an Output on the Data Direction Register
    OutputLow(ButtonP_F, LCD_D4); //Sets output pin low (sink)
    //
    setOuput(ButtonDDR_F, LCD_D5); //Sets pin as an Output on the Data Direction Register
    OutputLow(ButtonP_F, LCD_D5); //Sets output pin low (sink)
    //
    setOuput(ButtonDDR_F, LCD_D6); //Sets pin as an Output on the Data Direction Register
    OutputLow(ButtonP_F, LCD_D6); //Sets output pin low (sink)
    //
    setOuput(ButtonDDR_F, LCD_D7); //Sets pin as an Output on the Data Direction Register
    OutputLow(ButtonP_F, LCD_D7); //Sets output pin low (sink)
    //
    setOuput(ButtonDDR_F, LCD_RS); //Sets pin as an Output on the Data Direction Register
    OutputLow(ButtonP_F, LCD_RS); //Sets output pin low (sink)
    //
    setOuput(ButtonDDR_F, LCD_EN); //Sets pin as an Output on the Data Direction Register
    OutputLow(ButtonP_F, LCD_EN); //Sets output pin low (sink)
    //
    /* Initialize Button Outputs */
    setOuput(ButtonDDR_B, Button_D9); //Sets pin as an Output on the Data Direction Register
    OutputLow(ButtonP_B, Button_D9); //Sets output pin low (sink)
    //
    setOuput(ButtonDDR_B, Button_D10); //Sets pin as an Output on the Data Direction Register
    OutputLow(ButtonP_B, Button_D10); //Sets output pin low (sink)
    //
    setOuput(ButtonDDR_B, Button_D11); //Sets pin as an Output on the Data Direction Register
    OutputLow(ButtonP_B, Button_D11); //Sets output pin low (sink)
    //
    setOuput(ButtonDDR_D, Button_D12); //Sets pin as an Output on the Data Direction Register
    OutputLow(ButtonP_D, Button_D12); //Sets output pin low (sink)
}

uint8_t DigitalIO::readInputs(){

}

void DigitalIO::toggleOutputs(){

}

bool DigitalIO::isButtonPressed(){

}

void DigitalIO::writeOutput(){

}
