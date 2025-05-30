#include "Thrust.h"

/*Conversion Table-----------------------------------------------------------------------------
	+ 1Kg = 9.81 N
*/

//Functions------------------------------------------------------------------------------------

float Calculate_UpwardForce(float droneMass, uint8_t thrustRatio) {
	
	//Returns Newtons
	return (((droneMass * (float) thrustRatio) / (float) 1000)) * ACEL_GRAV; 
}

float Calculate_UpwardForcePerMotor(float upwardForce, uint8_t numOfMotors) {
	
	return upwardForce / numOfMotors;
}

float ThrustNewtons_to_ThrustGrams(float newtons) {
	
	return (newtons / 9.81) * 1000;
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