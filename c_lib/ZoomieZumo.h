#ifndef _MEGN540_ZOOMIE_ZUMO_H
#define _MEGN540_ZOOMIE_ZUMO_H
#include "Controller.h"
#include "MotorPWM.h"
#include "Encoder.h"
//
#include "MEGN540_MessageHandeling.h"

//typedef void (*SetReference)( );

struct MotorControllers {

    // Variables
    Controller_t Controller_Left;
    Controller_t Controller_Right;
    
    float width;

    uint8_t SlewRate;
    // For slew Rate Implementation
    // float lin_LAST;
    // float ang_LAST;           
    // float lin_REF;
    // float ang_REF;         

    // SetReference SetRef;

}static ZumoController;



void Zumo_Init( float* num_left, float* denom_left, float kp_left, float* num_right, float* denom_right, float kp_right, uint8_t order, float updatePeriod, float width );

void Zumo_setDisplacement( float arc_len, float theta);
//void Zumo_setDisplacement( );

void Zumo_setVelocity( float lin_vel, float ang_vel );

#endif