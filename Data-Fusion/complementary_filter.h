#pragma once
#include "../Flight-Control/State-Estimator/sensordata_convert.h"

typedef struct f_angles filteredAngles;

//DECLARATIONS
/**
 * @brief 
 * 
 * @param angles 
 * @param rotations 
 * @param gyroWeight 
 * @param accelWeight 
 * @return ** void* 
 */
void complementary_filter(filteredAngles* angles, RotationAngles* rotations, float gyroWeight, float accelWeight);


//Structs
struct f_angles {

    double Filtered_Angle_X;
    double Filtered_Angle_Y;
    double Filtered_Angle_Z;
};

#define FILTERED_ANGLE_INIT { 0.0, 0.0, 0.0 }


