/*
 * BalanceBot.h
 *
 * Created: 4/15/2022 2:35:47 PM
 *  Author: Matthew
 */ 


#ifndef BALANCEBOT_H_
#define BALANCEBOT_H_

// #include <avr/io.h>
// #include <avr/eeprom.h>
// #include <util/delay.h>
// #include <avr/fuse.h>

// #include "LED_TOGGLE.h"
// #include "I2C_MPU6050.h"
// #include "MotorPWM.h"
#include "Matrix.h"
#include "state_space_control.h"
// #include "Encoder.h"
// #include "Timing.h"
// #include "Task_Management.h"

// #include "print.h"
// #include "usb_debug_only.h"

#define _NUM_MEAS_ 3
#define _NUM_STATE_ 4
#define _NUM_CTRL_ 1

SS_Control_t leftMotor;
SS_Control_t rightMotor;


// static struct Segway {
// 	float** K;
// 	float** L;
// 	float** C;
// 	float** D;
// 	float** Ado;
// 	float** Bdo;
// 	float** x_last_L;
// 	float** u_last_L;
// 	float** y_measured_L;
// 	float** x_last_R;
// 	float** u_last_R;
// 	float** y_measured_R;
// 	float** x_desired;
// 	float** x_now_L;
// 	float** u_now_L;
// 	float** x_now_R;
// 	float** u_now_R;
// 	float** A_xlast;
// 	float** B_ulast;
// 	float** L_ymeasured;
// 	float** D_ulast;
// 	float** X_error;
// 	// float** test1;
// 	// float** test2;
// 	// float** result;
// 	} BalanceBot;
	
