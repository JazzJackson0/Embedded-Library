#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include "i2c_STM32F446.h"
#include "gpio_STM32F446.h"

//Static Prototypes----------------------------------------------------
static void I2C_PinInit(uint8_t i2cNumber);
static void I2CClockSelect(uint8_t i2cNumber);
static uint64_t kHz_to_nsP(uint64_t kHzVal);
static I2C_CONTROL1* Set_Control1Register(uint8_t i2cNumber);
static I2C_CONTROL2* Set_Control2Register(uint8_t i2cNumber);
static I2C_CLOCKCONTROL* Set_ClockControlRegister(uint8_t i2cNumber);
static I2C_STATUS1* Set_Status1Register(uint8_t i2cNumber);
static I2C_STATUS2* Set_Status2Register(uint8_t i2cNumber);
static I2C_DATA* Set_DataRegister(uint8_t i2cNumber);

//Global Variables-------------------------------------------------------
I2C_CLOCK *const I2CClock = ADDR_I2C_CLOCK;
//I2C 1
I2C_CONTROL1 *const I2CControl1_1 = ADDR_I2C1_CONTROL1;
I2C_CONTROL2 *const I2CControl2_1 = ADDR_I2C1_CONTROL2;
I2C_CLOCKCONTROL *const I2CClockControl_1 = ADDR_I2C1_CLOCKCONTROL;
I2C_STATUS1 *const I2CStatus1_1 = ADDR_I2C1_STATUS1;
I2C_STATUS2 *const I2CStatus2_1 = ADDR_I2C1_STATUS2;
I2C_DATA *const I2CData_1 = ADDR_I2C1_DATA;
//I2C 2
I2C_CONTROL1 *const I2CControl1_2 = ADDR_I2C2_CONTROL1;
I2C_CONTROL2 *const I2CControl2_2 = ADDR_I2C2_CONTROL2;
I2C_CLOCKCONTROL *const I2CClockControl_2 = ADDR_I2C2_CLOCKCONTROL;
I2C_STATUS1 *const I2CStatus1_2 = ADDR_I2C2_STATUS1;
I2C_STATUS2 *const I2CStatus2_2 = ADDR_I2C2_STATUS2;
I2C_DATA *const I2CData_2 = ADDR_I2C2_DATA;
//I2C 3
I2C_CONTROL1 *const I2CControl1_3 = ADDR_I2C3_CONTROL1;
I2C_CONTROL2 *const I2CControl2_3 = ADDR_I2C3_CONTROL2;
I2C_CLOCKCONTROL *const I2CClockControl_3 = ADDR_I2C3_CLOCKCONTROL;
I2C_STATUS1 *const I2CStatus1_3 = ADDR_I2C3_STATUS1;
I2C_STATUS2 *const I2CStatus2_3 = ADDR_I2C3_STATUS2;
I2C_DATA *const I2CData_3 = ADDR_I2C3_DATA;


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
	
	I2C_CONTROL1 *const I2CControl1 = Set_Control1Register(i2cNumber);
	I2C_CONTROL2 *const I2CControl2 = Set_Control2Register(i2cNumber);
	I2C_CLOCKCONTROL *const I2CClockControl = Set_ClockControlRegister(i2cNumber);
	
	I2CClockSelect(i2cNumber);
	I2C_PinInit(i2cNumber);

	I2CControl2->rw_APBClockFrequency = apbClockFreqMHz; //Ex: 8 for 8MHz Clock
	I2CClockControl->rw_ClockValue = kHz_to_nsP(desiredI2CFrequencykHz) / kHz_to_nsP(apbClockFreqMHz * 1000); 
	
	I2CControl1->enable_ACK = 1;
	I2CControl1->enable_I2C = 1;
}


