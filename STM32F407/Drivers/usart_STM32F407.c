#include <stdint.h>
#include <stddef.h>
#include "usart_STM32F407.h"
#include "gpio_STM32F407.h"

//Macros---------------------------------------------------------------
#define CLOCK_SPEED 16

//Static Prototypes----------------------------------------------------
static void USART_PinInit(uint8_t usartNumber);
static void Set_DataBitSize(uint8_t usartNumber, uint8_t dataBitSize);
static void Set_StopBitSize(uint8_t usartNumber, uint8_t stopBitSize);
static void USARTClockSelect(uint8_t usartNumber);
static USART_CONTROL1* Set_Control1Register(uint8_t usartNum);
static USART_CONTROL2* Set_Control2Register(uint8_t usartNum);
static USART_CONTROL3* Set_Control3Register(uint8_t usartNum);
static USART_BAUDRATE* Set_BaudRateRegister(uint8_t usartNum);
static USART_STATUS* Set_StatusRegister(uint8_t usartNum);
static USART_DATA* Set_DataRegister(uint8_t usartNum);

//Global Variables-------------------------------------------------------
USART_CLOCK_1_6 *const USARTClock1_6 = ADDR_USART_CLOCK_1_6;
USART_CLOCK *const USARTClock = ADDR_USART_CLOCK;
//USART 1
USART_CONTROL1 *const USARTControl1_1 = ADDR_USART1_CONTROL1;
USART_CONTROL2 *const USARTControl2_1 = ADDR_USART1_CONTROL2;
USART_CONTROL3 *const USARTControl3_1 = ADDR_USART1_CONTROL3;
USART_BAUDRATE *const USARTBaud_1 = ADDR_USART1_BAUDRATE;
USART_STATUS *const USARTStat_1 = ADDR_USART1_STATUS;
USART_DATA *const USARTData_1 = ADDR_USART1_DATA;
//USART 2
USART_CONTROL1 *const USARTControl1_2 = ADDR_USART2_CONTROL1;
USART_CONTROL2 *const USARTControl2_2 = ADDR_USART2_CONTROL2;
USART_CONTROL3 *const USARTControl3_2 = ADDR_USART2_CONTROL3;
USART_BAUDRATE *const USARTBaud_2 = ADDR_USART2_BAUDRATE;
USART_STATUS *const USARTStat_2 = ADDR_USART2_STATUS;
USART_DATA *const USARTData_2 = ADDR_USART2_DATA;
//USART 3
USART_CONTROL1 *const USARTControl1_3 = ADDR_USART3_CONTROL1;
USART_CONTROL2 *const USARTControl2_3 = ADDR_USART3_CONTROL2;
USART_CONTROL3 *const USARTControl3_3 = ADDR_USART3_CONTROL3;
USART_BAUDRATE *const USARTBaud_3 = ADDR_USART3_BAUDRATE;
USART_STATUS *const USARTStat_3 = ADDR_USART3_STATUS;
USART_DATA *const USARTData_3 = ADDR_USART3_DATA;
//UART 4
USART_CONTROL1 *const USARTControl1_4 = ADDR_USART4_CONTROL1;
USART_CONTROL2 *const USARTControl2_4 = ADDR_USART4_CONTROL2;
USART_CONTROL3 *const USARTControl3_4 = ADDR_USART4_CONTROL3;
USART_BAUDRATE *const USARTBaud_4 = ADDR_USART4_BAUDRATE;
USART_STATUS *const USARTStat_4 = ADDR_USART4_STATUS;
USART_DATA *const USARTData_4 = ADDR_USART4_DATA;
//UART 5
USART_CONTROL1 *const USARTControl1_5 = ADDR_USART5_CONTROL1;
USART_CONTROL2 *const USARTControl2_5 = ADDR_USART5_CONTROL2;
USART_CONTROL3 *const USARTControl3_5 = ADDR_USART5_CONTROL3;
USART_BAUDRATE *const USARTBaud_5 = ADDR_USART5_BAUDRATE;
USART_STATUS *const USARTStat_5 = ADDR_USART5_STATUS;
USART_DATA *const USARTData_5 = ADDR_USART5_DATA;
//USART 6
USART_CONTROL1 *const USARTControl1_6 = ADDR_USART6_CONTROL1;
USART_CONTROL2 *const USARTControl2_6 = ADDR_USART6_CONTROL2;
USART_CONTROL3 *const USARTControl3_6 = ADDR_USART4_CONTROL3;
USART_BAUDRATE *const USARTBaud_6 = ADDR_USART6_BAUDRATE;
USART_STATUS *const USARTStat_6 = ADDR_USART6_STATUS;
USART_DATA *const USARTData_6 = ADDR_USART6_DATA;


