#ifndef SENSORDATA_CONVERT_H
#define SENSORDATA_CONVERT_H

typedef struct _sens Sensor_Reading;
typedef struct r_angles RotationAngles;

//DECLARATIONS
/**
 * @brief Updates a Sensor_Reading struct with 
 * 			data converted from G-Force Units to mps^2
 * 
 * 
 * @param sensReadings 
 * @param x 
 * @param y 
 * @param z 
 * @return ** void 
 */
void Convert_GUnitToMps2(Sensor_Reading* sensReadings, double x, double y, double z);

/**
 * @brief Updates a Sensor_Reading struct with 
 * 			data converted from rotations-per-sec to degrees-per-sec
 * 
 * @param sensReadings 
 * @param x 
 * @param y 
 * @param z 
 * @return ** void 
 */
void Convert_RpsToDps(Sensor_Reading* sensReadings, double x, double y, double z);

/**
 * @brief Updates a Sensor_Reading struct with mps^2 data.
 * 			Can be used if data is in mps^2 units and so does not need
 * 			to be converted.
 * 
 * @param Readings 
 * @param Ax 
 * @param Ay 
 * @param Az 
 * @return ** void 
 */
void SensorReadingMpsUpdate(Sensor_Reading *Readings, double Ax, double Ay, double Az);

/**
 * @brief Updates a Sensor_Reading struct with dps data.
 * 			Can be used if data is in dps units and so does not need
 * 			to be converted.
 * 
 * @param Readings 
 * @param Gx 
 * @param Gy 
 * @param Gz 
 * @return ** void 
 */
void SensorReadingDpsUpdate(Sensor_Reading *Readings, double Gx, double Gy, double Gz);

/**
 * @brief Returns a zero-initialized RotationAngles struct
 * 
 * @return ** RotationAngles* 
 */
RotationAngles* RotationAnglesInit(void);

/**
 * @brief Converts the msp^2 and dsp units to rotation angles.
 * 
 * @param rotations
 * @param readings 
 * @param sample_period 
 * @return ** void
 */
void Get_AngularRotations(RotationAngles *rotations, Sensor_Reading *readings, 
	float sample_period);

//Structs
struct _sens{
	double Ax_mps2;
	double Ay_mps2;
	double Az_mps2;

	double Gx_dps;
	double Gy_dps;
	double Gz_dps;	
};

/*
Ax - Az: Rotation angles obtained from acceleration
Gx - Gz: Rotation angles obtained from angular velocity
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