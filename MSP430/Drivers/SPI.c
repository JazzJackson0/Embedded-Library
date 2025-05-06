#include "SPI.h"

//Static Prototypes----------------------------------------------------
static void SPI_PinInit(void);
static SPIx* Get_SPI(char* spiID);

//Global Variables-------------------------------------------------------
//SPI
SPIx *const SPI_A0 = ADDR_SPI_A0;
SPIx *const SPI_A1 = ADDR_SPI_A1;
SPIx *const SPI_B0 = ADDR_SPI_B0;


void SPI_ClockSetup(char* spiNumber, E_SPIClockSource clockSrc, uint16_t clockDivide, E_Phase phase, E_Polarity polarity) {
	
	SPIx *const SPI = Get_SPI(spiNumber);

	SPI->ControlReg.select_ClockSource = clockSrc;
	SPI->BitRateControlReg.rw_BitClockPrescalerValue = clockDivide;
	SPI->ControlReg.clockPhase2ndEdge0_clockPhase1stEdge1 = phase;
	SPI->ControlReg.clockPolarityLow0_clockPolarityHigh1 = polarity;
}

void SPI_Init(char* spiNumber, E_SPIMode mode, E_BitOrder bitOrder, uint8_t dataSize) {
	
	SPIx *const SPI = Get_SPI(spiNumber);
	
	if ( SPI->ControlReg.enable_SoftwareReset != 1 ) SPI->ControlReg.enable_SoftwareReset = 1;
	
	SPI->ControlReg.slaveMode0_masterMode1 = mode;
	SPI->ControlReg.lsbFirst0_msbFirst1 = bitOrder;
	
	switch (dataSize) {
		case 7 : 
			SPI->ControlReg.data8Bit0_data7Bit1 = 1;
			break;
		case 8 :
			SPI->ControlReg.data8Bit0_data7Bit1 = 0;
			break;
	}
	
	SPI->ControlReg.enable_SynchronousMode = 1;
	SPI->ControlReg.ssPinForArbitration0_ssPinForSlaveEnable1 = 1;
	SPI->ControlReg.rw_SynchronousModeType = SPI_4PIN_SS_LOW;
	
	SPI_PinInit();
	SPI->ControlReg.enable_SoftwareReset = 0; // Releases module for operation
}


uint8_t SPI_Transmit_and_Receive(char* spiNumber, uint8_t data) {

	SPIx *const SPI = Get_SPI(spiNumber);
	
	while (SPI->StatusReg.spiBusy == 1);
	
	//Receive and transmit operations operate concurrently.
	SPI->TXBufferReg.rw_DataToTransmit = data;
	return SPI->RXBufferReg.read_DataReceived;
}

//Helper Functions--------------------------------------------------------------------------------------------------------

/**
SPI Pins ---------------------------
		+ SPIA0 Clock In/Out: P1-5 	[(Secondary Function)]
		+ SPIA0 MOSI: P2-0 			[(Secondary Function)]
		+ SPIA0 MISO: P2-1 			[(Secondary Function)]
		+ SPIA0 SS: P1-4 			[(Secondary Function)]
		
		+ SPIA1 Clock In/Out: P2-4 	[(Secondary Function)]
		+ SPIA1 MOSI: P2-5 			[(Secondary Function)]
		+ SPIA1 MISO: P2-6 			[(Secondary Function)]
		+ SPIA1 SS: P2-3 			[(Secondary Function)]
		
		+ SPIB0 Clock In/Out: P2-2 	[(Secondary Function)]
		+ SPIB0 MOSI: P1-6 			[(Secondary Function)]
		+ SPIB0 MISO: P1-7 			[(Secondary Function)]
		+ SPIB0 SS: P1-3 			[(Secondary Function)]
		------------------------------------
**/
static void SPI_PinInit(void) {

	//SCLK
	Pin_Init('2', 2, NONE, SECONDARY_F, NO_PULL);
	//MISO
	Pin_Init('1', 7, NONE, SECONDARY_F, NO_PULL);
	//MOSI
	Pin_Init('1', 6, NONE, SECONDARY_F, NO_PULL);
	//SS
	Pin_Init('1', 3, NONE, SECONDARY_F, NO_PULL);
}

static SPIx* Get_SPI(char* spiID) {
	if (spiID == "A0") { return SPI_A0; }
	else if (spiID == "A1") { return SPI_A1; }
	else if (spiID == "B0") { return SPI_B0; }
	return NULL;
}

