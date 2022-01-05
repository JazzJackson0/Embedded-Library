//MSP430FR59xx Driver
#ifndef UART_H_
#define UART_H_

#include <stdint.h>

typedef enum _Parity E_Parity;
typedef enum _UARTBitOrder E_UARTBitOrder;
typedef enum _UARTClockSource E_UARTClockSource;

//DECLARATIONS
void USART_BaudRate_and_OverSample(char* uartNum, E_UARTClockSource clocksrc, uint32_t baudRate, uint8_t overSampleRate);
void UART_Init(char* uartNum, uint8_t numOfStopBits, uint8_t dataSize, E_Parity parityType, E_UARTBitOrder bitorder);
uint8_t UART_Receive(char* uartNum);
void UART_Transmit(char* uartNum, uint8_t data);

#define UART0 0x05C0  //These Base Addresses can be used by SPI as well
#define UART1 0x05E0 //These Base Addresses can be used by SPI as well

//UART0
#define ADDR_UART0_CONTROL_WORD0 ( (UART_CONTROL_WORD0*) ((UART0) + 0x00) )
#define ADDR_UART0_CONTROL_WORD1 ( (UART_CONTROL_WORD1*) ((UART0) + 0x02) )
#define ADDR_UART0_BAUDRATE_CONTROL_WORD ( (UART_BAUDRATE_CONTROL_WORD*) ((UART0) + 0x06) )
#define ADDR_UART0_MODULATION_CONTROL_WORD ( (UART_MODULATION_CONTROL_WORD*) ((UART0) + 0x08) )
#define ADDR_UART0_STATUS ( (UART_STATUS*) ((UART0) + 0x0A) )
#define ADDR_UART0_RECEIVE_BUFFER ( (UART_RECEIVE_BUFFER*) ((UART0) + 0x0C) )
#define ADDR_UART0_TRANSMIT_BUFFER ( (UART_TRANSMIT_BUFFER*) ((UART0) + 0x0E) )
#define ADDR_UART0_AUTO_BAUDRATE_CONTROL ( (UART_AUTO_BAUDRATE_CONTROL*) ((UART0) + 0x10) )
#define ADDR_UART0_IRDA_CONTROL_WORD ( (UART_IRDA_CONTROL_WORD*) ((UART0) + 0x12) )
#define ADDR_UART0_INTERRUPT_ENABLE ( (UART_INTERRUPT_ENABLE*) ((UART0) + 0x1A) )
#define ADDR_UART0_INTERRUPT_FLAG ( (UART_INTERRUPT_FLAG*) ((UART0) + 0x1C) )
#define ADDR_UART0_INTERRUPT_VECTOR ( (UART_INTERRUPT_VECTOR*) ((UART0) + 0x1E) )

//UART1
#define ADDR_UART1_CONTROL_WORD0 ( (UART_CONTROL_WORD0*) ((UART1) + 0x00) )
#define ADDR_UART1_CONTROL_WORD1 ( (UART_CONTROL_WORD1*) ((UART1) + 0x02) )
#define ADDR_UART1_BAUDRATE_CONTROL_WORD ( (UART_BAUDRATE_CONTROL_WORD*) ((UART1) + 0x06) )
#define ADDR_UART1_MODULATION_CONTROL_WORD ( (UART_MODULATION_CONTROL_WORD*) ((UART1) + 0x08) )
#define ADDR_UART1_STATUS ( (UART_STATUS*) ((UART1) + 0x0A) )
#define ADDR_UART1_RECEIVE_BUFFER ( (UART_RECEIVE_BUFFER*) ((UART1) + 0x0C) )
#define ADDR_UART1_TRANSMIT_BUFFER ( (UART_TRANSMIT_BUFFER*) ((UART1) + 0x0E) )
#define ADDR_UART1_AUTO_BAUDRATE_CONTROL ( (UART_AUTO_BAUDRATE_CONTROL*) ((UART1) + 0x10) )
#define ADDR_UART1_IRDA_CONTROL_WORD ( (UART_IRDA_CONTROL_WORD*) ((UART1) + 0x12) )
#define ADDR_UART1_INTERRUPT_ENABLE ( (UART_INTERRUPT_ENABLE*) ((UART1) + 0x1A) )
#define ADDR_UART1_INTERRUPT_FLAG ( (UART_INTERRUPT_FLAG*) ((UART1) + 0x1C) )
#define ADDR_UART1_INTERRUPT_VECTOR ( (UART_INTERRUPT_VECTOR*) ((UART1) + 0x1E) )

//UART_CONTROL_WORD0 Register
/*Asynchronous Mode Type*/
#define UART_MODE 0x00
#define IDLE_LINE_MULTIPROCESSOR 0x01
#define ADDRS_BIT_MULTIPROCESSOR 0x02
#define UART_AUTO_BAUDRATE_DETECT 0x03

//UART_CONTROL_WORD1
/*Deglitch Time*/
#define NS_2 0x00
#define NS_50 0x01
#define NS_100 0x02
#define NS_200 0x03

