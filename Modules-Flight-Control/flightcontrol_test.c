#include "rotations.h"
#include "pid.h"
#include "motormix_algo.h"
#include "imu_datacleaner.h"

IMU_Reading Get_Reading(char* accelUnitType, char* gyroUnitType, float *data);

typedef struct {
	
	float Ax;
	float Ay;
	float Az;
	
	float Gx;
	float Gy;
	float Gz;
	
}IMU_Reading;


void PID_Update(PIDController *PID, double set_point, double current_measurement);
void Set_Tuning_Parameters(PIDController *PID, double kp, double ki, double kd);
void Set_Sample_Time(PIDController *PID, int new_sample_time);
void Set_Output_Limits(PIDController *PID, double min, double max);
void Set_PIDMode(PIDController *PID, int mode);
void Set_ControllerDirection(PIDController *PID, int direction);


void RotationMaster(double xRotation, double yRotation, double zRotation);


_4Motors* Motor_Mix(double thrust, double yaw, double pitch, double roll);


struct motors {
	double front_Right;
	double front_Left;
	double back_Right;
	double back_Left;
};