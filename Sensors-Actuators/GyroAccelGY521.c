#include <stdint.h>
#include <stddef.h>
#include "GyroAccelGY521.h"

//Macros & Prototypes----------------------------------------------------
#define SLAVE_ADDRS_AND_READ 0xD3
#define SLAVE_ADDRS_AND_WRITE 0xD2
#define ACCEL_X_ADDRESS 0x3B //16-Bit Read-Only Register

float* IMUSensor_ReadToSTM32(uint8_t i2cNumber, void (*transmitFunc)(uint8_t, uint8_t), 
	uint8_t (*receiveFunc)(uint8_t), void (*stopFunc)(uint8_t)) {

	int8_t *rawData = NULL;
	float *imuData = NULL;
	
	(*transmitFunc)(i2cNumber, SLAVE_ADDRS_AND_WRITE); //Are these both uint8_t???
	(*transmitFunc)(i2cNumber, ACCEL_X_ADDRESS);
	(*transmitFunc)(i2cNumber, SLAVE_ADDRS_AND_READ);
	
	for (int i = 0; i < 14; i++) { rawData[i] = (*receiveFunc)(i2cNumber); }
	
	//Data Converted to G-Force Units
	imuData[0] = (float) (((int16_t) rawData[0] << 8 | rawData[1]) / 16384.0);
	imuData[1] = (float) (((int16_t) rawData[2] << 8 | rawData[3]) / 16384.0);
	imuData[2] = (float) (((int16_t) rawData[4] << 8 | rawData[5]) / 16384.0);
	//---Skipping Stored Temp Data---
	//Data Converted to Degrees-Per-Sec Units
	imuData[3] = (float) (((int16_t) rawData[8] << 8 | rawData[9]) / 131.0);
	imuData[4] = (float) (((int16_t) rawData[10] << 8 | rawData[11]) / 131.0);
	imuData[5] = (float) (((int16_t) rawData[12] << 8 | rawData[13]) / 131.0);
	
	(*stopFunc)(i2cNumber);
		
	return imuData;
	
	return NULL;
}


float* IMUSensor_ReadToMSP32orUNO(uint8_t i2cNumber, void (*transmitFunc)(uint8_t), 
	uint8_t (*receiveFunc)(), void (*stopFunc)()) {

	int8_t *rawData = NULL;
	float *imuData = NULL;
	
	(*transmitFunc)(SLAVE_ADDRS_AND_WRITE);
	(*transmitFunc)(ACCEL_X_ADDRESS);
	(*transmitFunc)(SLAVE_ADDRS_AND_READ);
	
	int i = 0;
	for (i; i < 14; i++) { rawData[i] = (*receiveFunc)(); }
	
	//Data Converted to G-Force Units (See GY-521 Register Map pdf)
	imuData[0] = (float) (((int16_t) rawData[0] << 8 | rawData[1]) / 16384.0);
	imuData[1] = (float) (((int16_t) rawData[2] << 8 | rawData[3]) / 16384.0);
	imuData[2] = (float) (((int16_t) rawData[4] << 8 | rawData[5]) / 16384.0);
	//---Skipping Stored Temperature Data---
	//Data Converted to Degrees-Per-Sec Units (See GY-521 Register Map pdf)
	imuData[3] = (float) (((int16_t) rawData[8] << 8 | rawData[9]) / 131.0);
	imuData[4] = (float) (((int16_t) rawData[10] << 8 | rawData[11]) / 131.0);
	imuData[5] = (float) (((int16_t) rawData[12] << 8 | rawData[13]) / 131.0);
	
	(*stopFunc);
		
	return imuData;
}

/*
 * 			TO-DO
 * 			-----
 *  - Test Code
 *
 *  - 
 *  
 *  - 
 *  */
