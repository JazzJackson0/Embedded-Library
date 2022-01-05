#pragma once


float Calculate_UpwardForce(uint8_t droneMass, uint8_t thrustRatio);
float Calculate_UpwardForcePerMotor(float upwardForce, uint8_t numOfMotors);
float ThrustNewtons_to_ThrustGrams(float newtons);
