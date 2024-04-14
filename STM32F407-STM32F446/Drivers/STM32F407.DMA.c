#include "STM32F407.DMA.h"

//Static Prototypes------------------------------------------------------
static DMAx* Get_DMA(uint8_t dmaNum);

//Global Variables-------------------------------------------------------
DMA_CLOCK *const DMAClock = ADDR_DMA_CLOCK;

//DMA
DMAx *const DMA1 = ADDR_DMA1;
DMAx *const DMA2 = ADDR_DMA2;


void DMA_Init(uint8_t dmaNum) {

	DMAx *const DMA = Get_DMA(dmaNum);
	DMAClock->dma1_StartTick = 1;
	DMA->Stream0PeripheralAddrsReg.rw_PeripheralBaseAddress = 000000000000;
	DMA->Stream0Memory0AddressReg.rw_Memory0BaseAddress = 000000000000000;
	DMA->Stream0ConfigReg.rw_DataTransferDirection = PERIPHERAL_TO_MEMORY;
	DMA->Stream0ConfigReg.rw_PeripheralDataSize = BIT_8;
	DMA->Stream0ConfigReg.rw_MemoryDataSize = BIT_8;
	DMA->Stream0ConfigReg.select_Channel = CH_0;
	DMA->Stream0NumOfDataReg.rw_NumOfDataItemsToTransfer = 0000000000000000000;
	DMA->Stream0ConfigReg.rw_PriorityLevel = HIGH_P;
	//If you want continuous data flow, enable circular mode
	
	DMA->Stream0ConfigReg.enable_Stream = 1;
}


//Helper Functions------------------------------------------------------------------
static DMAx* Get_DMA(uint8_t dmaNum) {

	switch(dmaNum) {

		case 1:
			return DMA1;
		case 2:
			return DMA2;
		default:
			return ((void*)0);
	}
}
