#include <assert.h>
#include "Odometry2Wheel.h"

// Not yet Tested

void OdometryInitTest();
void Get_PoseTest();


int main() {

    OdometryInitTest();
    Get_PoseTest();
    return 0;
}

/**
 * @brief Testing OdometryInit(). Checking that Robot Odometry model is properly initialized.
 * 
 * @return ** void 
 */
void OdometryInitTest() {
    RobotOdom* rOdom = OdometryInit(0.20);

    assert((float)0.20 == rOdom->trackwidth);
    assert((float)0.10 == rOdom->r_center);
    assert((float)0.0 == rOdom->x);
    assert((float)0.0 == rOdom->y);
    assert((float)0.0 == rOdom->orientation);

}

/**
 * @brief Testing Get_Pose(). Checking that odometry calculations are correct.
 * 
 * @return ** void 
 */
void Get_PoseTest() {

    RobotOdom* rOdom = OdometryInit(0.20);
    Get_Pose(rOdom, 0.05, 0.05);

    assert((float)0.0 == rOdom->x);
    assert((float)0.0 == rOdom->y);
    assert((float)0.0 == rOdom->orientation);
}