uint8_t I2C_StartMaster_SendAddress(uint8_t i2cNumber, uint8_t slaveAddress, E_ReadWrite readWrite) {
	
	
	I2C_CONTROL1 *const I2CControl1 = Set_Control1Register(i2cNumber);
	I2C_STATUS1 *const I2CStatus1 = Set_Status1Register(i2cNumber);
	I2C_STATUS2 *const I2CStatus2 = Set_Status2Register(i2cNumber);
	I2C_DATA *const I2CData = Set_DataRegister(i2cNumber);

	while (I2CStatus2->busBusy == 1);
	I2CControl1->enable_StartGeneration = 1; //Causes interface to generate a Start condition & switch to Master mode	
	
	I2CData->rw_Data = slaveAddress | readWrite;
	
	while (!(I2CStatus1->byteTransferFinished == 1 
		&& I2CStatus1->addressSentOrMatched == 1 
		&& I2CStatus2->transmitter1_receiver0 == 0));
		
	return 1;
}

uint8_t I2C_Receive(uint8_t i2cNumber) {
	
	I2C_STATUS2 *const I2CStatus2 = Set_Status2Register(i2cNumber);
	I2C_DATA *const I2CData = Set_DataRegister(i2cNumber);
	
	while (I2CStatus2->busBusy == 1);
	return I2CData->rw_Data;
}

uint8_t I2C_Transmit(uint8_t i2cNumber, uint8_t data) {
	
	I2C_STATUS2 *const I2CStatus2 = Set_Status2Register(i2cNumber);
	I2C_DATA *const I2CData = Set_DataRegister(i2cNumber);
	
	while (I2CStatus2->busBusy == 1);
	I2CData->rw_Data = data;
		
	return 1;
}

void I2C_Stop(uint8_t i2cNumber) {
	
	I2C_CONTROL1 *const I2CControl1 = Set_Control1Register(i2cNumber);
	I2CControl1->enable_StopGeneration = 1;
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

/**
kHz to nano-second Period
**/
static uint64_t kHz_to_nsP(uint64_t kHzVal) {
	
	return (uint64_t) 1000000000 / (kHzVal * 1000); 
}

static I2C_CONTROL1* Set_Control1Register(uint8_t i2cNumber) {
	
	switch(i2cNumber) {
		
		case 1 :
			return I2CControl1_1;
		case 2 :
			return I2CControl1_2;
		case 3 :
			return I2CControl1_3;
		default :
			return NULL;
	}
}

static I2C_CONTROL2* Set_Control2Register(uint8_t i2cNumber) {
	
	switch(i2cNumber) {
		
		case 1 :
			return I2CControl2_1;
		case 2 :
			return I2CControl2_2;
		case 3 :
			return I2CControl2_3;
		default :
			return NULL;
	}
}

static I2C_CLOCKCONTROL* Set_ClockControlRegister(uint8_t i2cNumber) {
	
	switch(i2cNumber) {
		
		case 1 :
			return I2CClockControl_1;
		case 2 :
			return I2CClockControl_2;
		case 3 :
			return I2CClockControl_3;
		default :
			return NULL;
	}
}

static I2C_STATUS1* Set_Status1Register(uint8_t i2cNumber) {
	
	switch(i2cNumber) {
		
		case 1 :
			return I2CStatus1_1;
		case 2 :
			return I2CStatus1_2;
		case 3 :
			return I2CStatus1_3;
		default :
			return NULL;
	}
}

static I2C_STATUS2* Set_Status2Register(uint8_t i2cNumber) {
	
	switch(i2cNumber) {
		
		case 1 :
			return I2CStatus2_1;
		case 2 :
			return I2CStatus2_2;
		case 3 :
			return I2CStatus2_3;
		default :
			return NULL;
	}
}

static I2C_DATA* Set_DataRegister(uint8_t i2cNumber) {
	
	switch(i2cNumber) {
		
		case 1 :
			return I2CData_1;
		case 2 :
			return I2CData_2;
		case 3 :
			return I2CData_3;
		default :
			return NULL;
	}
}

