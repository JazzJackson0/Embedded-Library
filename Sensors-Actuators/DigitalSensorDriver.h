#include <stdint.h>
#include <stdlib.h>
#include "../STM32F407/Drivers/STM32F407.GPIO.h"
#include "../STM32F407/Drivers/STM32F407.TimerGeneral2_5.h"
//#include "../MSP430/Drivers/MSP430FR.DigitalIO.h"
//#include "../MSP430/Drivers/MSP430FR.Timer.h"
//#include "../ATmega328P/Drivers/ATmega328.IOPorts.h"
//#include "../ATmega328P/Drivers/ATmega328.TimerCounter.h"

typedef struct d_sensor DigitalSensor;

// DECLARATIONS
/**
 * @brief Initialize Digital Sensor
 * 
 * @param port Port the sensor connects to.
 * @param pinNum Pin the sensor connects to.
 * @return ** DigitalSensor* - Initialized Digital Sensor
 */
DigitalSensor* SensorInit(char port, uint8_t pinNum);

/**
 * @brief DeInitialize Digital Sensor
 * 
 * @param DSensor Sensor object
 */
void SensorDeInit(DigitalSensor *DSensor);

/**
 * @brief Get state of Digital Sensor
 * 
 * @param DSensor Sensor to obtain state from
 * @return ** uint8_t - HIGH = 1, LOW = 0
 */
uint8_t Get_SensorState(DigitalSensor *DSensor);


// Struct
struct d_sensor {
    
    char port;
    uint8_t pinNum;
    
    uint8_t (*pinIn)(char, uint8_t);

    // Pin Init Functions (Architecture Specific)
    void (*pinInit)(char, uint8_t, E_PinModes); // STM32 Version
    //void (*pinInit)(char, uint8_t, E_PinType, E_FunctionType, E_PullUpDown); // MSP430 Version
    //void (*pinInit)(char, uint8_t, E_PinDirection); // ATMega328 Version
};