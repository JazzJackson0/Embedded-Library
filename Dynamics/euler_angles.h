#pragma once

typedef struct euler EulerAngle;

//Functions
EulerAngle* RotMat_to_EulerAngles(double one, double two, double three);
EulerAngle* RotMat_to_TaitBryanAngles(double one, double two, double three);

//Structs
struct euler {
    double Roll;
    double Pitch;
    double Yaw;
};