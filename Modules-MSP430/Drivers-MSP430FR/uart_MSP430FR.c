#include <stdint.h>
#include <stddef.h>
#include "uart_MSP430FR.h"
#include "digital_io_MSP430FR.h"

//Static Prototypes----------------------------------------------------
static void UART_PinInit(void);
static UART_CONTROL_WORD0* Get_ControlWord0Reg(char* uartNum);
static UART_CONTROL_WORD1* Get_ControlWord1Reg(char* uartNum);
static UART_BAUDRATE_CONTROL_WORD* Get_BaudControlReg(char* uartNum);
static UART_MODULATION_CONTROL_WORD* Get_ModControlReg(char* uartNum);
static UART_STATUS* Get_StatusReg(char* uartNum);
static UART_RECEIVE_BUFFER* Get_RXReg(char* uartNum);
static UART_TRANSMIT_BUFFER* Get_TXReg(char* uartNum);
static UART_AUTO_BAUDRATE_CONTROL* Get_AutoBaudRateControlReg(char* uartNum);

//Global Variables-------------------------------------------------------
//UART A0
UART_CONTROL_WORD0 *const UARTControlWord0_A0 = ADDR_UART0_CONTROL_WORD0;
UART_CONTROL_WORD1 *const UARTControlWord1_A0 = ADDR_UART0_CONTROL_WORD1;
UART_BAUDRATE_CONTROL_WORD *const UARTBaudWord_A0 = ADDR_UART0_BAUDRATE_CONTROL_WORD;
UART_MODULATION_CONTROL_WORD *const UARTModWord_A0 = ADDR_UART0_MODULATION_CONTROL_WORD;
UART_STATUS *const UARTStat_A0 = ADDR_UART0_STATUS;
UART_RECEIVE_BUFFER *const UARTRX_A0 = ADDR_UART0_RECEIVE_BUFFER;
UART_TRANSMIT_BUFFER *const UARTTX_A0 = ADDR_UART0_TRANSMIT_BUFFER;
UART_AUTO_BAUDRATE_CONTROL *const UARTAutoBaudControl_A0 = ADDR_UART0_AUTO_BAUDRATE_CONTROL;

//UART A1
UART_CONTROL_WORD0 *const UARTControlWord0_A1 = ADDR_UART1_CONTROL_WORD0;
UART_CONTROL_WORD1 *const UARTControlWord1_A1 = ADDR_UART1_CONTROL_WORD1;
UART_BAUDRATE_CONTROL_WORD *const UARTBaudWord_A1 = ADDR_UART1_BAUDRATE_CONTROL_WORD;
UART_MODULATION_CONTROL_WORD *const UARTModWord_A1 = ADDR_UART1_MODULATION_CONTROL_WORD;
UART_STATUS *const UARTStat_A1 = ADDR_UART1_STATUS;
UART_RECEIVE_BUFFER *const UARTRX_A1 = ADDR_UART1_RECEIVE_BUFFER;
UART_TRANSMIT_BUFFER *const UARTTX_A1 = ADDR_UART1_TRANSMIT_BUFFER;
UART_AUTO_BAUDRATE_CONTROL *const UARTAutoBaudControl_A1 = ADDR_UART1_AUTO_BAUDRATE_CONTROL;


