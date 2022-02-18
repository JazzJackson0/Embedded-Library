#include <stdint.h>
#include "ATmega328.IOPorts.h"

//Static Prototypes----------------------------------------------------------------
static PORTx* Get_Port(char port);

//Global Variables-----------------------------------------------------------------
MCU_CONTROL_PORTS *const ControlPorts = ADDR_MCU_CONTROL_PORTS;
//Port
PORTx *const PORTB = ADDR_PORTB;
PORTx *const PORTC = ADDR_PORTC;
PORTx *const PORTD = ADDR_PORTD;


void Pin_Init(char port, uint8_t pinNum, E_PinDirection direction) {
	
	PORTx *const PORT = Get_Port(port);
	switch (pinNum) {
		case 0 : 
			PORT->DirectionReg.pin0Input0_pin0Output1 = direction;
			break;
		case 1 :
			PORT->DirectionReg.pin1Input0_pin1Output1 = direction;
			break;
		case 2 :
			PORT->DirectionReg.pin2Input0_pin2Output1 = direction;
			break;
		case 3 :
			PORT->DirectionReg.pin3Input0_pin3Output1 = direction;
			break;
		case 4 :
			PORT->DirectionReg.pin4Input0_pin4Output1 = direction;
			break;
		case 5 : 
			PORT->DirectionReg.pin5Input0_pin5Output1 = direction;
			break;
		case 6 :
			PORT->DirectionReg.pin6Input0_pin6Output1 = direction;
			break;
		case 7 :
			if (port == 'B' || port == 'D') {
				PORT->DirectionReg.pin7Input0_pin7Output1 = direction;
				break;
			}
			break;	
	}
}


uint8_t Pin_GetInput(char port, uint8_t pinNum) {
	
	PORTx *const PORT = Get_Port(port);
	switch (pinNum) {
		case 0 : 
			return PORT->DataReg.p0_readData_writeData;
		case 1 :
			return PORT->DataReg.p1_readData_writeData;
		case 2 :
			return PORT->DataReg.p2_readData_writeData;
		case 3 :
			return PORT->DataReg.p3_readData_writeData;
		case 4 :
			return PORT->DataReg.p4_readData_writeData;
		case 5 : 
			return PORT->DataReg.p5_readData_writeData;
		case 6 :
			return PORT->DataReg.p6_readData_writeData;
		case 7 :
			if (port == 'B' || port == 'D') {
				return PORT->DataReg.p7_readData_writeData;
			}
			break;
			
	}
}

void Pin_Out(char port, uint8_t pinNum, uint8_t pinState) {
	
	PORTx *const PORT = Get_Port(port);
	switch (pinNum) {
		case 0 : 
			PORT->DataReg.p0_readData_writeData = pinState;
			break;
		case 1 :
			PORT->DataReg.p1_readData_writeData = pinState;
			break;
		case 2 :
			PORT->DataReg.p2_readData_writeData = pinState;
			break;
		case 3 :
			PORT->DataReg.p3_readData_writeData = pinState;
			break;
		case 4 :
			PORT->DataReg.p4_readData_writeData = pinState;
			break;
		case 5 : 
			PORT->DataReg.p5_readData_writeData = pinState;
			break;
		case 6 :
			PORT->DataReg.p6_readData_writeData = pinState;
			break;
		case 7 :
			if (port == 'B' || port == 'D') {
				PORT->DataReg.p7_readData_writeData = pinState;
				break;
			}
			break;
	}
}

void Pin_Toggle(char port, uint8_t pinNum) {
	
	PORTx *const PORT = Get_Port(port);
	switch (pinNum) {
		case 0 : 
			PORT->ToggleReg.pin0_Toggle = 1;
			break;
		case 1 :
			PORT->ToggleReg.pin1_Toggle = 1;
			break;
		case 2 :
			PORT->ToggleReg.pin2_Toggle = 1;
			break;
		case 3 :
			PORT->ToggleReg.pin3_Toggle = 1;
			break;
		case 4 :
			PORT->ToggleReg.pin4_Toggle = 1;
			break;
		case 5 : 
			PORT->ToggleReg.pin5_Toggle = 1;
			break;
		case 6 :
			PORT->ToggleReg.pin6_Toggle = 1;
			break;
		case 7 :
			if (port == 'B' || port == 'D') {
				PORT->ToggleReg.pin7_Toggle = 1;
				break;
			}
			break;
	}
}

//Helper Functions--------------------------------------------------------------------------
static PORTx* Get_Port(char port) {

	switch (port) {
		case 'B' :
			return PORTB;
		case 'C' :
			return PORTC;
		case 'D' :
			return PORTD;
		default :
			return ((void*)0);
	}
}





