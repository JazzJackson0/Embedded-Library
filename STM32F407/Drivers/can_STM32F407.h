//STM32F407 Driver
#ifndef CAN_H_
#define CAN_H_

#include <stdint.h>

typedef enum _FilterSize E_FilterSize;
typedef enum _FilterMode E_FilterMode;
typedef struct _Data Received_Data;

void CAN_SetBitTime(uint8_t baudRatePrescale, uint8_t resyncJump, uint8_t timeSeg1, uint8_t timeSeg2);
void CAN_SetAcceptanceFilter(uint8_t filterNum, E_FilterSize filterSize, E_FilterMode filterMode, uint64_t filterBankVal, uint8_t fifoNum);
void CAN_SetTXMailbox(uint8_t canNum, uint64_t standardID, uint8_t numOfBytes);
void CAN_SetRXMailbox(uint8_t canNum, uint64_t standardID, uint8_t numOfBytes);
void CAN_Init_and_Start(uint8_t canNum);
uint8_t CAN_Transmit(uint8_t canNum, uint8_t *dataBuffer, uint8_t numOfBytes);
Received_Data* CAN_Receive(uint8_t canNum, uint8_t numOfBytes);

#define CLOCK 0x40023800
#define APB1 0x40
#define CAN1 0x40006400
#define CAN2 0x40006800
#define CANx CAN1

//CLOCK
#define ADDR_CAN_CLOCK ( (CAN_CLOCK*) ((CLOCK) + APB1) )

//CONTROL & STATUS REGISTERS-----------------------------------------------
#define ADDR_CAN_MASTER_CONTROL ( (CAN_MASTER_CONTROL*) ((CANx) + 0x00) )
#define ADDR_CAN_MASTER_SATUS ( (CAN_MASTER_SATUS*) ((CANx) + 0x04) )
#define ADDR_CAN_TRANSMIT_STATUS ( (CAN_TRANSMIT_STATUS*) ((CANx) + 0x08) )
#define ADDR_CAN_RECEIVE_FIFO0 ( (CAN_RECEIVE_FIFO0*) ((CANx) + 0x0C) )
#define ADDR_CAN_RECEIVE_FIFO1 ( (CAN_RECEIVE_FIFO1*) ((CANx) + 0x10) )
#define ADDR_CAN_INTERRUPTS ( (CAN_INTERRUPTS*) ((CANx) + 0x14) )
#define ADDR_CAN_ERRORSTATUS ( (CAN_ERRORSTATUS*) ((CANx) + 0x18) )
#define ADDR_CAN_BITTIMING ( (CAN_BITTIMING*) ((CANx) + 0x1C) )

//MAILBOX REGISTERS--------------------------------------------------------
//tx
#define ADDR_CAN_TX_MAILBOX_IDENTIFIER_1 ( (CAN_TX_MAILBOX_IDENTIFIER*) ((CANx) + 0x180) )
#define ADDR_CAN_TX_MAILBOX_IDENTIFIER_2 ( (CAN_TX_MAILBOX_IDENTIFIER*) ((CANx) + 0x190) )
#define ADDR_CAN_TX_MAILBOX_IDENTIFIER_3 ( (CAN_TX_MAILBOX_IDENTIFIER*) ((CANx) + 0x1A0) )

#define ADDR_CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP_1 ( (CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP*) ((CANx) + 0x184) )
#define ADDR_CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP_2 ( (CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP*) ((CANx) + 0x194) )
#define ADDR_CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP_3 ( (CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP*) ((CANx) + 0x1A4) )

#define ADDR_CAN_TX_MAILBOX_DATALOW_1 ( (CAN_TX_MAILBOX_DATALOW*) ((CANx) + 0x188) )
#define ADDR_CAN_TX_MAILBOX_DATALOW_2 ( (CAN_TX_MAILBOX_DATALOW*) ((CANx) + 0x198) )
#define ADDR_CAN_TX_MAILBOX_DATALOW_3 ( (CAN_TX_MAILBOX_DATALOW*) ((CANx) + 0x1A8) )

