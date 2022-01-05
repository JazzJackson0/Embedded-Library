#include <stdint.h>
#include <stddef.h>
#include "spi_MSP430FR.h"
#include "digital_io_MSP430FR.h"

//Static Prototypes----------------------------------------------------
static void SPI_PinInit(void);
static SPI_CONTROL* Get_ControlReg(char* spiNumber);
static SPI_STATUS* Get_StatusReg(char* spiNumber);
static SPI_RECEIVE_BUFFER* Get_RXReg(char* spiNumber);
static SPI_TRANSMIT_BUFFER* Get_TXReg(char* spiNumber);
static SPI_BITRATE_CONTROL* Get_BitRateControlReg(char* spiNumber);

//Global Variables-------------------------------------------------------
//SPI A0
SPI_CONTROL *const SPIControl_A0 = ADDR_SPI_A0_CONTROL;
SPI_STATUS *const SPIStat_A0 = ADDR_SPI_A0_STATUS;
SPI_RECEIVE_BUFFER *const SPIRX_A0 = ADDR_SPI_A0_RECEIVE_BUFFER;
SPI_TRANSMIT_BUFFER *const SPITX_A0 = ADDR_SPI_A0_TRANSMIT_BUFFER;
SPI_BITRATE_CONTROL *const SPIBitRateControl_A0 = ADDR_SPI_A0_BITRATE_CONTROL;
//SPI A0
SPI_CONTROL *const SPIControl_A1 = ADDR_SPI_A1_CONTROL;
SPI_STATUS *const SPIStat_A1 = ADDR_SPI_A1_STATUS;
SPI_RECEIVE_BUFFER *const SPIRX_A1 = ADDR_SPI_A1_RECEIVE_BUFFER;
SPI_TRANSMIT_BUFFER *const SPITX_A1 = ADDR_SPI_A1_TRANSMIT_BUFFER;
SPI_BITRATE_CONTROL *const SPIBitRateControl_A1 = ADDR_SPI_A1_BITRATE_CONTROL;
//SPI B0
SPI_CONTROL *const SPIControl_B0 = ADDR_SPI_B0_CONTROL;
SPI_STATUS *const SPIStat_B0 = ADDR_SPI_B0_STATUS;
SPI_RECEIVE_BUFFER *const SPIRX_B0 = ADDR_SPI_B0_RECEIVE_BUFFER;
SPI_TRANSMIT_BUFFER *const SPITX_B0 = ADDR_SPI_B0_TRANSMIT_BUFFER;
SPI_BITRATE_CONTROL *const SPIBitRateControl_B0 = ADDR_SPI_B0_BITRATE_CONTROL;


/**
- BIT CLOCK VALUE
		fbitclock = (Clock Source)/(Value you Enter)
			+ If (Value you Enter) = 0, fbitclock = (CLock Source)
    
	- CLOCK SPEED: According to '3.2 Clock System Operation'
		+ MCLK & SMCLK = DCOCLK
		+ Then they are divided by 8
		+-----------------------------
		+ DCOCLK = 1MHx
		+ SMCLK & MCLK = 1 MHz / 8
		+ SMCLK & MCLK = 125KHz
**/
void SPI_ClockSetup(char* spiNumber, E_SPIClockSource clockSrc, uint16_t clockDivide, E_Phase phase, E_Polarity polarity) {
	
	SPI_CONTROL *const SPIControl = Get_ControlReg(spiNumber);
	SPI_BITRATE_CONTROL *const SPIBitRateControl = Get_BitRateControlReg(spiNumber);
	
	SPIControl->select_ClockSource = clockSrc;
	SPIBitRateControl->rw_BitClockPrescalerValue = clockDivide;
	SPIControl->clockPhase2ndEdge0_clockPhase1stEdge1 = phase;
	SPIControl->clockPolarityLow0_clockPolarityHigh1 = polarity;
}

