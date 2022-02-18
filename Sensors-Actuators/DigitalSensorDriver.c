// Driver for a generic digital sensor
#include "DigitalSensorDriver.h"
#include <stdint.h>
#include <stdlib.h>
#include "../STM32F407/Drivers/gpio_STM32F407.h"
#include "../STM32F407/Drivers/timerGeneral2_5_STM32F407.h"
//#include "../MSP430/Drivers/digital_io_MSP430FR.h"
//#include "../MSP430/Drivers/timer_MSP430FR.h"
//#include "../ATmega328P/Drivers/io_ports_ATmega328.h"
//#include "../ATmega328P/Drivers/timer_counter_ATmega328.h"

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