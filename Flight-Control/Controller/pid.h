#ifndef PID_H
#define PID_H

#include <stdbool.h>
typedef struct pid PIDController;

//DECLARATIONS
/**
 * @brief 
 * 
 * @return ** PIDController* 
 */
PIDController* PID_Init(void);
/**
 * @brief 
 * 
 * @param PID 
 * @param set_point 
 * @param current_measurement 
 * @return ** PIDController* 
 */
PIDController* PID_Update(PIDController *PID, double set_point, double current_measurement);
/**
 * @brief 
 * 
 * @param PID 
 * @param kp 
 * @param ki 
 * @param kd 
 * @return ** void 
 */
void Set_Tuning_Parameters(PIDController *PID, double kp, double ki, double kd);
/**
 * @brief 
 * 
 * @param PID 
 * @param new_sample_time 
 * @return ** void 
 */
void Set_Sample_Time(PIDController *PID, int new_sample_time);
/**
 * @brief 
 * 
 * @param PID 
 * @param min 
 * @param max 
 * @return ** void 
 */
void Set_Output_Limits(PIDController *PID, double min, double max);
/**
 * @brief Set PID to Manual Mode or AUtomatic Mode
 * 			Manual Mode: 
 * 			Automatic Mode: 
 * 
 * @param PID 
 * @param mode 
 * @return ** void 
 */
void Set_PIDMode(PIDController *PID, int mode);
/**
 * @brief 
 * 
 * @param PID 
 * @param direction 
 * @return ** void 
 */
void Set_ControllerDirection(PIDController *PID, int direction);

/*Controller Mode*/
#define MANUAL 0
#define AUTOMATIC 1

/*Controller Direction*/
#define DIRECT 0			
#define REVERSE 1

struct pid {
	
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
};

#define PID_INIT { .proportional_gain = 0, .integral_gain = 0, .derivative_gain = 0,\
					.max_output = 0.0f, .min_output = 0.0f, .Integrator = 0.0f,\
					.previous_error = 0.0f, .Differentiator = 0.0f, .previous_measurement = 0.0f,\
					.current_measurement = 0.0f, .sample_time = 0.0f, .previous_time = 0.0f,\
					.controller_direction = DIRECT, .inAutoMode = AUTOMATIC, .output_data = 0.0f }

#endif