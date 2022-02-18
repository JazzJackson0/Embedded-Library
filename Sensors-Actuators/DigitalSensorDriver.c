// Driver for a generic digital sensor
#include "DigitalSensorDriver.h"
#include <stdint.h>
#include <stdlib.h>
#include "../STM32F407/Drivers/STM32F407.GPIO.h"
#include "../STM32F407/Drivers/STM32F407.TimerGeneral2_5.h"
//#include "../MSP430/Drivers/MSP430FR.DigitalIO.h"
//#include "../MSP430/Drivers/MSP430FR.Timer.h"
//#include "../ATmega328P/Drivers/ATmega328.IOPorts.h"
//#include "../ATmega328P/Drivers/ATmega328.TimerCounter.h"

DigitalSensor* SensorInit(char port, uint8_t pinNum) {
    
    DigitalSensor* DSensor = malloc(sizeof(DigitalSensor));
    DSensor->port = port;
    DSensor->pinNum = pinNum;
    
    DSensor->pinInit = &Pin_Init;
    DSensor->pinIn = &Pin_GetInput;

    DSensor->pinInit(port, pinNum, IN); // STM32 Or ATMega328 Version
    //DSensor->pinInit(port, pinNum, IN, NO_F, NO_PULL); // MSP430 Version

    return DSensor;
}

uint8_t Get_SensorState(DigitalSensor *DSensor) {

    return DSensor->pinIn(DSensor->port, DSensor->pinNum);
}