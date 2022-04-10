// Driver for a generic digital sensor
#include "DigitalSensorDriver.h"


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