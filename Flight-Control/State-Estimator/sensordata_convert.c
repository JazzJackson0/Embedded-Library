#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "sensordata_convert.h"

void Convert_GUnitToMps2(Sensor_Reading* sensReadings, double x, double y, double z) {

	//1 (m/s)^2 = 0.10197162129779 g-unit (G-force).
	sensReadings->Ax_mps2 = x / 0.10197162129779;
	sensReadings->Ay_mps2 = y / 0.10197162129779;
	sensReadings->Az_mps2 = z / 0.10197162129779;
}

void Convert_RpsToDps(Sensor_Reading* sensReadings, double x, double y, double z) {

	//1 dps is equal to 0.017448352875489 rps = radians per sec?????? 
	//???SHOHULD BE REVOLUTIONS/ROTATIONS PER SEC (AKA: HZ)
	sensReadings->Gx_dps = x / 0.017448352875489;
	sensReadings->Gy_dps = y / 0.017448352875489;
	sensReadings->Gz_dps = z / 0.017448352875489;
}

void SensorReadingMpsUpdate(Sensor_Reading *Readings, double Ax, double Ay, double Az) {
	
    Readings->Ax_mps2 = Ax;
    Readings->Ay_mps2 = Ay;
    Readings->Az_mps2 = Az;
}

void SensorReadingDpsUpdate(Sensor_Reading *Readings, double Gx, double Gy, double Gz) {

    Readings->Gx_dps = Gx;
    Readings->Gy_dps = Gy;
    Readings->Gz_dps = Gz;
}

RotationAngles* RotationAnglesInit(void) {
	RotationAngles *rotations = malloc(sizeof(RotationAngles));
	rotations->Angle_Ax = 0.0;
	rotations->Angle_Ay = 0.0;
	rotations->Angle_Az = 0.0;
	rotations->Angle_Gx = 0.0;
	rotations->Angle_Gy = 0.0;
	rotations->Angle_Gz = 0.0;

	return rotations;
}


void Get_AngularRotations(RotationAngles *rotations, Sensor_Reading *readings, 
	float sample_period) {
	
	rotations->Angle_Ax = _180_DIV_PI * atan( readings->Ax_mps2 / 
		( sqrt( (readings->Ay_mps2 * readings->Ay_mps2) + (readings->Az_mps2 * readings->Az_mps2) ) ) );
	
	rotations->Angle_Ay = _180_DIV_PI * atan( readings->Ay_mps2 / 
		( sqrt( (readings->Ax_mps2 * readings->Ax_mps2) + (readings->Az_mps2 * readings->Az_mps2) ) ) );
	
	rotations->Angle_Az = _180_DIV_PI * atan( sqrt( (readings->Ax_mps2 * readings->Ax_mps2) + 
		(readings->Ay_mps2 * readings->Ay_mps2) ) / readings->Az_mps2 );

	rotations->Angle_Gx += readings->Gx_dps * sample_period;
	rotations->Angle_Gy += readings->Gy_dps * sample_period;
	rotations->Angle_Gz += readings->Gz_dps * sample_period;

}

/*
 * 			TO-DO
 * 			-----
 *  - 
 *
 *  - 
 *  
 *  - 
 *  */


