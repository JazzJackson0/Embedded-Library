#ifndef ODOMETRY_2WHEEL_H
#define ODOMETRY_2WHEEL_H

typedef struct odom RobotOdom;

// DECLARATIONS
/**
 * @brief Initialize an Odometry struct with an (x, y) position and orientation of 0 (degrees).
 *          Stores the trackwidth of the robot wheels.
 *          Calculates and stores the midplane of the robot (r_center). 
            Returns a struct to represent a given robot's odometry information.
 * 
 * @param trackwidth Distance between the midplane of the right and left wheels (meters)
 * @return ** RobotOdom* 
 */
RobotOdom* OdometryInit(float trackwidth);

/**
 * @brief Takes information on distance travelled by each wheel.
 *          Updates a robot's odometry information with the provided info.
 * 
 * @param r_odom Robot's current odometry state to be updated.
 * @param left_dist Distance travelled by left wheel (meters).
 * @param right_dist Distance travelled by right wheel (meters).
 * @return ** void 
 */
void Get_Pose(RobotOdom* r_odom, float left_dist, float right_dist);



// Structs
struct odom {
    float x;
    float y;
    float orientation; // Degrees

    // Physical Specs on robot
    float trackwidth; // (meters)
    float r_center; // Midplane of Robot
};







#endif