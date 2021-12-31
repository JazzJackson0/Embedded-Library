#include <stdint.h>
#include <math.h>
#include "sensordata_convert.h"
//Sensor Dependent
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
Sensor_Reading* Get_Reading(char* accelUnitType, char* gyroUnitType, double *data) {
	
	Sensor_Reading *imu_data;
	
	if (accelUnitType == "G-UNIT") { //G-Force Units As Input
		
		//DO CONVERSION TO MPS^2
		imu_data->Ax_mps2 = data[0];
		imu_data->Ay_mps2 = data[1];
		imu_data->Az_mps2 = data[2];
	}
		
	else if (accelUnitType == "MPS2") { //mps^2 As Input
		
		imu_data->Ax_mps2 = data[0];
		imu_data->Ay_mps2 = data[1];
		imu_data->Az_mps2 = data[2];
	}
	
	if (gyroUnitType == "DPS") { //Degrees per Sec As Input
		
		imu_data->Gx_dps = data[3];
		imu_data->Gy_dps = data[4];
		imu_data->Gz_dps = data[5];
	}
	
	 else if (gyroUnitType == "RPS") { //Rotations per Sec As Input
		
		//DO CONVERSION TO DPS
		imu_data->Gx_dps = data[3];
		imu_data->Gy_dps = data[4];
		imu_data->Gz_dps = data[5];
	}

	return imu_data;
}

RotationAngles* Get_AngularRotations(Sensor_Reading *reading, float sample_period) {

	RotationAngles *rotations;
	rotations->Angle_Ax = _180_DIV_PI * atan( reading->Ax_mps2 / ( sqrt( (reading->Ay_mps2 * reading->Ay_mps2) + (reading->Az_mps2 * reading->Az_mps2) ) ) );
	rotations->Angle_Ay = _180_DIV_PI * atan( reading->Ay_mps2 / ( sqrt( (reading->Ax_mps2 * reading->Ax_mps2) + (reading->Az_mps2 * reading->Az_mps2) ) ) );
	rotations->Angle_Az = _180_DIV_PI * atan( sqrt( (reading->Ax_mps2 * reading->Ax_mps2) + (reading->Ay_mps2 * reading->Ay_mps2) ) / reading->Az_mps2 );

	rotations->Angle_Gx += reading->Gx_dps * sample_period;
	rotations->Angle_Gy += reading->Gy_dps * sample_period;
	rotations->Angle_Gz += reading->Gz_dps * sample_period;

	return rotations;
}

/*
 * 			TO-DO
 * 			-----
 *  - Write the conversion part of the Get_Reading function.
 *
 *  - 
 *  
 *  - 
 *  */


