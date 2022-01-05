//MSP430FR59xx Driver
#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>

typedef enum _SPIClockSource E_SPIClockSource;
typedef enum _SPIMode E_SPIMode;
typedef enum _BitOrder E_BitOrder;
typedef enum _Phase E_Phase;
typedef enum _Polarity E_Polarity;

void SPI_ClockSetup(char* spiNumber, E_SPIClockSource clockSrc, uint16_t clockDivide, E_Phase phase, E_Polarity polarity);
void SPI_Init(char* spiNumber, E_SPIMode mode, E_BitOrder bitOrder, uint8_t dataSize);
uint8_t SPI_Transmit_and_Receive(char* spiNumber, uint8_t data);
uint8_t SPI_Receive(char* spiNumber);

#define SPI_A0 0x05C0  //These Base Addresses can be used by UART as well??
#define SPI_A1 0x05E0 //These Base Addresses can be used by UART as well??
#define SPI_B0 0x00 //WHERE IS THIS ADDRESS??? 

//SPI_A0
#define ADDR_SPI_A0_CONTROL ( (SPI_CONTROL*) ((SPI_A0) + 0x00) )
#define ADDR_SPI_A0_BITRATE_CONTROL ( (SPI_BITRATE_CONTROL*) ((SPI_A0) + 0x06) )
#define ADDR_SPI_A0_STATUS ( (SPI_STATUS*) ((SPI_A0) + 0x0A) )
#define ADDR_SPI_A0_RECEIVE_BUFFER ( (SPI_RECEIVE_BUFFER*) ((SPI_A0) + 0x0C) )
#define ADDR_SPI_A0_TRANSMIT_BUFFER ( (SPI_TRANSMIT_BUFFER*) ((SPI_A0) + 0x0E) )
#define ADDR_SPI_A0_INTERRUPT_ENABLE ( (SPI_INTERRUPT_ENABLE*) ((SPI_A0) + 0x1A) )
#define ADDR_SPI_A0_INTERRUPT_FLAG ( (SPI_INTERRUPT_FLAG*) ((SPI_A0) + 0x1C) )
#define ADDR_SPI_A0_INTERRUPT_VECTOR ( (SPI_INTERRUPT_VECTOR*) ((SPI_A0) + 0x1E) )

//SPI_A1
#define ADDR_SPI_A1_CONTROL ( (SPI_CONTROL*) ((SPI_A1) + 0x00) )
#define ADDR_SPI_A1_BITRATE_CONTROL ( (SPI_BITRATE_CONTROL*) ((SPI_A1) + 0x06) )
#define ADDR_SPI_A1_STATUS ( (SPI_STATUS*) ((SPI_A1) + 0x0A) )
#define ADDR_SPI_A1_RECEIVE_BUFFER ( (SPI_RECEIVE_BUFFER*) ((SPI_A1) + 0x0C) )
#define ADDR_SPI_A1_TRANSMIT_BUFFER ( (SPI_TRANSMIT_BUFFER*) ((SPI_A1) + 0x0E) )
#define ADDR_SPI_A1_INTERRUPT_ENABLE ( (SPI_INTERRUPT_ENABLE*) ((SPI_A1) + 0x1A) )
#define ADDR_SPI_A1_INTERRUPT_FLAG ( (SPI_INTERRUPT_FLAG*) ((SPI_A1) + 0x1C) )
#define ADDR_SPI_A1_INTERRUPT_VECTOR ( (SPI_INTERRUPT_VECTOR*) ((SPI_A1) + 0x1E) )

