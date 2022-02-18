#include <stdint.h>
#include "../STM32F407/Drivers/gpio_STM32F407.h"
#include "../STM32F407/Drivers/timerGeneral2_5_STM32F407.h"
//#include "../MSP430/Drivers/digital_io_MSP430FR.h"
//#include "../MSP430/Drivers/timer_MSP430FR.h"
//#include "../ATmega328P/Drivers/io_ports_ATmega328.h"
//#include "../ATmega328P/Drivers/timer_counter_ATmega328.h"

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