#define ADDR_CAN_TX_MAILBOX_DATAHIGH_1 ( (CAN_TX_MAILBOX_DATAHIGH*) ((CANx) + 0x18C) )
#define ADDR_CAN_TX_MAILBOX_DATAHIGH_2 ( (CAN_TX_MAILBOX_DATAHIGH*) ((CANx) + 0x19C) )
#define ADDR_CAN_TX_MAILBOX_DATAHIGH_3 ( (CAN_TX_MAILBOX_DATAHIGH*) ((CANx) + 0x1AC) )

//rx
#define ADDR_CAN_RX_MAILBOX_IDENTIFIER_1 ( (CAN_RX_MAILBOX_IDENTIFIER*) ((CANx) + 0x1B0) )
#define ADDR_CAN_RX_MAILBOX_IDENTIFIER_2 ( (CAN_RX_MAILBOX_IDENTIFIER*) ((CANx) + 0x1C0) )

#define ADDR_CAN_RX_MAILBOX_DATALENCNTRL_TIMESTAMP_1 ( (CAN_RX_MAILBOX_DATALENCNTRL_TIMESTAMP*) ((CANx) + 0x1B4) )
#define ADDR_CAN_RX_MAILBOX_DATALENCNTRL_TIMESTAMP_2 ( (CAN_RX_MAILBOX_DATALENCNTRL_TIMESTAMP*) ((CANx) + 0x1C4) )

#define ADDR_CAN_RX_MAILBOX_DATALOW_1 ( (CAN_RX_MAILBOX_DATALOW*) ((CANx) + 0x1B8) )
#define ADDR_CAN_RX_MAILBOX_DATALOW_2 ( (CAN_RX_MAILBOX_DATALOW*) ((CANx) + 0x1C8) )

#define ADDR_CAN_RX_MAILBOX_DATAHIGH_1 ( (CAN_RX_MAILBOX_DATAHIGH*) ((CANx) + 0x1BC) )
#define ADDR_CAN_RX_MAILBOX_DATAHIGH_2 ( (CAN_RX_MAILBOX_DATAHIGH*) ((CANx) + 0x1CC) )


//FILTER REGISTERS--------------------------------------------------------
#define ADDR_CAN_FILTER_MASTER ( (CAN_FILTER_MASTER*) ((CANx) + 0x200) )
#define ADDR_CAN_FILTER_MODE ( (CAN_FILTER_MODE*) ((CANx) + 0x204) )
#define ADDR_CAN_FILTER_SCALE ( (CAN_FILTER_SCALE*) ((CANx) + 0x20C) )
#define ADDR_CAN_FILTER_FIFO_ASSIGNMENT ( (CAN_FILTER_FIFO_ASSIGNMENT*) ((CANx) + 0x214) )
#define ADDR_CAN_FILTER_ACTIVATION ( (CAN_FILTER_ACTIVATION*) ((CANx) + 0x21C) )

