#include <stdbool.h>
#include "PID.h"

//Static Prototypes-------------------------------------
static void Initialize(PIDController *PID);
#define AUTOMATIC 1			
#define REVERSE 1

PIDController* PID_Init(void) {
	
	PIDController PIDTarget = PID_INIT;
	PIDController *PID = &PIDTarget;
	return PID;
}

int PID_Update(PIDController *PID, double set_point, double current_measurement, 
	double (*RTCTimeKeepingFunction)() ) {
	
	if (!PID->inAutoMode) return 0;
	
	/*Calculate dt: Time since last calculation*/
	double current_time = (*RTCTimeKeepingFunction)(); //Use an RTC Function here
	double change_in_time = (double) (current_time - PID->previous_time); // dt
	
	if (change_in_time >= PID->sample_time) {
		
		PID->current_measurement = current_measurement;
		/*Current Error*/
		double current_error = set_point - current_measurement; // e(t)
		/*Proportional Term*/
		double proportional_term = PID->proportional_gain * current_error;
		/*Integral Term*/
		PID->Integrator += PID->integral_gain * current_error;
		if (PID->Integrator > PID->max_output) PID->Integrator = PID->max_output;
		else if (PID->Integrator < PID->min_output) PID->Integrator = PID->min_output;
		/*Derivative Term*/
		PID->Differentiator = current_measurement - PID->previous_measurement;
		/*PID formula*/
		PID->output_data = proportional_term + PID->Integrator + (PID->derivative_gain * PID->Differentiator);
		if (PID->output_data > PID->max_output) PID->output_data = PID->max_output;
		else if (PID->output_data < PID->min_output) PID->output_data = PID->min_output;
		
		/*Update Measurement & Time*/
		PID->previous_measurement = current_measurement;
		PID->previous_time = current_time;
	}
	return 1;
}

void Set_Tuning_Parameters(PIDController *PID, double kp, double ki, double kd) {
	
	if (PID->proportional_gain < 0.0 || PID->integral_gain < 0.0 || PID->derivative_gain < 0.0) return;
	
	double sample_time_in_secs = ((double) PID->sample_time) / 1000;
	PID->proportional_gain = kp;
	PID->integral_gain = ki * sample_time_in_secs;
	PID->derivative_gain = kd / sample_time_in_secs;
	
	if (PID->controller_direction == REVERSE) {				
		
		PID->proportional_gain = (0 - PID->proportional_gain);
		PID->integral_gain = (0 - PID->integral_gain);
		PID->derivative_gain = (0 - PID->derivative_gain);
	}
}

void Set_Sample_Time(PIDController *PID, int new_sample_time) {
	
	if (new_sample_time > 0) {
		
		double ratio = (double) new_sample_time / (double) PID->sample_time;
		
		PID->integral_gain *= ratio; // (Ki * dt) * integral(e(t) == Ki integral(e(t) * dt)
		PID->derivative_gain /= ratio; // (Kd / dt) * de == Kd * (de/dt)
		
		PID->sample_time = (unsigned long) new_sample_time;
	}
}

void Set_Output_Limits(PIDController *PID, double min, double max) {
	
	if (min > max) return;
	PID->min_output = min;		
	PID->max_output = max;			
	
	if (PID->output_data > PID->max_output) PID->output_data = PID->max_output;			
	else if (PID->output_data < PID->min_output) PID->output_data = PID->min_output;	
	
	if (PID->Integrator > PID->max_output) PID->Integrator = PID->max_output;	
	else if (PID->Integrator < PID->min_output) PID->Integrator = PID->min_output;
}

void Set_PIDMode(PIDController *PID, PIDMode mode) { 
	
	bool newAutoMode = (mode == AUTOMATIC);
	if (newAutoMode && !PID->inAutoMode) Initialize(PID); //If going from manunal to auto
	PID->inAutoMode = newAutoMode;
}

void Set_ControllerDirection(PIDController *PID, PIDDirection direction) {
	
	PID->controller_direction = direction;
}


//Helper Functions------------------------------------------------------------------------

static void Initialize(PIDController *PID) {		
	
	PID->previous_measurement = PID->current_measurement;	//Keep derivative from spiking
	PID->Integrator = PID->output_data;									
	if (PID->Integrator > PID->max_output) PID->Integrator = PID->max_output;
	else if (PID->Integrator < PID->min_output) PID->Integrator = PID->min_output;
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