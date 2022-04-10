#include "MotormixAlgo.h"

Motors* Motor_Mix(int numOfMotors, double thrustPID, double yawPID, double pitchPID, double rollPID) {
	
	Motors *Motor = malloc(sizeof(Motors));
	
	Motor->front_Right = (thrustPID / numOfMotors) + yawPID + pitchPID + rollPID;
	Motor->front_Left = (thrustPID / numOfMotors) - yawPID + pitchPID - rollPID;
	Motor->back_Right = (thrustPID / numOfMotors) - yawPID - pitchPID + rollPID;
	Motor->back_Left = (thrustPID / numOfMotors) + yawPID - pitchPID - rollPID;
	
	/* Don't know the physics for this yet...
	if (numOfMotors == 6) {
		
	}

	if (numOfMotors == 8) {

	}
	*/
	
	return Motor;
	//Note: To maintain altidutde when moving, the thrust must be increased.
}



/*
 * 			TO-DO
 * 			-----
 *  - 
 *
 *  - 
 *  
 *  - 
 *  */