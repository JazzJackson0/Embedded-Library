#ifndef MOTORMIX_ALGO_H
#define MOTORMIX_ALGO_H
#include <math.h>
#include <stdlib.h>

typedef struct motors Motors;

//DECLARATIONS
/**
 * @brief Alters motor thrust values based on Roll, Pitch and Yaw PID results.
 * 		|||  Example:
 * 		|||  Motor (Front Right) = [1/4]Thrust Command + Yaw Command + Pitch Command + Roll Command
 *		|||  Motor (Front Left) = [1/4]Thrust Command - Yaw Command + Pitch Command - Roll Command
 *		|||  Motor (Back Right) = [1/4]Thrust Command - Yaw Command - Pitch Command + Roll Command
 *		|||  Motor (Back Left) = [1/4]Thrust Command + Yaw Command - Pitch Command - Roll Command
 * 
 * @param numOfMotors Number of motors being used.
 * @param thrustPID Thrust PID Value
 * @param yawPID Yaaw PID Value
 * @param pitchPID Pitch PID Value
 * @param rollPID Roll PID Value
 * @return ** Motors* Amount of thrust required per motor
 */
Motors* Motor_Mix(int numOfMotors, double thrustPID, double yawPID, double pitchPID, double rollPID);

/**
 * @brief Amounts of thrust per motor
 * 
 */
struct motors {
	double front_Right;
	double front_Left;
	double back_Right;
	double back_Left;

	/*----6 Motor Config----*/
	double front;
	double back;
	//Or
	double right;
	double left;

	/*----8 Motor Config----*/
	/*Would use 6 Motor Config's right and left as right_infront and left_infront.
	Along with the 4 motor configuration to make 8*/
	double right_behind;
	double left_behind;
};



#endif


