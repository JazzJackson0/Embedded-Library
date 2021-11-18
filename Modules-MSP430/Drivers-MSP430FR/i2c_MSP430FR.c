#include <stdint.h>
//#include <stdio.h>
#include "i2c_MSP430FR.h"
#include "digital_io_MSP430FR.h"

//Static Prototypes----------------------------------------------------
static void I2C_PinInit(void);

//Global Variables-------------------------------------------------------
//I2C B0
I2C_CONTROL_WORD0 *const I2CControlWord0 = ADDR_I2C_CONTROL_WORD0;
I2C_CONTROL_WORD1 *const I2CControlWord1 = ADDR_I2C_CONTROL_WORD1;
I2C_BITRATE_CONTROL_WORD *const I2CBitControlWord = ADDR_I2C_BITRATE_CONTROL_WORD;
I2C_STATUS_WORD *const I2CStatWord = ADDR_I2C_STATUS_WORD;
I2C_RECEIVE_BUFFER *const I2CRX = ADDR_I2C_RECEIVE_BUFFER;
I2C_TRANSMIT_BUFFER *const I2CTX = ADDR_I2C_TRANSMIT_BUFFER;
I2C_SLAVE_ADDRESS *const I2CSlaveAddrss = ADDR_I2C_SLAVE_ADDRESS; 
I2C_OWN_ADDRESS0 *const I2COwnAddrss = ADDR_I2C_OWN_ADDRESS0;
I2C_INTERRUPT_ENABLE *const I2CIntEnable = ADDR_I2C_INTERRUPT_ENABLE;
I2C_INTERRUPT_FLAG *const I2CIntFlag = ADDR_I2C_INTERRUPT_FLAG;

/**
- CLOCK SPEED: According to '3.2 Clock System Operation'
		+ MCLK & SMCLK = DCOCLK
		+ Then they are divided by 8
		+-----------------------------
		+ DCOCLK = 1MHx
		+ SMCLK & MCLK = 1 MHz / 8
		+ SMCLK & MCLK = 125KHz
**/
void I2C_Init(E_I2CClockSource clockSrc, uint16_t clockDivide, E_I2CMode mode, E_AddressSize ownSize) {
	
	if ( I2CControlWord0->enable_SoftwareReset != 1 ) I2CControlWord0->enable_SoftwareReset = 1;
	
	I2CControlWord0->select_ClockSource = clockSrc;
	I2CBitControlWord->rw_BitClockPrescaler = clockDivide;
	
	I2CControlWord1->rw_AutoStopConditionType = NONE;
	I2CControlWord0->enable_SynchronousMode = 1;
	I2CControlWord0->rw_SynchronousModeType = I2C_MODE;
	I2CIntEnable->enable_NACKInterrupt = 1;
	
	I2CControlWord0->slaveMode0_masterMode1 = mode;
	I2CControlWord0->ownAddrss7Bit0_ownAddrss10Bit1 = ownSize;
	
	I2C_PinInit();
	I2CControlWord0->enable_SoftwareReset = 0; // Releases module for operation
}

void I2C_SetSlaveAddress(uint16_t slaveAddrs, E_AddressSize slaveSize) {
	
	I2CSlaveAddrss->rw_SlaveAddress = slaveAddrs;
	I2CControlWord0->slaveAddrss7Bit0_slaveAddrss10Bit1 = slaveSize;
}

void Start_RX_Mode(void) {
	
	I2CControlWord0->receiver0_transmitter1 = 0;
	while (I2CStatWord->busBusy == 1);
	I2CControlWord0->send_StartCondition = 1;
}

void Start_TX_Mode(void) {
	
	I2CControlWord0->receiver0_transmitter1 = 1;
	while (I2CStatWord->busBusy == 1);
	I2CControlWord0->send_StartCondition = 1;
}

uint8_t I2C_Receive(void) {
	
	while (I2CStatWord->busBusy == 1);
			
	I2CControlWord0->send_ACK = 1;
	return I2CRX->read_DataReceived;
}

uint8_t I2C_Transmit(uint8_t data) {
	
	while (I2CStatWord->busBusy == 1);

	I2CTX->rw_DataToTransmit = data;
	
	if (I2CIntFlag->nACKInterruptOccurred == 1) return 0;
	
	else return 1;
}

void I2C_Stop(void) {
	
	I2CControlWord0->send_StopCondition = 1;
}

//Helper Functions--------------------------------------------------------------------------------------------------------


/**
I2C Pins ---------------------------------
		+ I2C B0 Data: P1-6 	[(Secondary Function)]
		+ I2C B0 Clock: P1-7 	[(Secondary Function)] 
		------------------------------------
**/
static void I2C_PinInit(void) {
	
	//Turn Off Watchdog Timer
	Watchdog_Off();
	//SCK
	Pin_Init('1', 7, NONE, SECONDARY_F, NO_PULL);
	//SDA
	Pin_Init('1', 6, NONE, SECONDARY_F, NO_PULL);
}