#ifndef ROTATION_MATRIX_H
#define ROTATION_MATRIX_H
#include "../Logic/matrix_math.h"

//DECLARATIONS
/**
 * @brief 
 * 
 * @param xRotation 
 * @param yRotation 
 * @param zRotation 
 * @return ** Matrix* 
 */
Matrix* RotationMaster(double xRotation, double yRotation, double zRotation);
/**
 * @brief 
 * 
 * @param rotationAngle 
 * @return ** Matrix* 
 */
Matrix* RotateAroundX_Roll(double rotationAngle);
/**
 * @brief 
 * 
 * @param rotationAngle 
 * @return ** Matrix* 
 */
Matrix* RotateAroundY_Pitch(double rotationAngle);
/**
 * @brief 
 * 
 * @param rotationAngle 
 * @return ** Matrix* 
 */
Matrix* RotateAroundZ_Yaw(double rotationAngle);



#endif