#define ADDR_CAN_FILTERBANK0_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x240) )
#define ADDR_CAN_FILTERBANK1_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x244) )
#define ADDR_CAN_FILTERBANK2_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x248) )
#define ADDR_CAN_FILTERBANK3_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x24C) )
#define ADDR_CAN_FILTERBANK4_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x250) )
#define ADDR_CAN_FILTERBANK5_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x254) )
#define ADDR_CAN_FILTERBANK6_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x258) )
#define ADDR_CAN_FILTERBANK7_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x25C) )
#define ADDR_CAN_FILTERBANK8_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x260) )
#define ADDR_CAN_FILTERBANK9_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x264) )
#define ADDR_CAN_FILTERBANK10_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x268) )
#define ADDR_CAN_FILTERBANK11_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x26C) )
#define ADDR_CAN_FILTERBANK12_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x270) )
#define ADDR_CAN_FILTERBANK13_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x274) )
#define ADDR_CAN_FILTERBANK14_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x278) )
#define ADDR_CAN_FILTERBANK15_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x27C) )
#define ADDR_CAN_FILTERBANK16_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x280) )
#define ADDR_CAN_FILTERBANK17_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x284) )
#define ADDR_CAN_FILTERBANK18_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x288) )
#define ADDR_CAN_FILTERBANK19_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x28C) )
#define ADDR_CAN_FILTERBANK20_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x290) )
#define ADDR_CAN_FILTERBANK21_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x294) )
#define ADDR_CAN_FILTERBANK22_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x298) )
#define ADDR_CAN_FILTERBANK23_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x29C) )
#define ADDR_CAN_FILTERBANK24_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2A0) )
#define ADDR_CAN_FILTERBANK25_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2A4) )
#define ADDR_CAN_FILTERBANK26_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2A8) )
#define ADDR_CAN_FILTERBANK27_REGISTER1 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2AC) )

#define ADDR_CAN_FILTERBANK0_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2B0) )
#define ADDR_CAN_FILTERBANK1_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2B4) )
#define ADDR_CAN_FILTERBANK2_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2B8) )
#define ADDR_CAN_FILTERBANK3_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2BC) )
#define ADDR_CAN_FILTERBANK4_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2C0) )
#define ADDR_CAN_FILTERBANK5_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2C4) )
#define ADDR_CAN_FILTERBANK6_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2C8) )
#define ADDR_CAN_FILTERBANK7_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2CC) )
#define ADDR_CAN_FILTERBANK8_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2D0) )
#define ADDR_CAN_FILTERBANK9_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2D4) )
#define ADDR_CAN_FILTERBANK10_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2D8) )
#define ADDR_CAN_FILTERBANK11_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2DC) )
#define ADDR_CAN_FILTERBANK12_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2E0) )
#define ADDR_CAN_FILTERBANK13_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2E4) )
#define ADDR_CAN_FILTERBANK14_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2E8) )
#define ADDR_CAN_FILTERBANK15_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2EC) )
#define ADDR_CAN_FILTERBANK16_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2F0) )
#define ADDR_CAN_FILTERBANK17_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2F4) )
#define ADDR_CAN_FILTERBANK18_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2F8) )
#define ADDR_CAN_FILTERBANK19_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x2FC) )
#define ADDR_CAN_FILTERBANK20_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x300) )
#define ADDR_CAN_FILTERBANK21_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x304) )
#define ADDR_CAN_FILTERBANK22_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x308) )
#define ADDR_CAN_FILTERBANK23_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x30C) )
#define ADDR_CAN_FILTERBANK24_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x310) )
#define ADDR_CAN_FILTERBANK25_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x314) )
#define ADDR_CAN_FILTERBANK26_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x318) )
#define ADDR_CAN_FILTERBANK27_REGISTER2 ( (CAN_FILTERBANKi_REGISTERx*) ((CANx) + 0x31C) )

//CAN_ERRORSTATUS
/*Most recent error code*/
#define NO_ERROR 0x00
#define STUFF_ERROR 0x01
#define FORM_ERROR 0x02
#define ACK_ERROR 0x03
#define BIT_RECESSIVE_ERROR 0x04
#define BIT_DOMINANT_ERROR 0x05
#define CRC_ERROR 0x06
#define SETBY_SOFTWARE 0x07


//Enums----------------------------------------------------------------------

//CAN_FILTER_SCALE
enum _FilterSize {
	_16BIT_CAN = 0,
	_32BIT_CAN = 1
};

//CAN_FILTER_MODE
enum _FilterMode {
	MASK_MODE = 0,
	LIST_MODE = 1
};

