#include <assert.h>
#include <stdlib.h>
#include "complementary_filter.h"

void complementary_filterTest();

int main(int argc, char *argv[]) {

    complementary_filterTest();
    return 0;
}

void complementary_filterTest() {
    
    RotationAngles *rAngles;
    filteredAngles *fAngles;
    filteredAngles *fAnglesResult;
    
    fAnglesResult = complementary_filter(fAngles, rAngles, 0.80, 0.20);
    
    assert(0.00, fAnglesResult->Filtered_Angle_X);
    assert(0.00, fAnglesResult->Filtered_Angle_Y);
    assert(0.00, fAnglesResult->Filtered_Angle_Z);
}