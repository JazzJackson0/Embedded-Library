//STM32F407 Driver
#ifndef CAN_H_
#define CAN_H_

#include <stdint.h>

typedef enum _FilterSize E_FilterSize;
typedef enum _FilterMode E_FilterMode;
typedef union _Data Received_Data;
typedef struct _filter Filter;

//DECLARATIONS
void CAN_SetBitTime(uint8_t canNum, uint8_t baudRatePrescale, uint8_t resyncJump, uint8_t timeSeg1, uint8_t timeSeg2);
void CAN_SetAcceptanceFilter(uint8_t canNum, Filter *filterInfo);
void CAN_SetTXMailbox(uint8_t canNum, uint8_t mailboxNum, uint64_t standardID, uint8_t numOfBytes);
void CAN_SetRXMailbox(uint8_t canNum, uint8_t mailboxNum, uint64_t standardID, uint8_t numOfBytes);
void CAN_Init_and_Start(uint8_t canNum);
uint8_t CAN_Transmit(uint8_t canNum, uint8_t mailboxNum, uint8_t *dataBuffer, uint8_t numOfBytes);
Received_Data* CAN_Receive(uint8_t canNum, uint8_t mailboxNum, uint8_t numOfBytes);

//CLOCK
#define CLOCK 0x40023800
#define APB1 0x40
#define ADDR_CAN_CLOCK ( (CAN_CLOCK*) ((CLOCK) + APB1) )

//CANx
typedef struct _can CANx;
typedef struct _mailbox_filters MAIL_FILTERSx;
typedef union _filterBanks FILTER_BANKSx;
#define CAN_BASE 0x40006000
//
#define ADDR_CAN1 ( (CANx*) ((CAN_BASE) + 0x400) )
#define ADDR_CAN1_MAIL_FILTERS ( (MAIL_FILTERSx*) ((CAN_BASE) + (0x400 + 0x180)) )
#define ADDR_CAN1_FILTERBANKS ( (FILTER_BANKSx*) ((CAN_BASE) + (0x400 + 0x240) ) )
//
#define ADDR_CAN2 ( (CANx*) ((CAN_BASE) + 0x800) )
#define ADDR_CAN2_MAIL_FILTERS ( (MAIL_FILTERSx*) ((CAN_BASE) + (0x800 + 0x180)) )
#define ADDR_CAN2_FILTERBANKS ( (FILTER_BANKSx*) ((CAN_BASE) + (0x400 + 0x2B0) ) )

//Filter 
struct _filter{
	uint8_t filterNum;
	E_FilterSize filterSize;
	E_FilterMode filterMode;
	uint64_t filterBankVal;
	uint8_t filterBankRegNum; // 1 or 2
	uint8_t fifoNum;
};

//Byte Container
union _Data {
	struct {
		uint8_t byte0;
		uint8_t byte1;
		uint8_t byte2;
		uint8_t byte3;
		uint8_t byte4;
		uint8_t byte5;
		uint8_t byte6;
		uint8_t byte7;
	};
	
	uint8_t dataIterator[8];
};

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


//Clock Register-------------------------------------------------------------
typedef struct {
	const uint32_t reserved0:25;
	volatile uint32_t can1_StartTick:1;
	volatile uint32_t can2_StartTick:1;
	const uint32_t reserved1:5;
}CAN_CLOCK;


//CONTROL & STATUS REGISTERS-----------------------------------------------
typedef struct {
	const uint32_t reserved1:32;
}CAN_RESERVED;

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

typedef union {
	struct {
		volatile uint32_t rw_DataByte0:8;
		volatile uint32_t rw_DataByte1:8;
		volatile uint32_t rw_DataByte2:8;
		volatile uint32_t rw_DataByte3:8;
	};
	uint8_t dataIterator[4];
}CAN_TX_MAILBOX_DATALOW;

