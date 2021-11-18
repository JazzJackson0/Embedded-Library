//AVR TWI is byte oriented and interrupt based
#include <stdint.h>
#include <stdio.h>
#include "twi_ATmega328.h"

//Macros-----------------------------------------------------------------
#define CLOCK_SPEED 16

//Global Variables-------------------------------------------------------
//TWI
POWER_REDUCTION_TWI *const twiPower = ADDR_POWER_REDUCTION_TWI;
TWI_BITRATE *const twiBitRate = ADDR_TWI_BITRATE;
TWI_STATUS *const twiStat = ADDR_TWI_STATUS;
TWI_DATA *const twiData = ADDR_TWI_DATA;
TWI_CONTROL *const twiControl = ADDR_TWI_CONTROL;
TWI_OWN_SLAVE_ADDRESS *const twiSlaveAddrss = ADDR_TWI_OWN_SLAVE_ADDRESS;


/**
- Arduino Uno Clock Speed
	+ATmega defaults to 8MHz RC Prescaled to 1MHz
	+Arduino Uno Board overrides ATmega and defaults to 16MHz external xtal oscillator
	
Parameters:
	clockDivider -
	bitRate - (In KHz) Ex: 500 for 500KHz
**/
void TWI_Init(E_TWIClockDivide clockDivider, uint8_t bitRatekHz) {
	
	twiPower->twiOn0_twiOff1 = 0;
	twiControl->enable_TWIEventInterrupt = 1;
	
	twiStat->rw_Prescaler = clockDivider;
	twiBitRate->rw_BitRate = (uint8_t) CLOCK_SPEED / (bitRatekHz * 1000);
	
	twiControl->enable_TWI = 1;
}


uint8_t TWIMasterStart(uint8_t slaveAddress, E_Read_Write readWrite) {
	
	twiControl->send_StartCondition = 1;
	
	if (twiControl->twiEventInterruptOccurred == 1 
		&& twiStat->read_TWIStatus == START_CONDITION_TRANSMITTED) {
			
		twiData->readData0_writeData1 = slaveAddress | readWrite;
		twiControl->twiEventInterruptOccurred = 1; //Initiates transmission
	}
	
	else return -1;
	
	switch (readWrite) {
		
		case READ :
			if (twiControl->twiEventInterruptOccurred == 1 
				&& twiStat->read_TWIStatus == SLA_AND_R_TRANSMITTED_ACK_RECEIVED)
				
				return 1;
		case WRITE :
			if (twiControl->twiEventInterruptOccurred == 1 
				&& twiStat->read_TWIStatus == SLA_AND_W_TRANSMITTED_ACK_RECEIVED)
				
				return 1;
	}
	
	return -2;
}

uint8_t TWIMaster_Transmit(uint8_t data) {
	
	twiData->readData0_writeData1 = data;
	twiControl->twiEventInterruptOccurred = 1; //Initiates transmission
	
	if (twiControl->twiEventInterruptOccurred == 1 
		&& twiStat->read_TWIStatus == MASTER_DATA_BYTE_TRANSMITTED_ACK_RECEIVED) {
			
		return 1;
	}
	
	else return -1;
}


uint8_t TWIMaster_Receive(void) {
	
	twiControl->twiEventInterruptOccurred = 1; //Resets the interrupt (TWI wont work while this is set)
	
	//Read Incoming Data
	uint8_t incomingByte = twiData->readData0_writeData1;
	twiControl->twiEventInterruptOccurred = 1;
	twiControl->send_ACK = 1;
	
	if (twiControl->twiEventInterruptOccurred == 1 
		&& twiStat->read_TWIStatus == DATA_BYTE_RECEIVED_ACK_RETURNED) {

		return incomingByte;
	}
	
	else if (twiStat->read_TWIStatus == DATA_BYTE_RECEIVED_NACK_RETURNED) return 0;
}

void TWI_Stop (void) {
	
	twiControl->send_StopConditionORErrorRecover = 1;
}