void SPI_Init(char* spiNumber, E_SPIMode mode, E_BitOrder bitOrder, uint8_t dataSize) {
	
	SPI_CONTROL *const SPIControl = Get_ControlReg(spiNumber);
	
	if ( SPIControl->enable_SoftwareReset != 1 ) SPIControl->enable_SoftwareReset = 1;
	
	SPIControl->slaveMode0_masterMode1 = mode;
	SPIControl->lsbFirst0_msbFirst1 = bitOrder;
	
	switch (dataSize) {
		
		case 7 : 
			SPIControl->data8Bit0_data7Bit1 = 1;
			break;
		case 8 :
			SPIControl->data8Bit0_data7Bit1 = 0;
			break;
	}
	
	SPIControl->enable_SynchronousMode = 1;
	SPIControl->ssPinForArbitration0_ssPinForSlaveEnable1 = 1;
	SPIControl->rw_SynchronousModeType = SPI_4PIN_SS_LOW;
	
	SPI_PinInit();
	SPIControl->enable_SoftwareReset = 0; // Releases module for operation
}


uint8_t SPI_Transmit_and_Receive(char* spiNumber, uint8_t data) {

	SPI_STATUS *const SPIStat = Get_StatusReg(spiNumber);
	SPI_RECEIVE_BUFFER *const SPIRX = Get_RXReg(spiNumber);
	SPI_TRANSMIT_BUFFER *const SPITX = Get_TXReg(spiNumber);
	
	while (SPIStat->spiBusy == 1);
	
	//Receive and transmit operations operate concurrently.
	SPITX->rw_DataToTransmit = data;
	return SPIRX->read_DataReceived;
}

uint8_t SPI_Receive(char* spiNumber) {
	
	SPI_STATUS *const SPIStat = Get_StatusReg(spiNumber);
	SPI_RECEIVE_BUFFER *const SPIRX = Get_RXReg(spiNumber);
	SPI_TRANSMIT_BUFFER *const SPITX = Get_TXReg(spiNumber);
	
	while (SPIStat->spiBusy == 1);
	
	//Receive and transmit operations operate concurrently.
	SPITX->rw_DataToTransmit = 0x00;
	return SPIRX->read_DataReceived;
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
	
	Watchdog_Off();
	//SCLK
	Pin_Init('2', 2, NONE, SECONDARY_F, NO_PULL);
	//MISO
	Pin_Init('1', 7, NONE, SECONDARY_F, NO_PULL);
	//MOSI
	Pin_Init('1', 6, NONE, SECONDARY_F, NO_PULL);
	//SS
	Pin_Init('1', 3, NONE, SECONDARY_F, NO_PULL);
}

static SPI_CONTROL* Get_ControlReg(char* spiNumber) {
	
	if (spiNumber == "A0") { return SPIControl_A0; }
	if (spiNumber == "A1") { return SPIControl_A1; }
	if (spiNumber == "B0") { return SPIControl_B0; }
	return NULL;
}

static SPI_STATUS* Get_StatusReg(char* spiNumber) {
	
	if (spiNumber == "A0") { return SPIStat_A0; }
	if (spiNumber == "A1") { return SPIStat_A1; }
	if (spiNumber == "B0") { return SPIStat_B0; }
	return NULL;
}

static SPI_RECEIVE_BUFFER* Get_RXReg(char* spiNumber) {
	
	if (spiNumber == "A0") { return SPIRX_A0; }
	if (spiNumber == "A1") { return SPIRX_A1; }
	if (spiNumber == "B0") { return SPIRX_B0; }
	return NULL;
}

static SPI_TRANSMIT_BUFFER* Get_TXReg(char* spiNumber) {
	
	if (spiNumber == "A0") { return SPITX_A0; }
	if (spiNumber == "A1") { return SPITX_A1; }
	if (spiNumber == "B0") { return SPITX_B0; }
	return NULL;
}

static SPI_BITRATE_CONTROL* Get_BitRateControlReg(char* spiNumber) {
	
	if (spiNumber == "A0") { return SPIBitRateControl_A0; }
	if (spiNumber == "A1") { return SPIBitRateControl_A1; }
	if (spiNumber == "B0") { return SPIBitRateControl_B0; }
	return NULL;
}
