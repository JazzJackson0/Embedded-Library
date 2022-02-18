#pragma once

typedef struct euler EulerAngle;

//DECLARATIONS
/**
 * @brief Convert given rotation angles to euler angles.
 *          |||  Example: for XZX rotation matrix: one = x-rotation, 
 *              two = z-rotation, three = x-rotation.
 *          |||  Available Sets: XZX, XYX, YXY, YZY, ZYZ, ZXZ
 * 
 * @param one The (X,Y or Z) angle of rotation in your corresponding rotation matrix
 * @param two The (X,Y or Z) angle of rotation in your corresponding rotation matrix
 * @param three The (X,Y or Z) angle of rotation in your corresponding rotation matrix
 * @return ** EulerAngle* 
 */
EulerAngle* RotMat_to_EulerAngles(double one, double two, double three);
/**
 * @brief Convert given rotation angles to tait-bryan angles.
 *          |||  Example: for XZY rotation matrix: one = x-rotation, 
 *              two = z-rotation, three = y-rotation.
 *          |||  Available Sets: XZY, XYZ, YXZ, YZX, ZYX, ZXY
 * 
 * @param one The (X,Y or Z) angle of rotation in your corresponding rotation matrix 
 * @param two The (X,Y or Z) angle of rotation in your corresponding rotation matrix
 * @param three The (X,Y or Z) angle of rotation in your corresponding rotation matrix
 * @return ** EulerAngle* 
 */
EulerAngle* RotMat_to_TaitBryanAngles(double one, double two, double three);

//Structs
struct euler {
    double Roll;
    double Pitch;
    double Yaw;
};