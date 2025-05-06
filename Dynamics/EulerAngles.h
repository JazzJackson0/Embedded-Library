#pragma once
#include <math.h>
#include <stdlib.h>
#include "RotationMatrix.h"
#include "../Logic/MatrixMath.h"


//DECLARATIONS
/**
 * @brief Define the orientation given the 3 Euler Angles
 * 
 * @param roll The Roll Rotation 
 * @param pitch The Pitch Rotation
 * @param yaw The Yaw Rotation
 * @return ** The Final Orientation Rotation Matrix 
 */
Matrix EulerOrientation_XYZ(double roll, double pitch, double yaw);
/**
 * @brief Define the orientation given the 3 Euler Angles
 * 
 * @param roll The Roll Rotation 
 * @param pitch The Pitch Rotation
 * @param yaw The Yaw Rotation
 * @return ** The Final Orientation Rotation Matrix 
 */
Matrix EulerOrientation_ZYX(double roll, double pitch, double yaw);
/**
 * @brief Define the orientation given the 3 Euler Angles
 * 
 * @param pitch The Pitch Rotation
 * @param yaw The Yaw Rotation
 * @return ** The Final Orientation Rotation Matrix 
 */
Matrix EulerOrientation_ZYZ(double pitch, double yaw);

