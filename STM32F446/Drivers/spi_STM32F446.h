//STM32F446 Driver
#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>

typedef enum _Phase E_Phase;
typedef enum _Polarity E_Polarity;
typedef enum _Prescaler E_Prescaler;
typedef enum _Mode E_Mode;
typedef enum _BitOrder E_BitOrder;

void SPI_ClockSetup(uint8_t spiNumber, E_Phase phase, E_Polarity polarity, E_Prescaler prescaler);
void SPI_Init(uint8_t spiNumber, E_Mode mode, E_BitOrder bitOrder, uint8_t dataSize);
uint8_t SPI_Receive(uint8_t spiNumber);
uint8_t SPI_Transmit(uint8_t spiNumber, uint8_t data);

#define CLOCK 0x40023800
#define APB2 0x44
#define APB1 0x40
#define SPI1 0x40013000
#define SPI2_I2S2 0x40003800
#define SPI3_I2S3 0x40003C00
#define SPI4 0x40013400

//CLOCK
#define ADDR_SPI_CLOCK_1 ( (SPI_CLOCK_1*) ((CLOCK) + APB2) )
#define ADDR_SPI_CLOCK_2_3 ( (SPI_CLOCK_2_3*) ((CLOCK) + APB1) )

//SPI 1
#define ADDR_SPI1_CONTROL1 ( (SPI_CONTROL1*) ((SPI1) + 0x00) )
#define ADDR_SPI1_CONTROL2 ( (SPI_CONTROL2*) ((SPI1) + 0x04) )
#define ADDR_SPI1_STATUS ( (SPI_STATUS*) ((SPI1) + 0x08) )
#define ADDR_SPI1_DATA ( (SPI_DATA*) ((SPI1) + 0x0C) )
#define ADDR_SPI1_CRC_POLYNOMIAL ( (SPI_CRC_POLYNOMIAL*) ((SPI1) + 0x10) )
#define ADDR_SPI1_RX_CRC ( (SPI_RX_CRC*) ((SPI1) + 0x14) )
#define ADDR_SPI1_TX_CRC ( (SPI_TX_CRC*) ((SPI1) + 0x18) )
#define ADDR_SPI1_I2S_CONFIG ( (SPI_I2S_CONFIG*) ((SPI1) + 0x1C) )
#define ADDR_SPI1_I2S_PRESCALER ( (SPI_I2S_PRESCALER*) ((SPI1) + 0x20) )

//SPI 2 / I2S 2
#define ADDR_SPI2_CONTROL1 ( (SPI_CONTROL1*) ((SPI2_I2S2) + 0x00) )
#define ADDR_SPI2_CONTROL2 ( (SPI_CONTROL2*) ((SPI2_I2S2) + 0x04) )
#define ADDR_SPI2_STATUS ( (SPI_STATUS*) ((SPI2_I2S2) + 0x08) )
#define ADDR_SPI2_DATA ( (SPI_DATA*) ((SPI2_I2S2) + 0x0C) )
#define ADDR_SPI2_CRC_POLYNOMIAL ( (SPI_CRC_POLYNOMIAL*) ((SPI2_I2S2) + 0x10) )
#define ADDR_SPI2_RX_CRC ( (SPI_RX_CRC*) ((SPI2_I2S2) + 0x14) )
#define ADDR_SPI2_TX_CRC ( (SPI_TX_CRC*) ((SPI2_I2S2) + 0x18) )
#define ADDR_SPI2_I2S_CONFIG ( (SPI_I2S_CONFIG*) ((SPI2_I2S2) + 0x1C) )
#define ADDR_SPI2_I2S_PRESCALER ( (SPI_I2S_PRESCALER*) ((SPI2_I2S2) + 0x20) )

