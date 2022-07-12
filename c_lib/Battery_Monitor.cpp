#include "Battery_Monitor.h"
#define initialize_LED()  DDRC |= (1 << DDC7)    // Make pin 13 be an output.

#define LED_ON()      PORTC |= (1 << PORTC7)   // Turn the LED on.

#define LED_TOGGLE()  PORTC ^= (1 << PORTC7)   // Toggles the led state

#define LED_OFF()     PORTC &= ~(1 << PORTC7)  // Turn the LED off.
static const float BITS_TO_BATTERY_VOLTS = 10.0/1023.0;

/**
 * Function Battery_Monitor_Init initializes the Battery Monitor to record the current battery voltages.
 */
void Battery_Monitor_Init()
{
    
    ADCSRA |= (1<<ADEN);
    // ADCSRB |= (1<<ADHSM); //does nothing
	ADMUX |= (1<<MUX1) | (1<<MUX2) | (1<<REFS0);
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
    DIDR0 |= (1<<ADC6D);

}

/**
 * Function Battery_Voltage initiates the A/D measurement and returns the result for the battery voltage.
 */
float Battery_Voltage()
{
    // ADMUX |= (1<<MUX1) | (1<<MUX2);
    ADCSRA |= (1 << ADSC);

    while(bit_is_set(ADCSRA, ADSC) != 0){}

    // A Union to assist with reading the LSB and MSB in the  16 bit register
    union { struct {uint8_t LSB; uint8_t MSB; } split; uint16_t value;} data;

    data.split.LSB = ADCL;
    data.split.MSB = ADCH;

    float voltage = data.value;

    return voltage * BITS_TO_BATTERY_VOLTS;
    //return data.value;

}
