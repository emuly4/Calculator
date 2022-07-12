
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

#include "MEGN540_MessageHandeling.h"

extern struct MotorController MotorControllers;
// static inline void MSG_FLAG_Init(MSG_FLAG_t* p_flag)
// {
//     p_flag->active = false;
//     p_flag->duration = -1;
//     p_flag->last_trigger_time.millisec=0;
//     p_flag->last_trigger_time.microsec=0;
// }


/**
 * Function Message_Handler processes USB messages as necessary and sets status flags to control the flow of the program.
 * It returns true unless the program receives a reset message.
 * @return
 */
void Message_Handling_Task()
{
    // *** MEGN540  ***
    // YOUR CODE HERE. I suggest you use your peak function and a switch interface
    // Either do the simple stuff strait up, set flags to have it done later.
    // If it just is a USB thing, do it here, if it requires other hardware, do it in the main and
    // set a flag to have it done here.

    // Check to see if their is data in waiting
    if( !usb_msg_length() )
        
        return; // nothing to process...

    // Get Your command designator without removal so if their are not enough bytes yet, the command persists
    char command = usb_msg_peek();

    

    // process command
    switch( command )
    {
        case '*':
            if( usb_msg_length() >= MEGN540_Message_Len('*') )
            {
                //then process your times...

                // remove the command from the usb recieved buffer using the usb_msg_get() function
                usb_msg_get(); // removes the first character from the received buffer, we already know it was a * so no need to save it as a variable

                // Build a meaningful structure to put your data in. Here we want two floats.
                struct __attribute__((__packed__)) { float v1; float v2; } data;

                // Copy the bytes from the usb receive buffer into our structure so we can use the information
                usb_msg_read_into( &data, sizeof(data) );

                // Do the thing you need to do. Here we want to multiply
                float ret_val = data.v1 * data.v2;

                // send response right here if appropriate.
                usb_send_msg("cf", command, &ret_val, sizeof(ret_val));
            }
            break;
        case '/':
            if( usb_msg_length() >= MEGN540_Message_Len('/') )
            {
                // remove the command from the usb recieved buffer using the usb_msg_get() function
                usb_msg_get(); // removes the first character from the received buffer, we already know it was a * so no need to save it as a variable

                // Build a meaningful structure to put your data in. Here we want two floats.
                struct __attribute__((__packed__)) { float v1; float v2; } data;

                // Copy the bytes from the usb receive buffer into our structure so we can use the information
                usb_msg_read_into( &data, sizeof(data) );

                // Do the thing you need to do. Here we want to multiply
                float ret_val = data.v1 / data.v2;

                // send response right here if appropriate.
                usb_send_msg("cf", command, &ret_val, sizeof(ret_val));
            }
            break;
        case '+':
            if( usb_msg_length() >= MEGN540_Message_Len('+') )
            {
                
                // remove the command from the usb recieved buffer using the usb_msg_get() function
                usb_msg_get(); // removes the first character from the received buffer, we already know it was a * so no need to save it as a variable

                // Build a meaningful structure to put your data in. Here we want two floats.
                struct __attribute__((__packed__)) { float v1; float v2; } data;

                // Copy the bytes from the usb receive buffer into our structure so we can use the information
                usb_msg_read_into( &data, sizeof(data) );

                // Do the thing you need to do. Here we want to multiply
                float ret_val = data.v1 + data.v2;

                // send response right here if appropriate.
                usb_send_msg("cf", command, &ret_val, sizeof(ret_val));
            }
            break;
        case '-':
            if( usb_msg_length() >= MEGN540_Message_Len('-') )
            {
                // remove the command from the usb recieved buffer using the usb_msg_get() function
                usb_msg_get(); // removes the first character from the received buffer, we already know it was a * so no need to save it as a variable

                // Build a meaningful structure to put your data in. Here we want two floats.
                struct __attribute__((__packed__)) { float v1; float v2; } data;

                // Copy the bytes from the usb receive buffer into our structure so we can use the information
                usb_msg_read_into( &data, sizeof(data) );

                // Do the thing you need to do. Here we want to multiply
                float ret_val = data.v1 - data.v2;

                // send response right here if appropriate.
                usb_send_msg("cf", command, &ret_val, sizeof(ret_val));
            }
            break;
        case 'T':
            if( usb_msg_length() >= MEGN540_Message_Len('T') ){

                usb_msg_get();
                char time_cmd = usb_msg_get();
                union {
                    float period;
                    uint8_t arr[4];
                }period_U; 
                period_U.arr[0] = usb_msg_get();
                period_U.arr[1] = usb_msg_get();
                period_U.arr[2] = usb_msg_get();
                period_U.arr[3] = usb_msg_get();
                
                switch(time_cmd){
                    case 0x00:         //Time Now
                        task_send_time_now.is_active = true;
                        task_send_time_now.run_period = period_U.period;
                        
                        break;
                    case 0x01://Time to Loop
                        task_time_loop.is_active = true;
                        task_time_loop.run_period = period_U.period;
                        
                        break;
                    default: 
                        // What to do if you dont recognize the command character
                        usb_flush_input_buffer();
                        float ret_false = 0;
                        usb_send_msg("c", '!' , &ret_false, 0);
                        break;
                }
                
            }


            break;
        case 't':
            if( usb_msg_length() >= MEGN540_Message_Len('t') ){
                usb_msg_get();
                char time_cmd = usb_msg_get();
                switch(time_cmd){
                    case 0x00:      //Time Now
                    
                        task_send_time_now.is_active = true;
                        task_send_time_now.run_period = -1;
                        break;
                    case 0x01:      //Time to Loop
                        
                        task_time_loop.is_active = true;
                        task_time_loop.run_period = -1;
                        break;
                    default: 
                        // What to do if you dont recognize the command character
                        usb_flush_input_buffer();
                        float ret_false = 0;
                        usb_send_msg("c", '!' , &ret_false, 0);
                        break;
                }
            }
            break;
        case 'b':
            if( usb_msg_length() >= MEGN540_Message_Len('b') ){
                usb_msg_get();

                task_send_battery_voltage.is_active = true;
                task_send_battery_voltage.run_period = -1;
            }
            break;
        case 'B':
            if( usb_msg_length() >= MEGN540_Message_Len('B') ){
                usb_msg_get();
                
                union {
                    float period;
                    uint8_t arr[4];
                }period_U; 
                period_U.arr[0] = usb_msg_get();
                period_U.arr[1] = usb_msg_get();
                period_U.arr[2] = usb_msg_get();
                period_U.arr[3] = usb_msg_get();

                task_send_battery_voltage.is_active = true;
                task_send_battery_voltage.run_period = period_U.period;
            }
            break;
        case 'e':
            if( usb_msg_length() >= MEGN540_Message_Len('e') ){
                usb_msg_get();

                task_send_encoder_vals.is_active = true;
                task_send_encoder_vals.run_period = -1;
            }
            break;
        case 'E':
            if( usb_msg_length() >= MEGN540_Message_Len('E') ){
                usb_msg_get();
                
                union {
                    float period;
                    uint8_t arr[4];
                }period_U; 
                period_U.arr[0] = usb_msg_get();
                period_U.arr[1] = usb_msg_get();
                period_U.arr[2] = usb_msg_get();
                period_U.arr[3] = usb_msg_get();
                if(period_U.period > 0){
                    task_send_encoder_vals.is_active = true;
                    task_send_encoder_vals.run_period = period_U.period/1000;
                }
                
            }
            break;
        case 'p':       //Set PWM
            if( usb_msg_length() >= MEGN540_Message_Len('p') ){
                usb_msg_get();
                int16_t Left_PWM, Right_PWM;

                union {
                    int16_t word;
                    uint8_t arr[2];
                }WordToBytes;

                WordToBytes.arr[0] = usb_msg_get();
                WordToBytes.arr[1] = usb_msg_get();
                Left_PWM = WordToBytes.word;
                WordToBytes.arr[0] = usb_msg_get();
                WordToBytes.arr[1] = usb_msg_get();
                Right_PWM = WordToBytes.word;
                
                //Set Motor PWM Values
                Motor_PWM_Left(Left_PWM);
                Motor_PWM_Right(Right_PWM);

                Motor_PWM_Enable(true);

            }
            break;
        case 'P':
            if( usb_msg_length() >= MEGN540_Message_Len('P') ){
                usb_msg_get();
                int16_t Left_PWM, Right_PWM;

                union {
                    int16_t word;
                    uint8_t arr[2];
                }WordToBytes;

                WordToBytes.arr[0] = usb_msg_get();
                WordToBytes.arr[1] = usb_msg_get();
                Left_PWM = WordToBytes.word;
                //if(Left_PWM == 800){LED_ON();}
                WordToBytes.arr[0] = usb_msg_get();
                WordToBytes.arr[1] = usb_msg_get();
                Right_PWM = WordToBytes.word;


                union {
                    float period;
                    uint8_t arr[4];
                }period_U; 
                period_U.arr[0] = usb_msg_get();
                period_U.arr[1] = usb_msg_get();
                period_U.arr[2] = usb_msg_get();
                period_U.arr[3] = usb_msg_get();
                
                //Set Motor PWM Values
                Motor_PWM_Left(Left_PWM);
                Motor_PWM_Right(Right_PWM);
                Motor_PWM_Enable(true);
                


                task_set_pwm.is_active = true;
                task_set_pwm.run_period = period_U.period / 1000;

                //Set time since last ran to current time so the main loop waits exactly one period to run the task function.
                task_set_pwm.time_last_ran = Timing_Get_Time();

                
            }
            break;
        case 's':
            if( usb_msg_length() >= MEGN540_Message_Len('s') ){
                usb_msg_get();

                task_CTRL.is_active = false;
                task_controller_update.is_active = false;
                task_set_pwm.is_active = false;
                Motor_PWM_Enable(false);
                
            }
            break;
        case 'S':
            if( usb_msg_length() >= MEGN540_Message_Len('S') ){
                usb_msg_get();

                task_CTRL.is_active = false;
                task_controller_update.is_active = false;
                task_set_pwm.is_active = false;
                Motor_PWM_Enable(false);
            }
            break;
        case 'q':
            if( usb_msg_length() >= MEGN540_Message_Len('q') ){
                usb_msg_get();

                task_send_system_ID.is_active = true;
                task_send_system_ID.run_period = -1;
            }
            break;
        case 'Q':
            if( usb_msg_length() >= MEGN540_Message_Len('Q') ){
                usb_msg_get();

                union {
                    float period;
                    uint8_t arr[4];
                }period_U; 
                period_U.arr[0] = usb_msg_get();
                period_U.arr[1] = usb_msg_get();
                period_U.arr[2] = usb_msg_get();
                period_U.arr[3] = usb_msg_get();

                task_send_system_ID.is_active = true;
                task_send_system_ID.run_period = period_U.period;
            }
            break;
        case 'd':
            if( usb_msg_length() >= MEGN540_Message_Len('d') ){
                usb_msg_get();
                union {
                    float arc_len;
                    uint8_t arr[4];
                }arcLenUnion; 
                arcLenUnion.arr[0] = usb_msg_get();
                arcLenUnion.arr[1] = usb_msg_get();
                arcLenUnion.arr[2] = usb_msg_get();
                arcLenUnion.arr[3] = usb_msg_get();

                union {
                    float theta;
                    uint8_t arr[4];
                }thetaUnion; 
                thetaUnion.arr[0] = usb_msg_get();
                thetaUnion.arr[1] = usb_msg_get();
                thetaUnion.arr[2] = usb_msg_get();
                thetaUnion.arr[3] = usb_msg_get();
                
                Zumo_setDisplacement(arcLenUnion.arc_len, thetaUnion.theta);
                // ZumoController.lin_REF = arcLenUnion.arc_len;
                // ZumoController.ang_REF = thetaUnion.theta;
                // ZumoController.SetRef = Zumo_setDisplacement;

                // Controller_SetTo(&ZumoController.Controller_Left, Rad_Left());
                // Controller_SetTo(&ZumoController.Controller_Right, Rad_Right());

                
                Motor_PWM_Left(0);
                Motor_PWM_Right(0);

                //PWM Enable
                Motor_PWM_Enable(true);
                task_controller_update.is_active = true;

            }
            break;
        case 'D':
            if( usb_msg_length() >= MEGN540_Message_Len('D') ){
                usb_msg_get();

                union {
                    float arc_len;
                    uint8_t arr[4];
                }arcLenUnion; 
                arcLenUnion.arr[0] = usb_msg_get();
                arcLenUnion.arr[1] = usb_msg_get();
                arcLenUnion.arr[2] = usb_msg_get();
                arcLenUnion.arr[3] = usb_msg_get();

                union {
                    float theta;
                    uint8_t arr[4];
                }thetaUnion; 
                thetaUnion.arr[0] = usb_msg_get();
                thetaUnion.arr[1] = usb_msg_get();
                thetaUnion.arr[2] = usb_msg_get();
                thetaUnion.arr[3] = usb_msg_get();
                
                union {
                    float period;
                    uint8_t arr[4];
                }periodUnion; 
                periodUnion.arr[0] = usb_msg_get();
                periodUnion.arr[1] = usb_msg_get();
                periodUnion.arr[2] = usb_msg_get();
                periodUnion.arr[3] = usb_msg_get();
                
                Zumo_setDisplacement(arcLenUnion.arc_len, thetaUnion.theta);
                
                if(periodUnion.period >=0){
                    task_controller_update.is_active = true;
                    task_CTRL.is_active = true;
                    task_CTRL.run_period = periodUnion.period / 1000;
                    task_CTRL.time_last_ran = Timing_Get_Time();
                    Motor_PWM_Enable(true);
                }else{
                    
                    task_set_pwm.is_active = false;
                    task_controller_update.is_active = false;
                    task_CTRL.is_active = false;
                    Motor_PWM_Enable(false);
                }
            }
            break;
        case 'v':
            if( usb_msg_length() >= MEGN540_Message_Len('v') ){
                usb_msg_get();

                union {
                    float linear;
                    uint8_t arr[4];
                }linvelUnion; 
                linvelUnion.arr[0] = usb_msg_get();
                linvelUnion.arr[1] = usb_msg_get();
                linvelUnion.arr[2] = usb_msg_get();
                linvelUnion.arr[3] = usb_msg_get();

                union {
                    float angular;
                    uint8_t arr[4];
                }angvelUnion; 
                angvelUnion.arr[0] = usb_msg_get();
                angvelUnion.arr[1] = usb_msg_get();
                angvelUnion.arr[2] = usb_msg_get();
                angvelUnion.arr[3] = usb_msg_get();

                Zumo_setVelocity(linvelUnion.linear, angvelUnion.angular);
                //ZumoController.SetRef = Zumo_setVelocity;

                //Set Left and Right Motor Duty Cycle
                Motor_PWM_Left(0);
                Motor_PWM_Right(0);
                //PWM Enable
                Motor_PWM_Enable(true);

                task_controller_update.is_active = true;
            }
            break;
        case 'V':
            if( usb_msg_length() >= MEGN540_Message_Len('V') ){
                usb_msg_get();

                union {
                    float linear;
                    uint8_t arr[4];
                }linvelUnion; 
                linvelUnion.arr[0] = usb_msg_get();
                linvelUnion.arr[1] = usb_msg_get();
                linvelUnion.arr[2] = usb_msg_get();
                linvelUnion.arr[3] = usb_msg_get();

                union {
                    float angular;
                    uint8_t arr[4];
                }angvelUnion; 
                angvelUnion.arr[0] = usb_msg_get();
                angvelUnion.arr[1] = usb_msg_get();
                angvelUnion.arr[2] = usb_msg_get();
                angvelUnion.arr[3] = usb_msg_get();
                
                union {
                    float period;
                    uint8_t arr[4];
                }periodUnion; 
                periodUnion.arr[0] = usb_msg_get();
                periodUnion.arr[1] = usb_msg_get();
                periodUnion.arr[2] = usb_msg_get();
                periodUnion.arr[3] = usb_msg_get();
                
                Zumo_setVelocity(linvelUnion.linear, angvelUnion.angular);

                if(periodUnion.period >=0){
                    task_controller_update.is_active = true;
                    task_CTRL.is_active = true;
                    task_CTRL.run_period = periodUnion.period;
                    task_CTRL.time_last_ran = Timing_Get_Time();
                    Motor_PWM_Enable(true);
                }else{
                    
                    task_set_pwm.is_active = false;
                    task_controller_update.is_active = false;
                    task_CTRL.is_active = false;
                    Motor_PWM_Enable(false);
                }
            }
            break;
        case '~':
            
            if( usb_msg_length() >= MEGN540_Message_Len('~') )
            {
                usb_flush_input_buffer();
                float ret_false = 0;
                usb_send_msg("c", '0' , &ret_false, 0);
                //then process your reset by setting the mf_restart flag
                //mf_restart.active=true;
                task_restart.is_active = true;
            }
            break;
        default:
            // What to do if you dont recognize the command character
            usb_flush_input_buffer();
            float ret_false = 0;
            usb_send_msg("c", '?' , &ret_false, 0);
            break;
    }
}



/**
 * Function MEGN540_Message_Len returns the number of bytes associated with a command string per the
 * class documentation;
 * @param cmd
 * @return Size of expected string. Returns 0 if unreconized.
 */
uint8_t MEGN540_Message_Len( char cmd )
{
    switch(cmd)
    {
        case '~': return	1; break;
        case '*': return	9; break;
        case '/': return	9; break;
        case '+': return	9; break;
        case '-': return	9; break;
        case 't': return	2; break;
        case 'T': return	6; break;
        case 'e': return	1; break;
        case 'E': return	5; break;
        case 'b': return	1; break;
        case 'B': return	5; break;
//        case 'a': return	1; break;
//        case 'A': return 	5; break;
//        case 'w': return	1; break;
//        case 'W': return 	5; break;
//        case 'm': return	1; break;
//        case 'M': return	5; break;
        case 'p': return	5; break;
        case 'P': return	9; break;
        case 's': return 	1; break;
        case 'S': return 	1; break;
        case 'q': return	1; break;
        case 'Q': return 	5; break;
        case 'd': return 	9; break;
        case 'D': return	13; break;
        case 'v': return	9; break;
        case 'V': return	13; break;
        default:  return	0; break;
    }
}
