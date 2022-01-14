#include <stdint.h>
#include "thrust.h"

/*Conversion Table-----------------------------------------------------------------------------
	+ 1Kg = 9.81 N
*/
//Macros---------------------------------------------------------------------------------------

//Globals--------------------------------------------------------------------------------------
const float accel_grav = 9.81;
const float drone_mass = 700; //g

//Functions------------------------------------------------------------------------------------

float Calculate_UpwardForce(uint8_t droneMass, uint8_t thrustRatio) {
	
	//Returns Newtons
	return ((droneMass * thrustRatio) / 1000) * accel_grav; 
}

float Calculate_UpwardForcePerMotor(float upwardForce, uint8_t numOfMotors) {
	
	return upwardForce / numOfMotors;
}

float ThrustNewtons_to_ThrustGrams(float newtons) {
	
	return (newtons / 9.81) * 1000;
}

