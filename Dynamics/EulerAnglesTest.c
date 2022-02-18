#include <assert.h>
#include <math.h>
#include "euler_angles.h"

void RotMat_to_EulerAnglesTest();
void RotMat_to_TaitBryanAnglesTest();
const double degree2RadConvert = 3.141592 / 180;
EulerAngle *euler;

int main(int argc, char *argv[]) {

    RotMat_to_EulerAnglesTest();
    RotMat_to_TaitBryanAnglesTest();
    return 0;
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void RotMat_to_EulerAnglesTest() {

    euler = RotMat_to_EulerAngles(30.0, 45.0, 60.0);
    
    double one = 30.0 * degree2RadConvert;
    double two = 45.0 * degree2RadConvert;
    double three = 60.0 * degree2RadConvert;

    assert(euler->Roll > 0.0);
    assert(euler->Pitch > 0.0);
    assert(euler->Yaw > 0.0);

    assert(atan( ( sin(one) * sin(two) ) / ( cos(one) * sin(two) ) ) == euler->Roll);
    assert(atan( sqrt( 1 - ( cos(two) * cos(two) ) ) / cos(two) ) == euler->Pitch);
    assert(atan( ( sin(two) * sin(three) ) / ( cos(three) * sin(two) ) ) == euler->Yaw);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void RotMat_to_TaitBryanAnglesTest() {
    
    euler = RotMat_to_TaitBryanAngles(30.0, 45.0, 60.0);
    
    double one = 30.0 * degree2RadConvert;
    double two = 45.0 * degree2RadConvert;
    double three = 60.0 * degree2RadConvert;

    assert(euler->Roll > 0);
    assert(euler->Pitch > 0);
    assert(euler->Yaw > 0);

    assert(atan( cos(two) * sin(one) / ( cos(one) * cos(two) ) ) == euler->Roll);
    assert(atan( sin(two) / sqrt( 1 - ( sin(two) * sin(two) ) ) ) == euler->Pitch);
    assert(atan( cos(two) * sin(three) / ( cos(two) * cos(three) ) ) == euler->Yaw);
}
