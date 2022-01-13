#include <stdint.h>
#include "usart_ATmega328.h"

//Global Variables-------------------------------------------------------
//USART
POWER_REDUCTION_USART *const USARTPower = ADDR_POWER_REDUCTION_USART;
USARTx *const USART = ADDR_USART;


void USART_Init(E_USARTMode mode, E_Parity parity, E_USARTPolarity polarity, uint8_t dataSize, uint8_t numOfStopBits) {
	
	USARTPower->usartOn0_usartOff1 = 0;
	
	USART->StatusCReg.rw_ModeSelect = mode;
	USART->StatusCReg.rw_ParityMode = parity;
	USART->StatusCReg.polarity_TXRiseRXFall0_TXFallRXRise1 = polarity;
	
	switch (dataSize) {
		case 5 :
			USART->StatusCReg.rw_dataFrameSizePart1 = _5_BIT_PART1;
			USART->StatusBReg.rw_dataFrameSizePart2 = _5_BIT_PART2;
			break;
		case 6 :
			USART->StatusCReg.rw_dataFrameSizePart1 = _6_BIT_PART1;
			USART->StatusBReg.rw_dataFrameSizePart2 = _6_BIT_PART2;
			break;
		case 7 :
			USART->StatusCReg.rw_dataFrameSizePart1 = _7_BIT_PART1;
			USART->StatusBReg.rw_dataFrameSizePart2 = _7_BIT_PART2;
			break;
		case 8 :
			USART->StatusCReg.rw_dataFrameSizePart1 = _8_BIT_PART1;
			USART->StatusBReg.rw_dataFrameSizePart2 = _8_BIT_PART2;
			break;
		case 9 :
			USART->StatusCReg.rw_dataFrameSizePart1 = _9_BIT_PART1;
			USART->StatusBReg.rw_dataFrameSizePart2 = _9_BIT_PART2;
			break;
	}
	
	switch (numOfStopBits) {
		case 1 : 
			USART->StatusCReg.oneStopBit0_twoStopBits1 = 0;
			break;
		case 2 :
			USART->StatusCReg.oneStopBit0_twoStopBits1 = 1;
			break;
	}
	
	USART->StatusBReg.enable_Transmitter = 1;
	USART->StatusBReg.enable_Receiver = 1;
	
	//Set Desired BaudRate in Header File
	USART->BaudRateLowReg.rw_BaudRateLow = ASYNC_NORMAL_MODE; //I beleive a num > 8 bits will automatically fill the baudHigh Reg?
	//baudHigh->rw_BaudRateHigh = (ASYNC_NORMAL_MODE >> 8);
}

uint8_t USART_Receive(void) {
	
	while (USART->StatusAReg.dataReadyToRead != 1); 
	return USART->IODataReg.dataReceived_dataToSend;
}

void USART_Transmit(uint8_t data) {
	
	while (USART->StatusAReg.readyToTransmit != 1); 
	USART->IODataReg.dataReceived_dataToSend = data;
}

