#ifndef PID_H
#define PID_H

#include <stdbool. h>

void PID_Update(PIDController *PID, double set_point, double current_measurement);
void Set_Tuning_Parameters(PIDController *PID, double kp, double ki, double kd);
void Set_Sample_Time(PIDController *PID, int new_sample_time);
void Set_Output_Limits(PIDController *PID, double min, double max);
void Set_PIDMode(PIDController *PID, int mode);
void Set_ControllerDirection(PIDController *PID, int direction);

/*Controller Mode*/
#define MANUAL 0
#define AUTOMATIC 1

/*Controller Direction*/
#define DIRECT 0			
#define REVERSE 1

typedef struct {
	
	int proportional_gain;
	int integral_gain;
	int derivative_gain;

	double max_output;
	double min_output;
	
	double Integrator;
	double previous_error;
	
	double Differentiator;
	double previous_measurement;
	double current_measurement;
	
	int sample_time;
	double previous_time;
	
	int controller_direction;
	bool inAutoMode;
	
	double output_data;
	
}PIDController;

#endif