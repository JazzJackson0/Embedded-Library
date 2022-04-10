#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "can_STM32F446.h"
#include "gpio_STM32F446.h"



//Static Prototypes----------------------------------------------------
static void CAN_PinInit(uint8_t canNum);
static CAN_FILTERBANKi_REGISTERx* Set_FilterBankReg(uint8_t filterNumber, uint8_t registerNum);
static void Set_FilterNumber_AssignFIFO_SetFilterMode(uint8_t filterNumber, E_FilterSize filterSize, uint8_t fifoNumber, E_FilterMode filterMode);
static CAN_TX_MAILBOX_IDENTIFIER* Set_TXMailboxID(uint8_t canNum);
static CAN_RX_MAILBOX_IDENTIFIER* Set_RXMailboxID(uint8_t canNum);
static CAN_RX_MAILBOX_DATALENCNTRL_TIMESTAMP* Set_RXDataCtrl_TimeStamp(uint8_t canNum);
static CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP* Set_TXDataCtrl_TimeStamp(uint8_t canNum);
static CAN_TX_MAILBOX_DATALOW* Set_TXDataLow(uint8_t canNum);
static CAN_TX_MAILBOX_DATAHIGH* Set_TXDataHigh(uint8_t canNum);
static CAN_RX_MAILBOX_DATALOW* Set_RXDataLow(uint8_t canNum);
static CAN_RX_MAILBOX_DATAHIGH* Set_RXDataHigh(uint8_t canNum);


//Global Variables-------------------------------------------------------
CAN_CLOCK *const CANClock = ADDR_CAN_CLOCK;

//CAN
CAN_MASTER_CONTROL *const MasterControl = ADDR_CAN_MASTER_CONTROL;
CAN_MASTER_SATUS *const MasterStat = ADDR_CAN_MASTER_SATUS;
CAN_BITTIMING *const BitTime = ADDR_CAN_BITTIMING;
CAN_TRANSMIT_STATUS *const TXStat = ADDR_CAN_TRANSMIT_STATUS;

//Tx 1
CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP *const TXDataCtrlTimeStamp_1 = ADDR_CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP_1;
CAN_TX_MAILBOX_IDENTIFIER *const TXMailboxID_1 = ADDR_CAN_TX_MAILBOX_IDENTIFIER_1;
CAN_TX_MAILBOX_DATALOW *const TXMailboxDataLow_1 = ADDR_CAN_TX_MAILBOX_DATALOW_1;
CAN_TX_MAILBOX_DATAHIGH *const TXMailboxDataHigh_1 = ADDR_CAN_TX_MAILBOX_DATAHIGH_1;

//Rx 1
CAN_RX_MAILBOX_DATALENCNTRL_TIMESTAMP *const RXDataCtrlTimeStamp_1 = ADDR_CAN_RX_MAILBOX_DATALENCNTRL_TIMESTAMP_1;
CAN_RX_MAILBOX_IDENTIFIER *const RXMailboxID_1 = ADDR_CAN_RX_MAILBOX_IDENTIFIER_1;
CAN_RX_MAILBOX_DATALOW *const RXMailboxDataLow_1 = ADDR_CAN_RX_MAILBOX_DATALOW_1;
CAN_RX_MAILBOX_DATAHIGH *const RXMailboxDataHigh_1 = ADDR_CAN_RX_MAILBOX_DATAHIGH_1;

//Tx 2
CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP *const TXDataCtrlTimeStamp_2 = ADDR_CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP_2;
CAN_TX_MAILBOX_IDENTIFIER *const TXMailboxID_2 = ADDR_CAN_TX_MAILBOX_IDENTIFIER_2;
CAN_TX_MAILBOX_DATALOW *const TXMailboxDataLow_2 = ADDR_CAN_TX_MAILBOX_DATALOW_2;
CAN_TX_MAILBOX_DATAHIGH *const TXMailboxDataHigh_2 = ADDR_CAN_TX_MAILBOX_DATAHIGH_2;

//Rx 2
CAN_RX_MAILBOX_DATALENCNTRL_TIMESTAMP *const RXDataCtrlTimeStamp_2 = ADDR_CAN_RX_MAILBOX_DATALENCNTRL_TIMESTAMP_2;
CAN_RX_MAILBOX_IDENTIFIER *const RXMailboxID_2 = ADDR_CAN_RX_MAILBOX_IDENTIFIER_2;
CAN_RX_MAILBOX_DATALOW *const RXMailboxDataLow_2 = ADDR_CAN_RX_MAILBOX_DATALOW_2;
CAN_RX_MAILBOX_DATAHIGH *const RXMailboxDataHigh_2 = ADDR_CAN_RX_MAILBOX_DATAHIGH_2;

