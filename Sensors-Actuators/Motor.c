#include <stdint.h>
#include <stdlib.h>
#include "Motor.h"
#include "../STM32F407/Drivers/gpio_STM32F407.h"
#include "../STM32F407/Drivers/timerGeneral2_5_STM32F407.h"
//#include "../MSP430/Drivers/digital_io_MSP430FR.h"
//#include "../MSP430/Drivers/timer_MSP430FR.h"
//#include "../ATmega328P/Drivers/io_ports_ATmega328.h"
//#include "../ATmega328P/Drivers/timer_counter_ATmega328.h"


Motor* Motor_Init(char directionPort1, int directionPin1, 
    char directionPort2, int directionPin2) {

    Motor* motor = malloc(sizeof(Motor));
    motor->DirectionPort1 = directionPort1;
    motor->DirectionPort2 = directionPort2;
    motor->DirectionPin1 = directionPin1;
    motor->DirectionPin2 = directionPin2;

   // Initialize Functions -----------------------------------------------
    motor->pinInit = &Pin_Init;
    motor->pinOut = &Pin_Out;
    
    //STM32 Functions
    motor->pwmStart = &GeneralTimer2_5_PWM_Start;
    motor->pwmUpdate = &GeneralTimer2_5_PWM_Update;

    /*
    //MSP430 OR ATMega328 Functions
    motor->pwmStart = &PWM_Start;
    motor->pwmUpdate = &PWM_Update;
    */

   // Initialize Pins ----------------------------------------------------
    // STM32 Version OR ATMega Version
    motor->pinInit(motor->DirectionPort1, motor->DirectionPin1, OUT); 
    motor->pinInit(motor->DirectionPort2, motor->DirectionPin2, OUT);

    /*
    // MSP430 Version
    motor->pinInit(motor->DirectionPort1, motor->DirectionPin1, OUT, NO_F, NO_PULL);
    motor->pinInit(motor->DirectionPort2, motor->DirectionPin2, OUT, NO_F, NO_PULL);
    */

   return motor;
}



void Update_Motor(Motor *motor, MotorDirection direction, float speed) {

    if (direction == FORWARD) {
        motor->pinOut(motor->DirectionPort1, motor->DirectionPin1, 1);
        motor->pinOut(motor->DirectionPort1, motor->DirectionPin2, 0);
    }

    else if (direction == REVERSE) {
        motor->pinOut(motor->DirectionPort1, motor->DirectionPin1, 0);
        motor->pinOut(motor->DirectionPort1, motor->DirectionPin2, 1);
    }

    motor->pwmStart(motor->timerID, 1, 16000, 1000, speed); // STM32 Version
    //motor->pwmStart(motor->timerID, DIV_1, 1000, speed); // MSP430 Version
    //motor->pwmStart(motor->timerID, _DIV_8, 1000, speed); // ATMega328 Version
}

/*
 * 			TO-DO
 * 			-----
 *  - Test Code
 *
 *  - Figure out a way to set timer ID.
 *  
 *  - 
 *  */