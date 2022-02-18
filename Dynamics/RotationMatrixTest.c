#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "RotationMatrix.h"

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
    Matrix *rMaster = RotationMaster(30.0, 20.0, 15.0);
    assert(cos(15.0) * cos(20.0) == rMaster->matrix[0][0]);
    assert((cos(15.0) * sin(20.0) * sin(30.0)) - (sin(15.0) * cos(30.0)) 
        == rMaster->matrix[0][1]);
    assert((cos(15.0) * sin(20.0) * cos(30.0)) + (sin(15.0) * sin(30.0)) 
        == rMaster->matrix[0][2]);
    assert(sin(15.0) * cos(20.0) == rMaster->matrix[1][0]);
    assert((sin(15.0) * sin(20.0) * sin(30.0)) + (cos(15.0) * cos(30.0)) 
        == rMaster->matrix[1][1]);
    assert((sin(15.0) * sin(20.0) * cos(30.0)) - (cos(15.0) * sin(30.0)) 
        == rMaster->matrix[1][2]);
    assert(-1 * sin(20.0) == rMaster->matrix[2][0]);
    assert(cos(20.0) * sin(30.0) == rMaster->matrix[2][1]);
    assert(cos(20.0) * cos(30.0) == rMaster->matrix[2][2]);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void RotateAroundX_RollTest() {
    Matrix *rX_Roll = RotateAroundX_Roll(67.0);
    assert(1.0 == rX_Roll->matrix[0][0]);
    assert(0.0 == rX_Roll->matrix[0][1]);
    assert(0.0 == rX_Roll->matrix[0][2]);
    assert(0.0 == rX_Roll->matrix[1][0]);
    assert(cos(67.0) == rX_Roll->matrix[1][1]);
    assert((-1 * sin(67.0)) == rX_Roll->matrix[1][2]);
    assert(0.0 == rX_Roll->matrix[2][0]);
    assert(sin(67.0) == rX_Roll->matrix[2][1]);
    assert(cos(67.0) == rX_Roll->matrix[2][2]);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void RotateAroundY_PitchTest() {
    Matrix *rY_Pitch = RotateAroundY_Pitch(19.0);
    assert(cos(19.0) == rY_Pitch->matrix[0][0]);
    assert(0.0 == rY_Pitch->matrix[0][1]);
    assert(sin(19.0) == rY_Pitch->matrix[0][2]);
    assert(0.0 == rY_Pitch->matrix[1][0]);
    assert(1.0 == rY_Pitch->matrix[1][1]);
    assert(0.0 == rY_Pitch->matrix[1][2]);
    assert((-1 * sin(19.0)) == rY_Pitch->matrix[2][0]);
    assert(0.0 == rY_Pitch->matrix[2][1]);
    assert(cos(19.0) == rY_Pitch->matrix[2][2]);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void RotateAroundZ_YawTest() {
    Matrix *rZ_Yaw = RotateAroundZ_Yaw(23.0);
    assert(cos(23.0) == rZ_Yaw->matrix[0][0]);
    assert((-1 * sin(23.0)) == rZ_Yaw->matrix[0][1]);
    assert(0.0 == rZ_Yaw->matrix[0][2]);
    assert(sin(23.0) == rZ_Yaw->matrix[1][0]);
    assert(cos(23.0) == rZ_Yaw->matrix[1][1]);
    assert(0.0 == rZ_Yaw->matrix[1][2]);
    assert(0.0 == rZ_Yaw->matrix[2][0]);
    assert(0.0 == rZ_Yaw->matrix[2][1]);
    assert(1.0 == rZ_Yaw->matrix[2][2]);
}