//Filters
CAN_FILTER_MASTER *const FilterMaster = ADDR_CAN_FILTER_MASTER;
CAN_FILTER_MODE *const FilterMode = ADDR_CAN_FILTER_MODE;
CAN_FILTER_SCALE *const FilterScale = ADDR_CAN_FILTER_SCALE;
CAN_FILTER_FIFO_ASSIGNMENT *const FilterFIFOAssign = ADDR_CAN_FILTER_FIFO_ASSIGNMENT;
CAN_FILTER_ACTIVATION *const FilterActivate = ADDR_CAN_FILTER_ACTIVATION;

//Filter Banks - Register 1
CAN_FILTERBANKi_REGISTERx *const FilterBank0_R1 = ADDR_CAN_FILTERBANK0_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank1_R1 = ADDR_CAN_FILTERBANK1_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank2_R1 = ADDR_CAN_FILTERBANK2_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank3_R1 = ADDR_CAN_FILTERBANK3_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank4_R1 = ADDR_CAN_FILTERBANK4_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank5_R1 = ADDR_CAN_FILTERBANK5_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank6_R1 = ADDR_CAN_FILTERBANK6_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank7_R1 = ADDR_CAN_FILTERBANK7_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank8_R1 = ADDR_CAN_FILTERBANK8_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank9_R1 = ADDR_CAN_FILTERBANK9_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank10_R1 = ADDR_CAN_FILTERBANK10_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank11_R1 = ADDR_CAN_FILTERBANK11_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank12_R1 = ADDR_CAN_FILTERBANK12_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank13_R1 = ADDR_CAN_FILTERBANK13_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank14_R1 = ADDR_CAN_FILTERBANK14_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank15_R1 = ADDR_CAN_FILTERBANK15_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank16_R1 = ADDR_CAN_FILTERBANK16_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank17_R1 = ADDR_CAN_FILTERBANK17_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank18_R1 = ADDR_CAN_FILTERBANK18_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank19_R1 = ADDR_CAN_FILTERBANK19_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank20_R1 = ADDR_CAN_FILTERBANK20_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank21_R1 = ADDR_CAN_FILTERBANK21_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank22_R1 = ADDR_CAN_FILTERBANK22_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank23_R1 = ADDR_CAN_FILTERBANK23_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank24_R1 = ADDR_CAN_FILTERBANK24_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank25_R1 = ADDR_CAN_FILTERBANK25_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank26_R1 = ADDR_CAN_FILTERBANK26_REGISTER1;
CAN_FILTERBANKi_REGISTERx *const FilterBank27_R1 = ADDR_CAN_FILTERBANK27_REGISTER1;

//Filters Register 2
CAN_FILTERBANKi_REGISTERx *const FilterBank0_R2 = ADDR_CAN_FILTERBANK0_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank1_R2 = ADDR_CAN_FILTERBANK1_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank2_R2 = ADDR_CAN_FILTERBANK2_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank3_R2 = ADDR_CAN_FILTERBANK3_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank4_R2 = ADDR_CAN_FILTERBANK4_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank5_R2 = ADDR_CAN_FILTERBANK5_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank6_R2 = ADDR_CAN_FILTERBANK6_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank7_R2 = ADDR_CAN_FILTERBANK7_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank8_R2 = ADDR_CAN_FILTERBANK8_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank9_R2 = ADDR_CAN_FILTERBANK9_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank10_R2 = ADDR_CAN_FILTERBANK10_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank11_R2 = ADDR_CAN_FILTERBANK11_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank12_R2 = ADDR_CAN_FILTERBANK12_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank13_R2 = ADDR_CAN_FILTERBANK13_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank14_R2 = ADDR_CAN_FILTERBANK14_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank15_R2 = ADDR_CAN_FILTERBANK15_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank16_R2 = ADDR_CAN_FILTERBANK16_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank17_R2 = ADDR_CAN_FILTERBANK17_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank18_R2 = ADDR_CAN_FILTERBANK18_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank19_R2 = ADDR_CAN_FILTERBANK19_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank20_R2 = ADDR_CAN_FILTERBANK20_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank21_R2 = ADDR_CAN_FILTERBANK21_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank22_R2 = ADDR_CAN_FILTERBANK22_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank23_R2 = ADDR_CAN_FILTERBANK23_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank24_R2 = ADDR_CAN_FILTERBANK24_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank25_R2 = ADDR_CAN_FILTERBANK25_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank26_R2 = ADDR_CAN_FILTERBANK26_REGISTER2;
CAN_FILTERBANKi_REGISTERx *const FilterBank27_R2 = ADDR_CAN_FILTERBANK27_REGISTER2;


