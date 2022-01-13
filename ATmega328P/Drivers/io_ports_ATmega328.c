#include <stdint.h>
#include "io_ports_ATmega328.h"

//Global Variables-----------------------------------------------------------------
MCU_CONTROL_PORTS *const ControlPorts = ADDR_MCU_CONTROL_PORTS;
//Port
PORTx *const PORTS = ADDR_PORTS;


void Pin_Init(char port, uint8_t pinNum, E_PinDirection direction) {
	
	switch (port) {
		case 'B' : 
			switch (pinNum) {
				case 0 : 
					PORTS->B_DirectionReg.pin0Input0_pin0Output1 = direction;
					break;
				case 1 :
					PORTS->B_DirectionReg.pin1Input0_pin1Output1 = direction;
					break;
				case 2 :
					PORTS->B_DirectionReg.pin2Input0_pin2Output1 = direction;
					break;
				case 3 :
					PORTS->B_DirectionReg.pin3Input0_pin3Output1 = direction;
					break;
				case 4 :
					PORTS->B_DirectionReg.pin4Input0_pin4Output1 = direction;
					break;
				case 5 : 
					PORTS->B_DirectionReg.pin5Input0_pin5Output1 = direction;
					break;
				case 6 :
					PORTS->B_DirectionReg.pin6Input0_pin6Output1 = direction;
					break;
				case 7 :
					PORTS->B_DirectionReg.pin7Input0_pin7Output1 = direction;
					break;
			}
			break;
		case 'C' :
			switch (pinNum) {
				case 0 : 
					PORTS->C_DirectionReg.pin0Input0_pin0Output1 = direction;
					break;
				case 1 :
					PORTS->C_DirectionReg.pin1Input0_pin1Output1 = direction;
					break;
				case 2 :
					PORTS->C_DirectionReg.pin2Input0_pin2Output1 = direction;
					break;
				case 3 :
					PORTS->C_DirectionReg.pin3Input0_pin3Output1 = direction;
					break;
				case 4 :
					PORTS->C_DirectionReg.pin4Input0_pin4Output1 = direction;
					break;
				case 5 : 
					PORTS->C_DirectionReg.pin5Input0_pin5Output1 = direction;
					break;
				case 6 :
					PORTS->C_DirectionReg.pin6Input0_pin6Output1 = direction;
					break;
			}
			break;
		case 'D' :
			switch (pinNum) {
				case 0 : 
					PORTS->D_DirectionReg.pin0Input0_pin0Output1 = direction;
					break;
				case 1 :
					PORTS->D_DirectionReg.pin1Input0_pin1Output1 = direction;
					break;
				case 2 :
					PORTS->D_DirectionReg.pin2Input0_pin2Output1 = direction;
					break;
				case 3 :
					PORTS->D_DirectionReg.pin3Input0_pin3Output1 = direction;
					break;
				case 4 :
					PORTS->D_DirectionReg.pin4Input0_pin4Output1 = direction;
					break;
				case 5 : 
					PORTS->D_DirectionReg.pin5Input0_pin5Output1 = direction;
					break;
				case 6 :
					PORTS->D_DirectionReg.pin6Input0_pin6Output1 = direction;
					break;
				case 7 :
					PORTS->D_DirectionReg.pin7Input0_pin7Output1 = direction;
					break;
			}
			break;			
	}
}


uint8_t Pin_GetInput(char port, uint8_t pinNum) {
	
	switch (port) {
		case 'B' : 
			switch (pinNum) {
				case 0 : 
					return PORTS->B_DataReg.p0_readData_writeData;
				case 1 :
					return PORTS->B_DataReg.p1_readData_writeData;
				case 2 :
					return PORTS->B_DataReg.p2_readData_writeData;
				case 3 :
					return PORTS->B_DataReg.p3_readData_writeData;
				case 4 :
					return PORTS->B_DataReg.p4_readData_writeData;
				case 5 : 
					return PORTS->B_DataReg.p5_readData_writeData;
				case 6 :
					return PORTS->B_DataReg.p6_readData_writeData;
				case 7 :
					return PORTS->B_DataReg.p7_readData_writeData;
			}
			break;
		case 'C' :
			switch (pinNum) {
				case 0 : 
					return PORTS->C_DataReg.p0_readData_writeData;
				case 1 :
					return PORTS->C_DataReg.p1_readData_writeData;
				case 2 :
					return PORTS->C_DataReg.p2_readData_writeData;
				case 3 :
					return PORTS->C_DataReg.p3_readData_writeData;
				case 4 :
					return PORTS->C_DataReg.p4_readData_writeData;
				case 5 : 
					return PORTS->C_DataReg.p5_readData_writeData;
				case 6 :
					return PORTS->C_DataReg.p6_readData_writeData;
			}
			break;
		case 'D' :
			switch (pinNum) {
				case 0 : 
					return PORTS->D_DataReg.p0_readData_writeData;
				case 1 :
					return PORTS->D_DataReg.p1_readData_writeData;
				case 2 :
					return PORTS->D_DataReg.p2_readData_writeData;
				case 3 :
					return PORTS->D_DataReg.p3_readData_writeData;
				case 4 :
					return PORTS->D_DataReg.p4_readData_writeData;
				case 5 : 
					return PORTS->D_DataReg.p5_readData_writeData;
				case 6 :
					return PORTS->D_DataReg.p6_readData_writeData;
				case 7 :
					return PORTS->D_DataReg.p7_readData_writeData;
			}
			break;
		default :
			return 42;
	}
}

