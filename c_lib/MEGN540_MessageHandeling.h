/*
         MEGN540 Mechatronics Lab
    Copyright (C) Andrew Petruska, 2021.
       apetruska [at] mines [dot] edu
          www.mechanical.mines.edu
*/

/*
    Copyright (c) 2021 Andrew Petruska at Colorado School of Mines

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.

*/

/*
 * This file defines the incomming message length and other details.
 */

#ifndef MEGN540_MESAGEHANDELING_H
#define MEGN540_MESAGEHANDELING_H

#define initialize_LED()  DDRC |= (1 << DDC7)    // Make pin 13 be an output.

#define LED_ON()      PORTC |= (1 << PORTC7)   // Turn the LED on.

#define LED_TOGGLE()  PORTC ^= (1 << PORTC7)   // Toggles the led state

#define LED_OFF()     PORTC &= ~(1 << PORTC7)  // Turn the LED off.


#include "SerialIO.h"
#include "Timing.h"
#include "Task_Management.h"
#include "MotorPWM.h"
#include "Controller.h"
#include "ZoomieZumo.h"
#include <stdlib.h>

// Define message driving task objects here. These are global.  You'll need to add to the list for subsiquent labs
static Task_t task_restart;                ///<-- This flag indicates that the device received a restart command from the hoast. Default inactive.
static Task_t task_time_loop;              ///<-- Indicates if the system should report time to complete a loop.
static Task_t task_send_time_now;          ///<-- Indicates if the system should send the current time.
static Task_t task_send_battery_voltage;   ///<-- Indicates if the system should send battery voltage
static Task_t task_filter_voltage;         ///<-- Filters Battery Voltage constantly
static Task_t task_send_encoder_vals;     ///<-- Indicates if the system should send encoder vals
static Task_t task_set_pwm;                ///<-- Enables PWM
static Task_t task_send_system_ID;         ///<-- Sends System Indentification values
static Task_t task_controller_update;      ///<-- Updates the Left and Right Motor Controller Values
static Task_t task_CTRL;                   ///<-- Big Control

/**
 * Function Message_Handler processes USB messages as necessary and sets status flags to control the flow of the program.
 * It returns true unless the program receives a reset message.
 * @return
 */
void Message_Handling_Task();

/**
 * Function MEGN540_Message_Len returns the number of bytes associated with a command string per the
 * class documentation;
 * @param cmd
 * @return Size of expected string. Returns 0 if unrecognized.
 */
uint8_t MEGN540_Message_Len( char cmd );

#endif