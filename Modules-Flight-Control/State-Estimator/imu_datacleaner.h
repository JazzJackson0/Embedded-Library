#ifndef IMU_DATACLEANER_H
#define IMU_DATACLEANER_H

IMU_Reading Get_Reading(char* accelUnitType, char* gyroUnitType, float *data);

typedef struct {
	
	float Ax;
	float Ay;
	float Az;
	
	float Gx;
	float Gy;
	float Gz;
	
}IMU_Reading;



#endif