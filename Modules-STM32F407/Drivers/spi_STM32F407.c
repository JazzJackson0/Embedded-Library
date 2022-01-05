#include <stdint.h>
#include <stddef.h>
#include "spi_STM32F407.h"
#include "gpio_STM32F407.h"

//Static Prototypes---------------------------------------------
static void SPI_PinInit(uint8_t spiNumber);
static void SPIClockSelect(uint8_t spiNumber);
static SPI_CONTROL1* Set_Control1Register(uint8_t spiNumber);
static SPI_CONTROL2* Set_Control2Register(uint8_t spiNumber);
static SPI_STATUS* Set_StatusRegister(uint8_t spiNumber);
static SPI_DATA* Set_DataRegister(uint8_t spiNumber);

//Global Variables------------------------------------------------
//Clock
SPI_CLOCK_1 *const SPIClock = ADDR_SPI_CLOCK_1;
SPI_CLOCK_2_3 *const SPIClock2_3 = ADDR_SPI_CLOCK_2_3;
//For SPI 1
SPI_CONTROL1 *const SPIControl1_1 = ADDR_SPI1_CONTROL1;
SPI_CONTROL2 *const SPIControl2_1 = ADDR_SPI1_CONTROL2; 
SPI_STATUS *const SPIStatus_1 = ADDR_SPI1_STATUS; 
SPI_DATA *const SPIData_1 = ADDR_SPI1_DATA; 
//For SPI 2
SPI_CONTROL1 *const SPIControl1_2 = ADDR_SPI2_CONTROL1;
SPI_CONTROL2 *const SPIControl2_2 = ADDR_SPI2_CONTROL2; 
SPI_STATUS *const SPIStatus_2 = ADDR_SPI2_STATUS; 
SPI_DATA *const SPIData_2 = ADDR_SPI2_DATA; 
//For SPI 3
SPI_CONTROL1 *const SPIControl1_3 = ADDR_SPI3_CONTROL1;
SPI_CONTROL2 *const SPIControl2_3 = ADDR_SPI3_CONTROL2; 
SPI_STATUS *const SPIStatus_3 = ADDR_SPI3_STATUS; 
SPI_DATA *const SPIData_3 = ADDR_SPI3_DATA; 


/**

SPI Clock:
        SPI1 Clock = PCLK2 (AKA: APB2 84 MHz)
        Baud Rate = PCLK2 / 2 = 42 MHz
**/
void SPI_ClockSetup(uint8_t spiNumber, E_Phase phase, E_Polarity polarity, E_Prescaler prescaler) {
	
	SPI_CONTROL1 *const SPIControl1 = Set_Control1Register(spiNumber);
	
	SPIControl1->enable_SPI = 0;
	SPIControl1->trans1ClockPhase0_trans2ClockPhase1 = 0;
	SPIControl1->clockPolarityLow0_clockPolarityHigh1 = 0;
	SPIControl1->rw_BaudRate = CLOCK_DIV_4;
}


void SPI_Init(uint8_t spiNumber, E_Mode mode, E_BitOrder bitOrder, uint8_t dataSize) {
	
	SPI_CONTROL1 *const SPIControl1 = Set_Control1Register(spiNumber);
	SPI_CONTROL2 *const SPIControl2 = Set_Control2Register(spiNumber); 
	
	SPI_PinInit(spiNumber);
	SPIClockSelect(spiNumber);
	
	SPIControl1->enable_SPI = 0;
	SPIControl1->slaveMode0_masterMode1 = 1;
	SPIControl1->msbFirst0_lsbFirst1 = 0;
	
	switch (dataSize) {
		
		case 8 :
			SPIControl1->dataFrame8Bit0_dataFrame16Bit1 = 0;
			break;
		case 16 :
			SPIControl1->dataFrame8Bit0_dataFrame16Bit1 = 1;
			break;
	}
	
	//Hardware NSS
	SPIControl2->enable_HardwareSlaveSelectAsOutput = 1;
	
	//Software NSS
	/* SPIControl1->enable_SoftwareSlaveSelect = 1; 
	SPIControl1->softwareNSSLow0_softwareNSSHigh1 = 0; 
	*/
	
	SPIControl1->enable_SPI = 1;
}


