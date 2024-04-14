#include <assert.h>
#include <stdlib.h>
#include "ComplementaryFilter.h"
#include "../FlightControl/StateEstimator/SensorDataConvert.h"

void complementary_filterTest();

int main(int argc, char *argv[]) {

    complementary_filterTest();
    return 0;
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void complementary_filterTest() {
    filteredAngles f1 = FILTERED_ANGLE_INIT;
    filteredAngles *fAngles = &f1;
    RotationAngles *rAngles = malloc(sizeof(RotationAngles));
    rAngles->Angle_Ax = 10.0;
    rAngles->Angle_Ay = 15.0;
    rAngles->Angle_Az = 20.0;
    rAngles->Angle_Gx = 20.0;
    rAngles->Angle_Gy = 20.0;
    rAngles->Angle_Gz = 25.0;

    assert(0.00 == fAngles->Filtered_Angle_X);
    assert(0.00 == fAngles->Filtered_Angle_Y);
    assert(0.00 == fAngles->Filtered_Angle_Z);
    
    complementary_filter(fAngles, rAngles, 0.80, 0.20);
    
    assert( (0.80 * (20.0)) + (0.20 * (10.0)) == (int) fAngles->Filtered_Angle_X);
    assert( (0.80 * (20.0)) + (0.20 * (15.0)) == (int) fAngles->Filtered_Angle_Y);
    assert( (0.80 * (25.0)) + (0.20 * (20.0)) == (int) fAngles->Filtered_Angle_Z);
    //For come reason C is converting lvalue to int

    free(rAngles);
}