//Struct for holding received bytes------------------------------------------
struct _Data {
	uint8_t byte0;
	uint8_t byte1;
	uint8_t byte2;
	uint8_t byte3;
	uint8_t byte4;
	uint8_t byte5;
	uint8_t byte6;
	uint8_t byte7;
};

//Clock Register-------------------------------------------------------------
typedef struct {
	const uint32_t reserved0:25;
	volatile uint32_t can1_StartTick:1;
	volatile uint32_t can2_StartTick:1;
	const uint32_t reserved1:5;
}CAN_CLOCK;


//CONTROL & STATUS REGISTERS-----------------------------------------------
typedef struct {
	volatile uint32_t send_InitializeModeRequest:1;
	volatile uint32_t send_SleepModeRequest:1;
	volatile uint32_t txOrderIdentifier0_txOrderChronological1:1;
	volatile uint32_t enable_LockRXWhenFull:1;
	volatile uint32_t disable_AutoRetransmit:1;
	volatile uint32_t enable_AutoWakeUp:1;
	volatile uint32_t enable_AutoExitBusOffState:1;
	volatile uint32_t enable_TimeTriggeredCommMode:1;
	const uint32_t reserved0:7;
	volatile uint32_t resetMaster_thenSleep:1;
	volatile uint32_t enable_FreezeDuringDebug:1;
	const uint32_t reserved:15;
}CAN_MASTER_CONTROL;

typedef struct {
	volatile uint32_t initializeModeRequestAccepted:1;
	volatile uint32_t sleepModeRequestAccepted:1;
	volatile uint32_t errorDetected:1;
	volatile uint32_t wakeUpDetected:1;
	volatile uint32_t inSleepMode:1;
	const uint32_t reserved0:3;
	volatile uint32_t inTransmitMode:1;
	volatile uint32_t inReceiveMode:1;
	volatile uint32_t rxVal_LastSamplePoint:1;
	volatile uint32_t rxSignal:1;
	const uint32_t reserved:20;
}CAN_MASTER_SATUS;

typedef struct {
	volatile uint32_t mailbox0_RequestCompleted:1;
	volatile uint32_t mailbox0_TransmitSuccess:1;
	volatile uint32_t mailbox0_ArbitrationLost:1;
	volatile uint32_t mailbox0_TransmitError:1;
	const uint32_t reserved0:3;
	volatile uint32_t send_Mailbox0TransmitAbortRequest:1;
	volatile uint32_t mailbox1_RequestCompleted:1;
	volatile uint32_t mailbox1_TransmitSuccess:1;
	volatile uint32_t mailbox1_ArbitrationLost:1;
	volatile uint32_t mailbox1_TransmitError:1;
	const uint32_t reserved1:3;
	volatile uint32_t send_Mailbox1TransmitAbortRequest:1;
	volatile uint32_t mailbox2_RequestCompleted:1;
	volatile uint32_t mailbox2_TransmitSuccess:1;
	volatile uint32_t mailbox2_ArbitrationLost:1;
	volatile uint32_t mailbox2_TransmitError:1;
	const uint32_t reserved2:3;
	volatile uint32_t send_Mailbox2TransmitAbortRequest:1;
	volatile uint32_t freeMailbox:2;
	volatile uint32_t mailbox0_NoTransmitRequestPending:1;
	volatile uint32_t mailbox1_NoTransmitRequestPending:1;
	volatile uint32_t mailbox2_NoTransmitRequestPending:1;
	volatile uint32_t mailbox0_HasLowestPriority:1;
	volatile uint32_t mailbox1_HasLowestPriority:1;
	volatile uint32_t mailbox2_HasLowestPriority:1;
}CAN_TRANSMIT_STATUS;

typedef struct {
	volatile uint32_t numOfMessagesWaitingInFIFO0:2;
	const uint32_t reserved0:1;
	volatile uint32_t messageFIFO0_Full:1;
	volatile uint32_t messageFIFO0_Overrun:1;
	volatile uint32_t release_FIFO0_OutputMailbox:1;
	const uint32_t reserved1:26;
}CAN_RECEIVE_FIFO0;

