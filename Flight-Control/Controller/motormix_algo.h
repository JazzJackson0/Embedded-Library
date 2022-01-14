#ifndef MOTORMIX_ALGO_H
#define MOTORMIX_ALGO_H

typedef struct motors _4Motors;

//DECLARATIONS
/**
 * @brief 
 * 		Motor (Front Right) = [1/4]Thrust Command + Yaw Command + Pitch Command + Roll Command
 *		Motor (Front Left) = [1/4]Thrust Command - Yaw Command + Pitch Command - Roll Command
 *		Motor (Back Right) = [1/4]Thrust Command - Yaw Command - Pitch Command + Roll Command
 *		Motor (Back Left) = [1/4]Thrust Command + Yaw Command - Pitch Command - Roll Command
 * 
 * @param thrustPID 
 * @param yawPID 
 * @param pitchPID 
 * @param rollPID 
 * @return ** _4Motors* 
 */
_4Motors* Motor_Mix(double thrustPID, double yawPID, double pitchPID, double rollPID);


struct motors {
	double front_Right;
	double front_Left;
	double back_Right;
	double back_Left;
};



#endif


