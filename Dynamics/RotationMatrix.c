#include "RotationMatrix.h"



Matrix* RotationMaster(double xAngle, double yAngle, double zAngle) {

	Matrix *master_Matrix = MatrixInit(3, 3);
	
	master_Matrix->matrix[0][0] = cos(zAngle) * cos(yAngle);
	master_Matrix->matrix[0][1] = (cos(zAngle) * sin(yAngle) * sin(xAngle)) - (sin(zAngle) * cos(xAngle));
	master_Matrix->matrix[0][2] = (cos(zAngle) * sin(yAngle) * cos(xAngle)) + (sin(zAngle) * sin(xAngle));
	master_Matrix->matrix[1][0] = sin(zAngle) * cos(yAngle);
	master_Matrix->matrix[1][1] = (sin(zAngle) * sin(yAngle) * sin(xAngle)) + (cos(zAngle) * cos(xAngle));
	master_Matrix->matrix[1][2] = (sin(zAngle) * sin(yAngle) * cos(xAngle)) - (cos(zAngle) * sin(xAngle));
	master_Matrix->matrix[2][0] = -1 * sin(yAngle);
	master_Matrix->matrix[2][1] = cos(yAngle) * sin(xAngle);
	master_Matrix->matrix[2][2] = cos(yAngle) * cos(xAngle);

	return master_Matrix;
}

Matrix* RotateAroundX_Roll(double rotationAngle) {

	Matrix *xRotationMatrix = MatrixInit(3, 3);
	
	//Create your 3D rotation matrix for X-axis
	xRotationMatrix->matrix[0][0] = 1.0;
	xRotationMatrix->matrix[0][1] = 0.0;
	xRotationMatrix->matrix[0][2] = 0.0;
	xRotationMatrix->matrix[1][0] = 0.0;
	xRotationMatrix->matrix[1][1] = cos(rotationAngle);
	xRotationMatrix->matrix[1][2] = (-1 * sin(rotationAngle));
	xRotationMatrix->matrix[2][0] = 0.0;
	xRotationMatrix->matrix[2][1] = sin(rotationAngle);
	xRotationMatrix->matrix[2][2] = cos(rotationAngle);

	return xRotationMatrix;
}

Matrix* RotateAroundY_Pitch(double rotationAngle) {

	Matrix *yRotationMatrix = MatrixInit(3, 3);
	
	//Create your 3D rotation matrix for Y-axis
	
	yRotationMatrix->matrix[0][0] = cos(rotationAngle);
	yRotationMatrix->matrix[0][1] = 0.0;
	yRotationMatrix->matrix[0][2] = sin(rotationAngle);
	yRotationMatrix->matrix[1][0] = 0.0;
	yRotationMatrix->matrix[1][1] = 1.0;
	yRotationMatrix->matrix[1][2] = 0.0;
	yRotationMatrix->matrix[2][0] = (-1 * sin(rotationAngle));
	yRotationMatrix->matrix[2][1] = 0.0;
	yRotationMatrix->matrix[2][2] = cos(rotationAngle);
	
	return yRotationMatrix;
}

Matrix* RotateAroundZ_Yaw(double rotationAngle) {

	Matrix *zRotationMatrix = MatrixInit(3, 3);
	
	//Create your 3D rotation matrix for Z-axis
	zRotationMatrix->matrix[0][0] = cos(rotationAngle);
	zRotationMatrix->matrix[0][1] = (-1 * sin(rotationAngle));
	zRotationMatrix->matrix[0][2] = 0.0;
	zRotationMatrix->matrix[1][0] = sin(rotationAngle);
	zRotationMatrix->matrix[1][1] = cos(rotationAngle);
	zRotationMatrix->matrix[1][2] = 0.0;
	zRotationMatrix->matrix[2][0] = 0.0;
	zRotationMatrix->matrix[2][1] = 0.0;
	zRotationMatrix->matrix[2][2] = 1.0;

	return zRotationMatrix;
}

/*
 * 			TO-DO
 * 			-----
 *  - 
 *
 *  - 
 *  
 *  - 
 *  */

