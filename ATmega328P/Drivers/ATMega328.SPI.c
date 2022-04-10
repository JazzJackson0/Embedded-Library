#include "ATmega328.SPI.h"

//Global Variables-------------------------------------------------------
//SPI
POWER_REDUCTION_SPI *const SPIPower = ADDR_POWER_REDUCTION_SPI;
SPIx *const SPI = ADDR_SPI;

	
void SPI_ClockSetup(E_ClockDivider clockDiv, E_Phase phase, E_SPIPolarity polarity) {
	
	SPIPower->spiOn0_spiOff1 = 0;
	SPI->ControlReg.rw_SPIClockFrequency = clockDiv;
	SPI->ControlReg.clockPhase1stEdge0_clockPhaseSecondEdge1 = phase;
	SPI->ControlReg.clockPolarityLow0_clockPolarityHigh1 = polarity;
}

void SPI_Init(E_SPIMode mode, E_BitOrder bitOrder) {
	
	SPIPower->spiOn0_spiOff1 = 0;
	SPI->ControlReg.slaveMode0_masterMode1 = mode;
	SPI->ControlReg.msbFirst0_lsbFirst1 = bitOrder;
	SPI->ControlReg.enable_SPIInterrupt = 1;
	SPI->ControlReg.enable_SPI = 1;
}

uint8_t SPI_Transmit_and_Receive(uint8_t data) {
	while (SPI->StatusReg.spiInterruptOccurred != 1);
	SPI->DataReg.readData_writeData = data;
	return SPI->DataReg.readData_writeData;
}


