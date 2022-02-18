//AVR TWI is byte oriented and interrupt based
#include <stdint.h>
//#include <stdio.h>
#include "ATmega328.TWI.h"

//Macros-----------------------------------------------------------------
#define CLOCK_SPEED 16

//Global Variables-------------------------------------------------------
//TWI
POWER_REDUCTION_TWI *const TWIPower = ADDR_POWER_REDUCTION_TWI;
TWIx *const TWI = ADDR_TWI;


void TWI_Init(E_TWIClockDivide clockDivider, uint8_t bitRatekHz) {
	
	TWIPower->twiOn0_twiOff1 = 0;
	TWI->ControlReg.enable_TWIEventInterrupt = 1;
	
	TWI->StatusReg.rw_Prescaler = clockDivider;
	TWI->BitRateReg.rw_BitRate = (uint8_t) CLOCK_SPEED / (bitRatekHz * 1000);
	
	TWI->ControlReg.enable_TWI = 1;
}


uint8_t TWIMasterStart(uint8_t slaveAddress, E_Read_Write readWrite) {
	
	TWI->ControlReg.send_StartCondition = 1;
	
	if (TWI->ControlReg.twiEventInterruptOccurred == 1 
		&& TWI->StatusReg.read_TWIStatus == START_CONDITION_TRANSMITTED) {
			
		TWI->DataReg.readData0_writeData1 = slaveAddress | readWrite;
		TWI->ControlReg.twiEventInterruptOccurred = 1; //Initiates transmission
	}
	
	else return 0;
	
	switch (readWrite) {
		
		case READ :
			if (TWI->ControlReg.twiEventInterruptOccurred == 1 
				&& TWI->StatusReg.read_TWIStatus == SLA_AND_R_TRANSMITTED_ACK_RECEIVED)
				
				return 1;
		case WRITE :
			if (TWI->ControlReg.twiEventInterruptOccurred == 1 
				&& TWI->StatusReg.read_TWIStatus == SLA_AND_W_TRANSMITTED_ACK_RECEIVED)
				
				return 1;
	}
	
	return 0;
}

uint8_t TWIMaster_Transmit(uint8_t data) {
	
	TWI->DataReg.readData0_writeData1 = data;
	TWI->ControlReg.twiEventInterruptOccurred = 1; //Initiates transmission
	
	if (TWI->ControlReg.twiEventInterruptOccurred == 1 
		&& TWI->StatusReg.read_TWIStatus == MASTER_DATA_BYTE_TRANSMITTED_ACK_RECEIVED) {
			
		return 1;
	}
	
	else return 0;
}


uint8_t TWIMaster_Receive(void) {
	
	TWI->ControlReg.twiEventInterruptOccurred = 1; //Resets the interrupt (TWI wont work while this is set)
	
	//Read Incoming Data
	uint8_t incomingByte = TWI->DataReg.readData0_writeData1;
	TWI->ControlReg.twiEventInterruptOccurred = 1;
	TWI->ControlReg.send_ACK = 1;
	
	if (TWI->ControlReg.twiEventInterruptOccurred == 1 
		&& TWI->StatusReg.read_TWIStatus == DATA_BYTE_RECEIVED_ACK_RETURNED) {

		return incomingByte;
	}
	
	else if (TWI->StatusReg.read_TWIStatus == DATA_BYTE_RECEIVED_NACK_RETURNED) return 0;
}

void TWI_Stop (void) {
	
	TWI->ControlReg.send_StopConditionORErrorRecover = 1;
}