#ifndef PID_H
#define PID_H
#include <stdbool.h>

#define AUTOMATIC 1			
#define REVERSE 1

typedef struct pid PIDController;
typedef enum mode PIDMode;
typedef enum dir PIDDirection;

//DECLARATIONS
/**
 * @brief Initialize the PID Controller
 * 
 * @return ** PIDController Initialized PID
 */
PIDController PID_Init(void);

/**
 * @brief Run PID on incoming data.
 * 
 * @param PID PID to be updated
 * @param set_point Set point to compare incoming value to.
 * @param current_measurement current incoming value to input into the PID
 * @param RTCTimeKeepingFunction Device specific time-keeping function to track time
 * 								since last calculation.
 * @return ** int 1: Upon successful PID calculation. 0: If in Vehicle is in 
 * 					Manual Mode and does not require PID
 */
int PID_Update(PIDController *PID, double set_point, double current_measurement,
	double (*RTCTimeKeepingFunction)());
/**
 * @brief Sets or Updates the PID Tuning parameters.
 * 
 * @param PID PID to be updated
 * @param kp Proportional Gain Coefficient
 * @param ki Integral Gain Coefficient
 * @param kd Derivative Gain Coefficient
 * @return ** void 
 */
void Set_Tuning_Parameters(PIDController *PID, double kp, double ki, double kd);
/**
 * @brief Sets or Updates the PID Sample Time.
 * 
 * @param PID PID to be updated
 * @param new_sample_time Time interval between calculations
 * @return ** void 
 */
void Set_Sample_Time(PIDController *PID, int new_sample_time);
/**
 * @brief Sets output limits to prevent integral windup
 * 
 * @param PID PID to be updated
 * @param min Min PID Output value
 * @param max Max PID Output value
 * @return ** void 
 */
void Set_Output_Limits(PIDController *PID, double min, double max);
/**
 * @brief Set or Update Vehicle to Manual Mode or AUtomatic Mode
 * 			|||  Manual Mode: Vehicle is remote controlled by a user and not the PID algorithm
 * 			|||  Automatic Mode: Vehicle is controlled by PID algorithm
 * 
 * @param PID PID to be updated
 * @param mode Vehicle Mode: Manual or Automatic
 * @return ** void 
 */
void Set_PIDMode(PIDController *PID, PIDMode mode);
/**
 * @brief Set or Update PID controller Direction
 * 			|||  Direct: Larger inputs lead to Larger outputs
 * 			|||  Reverse: Larger inputs lead to Smaller outputs
 * 
 * @param PID PID to be updated
 * @param direction Direction of PID: Direct or Reverse
 * @return ** void 
 */
void Set_ControllerDirection(PIDController *PID, PIDDirection direction);

/*Controller Mode*/
enum mode {
	manual = 0, automatic = 1
};

/*Controller Direction*/
enum dir {
	direct = 0, reverse = 1
};

struct pid {
	
	double proportional_gain;
	double integral_gain;
	double derivative_gain;

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

#define PID_INIT { .proportional_gain = 0.0f, .integral_gain = 0.0f, .derivative_gain = 0.0f,\
					.max_output = 0.0f, .min_output = 0.0f, .Integrator = 0.0f,\
					.previous_error = 0.0f, .Differentiator = 0.0f, .previous_measurement = 0.0f,\
					.current_measurement = 0.0f, .sample_time = 0.0f, .previous_time = 0.0f,\
					.controller_direction = 0 /*Direct*/, .inAutoMode = 1/*Auto*/, \
					.output_data = 0.0f }

#endif