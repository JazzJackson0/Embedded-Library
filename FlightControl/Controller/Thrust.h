#pragma once
#include <stdint.h>

#define ACEL_GRAV 9.81;

//DECLARATIONS
/**
 * @brief Calculates the resultig upward force from a given thrust value and the vehicle's mass.
 * 
 *      |||  Thrust-to-Weight Ratio Example
 *              |||  Thrust : Weight
 *                  |||  2 : 1
 *          |||  So thrust Ratio would be 2
 *            
 *         |||   Upward Force Calc Example
 *              |||  Drone Mass: 700g
 *          |||  Thrust-to-Weight Ratio: 3:1
 *            
 *      |||  ((700 * 3)g / 1000) -> (2100g / 1000)
 *      |||  (2.1Kg * acceleration due to gravity)
 *              |||  = 20.601N Upward Force
 * 
 * @param droneMass Mass of the drone in grams
 * @param thrustRatio The "thrust" portion of the thrust-to-weight ratio
 * @return ** float: Upward force in Newtons.
 */
float Calculate_UpwardForce(float droneMass, uint8_t thrustRatio);
/**
 * @brief Calculates the amount of thrust needed per motor for a vehicle to obtain
 *          the desired upward force.
 * 
 * @param upwardForce Upward force in Newtons.
 * @param numOfMotors Number of Motors on the drone
 * @return ** float: Upward force for 1 motor in Newtons. 
 */
float Calculate_UpwardForcePerMotor(float upwardForce, uint8_t numOfMotors);
/**
 * @brief Converts Thrust in Newtons to Thrust in Grams
 * 
 * @param newtons Thrust in Newtons.
 * @return ** float: Thrust in Grams. 
 */
float ThrustNewtons_to_ThrustGrams(float newtons);
