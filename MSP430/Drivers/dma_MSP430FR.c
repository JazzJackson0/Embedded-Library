#include <stdint.h>
#include "dma_MSP430FR.h"
#include "digital_io_MSP430FR.h"

//Static Prototypes------------------------------------------------------
static void DMA_PinInit(void);
static DMAx* Get_DMA(uint8_t dmaNum);

//Global Variables-------------------------------------------------------
//DMA Channel 0
DMA_CTRL *const DMA_CONTROLx = ADDR_DMA_CTRL;
DMAx *const DMA_CH0 = ADDR_DMA_CH0;
DMAx *const DMA_CH1 = ADDR_DMA_CH1;
DMAx *const DMA_CH2 = ADDR_DMA_CH2;


void DMA_Init(uint8_t dmaNum) {

	DMAx *const DMA = Get_DMA(dmaNum);
	DMA_CTRL *const CNTRL = DMA_CONTROLx;
	
	DMA->ChannelControlReg.enable_DMA = 0;
	CNTRL->ControlReg0.rw_DMA0TransferTriggerSelect = DMAxTRIG0;
	DMA->ChannelControlReg.dmaWordSourceAddrss0_dmaByteSourceAddrss1 = 1;
	DMA->ChannelControlReg.dmaWordDestAddrss0_dmaByteDestAddrss1 = 1;
	DMA->ChannelControlReg.rw_DMASourceDecrementIncrement = INCREMENT;
	DMA->ChannelControlReg.rw_DMADestDecrementIncrement = INCREMENT;
	DMA->ChannelControlReg.rw_DMATransferMode = REPEATED_SINGLE_TRANS;
	CNTRL->ControlReg4.enable_NoTransferDuringCPUReadModifyWriteOps = 1;
	DMA->ChannelSourceAddressReg.rw_DMASourceAddress = 00000;
	DMA->ChannelDestinationAddressReg.rw_DMADestinationAddress = 00000000;
	DMA->ChannelSizeAddressReg.rw_NumOfDataUnitsPerTransfer = 00000000000;
	DMA->ChannelControlReg.enable_DMA = 1;
}


//Helper Functions---------------------------------------------------------------------------

/*DMA Pins ---------------------------------
		+ External DMA Trig: P1-0 	[(Secondary Function)-(Direction Pin: IN)]
		------------------------------------*/
static void DMA_PinInit(void) {
	
	Pin_Init('1', 2, IN, SECONDARY_F, NO_PULL);
}

static DMAx* Get_DMA(uint8_t dmaNum) {

	switch(dmaNum) {

		case 0:
			return DMA_CH0;
		case 1:
			return DMA_CH1;
		case 2:
			return DMA_CH2;
		default:
			return;
	}
}

