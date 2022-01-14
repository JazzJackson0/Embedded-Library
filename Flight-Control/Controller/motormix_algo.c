#include <math.h>
#include <stdlib.h>
#include "motormix_algo.h"

_4Motors* Motor_Mix(double thrustPID, double yawPID, double pitchPID, double rollPID) {
	
	_4Motors *Motor = malloc(sizeof(_4Motors));
	
	Motor->front_Right = (thrustPID / 4) + yawPID + pitchPID + rollPID;
	Motor->front_Left = (thrustPID / 4) - yawPID + pitchPID - rollPID;
	Motor->back_Right = (thrustPID / 4) - yawPID - pitchPID + rollPID;
	Motor->back_Left = (thrustPID / 4) + yawPID - pitchPID - rollPID;
	
	return Motor;
}

//Note: To maintain altidutde when moving, the thrust must be increased.

/*
 * 			TO-DO
 * 			-----
 *  - Test Code
 *
 *  - 
 *  
 *  - 
 *  */