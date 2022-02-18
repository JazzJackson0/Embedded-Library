#include <stdint.h>
#include "MSP430FR.UART.h"
#include "MSP430FR.DigitalIO.h"

//Static Prototypes----------------------------------------------------
static void UART_PinInit(void);
static UARTx* Get_UART(char *uartNum);

//Global Variables-------------------------------------------------------
//UART A0
UARTx *const UART_A0 = ADDR_UART0;
UARTx *const UART_A1 = ADDR_UART1;


void USART_BaudRate_and_OverSample(char* uartNum, E_UARTClockSource clocksrc, uint32_t baudRate, uint8_t overSampleRate) {
	
	UARTx *const UART = Get_UART(uartNum);
	UART->ControlWord0Reg.select_ClockSource = clocksrc;
	
	switch (clocksrc) {
		case U_CLOCK :
			UART->BaudRateControlWordReg.rw_BaudRateClockPrescaler = (uint8_t ) (1000000 / baudRate); //Is this the DCO Clock?
			break;
		case A_CLOCK :
			UART->BaudRateControlWordReg.rw_BaudRateClockPrescaler = (uint8_t ) (125000 / baudRate); //Ex: (125KHz Clock) / 9600 Baudrate = (~13 Prescaler)
			break;
		case SM_CLOCK :
			UART->BaudRateControlWordReg.rw_BaudRateClockPrescaler = (uint8_t ) (125000 / baudRate);
			break;
	}
	
	switch (overSampleRate) {
		case 0 :
			UART->ModulationControlWordReg.enable_OversamplingMode = 0;
			break;
		case 16 :
			UART->ModulationControlWordReg.enable_OversamplingMode = 1;
			break;
	}
}

	
void UART_Init(char* uartNum, uint8_t numOfStopBits, uint8_t dataSize, E_Parity parityType, E_UARTBitOrder bitorder) {
	
	UARTx *const UART = Get_UART(uartNum);
	
	if ( UART->ControlWord0Reg.enable_SoftwareReset != 1 ) UART->ControlWord0Reg.enable_SoftwareReset = 1;
	UART->ControlWord0Reg.select_AsychronousModeType = UART_MODE;
	
	switch (numOfStopBits) {
		case 1 : 
			UART->ControlWord0Reg.oneStopBit0_twoStopBits1 = 0;
			break;	
		case 2 :
			UART->ControlWord0Reg.oneStopBit0_twoStopBits1 = 1;
			break;
	}
	
	switch (dataSize) {
		case 7 :
			UART->ControlWord0Reg.data8Bit0_data7Bit1 = 1;
			break;
		case 8 : 
			UART->ControlWord0Reg.data8Bit0_data7Bit1 = 0;
			break;
	}
	
	if (parityType != NO_PARITY) {
		UART->ControlWord0Reg.oddParity0_evenParity1 = parityType;
		UART->ControlWord0Reg.enable_Parity =1;
	}
	
	UART->ControlWord0Reg.lsbFirst0_msbFirst1 = bitorder;
	UART_PinInit();
	UART->ControlWord0Reg.enable_SoftwareReset = 0; // Releases module for operation
}


uint8_t UART_Receive(char* uartNum) {
	
	UARTx *const UART = Get_UART(uartNum);
	while (!(UART->StatusReg.usartBusy == 0 && UART->StatusReg.dataReceivedNoIdle0_addrsReceivedIdleDetected1 == 0));
	return UART->RXBufferReg.read_DataReceived;
}

void UART_Transmit(char* uartNum, uint8_t data) {
	UARTx *const UART = Get_UART(uartNum);
	while (UART->StatusReg.usartBusy == 1);
	UART->TXBufferReg.rw_DataToTransmit = data;
}


//Helper Functions--------------------------------------------------------------------------------------------------------

/**
UART Pins ---------------------------
		+ UART A0 Transmit: P2-0 	[(Secondary Function)]
		+ UART A0 Receive: P2-1 	[(Secondary Function)] 
		
		+ UART A1 Transmit: P2-5 	[(Secondary Function)]
		+ UART A1 Receive: P2-6 	[(Secondary Function)]
		------------------------------------
**/
static void UART_PinInit(void) {

	//TX
	Pin_Init('2', 5, NONE, SECONDARY_F, NO_PULL);
	//RX
	Pin_Init('2', 6, NONE, SECONDARY_F, NO_PULL);
}

static UARTx* Get_UART(char *uartNum) {

	if (uartNum == "A0") { return UART_A0; }
	else if (uartNum == "A1") { return UART_A1; }
	return NULL;
}

