#ifndef SENSORDATA_CONVERT_H
#define SENSORDATA_CONVERT_H
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

typedef struct _sens Sensor_Reading;
typedef struct r_angles RotationAngles;

//DECLARATIONS
/**
 * @brief Convert Accelerometer readings from G-Force Units to mps^2
 * 
 * 
 * @param sensReadings Converted mps^2 values are placed in this struct
 * @param x x-direction g-unit reading
 * @param y y-direction g-unit reading
 * @param z z-direction g-unit reading
 * @return ** void 
 */
void Convert_GUnitToMps2(Sensor_Reading* sensReadings, double x, double y, double z);

/**
 * @brief Convert Gyroscope readings from rotations-per-sec to degrees-per-sec
 * 
 * @param sensReadings Converted dps values are placed in this struct
 * @param x x-angle rps reading
 * @param y y-angle rps reading
 * @param z z-angle rps reading
 * @return ** void 
 */
void Convert_RpsToDps(Sensor_Reading* sensReadings, double x, double y, double z);

/**
 * @brief Updates a Sensor_Reading struct with new mps^2 data.
 * 			Can be used if data is in mps^2 units and so does not need
 * 			to be converted.
 * 
 * @param Readings This struct is updated with the new msp^2 data
 * @param Ax New x-direction mps^2 data
 * @param Ay New y-direction mps^2 data
 * @param Az New z-direction mps^2 data
 * @return ** void 
 */
void SensorReadingMpsUpdate(Sensor_Reading *Readings, double Ax, double Ay, double Az);

/**
 * @brief Updates a Sensor_Reading struct with new dps data.
 * 			Can be used if data is in dps units and so does not need
 * 			to be converted.
 * 
 * @param Readings This struct is updated with the new dps data
 * @param Gx New x-angle dps data
 * @param Gy New y-angle dps data
 * @param Gz New z-angle dps data
 * @return ** void 
 */
void SensorReadingDpsUpdate(Sensor_Reading *Readings, double Gx, double Gy, double Gz);

/**
 * @brief Returns a zero-initialized RotationAngles struct
 * 
 * @return ** RotationAngles* Zero-initialized RotationAngles struct
 */
RotationAngles* RotationAnglesInit(void);

/**
 * @brief Converts the mps^2 & dps units to rotation angles.
 * 
 * @param rotations Converted rotation angles are placed in this struct
 * @param readings Sensor Reading struct holding the mps^2 and dps data
 * @param sample_period Time between each new sensor reading/conversion to rotation angles
 * @return ** void
 */
void Get_AngularRotations(RotationAngles *rotations, Sensor_Reading *readings, 
	float sample_period);

//Structs
/**
 * @brief Sensor reading in mps^2 and dps
 * 
 */
struct _sens{
	double Ax_mps2;
	double Ay_mps2;
	double Az_mps2;

	double Gx_dps;
	double Gy_dps;
	double Gz_dps;	
};

/**
 * @brief |||  Ax - Az: Rotation angles obtained from acceleration
 *		|||  Gx - Gz: Rotation angles obtained from angular velocity
 */
struct r_angles{
	double Angle_Ax;
	double Angle_Ay;
	double Angle_Az;
	
	double Angle_Gx;
	double Angle_Gy;
	double Angle_Gz;
};

#define _180_DIV_PI 57.2958

#endif