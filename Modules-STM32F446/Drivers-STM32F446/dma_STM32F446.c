#include <stdint.h>
#include "dma_STM32F446.h"


//Global Variables-------------------------------------------------------
DMA_CLOCK *const DMAClock = ADDR_DMA_CLOCK;

//DMA Stream 0
DMA_STREAMx_CONFIG *const stream0Config = ADDR_DMA_STREAM0_CONFIG;
DMA_STREAMx_FIFO_CONTROL *const stream0FIFOControl = ADDR_DMA_STREAM0_FIFO_CONTROL;
DMA_STREAMx_PERIPHERAL_ADDRESS *const stream0PeriphAddrss = ADDR_DMA_STREAM0_PERIPHERAL_ADDRESS;
DMA_STREAMx_MEMORY0_ADDRESS *const stream0Mem0Addrss = ADDR_DMA_STREAM0_MEMORY0_ADDRESS;
DMA_STREAMx_MEMORY1_ADDRESS *const stream0Mem1Addrss = ADDR_DMA_STREAM0_MEMORY1_ADDRESS;
DMA_STREAMx_NUMBEROF_DATA *const stream0NumOfData = ADDR_DMA_STREAM0_NUMBEROF_DATA;




void DMA_Init(void){
	
	DMAClock->dma1_StartTick = 1;
	stream0PeriphAddrss->rw_PeripheralBaseAddress = 000000000000;
	stream0Mem0Addrss->rw_Memory0BaseAddress = 000000000000000;
	stream0Config->rw_DataTransferDirection = PERIPHERAL_TO_MEMORY;
	stream0Config->rw_PeripheralDataSize = BIT_8;
	stream0Config->rw_MemoryDataSize = BIT_8;
	stream0Config->select_Channel = CH_0;
	stream0NumOfData->rw_NumOfDataItemsToTransfer = 0000000000000000000;
	stream0Config->rw_PriorityLevel = HIGH_P;
	//If you want continuous data flow, enable circular mode
	
	stream0Config->enable_Stream = 1;
}



