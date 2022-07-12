#ifndef STATE_SPACE_CONTROL_H
#define STATE_SPACE_CONTROL_H

#include "inttypes.h"

#define _NUM_MEAS_  3
#define _NUM_STATE_ 4
#define _NUM_CTRL_  1

typedef struct {
    float Ado[_NUM_STATE_ * _NUM_STATE_];
    float Bdo[_NUM_STATE_ * _NUM_CTRL_];
    float C[_NUM_MEAS_ * _NUM_STATE_];
    float D[_NUM_MEAS_ * _NUM_CTRL_];

    float observer_gain_L[_NUM_STATE_ * _NUM_MEAS_];
    float control_gain_K[_NUM_CTRL_ * _NUM_STATE_];

    float state_vector[_NUM_STATE_];
    float control_vector[_NUM_CTRL_];

    float state_target[_NUM_STATE_];
} SS_Control_t;

void SS_Control_Init( SS_Control_t* controller );

void SS_Control_Update( SS_Control_t* controller, float* new_measurement );

void SS_Control_Set_Ado( float val, SS_Control_t* controller, uint8_t row, uint8_t col );
float SS_Control_Get_Ado( SS_Control_t* controller, uint8_t row, uint8_t col );

void SS_Control_Set_Bdo( float val, SS_Control_t* controller, uint8_t row, uint8_t col );
float SS_Control_Get_Bdo( SS_Control_t* controller, uint8_t row, uint8_t col );

void SS_Control_Set_C( float val, SS_Control_t* controller, uint8_t row, uint8_t col );
float SS_Control_Get_C( SS_Control_t* controller, uint8_t row, uint8_t col );

void SS_Control_Set_D( float val, SS_Control_t* controller, uint8_t row, uint8_t col );
float SS_Control_Get_D( SS_Control_t* controller, uint8_t row, uint8_t col );

void SS_Control_Set_Obs_L( float val, SS_Control_t* controller, uint8_t row, uint8_t col );
float SS_Control_Get_Obs_L( SS_Control_t* controller, uint8_t row, uint8_t col );

void SS_Control_Set_Ctrl_K( float val, SS_Control_t* controller, uint8_t row, uint8_t col );
float SS_Control_Get_Ctrl_K( SS_Control_t* controller, uint8_t row, uint8_t col );

void SS_Control_Set_State( float val, SS_Control_t* controller, uint8_t row );
float SS_Control_Get_State( SS_Control_t* controller, uint8_t row );

void SS_Control_Set_Control( float val, SS_Control_t* controller, uint8_t row, uint8_t col );
float SS_Control_Get_Control( SS_Control_t* controller, uint8_t row, uint8_t col );

void SS_Control_Set_Target( float val, SS_Control_t* controller, uint8_t row );
float SS_Control_Get_Target( SS_Control_t* controller, uint8_t row );

#endif