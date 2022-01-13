#include <stdint.h>
#include <stdio.h>
#include "i2c_STM32F407.h"
#include "gpio_STM32F407.h"

//Static Prototypes----------------------------------------------------
static void I2C_PinInit(uint8_t i2cNumber);
static void I2CClockSelect(uint8_t i2cNumber);
static I2Cx* Get_I2C(uint8_t i2cNum);
static uint64_t kHz_to_nsP(uint64_t kHzVal);

//Global Variables-------------------------------------------------------
I2C_CLOCK *const I2CClock = ADDR_I2C_CLOCK;
//I2C 1
I2Cx *const I2C1 = ADDR_I2C1;
I2Cx *const I2C2 = ADDR_I2C2;
I2Cx *const I2C3 = ADDR_I2C3;

/**
Parameters:
	- i2cNumber - 
	- apbClockFreqMHz - Ex: 8 for 8MHz Clock
	- desiredI2CFrequencykHz - (in KHz) Ex: 100 for 100KHz SCLK


Clock Control Clock Value Calculation
		+ SCL FREQ GOAL: 100KHz = 10,000 ns(p)
			
			+ Peripheral Clock Frequency: 8MHz = 125 ns(p)
			+ [Clock Value * 125 ns(p) = 10,000 ns(p)]
			+ Clock Value = 10,000 / 125 ns(p)
			+ Clock Value = 80 (i.e. 0x50) 

**/
void I2C_Init(uint8_t i2cNumber, uint8_t apbClockFreqMHz, uint8_t desiredI2CFrequencykHz) {
	I2Cx *const I2C = Get_I2C(i2cNumber);
	I2CClockSelect(i2cNumber);
	I2C_PinInit(i2cNumber);
	I2C->ControlReg2.rw_APBClockFrequency = apbClockFreqMHz; //Ex: 8 for 8MHz Clock
	I2C->ClockControlReg.rw_ClockValue = kHz_to_nsP(desiredI2CFrequencykHz) / kHz_to_nsP(apbClockFreqMHz * 1000); 
	I2C->ControlReg1.enable_ACK = 1;
	I2C->ControlReg1.enable_I2C = 1;
}


uint8_t I2C_StartMaster_SendAddress(uint8_t i2cNumber, uint8_t slaveAddress, E_ReadWrite readWrite) {
	I2Cx *const I2C = Get_I2C(i2cNumber);
	while (I2C->StatusReg2.busBusy == 1);
	I2C->ControlReg1.enable_StartGeneration = 1; //Causes interface to generate a Start condition & switch to Master mode	
	I2C->DataReg.rw_Data = slaveAddress | readWrite;
	
	while (!(I2C->StatusReg1.byteTransferFinished == 1 
		&& I2C->StatusReg1.addressSentOrMatched == 1 
		&& I2C->StatusReg2.transmitter1_receiver0 == 0));
	return 1;
}

uint8_t I2C_Receive(uint8_t i2cNumber) {
	I2Cx *const I2C = Get_I2C(i2cNumber);
	while (I2C->StatusReg2.busBusy == 1);
	return I2C->DataReg.rw_Data;
}

uint8_t I2C_Transmit(uint8_t i2cNumber, uint8_t data) {
	I2Cx *const I2C = Get_I2C(i2cNumber);
	while (I2C->StatusReg2.busBusy == 1);
	I2C->DataReg.rw_Data = data;	
	return 1;
}

void I2C_Stop(uint8_t i2cNumber) {
	I2Cx *const I2C = Get_I2C(i2cNumber);
	I2C->ControlReg1.enable_StopGeneration = 1;
}


//Helper Functions--------------------------------------------------------------------------------------------------------------

/**
I2C Pins ---------------------------------
		+ I2C1_SCL: PB6, PB8 (AF4)
		+ I2C1_SDA: PB7, PB9 (AF4)
		+ I2C1_SMBA PB5 (AF4)
		
		+ I2C2_SCL: PB10, PF1, PH4 (AF4)
		+ I2C2_SDA: PB11, PF0, PH5 (AF4)
		+ I2C2_SMBA PB12, PF2 (AF4)
		
		+ I2C3_SCL: PA8, PH7 (AF4)
		+ I2C3_SCL: PC9, PH8 (AF4)
		------------------------------------
**/
static void I2C_PinInit(uint8_t i2cNumber) {
	
	switch(i2cNumber) {
		
		case 1 :
			//SCl
			Pin_Init('A', 6, AF4);
			//SDA
			Pin_Init('A', 7, AF4);
			break;
		case 2 :
			//SCl
			Pin_Init('B', 10, AF4);
			//SDA
			Pin_Init('B', 11, AF4);
			break;
		case 3 :
			//SCl
			Pin_Init('A', 8, AF4);
			//SDA
			Pin_Init('C', 9, AF4);
			break;
	}
}

static void I2CClockSelect(uint8_t i2cNumber) {
	
	switch(i2cNumber) {
		
		case 1 :
			I2CClock->i2c1_StartTick = 1;
			break;
		case 2 :
			I2CClock->i2c2_StartTick = 1;
			break;
		case 3 :
			I2CClock->i2c3_StartTick = 1;
			break;
	}
}

static I2Cx* Get_I2C(uint8_t i2cNum) {

	switch(i2cNum) {

		case 1:
			return I2C1;
		case 2:
			return I2C2;
		case 3:
			return I2C3;
		default:
			return;
	}
}

/**
kHz to nano-second Period
**/
static uint64_t kHz_to_nsP(uint64_t kHzVal) {
	
	return (uint64_t) 1000000000 / (kHzVal * 1000); 
}
