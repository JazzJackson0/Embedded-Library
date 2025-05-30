//MSP430FR59xx Driver
#ifndef UART_H_
#define UART_H_
#include <stdint.h>
#include "DigitalIO.h"

typedef enum _Parity E_Parity;
typedef enum _UARTBitOrder E_UARTBitOrder;
typedef enum _UARTClockSource E_UARTClockSource;

//DECLARATIONS
/**
 * @brief Set the Clock Source, BaudRate and Oversample Rate of a given UART
 * 
 * @param uartNum UART Number (0 or 1)
 * @param clocksrc Clock Source: (U_CLOCK, A_CLOCK, SM_CLOCK) 
 * 						|||  SMCLK & MCLK = DCOCLK(1MHz) / 8  = 125KHz 
 * 						|||  According to '3.2 Clock System Operation'
 * @param baudRate UART BaudRate
 * @param overSampleRate OverSample Rate: 0 or 16
 * @return ** void 
 */
void USART_BaudRate_and_OverSample(char* uartNum, E_UARTClockSource clocksrc, uint32_t baudRate, uint8_t overSampleRate);
/**
 * @brief Initialize UART
 * 
 * @param uartNum UART Number (0 or 1)
 * @param numOfStopBits Number of Stop Bits: 1 or 2
 * @param dataSize Data Frame Size: 7-Bits or 8-Bits
 * @param parityType Parity Type: EVEN_PARITY, ODD_PARITY, NO_PARITY
 * @param bitorder Order of Bits: _LSB or _MSB
 * @return ** void 
 */
void UART_Init(char* uartNum, uint8_t numOfStopBits, uint8_t dataSize, E_Parity parityType, E_UARTBitOrder bitorder);
/**
 * @brief Receive Data over UART
 * 
 * @param uartNum UART Number (0 or 1)
 * @return ** uint8_t Data received
 */
uint8_t UART_Receive(char* uartNum);
/**
 * @brief Transmit data over UART
 * 
 * @param uartNum UART Number (0 or 1)
 * @param data Data to transmit
 * @return ** void 
 */
void UART_Transmit(char* uartNum, uint8_t data);

//UART
typedef struct _uart UARTx;
#define UART_BASE 0x0500
#define ADDR_UART0 ( (UARTx*) ((UART_BASE) + 0xC0) ) // Base Addresses shared with SPI
#define ADDR_UART1 ( (UARTx*) ((UART_BASE) + 0xE0) ) // Base Addresses shared with SPI

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
	EVEN_PARITY = 0, ODD_PARITY = 1,
	NO_PARITY = 2
};

enum _UARTBitOrder {
	_MSB = 0, _LSB = 1
};

//UART_CONTROL_WORD0 Register
/*Clock Source*/
enum _UARTClockSource {
	U_CLOCK = 0x00, A_CLOCK = 0x01,
	SM_CLOCK = 0x02
};

//Registers------------------------------------------------------------------
typedef struct {
	const uint16_t reserved:16;
}UART_RESERVED;

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

struct _uart {
	UART_CONTROL_WORD0 ControlWord0Reg; // 0x00
	UART_CONTROL_WORD1 ControlWord1Reg; // 0x02
	UART_RESERVED reserved0; // 0x04
	UART_BAUDRATE_CONTROL_WORD BaudRateControlWordReg; // 0x06
	UART_MODULATION_CONTROL_WORD ModulationControlWordReg; // 0x08
	UART_STATUS StatusReg; // 0x0A
	UART_RECEIVE_BUFFER RXBufferReg; // 0x0C
	UART_TRANSMIT_BUFFER TXBufferReg; // 0x0E
	UART_AUTO_BAUDRATE_CONTROL BaudRateControlReg; // 0x10
	UART_IRDA_CONTROL_WORD IRDAControlReg; // 0x12
	UART_RESERVED reserved1; // 0x14
	UART_RESERVED reserved2; // 0x16
	UART_RESERVED reserved3; // 0x18
	UART_INTERRUPT_ENABLE InterruptEnableReg; // 0x1A
	UART_INTERRUPT_FLAG InterruptFlagReg; // 0x1C
	UART_INTERRUPT_VECTOR InterruptVectorReg; // 0x1E
};

#endif
