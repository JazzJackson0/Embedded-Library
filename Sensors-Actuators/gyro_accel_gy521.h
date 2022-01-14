#ifndef GYRO_ACCEL_H
#define GYRO_ACCEL_H

//DECLARATIONS
/**
 * @brief 
 * 
 * @param deviceName 
 * @param i2cNumber 
 * @return ** float* 
 */
float* IMU_Read(char* deviceName, uint8_t i2cNumber);


#endif