/*

For 1Mbps Bit Rate 
        + Prescaler = 1
        + Num of Time Quanta = 16
            + Seg 1 = 13
            + Seg 2 = 2
            + Resync Jump Width = 1 (Always 1)
            + 13 + 2 + 1 = 16
		+ Obtained from bittiming.can

*/
void CAN_SetBitTime(uint8_t baudRatePrescale, uint8_t resyncJump, uint8_t timeSeg1, uint8_t timeSeg2) {
	
	BitTime->rw_BaudRatePrescaler = baudRatePrescale;
	BitTime->rw_ReSyncJumpWidth = resyncJump;
	BitTime->rw_TimeSegment1 = timeSeg1;
	BitTime->rw_TimeSegment2 = timeSeg2;
}

void CAN_SetAcceptanceFilter(uint8_t filterNum, E_FilterSize filterSize, E_FilterMode filterMode, uint64_t filterBankVal, uint8_t fifoNum) {

	FilterMaster->filterActive0_filterReadyToInitialize1 = 1;
	
	Set_FilterNumber_AssignFIFO_SetFilterMode(filterNum, filterSize, fifoNum, filterMode);
	CAN_FILTERBANKi_REGISTERx *const FilterBank = Set_FilterBankReg(filterNum, 1); //Register Number: Harcoded to 1 out of 2.

	FilterBank->bit0_Expects0_Expects1OrMatch1 = filterBankVal % 10;
	filterBankVal /= 10;
	FilterBank->bit1_Expects0_Expects1OrMatch1 = filterBankVal % 10;
	filterBankVal /= 10;
	FilterBank->bit2_Expects0_Expects1OrMatch1 = filterBankVal % 10;
	filterBankVal /= 10;
	FilterBank->bit3_Expects0_Expects1OrMatch1 = filterBankVal % 10;
	filterBankVal /= 10;
	FilterBank->bit4_Expects0_Expects1OrMatch1 = filterBankVal % 10;
	filterBankVal /= 10;
	FilterBank->bit5_Expects0_Expects1OrMatch1 = filterBankVal % 10;
	filterBankVal /= 10;
	FilterBank->bit6_Expects0_Expects1OrMatch1 = filterBankVal % 10;
	filterBankVal /= 10;
	FilterBank->bit7_Expects0_Expects1OrMatch1 = filterBankVal % 10;
	filterBankVal /= 10;
	FilterBank->bit8_Expects0_Expects1OrMatch1 = filterBankVal % 10;
	filterBankVal /= 10;
	FilterBank->bit9_Expects0_Expects1OrMatch1 = filterBankVal % 10;
	filterBankVal /= 10;
	FilterBank->bit10_Expects0_Expects1OrMatch1 = filterBankVal % 10;
	filterBankVal /= 10;
	FilterBank->bit11_Expects0_Expects1OrMatch1 = filterBankVal % 10;
	filterBankVal /= 10;
	FilterBank->bit12_Expects0_Expects1OrMatch1 = filterBankVal % 10;
	filterBankVal /= 10;
	FilterBank->bit13_Expects0_Expects1OrMatch1 = filterBankVal % 10;
	filterBankVal /= 10;
	FilterBank->bit14_Expects0_Expects1OrMatch1 = filterBankVal % 10;
	filterBankVal /= 10;
	FilterBank->bit15_Expects0_Expects1OrMatch1 = filterBankVal % 10;

	FilterMaster->filterActive0_filterReadyToInitialize1 = 0;
	FilterActivate->enable_Filter0 = 1;
}