//SPI 3 / I2S 3
#define ADDR_SPI3_CONTROL1 ( (SPI_CONTROL1*) ((SPI3_I2S3) + 0x00) )
#define ADDR_SPI3_CONTROL2 ( (SPI_CONTROL2*) ((SPI3_I2S3) + 0x04) )
#define ADDR_SPI3_STATUS ( (SPI_STATUS*) ((SPI3_I2S3) + 0x08) )
#define ADDR_SPI3_DATA ( (SPI_DATA*) ((SPI3_I2S3) + 0x0C) )
#define ADDR_SPI3_CRC_POLYNOMIAL ( (SPI_CRC_POLYNOMIAL*) ((SPI3_I2S3) + 0x10) )
#define ADDR_SPI3_RX_CRC ( (SPI_RX_CRC*) ((SPI3_I2S3) + 0x14) )
#define ADDR_SPI3_TX_CRC ( (SPI_TX_CRC*) ((SPI3_I2S3) + 0x18) )
#define ADDR_SPI3_I2S_CONFIG ( (SPI_I2S_CONFIG*) ((SPI3_I2S3) + 0x1C) )
#define ADDR_SPI3_I2S_PRESCALER ( (SPI_I2S_PRESCALER*) ((SPI3_I2S3) + 0x20) )

//SPI 4
#define ADDR_SPI4_CONTROL1 ( (SPI_CONTROL1*) ((SPI4) + 0x00) )
#define ADDR_SPI4_CONTROL2 ( (SPI_CONTROL2*) ((SPI4) + 0x04) )
#define ADDR_SPI4_STATUS ( (SPI_STATUS*) ((SPI4) + 0x08) )
#define ADDR_SPI4_DATA ( (SPI_DATA*) ((SPI4) + 0x0C) )
#define ADDR_SPI4_CRC_POLYNOMIAL ( (SPI_CRC_POLYNOMIAL*) ((SPI4) + 0x10) )
#define ADDR_SPI4_RX_CRC ( (SPI_RX_CRC*) ((SPI4) + 0x14) )
#define ADDR_SPI4_TX_CRC ( (SPI_TX_CRC*) ((SPI4) + 0x18) )
#define ADDR_SPI4_I2S_CONFIG ( (SPI_I2S_CONFIG*) ((SPI4) + 0x1C) )
#define ADDR_SPI4_I2S_PRESCALER ( (SPI_I2S_PRESCALER*) ((SPI4) + 0x20) )


//SPI_I2S_CONFIG Register
/*Len Of Transfer Data*/
#define LEN_16BIT 0x00
#define LEN_24BIT 0x01
#define LEN_32BIT 0x02


/*I2S Standards*/
#define PHILLIPS_STANDARD 0x00
#define MSB_JUSTIFIED_STANDARD 0x01
#define LSB_JUSTIFIED_STANDARD 0x02
#define PCM_STANDARD 0x03

/*I2S Config Modes*/
#define SLAVE_TRANSMIT 0x00
#define SLAVE_RECEIVE 0x01
#define MASTER_TRANSMIT 0x02
#define MASTER_RECEIVE 0x03

//Enums----------------------------------------------------------------------
enum _Phase {
	_1ST_EDGE = 0,
	_2ND_EDGE = 1
};

enum _Polarity {
	LOW_POL = 0,
	HIGH_POL = 1
};

//SPI_CONTROL1 Register
/*Baud Rate*/
enum _Prescaler {
	CLOCK_DIV_2 = 0x00,
	CLOCK_DIV_4 = 0x01,
	CLOCK_DIV_8 = 0x02,
	CLOCK_DIV_16 = 0x03,
	CLOCK_DIV_32 = 0x04,
	CLOCK_DIV_64 = 0x05,
	CLOCK_DIV_128 = 0x06,
	CLOCK_DIV_256 = 0x07
};

enum _Mode {
	SLAVE = 0,
	MASTER = 1
};

enum _BitOrder {
	MSB = 0,
	LSB = 1
};

//Registers------------------------------------------------------------------
typedef struct {
	const uint32_t reserved0:12;
	volatile uint32_t spi1_StartTick:1;
	const uint32_t reserved1:19;
}SPI_CLOCK_1;