typedef struct {
	volatile uint32_t numOfMessagesWaitingInFIFO1:2;
	const uint32_t reserved0:1;
	volatile uint32_t messageFIFO1_Full:1;
	volatile uint32_t messageFIFO1_Overrun:1;
	volatile uint32_t release_FIFO1_OutputMailbox:1;
	const uint32_t reserved1:26;
}CAN_RECEIVE_FIFO1;

typedef struct {
	volatile uint32_t enable_TransmitMailboxEmptyInterrupt:1;
	volatile uint32_t enable_FIFO0MessagePendingInterrupt:1;
	volatile uint32_t enable_FIFO0FullInterrupt:1;
	volatile uint32_t enable_FIFO0OverrunInterrupt:1;
	volatile uint32_t enable_FIFO1MessagePendingInterrupt:1;
	volatile uint32_t enable_FIFO1FullInterrupt:1;
	volatile uint32_t enable_FIFO1OverrunInterrupt:1;
	const uint32_t reserved0:1;
	volatile uint32_t enable_ErrorWarningInterrupt:1;
	volatile uint32_t enable_ErrorPassiveInterrupt:1;
	volatile uint32_t enable_BusOffInterrupt:1;
	volatile uint32_t enable_LastErrorCodeInterrupt:1;
	const uint32_t reserved1:3;
	volatile uint32_t enable_ErrorInterrupt:1;
	volatile uint32_t enable_WakeupInterrupt:1;
	volatile uint32_t enable_SleepInterrupt:1;
	const uint32_t reserved2:14;
}CAN_INTERRUPTS;

typedef struct {
	volatile uint32_t errorWarning:1;
	volatile uint32_t ErrorPassive:1;
	volatile uint32_t busOff:1;
	const uint32_t reserved0:1;
	volatile uint32_t mostRecentErrorCode:3;
	const uint32_t reserved1:9;
	volatile uint32_t numOfTransmitErrors:8;
	volatile uint32_t numOfReceiveErrors:8;
}CAN_ERRORSTATUS;

typedef struct {
	volatile uint32_t rw_BaudRatePrescaler:10;
	const uint32_t reserved0:6;
	volatile uint32_t rw_TimeSegment1:4; //No Macros available
	volatile uint32_t rw_TimeSegment2:3; //No Macros available
	const uint32_t reserved1:1;
	volatile uint32_t rw_ReSyncJumpWidth:2; //No Macros available
	const uint32_t reserved2:4;
	volatile uint32_t enable_LoopbackMode:1;
	volatile uint32_t enable_SilentMode:1;
}CAN_BITTIMING;


//MAILBOX REGISTERS-------------------------------------------------------
typedef union {
	
	struct {
		volatile uint32_t request_TransmissionFromMailbox:1;
		volatile uint32_t enable_RemoteFrame:1;
		volatile uint32_t enable_ExtendedIdentifier:1;
		volatile uint32_t rw_ExtendedIdentifier:26;
		const uint32_t reserved:3;
	}ExtendedIdentifier;

	struct {
		volatile uint32_t request_TransmissionFromMailbox:1;
		volatile uint32_t enable_RemoteFrame:1;
		const uint32_t reserved:19;
		volatile uint32_t rw_StandardIdentifier:11;
	}StandardIdentifier;

}CAN_TX_MAILBOX_IDENTIFIER;

typedef struct {
	volatile uint32_t rw_DataLen_InBytes:4; //0 to 8 Bytes
	const uint32_t reserved0:4;
	volatile uint32_t transmit_GlobalTime:1;
	const uint32_t reserved1:7;
	volatile uint32_t rw_MessageTimeStamp:16;
}CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP;

