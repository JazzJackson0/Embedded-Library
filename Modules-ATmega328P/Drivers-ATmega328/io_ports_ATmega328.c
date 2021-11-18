#include <stdint.h>
#include "io_ports_ATmega328.h"

//Global Variables-----------------------------------------------------------------
MCU_CONTROL_PORTS *const controlPorts = ADDR_MCU_CONTROL_PORTS;
//Port B
PORT_B_D_DIRECTION *const PINDirection_B = ADDR_PORT_B_DIRECTION;
PORT_B_D_DATA *const PINData_B = ADDR_PORT_B_DATA;
PORT_B_D_TOGGLE *const PINToggle_B = ADDR_PORT_B_TOGGLE;
//Port C
PORT_C_DIRECTION *const PINDirection_C = ADDR_PORT_C_DIRECTION;
PORT_C_DATA *const PINData_C = ADDR_PORT_C_DATA;
PORT_C_TOGGLE *const PINToggle_C = ADDR_PORT_C_TOGGLE;
//Port D
PORT_B_D_DIRECTION *const PINDirection_D = ADDR_PORT_D_DIRECTION;
PORT_B_D_DATA *const PINData_D = ADDR_PORT_D_DATA;
PORT_B_D_TOGGLE *const PINToggle_D = ADDR_PORT_D_TOGGLE;