uint8_t SPI_Receive(uint8_t spiNumber) {
	
	SPI_STATUS *const SPIStatus = Set_StatusRegister(spiNumber); 
	SPI_DATA *const SPIData = Set_DataRegister(spiNumber); 
	
	while (SPIStatus->dataReadyToRead != 1);
	return SPIData->rw_Data;
} 


uint8_t SPI_Transmit(uint8_t spiNumber, uint8_t data) {

	SPI_STATUS *const SPIStatus = Set_StatusRegister(spiNumber); 
	SPI_DATA *const SPIData = Set_DataRegister(spiNumber); 
	
	while(SPIStatus->transferRegisterOpen != 1);
	SPIData->rw_Data = data;
	return 1;
} 


//Helper Functions--------------------------------------------------------------------------------------------------------------

/**
SPI Pins ---------------------------
		+ SPI1_NSS: PA4, PA15 (AF5)
		+ SPI1_SCK: PA5, PB3 (AF5)
		+ SPI1_MISO: PA6, PB4 (AF5)
		+ SPI1_MOSI: PA7, PB5 (AF5)
		
		+ SPI2_NSS: PB9, PB12, PI0 (AF5)
		+ SPI2_SCK: PB10, PB13, PI1 (AF5)
		+ SPI2_MISO: PB14, PC2, PI2 (AF5)
		+ SPI2_MOSI: PB15, PC3, PI3 (AF5)
		
		+ SPI3_NSS: PA4, PA15 (AF6)
		+ SPI3_SCK: PB3, PC10 (AF6)
		+ SPI3_MISO: PB4, PC11 (AF6)
		+ SPI3_MOSI: PB5, PC12 (AF6)
		------------------------------------
**/
static void SPI_PinInit(uint8_t spiNumber) {
	
	switch(spiNumber) {
		
		case 1 :
			//NSS
			Pin_Init('A', 4, AF5);
			//SCK
			Pin_Init('A', 5, AF5);
			//MISO
			Pin_Init('A', 6, AF5);
			//MOSI
			Pin_Init('A', 7, AF5);
			break;
		case 2 :
			//NSS
			Pin_Init('B', 9, AF5);
			//SCK
			Pin_Init('B', 10, AF5);
			//MISO
			Pin_Init('B', 14, AF5);
			//MOSI
			Pin_Init('B', 15, AF5);
			break;
		case 3 :
			//NSS
			Pin_Init('A', 4, AF6);
			//SCK
			Pin_Init('B', 3, AF6);
			//MISO
			Pin_Init('B', 4, AF6);
			//MOSI
			Pin_Init('B', 5, AF6);
			break;
	}
}

static void SPIClockSelect(uint8_t spiNumber) {
	
	switch(spiNumber) {
		
		case 1 :
			SPIClock->spi1_StartTick = 1;
			break;
		case 2 :
			SPIClock2_3->spi2_StartTick = 1;
			break;
		case 3 :
			SPIClock2_3->spi3_StartTick = 1;
			break;
	}
}

static SPI_CONTROL1* Set_Control1Register(uint8_t spiNumber) {
	
	switch(spiNumber) {
		
		case 1 :
			return SPIControl1_1;
		case 2 :
			return SPIControl1_2;
		case 3 :
			return SPIControl1_3;
		default :
			return NULL;
	}
}

static SPI_CONTROL2* Set_Control2Register(uint8_t spiNumber) {
	
	switch(spiNumber) {
		
		case 1 :
			return SPIControl2_1;
		case 2 :
			return SPIControl2_2;
		case 3 :
			return SPIControl2_3;
		default :
			return NULL;
	}
}

static SPI_STATUS* Set_StatusRegister(uint8_t spiNumber) {
	
	switch(spiNumber) {
		
		case 1 :
			return SPIStatus_1;
		case 2 :
			return SPIStatus_2;
		case 3 :
			return SPIStatus_3;
		default :
			return NULL;
	}
}

static SPI_DATA* Set_DataRegister(uint8_t spiNumber) {
	
	switch(spiNumber) {
		
		case 1 :
			return SPIData_1;
		case 2 :
			return SPIData_2;
		case 3 :
			return SPIData_3;
		default :
			return NULL;
	}
}