typedef struct {
	volatile uint32_t rw_DataByte0:8;
	volatile uint32_t rw_DataByte1:8;
	volatile uint32_t rw_DataByte2:8;
	volatile uint32_t rw_DataByte3:8;
}CAN_TX_MAILBOX_DATALOW;

typedef struct {
	volatile uint32_t rw_DataByte4:8;
	volatile uint32_t rw_DataByte5:8;
	volatile uint32_t rw_DataByte6:8;
	volatile uint32_t rw_DataByte7:8;

}CAN_TX_MAILBOX_DATAHIGH;

typedef struct {
	struct {
		const uint32_t reserved0:1;
		volatile uint32_t enable_RemoteFrame:1;
		volatile uint32_t enable_ExtendedIdentifier:1;
		volatile uint32_t read_ExtendedIdentifier:26;
		const uint32_t reserved1:3;
	}ExtendedIdentifier;

	struct {
		const uint32_t reserved0:1;
		volatile uint32_t enable_RemoteFrame:1;
		const uint32_t reserved1:19;
		volatile uint32_t read_StandardIdentifier:11;
	}StandardIdentifier;
}CAN_RX_MAILBOX_IDENTIFIER;

typedef struct {
	volatile uint32_t read_DataLen_InBytes:4;
	const uint32_t reserved0:4;
	volatile uint32_t read_IdentifierFilterMatchIndex:8;
	volatile uint32_t read_MessageTimeStamp:16;
}CAN_RX_MAILBOX_DATALENCNTRL_TIMESTAMP;

typedef struct {
	volatile uint32_t read_DataByte0:8;
	volatile uint32_t read_DataByte1:8;
	volatile uint32_t read_DataByte2:8;
	volatile uint32_t read_DataByte3:8;
}CAN_RX_MAILBOX_DATALOW;

typedef struct {
	volatile uint32_t read_DataByte4:8;
	volatile uint32_t read_DataByte5:8;
	volatile uint32_t read_DataByte6:8;
	volatile uint32_t read_DataByte7:8;
}CAN_RX_MAILBOX_DATAHIGH;



//FILTER REGISTERS--------------------------------------------------------
typedef struct {
	volatile uint32_t filterActive0_filterReadyToInitialize1:1;
	const uint32_t reserved0:7;
	volatile uint32_t set_CAN2StartBank:6;
	const uint32_t reserved1:18;
}CAN_FILTER_MASTER;

typedef struct {
	volatile uint32_t filter0IDMaskMode0_filter0IDListMode1:1;
	volatile uint32_t filter1IDMaskMode0_filter1IDListMode1:1;
	volatile uint32_t filter2IDMaskMode0_filter2IDListMode1:1;
	volatile uint32_t filter3IDMaskMode0_filter3IDListMode1:1;
	volatile uint32_t filter4IDMaskMode0_filter4IDListMode1:1;
	volatile uint32_t filter5IDMaskMode0_filter5IDListMode1:1;
	volatile uint32_t filter6IDMaskMode0_filter6IDListMode1:1;
	volatile uint32_t filter7IDMaskMode0_filter7IDListMode1:1;
	volatile uint32_t filter8IDMaskMode0_filter8IDListMode1:1;
	volatile uint32_t filter9IDMaskMode0_filter9IDListMode1:1;
	volatile uint32_t filter10IDMaskMode0_filter10IDListMode1:1;
	volatile uint32_t filter11IDMaskMode0_filter11IDListMode1:1;
	volatile uint32_t filter12IDMaskMode0_filter12IDListMode1:1;
	volatile uint32_t filter13IDMaskMode0_filter13IDListMode1:1;
	volatile uint32_t filter14IDMaskMode0_filter14IDListMode1:1;
	volatile uint32_t filter15IDMaskMode0_filter15IDListMode1:1;
	volatile uint32_t filter16IDMaskMode0_filter16IDListMode1:1;
	volatile uint32_t filter17IDMaskMode0_filter17IDListMode1:1;
	volatile uint32_t filter18IDMaskMode0_filter18IDListMode1:1;
	volatile uint32_t filter19IDMaskMode0_filter19IDListMode1:1;
	volatile uint32_t filter20IDMaskMode0_filter20IDListMode1:1;
	volatile uint32_t filter21IDMaskMode0_filter21IDListMode1:1;
	volatile uint32_t filter22IDMaskMode0_filter22IDListMode1:1;
	volatile uint32_t filter23IDMaskMode0_filter23IDListMode1:1;
	volatile uint32_t filter24IDMaskMode0_filter24IDListMode1:1;
	volatile uint32_t filter25IDMaskMode0_filter25IDListMode1:1;
	volatile uint32_t filter26IDMaskMode0_filter26IDListMode1:1;
	volatile uint32_t filter27IDMaskMode0_filter27IDListMode1:1;
	const uint32_t reserved:4;
}CAN_FILTER_MODE;

