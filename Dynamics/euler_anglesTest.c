#include <assert.h>
#include <stdlib.h>
#include "euler_angles.h"

void RotMat_to_EulerAnglesTest();
void RotMat_to_TaitBryanAnglesTest();

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

    assert(0.0 == RotMat_to_EulerAngles(30.0, 45.0, 60.0)->Roll);
    assert(0.0 == RotMat_to_EulerAngles(30.0, 45.0, 60.0)->Pitch);
    assert(0.0 == RotMat_to_EulerAngles(30.0, 45.0, 60.0)->Yaw);

    assert(RotMat_to_EulerAngles(30.0, 45.0, 60.0)->Roll > 0);
    assert(RotMat_to_EulerAngles(30.0, 45.0, 60.0)->Pitch > 0);
    assert(RotMat_to_EulerAngles(30.0, 45.0, 60.0)->Yaw > 0);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void RotMat_to_TaitBryanAnglesTest() {
    
    assert(0.0 == RotMat_to_TaitBryanAngles(30.0, 45.0, 60.0)->Roll);
    assert(0.0 == RotMat_to_TaitBryanAngles(30.0, 45.0, 60.0)->Pitch);
    assert(0.0 == RotMat_to_TaitBryanAngles(30.0, 45.0, 60.0)->Yaw);

    assert(RotMat_to_TaitBryanAngles(30.0, 45.0, 60.0)->Roll > 0);
    assert(RotMat_to_TaitBryanAngles(30.0, 45.0, 60.0)->Pitch > 0);
    assert(RotMat_to_TaitBryanAngles(30.0, 45.0, 60.0)->Yaw > 0);
}
