#ifndef ROTATION_MATRIX_H
#define ROTATION_MATRIX_H

//DECLARATIONS
/**
 * @brief 
 * 
 * @param xRotation 
 * @param yRotation 
 * @param zRotation 
 * @return ** double** 
 */
double** RotationMaster(double xRotation, double yRotation, double zRotation);
/**
 * @brief 
 * 
 * @param rotationAngle 
 * @return ** double** 
 */
double** RotateAroundX_Roll(double rotationAngle);
/**
 * @brief 
 * 
 * @param rotationAngle 
 * @return ** double** 
 */
double** RotateAroundY_Pitch(double rotationAngle);
/**
 * @brief 
 * 
 * @param rotationAngle 
 * @return ** double** 
 */
double** RotateAroundZ_Yaw(double rotationAngle);



#endif