void CAN_SetTXMailbox(uint8_t canNum, uint64_t standardID, uint8_t numOfBytes) {
	
	CAN_TX_MAILBOX_IDENTIFIER *const TXMailboxID = Set_TXMailboxID(canNum);
	CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP *const TXDataCtrlTimeStamp = Set_TXDataCtrl_TimeStamp(canNum);
	
	switch (canNum) {
		
		case 1 :
			CANClock->can1_StartTick = 1;
		case 2 : 
			CANClock->can2_StartTick = 1;
	}
	
	
	if (numOfBytes < 0 || numOfBytes > 8) numOfBytes = 0; 
	
	TXMailboxID->StandardIdentifier.rw_StandardIdentifier = standardID;
	TXDataCtrlTimeStamp->rw_DataLen_InBytes = numOfBytes;
}

void CAN_SetRXMailbox(uint8_t canNum, uint64_t standardID, uint8_t numOfBytes) {
	
	CAN_RX_MAILBOX_IDENTIFIER *const RXMailboxID = Set_RXMailboxID(canNum);
	CAN_RX_MAILBOX_DATALENCNTRL_TIMESTAMP *const RXDataCtrlTimeStamp = Set_RXDataCtrl_TimeStamp(canNum);
	
	switch (canNum) {
		
		case 1 :
			CANClock->can1_StartTick = 1;
		case 2 : 
			CANClock->can2_StartTick = 1;
	}
	
	
	if (numOfBytes < 0 || numOfBytes > 8) numOfBytes = 0; 
	
	RXMailboxID->StandardIdentifier.read_StandardIdentifier = standardID;
	RXDataCtrlTimeStamp->read_DataLen_InBytes = numOfBytes;
}


void CAN_Init_and_Start(uint8_t canNum){

	CAN_PinInit(canNum);
	
	MasterControl->enable_AutoExitBusOffState = 1;
	MasterControl->enable_AutoWakeUp = 1;
	
	MasterControl->enable_LockRXWhenFull = 1;
	
	MasterControl->txOrderIdentifier0_txOrderChronological1 = 1;
	
	//Starting CAN.....
	MasterControl->send_InitializeModeRequest = 0; //Sends Request that Hardware enter 'Normal Mode;
	while (MasterStat->initializeModeRequestAccepted == 1); //Syncing to CAN Bus (Waiting for 11 Recessive Bits)
}

uint8_t CAN_Transmit(uint8_t canNum, uint8_t *dataBuffer, uint8_t numOfBytes) {
	
	CAN_TX_MAILBOX_DATALOW *const TXMailboxDataLow = Set_TXDataLow(canNum);
	CAN_TX_MAILBOX_DATAHIGH *const TXMailboxDataHigh = Set_TXDataHigh(canNum);
	CAN_TX_MAILBOX_IDENTIFIER *const TXMailboxID = Set_TXMailboxID(canNum);;
	
	if (numOfBytes > 0)
	TXMailboxDataLow->rw_DataByte0 = *dataBuffer;
	dataBuffer++;
	
	if (numOfBytes > 1)
	TXMailboxDataLow->rw_DataByte1 = *dataBuffer;
	dataBuffer++;
	
	if (numOfBytes > 2)
	TXMailboxDataLow->rw_DataByte2 = *dataBuffer;
	dataBuffer++;
	
	if (numOfBytes > 3)
	TXMailboxDataLow->rw_DataByte3 = *dataBuffer;
	dataBuffer++;
	
	if (numOfBytes > 4)
	TXMailboxDataHigh->rw_DataByte4 = *dataBuffer;
	dataBuffer++;
	
	if (numOfBytes > 5)
	TXMailboxDataHigh->rw_DataByte5 = *dataBuffer;
	dataBuffer++;
	
	if (numOfBytes > 6)
	TXMailboxDataHigh->rw_DataByte6 = *dataBuffer;
	dataBuffer++;
	
	if (numOfBytes > 7)
	TXMailboxDataHigh->rw_DataByte7 = *dataBuffer;
	dataBuffer++;
	
	TXMailboxID->StandardIdentifier.request_TransmissionFromMailbox = 1;
	
	//Check Status Reg for any transmission errors.
	
	return 1;
}

