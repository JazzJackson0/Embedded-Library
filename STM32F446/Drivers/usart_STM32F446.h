//STM32F446 Driver
#ifndef USART_H_
#define USART_H_

#include <stdint.h>

typedef enum _Parity E_Parity;

void USART_BaudRate_and_OverSample(uint8_t usartNumber, uint32_t baudRate, uint8_t overSampleRate);
void USART_Init(uint8_t usartNumber, E_Parity parityType, uint8_t dataBitSize, float stopBitSize);
uint8_t USART_Transmit(uint8_t usartNumber, uint8_t data);
uint8_t USART_Receive(uint8_t usartNumber);

#define CLOCK 0x40023800
#define APB1 0x40
#define APB2 0x44
#define USART1 0x40011000
#define USART2 0x40004400
#define USART3 0x40004800
#define UART4 0x40004C00
#define UART5 0x40005000
#define USART6 0x40011400

//CLOCK
#define ADDR_USART_CLOCK ( (USART_CLOCK*) ((CLOCK) + APB1) )
#define ADDR_USART_CLOCK_1_6 ( (USART_CLOCK_1_6*) ((CLOCK) + APB2) )

// USART 1
#define ADDR_USART1_STATUS ( (USART_STATUS*) ((USART1) + 0x00) )
#define ADDR_USART1_DATA ( (USART_DATA*) ((USART1) + 0x04) )
#define ADDR_USART1_BAUDRATE ( (USART_BAUDRATE*) ((USART1) + 0x08) )
#define ADDR_USART1_CONTROL1 ( (USART_CONTROL1*) ((USART1) + 0x0C) )
#define ADDR_USART1_CONTROL2 ( (USART_CONTROL2*) ((USART1) + 0x10) )
#define ADDR_USART1_CONTROL3 ( (USART_CONTROL3*) ((USART1) + 0x14) )
#define ADDR_USART1_GUARDTIME_PRESCALER ( (USART_GUARDTIME_PRESCALER*) ((USART1) + 0x18) )

// USART 2
#define ADDR_USART2_STATUS ( (USART_STATUS*) ((USART2) + 0x00) )
#define ADDR_USART2_DATA ( (USART_DATA*) ((USART2) + 0x04) )
#define ADDR_USART2_BAUDRATE ( (USART_BAUDRATE*) ((USART2) + 0x08) )
#define ADDR_USART2_CONTROL1 ( (USART_CONTROL1*) ((USART2) + 0x0C) )
#define ADDR_USART2_CONTROL2 ( (USART_CONTROL2*) ((USART2) + 0x10) )
#define ADDR_USART2_CONTROL3 ( (USART_CONTROL3*) ((USART2) + 0x14) )
#define ADDR_USART2_GUARDTIME_PRESCALER ( (USART_GUARDTIME_PRESCALER*) ((USART2) + 0x18) )

// USART 3
#define ADDR_USART3_STATUS ( (USART_STATUS*) ((USART3) + 0x00) )
#define ADDR_USART3_DATA ( (USART_DATA*) ((USART3) + 0x04) )
#define ADDR_USART3_BAUDRATE ( (USART_BAUDRATE*) ((USART3) + 0x08) )
#define ADDR_USART3_CONTROL1 ( (USART_CONTROL1*) ((USART3) + 0x0C) )
#define ADDR_USART3_CONTROL2 ( (USART_CONTROL2*) ((USART3) + 0x10) )
#define ADDR_USART3_CONTROL3 ( (USART_CONTROL3*) ((USART3) + 0x14) )
#define ADDR_USART3_GUARDTIME_PRESCALER ( (USART_GUARDTIME_PRESCALER*) ((USART3) + 0x18) )

// UART 4
#define ADDR_USART4_STATUS ( (USART_STATUS*) ((UART4) + 0x00) )
#define ADDR_USART4_DATA ( (USART_DATA*) ((UART4) + 0x04) )
#define ADDR_USART4_BAUDRATE ( (USART_BAUDRATE*) ((UART4) + 0x08) )
#define ADDR_USART4_CONTROL1 ( (USART_CONTROL1*) ((UART4) + 0x0C) )
#define ADDR_USART4_CONTROL2 ( (USART_CONTROL2*) ((UART4) + 0x10) )
#define ADDR_USART4_CONTROL3 ( (USART_CONTROL3*) ((UART4) + 0x14) )
#define ADDR_USART4_GUARDTIME_PRESCALER ( (USART_GUARDTIME_PRESCALER*) ((UART4) + 0x18) )

// UART 5
#define ADDR_USART5_STATUS ( (USART_STATUS*) ((UART5) + 0x00) )
#define ADDR_USART5_DATA ( (USART_DATA*) ((UART5) + 0x04) )
#define ADDR_USART5_BAUDRATE ( (USART_BAUDRATE*) ((UART5) + 0x08) )
#define ADDR_USART5_CONTROL1 ( (USART_CONTROL1*) ((UART5) + 0x0C) )
#define ADDR_USART5_CONTROL2 ( (USART_CONTROL2*) ((UART5) + 0x10) )
#define ADDR_USART5_CONTROL3 ( (USART_CONTROL3*) ((UART5) + 0x14) )
#define ADDR_USART5_GUARDTIME_PRESCALER ( (USART_GUARDTIME_PRESCALER*) ((UART5) + 0x18) )

