#include "Encoder.h"
#include <avr/interrupt.h>
#include <util/atomic.h>

// #include "print.h"
// #include "usb_debug_only.h"
/**
* Internal counters for the Interrupts to increment or decrement as necessary.
*/
static volatile int32_t _left_counts;   // Static limits it's use to this file
static volatile int32_t _right_counts;  // Static limits it's use to this file

/** Helper Funcions for Accessing Bit Information */

static inline bool Right_B()   {return bit_is_set(PINF, PINF4) != 0 ?  true:  false; } // MEGN540 Lab 3 TODO
static inline bool Right_A()   { return bit_is_set(PINE, PINE6) != 0 ?  true:  false;  }

static inline bool Left_B()   { return bit_is_set(PIND, PIND6) != 0 ? true: false; } // MEGN540 Lab 3 TODO
static inline bool Left_A()   { return bit_is_set(PIND, PIND2) != 0 ? true: false; } // MEGN540 Lab 3 TODO


volatile bool NOW_B;
volatile bool NOW_A;

/**
 * Function Encoders_Init initializes the encoders, sets up the pin change interrupts, and zeros the initial encoder
 * counts.
 */
void Encoders_Init()
{
    //INT6 Interupt Setup:
    uint8_t INT6_MASK = (!(255 & (1<<INT6)));
    
    EIMSK &= INT6_MASK;         //Set int6 interrupt to off

    EICRB |= (1 << ISC60);       // ISC60 = 1 and ISC61 = 0 sets any logical change to trigger INT6 interrupt

    uint8_t REGE_MASK = (!(255 & (1<<DDE6))); //Digitial Pin E6 aka Right-A
    DDRE &= REGE_MASK;

    uint8_t REGF_MASK = (!(255 & (1<<DDF4))); //Digital Pin F4 aka Right-B
    DDRF &= REGF_MASK;

    //INT2 Interupt Setup:
    uint8_t INT2_MASK = !(255 & (1<<INT2));
    
    EIMSK &= INT2_MASK;         //Set int6 interrupt to off

    EICRA |= (1 << ISC20);       // ISC60 = 1 and ISC61 = 0 sets any logical change to trigger INT2 interrupt

    uint8_t REGD_MASK = (!(!(255 & (1<<DDD2)) & (1<<DDD6)));//Digitial Pin D2 aka Left-A and Digitial Pin D6 aka Left-B
    DDRD &= REGD_MASK;

    //Turn INT2 and INT6 on
    EIMSK = 0b01000100;
    //Initialize Counts
    _left_counts = 0;  // MEGN540 Lab 3 TODO
    _right_counts = 0;  // MEGN540 Lab 3 TODO

}


/**
 * Function Counts_Left returns the number of counts from the left encoder.
 * @return [int32_t] The count number.
 */
int32_t Counts_Left()
{
    unsigned char SREG_status = SREG;
    int32_t counts;
    
    //__disable_interrupt();
    cli();
    //ATOMIC_BLOCK {ATOMIC_RESTORESTATE{counts = _left_counts;}}
    counts = _left_counts;
    SREG = SREG_status;

    // Note: Interrupts can trigger during a function call and an int32 requires
    // multiple clock cycles to read/save. You may want to stop interrupts, copy the value,
    // and re-enable interrupts to prevent this from corrupting your read/write.
    return counts;
}

/**
 * Function Counts_Right returns the number of counts from the right encoder.
 * @return [int32_t] The count number.
 */
int32_t Counts_Right()
{
    unsigned char SREG_status = SREG;
    int32_t counts;

    //__disable_interrupt();
    cli();
    //ATOMIC_BLOCK {ATOMIC_RESTORESTATE{counts = _right_counts;}}
    counts = _right_counts;
    SREG = SREG_status;

    // Note: Interrupts can trigger during a function call and an int32 requires
    // multiple clock cycles to read/save. You may want to stop interrupts, copy the value,
    // and re-enable interrupts to prevent this from corrupting your read/write.
    return counts;
}

/**
 * Function Rad_Left returns the number of radians for the left encoder.
 * @return [float] Encoder angle in radians
 */
float Rad_Left()
{
    // return 5.0;
    //return (float)Counts_Left();
    return -(((float)Counts_Left()) * 2 * M_PI) / 700.0;
}

/**
 * Function Rad_Right returns the number of radians for the left encoder.
 * @return [float] Encoder angle in radians
 */
float Rad_Right()
{
    // YOUR CODE HERE.  How many counts per rotation???
    // return 5.0;
    // return (float)Counts_Right();
    return (((float)Counts_Right()) * 2 * M_PI) / 700.0; //Changed from 909.7->700
}

/**
 * Interrupt Service Routine for the Right Encoder.
 * @return
 */
ISR(INT6_vect)
{
    NOW_B = Right_B();
    NOW_A = Right_A();
    if(NOW_A == NOW_B){
        _right_counts += 1;
    }else{
        _right_counts -= 1;
    }
    //print("Right");
}


/**
 * Interrupt Service Routine for the left Encoder.
 * @return
 */
ISR(INT2_vect)
{
    NOW_B = Left_B();
    NOW_A = Left_A();
    if(NOW_A == NOW_B){
        _left_counts += 1;
    }else{
        _left_counts -= 1;
    }
    //print("Left");
}