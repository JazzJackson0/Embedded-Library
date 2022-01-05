#ifndef ROTATION_MATRIX_H
#define ROTATION_MATRIX_H

double** RotationMaster(double xRotation, double yRotation, double zRotation);
double** RotateAroundX_Roll(double rotationAngle);
double** RotateAroundY_Pitch(double rotationAngle);
double** RotateAroundZ_Yaw(double rotationAngle);



#endif