Received_Data* CAN_Receive(uint8_t canNum, uint8_t numOfBytes) {
	
	CAN_RX_MAILBOX_DATALOW *const RXMailboxDataLow = Set_RXDataLow(canNum);
	CAN_RX_MAILBOX_DATAHIGH *const RXMailboxDataHigh = Set_RXDataHigh(canNum);
	Received_Data *R_Data = malloc(sizeof(Received_Data));
	
	//uint8_t id = rxMailboxID->StandardIdentifier.read_StandardIdentifier;
	//uint8_t len = txDataCtrlTimeStamp->read_DataLen_InBytes
	
	if (numOfBytes > 1)
		R_Data->byte0 = RXMailboxDataLow->read_DataByte0;
	
	if (numOfBytes > 2)
		R_Data->byte1 = RXMailboxDataLow->read_DataByte1;
	
	if (numOfBytes > 3)
		R_Data->byte2 = RXMailboxDataLow->read_DataByte2;
	
	if (numOfBytes > 4)
		R_Data->byte3 = RXMailboxDataLow->read_DataByte3;
	
	if (numOfBytes > 5)
		R_Data->byte4 = RXMailboxDataHigh->read_DataByte4;
	
	if (numOfBytes > 6)
		R_Data->byte5 = RXMailboxDataHigh->read_DataByte5;
	
	if (numOfBytes > 7)
		R_Data->byte6 = RXMailboxDataHigh->read_DataByte6;
	
	if (numOfBytes > 8)
		R_Data->byte7 = RXMailboxDataHigh->read_DataByte7;
	
	return R_Data;
}


//Helper Functions--------------------------------------------------------------------------------------------------------------

/**
CAN Pins ---------------------------
		+ CAN1_TX: PA12, PB9, PD1, PH13 (AF9)
		+ CAN1_RX: PA11, PB8, PD0, PI9 (AF9)

		+ CAN2_TX: PB6, PB13 (AF9)
		+ CAN2_RX: PB5, PB12 (AF9)
		------------------------------------
**/
static void CAN_PinInit(uint8_t canNum) {

	switch (canNum) {

		case 1 :
			//CAN TX
			Pin_Init('A', 12, AF9);
			//CAN RX
			Pin_Init('A', 11, AF9);
			break;
		case 2 : 
			//CAN TX
			Pin_Init('B', 6, AF9);
			//CAN RX
			Pin_Init('B', 5, AF9);
			break;
	}		
}

static CAN_FILTERBANKi_REGISTERx* Set_FilterBankReg(uint8_t filterNumber, uint8_t registerNum) {
	
	switch(filterNumber) {
		
		case 0 :
			switch(registerNum) {
				case 1 :
					return FilterBank0_R1;
				case 2 :
					return FilterBank0_R2;
			}
		case 1 :
			switch(registerNum) {
				case 1 :
					return FilterBank1_R1;
				case 2 :
					return FilterBank1_R2;
			}
		case 2 :
			switch(registerNum) {
				case 1 :
					return FilterBank2_R1;
				case 2 :
					return FilterBank2_R2;
			}
		case 3 :
			switch(registerNum) {
				case 1 :
					return FilterBank3_R1;
				case 2 :
					return FilterBank3_R2;
			};
		case 4 :
			switch(registerNum) {
				case 1 :
					return FilterBank4_R1;
				case 2 :
					return FilterBank4_R2;
			}
		case 5 :
			switch(registerNum) {
				case 1 :
					return FilterBank5_R1;
				case 2 :
					return FilterBank5_R2;
			}	
		case 6 :
			switch(registerNum) {
				case 1 :
					return FilterBank6_R1;
				case 2 :
					return FilterBank6_R2;
			}
		case 7 :
			switch(registerNum) {
				case 1 :
					return FilterBank7_R1;
				case 2 :
					return FilterBank7_R2;
			}
		case 8 :
			switch(registerNum) {
				case 1 :
					return FilterBank8_R1;
				case 2 :
					return FilterBank8_R2;
			}
		case 9 :
			switch(registerNum) {
				case 1 :
					return FilterBank9_R1;
				case 2 :
					return FilterBank9_R2;
			}
		case 10 :
			switch(registerNum) {
				case 1 :
					return FilterBank10_R1;
				case 2 :
					return FilterBank10_R2;
			}
		case 11 :
			switch(registerNum) {
				case 1 :
					return FilterBank11_R1;
				case 2 :
					return FilterBank11_R2;
			}
		case 12 :
			switch(registerNum) {
				case 1 :
					return FilterBank12_R1;
				case 2 :
					return FilterBank12_R2;
			}
		case 13 :
			switch(registerNum) {
				case 1 :
					return FilterBank13_R1;
				case 2 :
					return FilterBank13_R2;
			}
		case 14 :
			switch(registerNum) {
				case 1 :
					return FilterBank14_R1;
				case 2 :
					return FilterBank14_R2;
			}	
		case 15 :
			switch(registerNum) {
				case 1 :
					return FilterBank15_R1;
				case 2 :
					return FilterBank15_R2;
			}
		case 16 :
			switch(registerNum) {
				case 1 :
					return FilterBank16_R1;
				case 2 :
					return FilterBank16_R2;
			}	
		case 17 :
			switch(registerNum) {
				case 1 :
					return FilterBank17_R1;
				case 2 :
					return FilterBank17_R2;
			}	
		case 18 :
			switch(registerNum) {
				case 1 :
					return FilterBank18_R1;
				case 2 :
					return FilterBank18_R2;
			}	
		case 19 :
			switch(registerNum) {
				case 1 :
					return FilterBank19_R1;
				case 2 :
					return FilterBank19_R2;
			}	
		case 20 :
			switch(registerNum) {
				case 1 :
					return FilterBank20_R1;
				case 2 :
					return FilterBank20_R2;
			}	
		case 21 :
			switch(registerNum) {
				case 1 :
					return FilterBank21_R1;
				case 2 :
					return FilterBank21_R2;
			}	
		case 22 :
			switch(registerNum) {
				case 1 :
					return FilterBank22_R1;
				case 2 :
					return FilterBank22_R2;
			}	
		case 23 :
			switch(registerNum) {
				case 1 :
					return FilterBank23_R1;
				case 2 :
					return FilterBank23_R2;
			}	
		case 24 :
			switch(registerNum) {
				case 1 :
					return FilterBank24_R1;
				case 2 :
					return FilterBank24_R2;
			}	
		case 25 :
			switch(registerNum) {
				case 1 :
					return FilterBank25_R1;
				case 2 :
					return FilterBank25_R2;
			}	
		case 26 :
			switch(registerNum) {
				case 1 :
					return FilterBank26_R1;
				case 2 :
					return FilterBank26_R2;
			}	
		case 27 :
			switch(registerNum) {
				case 1 :
					return FilterBank27_R1;
				case 2 :
					return FilterBank27_R2;
			}
				
		default :
			return NULL;
	}
}


