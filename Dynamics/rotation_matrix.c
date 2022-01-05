#include <math.h>
#include "rotation_matrix.h"


double** RotationMaster(double xAngle, double yAngle, double zAngle) {
	
	double **master_Matrix;
	
	master_Matrix[0][0] = cos(zAngle) * cos(yAngle);
	master_Matrix[0][1] = (cos(zAngle) * sin(yAngle) * sin(xAngle)) - (sin(zAngle) * cos(xAngle));
	master_Matrix[0][2] = (cos(zAngle) * sin(yAngle) * cos(xAngle)) + (sin(zAngle) * sin(xAngle));
	master_Matrix[1][0] = sin(zAngle) * cos(yAngle);
	master_Matrix[1][1] = (sin(zAngle) * sin(yAngle) * sin(xAngle)) + (cos(zAngle) * cos(xAngle));
	master_Matrix[1][2] = (sin(zAngle) * sin(yAngle) * cos(xAngle)) - (cos(zAngle) * sin(xAngle));
	master_Matrix[2][0] = -1 * sin(yAngle);
	master_Matrix[2][1] = cos(yAngle) * sin(xAngle);
	master_Matrix[2][2] = cos(yAngle) * cos(xAngle);

	return master_Matrix;
}

double** RotateAroundX_Roll(double rotationAngle) {
	
	double **xRotationMatrix;
	
	//Create your 3D rotation matrix for X-axis
	xRotationMatrix[0][0] = 1.0;
	xRotationMatrix[0][1] = 0.0;
	xRotationMatrix[0][2] = 0.0;
	xRotationMatrix[1][0] = 0.0;
	xRotationMatrix[1][1] = cos(rotationAngle);
	xRotationMatrix[1][2] = (-1 * sin(rotationAngle));
	xRotationMatrix[2][0] = 0.0;
	xRotationMatrix[2][1] = sin(rotationAngle);
	xRotationMatrix[2][2] = cos(rotationAngle);

	return xRotationMatrix;
}

double** RotateAroundY_Pitch(double rotationAngle) {
	
	double **yRotationMatrix;
	
	//Create your 3D rotation matrix for Y-axis
	
	yRotationMatrix[0][0] = cos(rotationAngle);
	yRotationMatrix[0][1] = 0.0;
	yRotationMatrix[0][2] = sin(rotationAngle);
	yRotationMatrix[1][0] = 0.0;
	yRotationMatrix[1][1] = 1.0;
	yRotationMatrix[1][2] = 0.0;
	yRotationMatrix[2][0] = (-1 * sin(rotationAngle));
	yRotationMatrix[2][1] = 0.0;
	yRotationMatrix[2][2] = cos(rotationAngle);
	
	return yRotationMatrix;
}

double** RotateAroundZ_Yaw(double rotationAngle) {
	
	double **zRotationMatrix;
	
	//Create your 3D rotation matrix for Z-axis
	zRotationMatrix[0][0] = cos(rotationAngle);
	zRotationMatrix[0][1] = (-1 * sin(rotationAngle));
	zRotationMatrix[0][2] = 0.0;
	zRotationMatrix[1][0] = sin(rotationAngle);
	zRotationMatrix[1][1] = cos(rotationAngle);
	zRotationMatrix[1][2] = 0.0;
	zRotationMatrix[2][0] = 0.0;
	zRotationMatrix[2][1] = 0.0;
	zRotationMatrix[2][2] = 1.0;

	return zRotationMatrix;
}

/*
 * 			TO-DO
 * 			-----
 *  - Test Code
 *
 *  - 
 *  
 *  - 
 *  */

