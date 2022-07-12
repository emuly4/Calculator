#include "state_space_control.h"

#include "inttypes.h"

void Set_Mat_Zero( float* mat, uint8_t num_row, uint8_t num_col );
void Set_Vec_Zero( float* vec, uint8_t num_row );

void Matrix_Vector_Multiply_Add_To( float* result, float* in_mat, float* in_vec, uint8_t mat_row, uint8_t mat_col );
void Vector_Copy( float* to_vec, float* from_vec, uint8_t vec_row );
void Vector_Add( float* out_vec, float* in_vec_lhs, float* in_vec_rhs, uint8_t vec_row );
void Vector_Sub( float* out_vec, float* in_vec_lhs, float* in_vec_rhs, uint8_t vec_row );

void SS_Control_Init( SS_Control_t* controller )
{
    Set_Mat_Zero( controller->Ado, _NUM_STATE_, _NUM_STATE_ );
    Set_Mat_Zero( controller->Bdo, _NUM_STATE_, _NUM_CTRL_ );
    Set_Mat_Zero( controller->C, _NUM_MEAS_, _NUM_STATE_ );
    Set_Mat_Zero( controller->D, _NUM_MEAS_, _NUM_CTRL_ );
    Set_Mat_Zero( controller->control_gain_K, _NUM_CTRL_, _NUM_STATE_ );
    Set_Mat_Zero( controller->observer_gain_L, _NUM_STATE_, _NUM_MEAS_ );

    Set_Vec_Zero( controller->state_vector, _NUM_STATE_ );
    Set_Vec_Zero( controller->control_vector, _NUM_CTRL_ );
    Set_Vec_Zero( controller->state_target, _NUM_STATE_ );
}

void SS_Control_Update( SS_Control_t* controller, float* new_measurement )
{
    // state update
    float x_est[_NUM_STATE_];
    Set_Vec_Zero( x_est, _NUM_STATE_ );
    Matrix_Vector_Multiply_Add_To( x_est, controller->Ado, controller->state_vector, _NUM_STATE_, _NUM_STATE_ );
    Matrix_Vector_Multiply_Add_To( x_est, controller->Bdo, controller->control_vector, _NUM_STATE_, _NUM_CTRL_ );
    Matrix_Vector_Multiply_Add_To( x_est, controller->observer_gain_L, new_measurement, _NUM_STATE_, _NUM_MEAS_ );
    Vector_Copy( controller->state_vector, x_est, _NUM_STATE_ );

    // calculate error
    float st_err[_NUM_STATE_];
    Vector_Sub( st_err, controller->state_target, controller->state_vector, _NUM_STATE_ );

    // calculate control
    Set_Vec_Zero( controller->control_vector, _NUM_CTRL_ );
    Matrix_Vector_Multiply_Add_To( controller->control_vector, controller->control_gain_K, st_err, _NUM_CTRL_, _NUM_STATE_ );
}

void SS_Control_Set_Ado( float val, SS_Control_t* controller, uint8_t row, uint8_t col )
{
    controller->Ado[row * _NUM_STATE_ + col] = val;
}
float SS_Control_Get_Ado( SS_Control_t* controller, uint8_t row, uint8_t col )
{
    return controller->Ado[row * _NUM_STATE_ + col];
}

void SS_Control_Set_Bdo( float val, SS_Control_t* controller, uint8_t row, uint8_t col )
{
    controller->Bdo[row * _NUM_CTRL_ + col] = val;
}
float SS_Control_Get_Bdo( SS_Control_t* controller, uint8_t row, uint8_t col )
{
    return controller->Bdo[row * _NUM_CTRL_ + col];
}

void SS_Control_Set_C( float val, SS_Control_t* controller, uint8_t row, uint8_t col )
{
    controller->C[row * _NUM_STATE_ + col] = val;
}
float SS_Control_Get_C( SS_Control_t* controller, uint8_t row, uint8_t col )
{
    return controller->C[row * _NUM_STATE_ + col];
}

void SS_Control_Set_D( float val, SS_Control_t* controller, uint8_t row, uint8_t col )
{
    controller->D[row * _NUM_CTRL_ + col] = val;
}
float SS_Control_Get_D( SS_Control_t* controller, uint8_t row, uint8_t col )
{
    return controller->D[row * _NUM_CTRL_ + col];
}

void SS_Control_Set_Obs_L( float val, SS_Control_t* controller, uint8_t row, uint8_t col )
{
    controller->observer_gain_L[row * _NUM_MEAS_ + col] = val;
}
float SS_Control_Get_Obs_L( SS_Control_t* controller, uint8_t row, uint8_t col )
{
    return controller->observer_gain_L[row * _NUM_MEAS_ + col];
}

void SS_Control_Set_Ctrl_K( float val, SS_Control_t* controller, uint8_t row, uint8_t col )
{
    controller->control_gain_K[row * _NUM_STATE_ + col] = val;
}
float SS_Control_Get_Ctrl_K( SS_Control_t* controller, uint8_t row, uint8_t col )
{
    return controller->control_gain_K[row * _NUM_STATE_ + col];
}

void SS_Control_Set_State( float val, SS_Control_t* controller, uint8_t row )
{
    controller->state_vector[row] = val;
}
float SS_Control_Get_State( SS_Control_t* controller, uint8_t row )
{
    return controller->state_vector[row];
}

void SS_Control_Set_Control( float val, SS_Control_t* controller, uint8_t row, uint8_t col )
{
    controller->control_vector[row] = val;
}
float SS_Control_Get_Control( SS_Control_t* controller, uint8_t row, uint8_t col )
{
    return controller->control_vector[row];
}

void SS_Control_Set_Target( float val, SS_Control_t* controller, uint8_t row )
{
    controller->state_target[row] = val;
}
float SS_Control_Get_Target( SS_Control_t* controller, uint8_t row )
{
    return controller->state_target[row];
}

void Set_Mat_Zero( float* mat, uint8_t num_row, uint8_t num_col )
{
    for( uint8_t r = 0; r < num_row; r++ )
        for( uint8_t c = 0; c < num_col; c++ )
            mat[r * num_col + c] = 0.0f;
}

void Set_Vec_Zero( float* vec, uint8_t num_row )
{
    for( uint8_t r = 0; r < num_row; r++ )
        vec[r] = 0.0f;
}

void Matrix_Vector_Multiply_Add_To( float* out_vec, float* in_mat, float* in_vec, uint8_t mat_row, uint8_t mat_col )
{
    for( uint8_t r = 0; r < mat_row; r++ ) {
        for( uint8_t c = 0; c < mat_col; c++ ) {
            out_vec[r] += in_mat[r * mat_col + c] * in_vec[c];
        }
    }
}

void Vector_Copy( float* to_vec, float* from_vec, uint8_t vec_row )
{
    for( uint8_t r = 0; r < vec_row; r++ )
        to_vec[r] = from_vec[r];
}

void Vector_Add( float* out_vec, float* in_vec_lhs, float* in_vec_rhs, uint8_t vec_row )
{
    for( uint8_t r = 0; r < vec_row; r++ )
        out_vec[r] = in_vec_lhs[r] + in_vec_rhs[r];
}
void Vector_Sub( float* out_vec, float* in_vec_lhs, float* in_vec_rhs, uint8_t vec_row )
{
    for( uint8_t r = 0; r < vec_row; r++ )
        out_vec[r] = in_vec_lhs[r] - in_vec_rhs[r];
}