static void Set_FilterNumber_AssignFIFO_SetFilterMode(uint8_t filterNumber, E_FilterSize filterSize, uint8_t fifoNumber, E_FilterMode filterMode) {
	
	switch(filterNumber) {
		
		case 0 :
			FilterScale->filter0Size16B0_filter0Size32B1 = filterSize;
			FilterFIFOAssign->filter0ToFIFO0_filter0ToFIFO1 = fifoNumber;
			FilterMode->filter0IDMaskMode0_filter0IDListMode1 = filterMode;
			break;
		case 1 :
			FilterScale->filter1Size16B0_filter1Size32B1 = filterSize;
			FilterFIFOAssign->filter1ToFIFO0_filter1ToFIFO1 = fifoNumber;
			FilterMode->filter1IDMaskMode0_filter1IDListMode1 = filterMode;
			break;
		case 2 :
			FilterScale->filter2Size16B0_filter2Size32B1 = filterSize;
			FilterFIFOAssign->filter2ToFIFO0_filter2ToFIFO1 = fifoNumber;
			FilterMode->filter2IDMaskMode0_filter2IDListMode1 = filterMode;
			break;
		case 3 :
			FilterScale->filter3Size16B0_filter3Size32B1 = filterSize;
			FilterFIFOAssign->filter3ToFIFO0_filter3ToFIFO1 = fifoNumber;
			FilterMode->filter3IDMaskMode0_filter3IDListMode1 = filterMode;
			break;
		case 4 :
			FilterScale->filter4Size16B0_filter4Size32B1 = filterSize;
			FilterFIFOAssign->filter4ToFIFO0_filter4ToFIFO1 = fifoNumber;
			FilterMode->filter4IDMaskMode0_filter4IDListMode1 = filterMode;
			break;
		case 5 :
			FilterScale->filter5Size16B0_filter5Size32B1 = filterSize;
			FilterFIFOAssign->filter5ToFIFO0_filter5ToFIFO1 = fifoNumber;
			FilterMode->filter5IDMaskMode0_filter5IDListMode1 = filterMode;
			break;
		case 6 :
			FilterScale->filter6Size16B0_filter6Size32B1 = filterSize;
			FilterFIFOAssign->filter6ToFIFO0_filter6ToFIFO1 = fifoNumber;
			FilterMode->filter6IDMaskMode0_filter6IDListMode1 = filterMode;
			break;
		case 7 :
			FilterScale->filter7Size16B0_filter7Size32B1 = filterSize;
			FilterFIFOAssign->filter7ToFIFO0_filter7ToFIFO1 = fifoNumber;
			FilterMode->filter7IDMaskMode0_filter7IDListMode1 = filterMode;
			break;
		case 8 :
			FilterScale->filter8Size16B0_filter8Size32B1 = filterSize;
			FilterFIFOAssign->filter8ToFIFO0_filter8ToFIFO1 = fifoNumber;
			FilterMode->filter8IDMaskMode0_filter8IDListMode1 = filterMode;
			break;
		case 9 :
			FilterScale->filter9Size16B0_filter9Size32B1 = filterSize;
			FilterFIFOAssign->filter9ToFIFO0_filter9ToFIFO1 = fifoNumber;
			FilterMode->filter9IDMaskMode0_filter9IDListMode1 = filterMode;
			break;
		case 10 :
			FilterScale->filter10Size16B0_filter10Size32B1 = filterSize;
			FilterFIFOAssign->filter10ToFIFO0_filter10ToFIFO1 = fifoNumber;
			FilterMode->filter10IDMaskMode0_filter10IDListMode1 = filterMode;
			break;			
		case 11 :
			FilterScale->filter11Size16B0_filter11Size32B1 = filterSize;
			FilterFIFOAssign->filter11ToFIFO0_filter11ToFIFO1 = fifoNumber;	
			FilterMode->filter11IDMaskMode0_filter11IDListMode1 = filterMode;
			break;
		case 12 :
			FilterScale->filter12Size16B0_filter12Size32B1 = filterSize;
			FilterFIFOAssign->filter12ToFIFO0_filter12ToFIFO1 = fifoNumber;	
			FilterMode->filter12IDMaskMode0_filter12IDListMode1 = filterMode;
			break;
		case 13 :
			FilterScale->filter13Size16B0_filter13Size32B1 = filterSize;
			FilterFIFOAssign->filter13ToFIFO0_filter13ToFIFO1 = fifoNumber;	
			FilterMode->filter13IDMaskMode0_filter13IDListMode1 = filterMode;
			break;
		case 14 :
			FilterScale->filter14Size16B0_filter14Size32B1 = filterSize;
			FilterFIFOAssign->filter14ToFIFO0_filter14ToFIFO1 = fifoNumber;	
			FilterMode->filter14IDMaskMode0_filter14IDListMode1 = filterMode;
			break;
		case 15 :
			FilterScale->filter15Size16B0_filter15Size32B1 = filterSize;
			FilterFIFOAssign->filter15ToFIFO0_filter15ToFIFO1 = fifoNumber;	
			FilterMode->filter15IDMaskMode0_filter15IDListMode1 = filterMode;
			break;
		case 16 :
			FilterScale->filter16Size16B0_filter16Size32B1 = filterSize;
			FilterFIFOAssign->filter16ToFIFO0_filter16ToFIFO1 = fifoNumber;
			FilterMode->filter16IDMaskMode0_filter16IDListMode1 = filterMode;
			break;			
		case 17 :
			FilterScale->filter17Size16B0_filter17Size32B1 = filterSize;
			FilterFIFOAssign->filter17ToFIFO0_filter17ToFIFO1 = fifoNumber;	
			FilterMode->filter17IDMaskMode0_filter17IDListMode1 = filterMode;
			break;
		case 18 :
			FilterScale->filter18Size16B0_filter18Size32B1 = filterSize;
			FilterFIFOAssign->filter18ToFIFO0_filter18ToFIFO1 = fifoNumber;	
			FilterMode->filter18IDMaskMode0_filter18IDListMode1 = filterMode;
			break;
		case 19 :
			FilterScale->filter19Size16B0_filter19Size32B1 = filterSize;
			FilterFIFOAssign->filter19ToFIFO0_filter19ToFIFO1 = fifoNumber;	
			FilterMode->filter19IDMaskMode0_filter19IDListMode1 = filterMode;
			break;
		case 20 :
			FilterScale->filter20Size16B0_filter20Size32B1 = filterSize;
			FilterFIFOAssign->filter20ToFIFO0_filter20ToFIFO1 = fifoNumber;	
			FilterMode->filter20IDMaskMode0_filter20IDListMode1 = filterMode;
			break;
		case 21 :
			FilterScale->filter21Size16B0_filter21Size32B1 = filterSize;
			FilterFIFOAssign->filter21ToFIFO0_filter21ToFIFO1 = fifoNumber;	
			FilterMode->filter21IDMaskMode0_filter21IDListMode1 = filterMode;
			break;
		case 22 :
			FilterScale->filter22Size16B0_filter22Size32B1 = filterSize;
			FilterFIFOAssign->filter22ToFIFO0_filter22ToFIFO1 = fifoNumber;	
			FilterMode->filter22IDMaskMode0_filter22IDListMode1 = filterMode;
			break;
		case 23 :
			FilterScale->filter23Size16B0_filter23Size32B1 = filterSize;
			FilterFIFOAssign->filter23ToFIFO0_filter23ToFIFO1 = fifoNumber;	
			FilterMode->filter23IDMaskMode0_filter23IDListMode1 = filterMode;
			break;
		case 24 :
			FilterScale->filter24Size16B0_filter24Size32B1 = filterSize;
			FilterFIFOAssign->filter24ToFIFO0_filter24ToFIFO1 = fifoNumber;
			FilterMode->filter24IDMaskMode0_filter24IDListMode1 = filterMode;
			break;
		case 25 :
			FilterScale->filter25Size16B0_filter25Size32B1 = filterSize;
			FilterFIFOAssign->filter25ToFIFO0_filter25ToFIFO1 = fifoNumber;
			FilterMode->filter25IDMaskMode0_filter25IDListMode1 = filterMode;
			break;
		case 26 :
			FilterScale->filter26Size16B0_filter26Size32B1 = filterSize;
			FilterFIFOAssign->filter26ToFIFO0_filter26ToFIFO1 = fifoNumber;	
			FilterMode->filter26IDMaskMode0_filter26IDListMode1 = filterMode;
			break;
		case 27 :
			FilterScale->filter27Size16B0_filter27Size32B1 = filterSize;
			FilterFIFOAssign->filter27ToFIFO0_filter27ToFIFO1 = fifoNumber;	
			FilterMode->filter27IDMaskMode0_filter27IDListMode1 = filterMode;
			break;
	}	
}