void Pin_Init(char port, uint8_t pinNum, E_PinDirection direction) {
	
	switch (port) {
		
		case 'B' : 
			switch (pinNum) {
				
				case 0 : 
					PINDirection_B->pin0Input0_pin0Output1 = direction;
					break;
				case 1 :
					PINDirection_B->pin1Input0_pin1Output1 = direction;
					break;
				case 2 :
					PINDirection_B->pin2Input0_pin2Output1 = direction;
					break;
				case 3 :
					PINDirection_B->pin3Input0_pin3Output1 = direction;
					break;
				case 4 :
					PINDirection_B->pin4Input0_pin4Output1 = direction;
					break;
				case 5 : 
					PINDirection_B->pin5Input0_pin5Output1 = direction;
					break;
				case 6 :
					PINDirection_B->pin6Input0_pin6Output1 = direction;
					break;
				case 7 :
					PINDirection_B->pin7Input0_pin7Output1 = direction;
					break;
			}
			break;
		case 'C' :
			switch (pinNum) {
				
				case 0 : 
					PINDirection_C->pin0Input0_pin0Output1 = direction;
					break;
				case 1 :
					PINDirection_C->pin1Input0_pin1Output1 = direction;
					break;
				case 2 :
					PINDirection_C->pin2Input0_pin2Output1 = direction;
					break;
				case 3 :
					PINDirection_C->pin3Input0_pin3Output1 = direction;
					break;
				case 4 :
					PINDirection_C->pin4Input0_pin4Output1 = direction;
					break;
				case 5 : 
					PINDirection_C->pin5Input0_pin5Output1 = direction;
					break;
				case 6 :
					PINDirection_C->pin6Input0_pin6Output1 = direction;
					break;
			}
			break;
		case 'D' :
			switch (pinNum) {
				
				case 0 : 
					PINDirection_D->pin0Input0_pin0Output1 = direction;
					break;
				case 1 :
					PINDirection_D->pin1Input0_pin1Output1 = direction;
					break;
				case 2 :
					PINDirection_D->pin2Input0_pin2Output1 = direction;
					break;
				case 3 :
					PINDirection_D->pin3Input0_pin3Output1 = direction;
					break;
				case 4 :
					PINDirection_D->pin4Input0_pin4Output1 = direction;
					break;
				case 5 : 
					PINDirection_D->pin5Input0_pin5Output1 = direction;
					break;
				case 6 :
					PINDirection_D->pin6Input0_pin6Output1 = direction;
					break;
				case 7 :
					PINDirection_D->pin7Input0_pin7Output1 = direction;
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
					return PINData_B->p0_readData_writeData;
				case 1 :
					return PINData_B->p1_readData_writeData;
				case 2 :
					return PINData_B->p2_readData_writeData;
				case 3 :
					return PINData_B->p3_readData_writeData;
				case 4 :
					return PINData_B->p4_readData_writeData;
				case 5 : 
					return PINData_B->p5_readData_writeData;
				case 6 :
					return PINData_B->p6_readData_writeData;
				case 7 :
					return PINData_B->p7_readData_writeData;
			}
			break;
		case 'C' :
			switch (pinNum) {
				
				case 0 : 
					return PINData_C->p0_readData_writeData;
				case 1 :
					return PINData_C->p1_readData_writeData;
				case 2 :
					return PINData_C->p2_readData_writeData;
				case 3 :
					return PINData_C->p3_readData_writeData;
				case 4 :
					return PINData_C->p4_readData_writeData;
				case 5 : 
					return PINData_C->p5_readData_writeData;
				case 6 :
					return PINData_C->p6_readData_writeData;
			}
			break;
		case 'D' :
			switch (pinNum) {
				
				case 0 : 
					return PINData_D->p0_readData_writeData;
				case 1 :
					return PINData_D->p1_readData_writeData;
				case 2 :
					return PINData_D->p2_readData_writeData;
				case 3 :
					return PINData_D->p3_readData_writeData;
				case 4 :
					return PINData_D->p4_readData_writeData;
				case 5 : 
					return PINData_D->p5_readData_writeData;
				case 6 :
					return PINData_D->p6_readData_writeData;
				case 7 :
					return PINData_D->p7_readData_writeData;
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
					PINData_B->p0_readData_writeData = pinState;
					break;
				case 1 :
					PINData_B->p1_readData_writeData = pinState;
					break;
				case 2 :
					PINData_B->p2_readData_writeData = pinState;
					break;
				case 3 :
					PINData_B->p3_readData_writeData = pinState;
					break;
				case 4 :
					PINData_B->p4_readData_writeData = pinState;
					break;
				case 5 : 
					PINData_B->p5_readData_writeData = pinState;
					break;
				case 6 :
					PINData_B->p6_readData_writeData = pinState;
					break;
				case 7 :
					PINData_B->p7_readData_writeData = pinState;
					break;
			}
			break;
		case 'C' :
			switch (pinNum) {
				
				case 0 : 
					PINData_C->p0_readData_writeData = pinState;
					break;
				case 1 :
					PINData_C->p1_readData_writeData = pinState;
					break;
				case 2 :
					PINData_C->p2_readData_writeData = pinState;
					break;
				case 3 :
					PINData_C->p3_readData_writeData = pinState;
					break;
				case 4 :
					PINData_C->p4_readData_writeData = pinState;
					break;
				case 5 : 
					PINData_C->p5_readData_writeData = pinState;
					break;
				case 6 :
					PINData_C->p6_readData_writeData = pinState;
					break;
			}
			break;
		case 'D' :
			switch (pinNum) {
				
				case 0 : 
					PINData_D->p0_readData_writeData = pinState;
					break;
				case 1 :
					PINData_D->p1_readData_writeData = pinState;
					break;
				case 2 :
					PINData_D->p2_readData_writeData = pinState;
					break;
				case 3 :
					PINData_D->p3_readData_writeData = pinState;
					break;
				case 4 :
					PINData_D->p4_readData_writeData = pinState;
					break;
				case 5 : 
					PINData_D->p5_readData_writeData = pinState;
					break;
				case 6 :
					PINData_D->p6_readData_writeData = pinState;
					break;
				case 7 :
					PINData_D->p7_readData_writeData = pinState;
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
					PINToggle_B->pin0_Toggle = 1;
					break;
				case 1 :
					PINToggle_B->pin1_Toggle = 1;
					break;
				case 2 :
					PINToggle_B->pin2_Toggle = 1;
					break;
				case 3 :
					PINToggle_B->pin3_Toggle = 1;
					break;
				case 4 :
					PINToggle_B->pin4_Toggle = 1;
					break;
				case 5 : 
					PINToggle_B->pin5_Toggle = 1;
					break;
				case 6 :
					PINToggle_B->pin6_Toggle = 1;
					break;
				case 7 :
					PINToggle_B->pin7_Toggle = 1;
					break;
			}
			break;
		case 'C' :
			switch (pinNum) {
				
				case 0 : 
					PINToggle_C->pin0_Toggle = 1;
					break;
				case 1 :
					PINToggle_C->pin1_Toggle = 1;
					break;
				case 2 :
					PINToggle_C->pin2_Toggle = 1;
					break;
				case 3 :
					PINToggle_C->pin3_Toggle = 1;
					break;
				case 4 :
					PINToggle_C->pin4_Toggle = 1;
					break;
				case 5 : 
					PINToggle_C->pin5_Toggle = 1;
					break;
				case 6 :
					PINToggle_C->pin6_Toggle = 1;
					break;
			}
			break;
		case 'D' :
			switch (pinNum) {
				
				case 0 : 
					PINToggle_D->pin0_Toggle = 1;
					break;
				case 1 :
					PINToggle_D->pin1_Toggle = 1;
					break;
				case 2 :
					PINToggle_D->pin2_Toggle = 1;
					break;
				case 3 :
					PINToggle_D->pin3_Toggle = 1;
					break;
				case 4 :
					PINToggle_D->pin4_Toggle = 1;
					break;
				case 5 : 
					PINToggle_D->pin5_Toggle = 1;
					break;
				case 6 :
					PINToggle_D->pin6_Toggle = 1;
					break;
				case 7 :
					PINToggle_D->pin7_Toggle = 1;
					break;
			}
			break;
	}
}





