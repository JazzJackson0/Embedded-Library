#include <math.h>
##include <stdlib.h>
#include "motormix_algo.h"



/**
									Motor Mixing Algorithm
									----------------------

Motor (Front Right)		=	[1/4]Thrust Command		+	Yaw Command		+	Pitch Command	+	Roll Command


Motor (Front Left)		=	[1/4]Thrust Command		-	Yaw Command		+	Pitch Command	-	Roll Command


Motor (Back Right)		=	[1/4]Thrust Command		-	Yaw Command		-	Pitch Command	+	Roll Command


Motor (Back Left)		=	[1/4]Thrust Command		+	Yaw Command		-	Pitch Command	-	Roll Command

**/

_4Motors* Motor_Mix(double thrust, double yaw, double pitch, double roll) {
	
	_4Motors *Motor = malloc(sizeof(_4Motors));
	
	Motor->front_Right = (thrust / 4) + yaw + pitch + roll;
	Motor->front_Left = (thrust / 4) - yaw + pitch - roll;
	Motor->back_Right = (thrust / 4) - yaw - pitch + roll;
	Motor->back_Left = (thrust / 4) + yaw - pitch - roll;
	
	return Motor;
}

//This way you only need 1 thrust data point, 1 yaw data point, 1 pitch data point, etc. Rather than 4 data points for each command, for each motor.
//This is likely implemented well with a matrix


//Note: To maintain altidutde when moving, the thrust must be increased.