typedef union {
	struct {
		volatile uint32_t rw_DataByte4:8;
		volatile uint32_t rw_DataByte5:8;
		volatile uint32_t rw_DataByte6:8;
		volatile uint32_t rw_DataByte7:8;
	};
	uint8_t dataIterator[4];

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

typedef union {
	struct {
		volatile uint32_t read_DataByte0:8;
		volatile uint32_t read_DataByte1:8;
		volatile uint32_t read_DataByte2:8;
		volatile uint32_t read_DataByte3:8;
	};

	uint8_t dataIterator[4];
	
}CAN_RX_MAILBOX_DATALOW;

typedef union {
	struct {
		volatile uint32_t read_DataByte4:8;
		volatile uint32_t read_DataByte5:8;
		volatile uint32_t read_DataByte6:8;
		volatile uint32_t read_DataByte7:8;
	};

	uint8_t dataIterator[4];
	
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



struct _can {
	CAN_MASTER_CONTROL MasterControlReg; // 0x00
	CAN_MASTER_SATUS MasterStatusReg; // 0x04
	CAN_TRANSMIT_STATUS TransmitStatReg; // 0x08
	CAN_RECEIVE_FIFO0 RXFIFOReg1; // 0x0C
	CAN_RECEIVE_FIFO1 RXFIFOReg2; // 0x10
	CAN_INTERRUPTS InterruptsReg; // 0x14
	CAN_ERRORSTATUS ErrorStatusReg; // 0x18
	CAN_BITTIMING BitTimingReg; // 0x1C
};

struct _mailbox_filters {
	CAN_TX_MAILBOX_IDENTIFIER TXMailBox0IDReg; //0x180
	CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP TXMaiBox0DataLenCtrlTimeStampReg; //0x184
	CAN_TX_MAILBOX_DATALOW TXMailBox0DataLowReg; //0x188
	CAN_TX_MAILBOX_DATAHIGH TXMailBox0DataHighReg; //0x18C

	CAN_TX_MAILBOX_IDENTIFIER TXMailBox1IDReg; //0x190
	CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP TXMaiBox1DataLenCtrlTimeStampReg; //0x194
	CAN_TX_MAILBOX_DATALOW TXMailBox1DataLowReg; //0x198
	CAN_TX_MAILBOX_DATAHIGH TXMailBox1DataHighReg; //0x19C

	CAN_TX_MAILBOX_IDENTIFIER TXMailBox2IDReg; //0x1A0
	CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP TXMaiBox2DataLenCtrlTimeStampReg; //0x1A4
	CAN_TX_MAILBOX_DATALOW TXMailBox2DataLowReg; //0x1A8
	CAN_TX_MAILBOX_DATAHIGH TXMailBox2DataHighReg; //0x1AC
	
	CAN_RX_MAILBOX_IDENTIFIER RXMailBox0IDReg; //0x1B0
	CAN_RX_MAILBOX_DATALENCNTRL_TIMESTAMP RXMaiBox0DataLenCtrlTimeStampReg; //0x1B4
	CAN_RX_MAILBOX_DATALOW RXMailBox0DataLowReg; //0x1B8
	CAN_RX_MAILBOX_DATAHIGH RXMailBox0DataHighReg; //0x1BC

	CAN_RX_MAILBOX_IDENTIFIER RXMailBox1IDReg; //0x1C0
	CAN_RX_MAILBOX_DATALENCNTRL_TIMESTAMP RXMaiBox1DataLenCtrlTimeStampReg; //0x1C4
	CAN_RX_MAILBOX_DATALOW RXMailBox1DataLowReg; //0x1C8
	CAN_RX_MAILBOX_DATAHIGH RXMailBox1DataHighReg; //0x1CC
	CAN_RESERVED reserved0; // 0x1D0
	CAN_RESERVED reserved1; // 0x1D4
	CAN_RESERVED reserved2; // 0x1D8
	CAN_RESERVED reserved3; // 0x1DC
	CAN_RESERVED reserved4; // 0x1E0
	CAN_RESERVED reserved5; // 0x1E4
	CAN_RESERVED reserved6; // 0x1E8
	CAN_RESERVED reserved7; // 0x1EC
	CAN_RESERVED reserved8; // 0x1F0
	CAN_RESERVED reserved9; // 0x1F4
	CAN_RESERVED reserved10; // 0x1F8
	CAN_RESERVED reserved11; // 0x1FC
	CAN_FILTER_MASTER FilterMasterReg; // 0x200
	CAN_FILTER_MODE FilterModeReg; // 0x204
	CAN_RESERVED reserved12; // 0x208
	CAN_FILTER_SCALE FilterScaleReg; // 0x20C
	CAN_RESERVED reserved13; // 0x210
	CAN_FILTER_FIFO_ASSIGNMENT FilterFIFOAssignReg; // 0x214
	CAN_RESERVED reserved14; // 0x218
	CAN_FILTER_ACTIVATION FilterActivationReg; // 0x21C
	CAN_RESERVED reserved15; // 0x220
	CAN_RESERVED reserved16; // 0x224
	CAN_RESERVED reserved17; // 0x228
	CAN_RESERVED reserved18; // 0x22C
	CAN_RESERVED reserved19; // 0x230
	CAN_RESERVED reserved20; // 0x234
	CAN_RESERVED reserved21; // 0x238
	CAN_RESERVED reserved22; // 0x23C
};

union _filterBanks {
	struct  {
		CAN_FILTERBANKi_REGISTERx FilterBank0; // Reg1: 0x240 | Reg2: 0x2B0
		CAN_FILTERBANKi_REGISTERx FilterBank1; // Reg1: 00x244 | Reg2: 0x2B4
		CAN_FILTERBANKi_REGISTERx FilterBank2; // Reg1: 00x248 | Reg2: 0x2B8
		CAN_FILTERBANKi_REGISTERx FilterBank3; // Reg1: 00x24C | Reg2: 0x2BC
		CAN_FILTERBANKi_REGISTERx FilterBank4; // Reg1: 00x250 | Reg2: 0x2C0
		CAN_FILTERBANKi_REGISTERx FilterBank5; // Reg1: 00x254 | Reg2: 0x2C4
		CAN_FILTERBANKi_REGISTERx FilterBank6; // Reg1: 00x258 | Reg2: 0x2C8
		CAN_FILTERBANKi_REGISTERx FilterBank7; // Reg1: 00x25C | Reg2: 0x2CC
		CAN_FILTERBANKi_REGISTERx FilterBank8; // Reg1: 00x260 | Reg2: 0x2D0
		CAN_FILTERBANKi_REGISTERx FilterBank9; // Reg1: 00x264 | Reg2: 0x2D4
		CAN_FILTERBANKi_REGISTERx FilterBank10; // Reg1: 00x268 | Reg2: 0x2D8
		CAN_FILTERBANKi_REGISTERx FilterBank11; // Reg1: 00x26C | Reg2: 0x2DC
		CAN_FILTERBANKi_REGISTERx FilterBank12; // Reg1: 00x270 | Reg2: 0x2E0
		CAN_FILTERBANKi_REGISTERx FilterBank13; // Reg1: 00x274 | Reg2: 0x2E4
		CAN_FILTERBANKi_REGISTERx FilterBank14; // Reg1: 00x278 | Reg2: 0x2E8
		CAN_FILTERBANKi_REGISTERx FilterBank15; // Reg1: 00x27C | Reg2: 0x2EC
		CAN_FILTERBANKi_REGISTERx FilterBank16; // Reg1: 00x280 | Reg2: 0x2F0
		CAN_FILTERBANKi_REGISTERx FilterBank17; // Reg1: 00x284 | Reg2: 0x2F4
		CAN_FILTERBANKi_REGISTERx FilterBank18; // Reg1: 00x288 | Reg2: 0x2F8
		CAN_FILTERBANKi_REGISTERx FilterBank19; // Reg1: 00x28C | Reg2: 0x2FC
		CAN_FILTERBANKi_REGISTERx FilterBank20; // Reg1: 00x290 | Reg2: 0x300
		CAN_FILTERBANKi_REGISTERx FilterBank21; // Reg1: 00x294 | Reg2: 0x304
		CAN_FILTERBANKi_REGISTERx FilterBank22; // Reg1: 00x298 | Reg2: 0x308
		CAN_FILTERBANKi_REGISTERx FilterBank23; // Reg1: 00x29C | Reg2: 0x30C
		CAN_FILTERBANKi_REGISTERx FilterBank24; // Reg1: 00x2A0 | Reg2: 0x310
		CAN_FILTERBANKi_REGISTERx FilterBank25; // Reg1: 00x2A4 | Reg2: 0x314
		CAN_FILTERBANKi_REGISTERx FilterBank26; // Reg1: 00x2A8 | Reg2: 0x318
		CAN_FILTERBANKi_REGISTERx FilterBank27; // Reg1: 00x2AC | Reg2: 0x31C
	};

	CAN_FILTERBANKi_REGISTERx Banks[28];
};


#endif
