#include <stdint.h>
#include "thrust.h"

/*Conversion Table-----------------------------------------------------------------------------
	+ 1Kg = 9.81 N
*/
//Macros---------------------------------------------------------------------------------------

//Globals--------------------------------------------------------------------------------------
const float accel_grav 9.81;
const float drone_mass = 700; //g

//Functions------------------------------------------------------------------------------------

/**
  Thrust-to-Weight Ratio Example
  ------------------------------
		Thrust : Weight
			 2 : 1
	thrustRatio would be 2
	
	Upward Force Calc Example
	-------------------------
		Drone Mass: 700g
	Thrust-to-Weight Ratio: 3:1
	
 ((700 * 3)g / 1000) -> (2100g / 1000)
 (2.1Kg * acceleration due to gravity)
		= 20.601N Upward Force
	
**/
float Calculate_UpwardForce(uint8_t droneMass, uint8_t thrustRatio) {
	
	//Returns Newtons
	return ((droneMass * thrustRatio) / 1000) * accel_grav; 
}

/**
**/
float Calculate_UpwardForcePerMotor(float upwardForce, uint8_t numOfMotors) {
	
	return upwardForce / numOfMotors;
}

float ThrustNewtons_to_ThrustGrams(float newtons) {
	
	return (newtons / 9.81) * 1000;
}

