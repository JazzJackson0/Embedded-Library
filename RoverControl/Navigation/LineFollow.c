#include "LineFollow.h"

// Never been tested, just wrote this up in like 10 min.

const float FORWARD_SPEED = 100;
const float TURN_SPEED = 60;
//const float REVERSE_SPEED = 60;

void LineFollow() {

    DigitalSensor *LeftLightSensor = SensorInit('A', 1);
    DigitalSensor *RightLightSensor = SensorInit('A', 2);
    DiffDriveInit();

    // While both sensors are not detecting black simultaneously
    while (!(!LeftLightSensor && !RightLightSensor)) {

        // If Left Sensor detects black
        if (!LeftLightSensor) {
            LeftTurn(TURN_SPEED);
        }

        // If Right Sensor detects black
        else if (!RightLightSensor) {
            RightTurn(TURN_SPEED);
        }

        // If neither sensor detects black
        else if (LeftLightSensor && RightLightSensor) {

            Forward(FORWARD_SPEED);
        }
    }

    StopBot();
}


/*
 * 			TO-DO
 * 			-----
 *  - Test Code
 *
 *  - Maybe write a version/function that uses PID?
 *  
 *  - 
 *  */