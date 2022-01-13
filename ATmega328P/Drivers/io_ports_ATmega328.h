//ATmega328/P Driver
#ifndef IO_PORTS_H_
#define IO_PORTS_H_

#include <stdint.h>

typedef enum _PinDirection E_PinDirection;

//DECLARATIONS
void Pin_Init(char port, uint8_t pinNum, E_PinDirection direction);
uint8_t Pin_GetInput(char port, uint8_t pinNum);
void Pin_Out(char port, uint8_t pinNum, E_PinDirection pinState);
void Pin_Toggle(char port, uint8_t pinNum);

//IO_PORTS (Powered by AVR Clock Control Unit)
typedef struct _port PORTx;
#define ATMEGA_BASEADDRESS 0x0000
#define ADDR_MCU_CONTROL_PORTS ( (MCU_CONTROL_PORTS*) ((ATMEGA_BASEADDRESS) + 0x35) )
#define ADDR_PORTS ( (PORTx*) ((ATMEGA_BASEADDRESS) + 0x00) )


//Enums----------------------------------------------------------------------
enum _PinDirection {
	IN = 0,
	OUT = 1
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
	volatile uint8_t p7_readData_writeData:1;
}PORT_B_D_DATA;

typedef struct {
	volatile uint8_t pin0Input0_pin0Output1:1;
	volatile uint8_t pin1Input0_pin1Output1:1;
	volatile uint8_t pin2Input0_pin2Output1:1;
	volatile uint8_t pin3Input0_pin3Output1:1;
	volatile uint8_t pin4Input0_pin4Output1:1;
	volatile uint8_t pin5Input0_pin5Output1:1;
	volatile uint8_t pin6Input0_pin6Output1:1;
	volatile uint8_t pin7Input0_pin7Output1:1;
}PORT_B_D_DIRECTION;

typedef struct {
	volatile uint8_t pin0_Toggle:1;
	volatile uint8_t pin1_Toggle:1;
	volatile uint8_t pin2_Toggle:1;
	volatile uint8_t pin3_Toggle:1;
	volatile uint8_t pin4_Toggle:1;
	volatile uint8_t pin5_Toggle:1;
	volatile uint8_t pin6_Toggle:1;
	volatile uint8_t pin7_Toggle:1;
}PORT_B_D_TOGGLE;

typedef struct {
	volatile uint8_t p0_readData_writeData:1;
	volatile uint8_t p1_readData_writeData:1;
	volatile uint8_t p2_readData_writeData:1;
	volatile uint8_t p3_readData_writeData:1;
	volatile uint8_t p4_readData_writeData:1;
	volatile uint8_t p5_readData_writeData:1;
	volatile uint8_t p6_readData_writeData:1;
	const uint8_t reserved:1;
}PORT_C_DATA;

typedef struct {
	volatile uint8_t pin0Input0_pin0Output1:1;
	volatile uint8_t pin1Input0_pin1Output1:1;
	volatile uint8_t pin2Input0_pin2Output1:1;
	volatile uint8_t pin3Input0_pin3Output1:1;
	volatile uint8_t pin4Input0_pin4Output1:1;
	volatile uint8_t pin5Input0_pin5Output1:1;
	volatile uint8_t pin6Input0_pin6Output1:1;
	const uint8_t reserved:1;
}PORT_C_DIRECTION;

typedef struct {
	volatile uint8_t pin0_Toggle:1;
	volatile uint8_t pin1_Toggle:1;
	volatile uint8_t pin2_Toggle:1;
	volatile uint8_t pin3_Toggle:1;
	volatile uint8_t pin4_Toggle:1;
	volatile uint8_t pin5_Toggle:1;
	volatile uint8_t pin6_Toggle:1;
	const uint8_t reserved:1;
}PORT_C_TOGGLE;

struct _port {
	PORT_B_D_TOGGLE B_ToggleReg; // 0x03
	PORT_B_D_DIRECTION B_DirectionReg; // 0x04
	PORT_B_D_DATA B_DataReg; // 0x05
	PORT_C_TOGGLE C_ToggleReg; // 0x06
	PORT_C_DIRECTION C_DirectionReg; // 0x07
	PORT_C_DATA C_DataReg; // 0x08
	PORT_B_D_TOGGLE D_ToggleReg; // 0x09
	PORT_B_D_DIRECTION D_DirectionReg; // 0x0A
	PORT_B_D_DATA D_DataReg; // 0x0B	
};

#endif
