#include <stdint.h>
#include <stddef.h>
#include "gyro_accel_gy521.h"
#include "i2c_STM32F407.h"
#include "i2c_STM32F446.h"
#include "i2c_MSP430FR.h"
#include "twi_ATmega328.h"

//Macros & Prototypes----------------------------------------------------
#define SLAVE_ADDRS_AND_READ 0xD3
#define SLAVE_ADDRS_AND_WRITE 0xD2
#define ACCEL_X_ADDRESS 0x3B //16-Bit Read-Only Register

float* IMU_Read(char* deviceName, uint8_t i2cNumber) {
	
	int8_t *rawData = NULL;
	float *imuData = NULL;
	
	if (deviceName == "MSP430") {
		
		I2C_Transmit(SLAVE_ADDRS_AND_WRITE);
		I2C_Transmit(ACCEL_X_ADDRESS);
		I2C_Transmit(SLAVE_ADDRS_AND_READ);
		
		int i = 0;
		for (i; i < 14; i++) {
			
			rawData[i] = I2C_Receive();
		}
		
		//Data Converted to G-Force Units (See GY-521 Register Map pdf)
		imuData[0] = (float) (((int16_t) rawData[0] << 8 | rawData[1]) / 16384.0);
		imuData[1] = (float) (((int16_t) rawData[2] << 8 | rawData[3]) / 16384.0);
		imuData[2] = (float) (((int16_t) rawData[4] << 8 | rawData[5]) / 16384.0);
		//---Skipping Stored Temp Data---
		//Data Converted to Degrees-Per-Sec Units (See GY-521 Register Map pdf)
		imuData[3] = (float) (((int16_t) rawData[8] << 8 | rawData[9]) / 131.0);
		imuData[4] = (float) (((int16_t) rawData[10] << 8 | rawData[11]) / 131.0);
		imuData[5] = (float) (((int16_t) rawData[12] << 8 | rawData[13]) / 131.0);
		
		I2C_Stop();
			
		return imuData;
	}
	
	if (deviceName == "STM32") {
		
		I2C_Transmit(i2cNumber, SLAVE_ADDRS_AND_WRITE);
		I2C_Transmit(i2cNumber, ACCEL_X_ADDRESS);
		I2C_Transmit(i2cNumber, SLAVE_ADDRS_AND_READ);
		
		for (int i = 0; i < 14; i++) {
			
			rawData[i] = I2C_Receive(i2cNumber);
		}
		
		//Data Converted to G-Force Units
		imuData[0] = (float) (((int16_t) rawData[0] << 8 | rawData[1]) / 16384.0);
		imuData[1] = (float) (((int16_t) rawData[2] << 8 | rawData[3]) / 16384.0);
		imuData[2] = (float) (((int16_t) rawData[4] << 8 | rawData[5]) / 16384.0);
		//---Skipping Stored Temp Data---
		//Data Converted to Degrees-Per-Sec Units
		imuData[3] = (float) (((int16_t) rawData[8] << 8 | rawData[9]) / 131.0);
		imuData[4] = (float) (((int16_t) rawData[10] << 8 | rawData[11]) / 131.0);
		imuData[5] = (float) (((int16_t) rawData[12] << 8 | rawData[13]) / 131.0);
		
		I2C_Stop(i2cNumber);
			
		return imuData;
	}
	
	if (deviceName == "UNO") {
		
		TWIMaster_Transmit(SLAVE_ADDRS_AND_WRITE);
		TWIMaster_Transmit(ACCEL_X_ADDRESS);
		TWIMaster_Transmit(SLAVE_ADDRS_AND_READ);
		
		int i = 0;
		for (i; i < 14; i++) {
			
			rawData[i] = TWIMaster_Receive();
		}
		
		//Data Converted to G-Force Units
		imuData[0] = (float) (((int16_t) rawData[0] << 8 | rawData[1]) / 16384.0);
		imuData[1] = (float) (((int16_t) rawData[2] << 8 | rawData[3]) / 16384.0);
		imuData[2] = (float) (((int16_t) rawData[4] << 8 | rawData[5]) / 16384.0);
		//---Skipping Stored Temp Data---
		//Data Converted to Degrees-Per-Sec Units
		imuData[3] = (float) (((int16_t) rawData[8] << 8 | rawData[9]) / 131.0);
		imuData[4] = (float) (((int16_t) rawData[10] << 8 | rawData[11]) / 131.0);
		imuData[5] = (float) (((int16_t) rawData[12] << 8 | rawData[13]) / 131.0);
		
		TWI_Stop();
			
		return imuData;
	}
	
	return NULL;
}
