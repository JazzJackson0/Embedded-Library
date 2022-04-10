#include "DifferentialMove.h"

Motor *LeftMotor;
Motor *RightMotor;

void DiffDriveInit() {

    LeftMotor = Motor_Init('A', 1, 'A', 2);
    RightMotor = Motor_Init('B', 1, 'B', 2);
}

void Forward(float speed) {

    Update_Motor(LeftMotor, FORWARD, speed);
    Update_Motor(RightMotor, FORWARD, speed);
}

void Reverse(float speed) {

    Update_Motor(LeftMotor, REVERSE, speed);
    Update_Motor(RightMotor, REVERSE, speed);
}

void RightTurn(float speed) {

    Update_Motor(LeftMotor, FORWARD, speed);
    Update_Motor(RightMotor, REVERSE, speed);
}

void LeftTurn(float speed) {

    Update_Motor(LeftMotor, REVERSE, speed);
    Update_Motor(RightMotor, FORWARD, speed);
}

void StopBot() {

    //
}


/*
 * 			TO-DO
 * 			-----
 *  - Test Code
 *
 *  - Create a Stop function
 *  
 *  - 
 *  */
