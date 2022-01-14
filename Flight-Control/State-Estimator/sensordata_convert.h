#ifndef SENSORDATA_CONVERT_H
#define SENSORDATA_CONVERT_H

typedef struct sensor_read Sensor_Reading;
typedef struct r_angles RotationAngles;

//DECLARATIONS
/**
 * @brief Will convert Accelerometer units to Mps^2 if not already.
 *		  Will convert Gyroscope units to DPS if not already.
 *
 *		  Pre-Conditions: 
 *			+ Accelerometer Readings in g-units or mps^2
 *			+ Gyroscpe Readings in dps or rps
 *
 *		  Conversion Info:
 *			+ 1 (m/s)^2 = 0.10197162129779 g-unit (G-force).
 *			+ 1 dps is equal to 0.017448352875489 rps = radians per sec??????????????????????? 
 *				????????????????SHOHULD BE REVOLUTIONS/ROTATIONS PER SEC (AKA: HZ)
 * 
 * @param accelUnitType Unit type of the data accelerometer data being passed to the function
 * @param gyroUnitType Unit type of the data gyroscope data being passed to the function
 * @param data 
 * @return ** Sensor_Reading* 
 */
Sensor_Reading* Get_Reading(char* accelUnitType, char* gyroUnitType, double *data);
/**
 * @brief 
 * 
 * @param reading 
 * @param sample_period 
 * @return ** RotationAngles* 
 */
RotationAngles* Get_AngularRotations(Sensor_Reading *reading, float sample_period);

//Structs
struct sensor_read{
	double Ax_mps2;
	double Ay_mps2;
	double Az_mps2;

	double Gx_dps;
	double Gy_dps;
	double Gz_dps;	
};

/*
Ax - Az: Rotation angles obtained from acceleration
Gx - Gz: Rotation angles obtained from angular velocity
*/
struct r_angles{
	double Angle_Ax;
	double Angle_Ay;
	double Angle_Az;
	
	double Angle_Gx;
	double Angle_Gy;
	double Angle_Gz;
};

#define _180_DIV_PI 57.2958

#endif