typedef struct {
	volatile uint32_t filter0Size16B0_filter0Size32B1:1;
	volatile uint32_t filter1Size16B0_filter1Size32B1:1;
	volatile uint32_t filter2Size16B0_filter2Size32B1:1;
	volatile uint32_t filter3Size16B0_filter3Size32B1:1;
	volatile uint32_t filter4Size16B0_filter4Size32B1:1;
	volatile uint32_t filter5Size16B0_filter5Size32B1:1;
	volatile uint32_t filter6Size16B0_filter6Size32B1:1;
	volatile uint32_t filter7Size16B0_filter7Size32B1:1;
	volatile uint32_t filter8Size16B0_filter8Size32B1:1;
	volatile uint32_t filter9Size16B0_filter9Size32B1:1;
	volatile uint32_t filter10Size16B0_filter10Size32B1:1;
	volatile uint32_t filter11Size16B0_filter11Size32B1:1;
	volatile uint32_t filter12Size16B0_filter12Size32B1:1;
	volatile uint32_t filter13Size16B0_filter13Size32B1:1;
	volatile uint32_t filter14Size16B0_filter14Size32B1:1;
	volatile uint32_t filter15Size16B0_filter15Size32B1:1;
	volatile uint32_t filter16Size16B0_filter16Size32B1:1;
	volatile uint32_t filter17Size16B0_filter17Size32B1:1;
	volatile uint32_t filter18Size16B0_filter18Size32B1:1;
	volatile uint32_t filter19Size16B0_filter19Size32B1:1;
	volatile uint32_t filter20Size16B0_filter20Size32B1:1;
	volatile uint32_t filter21Size16B0_filter21Size32B1:1;
	volatile uint32_t filter22Size16B0_filter22Size32B1:1;
	volatile uint32_t filter23Size16B0_filter23Size32B1:1;
	volatile uint32_t filter24Size16B0_filter24Size32B1:1;
	volatile uint32_t filter25Size16B0_filter25Size32B1:1;
	volatile uint32_t filter26Size16B0_filter26Size32B1:1;
	volatile uint32_t filter27Size16B0_filter27Size32B1:1;
	const uint32_t reserved:4;
}CAN_FILTER_SCALE;

