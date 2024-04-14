#ifndef MOTOR_H
#define MOTOR_H
#include <stdint.h>
#include <stdlib.h>
#include "../STM32F407/Drivers/STM32F407.GPIO.h"
#include "../STM32F407/Drivers/STM32F407.TimerGeneral2_5.h"
//#include "../MSP430/Drivers/MSP430FR.DigitalIO.h"
//#include "../MSP430/Drivers/MSP430FR.Timer.h"
//#include "../ATmega328P/Drivers/ATmega328.IOPorts.h"
//#include "../ATmega328P/Drivers/ATmega328.TimerCounter.h"


typedef struct motor Motor;
typedef enum motor_dir MotorDirection;

// DECLARATIONS
/**
 * @brief Initialize Motor Hardware Settings. (Architecture Specific 
 *  settings can be altered within source code)
 *
 * @param directionPort1 Port of 1st Direction Pin
 * @param directionPin1 Pin Number of 1st Direction Pin
 * @param directionPort2 Port of 2nd Direction Pin
 * @param directionPin2 Pin Number of 2nd Direction Pin
 * @return ** Motor* - Motor to be set
 */
Motor* Motor_Init(char directionPort1, int directionPin1, 
    char directionPort2, int directionPin2);


/**
 * @brief Deinitialize motor
 * 
 * @param motor 
 */
void Motor_DeInit(Motor* motor);

/**
 * @brief 
 * 
 * @param motor 
 * @param direction 
 * @param speed Sets speed of motor (Range (In Percent): 1 - 100)
 * @return ** void 
 */
void Update_Motor(Motor *motor, MotorDirection direction, float speed);


// Enums
enum motor_dir { FORWARD, REVERSE };


// Structs
struct motor{

    // Motor Direction Pins
    char DirectionPort1;
    int DirectionPin1;
    char DirectionPort2;
    int DirectionPin2;

    // Motor Direction Change
    void (*pinOut)(char, uint8_t, uint8_t);

    // PWM: Motor Speed Timer
    uint8_t timerIDNum; // For STM32 & ATMega328
    char* timerIDChar; // For MSP430

    // STM32 Functions
    void (*pinInit)(char, uint8_t, E_PinModes);
    void (*pwmStart)(uint8_t, uint8_t, uint16_t, uint16_t, float);
    void (*pwmUpdate)(uint8_t, uint8_t, uint16_t, float);

    /*
    // MSP430 Functions
    void (*pinInit)(char, uint8_t, E_PinType, E_FunctionType, E_PullUpDown);
    void (*pwmStart)(char*, E_TimerPrescaler, uint32_t, float);
    void (*pwmUpdate)(char*, uint32_t, float);
    */

   /*
    //ATMega328 Functions
    void (*pinInit)(char, uint8_t, E_PinDirection);
    void (*pwmStart)(uint8_t, E_ClockSpeed, uint16_t, float);
    void (*pwmUpdate)(uint8_t, uint16_t, float);
    */
};



#endif