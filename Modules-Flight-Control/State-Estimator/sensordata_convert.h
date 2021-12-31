#ifndef SENSORDATA_CONVERT_H
#define SENSORDATA_CONVERT_H

typedef struct sensor_read Sensor_Reading;
typedef struct r_angles RotationAngles;

//Functions
Sensor_Reading* Get_Reading(char* accelUnitType, char* gyroUnitType, double *data);
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