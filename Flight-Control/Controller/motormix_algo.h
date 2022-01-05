#ifndef MOTORMIX_ALGO_H
#define MOTORMIX_ALGO_H

typedef struct motors _4Motors;
_4Motors* Motor_Mix(double thrustPID, double yawPID, double pitchPID, double rollPID);


struct motors {
	double front_Right;
	double front_Left;
	double back_Right;
	double back_Left;
};



#endif


