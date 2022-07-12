#ifndef MPU6050_H_
#define MPU6050_H_

#define F_CPU 16000000UL

#include <util/delay.h>
#include "i2cmaster.h"
#include "MPU6050_REGISTERS.h"
#include "LED_TOGGLE.h"
#include <math.h>

class MPU6050
{
private:
    /* data */
public:
    uint16_t rawXaccel, rawZaccel, rawYGyro;
	float Xaccel, Zaccel, YGyro, theta, PreviousTheta, GyroTheta, dt, alpha, tau, CurrentTheta;

    //Writes val to Reg
    void I2C_WriteConfigure(uint8_t reg, uint8_t val);

    void I2C_ReadSensorVals();

    //Convert Sensor Values//Convert Sensor Values
    void ConvertSensorVals();

    MPU6050();
};




#endif