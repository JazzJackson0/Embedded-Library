#pragma once

typedef struct euler EulerAngle;

//DECLARATIONS
/**
 * @brief 
 * 
 * @param one The angle of rotation in your corresponding matrix (X,Y or Z)
 * @param two The angle of rotation in your corresponding matrix (X,Y or Z)
 * @param three The angle of rotation in your corresponding matrix (X,Y or Z)
 * @return ** EulerAngle* 
 */
EulerAngle* RotMat_to_EulerAngles(double one, double two, double three);
/**
 * @brief 
 * 
 * @param one The angle of rotation in your corresponding matrix (X,Y or Z)
 * @param two The angle of rotation in your corresponding matrix (X,Y or Z)
 * @param three The angle of rotation in your corresponding matrix (X,Y or Z)
 * @return ** EulerAngle* 
 */
EulerAngle* RotMat_to_TaitBryanAngles(double one, double two, double three);

//Structs
struct euler {
    double Roll;
    double Pitch;
    double Yaw;
};