static CAN_TX_MAILBOX_IDENTIFIER* Set_TXMailboxID(uint8_t canNum) {
	
	switch (canNum) {
		
		case 1 :
			return TXMailboxID_1;
		case 2 : 
			return TXMailboxID_2;
		default :
			return NULL;
	}
}

static CAN_RX_MAILBOX_IDENTIFIER* Set_RXMailboxID(uint8_t canNum) {
	
	switch (canNum) {
		
		case 1 :
			return RXMailboxID_1;
		case 2 : 
			return RXMailboxID_2;
		default :
			return NULL;
	}
}

static CAN_RX_MAILBOX_DATALENCNTRL_TIMESTAMP* Set_RXDataCtrl_TimeStamp(uint8_t canNum) {
	
	switch (canNum) {
		
		case 1 :
			return RXDataCtrlTimeStamp_1;
		case 2 : 
			return RXDataCtrlTimeStamp_2;
		default :
			return NULL;
	}
}

static CAN_TX_MAILBOX_DATALENCNTRL_TIMESTAMP* Set_TXDataCtrl_TimeStamp(uint8_t canNum) {
	
	switch (canNum) {
		
		case 1 :
			return TXDataCtrlTimeStamp_1;
		case 2 : 
			return TXDataCtrlTimeStamp_2;
		default :
			return NULL;
	}
}

static CAN_TX_MAILBOX_DATALOW* Set_TXDataLow(uint8_t canNum) {
	
	switch (canNum) {
		
		case 1 :
			return TXMailboxDataLow_1;
		case 2 : 
			return TXMailboxDataLow_2;
		default :
			return NULL;
	}
}

static CAN_TX_MAILBOX_DATAHIGH* Set_TXDataHigh(uint8_t canNum) {
	
	switch (canNum) {
		
		case 1 :
			return TXMailboxDataHigh_1;
		case 2 : 
			return TXMailboxDataHigh_2;
		default :
			return NULL;
	}
}

static CAN_RX_MAILBOX_DATALOW* Set_RXDataLow(uint8_t canNum) {
	
	switch (canNum) {
		
		case 1 :
			return RXMailboxDataLow_1;
		case 2 : 
			return RXMailboxDataLow_2;
		default :
			return NULL;
	}
}

static CAN_RX_MAILBOX_DATAHIGH* Set_RXDataHigh(uint8_t canNum) {
	
	switch (canNum) {
		
		case 1 :
			return RXMailboxDataHigh_1;
		case 2 : 
			return RXMailboxDataHigh_2;
		default :
			return NULL;
	}
}
