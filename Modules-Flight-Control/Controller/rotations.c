#include <math.h>
#include "rotations.h"


double emptyMatrix[3][3] = { 
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0}
};

//Point
static double x = 0;
static double y = 0; 
static double z = 0;


void RotationMaster(double xRotation, double yRotation, double zRotation) {
	
	double master_Matrix[3][3] = emptyMatrix[3][3];
	
	master_Matrix[0][0] = cos(zRotation) * cos(yRotation);
	master_Matrix[0][1] = (cos(zRotation) * sin(yRotation) * sin(xRotation)) - (sin(zRotation) * cos(xRotation));
	master_Matrix[0][2] = (cos(zRotation) * sin(yRotation) * cos(xRotation)) + (sin(zRotation) * sin(xRotation));
	master_Matrix[1][0] = sin(zRotation) * cos(yRotation);
	master_Matrix[1][1] = (sin(zRotation) * sin(yRotation) * sin(xRotation)) + (cos(zRotation) * cos(xRotation));
	master_Matrix[1][2] = (sin(zRotation) * sin(yRotation) * cos(xRotation)) - (cos(zRotation) * sin(xRotation));
	master_Matrix[2][0] = -1 * sin(yRotation);
	master_Matrix[2][1] = cos(yRotation) * sin(xRotation);
	master_Matrix[2][2] = cos(yRotation) * cos(xRotation);
}

void RotateAroundX_Roll(double rotationAngle) {
	
	double xRotationMatrix[3][3] = emptyMatrix[3][3];
	
	//Create your 3D rotation matrix for X-axis
	xRotationMatrix[0][0] = 1 * x;
	xRotationMatrix[1][1] = cos(rotationAngle) * y;
	xRotationMatrix[1][2] = (-1 * sin(rotationAngle)) * z;
	xRotationMatrix[2][1] = sin(rotationAngle) * y;
	xRotationMatrix[2][2] = cos(rotationAngle) * z;
}

void RotateAroundY_Pitch(double rotationAngle) {
	
	double yRotationMatrix[3][3] = emptyMatrix[3][3];
	
	//Create your 3D rotation matrix for Y-axis
	yRotationMatrix[0][0] = cos(rotationAngle) * x;
	yRotationMatrix[0][2] = sin(rotationAngle) * z;
	yRotationMatrix[2][1] = 1 * y;
	yRotationMatrix[2][0] = cos(rotationAngle) * x;
	yRotationMatrix[2][2] = (-1 * sin(rotationAngle)) * z;
}

void RotateAroundZ_Yaw(double rotationAngle) {
	
	double zRotationMatrix[3][3] = emptyMatrix[3][3];
	
	//Create your 3D rotation matrix for Z-axis
	zRotationMatrix[0][0] = cos(rotationAngle) * x;
	zRotationMatrix[0][1] = (-1 * sin(rotationAngle)) * y;
	zRotationMatrix[1][0] = sin(rotationAngle) * x;
	zRotationMatrix[1][1] = cos(rotationAngle) * y;
	zRotationMatrix[2][2] = 1 * z;
}

