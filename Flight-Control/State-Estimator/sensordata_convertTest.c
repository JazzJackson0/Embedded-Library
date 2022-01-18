#include <assert.h>
#include <stdlib.h>
#include "sensordata_convert.h"

void Get_ReadingTest_ConversionsNeeded();
void Get_ReadingTest_NoConversionsNeeded();
void Get_AngularRotationsTest();
double *reading;

int main(int argc, char *argv[]) {

    Get_ReadingTest_ConversionsNeeded();
    Get_ReadingTest_NoConversionsNeeded();
    Get_AngularRotationsTest();
    return 0;
}

/**
 * @brief Tests Get_Reading when neither accelerometer nor gyroscope
 *          units match the desired output unit types (mps^2 and dps).
 * 
 * @return ** void 
 */
void Get_ReadingTest_ConversionsNeeded() {

    //Accel
    reading[0] = 0.0;
    reading[1] = 0.0;
    reading[2] = 0.0;
    //Gyro
    reading[3] = 0.0;
    reading[4] = 0.0;
    reading[5] = 0.0;

    assert(0.0 == Get_Reading("G-UNIT", "RPS", reading)->Ax_mps2);
    assert(0.0 == Get_Reading("G-UNIT", "RPS", reading)->Ay_mps2);
    assert(0.0 == Get_Reading("G-UNIT", "RPS", reading)->Ax_mps2);

    assert(0.0 == Get_Reading("G-UNIT", "RPS", reading)->Gx_dps);
    assert(0.0 == Get_Reading("G-UNIT", "RPS", reading)->Gy_dps);
    assert(0.0 == Get_Reading("G-UNIT", "RPS", reading)->Gx_dps);
}

/**
 * @brief Tests Get_Reading when both accelerometer and gyroscope
 *          units match the desired output unit types (mps^2 and dps).
 * 
 * @return ** void 
 */
void Get_ReadingTest_NoConversionsNeeded() {

    //Accel
    reading[0] = 0.0;
    reading[1] = 0.0;
    reading[2] = 0.0;
    //Gyro
    reading[3] = 0.0;
    reading[4] = 0.0;
    reading[5] = 0.0;

    assert(0.0 == Get_Reading("MPS2", "DPS", reading)->Ax_mps2);
    assert(0.0 == Get_Reading("MPS2", "DPS", reading)->Ay_mps2);
    assert(0.0 == Get_Reading("MPS2", "DPS", reading)->Ax_mps2);

    assert(0.0 == Get_Reading("MPS2", "DPS", reading)->Gx_dps);
    assert(0.0 == Get_Reading("MPS2", "DPS", reading)->Gy_dps);
    assert(0.0 == Get_Reading("MPS2", "DPS", reading)->Gx_dps);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Get_AngularRotationsTest() {
    
    IMU_Data imu;
    imu.Ax_mps2 = 0.0;
    imu.Ay_mps2 = 0.0;
    imu.Ax_mps2 = 0.0;
    imu.Gx_dps = 0.0;
    imu.Gy_dps = 0.0;
    imu.Gx_dps = 0.0;

    assert(0.0 == Get_AngularRotations(&imu, 1.0)->Angle_Ax);
    assert(0.0 == Get_AngularRotations(&imu, 1.0)->Angle_Ay);
    assert(0.0 == Get_AngularRotations(&imu, 1.0)->Angle_Az);

    assert(0.0 == Get_AngularRotations(&imu, 1.0)->Angle_Gx);
    assert(0.0 == Get_AngularRotations(&imu, 1.0)->Angle_Gy);
    assert(0.0 == Get_AngularRotations(&imu, 1.0)->Angle_Gz);
}