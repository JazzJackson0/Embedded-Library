#include "EulerAngles.h"


Matrix EulerOrientation_XYZ(double roll, double pitch, double yaw) {

    Matrix xRotation = Get_XRotationMatrix(roll);
    Matrix yRotation = Get_YRotationMatrix(pitch);
    Matrix zRotation = Get_ZRotationMatrix(yaw);

    Matrix orientation = MultiplyMatrices(yRotation, zRotation);
    orientation = MultiplyMatrices(xRotation, orientation);
    return orientation;
}

Matrix EulerOrientation_ZYX(double roll, double pitch, double yaw) {

    Matrix xRotation = Get_XRotationMatrix(roll);
    Matrix yRotation = Get_YRotationMatrix(pitch);
    Matrix zRotation = Get_ZRotationMatrix(yaw);

    Matrix orientation = MultiplyMatrices(yRotation, yRotation);
    orientation = MultiplyMatrices(zRotation, orientation);
    return orientation;
}

Matrix EulerOrientation_ZYZ(double pitch, double yaw) {

    Matrix yRotation = Get_YRotationMatrix(pitch);
    Matrix zRotation = Get_ZRotationMatrix(yaw);

    Matrix orientation = MultiplyMatrices(yRotation, zRotation);
    orientation = MultiplyMatrices(zRotation, orientation);
    return orientation;
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