typedef struct {
	const uint32_t reserved0:14;
	volatile uint32_t spi2_StartTick:1;
	volatile uint32_t spi3_StartTick:1;
	const uint32_t reserved1:16;
}SPI_CLOCK_2_3;

typedef struct {
	volatile uint16_t trans1ClockPhase0_trans2ClockPhase1:1;
	volatile uint16_t clockPolarityLow0_clockPolarityHigh1:1;
	volatile uint16_t slaveMode0_masterMode1:1;
	volatile uint16_t rw_BaudRate:3;
	volatile uint16_t enable_SPI:1;
	volatile uint16_t msbFirst0_lsbFirst1:1;
	volatile uint16_t softwareNSSLow0_softwareNSSHigh1:1;
	volatile uint16_t enable_SoftwareSlaveSelect:1;
	volatile uint16_t disable_Output:1;
	volatile uint16_t dataFrame8Bit0_dataFrame16Bit1:1;
	volatile uint16_t transfer_CRC:1;
	volatile uint16_t enable_CRCCalculation:1;
	volatile uint16_t enable_Output:1;
	volatile uint16_t uniDirect2Line0_BiDirect1Line1:1;
}SPI_CONTROL1;

typedef struct {
	volatile uint16_t enable_RXBufferDMA:1;
	volatile uint16_t enable_TXBufferDMA:1;
	volatile uint16_t enable_HardwareSlaveSelectAsOutput:1;
	const uint32_t reserved0:1;
	volatile uint16_t motorolaMode0_tiMode1:1;
	volatile uint16_t enable_ErrorInterrupt:1;
	volatile uint16_t enable_dataReadyToReadInterrupt:1;
	volatile uint16_t enable_transferRegisterOpenInterrupt:1;
	const uint32_t reserved1:8;
}SPI_CONTROL2;

typedef struct {
	volatile uint16_t dataReadyToRead:1;
	volatile uint16_t transferRegisterOpen:1;
	volatile uint16_t channelLeftTXRX0_channelRightTXRX1:1;
	volatile uint16_t underrunOccurred:1;
	volatile uint16_t crcErrorOccurred:1;
	volatile uint16_t modeFaultOccurred:1;
	volatile uint16_t overrunOccurred:1;
	volatile uint16_t spiBusy:1;
	volatile uint16_t frameFormatErrorOccurred:1;
	const uint16_t reserved:7;
}SPI_STATUS;

typedef struct {
	volatile uint16_t rw_Data:16;
}SPI_DATA;

typedef struct {
	volatile uint16_t rw_CRCPolynomial:16;
}SPI_CRC_POLYNOMIAL;

typedef struct {
	volatile uint16_t read_CRC:16;
}SPI_RX_CRC;

typedef struct {
	volatile uint16_t write_CRC:16;
}SPI_TX_CRC;

typedef struct {
	volatile uint16_t channelLen16Bit0_channelLen32Bit1:1;
	volatile uint16_t rw_LengthOfTransferData:2;
	volatile uint16_t clockPolarityLow0_clockPolarityHigh1:1;
	volatile uint16_t rw_I2SStandard:2;
	const uint16_t reserved0:1;
	volatile uint16_t shortFrameSync0_longFrameSync1:1;
	volatile uint16_t rw_I2SMode:2;
	volatile uint16_t enable_I2SPeripheral:1;
	volatile uint16_t enable_I2SMode:1;
	volatile uint16_t enable_AsynchronousStart:1;
	const uint16_t reserved1:3;
}SPI_I2S_CONFIG;

typedef struct {
	volatile uint16_t rw_I2SLinearPrescaler:8;
	volatile uint16_t enable_OddPrescaler:1;
	volatile uint16_t enable_MasterClockOutput:1;
	const uint16_t reserved:6;
}SPI_I2S_PRESCALER;

#endif
