//ATmega328/P Driver
#ifndef IO_PORTS_H_
#define IO_PORTS_H_

#include <stdint.h>

typedef enum _PinDirection E_PinDirection;

//DECLARATIONS
/**
 * @brief 
 * 
 * @param port 
 * @param pinNum 
 * @param direction 
 * @return ** void 
 */
void Pin_Init(char port, uint8_t pinNum, E_PinDirection direction);
/**
 * @brief 
 * 
 * @param port 
 * @param pinNum 
 * @return ** uint8_t 
 */
uint8_t Pin_GetInput(char port, uint8_t pinNum);
/**
 * @brief 
 * 
 * @param port 
 * @param pinNum 
 * @param pinState 
 * @return ** void 
 */
void Pin_Out(char port, uint8_t pinNum, E_PinDirection pinState);
/**
 * @brief 
 * 
 * @param port 
 * @param pinNum 
 * @return ** void 
 */
void Pin_Toggle(char port, uint8_t pinNum);

//IO_PORTS (Powered by AVR Clock Control Unit)
typedef struct _port PORTx;
#define ATMEGA_BASEADDRESS 0x0000
#define ADDR_MCU_CONTROL_PORTS ( (MCU_CONTROL_PORTS*) ((ATMEGA_BASEADDRESS) + 0x35) )
#define ADDR_PORTB ( (PORTx*) ((ATMEGA_BASEADDRESS) + 0x03) )
#define ADDR_PORTC ( (PORTx*) ((ATMEGA_BASEADDRESS) + 0x06) )
#define ADDR_PORTD ( (PORTx*) ((ATMEGA_BASEADDRESS) + 0x09) )


//Enums----------------------------------------------------------------------
enum _PinDirection {
	IN = 0, OUT = 1
};

//Registers------------------------------------------------------------------
typedef struct {
	volatile uint8_t enable_InterruptVectorChange:1;
	volatile uint8_t interruptVectorChange:1;
	const uint8_t reserved0:2;
	volatile uint8_t disable_PullUps:1;
	volatile uint8_t enable_BrownOutDetectionSleep:1;
	volatile uint8_t start_BrownOutDetectionSleep:1;
	const uint8_t reserved1:1;
}MCU_CONTROL_PORTS;

typedef struct {
	volatile uint8_t p0_readData_writeData:1;
	volatile uint8_t p1_readData_writeData:1;
	volatile uint8_t p2_readData_writeData:1;
	volatile uint8_t p3_readData_writeData:1;
	volatile uint8_t p4_readData_writeData:1;
	volatile uint8_t p5_readData_writeData:1;
	volatile uint8_t p6_readData_writeData:1;
	volatile uint8_t p7_readData_writeData:1; // Not available for port C
}PORT_DATA;

typedef struct {
	volatile uint8_t pin0Input0_pin0Output1:1;
	volatile uint8_t pin1Input0_pin1Output1:1;
	volatile uint8_t pin2Input0_pin2Output1:1;
	volatile uint8_t pin3Input0_pin3Output1:1;
	volatile uint8_t pin4Input0_pin4Output1:1;
	volatile uint8_t pin5Input0_pin5Output1:1;
	volatile uint8_t pin6Input0_pin6Output1:1;
	volatile uint8_t pin7Input0_pin7Output1:1; // Not available for port C
}PORT_DIRECTION;

typedef struct {
	volatile uint8_t pin0_Toggle:1;
	volatile uint8_t pin1_Toggle:1;
	volatile uint8_t pin2_Toggle:1;
	volatile uint8_t pin3_Toggle:1;
	volatile uint8_t pin4_Toggle:1;
	volatile uint8_t pin5_Toggle:1;
	volatile uint8_t pin6_Toggle:1;
	volatile uint8_t pin7_Toggle:1; // Not available for port C
}PORT_TOGGLE;


struct _port {
	PORT_TOGGLE ToggleReg; // Port B: 0x03 | Port C: 0x06 | Port D: 0x09 
	PORT_DIRECTION DirectionReg; // Port B: 0x04 | Port C: 0x07 | Port D: 0x0A 
	PORT_DATA DataReg; // Port B: 0x05 | Port C: 0x08 | Port D: 0x0B 	
};

#endif
