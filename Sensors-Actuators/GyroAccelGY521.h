#ifndef GYRO_ACCEL_H
#define GYRO_ACCEL_H

//DECLARATIONS
/**
 * @brief Reads GY-521 sensor Gyroscope and Accelerometer data to the STM32
 * 
 * @param i2cNumber I2C ID
 * @param transmitFunc I2C Transmit Function
 * @param receiveFunc I2C Receive Function
 * @param stopFunc I2C Stop Function
 * @return ** float* Sensor data
 */
float* IMUSensor_ReadToSTM32(uint8_t i2cNumber, void (*transmitFunc)(uint8_t, uint8_t), 
	uint8_t (*receiveFunc)(uint8_t), void (*stopFunc)(uint8_t));

/**
 * @brief Reads GY-521 sensor Gyroscope and Accelerometer data to the MSP430 or the Arduino Uno
 * 
 * @param i2cNumber I2C ID
 * @param transmitFunc I2C Transmit Function
 * @param receiveFunc I2C Receive Function
 * @param stopFunc I2C Stop Function
 * @return ** float* Sensor data
 */
float* IMUSensor_ReadToMSP32andUNO(uint8_t i2cNumber, void (*transmitFunc)(uint8_t), 
	uint8_t (*receiveFunc)(), void (*stopFunc)());


#endif