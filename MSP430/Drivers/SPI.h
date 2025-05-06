//MSP430FR59xx Driver
#ifndef SPI_H_
#define SPI_H_
#include <stdint.h>
#include "DigitalIO.h"


typedef enum _SPIClockSource E_SPIClockSource;
typedef enum _SPIMode E_SPIMode;
typedef enum _BitOrder E_BitOrder;
typedef enum _Phase E_Phase;
typedef enum _Polarity E_Polarity;

//DECLARATIONS
/**
 * @brief Setup the SPI Clock Source, Speed, Phase and Polarity.
 *
 * @param spiNumber SPI Number (A0-A1, B0)
 * @param clockSrc Clock Source: (SLAVE_UCxCLK_SPI, MASTER_ACLK_SPI, MASTER_SMCLK_SPI) 
 * 						|||  SMCLK & MCLK = DCOCLK(1MHz) / 8  = 125KHz 
 * 						|||  According to '3.2 Clock System Operation'
 * @param clockDivide Bit Clock (fbitclock) Prescaler Value
 * @param phase Clock Phase: _1ST_EDGE or _2ND_EDGE
 * @param polarity Clock Polarity: HIGH_POL or LOW_POL
 * @return ** void 
 */
void SPI_ClockSetup(char* spiNumber, E_SPIClockSource clockSrc, uint16_t clockDivide, E_Phase phase, E_Polarity polarity);
/**
 * @brief Initialize SPI
 * 
 * @param spiNumber SPI Number (A0-A1, B0)
 * @param mode SPI Mode: SPI_MASTER or SPI_SLAVE
 * @param bitOrder Order of Bits: LSB odr MSB
 * @param dataSize Size of Data: 7-Bit or 8-Bit
 * @return ** void 
 */
void SPI_Init(char* spiNumber, E_SPIMode mode, E_BitOrder bitOrder, uint8_t dataSize);
/**
 * @brief Transmit and receive data via SPI
 * 
 * @param spiNumber SPI Number (A0-A1, B0)
 * @param data Data to transmit |||  To just receive, input 0x00 for data.
 * @return ** uint8_t Data Received
 */
uint8_t SPI_Transmit_and_Receive(char* spiNumber, uint8_t data);

//SPI
typedef struct _spi SPIx;
#define SPI_BASE 0x0500
#define ADDR_SPI_A0 ( (SPIx*) ((SPI_BASE) + 0xC0) ) // Base Addresses shared with UART
#define ADDR_SPI_A1 ( (SPIx*) ((SPI_BASE) + 0xE0) ) // Base Addresses shared with UART
#define ADDR_SPI_B0 ( (SPIx*) ((SPI_BASE) + 0x00) ) // WHERE IS THIS ADDRESS??? 

/*Synchronous Mode Type*/
#define SPI_3PIN 0x00
#define SPI_4PIN_SS_HIGH 0x01
#define SPI_4PIN_SS_LOW 0x02

//Enums----------------------------------------------------------------------
//SPI_CONTROL Register
/*Clock Source*/
enum _SPIClockSource {
	SLAVE_UCxCLK_SPI = 0x00, MASTER_ACLK_SPI = 0x01,
	MASTER_SMCLK_SPI = 0x02
};

enum _SPIMode {
	SPI_SLAVE = 0, SPI_MASTER = 1
};

enum _BitOrder {
	MSB = 1, LSB = 0
};

enum _Phase {
	_1ST_EDGE = 1, _2ND_EDGE = 0
};

enum _Polarity {
	LOW_POL = 0, HIGH_POL = 1
};

//Registers------------------------------------------------------------------
typedef struct {
	const uint16_t reserved:16;
}SPI_RESERVED;

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

struct _spi {
	SPI_CONTROL ControlReg; // 0x00
	SPI_RESERVED reserved0; // 0x02
	SPI_RESERVED reserved1; // 0x04
	SPI_BITRATE_CONTROL BitRateControlReg; // 0x06
	SPI_RESERVED reserved2; // 0x08
	SPI_STATUS StatusReg; // 0x0A
	SPI_RECEIVE_BUFFER RXBufferReg; // 0x0C
	SPI_TRANSMIT_BUFFER TXBufferReg; // 0x0E
	SPI_RESERVED reserved3; // 0x10
	SPI_RESERVED reserved4; // 0x12
	SPI_RESERVED reserved5; // 0x14
	SPI_RESERVED reserved6; // 0x16
	SPI_RESERVED reserved7; // 0x18
	SPI_INTERRUPT_ENABLE InterruptEnableReg; // 0x1A
	SPI_INTERRUPT_FLAG InterruptFlagReg; // 0x1C
	SPI_INTERRUPT_VECTOR InterruptVectorReg; // 0x1E
};

#endif
