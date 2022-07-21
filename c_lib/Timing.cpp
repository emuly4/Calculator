/////Includes/////
#include "Timing.h"


/** These define the internal counters that will be updated in the ISR to keep track of the time
 *  The volatile keyword is because they are changing in an ISR, the static means they are not
 *  visible (not global) outside of this file.
 */
static volatile uint32_t _count_ms = 0;

/**
 * Function Initialize_Timing initializes Timer0 to have a prescalar of XX and initializes the compare
 * feature for use in an ISR.  It also enables ISR's.
 *
 *  FCPU = 16 000 000 Hz,  1 us => 1 000 000 Hz,  A prescalar of 16 would give you millisecond resolution, but you dont
 *  have enough time to do those additions every microsecond, in addition the 8-bit timer will roll over every 256 microseconds.
 *  So, you need to be counting in (effectively) 4us increments.  So use a prescalar of 64. This will give you a resolution of 4us per
 *  Timer0 Bit and enough head-room to compare at with 249 for a 1kHz update.
 *
 *  Since Timer 0 will be triggering at a kHz, we may want other things to be updated at 1kHz too.
 *
 */
void Initialize_Timing()
{   // Initialize the Prescalar to 64
    TCCR0B |= (1<<CS01) | (1<<CS00);
    //Set output compare value
    OCR0A = 249;
    //Set interrupt flag to matcch output compare
    TIMSK0 |= (1<<OCIE0A);
    //Run SEI
    sei();
    //Intialize millisecond counter
    _count_ms= 0;
}

/**
 * This function gets the current time and returns it in a Time_t structure.
 * @return
 */
float  Timing_Get_Time_Sec()
{
    float seconds;
    Time_t currTime = Timing_Get_Time();
    seconds = currTime.millisec;
    seconds /= 1000.0;
    float updateMicro = currTime.microsec;
    updateMicro /= 1000000.0;
    seconds += updateMicro;

    return seconds;
}
Time_t Timing_Get_Time()
{

    Time_t time;
    time.millisec = _count_ms;
    time.microsec = TCNT0 * 4;

    return time;
}

/**
 * These functions return the individual parts of the Time_t struct, useful if you only care about
 * things on second or millisecond resolution.
 * @return
 */
uint32_t Timing_Get_Milli()
{
    return _count_ms;
}
uint16_t Timing_Get_Micro()
{
    return TCNT0 * 4;
}


/**
 * This function takes a start time and calculates the time since that time, it returns it in the Time struct.
 * @param p_time_start a pointer to a start time struct
 * @return (Time_t) Time since the other time.
 */
float  Timing_Seconds_Since(const Time_t* time_start_p )
{
    float currTime = Timing_Get_Time_Sec();

    float updateMilli = time_start_p->millisec;
    updateMilli /= 1000.0;
    float updateMicro = time_start_p->microsec;
    updateMicro /= 1000000.0;

    float delta_time = currTime - (updateMicro + updateMilli);

    return delta_time;
}

/** This is the Interrupt Service Routine for the Timer0 Compare A feature.
 * You'll need to set the compare flags properly for it to work.
 */
ISR(TIMER0_COMPA_vect)
{
    
    // YOU NEED TO RESET THE Timer0 Value to 0 again!
    TCNT0 = 0;
    // take care of upticks of both our internal and external variables.
    _count_ms ++;

}
