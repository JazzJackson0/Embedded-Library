#include <stdint.h>
#include "dma_MSP430FR.h"
#include "digital_io_MSP430FR.h"

//Static Prototypes------------------------------------------------------
static void DMA_PinInit(void);

//Global Variables-------------------------------------------------------
//DMA Channel 0
DMA_CONTROL0 *const control0 = ADDR_DMA_CONTROL0;
DMA_CONTROL1 *const control1 = ADDR_DMA_CONTROL1;
DMA_CONTROL2 *const control2 = ADDR_DMA_CONTROL2;
DMA_CONTROL3 *const control3 = ADDR_DMA_CONTROL3;
DMA_CONTROL4 *const control4 = ADDR_DMA_CONTROL4;
DMA_CHx_CONTROL *const ch0Control = ADDR_DMA_CH0_CONTROL;
DMA_CHx_SOURCE_ADDRS *const ch0SourceAddrss = ADDR_DMA_CH0_SOURCE_ADDRS;
DMA_CHx_DESTINATION_ADDRS *const ch0DestAddrss = ADDR_DMA_CH0_DESTINATION_ADDRS;
DMA_CHx_SIZE_ADDRS *const ch0SizeAddrss = ADDR_DMA_CH0_SIZE_ADDRS;

void DMA_Init(void){
	ch0Control->enable_DMA = 0;
	control0->rw_DMA0TransferTriggerSelect = DMAxTRIG0;
	ch0Control->dmaWordSourceAddrss0_dmaByteSourceAddrss1 = 1;
	ch0Control->dmaWordDestAddrss0_dmaByteDestAddrss1 = 1;
	ch0Control->rw_DMASourceDecrementIncrement = INCREMENT;
	ch0Control->rw_DMADestDecrementIncrement = INCREMENT;
	ch0Control->rw_DMATransferMode = REPEATED_SINGLE_TRANS;
	control4->enable_NoTransferDuringCPUReadModifyWriteOps = 1;
	ch0SourceAddrss->rw_DMASourceAddress = 00000;
	ch0DestAddrss->rw_DMADestinationAddress = 00000000;
	ch0SizeAddrss->rw_NumOfDataUnitsPerTransfer = 00000000000;
	ch0Control->enable_DMA = 1;
}

/*DMA Pins ---------------------------------
		+ External DMA Trig: P1-0 	[(Secondary Function)-(Direction Pin: IN)]
		------------------------------------*/
static void DMA_PinInit(void) {
	
	Pin_Init('1', 2, IN, SECONDARY_F, NO_PULL);
}

