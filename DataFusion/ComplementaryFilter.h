#pragma once
#include "../FlightControl/StateEstimator/SensorDataConvert.h"

#define FILTERED_ANGLE_INIT { 0.0, 0.0, 0.0 }

typedef struct f_angles filteredAngles;

//DECLARATIONS
/**
 * @brief Run Complementary Filter on incoming data
 * 
 * @param angles Resulting x,y,z angles filtered through the Complementary Filter
 * @param rotations Pre-Filtered Rotation Angles
 * @param gyroWeight Gyroscope Weighting Coefficient
 * @param accelWeight Accelerometer Weighting Coefficient
 * @return ** void* 
 */
void complementary_filter(filteredAngles* angles, RotationAngles rotations, float gyroWeight, float accelWeight);


//Structs
struct f_angles {

    double Filtered_Angle_X;
    double Filtered_Angle_Y;
    double Filtered_Angle_Z;
};




