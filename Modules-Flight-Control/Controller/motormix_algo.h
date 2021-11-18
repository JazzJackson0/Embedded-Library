ifndef MOTORMIX_ALGO_H
define MOTORMIX_ALGO_H

typedef struct motors _4Motors;
_4Motors* Motor_Mix(double thrust, double yaw, double pitch, double roll);


struct motors {
	double front_Right;
	double front_Left;
	double back_Right;
	double back_Left;
};



#endif


