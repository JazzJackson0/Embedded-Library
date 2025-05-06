#include "MotorMixAlgo.h"

Motors Motor_Mix(int numOfMotors, double thrustPID, double yawPID, double pitchPID, double rollPID) {
	
	Motors Motor;
	Motor.front_Right = (thrustPID / numOfMotors) + yawPID + pitchPID + rollPID;
	Motor.front_Left = (thrustPID / numOfMotors) - yawPID + pitchPID - rollPID;
	Motor.back_Right = (thrustPID / numOfMotors) - yawPID - pitchPID + rollPID;
	Motor.back_Left = (thrustPID / numOfMotors) + yawPID - pitchPID - rollPID;
	
	if (numOfMotors == 6) {
		
	}

	if (numOfMotors == 8) {

	}
	
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