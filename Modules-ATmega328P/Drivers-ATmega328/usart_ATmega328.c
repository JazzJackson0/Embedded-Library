#include <stdint.h>
#include "usart_ATmega328.h"

//Global Variables-------------------------------------------------------
//USART
POWER_REDUCTION_USART *const uartPower = ADDR_POWER_REDUCTION_USART;
USART_IO_DATA *const uartData = ADDR_USART_IO_DATA;
USART_CONTROL_STATUS_A *const controlStatA = ADDR_USART_CONTROL_STATUS_A;
USART_CONTROL_STATUS_B *const controlStatB = ADDR_USART_CONTROL_STATUS_B;
USART_CONTROL_STATUS_C *const controlStatC = ADDR_USART_CONTROL_STATUS_C;
USART_BAUDRATE_LOW *const baudLow = ADDR_USART_BAUDRATE_LOW;
USART_BAUDRATE_HIGH *const baudHigh = ADDR_USART_BAUDRATE_HIGH;


void USART_Init(E_USARTMode mode, E_Parity parity, E_USARTPolarity polarity, uint8_t dataSize, uint8_t numOfStopBits) {
	
	uartPower->usartOn0_usartOff1 = 0;
	
	controlStatC->rw_ModeSelect = mode;
	controlStatC->rw_ParityMode = parity;
	controlStatC->polarity_TXRiseRXFall0_TXFallRXRise1 = polarity;
	
	
	switch (dataSize) {
		
		case 5 :
			controlStatC->rw_dataFrameSizePart1 = _5_BIT_PART1;
			controlStatB->rw_dataFrameSizePart2 = _5_BIT_PART2;
			break;
		case 6 :
			controlStatC->rw_dataFrameSizePart1 = _6_BIT_PART1;
			controlStatB->rw_dataFrameSizePart2 = _6_BIT_PART2;
			break;
		case 7 :
			controlStatC->rw_dataFrameSizePart1 = _7_BIT_PART1;
			controlStatB->rw_dataFrameSizePart2 = _7_BIT_PART2;
			break;
		case 8 :
			controlStatC->rw_dataFrameSizePart1 = _8_BIT_PART1;
			controlStatB->rw_dataFrameSizePart2 = _8_BIT_PART2;
			break;
		case 9 :
			controlStatC->rw_dataFrameSizePart1 = _9_BIT_PART1;
			controlStatB->rw_dataFrameSizePart2 = _9_BIT_PART2;
			break;
	}
	
	switch (numOfStopBits) {
		
		case 1 : 
			controlStatC->oneStopBit0_twoStopBits1 = 0;
			break;
			
		case 2 :
			controlStatC->oneStopBit0_twoStopBits1 = 1;
			break;
	}
	
	controlStatB->enable_Transmitter = 1;
	controlStatB->enable_Receiver = 1;
	
	//Set Desired BaudRate in Header File
	baudLow->rw_BaudRateLow = ASYNC_NORMAL_MODE; //I beleive a num > 8 bits will automatically fill the baudHigh Reg?
	//baudHigh->rw_BaudRateHigh = (ASYNC_NORMAL_MODE >> 8);
}

uint8_t USART_Receive(void) {
	
	while (controlStatA->dataReadyToRead != 1); 
	return uartData->dataReceived_dataToSend;
}

void USART_Transmit(uint8_t data) {
	
	while (controlStatA->readyToTransmit != 1); 
	uartData->dataReceived_dataToSend = data;
}

