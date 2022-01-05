#include <stdint.h>
#include "spi_ATmega328.h"
#include "io_ports_ATmega328.h"
#include "timer_counter_ATmega328.h"

//Global Variables-------------------------------------------------------
//SPI
POWER_REDUCTION_SPI *const spiPower = ADDR_POWER_REDUCTION_SPI;
SPI_CONTROL *const spiControl = ADDR_SPI_CONTROL;
SPI_STATUS *const spiStat = ADDR_SPI_STATUS;
SPI_DATA *const spiData = ADDR_SPI_DATA;
	
void SPI_ClockSetup(E_ClockDivider clockDiv, E_Phase phase, E_SPIPolarity polarity) {
	
	spiPower->spiOn0_spiOff1 = 0;
	spiControl->rw_SPIClockFrequency = clockDiv;
	spiControl->clockPhase1stEdge0_clockPhaseSecondEdge1 = phase;
	spiControl->clockPolarityLow0_clockPolarityHigh1 = polarity;
}

void SPI_Init(E_SPIMode mode, E_BitOrder bitOrder) {
	
	spiPower->spiOn0_spiOff1 = 0;
	spiControl->slaveMode0_masterMode1 = mode;
	spiControl->msbFirst0_lsbFirst1 = bitOrder;
	spiControl->enable_SPIInterrupt = 1;
	spiControl->enable_SPI = 1;
}

uint8_t SPI_Transmit_and_Receive(uint8_t data) {
	
	while (spiStat->spiInterruptOccurred != 1);
	spiData->readData_writeData = data;
	
	return spiData->readData_writeData;
}

uint8_t SPI_Receive(void) {
	
	while (spiStat->spiInterruptOccurred != 1);
	
	return spiData->readData_writeData;
}