// USART 6
#define ADDR_USART6_STATUS ( (USART_STATUS*) ((USART6) + 0x00) )
#define ADDR_USART6_DATA ( (USART_DATA*) ((USART6) + 0x04) )
#define ADDR_USART6_BAUDRATE ( (USART_BAUDRATE*) ((USART6) + 0x08) )
#define ADDR_USART6_CONTROL1 ( (USART_CONTROL1*) ((USART6) + 0x0C) )
#define ADDR_USART6_CONTROL2 ( (USART_CONTROL2*) ((USART6) + 0x10) )
#define ADDR_USART6_CONTROL3 ( (USART_CONTROL3*) ((USART6) + 0x14) )
#define ADDR_USART6_GUARDTIME_PRESCALER ( (USART_GUARDTIME_PRESCALER*) ((USART6) + 0x18) )


//For USART_CONTROL2
#define ONE_STOPBIT 0x00
#define HALF_STOPBIT 0x01
#define TWO_STOPBIT 0x02
#define ONE_AND_HALF_STOPBIT 0x03

//Enums----------------------------------------------------------------------
enum _Parity {
	EVEN_PARITY = 0,
	ODD_PARITY = 1,
	NO_PARITY = 2
};

//Registers------------------------------------------------------------------
typedef struct {
	const uint32_t reserved0:17;
	volatile uint32_t usart2_StartTick:1;
	volatile uint32_t usart3_StartTick:1;
	volatile uint32_t uart4_StartTick:1;
	volatile uint32_t uart5_StartTick:1;
	const uint32_t reserved1:11;
}USART_CLOCK;

typedef struct {
	const uint32_t reserved0:4;
	volatile uint32_t usart1_StartTick:1;
	volatile uint32_t usart6_StartTick:1;
	const uint32_t reserved1:26;
}USART_CLOCK_1_6;

typedef struct {
	volatile uint32_t parityError:1;
	volatile uint32_t FramingError:1;
	volatile uint32_t noiseDetected:1;
	volatile uint32_t overrunError:1;
	volatile uint32_t idleLineDetected:1;
	volatile uint32_t dataReadyToRead:1;
	volatile uint32_t transmissionComplete:1;
	volatile uint32_t transferRegisterOpen:1;
	volatile uint32_t localInterconnectNetworkBreak:1;
	volatile uint32_t clearToSend:1;
	const uint32_t reserved:22;
}USART_STATUS;


typedef struct {
	volatile uint32_t rw_Data:8;
	const uint32_t reserved:24;
}USART_DATA;


typedef struct {
	volatile uint32_t usartDividerFraction:4;
	volatile uint32_t usartDividerMantissa:12;
	const uint32_t reserved:16;
}USART_BAUDRATE;


typedef struct {
	volatile uint32_t send_BreakCharacter:1;
	volatile uint32_t enable_MuteMode:1;
	volatile uint32_t enable_Receiver:1;
	volatile uint32_t enable_Transmitter:1;
	volatile uint32_t enable_IDLEInterrupt:1;
	volatile uint32_t enable_readyToReadInterrupt:1;
	volatile uint32_t enable_TransmissionCompleteInterrupt:1;
	volatile uint32_t enable_TransferRegisterOpenInterrupt:1;
	volatile uint32_t enable_ParityErrorInterrupt:1;
	volatile uint32_t evenParity0_oddParity1:1;
	volatile uint32_t enable_ParityControl:1;
	volatile uint32_t idleLineWakeUp0_AddressMarkWakeUp1:1;
	volatile uint32_t data8Bit0_data9Bit1:1;
	volatile uint32_t enable_USART:1;
	const uint32_t reserved0:1;
	volatile uint32_t oversample16x0_oversample8x1:1;
	const uint32_t reserved1:16;
}USART_CONTROL1;


typedef struct {
	volatile uint32_t rw_USARTNodeAddress:4;
	const uint32_t reserved0:1;
	volatile uint32_t bit10BreakDetect0_bit11BreakDetect1:1;
	volatile uint32_t enable_LINBreakDetectionFlag:1;
	const uint32_t reserved1:1;
	volatile uint32_t enable_LastBitClockPulse:1;
	volatile uint32_t clkPhase1stTrans0_clckPhase2ndTrans1:1;
	volatile uint32_t clkPolarityLow0_clkPolarityHigh1:1;
	volatile uint32_t enable_Clock:1;
	volatile uint32_t numberOfStopBits:2;
	volatile uint32_t enable_LINMode:1;
	const uint32_t reserved2:17;
}USART_CONTROL2;


typedef struct {
	volatile uint32_t enable_ErrorFlag:1;
	volatile uint32_t enable_IrDAMode:1;
	volatile uint32_t enable_IrDALowPower:1;
	volatile uint32_t enable_HalfDuplexMode:1;
	volatile uint32_t enable_SmartcardNACK:1;
	volatile uint32_t enable_SmartcardMode:1;
	volatile uint32_t enable_DMAReceiver:1;
	volatile uint32_t enable_DMATransmitter:1;
	volatile uint32_t enable_RequestToSendInterrupt:1;
	volatile uint32_t enable_ClearToSendMode:1;
	volatile uint32_t enable_ClearToSendInterrupt:1;
	volatile uint32_t threeSampleBit0_oneSampleBit1:1;
	const uint32_t reserved:20;
}USART_CONTROL3;


typedef union {
	struct {
		volatile uint32_t rw_PrescalerValue:8;
		volatile uint32_t rw_GuardTimeValue:8;
		const uint32_t reserved:16;
	}IrDALowPowerMode;

	struct {
		volatile uint32_t rw_PrescalerValue:5;
		const uint32_t reserved0:3;
		volatile uint32_t rw_GuardTimeValue:8;
		const uint32_t reserved1:16;
	}NormalMode;
}USART_GUARDTIME_PRESCALER;


#endif