//SPI_B0 (NOT CORRECT ADDRESSES. THIS IS CURRENTLY JUST A COPY OF A1)
#define ADDR_SPI_B0_CONTROL ( (SPI_CONTROL*) ((SPI_B0) + 0x00) )
#define ADDR_SPI_B0_BITRATE_CONTROL ( (SPI_BITRATE_CONTROL*) ((SPI_B0) + 0x06) )
#define ADDR_SPI_B0_STATUS ( (SPI_STATUS*) ((SPI_B0) + 0x0A) )
#define ADDR_SPI_B0_RECEIVE_BUFFER ( (SPI_RECEIVE_BUFFER*) ((SPI_B0) + 0x0C) )
#define ADDR_SPI_B0_TRANSMIT_BUFFER ( (SPI_TRANSMIT_BUFFER*) ((SPI_B0) + 0x0E) )
#define ADDR_SPI_B0_INTERRUPT_ENABLE ( (SPI_INTERRUPT_ENABLE*) ((SPI_B0) + 0x1A) )
#define ADDR_SPI_B0_INTERRUPT_FLAG ( (SPI_INTERRUPT_FLAG*) ((SPI_B0) + 0x1C) )
#define ADDR_SPI_B0_INTERRUPT_VECTOR ( (SPI_INTERRUPT_VECTOR*) ((SPI_B0) + 0x1E) )

/*Synchronous Mode Type*/
#define SPI_3PIN 0x00
#define SPI_4PIN_SS_HIGH 0x01
#define SPI_4PIN_SS_LOW 0x02

//Enums----------------------------------------------------------------------
//SPI_CONTROL Register
/*Clock Source*/
enum _SPIClockSource {
	SLAVE_UCxCLK_SPI = 0x00,
	MASTER_ACLK_SPI = 0x01,
	MASTER_SMCLK_SPI = 0x02
};

enum _SPIMode {
	SPI_SLAVE = 0,
	SPI_MASTER = 1
};

enum _BitOrder {
	MSB = 1,
	LSB = 0
};

enum _Phase {
	_1ST_EDGE = 1,
	_2ND_EDGE = 0
};

enum _Polarity {
	LOW_POL = 0,
	HIGH_POL = 1
};

//Registers------------------------------------------------------------------
typedef struct {
	volatile uint16_t enable_SoftwareReset:1;
	volatile uint16_t ssPinForArbitration0_ssPinForSlaveEnable1:1;
	const uint16_t reserved:4;
	volatile uint16_t select_ClockSource:2;
	volatile uint16_t enable_SynchronousMode:1;
	volatile uint16_t rw_SynchronousModeType:2;
	volatile uint16_t slaveMode0_masterMode1:1;
	volatile uint16_t data8Bit0_data7Bit1:1;
	volatile uint16_t lsbFirst0_msbFirst1:1;
	volatile uint16_t clockPolarityLow0_clockPolarityHigh1:1;
	volatile uint16_t clockPhase2ndEdge0_clockPhase1stEdge1:1;
}SPI_CONTROL;

typedef struct {
	volatile uint16_t rw_BitClockPrescalerValue:16;
}SPI_BITRATE_CONTROL;

typedef struct {
	volatile uint16_t spiBusy:1;
	const uint16_t reserved0:4;
	volatile uint16_t overrunErrorOccurred:1;
	volatile uint16_t busConflictOccurred:1;
	volatile uint16_t enable_LoopbackMode:1;
	const uint16_t reserved1:8;
}SPI_STATUS;

typedef struct {
	volatile uint16_t read_DataReceived:8;
	const uint16_t reserved:8;
}SPI_RECEIVE_BUFFER;

typedef struct {
	volatile uint16_t rw_DataToTransmit:8;
	const uint16_t reserved:8;
}SPI_TRANSMIT_BUFFER;

typedef struct {
	volatile uint16_t receiveInterruptEnabled:1;
	volatile uint16_t transmitInterruptEnabled:1;
	const uint16_t reserved:14;
}SPI_INTERRUPT_ENABLE;

typedef struct {
	volatile uint16_t receiveInterruptOccurred:1;
	volatile uint16_t transmitInterruptOccurred:1;
	const uint16_t reserved:14;
}SPI_INTERRUPT_FLAG;

typedef struct {
	volatile uint16_t read_HighestPriorityInterruptPending:16;
}SPI_INTERRUPT_VECTOR;

#endif
