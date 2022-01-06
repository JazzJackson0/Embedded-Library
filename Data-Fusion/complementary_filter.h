#pragma once
#include "../Flight-Control/State-Estimator/sensordata_convert.h"

typedef struct f_angles filteredAngles;

//Functions
filteredAngles* complementary_filter(filteredAngles* angles, RotationAngles* rotations, float gyroWeight, float accelWeight);


//Structs
struct f_angles {

    double Filtered_Angle_X;
    double Filtered_Angle_Y;
    double Filtered_Angle_Z;
};

#define FILTERED_ANGLE_INIT { 0.0, 0.0, 0.0 }


