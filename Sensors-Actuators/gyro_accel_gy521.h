#ifndef GYRO_ACCEL_H
#define GYRO_ACCEL_H

//DECLARATIONS
/**
 * @brief 
 * 
 * @param i2cNumber 
 * @param transmitFunc 
 * @param receiveFunc 
 * @param stopFunc 
 * @return ** float* 
 */
float* IMUSensor_ReadToSTM32(uint8_t i2cNumber, void (*transmitFunc)(uint8_t, uint8_t), 
	uint8_t (*receiveFunc)(uint8_t), void (*stopFunc)(uint8_t));

/**
 * @brief 
 * 
 * @param i2cNumber 
 * @param transmitFunc 
 * @param receiveFunc 
 * @param stopFunc 
 * @return ** float* 
 */
float* IMUSensor_ReadToMSP32andUNO(uint8_t i2cNumber, void (*transmitFunc)(uint8_t), 
	uint8_t (*receiveFunc)(), void (*stopFunc)());


#endif