#include "euler_angles.h"
#include <math.h>

// Add 180 / pi

EulerAngle* RotMat_to_EulerAngles(double one, double two, double three) {

    EulerAngle *euler;
    double rollDenom = cos(one) * sin(two);
    double yawDenom = cos(three) * sin(two);

    //Keep Denominators positive
    if (rollDenom < 0) { rollDenom *= -1; } 
    if (yawDenom < 0) { yawDenom *= -1; }

    // convert to degrees????????????
    euler->Roll = atan( ( sin(one) * sin(two) ) / ( rollDenom ) ); 
    euler->Pitch = atan( sqrt( 1 - ( cos(two) * cos(two) ) ) / cos(two) );
    euler->Yaw = atan( ( sin(two) * sin(three) ) / ( yawDenom ) );

    return euler;
}


EulerAngle* RotMat_to_TaitBryanAngles(double one, double two, double three) {

    EulerAngle *euler;
    double rollNumerator = cos(two) * sin(one);
    double pitchNumerator = sin(two);
    double yawNumerator = cos(two) * sin(three);

    //Keep Numerators positive
    if (rollNumerator < 0) { rollNumerator *= -1; } 
    if (pitchNumerator < 0) { pitchNumerator *= -1; } 
    if (yawNumerator < 0) { yawNumerator *= -1; }

    // convert to degrees????????????
    euler->Roll = atan( rollNumerator / ( cos(one) * cos(two) ) ); 
    euler->Pitch = atan( pitchNumerator / sqrt( 1 - ( sin(two) * sin(two) ) ) );
    euler->Yaw = atan( yawNumerator / ( cos(two) * cos(three) ) );

    return euler;
}


/*
 * 			TO-DO
 * 			-----
 *  - Convert Radians to Degrees?
 *
 *  - Test Code
 *  
 *  - 
 *  */