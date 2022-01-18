#include <assert.h>
#include <stdlib.h>
#include "rotation_matrix.h"

void RotationMasterTest();
void RotateAroundX_RollTest();
void RotateAroundY_PitchTest();
void RotateAroundZ_YawTest();

int main(int argc, char *argv[]) {

    RotationMasterTest();
    RotateAroundX_RollTest();
    RotateAroundY_PitchTest();
    RotateAroundZ_YawTest();
    return 0;
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void RotationMasterTest() {
    assert(0.0 == RotationMaster(0.0, 0.0, 0.0)[0][0]);
    assert(0.0 == RotationMaster(0.0, 0.0, 0.0)[0][1]);
    assert(0.0 == RotationMaster(0.0, 0.0, 0.0)[0][2]);
    assert(0.0 == RotationMaster(0.0, 0.0, 0.0)[1][0]);
    assert(0.0 == RotationMaster(0.0, 0.0, 0.0)[1][1]);
    assert(0.0 == RotationMaster(0.0, 0.0, 0.0)[1][2]);
    assert(0.0 == RotationMaster(0.0, 0.0, 0.0)[2][0]);
    assert(0.0 == RotationMaster(0.0, 0.0, 0.0)[2][1]);
    assert(0.0 == RotationMaster(0.0, 0.0, 0.0)[2][2]);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void RotateAroundX_RollTest() {
    assert(0.0 == RotateAroundX_Roll(0.0)[0][0]);
    assert(0.0 == RotateAroundX_Roll(0.0)[0][1]);
    assert(0.0 == RotateAroundX_Roll(0.0)[0][2]);
    assert(0.0 == RotateAroundX_Roll(0.0)[1][0]);
    assert(0.0 == RotateAroundX_Roll(0.0)[1][1]);
    assert(0.0 == RotateAroundX_Roll(0.0)[1][2]);
    assert(0.0 == RotateAroundX_Roll(0.0)[2][0]);
    assert(0.0 == RotateAroundX_Roll(0.0)[2][1]);
    assert(0.0 == RotateAroundX_Roll(0.0)[2][2]);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void RotateAroundY_PitchTest() {
    assert(0.0 == RotateAroundY_Pitch(0.0)[0][0]);
    assert(0.0 == RotateAroundY_Pitch(0.0)[0][1]);
    assert(0.0 == RotateAroundY_Pitch(0.0)[0][2]);
    assert(0.0 == RotateAroundY_Pitch(0.0)[1][0]);
    assert(0.0 == RotateAroundY_Pitch(0.0)[1][1]);
    assert(0.0 == RotateAroundY_Pitch(0.0)[1][2]);
    assert(0.0 == RotateAroundY_Pitch(0.0)[2][0]);
    assert(0.0 == RotateAroundY_Pitch(0.0)[2][1]);
    assert(0.0 == RotateAroundY_Pitch(0.0)[2][2]);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void RotateAroundZ_YawTest() {
    assert(0.0 == RotateAroundZ_Yaw(0.0)[0][0]);
    assert(0.0 == RotateAroundZ_Yaw(0.0)[0][1]);
    assert(0.0 == RotateAroundZ_Yaw(0.0)[0][2]);
    assert(0.0 == RotateAroundZ_Yaw(0.0)[1][0]);
    assert(0.0 == RotateAroundZ_Yaw(0.0)[1][1]);
    assert(0.0 == RotateAroundZ_Yaw(0.0)[1][2]);
    assert(0.0 == RotateAroundZ_Yaw(0.0)[2][0]);
    assert(0.0 == RotateAroundZ_Yaw(0.0)[2][1]);
    assert(0.0 == RotateAroundZ_Yaw(0.0)[2][2]);
}