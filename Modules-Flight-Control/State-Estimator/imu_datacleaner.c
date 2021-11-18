#include <stdint.h>
#include "imu_datacleaner.h"

/**

Will convert Accelerometer units to Mps^2 if not already
Will convert Gyroscope units to DPS if not already

Pre-Conditions: 
	+ Accelerometer Readings in g-units or mps^2
	+ Gyroscpe Readings in dps or rps

Parameters:
	+ accelUnitType - Unit type of the data accelerometer data being passed to the function
	+ gyroUnitType - Unit type of the data gyroscope data being passed to the function
	+ data - 

Conversion Info:
	+ 1 (m/s)^2 = 0.10197162129779 g-unit (G-force).
	+ 1 dps is equal to 0.017448352875489 rps = radians per sec??????????????????????? SHOHULD BE REVOLUTIONS/ROTATIONS PER SEC (AKA: HZ)
**/
IMU_Reading Get_Reading(char* accelUnitType, char* gyroUnitType, float *data) {
	
	IMU_Reading imu_data;
	
	if (accelUnitType == "G-UNIT") { //G-Force Units As Input
		
		//DO CONVERSION TO MPS^2
		imu_data.Ax = data[0];
		imu_data.Ay = data[1];
		imu_data.Az = data[2];
	}
		
	else if (accelUnitType == "MPS2") { //mps^2 As Input
		
		imu_data.Ax = data[0];
		imu_data.Ay = data[1];
		imu_data.Az = data[2];
	}
	
	if (gyroUnitType == "DPS") { //Degrees per Sec As Input
		
		imu_data.Gx = data[3];
		imu_data.Gy = data[4];
		imu_data.Gz = data[5];
	}
	
	 else if (gyroUnitType == "RPS") { //Rotations per Sec As Input
		
		//DO CONVERSION TO DPS
		imu_data.Gx = data[3];
		imu_data.Gy = data[4];
		imu_data.Gz = data[5];
	}
	
	
}




