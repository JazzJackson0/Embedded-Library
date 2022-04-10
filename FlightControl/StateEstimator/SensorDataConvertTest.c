#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "SensorDataConvert.h"

void Convert_GUnitToMps2Test();
void Convert_RpsToDpsTest();
void SensorReadingMpsUpdateTest();
void SensorReadingDpsUpdateTest();
void RotationAnglesInitTest();
void Get_AngularRotationsTest();

int main(int argc, char *argv[]) {

    Convert_GUnitToMps2Test();
    Convert_RpsToDpsTest();
    SensorReadingMpsUpdateTest();
    SensorReadingDpsUpdateTest();
    RotationAnglesInitTest();
    Get_AngularRotationsTest();
    return 0;
}

/**
 * @brief Tests Convert_GUnitToMps2Test ...
 * 
 * @return ** void 
 */
void Convert_GUnitToMps2Test() {

    Sensor_Reading *sens_readings = malloc(sizeof(Sensor_Reading));

    Convert_GUnitToMps2(sens_readings, 20.0, 50.0, 85.5);

    assert(20.0 / 0.10197162129779 == sens_readings->Ax_mps2);
    assert(50.0 / 0.10197162129779 == sens_readings->Ay_mps2);
    assert(85.5 / 0.10197162129779 == sens_readings->Az_mps2);
}

/**
 * @brief Tests Convert_RpsToDpsTest ...
 * 
 * @return ** void 
 */
void Convert_RpsToDpsTest() {

    Sensor_Reading *sens_readings = malloc(sizeof(Sensor_Reading));

    Convert_RpsToDps(sens_readings, 60.0, 70.0, 93.0);

    assert(60.0 / 0.017448352875489 == sens_readings->Gx_dps);
    assert(70.0 / 0.017448352875489 == sens_readings->Gy_dps);
    assert(93.0 / 0.017448352875489 == sens_readings->Gz_dps);
}

void SensorReadingMpsUpdateTest() {
    
    Sensor_Reading *reading = malloc(sizeof(Sensor_Reading));
    SensorReadingMpsUpdate(reading, 1.0, 2.0, 3.0);

    assert(1.0 == reading->Ax_mps2);
    assert(2.0 == reading->Ay_mps2);
    assert(3.0 == reading->Az_mps2);
}

void SensorReadingDpsUpdateTest() {
    
    Sensor_Reading *reading = malloc(sizeof(Sensor_Reading));
    SensorReadingDpsUpdate(reading, 4.0, 5.0, 6.0);

    assert(4.0 == reading->Gx_dps);
    assert(5.0 == reading->Gy_dps);
    assert(6.0 == reading->Gz_dps);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void RotationAnglesInitTest() {

    RotationAngles *rotAngles = RotationAnglesInit();

    assert(0.0 == rotAngles->Angle_Ax);
    assert(0.0 == rotAngles->Angle_Ay);
    assert(0.0 == rotAngles->Angle_Az);
    assert(0.0 == rotAngles->Angle_Gx);
    assert(0.0 == rotAngles->Angle_Gy);
    assert(0.0 == rotAngles->Angle_Gz);

}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Get_AngularRotationsTest() {
    
    RotationAngles *rotAngles = RotationAnglesInit();
    Sensor_Reading *Readings = malloc(sizeof(Sensor_Reading));
    SensorReadingMpsUpdate(Readings, 1.0, 2.0, 3.0);
    SensorReadingDpsUpdate(Readings, 2.0, 3.0, 4.0);

    Get_AngularRotations(rotAngles, Readings, (float)2.0);

    assert(_180_DIV_PI * atan( 1.0/ sqrt( (2.0 * 2.0) + (3.0 * 3.0) ) ) == rotAngles->Angle_Ax);
    assert(_180_DIV_PI * atan( 2.0/ sqrt( (1.0 * 1.0) + (3.0 * 3.0) ) ) == rotAngles->Angle_Ay);
    assert(_180_DIV_PI * atan( sqrt( (1.0 * 1.0) + (2.0 * 2.0) ) / 3.0 ) == rotAngles->Angle_Az);

    assert(4.0 == rotAngles->Angle_Gx);
    assert(6.0 == rotAngles->Angle_Gy);
    assert(8.0 == rotAngles->Angle_Gz);
}