/**

Parameters:
	BaudRate -  
	OverSampleRate - 
	
- Default System Clock (fclk) = HSI 16MHz w/ No prescales or PLL
		+ USART 1 & 6 fclk = APB2 High Speed Bus (84MHz MAX Freq)
		+ USART/UART 2,3,4 & 5 fclk = APB1 Low Speed Bus (42MHz MAX Freq)
		
    - Calculating Baudrate:
		+ (Desired BaudRate) = fclk / (OverSampleRate * USARTDIV)
		+ Equation to Use: USARTDIV = fclk / (OverSampleRate * (Desired BaudRate))
    
	-  Getting a 9600 Baud Rate 
		+ USARTDIV = 104.1875
		+ Mantissa = 104
		+ Fraction = .1875 * (Oversampling Rate [16 in this case]) = 3

**/
void USART_BaudRate_and_OverSample(uint8_t usartNumber, uint32_t baudRate, uint8_t overSampleRate) {
	
	USART_CONTROL1 *const USARTControl1 = Set_Control1Register(usartNumber);
	USART_BAUDRATE *const USARTBaud = Set_BaudRateRegister(usartNumber);
	
	uint8_t clockSpeed = CLOCK_SPEED;
	
	switch (overSampleRate) {
		
		case 8 :
			USARTControl1->oversample16x0_oversample8x1 = 1;
		case 16 :
			USARTControl1->oversample16x0_oversample8x1 = 0;
	}
	
	float usartDividerFraction = (float) clockSpeed / (overSampleRate * baudRate);
	USARTBaud->usartDividerMantissa = (uint32_t) usartDividerFraction; //Ex: 1.456 -> 1
	USARTBaud->usartDividerFraction = (usartDividerFraction - USARTBaud->usartDividerMantissa) * overSampleRate; //Ex: (1.456 - 1) = 0.456 -> 0.456 * OverSampRate
}


/**
Parameters: 
	usartNumber - 
	ParityType -  
	DataBitSize -
	StopBitSize -

**/
void USART_Init(uint8_t usartNumber, E_Parity parityType, uint8_t dataBitSize, float stopBitSize){
	
	USARTClockSelect(usartNumber);
	USART_PinInit(usartNumber);
	
	USART_CONTROL1 *const USARTControl1 = Set_Control1Register(usartNumber);
	
	USARTControl1->enable_Transmitter = 1;
	USARTControl1->enable_Receiver = 1;
	
	Set_DataBitSize(usartNumber, dataBitSize);
	Set_StopBitSize(usartNumber, stopBitSize);
	
	if (parityType != NO_PARITY) {
		USARTControl1->evenParity0_oddParity1 = parityType;
		USARTControl1->enable_ParityControl = 1;
	}
	
	USARTControl1->enable_USART = 1; //Will send an Idle frame as first transmission
}


uint8_t USART_Transmit(uint8_t usartNumber, uint8_t data) {
	
	USART_STATUS *const USARTStat = Set_StatusRegister(usartNumber);
	USART_DATA *const USARTData = Set_DataRegister(usartNumber);
	
	while (USARTStat->transferRegisterOpen != 1);
	USARTData->rw_Data = data;
	
	return 1;
}

uint8_t USART_Receive(uint8_t usartNumber) {
	
	USART_STATUS *const USARTStat = Set_StatusRegister(usartNumber);
	USART_DATA *const USARTData = Set_DataRegister(usartNumber);
	
	while (USARTStat->dataReadyToRead != 1);
	return USARTData->rw_Data;
}


//Helper Functions--------------------------------------------------------------------------------------------------------------

/**
USART/UART Pins ---------------------------
		+ USART1_CK: PA4 (AF7)
		+ USART1_TX: PA2, PB6 (AF7)
		+ USART1_RX: PA3, PB7 (AF7)
		+ USART1_CTS: PA0 (AF7)
		+ USART1_RTS: PA1 (AF7)
		
		+ USART2_CTS: PA0, PD3 (AF7)
		+ USART2_RTS: PA1, PD4 (AF7)
		+ USART2_TX: PA2, PD5 (AF7)
		+ USART2_RX: PA3, PD6 (AF7)
		+ USART2_CK: PA4, PD7 (AF7)
		
		+ USART3_TX: PB10, PC10, PD8 (AF7)
		+ USART3_RX: PB11, PC11, PD9 (AF7)
		+ USART3_CK: PB12, PC12, PD10 (AF7)
		+ USART3_CTS: PB13, PD11 (AF7)
		+ USART3_RTS: PB14, PD12 (AF7)
		
		+ UART4_TX: PA0, PC10 (AF8)
		+ UART4_RX: PA1, PC11 (AF8)
		
		+ UART5_TX: PC12 (AF8)
		+ UART5_RX: PD2 (AF8)
		
		+ USART6_TX: PC6, PG14 (AF8)
		+ USART6_RX: PC7, PG9 (AF8)
		+ USART6_CK: PC8, PG7 (AF8)
		+ USART6_RTS: PG8, PG12 (AF8)
		+ USART6_CTS: PG13, PG15 (AF8)
		------------------------------------
**/
static void USART_PinInit(uint8_t usartNumber) {
	
	switch(usartNumber) {
		
		case 1 :
			//TX
			Pin_Init('A', 2, AF7);
			//RX
			Pin_Init('A', 3, AF7);
			break;
		case 2 :
			//TX
			Pin_Init('D', 5, AF7);
			//RX
			Pin_Init('D', 6, AF7);
			break;
		case 3 :
			//TX
			Pin_Init('B', 10, AF7);
			//RX
			Pin_Init('B', 11, AF7);
			break;
		case 4 : 
			//TX
			Pin_Init('A', 0, AF8);
			//RX
			Pin_Init('A', 1, AF8);
			break;
		case 5 : 
			//TX
			Pin_Init('C', 12, AF8);
			//RX
			Pin_Init('D', 2, AF8);
			break;
		case 6 :
			//TX
			Pin_Init('C', 6, AF8);
			//RX
			Pin_Init('C', 7, AF8);
			break;
	}
}