//UART_AUTO_BAUDRATE_CONTROL
/*Break and Sync Delimeter Length*/
#define BITTIME_1 0x00
#define BITTIME_2 0x01
#define BITTIME_3 0x02
#define BITTIME_4 0x03

//Enums----------------------------------------------------------------------
enum _Parity {
	EVEN_PARITY = 0,
	ODD_PARITY = 1,
	NO_PARITY = 2
};

enum _UARTBitOrder {
	_MSB = 0,
	_LSB = 1
};

//UART_CONTROL_WORD0 Register
/*Clock Source*/
enum _UARTClockSource {
	U_CLOCK = 0x00,
	A_CLOCK = 0x01,
	SM_CLOCK = 0x02
};

//Registers------------------------------------------------------------------
typedef struct {
	volatile uint16_t enable_SoftwareReset:1;
	volatile uint16_t transmit_Break:1;
	volatile uint16_t transmit_Address:1;
	volatile uint16_t enable_SleepMode:1;
	volatile uint16_t enable_ReceivedBreakCharInterrupt:1;
	volatile uint16_t enable_ReceivedErroneousCarInterrupt:1;
	volatile uint16_t select_ClockSource:2;
	volatile uint16_t enable_SynchronousMode:1;
	volatile uint16_t select_AsychronousModeType:2;
	volatile uint16_t oneStopBit0_twoStopBits1:1;
	volatile uint16_t data8Bit0_data7Bit1:1;
	volatile uint16_t lsbFirst0_msbFirst1:1;
	volatile uint16_t oddParity0_evenParity1:1;
	volatile uint16_t enable_Parity:1;
}UART_CONTROL_WORD0;

typedef struct {
	volatile uint16_t rw_DeglitchTime:2;
	const uint16_t reserved:14;
}UART_CONTROL_WORD1;

typedef struct {
	volatile uint16_t rw_BaudRateClockPrescaler:16;
}UART_BAUDRATE_CONTROL_WORD;

typedef struct {
	volatile uint16_t enable_OversamplingMode:1;
	const uint16_t reserved:3;
	volatile uint16_t rw_FirstModulationSatge:4;
	volatile uint16_t rw_SecondModulationStage:8;
}UART_MODULATION_CONTROL_WORD;

typedef struct {
	volatile uint16_t usartBusy:1;
	volatile uint16_t dataReceivedNoIdle0_addrsReceivedIdleDetected1:1;
	volatile uint16_t receiveErrorDetected:1;
	volatile uint16_t breakConditionOccurred:1;
	volatile uint16_t parityErrorOccurred:1;
	volatile uint16_t overrunErrorOccurred:1;
	volatile uint16_t framingErrorOccurred:1;
	volatile uint16_t enable_LoopbackMode:1;
	const uint16_t reserved:8;
}UART_STATUS;

typedef struct {
	volatile uint16_t read_DataReceived:8;
	const uint16_t reserved:8;
}UART_RECEIVE_BUFFER;

typedef struct {
	volatile uint16_t rw_DataToTransmit:8;
	const uint16_t reserved:8;
}UART_TRANSMIT_BUFFER;

typedef struct {
	volatile uint16_t enable_AutoBaudRateDetect:1;
	const uint16_t reserved0:1;
	volatile uint16_t breakTimeoutErrorOccurred:1;
	volatile uint16_t syncFieldTimeoutErrorOccurred:1;
	volatile uint16_t rw_BreakAndSyncDelimeterLength:2;
	const uint16_t reserved1:10;
}UART_AUTO_BAUDRATE_CONTROL;

typedef struct {
	volatile uint16_t enable_IrDAEncoderDecoder:1;
	volatile uint16_t enable_BITCLK16ForOversampleMode:1;
	volatile uint16_t rw_TransmitPulseLength:6;
	volatile uint16_t enable_IrDAReceiveFilter:1;
	volatile uint16_t txHighPulseOnLightPulse0_txLowPulseOnLightPulse1:1;
	volatile uint16_t rw_ReceiveFilterLength:6;
}UART_IRDA_CONTROL_WORD;

typedef struct {
	volatile uint16_t enable_ReceiveInterrupt:1;
	volatile uint16_t enable_TransmitInterrupt:1;
	volatile uint16_t enable_StartBitInterrupt:1;
	volatile uint16_t enable_TransmitCompleteInterrupt:1;
	const uint16_t reserved:12;
}UART_INTERRUPT_ENABLE;

typedef struct {
	volatile uint16_t receiveInterruptOccurred:1;
	volatile uint16_t transmitInterruptOccurred:1;
	volatile uint16_t startBitInterruptOccurred:1;
	volatile uint16_t transmitCompleteInterruptOccurred:1;
	const uint16_t reserved:12;
}UART_INTERRUPT_FLAG;

typedef struct {
	volatile uint16_t read_HighestPriorityInterruptPending:1;
}UART_INTERRUPT_VECTOR;

#endif