/**
MSP430FR CLOCK SPEED: According to '3.2 Clock System Operation'
		+ MCLK & SMCLK = DCOCLK
		+ Then they are divided by 8
		+-----------------------------
		+ DCOCLK = 1MHz
		+ SMCLK & MCLK = 1 MHz / 8
		+ SMCLK & MCLK = 125KHz
**/
void USART_BaudRate_and_OverSample(char* uartNum, E_UARTClockSource clocksrc, uint32_t baudRate, uint8_t overSampleRate) {
	
	UART_CONTROL_WORD0 *const UARTControlWord0 = Get_ControlWord0Reg(uartNum);
	UART_BAUDRATE_CONTROL_WORD *const UARTBaudWord = Get_BaudControlReg(uartNum);
	UART_MODULATION_CONTROL_WORD *const UARTModWord = Get_ModControlReg(uartNum);
	
	UARTControlWord0->select_ClockSource = clocksrc;
	
	switch (clocksrc) {
		
		case U_CLOCK :
			UARTBaudWord->rw_BaudRateClockPrescaler = (uint8_t ) (1000000 / baudRate); //Is this the DCO Clock?
			break;
		case A_CLOCK :
			UARTBaudWord->rw_BaudRateClockPrescaler = (uint8_t ) (125000 / baudRate); //Ex: (125KHz Clock) / 9600 Baudrate = (~13 Prescaler)
			break;
		case SM_CLOCK :
			UARTBaudWord->rw_BaudRateClockPrescaler = (uint8_t ) (125000 / baudRate);
			break;
	}
	
	switch (overSampleRate) {
		
		case 0 :
			UARTModWord->enable_OversamplingMode = 0;
		case 16 :
			UARTModWord->enable_OversamplingMode = 1;
	}
}

	
void UART_Init(char* uartNum, uint8_t numOfStopBits, uint8_t dataSize, E_Parity parityType, E_UARTBitOrder bitorder) {
	
	UART_CONTROL_WORD0 *const UARTControlWord0 = Get_ControlWord0Reg(uartNum);
	
	if ( UARTControlWord0->enable_SoftwareReset != 1 ) UARTControlWord0->enable_SoftwareReset = 1;
	UARTControlWord0->select_AsychronousModeType = UART_MODE;
	
	switch (numOfStopBits) {
		
		case 1 : 
			UARTControlWord0->oneStopBit0_twoStopBits1 = 0;
			break;
			
		case 2 :
			UARTControlWord0->oneStopBit0_twoStopBits1 = 1;
			break;
	}
	
	switch (dataSize) {
		
		case 7 :
			UARTControlWord0->data8Bit0_data7Bit1 = 1;
			break;
		
		case 8 : 
			UARTControlWord0->data8Bit0_data7Bit1 = 0;
			break;
	}
	
	if (parityType != NO_PARITY) {
		UARTControlWord0->oddParity0_evenParity1 = parityType;
		UARTControlWord0->enable_Parity =1;
	}
	
	UARTControlWord0->lsbFirst0_msbFirst1 = bitorder;
	UART_PinInit();
	UARTControlWord0->enable_SoftwareReset = 0; // Releases module for operation
}


uint8_t UART_Receive(char* uartNum) {
	
	UART_STATUS *const UARTStat = Get_StatusReg(uartNum);
	UART_RECEIVE_BUFFER *const UARTRX = Get_RXReg(uartNum);
	
	while (!(UARTStat->usartBusy == 0 && UARTStat->dataReceivedNoIdle0_addrsReceivedIdleDetected1 == 0));
		
	return UARTRX->read_DataReceived;
	
}

void UART_Transmit(char* uartNum, uint8_t data) {
	
	UART_STATUS *const UARTStat = Get_StatusReg(uartNum);
	UART_TRANSMIT_BUFFER *const UARTTX = Get_TXReg(uartNum);
	
	while (UARTStat->usartBusy == 1);
		
	UARTTX->rw_DataToTransmit = data;
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
	
	Watchdog_Off();
	//TX
	Pin_Init('2', 5, NONE, SECONDARY_F, NO_PULL);
	//RX
	Pin_Init('2', 6, NONE, SECONDARY_F, NO_PULL);
}

static UART_CONTROL_WORD0* Get_ControlWord0Reg(char* uartNum) {
	
	if (uartNum == "A0") { return UARTControlWord0_A0; }
	if (uartNum == "A1") { return UARTControlWord0_A1; }
	return NULL;
}

static UART_CONTROL_WORD1* Get_ControlWord1Reg(char* uartNum) {
	
	if (uartNum == "A0") { return UARTControlWord1_A0; }
	if (uartNum == "A1") { return UARTControlWord1_A1; }
	return NULL;
}

static UART_BAUDRATE_CONTROL_WORD* Get_BaudControlReg(char* uartNum) {
	
	if (uartNum == "A0") { return UARTBaudWord_A0; }
	if (uartNum == "A1") { return UARTBaudWord_A1; }
	return NULL;
}

static UART_MODULATION_CONTROL_WORD* Get_ModControlReg(char* uartNum) {
	
	if (uartNum == "A0") { return UARTModWord_A0; }
	if (uartNum == "A1") { return UARTModWord_A1; }
	return NULL;
}

static UART_STATUS* Get_StatusReg(char* uartNum) {
	
	if (uartNum == "A0") { return UARTStat_A0; }
	if (uartNum == "A1") { return UARTStat_A1; }
	return NULL;
}

static UART_RECEIVE_BUFFER* Get_RXReg(char* uartNum) {
	
	if (uartNum == "A0") { return UARTRX_A0; }
	if (uartNum == "A1") { return UARTRX_A1; }
	return NULL;
}

static UART_TRANSMIT_BUFFER* Get_TXReg(char* uartNum) {
	
	if (uartNum == "A0") { return UARTTX_A0; }
	if (uartNum == "A1") { return UARTTX_A1; }
	return NULL;
}

static UART_AUTO_BAUDRATE_CONTROL* Get_AutoBaudRateControlReg(char* uartNum) {
	
	if (uartNum == "A0") { return UARTAutoBaudControl_A0; }
	if (uartNum == "A1") { return UARTAutoBaudControl_A1; }
	return NULL;
}

