#include "ZoomieZumo.h"


void Zumo_Init( float* num_left, float* denom_left, float kp_left, float* num_right, float* denom_right, float kp_right, uint8_t order, float updatePeriod, float width ){
    Controller_Init( &ZumoController.Controller_Left, kp_left, num_left, denom_left, order, updatePeriod);
    Controller_Init( &ZumoController.Controller_Right, kp_right, num_right, denom_right, order, updatePeriod); //Change Method of Passing Pointers
    ZumoController.width = width;
}


void Zumo_setDisplacement( float arc_len, float theta ){
//void Zumo_setDisplacement( ){
    // float posLeft;
    // float posRight;
    // Theta Tuning
    // if(arc_len == 0){
    //     switch (theta)
    //     {
    //     case 1.57:
    //         /* code */
    //         break;
        // theta
    //     default:
    //         break;
    //     }
    // }
    //theta =  theta * (9.0 / 7.0); //360 - (10.0 / 7.0)

    // //Alternatively we could slew rate pos left and right
    // //Slew Limit arc len
    // ZumoController.lin_LAST = SlewRateLimiter(ZumoController.lin_REF, ZumoController.lin_LAST, 1000);
    // //Slew Limit theta
    // ZumoController.ang_LAST = SlewRateLimiter(ZumoController.ang_REF, ZumoController.ang_LAST, 1000);

    float posLeft = ((arc_len  - (ZumoController.width / 2)*theta) * (2.0 / 0.039)) + Rad_Left(); //D = 0.039m
    float posRight = ((arc_len  + (ZumoController.width / 2)*theta) * (2.0 / 0.039)) + Rad_Right(); 

    // float posLeft = ((ZumoController.lin_LAST  - (ZumoController.width / 2)*ZumoController.ang_LAST) * (2.0 / 0.039)) + Rad_Left(); //D = 0.039m
    // float posRight = ((ZumoController.lin_LAST  + (ZumoController.width / 2)*ZumoController.ang_LAST) * (2.0 / 0.039)) + Rad_Right();


    Controller_SetTo(&ZumoController.Controller_Left, Rad_Left());
    Controller_SetTo(&ZumoController.Controller_Right, Rad_Right());

    Controller_Set_Target_Position(&ZumoController.Controller_Left, posLeft);
    Controller_Set_Target_Position(&ZumoController.Controller_Right, posRight);

}


void Zumo_setVelocity( float lin_vel, float ang_vel ){

    // //Slew Limit arc len
    // SlewRateLimiter(ZumoController.lin_REF, ZumoController.lin_LAST, .3);
    // //Slew Limit theta
    // SlewRateLimiter(ZumoController.ang_REF, ZumoController.ang_LAST, 3.14);

    ////////////////////From Our Equations/////////////////////////////

    float velLeft = (lin_vel - (ang_vel * (ZumoController.width/2))) * (2 / 0.039);
    float velRight = (lin_vel + (ang_vel * (ZumoController.width/2))) * (2 / 0.039);

    ///////////////////////////////////////////////////////////////////

    Controller_SetTo(&ZumoController.Controller_Left, Rad_Left());
    Controller_SetTo(&ZumoController.Controller_Right, Rad_Right());

    Controller_Set_Target_Velocity(&ZumoController.Controller_Left, velLeft); 
    Controller_Set_Target_Velocity(&ZumoController.Controller_Right, velRight);
}
