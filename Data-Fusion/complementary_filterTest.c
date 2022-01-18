#include <assert.h>
#include <stdlib.h>
#include "complementary_filter.h"

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
    filteredAngles f2 = FILTERED_ANGLE_INIT;
    filteredAngles *fAngles = &f1;
    filteredAngles *fAnglesResult = &f2;
    RotationAngles *rAngles;

    assert(0.00 == f1.Filtered_Angle_X);
    assert(0.00 == f1.Filtered_Angle_Y);
    assert(0.00 == f1.Filtered_Angle_Z);
    
    fAnglesResult = complementary_filter(fAngles, rAngles, 0.80, 0.20);
    
    assert(0.00 == fAnglesResult->Filtered_Angle_X);
    assert(0.00 == fAnglesResult->Filtered_Angle_Y);
    assert(0.00 == fAnglesResult->Filtered_Angle_Z);
}