void Pin_Out(char port, uint8_t pinNum, E_PinDirection pinState) {
	
	switch (port) {
		case 'B' : 
			switch (pinNum) {
				case 0 : 
					PORTS->B_DataReg.p0_readData_writeData = pinState;
					break;
				case 1 :
					PORTS->B_DataReg.p1_readData_writeData = pinState;
					break;
				case 2 :
					PORTS->B_DataReg.p2_readData_writeData = pinState;
					break;
				case 3 :
					PORTS->B_DataReg.p3_readData_writeData = pinState;
					break;
				case 4 :
					PORTS->B_DataReg.p4_readData_writeData = pinState;
					break;
				case 5 : 
					PORTS->B_DataReg.p5_readData_writeData = pinState;
					break;
				case 6 :
					PORTS->B_DataReg.p6_readData_writeData = pinState;
					break;
				case 7 :
					PORTS->B_DataReg.p7_readData_writeData = pinState;
					break;
			}
			break;
		case 'C' :
			switch (pinNum) {
				case 0 : 
					PORTS->C_DataReg.p0_readData_writeData = pinState;
					break;
				case 1 :
					PORTS->C_DataReg.p1_readData_writeData = pinState;
					break;
				case 2 :
					PORTS->C_DataReg.p2_readData_writeData = pinState;
					break;
				case 3 :
					PORTS->C_DataReg.p3_readData_writeData = pinState;
					break;
				case 4 :
					PORTS->C_DataReg.p4_readData_writeData = pinState;
					break;
				case 5 : 
					PORTS->C_DataReg.p5_readData_writeData = pinState;
					break;
				case 6 :
					PORTS->C_DataReg.p6_readData_writeData = pinState;
					break;
			}
			break;
		case 'D' :
			switch (pinNum) {
				case 0 : 
					PORTS->D_DataReg.p0_readData_writeData = pinState;
					break;
				case 1 :
					PORTS->D_DataReg.p1_readData_writeData = pinState;
					break;
				case 2 :
					PORTS->D_DataReg.p2_readData_writeData = pinState;
					break;
				case 3 :
					PORTS->D_DataReg.p3_readData_writeData = pinState;
					break;
				case 4 :
					PORTS->D_DataReg.p4_readData_writeData = pinState;
					break;
				case 5 : 
					PORTS->D_DataReg.p5_readData_writeData = pinState;
					break;
				case 6 :
					PORTS->D_DataReg.p6_readData_writeData = pinState;
					break;
				case 7 :
					PORTS->D_DataReg.p7_readData_writeData = pinState;
					break;
			}
			break;
	}
}

void Pin_Toggle(char port, uint8_t pinNum) {
	
	switch (port) {
		
		case 'B' : 
			switch (pinNum) {
				case 0 : 
					PORTS->B_ToggleReg.pin0_Toggle = 1;
					break;
				case 1 :
					PORTS->B_ToggleReg.pin1_Toggle = 1;
					break;
				case 2 :
					PORTS->B_ToggleReg.pin2_Toggle = 1;
					break;
				case 3 :
					PORTS->B_ToggleReg.pin3_Toggle = 1;
					break;
				case 4 :
					PORTS->B_ToggleReg.pin4_Toggle = 1;
					break;
				case 5 : 
					PORTS->B_ToggleReg.pin5_Toggle = 1;
					break;
				case 6 :
					PORTS->B_ToggleReg.pin6_Toggle = 1;
					break;
				case 7 :
					PORTS->B_ToggleReg.pin7_Toggle = 1;
					break;
			}
			break;
		case 'C' :
			switch (pinNum) {
				case 0 : 
					PORTS->C_ToggleReg.pin0_Toggle = 1;
					break;
				case 1 :
					PORTS->C_ToggleReg.pin1_Toggle = 1;
					break;
				case 2 :
					PORTS->C_ToggleReg.pin2_Toggle = 1;
					break;
				case 3 :
					PORTS->C_ToggleReg.pin3_Toggle = 1;
					break;
				case 4 :
					PORTS->C_ToggleReg.pin4_Toggle = 1;
					break;
				case 5 : 
					PORTS->C_ToggleReg.pin5_Toggle = 1;
					break;
				case 6 :
					PORTS->C_ToggleReg.pin6_Toggle = 1;
					break;
			}
			break;
		case 'D' :
			switch (pinNum) {
				case 0 : 
					PORTS->D_ToggleReg.pin0_Toggle = 1;
					break;
				case 1 :
					PORTS->D_ToggleReg.pin1_Toggle = 1;
					break;
				case 2 :
					PORTS->D_ToggleReg.pin2_Toggle = 1;
					break;
				case 3 :
					PORTS->D_ToggleReg.pin3_Toggle = 1;
					break;
				case 4 :
					PORTS->D_ToggleReg.pin4_Toggle = 1;
					break;
				case 5 : 
					PORTS->D_ToggleReg.pin5_Toggle = 1;
					break;
				case 6 :
					PORTS->D_ToggleReg.pin6_Toggle = 1;
					break;
				case 7 :
					PORTS->D_ToggleReg.pin7_Toggle = 1;
					break;
			}
			break;
	}
}