void BalanceBotInit(){
	SS_Control_Set_Ctrl_K(0.4829825717289340/10, &leftMotor,0,0);
	SS_Control_Set_Ctrl_K(0.5478167751311889/10, &leftMotor,0,1);
	SS_Control_Set_Ctrl_K(775.0369390379474908/10, &leftMotor,0,2);
	SS_Control_Set_Ctrl_K(66.6971546033702936/10, &leftMotor,0,3);

	SS_Control_Set_Ctrl_K(0.4829825717289340/10, &rightMotor,0,0);
	SS_Control_Set_Ctrl_K(0.5478167751311889/10, &rightMotor,0,1);
	SS_Control_Set_Ctrl_K(775.0369390379474908/10, &rightMotor,0,2);
	SS_Control_Set_Ctrl_K(66.6971546033702936/10, &rightMotor,0,3);

	SS_Control_Set_Obs_L(0.3303035483185744, &leftMotor, 0,0);
	SS_Control_Set_Obs_L(0.0359393909083128, &leftMotor, 0,1);
	SS_Control_Set_Obs_L(-0.4171722835131074, &leftMotor, 0,2);
	SS_Control_Set_Obs_L(3.0205335560021425, &leftMotor, 1,0);
	SS_Control_Set_Obs_L(2.1793675448632115, &leftMotor, 1,1);
	SS_Control_Set_Obs_L(-8.7589993296995186, &leftMotor, 1,2);
	SS_Control_Set_Obs_L(0.4918667597505468, &leftMotor, 2,0);
	SS_Control_Set_Obs_L(-0.0712703301867525, &leftMotor, 2,1);
	SS_Control_Set_Obs_L(-0.0336711465510918, &leftMotor, 2,2);
	SS_Control_Set_Obs_L(1.1634402262390349, &leftMotor, 3,0);
	SS_Control_Set_Obs_L(0.3308619320104624, &leftMotor, 3,1);
	SS_Control_Set_Obs_L(0.1167504385692816, &leftMotor, 3,2);

	SS_Control_Set_Obs_L(0.3303035483185744, &rightMotor, 0,0);
	SS_Control_Set_Obs_L(0.0359393909083128, &rightMotor, 0,1);
	SS_Control_Set_Obs_L(-0.4171722835131074, &rightMotor, 0,2);
	SS_Control_Set_Obs_L(3.0205335560021425, &rightMotor, 1,0);
	SS_Control_Set_Obs_L(2.1793675448632115, &rightMotor, 1,1);
	SS_Control_Set_Obs_L(-8.7589993296995186, &rightMotor, 1,2);
	SS_Control_Set_Obs_L(0.4918667597505468, &rightMotor, 2,0);
	SS_Control_Set_Obs_L(-0.0712703301867525, &rightMotor, 2,1);
	SS_Control_Set_Obs_L(-0.0336711465510918, &rightMotor, 2,2);
	SS_Control_Set_Obs_L(1.1634402262390349, &rightMotor, 3,0);
	SS_Control_Set_Obs_L(0.3308619320104624, &rightMotor, 3,1);
	SS_Control_Set_Obs_L(0.1167504385692816, &rightMotor, 3,2);

	SS_Control_Set_C(0.0, &leftMotor, 0,0);
	SS_Control_Set_C(0.0, &leftMotor, 0,1);
	SS_Control_Set_C(1.0, &leftMotor, 0,2);
	SS_Control_Set_C(0.0, &leftMotor, 0,3);
	SS_Control_Set_C(0.0, &leftMotor, 1,0);
	SS_Control_Set_C(0.0, &leftMotor, 1,1);
	SS_Control_Set_C(0.0, &leftMotor, 1,2);
	SS_Control_Set_C(1.0, &leftMotor, 1,3);
	SS_Control_Set_C(-1.0, &leftMotor, 2,0);
	SS_Control_Set_C(0.0, &leftMotor, 2,1);
	SS_Control_Set_C(1.0, &leftMotor, 2,2);
	SS_Control_Set_C(0.0, &leftMotor, 2,3);

	SS_Control_Set_C(0.0, &rightMotor, 0,0);
	SS_Control_Set_C(0.0, &rightMotor, 0,1);
	SS_Control_Set_C(1.0, &rightMotor, 0,2);
	SS_Control_Set_C(0.0, &rightMotor, 0,3);
	SS_Control_Set_C(0.0, &rightMotor, 1,0);
	SS_Control_Set_C(0.0, &rightMotor, 1,1);
	SS_Control_Set_C(0.0, &rightMotor, 1,2);
	SS_Control_Set_C(1.0, &rightMotor, 1,3);
	SS_Control_Set_C(-1.0, &rightMotor, 2,0);
	SS_Control_Set_C(0.0, &rightMotor, 2,1);
	SS_Control_Set_C(1.0, &rightMotor, 2,2);
	SS_Control_Set_C(0.0, &rightMotor, 2,3);
	
	SS_Control_Set_D(0.0, &leftMotor, 0,0);
	SS_Control_Set_D(0.0, &leftMotor, 1,0);
	SS_Control_Set_D(0.0, &leftMotor, 2,0);

	SS_Control_Set_D(0.0, &rightMotor, 0,0);
	SS_Control_Set_D(0.0, &rightMotor, 1,0);
	SS_Control_Set_D(0.0, &rightMotor, 2,0);

	SS_Control_Set_Ado(0.5828277164868927, &leftMotor, 0,0);
	SS_Control_Set_Ado(0.0083132042326905, &leftMotor, 0,1);
	SS_Control_Set_Ado(0.0150718364149994, &leftMotor, 0,2);
	SS_Control_Set_Ado(-0.0351571820739224, &leftMotor, 0,3);
	SS_Control_Set_Ado(-8.7589993296995186, &leftMotor, 1,0);
	SS_Control_Set_Ado(0.7862821535151054, &leftMotor, 1,1);
	SS_Control_Set_Ado(0.1955620349975933, &leftMotor, 1,2);
	SS_Control_Set_Ado(-2.1354603627318975, &leftMotor, 1,3);
	SS_Control_Set_Ado(-0.0336711465510918, &leftMotor, 2,0);
	SS_Control_Set_Ado(-0.0003695370710301, &leftMotor, 2,1);
	SS_Control_Set_Ado(0.6785379597474346, &leftMotor, 2,2);
	SS_Control_Set_Ado(0.0804014711179791, &leftMotor, 2,3);
	SS_Control_Set_Ado(0.1167504385692816, &leftMotor, 3,0);
	SS_Control_Set_Ado(0.0026714983773796, &leftMotor, 3,1);
	SS_Control_Set_Ado(-0.0885628567023613, &leftMotor, 3,2);
	SS_Control_Set_Ado(0.6589017073801750, &leftMotor, 3,3);

	SS_Control_Set_Ado(0.5828277164868927, &rightMotor, 0,0);
	SS_Control_Set_Ado(0.0083132042326905, &rightMotor, 0,1);
	SS_Control_Set_Ado(0.0150718364149994, &rightMotor, 0,2);
	SS_Control_Set_Ado(-0.0351571820739224, &rightMotor, 0,3);
	SS_Control_Set_Ado(-8.7589993296995186, &rightMotor, 1,0);
	SS_Control_Set_Ado(0.7862821535151054, &rightMotor, 1,1);
	SS_Control_Set_Ado(0.1955620349975933, &rightMotor, 1,2);
	SS_Control_Set_Ado(-2.1354603627318975, &rightMotor, 1,3);
	SS_Control_Set_Ado(-0.0336711465510918, &rightMotor, 2,0);
	SS_Control_Set_Ado(-0.0003695370710301, &rightMotor, 2,1);
	SS_Control_Set_Ado(0.6785379597474346, &rightMotor, 2,2);
	SS_Control_Set_Ado(0.0804014711179791, &rightMotor, 2,3);
	SS_Control_Set_Ado(0.1167504385692816, &rightMotor, 3,0);
	SS_Control_Set_Ado(0.0026714983773796, &rightMotor, 3,1);
	SS_Control_Set_Ado(-0.0885628567023613, &rightMotor, 3,2);
	SS_Control_Set_Ado(0.6589017073801750, &rightMotor, 3,3);

	SS_Control_Set_Bdo(-0.0014986435566093, &leftMotor, 0,0);
	SS_Control_Set_Bdo(-0.2874750577493079, &leftMotor, 1,0);
	SS_Control_Set_Bdo(0.0004732197180038, &leftMotor, 2,0);
	SS_Control_Set_Bdo(0.0032131347724872, &leftMotor, 3,0);

	SS_Control_Set_Bdo(-0.0014986435566093, &rightMotor, 0,0);
	SS_Control_Set_Bdo(-0.2874750577493079, &rightMotor, 1,0);
	SS_Control_Set_Bdo(0.0004732197180038, &rightMotor, 2,0);
	SS_Control_Set_Bdo(0.0032131347724872, &rightMotor, 3,0);
}


#endif /* BALANCEBOT_H_ */