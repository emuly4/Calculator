#include "MPU6050.h"

MPU6050::MPU6050( void )
{
    i2c_init();     // init I2C interface
	_delay_ms(200);  // Wait for 200 ms.
	//
	tau = 0.004; //0.75 0.007
	float ControlUpdatePeriod = 0.0075;	//Timer Print takes 2.5MS .0075
	alpha = ((tau) / (tau + ControlUpdatePeriod));
	PreviousTheta = 0;
	dt = ControlUpdatePeriod;
	//
	unsigned char ret = i2c_start((MPU6050_ADDRESS_AD0_LOW<<1) + I2C_WRITE);       // set device address and write mode
	if ( ret )
	{
		/* failed to issue start condition, possibly no device found */
		i2c_stop();
		LED_ON(PORTF, DEBUG_LED4);    // Turn on the red LED immediately to signal the read is not ok
		while(1) {;;}  // lock program here as sensor init failed
	}else{
		/* issuing start condition ok, device accessible */
		i2c_write(MPU6050_RA_PWR_MGMT_1); // go to register 107
		i2c_write(0x00); // set value to 0000 0000 and wake up sensor
		i2c_stop();      // set stop condition = release bus
		
		I2C_WriteConfigure(MPU6050_RA_SMPLRT_DIV, 0x08); // set value to 0000 1000 for 1000 Hz
		I2C_WriteConfigure(MPU6050_RA_ACCEL_CONFIG, 0x08); // set value to 0000 1000 for 4g, normal line tension is 2,7g
		I2C_WriteConfigure(MPU6050_RA_GYRO_CONFIG, 0x10); // set value to 0001 0000 for 1000 (deg/s) (Motor Max RPM is 100)
		I2C_WriteConfigure(MPU6050_RA_FIFO_EN, 0xF8); // set value to 1111 1000 for all sensors not slave
		I2C_WriteConfigure(MPU6050_RA_USER_CTRL,0x40); // set value to 0100 0000 FIFO enable
		
	}
}

void MPU6050::I2C_WriteConfigure(uint8_t reg, uint8_t val){
    i2c_start( (MPU6050_ADDRESS_AD0_LOW<<1) + I2C_WRITE);
    i2c_write(reg); 
    i2c_write(val); 
    i2c_stop();      // set stop condition = release bus
}

void MPU6050::I2C_ReadSensorVals(){
    //Read X accel
    i2c_start_wait((MPU6050_ADDRESS_AD0_LOW<<1) + I2C_WRITE);    // set device address and write mode
    i2c_write(MPU6050_RA_ACCEL_XOUT_H);                      // ACCEL_XOUT
    i2c_rep_start((MPU6050_ADDRESS_AD0_LOW<<1) + I2C_READ);      // set device address and read mode
    rawXaccel = i2c_readAck();               // read one intermediate byte
    rawXaccel = (rawXaccel<<8) | i2c_readNak(); // read last byte
    i2c_stop();

    //Read Z accel
    i2c_start_wait((MPU6050_ADDRESS_AD0_LOW<<1) + I2C_WRITE);    // set device address and write mode
    i2c_write(MPU6050_RA_ACCEL_ZOUT_H);                      // ACCEL_ZOUT
    i2c_rep_start((MPU6050_ADDRESS_AD0_LOW<<1) + I2C_READ);      // set device address and read mode
    rawZaccel = i2c_readAck();               // read one intermediate byte
    rawZaccel = (rawZaccel<<8) | i2c_readNak(); // read last byte
    i2c_stop();


    //Read Y gyro

    i2c_start_wait((MPU6050_ADDRESS_AD0_LOW<<1) + I2C_WRITE);    // set device address and write mode
    i2c_write(MPU6050_RA_GYRO_YOUT_H);                      // GYRO_YOUT
    i2c_rep_start((MPU6050_ADDRESS_AD0_LOW<<1) + I2C_READ);      // set device address and read mode
    rawYGyro = i2c_readAck();               // read one intermediate byte
    rawYGyro = (rawYGyro<<8) | i2c_readNak(); // read last byte
    i2c_stop();
}

void MPU6050::ConvertSensorVals(){
    static const float DEG_TO_RAD = M_PI / 180.0;
	
	Xaccel = (((int16_t) rawXaccel) / 32767.0) * 4.0;
    //Calibrate Xaccel
    Xaccel -= 0.0276726;
	Zaccel = (((int16_t) rawZaccel) / 32767.0) * 4.0;
	//Calibrate Zaccel
    Zaccel -= -0.0714547;
	YGyro = (((int16_t) rawYGyro) / 32767.0) * 1000.0;
    //Calibrate YGyrro
    // YGyro -= -2.8737402;
	YGyro -= -2.74;
	YGyro *= DEG_TO_RAD;
	// GyroTheta = YGyro * (1.0 / RAD_TO_DEG) * dt;
	
	theta = -atan2((double) Xaccel, (double) Zaccel);
	
	// CurrentTheta = (alpha * (PreviousTheta + GyroTheta )) + ((1 - alpha)*(theta));
	/*MPU6050.CurrentTheta= MPU6050.theta;*/
}