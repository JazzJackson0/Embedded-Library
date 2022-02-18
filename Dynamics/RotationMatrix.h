#ifndef ROTATION_MATRIX_H
#define ROTATION_MATRIX_H
#include "../Logic/matrix_math.h"

//DECLARATIONS
/**
 * @brief Creates a rotation matrix for a set of given Roll, Pitch and Yaw angles.
 * 
 * @param xRotation X Rotation Angle (Roll)
 * @param yRotation Y Rotation Angle (Pitch)
 * @param zRotation Z Rotation Angle (Yaw)
 * @return ** Matrix* 
 */
Matrix* RotationMaster(double xRotation, double yRotation, double zRotation);
/**
 * @brief Creates a Roll rotation matrix for a given angle
 * 
 * @param rotationAngle X Rotation Angle (Roll)
 * @return ** Matrix* Roll Rotation Matrix
 */
Matrix* RotateAroundX_Roll(double rotationAngle);
/**
 * @brief Creates a Pitch rotation matrix for a given angle
 * 
 * @param rotationAngle Y Rotation Angle (Pitch)
 * @return ** Matrix* Pitch Rotation Matrix
 */
Matrix* RotateAroundY_Pitch(double rotationAngle);
/**
 * @brief Creates a Yaw rotation matrix for a given angle
 * 
 * @param rotationAngle Z Rotation Angle (Yaw)
 * @return ** Matrix* Yaw Rotation Matrix
 */
Matrix* RotateAroundZ_Yaw(double rotationAngle);



#endif