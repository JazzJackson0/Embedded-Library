#pragma once

//DECLARATIONS
/**
 * @brief 
 * 
 * 
 *      Thrust-to-Weight Ratio Example
 *      ------------------------------
 *              Thrust : Weight
 *                  2 : 1
 *          thrustRatio would be 2
 *            
 *          Upward Force Calc Example
 *          -------------------------
 *              Drone Mass: 700g
 *          Thrust-to-Weight Ratio: 3:1
 *            
 *      ((700 * 3)g / 1000) -> (2100g / 1000)
 *      (2.1Kg * acceleration due to gravity)
 *              = 20.601N Upward Force
 * 
 * @param droneMass 
 * @param thrustRatio 
 * @return ** float 
 */
float Calculate_UpwardForce(uint8_t droneMass, uint8_t thrustRatio);
/**
 * @brief 
 * 
 * @param upwardForce 
 * @param numOfMotors 
 * @return ** float 
 */
float Calculate_UpwardForcePerMotor(float upwardForce, uint8_t numOfMotors);
/**
 * @brief 
 * 
 * @param newtons 
 * @return ** float 
 */
float ThrustNewtons_to_ThrustGrams(float newtons);
