#include <stdint.h>
#include <math.h>
#include "sensordata_convert.h"
//Sensor Dependent

IMU_Data* Get_Reading(char* accelUnitType, char* gyroUnitType, double *data) {
	
	IMU_Data *imu_data;
	
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

RotationAngles* Get_AngularRotations(IMU_Data *reading, float sample_period) {

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


