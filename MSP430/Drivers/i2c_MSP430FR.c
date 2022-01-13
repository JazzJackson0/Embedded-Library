#include <stdint.h>
//#include <stdio.h>
#include "i2c_MSP430FR.h"
#include "digital_io_MSP430FR.h"

//Static Prototypes----------------------------------------------------
static void I2C_PinInit(void);

//Global Variables-------------------------------------------------------
//I2C B0
I2Cx *const I2C_x = ADDR_I2C;


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

	I2Cx *const I2C = I2C_x;
	if ( I2C->ControlWord0Reg.enable_SoftwareReset != 1 ) 
		I2C->ControlWord0Reg.enable_SoftwareReset = 1;
	
	I2C->ControlWord0Reg.select_ClockSource = clockSrc;
	I2C->BitRateControlWordReg.rw_BitClockPrescaler = clockDivide;
	
	I2C->ControlWord1Reg.rw_AutoStopConditionType = NONE;
	I2C->ControlWord0Reg.enable_SynchronousMode = 1;
	I2C->ControlWord0Reg.rw_SynchronousModeType = I2C_MODE;
	I2C->InterruptEnableReg.enable_NACKInterrupt = 1;
	
	I2C->ControlWord0Reg.slaveMode0_masterMode1 = mode;
	I2C->ControlWord0Reg.ownAddrss7Bit0_ownAddrss10Bit1 = ownSize;
	
	I2C_PinInit();
	I2C->ControlWord0Reg.enable_SoftwareReset = 0; // Releases module for operation
}

void I2C_SetSlaveAddress(uint16_t slaveAddrs, E_AddressSize slaveSize) {
	
	I2Cx *const I2C = I2C_x;
	I2C->SlaveAddressReg.rw_SlaveAddress = slaveAddrs;
	I2C->ControlWord0Reg.slaveAddrss7Bit0_slaveAddrss10Bit1 = slaveSize;
}

void Start_RX_Mode(void) {
	
	I2Cx *const I2C = I2C_x;
	I2C->ControlWord0Reg.receiver0_transmitter1 = 0;
	while (I2C->StatusWordReg.busBusy == 1);
	I2C->ControlWord0Reg.send_StartCondition = 1;
}

void Start_TX_Mode(void) {
	
	I2Cx *const I2C = I2C_x;
	I2C->ControlWord0Reg.receiver0_transmitter1 = 1;
	while (I2C->StatusWordReg.busBusy == 1);
	I2C->ControlWord0Reg.send_StartCondition = 1;
}

uint8_t I2C_Receive(void) {
	
	I2Cx *const I2C = I2C_x;
	while (I2C->StatusWordReg.busBusy == 1);
			
	I2C->ControlWord0Reg.send_ACK = 1;
	return I2C->RXBufferReg.read_DataReceived;
}

uint8_t I2C_Transmit(uint8_t data) {
	
	I2Cx *const I2C = I2C_x;
	while (I2C->StatusWordReg.busBusy == 1);

	I2C->TXBufferReg.rw_DataToTransmit = data;
	
	if (I2C->InterruptFlagReg.nACKInterruptOccurred == 1) return 0;
	
	else return 1;
}

void I2C_Stop(void) {
	
	I2Cx *const I2C = I2C_x;
	I2C->ControlWord0Reg.send_StopCondition = 1;
}

//Helper Functions--------------------------------------------------------------------------------------------------------


/**
I2C Pins ---------------------------------
		+ I2C B0 Data: P1-6 	[(Secondary Function)]
		+ I2C B0 Clock: P1-7 	[(Secondary Function)] 
		------------------------------------
**/
static void I2C_PinInit(void) {

	//SCK
	Pin_Init('1', 7, NONE, SECONDARY_F, NO_PULL);
	//SDA
	Pin_Init('1', 6, NONE, SECONDARY_F, NO_PULL);
}