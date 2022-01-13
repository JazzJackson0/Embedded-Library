//ATmega328/P Driver
#ifndef SPI_H_
#define SPI_H_

/*SPI Pins ---------------------------------
		+ SS0: PB2
		+ MOSI0: PB3
		+ MISO0: PB4
		+ SCK0: PB5
		------------------------------------*/

#include <stdint.h>

typedef enum _ClockDivider E_ClockDivider;
typedef enum _SPIMode E_SPIMode;
typedef enum _BitOrder E_BitOrder;
typedef enum _Phase E_Phase;
typedef enum _SPIPolarity E_SPIPolarity;

//DECLARATIONS
void SPI_ClockSetup(E_ClockDivider clockDiv, E_Phase phase, E_SPIPolarity polarity);
void SPI_Init(E_SPIMode mode, E_BitOrder bitOrder);
uint8_t SPI_Transmit_and_Receive(uint8_t data);

//SPI (Powered by AVR Clock Control Unit)
typedef struct _spi SPIx;
#define ATMEGA_BASEADDRESS 0x0000
#define ADDR_POWER_REDUCTION_SPI ( (POWER_REDUCTION_SPI*) ((ATMEGA_BASEADDRESS) + 0x64) ) //Found in Power Management Section
#define ADDR_SPI ( ( SPIx*) ((ATMEGA_BASEADDRESS) + 0x4C) )

//Enums----------------------------------------------------------------------
//SPI_CONTROL Register
/*Clock Frequency*/
enum _ClockDivider {
	SPI_DIV_4 = 0x00,
	SPI_DIV_16 = 0x01,
	SPI_DIV_64 = 0x02,
	SPI_DIV_128 = 0x03
};

enum _SPIMode {
	SLAVE = 0,
	MASTER = 1
};

enum _BitOrder {
	MSB = 1,
	LSB = 0
};

enum _Phase {
	_1ST_EDGE = 0,
	_2ND_EDGE = 1
};

enum _SPIPolarity {
	LOW_POL = 0,
	HIGH_POL = 1
};

//Registers------------------------------------------------------------------
typedef struct {
    const uint8_t reserved0:2;
    volatile uint8_t spiOn0_spiOff1:1;
    const uint8_t reserved1:5;
}POWER_REDUCTION_SPI;

typedef struct {
	volatile uint8_t rw_SPIClockFrequency:2;
	volatile uint8_t clockPhase1stEdge0_clockPhaseSecondEdge1:1;
	volatile uint8_t clockPolarityLow0_clockPolarityHigh1:1;
	volatile uint8_t slaveMode0_masterMode1:1;
	volatile uint8_t msbFirst0_lsbFirst1:1;
	volatile uint8_t enable_SPI:1;
	volatile uint8_t enable_SPIInterrupt:1;
}SPI_CONTROL;

typedef struct {
	volatile uint8_t enable_DoubleSPISpeed:1;
	const uint8_t reserved:5;
	volatile uint8_t writeCollisionOccurred:1;
	volatile uint8_t spiInterruptOccurred:1;
}SPI_STATUS;

typedef struct {
	volatile uint8_t readData_writeData:8;
}SPI_DATA;

struct _spi {
	SPI_CONTROL ControlReg; // 0x4C
	SPI_STATUS StatusReg; // 0x4D
	SPI_DATA DataReg; // 0x4E
};

#endif