static void Set_DataBitSize(uint8_t usartNumber, uint8_t dataBitSize) {
	
	USART_CONTROL1 *const USARTControl1 = Set_Control1Register(usartNumber);
	
	switch (dataBitSize) {
		
		case 8 : 
			USARTControl1->data8Bit0_data9Bit1 = 0;
		case 9 : 
			USARTControl1->data8Bit0_data9Bit1 = 1;
	}
}

static void Set_StopBitSize(uint8_t usartNumber, uint8_t stopBitSize) {
	
	USART_CONTROL2 *const USARTControl2 = Set_Control2Register(usartNumber);
	
	if (stopBitSize == 0.5) { USARTControl2->numberOfStopBits = HALF_STOPBIT; }
	if (stopBitSize == 1.0) { USARTControl2->numberOfStopBits = ONE_STOPBIT; }
	if (stopBitSize == 1.5) { USARTControl2->numberOfStopBits = ONE_AND_HALF_STOPBIT; }
	if (stopBitSize == 2.0) { USARTControl2->numberOfStopBits = TWO_STOPBIT; }
}

static void USARTClockSelect(uint8_t usartNumber) {
	
	switch(usartNumber) {
		
		case 1 :
			USARTClock1_6->usart1_StartTick = 1;
			break;
		case 2 :
			USARTClock->usart2_StartTick = 1;
			break;
		case 3 :
			USARTClock->usart3_StartTick = 1;
			break;
		case 4 : 
			USARTClock->uart4_StartTick = 1;
			break;
		case 5 : 
			USARTClock->uart5_StartTick = 1;
			break;
		case 6 :
			USARTClock1_6->usart6_StartTick = 1;
			break;
	}
}

static USART_CONTROL1* Set_Control1Register(uint8_t usartNum) {
	
	switch(usartNum) {
		
		case 1 :
			return USARTControl1_1;
		case 2 :
			return USARTControl1_2;
		case 3 :
			return USARTControl1_3;
		case 4 :
			return USARTControl1_4;
		case 5 :
			return USARTControl1_5;
		case 6 :
			return USARTControl1_6;
		default :
			return NULL;
	}
}

static USART_CONTROL2* Set_Control2Register(uint8_t usartNum) {
	
	switch(usartNum) {
		
		case 1 :
			return USARTControl2_1;
		case 2 :
			return USARTControl2_2;
		case 3 :
			return USARTControl2_3;
		case 4 :
			return USARTControl2_4;
		case 5 :
			return USARTControl2_5;
		case 6 :
			return USARTControl2_6;
		default :
			return NULL;
	}
}

static USART_CONTROL3* Set_Control3Register(uint8_t usartNum) {
	
	switch(usartNum) {
		
		case 1 :
			return USARTControl3_1;
		case 2 :
			return USARTControl3_2;
		case 3 :
			return USARTControl3_3;
		case 4 :
			return USARTControl3_4;
		case 5 :
			return USARTControl3_5;
		case 6 :
			return USARTControl3_6;
		default :
			return NULL;
	}
}

static USART_BAUDRATE* Set_BaudRateRegister(uint8_t usartNum) {
	
	switch(usartNum) {
		
		case 1 :
			return USARTBaud_1;
		case 2 :
			return USARTBaud_2;
		case 3 :
			return USARTBaud_3;
		case 4 :
			return USARTBaud_4;
		case 5 :
			return USARTBaud_5;
		case 6 :
			return USARTBaud_6;
		default :
			return NULL;
	}
}

static USART_STATUS* Set_StatusRegister(uint8_t usartNum) {
	
	switch(usartNum) {
		
		case 1 :
			return USARTStat_1;
		case 2 :
			return USARTStat_2;
		case 3 :
			return USARTStat_3;
		case 4 :
			return USARTStat_4;
		case 5 :
			return USARTStat_5;
		case 6 :
			return USARTStat_6;
		default :
			return NULL;
	}
}

static USART_DATA* Set_DataRegister(uint8_t usartNum) {
	
	switch(usartNum) {
		
		case 1 :
			return USARTData_1;
		case 2 :
			return USARTData_2;
		case 3 :
			return USARTData_3;
		case 4 :
			return USARTData_4;
		case 5 :
			return USARTData_5;
		case 6 :
			return USARTData_6;
		default :
			return NULL;
	}
}

