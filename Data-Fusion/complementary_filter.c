#include "complementary_filter.h"
#include "../Flight-Control/State-Estimator/sensordata_convert.h"

/*
Parameters
Ax - Az: Rotation angles obtained from acceleration
Gx - Gz: Rotation angles obtained from angular velocity
*/
filteredAngles* complementary_filter(filteredAngles* angles, RotationAngles* rotations, float gyroWeight, float accelWeight) {

    // Ensure weights add up to 1!!

    angles->Filtered_Angle_X = (gyroWeight * (angles->Filtered_Angle_X + rotations->Angle_Gx)) + (accelWeight * (rotations->Angle_Ax));
    angles->Filtered_Angle_Y = (gyroWeight * (angles->Filtered_Angle_Y + rotations->Angle_Gy)) + (accelWeight * (rotations->Angle_Ay));
    angles->Filtered_Angle_Z = (gyroWeight * (angles->Filtered_Angle_Z + rotations->Angle_Gz)) + (accelWeight * (rotations->Angle_Az));

    return angles;
}



/*
 * 			TO-DO
 * 			-----
 *  - Ensure weights add up to 1!!
 *
 *  - Test Code
 *  
 *  - 
 *  */