typedef struct {
	volatile uint32_t filter0ToFIFO0_filter0ToFIFO1:1;
	volatile uint32_t filter1ToFIFO0_filter1ToFIFO1:1;
	volatile uint32_t filter2ToFIFO0_filter2ToFIFO1:1;
	volatile uint32_t filter3ToFIFO0_filter3ToFIFO1:1;
	volatile uint32_t filter4ToFIFO0_filter4ToFIFO1:1;
	volatile uint32_t filter5ToFIFO0_filter5ToFIFO1:1;
	volatile uint32_t filter6ToFIFO0_filter6ToFIFO1:1;
	volatile uint32_t filter7ToFIFO0_filter7ToFIFO1:1;
	volatile uint32_t filter8ToFIFO0_filter8ToFIFO1:1;
	volatile uint32_t filter9ToFIFO0_filter9ToFIFO1:1;
	volatile uint32_t filter10ToFIFO0_filter10ToFIFO1:1;
	volatile uint32_t filter11ToFIFO0_filter11ToFIFO1:1;
	volatile uint32_t filter12ToFIFO0_filter12ToFIFO1:1;
	volatile uint32_t filter13ToFIFO0_filter13ToFIFO1:1;
	volatile uint32_t filter14ToFIFO0_filter14ToFIFO1:1;
	volatile uint32_t filter15ToFIFO0_filter15ToFIFO1:1;
	volatile uint32_t filter16ToFIFO0_filter16ToFIFO1:1;
	volatile uint32_t filter17ToFIFO0_filter17ToFIFO1:1;
	volatile uint32_t filter18ToFIFO0_filter18ToFIFO1:1;
	volatile uint32_t filter19ToFIFO0_filter19ToFIFO1:1;
	volatile uint32_t filter20ToFIFO0_filter20ToFIFO1:1;
	volatile uint32_t filter21ToFIFO0_filter21ToFIFO1:1;
	volatile uint32_t filter22ToFIFO0_filter22ToFIFO1:1;
	volatile uint32_t filter23ToFIFO0_filter23ToFIFO1:1;
	volatile uint32_t filter24ToFIFO0_filter24ToFIFO1:1;
	volatile uint32_t filter25ToFIFO0_filter25ToFIFO1:1;
	volatile uint32_t filter26ToFIFO0_filter26ToFIFO1:1;
	volatile uint32_t filter27ToFIFO0_filter27ToFIFO1:1;
	const uint32_t reserved:4;
}CAN_FILTER_FIFO_ASSIGNMENT;

typedef struct {
	volatile uint32_t enable_Filter0:1;
	volatile uint32_t enable_Filter1:1;
	volatile uint32_t enable_Filter2:1;
	volatile uint32_t enable_Filter3:1;
	volatile uint32_t enable_Filter4:1;
	volatile uint32_t enable_Filter5:1;
	volatile uint32_t enable_Filter6:1;
	volatile uint32_t enable_Filter7:1;
	volatile uint32_t enable_Filter8:1;
	volatile uint32_t enable_Filter9:1;
	volatile uint32_t enable_Filter10:1;
	volatile uint32_t enable_Filter11:1;
	volatile uint32_t enable_Filter12:1;
	volatile uint32_t enable_Filter13:1;
	volatile uint32_t enable_Filter14:1;
	volatile uint32_t enable_Filter15:1;
	volatile uint32_t enable_Filter16:1;
	volatile uint32_t enable_Filter17:1;
	volatile uint32_t enable_Filter18:1;
	volatile uint32_t enable_Filter19:1;
	volatile uint32_t enable_Filter20:1;
	volatile uint32_t enable_Filter21:1;
	volatile uint32_t enable_Filter22:1;
	volatile uint32_t enable_Filter23:1;
	volatile uint32_t enable_Filter24:1;
	volatile uint32_t enable_Filter25:1;
	volatile uint32_t enable_Filter26:1;
	volatile uint32_t enable_Filter27:1;
	const uint32_t reserved:4;
}CAN_FILTER_ACTIVATION;

typedef struct {
	volatile uint32_t bit0_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit1_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit2_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit3_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit4_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit5_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit6_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit7_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit8_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit9_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit10_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit11_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit12_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit13_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit14_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit15_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit16_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit17_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit18_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit19_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit20_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit21_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit22_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit23_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit24_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit25_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit26_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit27_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit28_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit29_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit30_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit31_Expects0_Expects1OrMatch1:1;
	volatile uint32_t bit32_Expects0_Expects1OrMatch1:1;
}CAN_FILTERBANKi_REGISTERx;


#endif
