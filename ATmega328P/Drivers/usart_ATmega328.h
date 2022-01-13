//ATmega328/P Driver
#ifndef USART_H_
#define USART_H_

/*USART Pins ---------------------------
		+ USART External Clock (Input/Output): PD4
		+ USART TX Pin: PD1
		+ USART RX Pin: PD0
		------------------------------------*/

#include <stdint.h>

typedef enum _USARTPolarity E_USARTPolarity;
typedef enum _Parity E_Parity;
typedef enum _USARTMode E_USARTMode;

//DECLARATIONS
void USART_Init(E_USARTMode mode, E_Parity parity, E_USARTPolarity polarity, uint8_t dataSize, uint8_t numOfStopBits);
uint8_t USART_Receive(void);
void USART_Transmit(uint8_t data);

//USART (Powered by AVR Clock Control Unit)
typedef struct _usart USARTx;
#define ATMEGA_BASEADDRESS 0x0000
#define ADDR_POWER_REDUCTION_USART ( (POWER_REDUCTION_USART*) ((ATMEGA_BASEADDRESS) + 0x64) ) //Found in Power Management Section
#define ADDR_USART ( (USARTx*) ((ATMEGA_BASEADDRESS) + 0xC0) )



/*Clock Speeds & Baud Rates for USART_BAUDRATE LOW & HIGH Calculations*/
/*Clock Speeds*/
#define ATMEGA_DEFAULT_CLOCK_SPEED 1000000ULL //1MHz (8MHz RC Prescaled to 1MHz)
#define UNO_DEFAULT_CLOCK_SPEED 16000000ULL //16MHz (External Crystal Osc)
#define CLOCK_SPEED (UNO_DEFAULT_CLOCK_SPEED)
/*Baud Rates*/
#define BAUD2400 2400ULL
#define BAUD4800 4800ULL
#define BAUD9600 9600ULL
#define BAUD14400 14400ULL
#define BAUD19200 19200ULL
#define BAUD38400 38400ULL
#define BAUD57600 57600ULL
#define BAUD115200 115200ULL
#define BAUD128000 128000ULL
#define BAUD256000 256000ULL
#define BAUDx BAUD9600 //Attatch Desired Baudrate to BAUDx

//USART_BAUDRATE LOW & HIGH
/*- Arduino Uno Clock Speed
		+ATmega defaults to 8MHz RC Prescaled to 1MHz
		+Arduino Uno Board overrides ATmega and defaults to 16MHz external xtal oscillator
*/
#define ASYNC_NORMAL_MODE ((CLOCK_SPEED / (16 * BAUDx)) - 1)
#define ASYNC_DOUBLESPEED_MODE ((CLOCK_SPEED / (8 * BAUDx)) - 1)
#define SYNC_MASTER_MODE ((CLOCK_SPEED / (2 * BAUDx)) - 1)

//USART_CONTROL_STATUS_B
/*Data Frame Size Part 2*/
#define _5_BIT_PART2 0x00
#define _6_BIT_PART2 0x00
#define _7_BIT_PART2 0x00
#define _8_BIT_PART2 0x00
#define _9_BIT_PART2 0x01

//USART_CONTROL_STATUS_C
/*Data Frame Size Part 1*/
#define _5_BIT_PART1 0x00
#define _6_BIT_PART1 0x01
#define _7_BIT_PART1 0x02
#define _8_BIT_PART1 0x03
#define _9_BIT_PART1 0x03

//Enums----------------------------------------------------------------------
enum _USARTPolarity {
	TX_ONRISE_RX_ONFALL = 0,
	TX_ONFALL_RX_ONRISE = 1
};

//USART_CONTROL_STATUS_C
/*Parity Modes*/
enum _Parity {
	EVEN_PAR = 0x02,
	ODD_PAR = 0x03
};

/*UART Mode Types*/
enum _USARTMode {
	ASYNC = 0x00,
	SYNC = 0x01,
	MASTER_SPI = 0x02
};

//Registers------------------------------------------------------------------
typedef struct {
    const uint8_t reserved0:1;
    volatile uint8_t usartOn0_usartOff1:1;
    const uint8_t reserved1:6;
}POWER_REDUCTION_USART;

typedef struct {
	const uint8_t reserved:8;
}USART_RESERVED;

typedef struct {
	volatile uint8_t dataReceived_dataToSend:8;
}USART_IO_DATA;

typedef struct {
	volatile uint8_t enable_MultiProcessorCommMode:1;
	volatile uint8_t doubleTransmissionSpeed:1;
	volatile uint8_t parityErrorOccurred:1;
	volatile uint8_t dataOverrunOccurred:1;
	volatile uint8_t frameErrorOccurred:1;
	volatile uint8_t readyToTransmit:1;
	volatile uint8_t transmissionComplete:1;
	volatile uint8_t dataReadyToRead:1;
}USART_CONTROL_STATUS_A;

typedef struct {
	volatile uint8_t transmit_9thDataBit:1;
	volatile uint8_t read_Received9thDataBit:1;
	volatile uint8_t rw_dataFrameSizePart2:1; //Macro Available
	volatile uint8_t enable_Transmitter:1;
	volatile uint8_t enable_Receiver:1;
	volatile uint8_t enable_DataRegisterEmptyInterrupt:1;
	volatile uint8_t enable_TXCompleteInterrupt:1;
	volatile uint8_t enable_RXCompleteInterrupt:1;
}USART_CONTROL_STATUS_B;

typedef struct {
	volatile uint8_t polarity_TXRiseRXFall0_TXFallRXRise1:1;
	volatile uint8_t rw_dataFrameSizePart1:2;
	volatile uint8_t oneStopBit0_twoStopBits1:1;
	volatile uint8_t rw_ParityMode:2;
	volatile uint8_t rw_ModeSelect:2;
}USART_CONTROL_STATUS_C;

typedef struct {
	volatile uint8_t rw_BaudRateLow:8;
}USART_BAUDRATE_LOW;

typedef struct {
	volatile uint8_t rw_BaudRateHigh:4;
	const uint8_t reserved:4;
}USART_BAUDRATE_HIGH;


struct _usart {
	USART_CONTROL_STATUS_A StatusAReg; // 0xC0
	USART_CONTROL_STATUS_B StatusBReg; // 0xC1
	USART_CONTROL_STATUS_C StatusCReg; // 0xC2
	USART_RESERVED reserved; // 0xC3
	USART_BAUDRATE_LOW BaudRateLowReg; // 0xC4
	USART_BAUDRATE_HIGH BaudRateHighReg; // 0xC5
	USART_IO_DATA IODataReg; // 0xC6
};

#endif
