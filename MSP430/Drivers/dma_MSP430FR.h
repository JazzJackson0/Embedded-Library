//MSP430FR59xx Driver
#ifndef DMA_H_
#define DMA_H_
//x69 Series only uses Channels 0, 1, 2
#include <stdint.h>

//DECLARATIONS
void DMA_Init(uint8_t dmaNum);

//DMA
typedef struct _dma_ctrl DMA_CTRL;
typedef struct _dma DMAx;
#define DMA_BASE 0x0500
//-----------
#define ADDR_DMA_CTRL ( (DMA_CTRL*) ((DMA_BASE) + 0x00) )
#define ADDR_DMA_CH0 ( (DMAx*) ((DMA_BASE) + 0x10) )
#define ADDR_DMA_CH1 ( (DMAx*) ((DMA_BASE) + 0x20) )
#define ADDR_DMA_CH2 ( (DMAx*) ((DMA_BASE) + 0x30) )


//DMA_CHANNELx_CONTROL Register
/*Decrement Increment*/
#define NEITHER 0x00
#define DECREMENT 0x02
#define INCREMENT 0x03
/*Transfer Modes*/
#define SINGLE_TRANSFER 0x00
#define BLOCK_TRANSFER 0x01
#define BURSTBLOCK_TRANSFER 0x02
#define REPEATED_SINGLE_TRANS 0x03
#define REPEATED_BLOCK_TRANS 0x05
#define REPEATED_BURSTBLOCK_TRANS 0x06

//DMA_CONTROL 0 - 3
/*DMA Transfer Triggers*/
#define DMAxTRIG0 0x00;
#define DMAxTRIG1 0x01;
#define DMAxTRIG2 0x02;
#define DMAxTRIG3 0x03;
#define DMAxTRIG4 0x04;
#define DMAxTRIG5 0x05;
#define DMAxTRIG6 0x06;
#define DMAxTRIG7 0x07;
#define DMAxTRIG8 0x08;
#define DMAxTRIG9 0x09;
#define DMAxTRIG10 0x0A;
#define DMAxTRIG11 0x0B;
#define DMAxTRIG12 0x0C;
#define DMAxTRIG13 0x0D;
#define DMAxTRIG14 0x0E;
#define DMAxTRIG15 0x0F;
#define DMAxTRIG16 0x10;
#define DMAxTRIG17 0x11;
#define DMAxTRIG18 0x12;
#define DMAxTRIG19 0x13;
#define DMAxTRIG20 0x14;
#define DMAxTRIG21 0x15;
#define DMAxTRIG22 0x16;
#define DMAxTRIG23 0x17;
#define DMAxTRIG24 0x18;
#define DMAxTRIG25 0x19;
#define DMAxTRIG26 0x1A;
#define DMAxTRIG27 0x1B;
#define DMAxTRIG28 0x1C;
#define DMAxTRIG29 0x1D;
#define DMAxTRIG30 0x1E;
#define DMAxTRIG31 0x1F;


//Register-------------------------------------------------------------------------
typedef struct {
	const uint16_t reserved:16;
}DMA_RESERVED;


typedef struct {
	volatile uint16_t rw_DMA0TransferTriggerSelect:5;
	const uint16_t reserved0:3;
	volatile uint16_t rw_DMA1TransferTriggerSelect:5;
	const uint16_t reserved1:3;
}DMA_CONTROL0;

typedef struct {
	volatile uint16_t rw_DMA2TransferTriggerSelect:5;
	const uint16_t reserved0:3;
	volatile uint16_t rw_DMA3TransferTriggerSelect:5;
	const uint16_t reserved1:3;
}DMA_CONTROL1;

typedef struct {
	volatile uint16_t rw_DMA4TransferTriggerSelect:5;
	const uint16_t reserved0:3;
	volatile uint16_t rw_DMA5TransferTriggerSelect:5;
	const uint16_t reserved1:3;
}DMA_CONTROL2;

typedef struct {
	volatile uint16_t rw_DMA6TransferTriggerSelect:5;
	const uint16_t reserved0:3;
	volatile uint16_t rw_DMA7TransferTriggerSelect:5;
	const uint16_t reserved1:3;
}DMA_CONTROL3;

typedef struct {
	volatile uint16_t enable_NMIInterrupts:1;
	volatile uint16_t enable_RoundRobinBasedPriority:1;
	volatile uint16_t enable_NoTransferDuringCPUReadModifyWriteOps:1;
	const uint16_t reserved:13;
}DMA_CONTROL4;

typedef struct {
	volatile uint16_t start_DMA:1;
	volatile uint16_t transferInterruptedByNMI:1;
	volatile uint16_t enable_DMAInterrupt:1;
	volatile uint16_t dmaInterruptOccurred:1;
	volatile uint16_t enable_DMA:1;
	volatile uint16_t edgeSensitiveTrig0_LevelSensitiveTrig1:1;
	volatile uint16_t dmaWordSourceAddrss0_dmaByteSourceAddrss1:1;
	volatile uint16_t dmaWordDestAddrss0_dmaByteDestAddrss1:1;
	volatile uint16_t rw_DMASourceDecrementIncrement:2;
	volatile uint16_t rw_DMADestDecrementIncrement:2;
	volatile uint16_t rw_DMATransferMode:3;
	const uint16_t reserved:1;
}DMA_CHx_CONTROL;

typedef struct {
	volatile uint32_t rw_DMASourceAddress:20;
	const uint32_t reserved:12;
}DMA_CHx_SOURCE_ADDRS;

typedef struct {
	volatile uint32_t rw_DMADestinationAddress:20;
	const uint32_t reserved:12;
}DMA_CHx_DESTINATION_ADDRS;

typedef struct {
	volatile uint16_t rw_NumOfDataUnitsPerTransfer:16;
}DMA_CHx_SIZE_ADDRS;

typedef struct {
	volatile uint16_t read_HighestPriorityInterruptPending:16;
}DMA_INTERRUPT_VECTOR;

struct _dma_ctrl {
	DMA_CONTROL0 ControlReg0; // 0x00
	DMA_CONTROL1 ControlReg1; // 0x02
	DMA_CONTROL2 ControlReg2; // 0x04
	DMA_CONTROL3 ControlReg3; // 0x06
	DMA_CONTROL4 ControlReg4; // 0x08
};

struct _dma {
	DMA_CHx_CONTROL ChannelControlReg; // 0x00
	DMA_CHx_SOURCE_ADDRS ChannelSourceAddressReg; // 0x02
	DMA_RESERVED reserved0; // 0x04
	DMA_CHx_DESTINATION_ADDRS ChannelDestinationAddressReg; // 0x06
	DMA_RESERVED reserved1; // 0x08
	DMA_CHx_SIZE_ADDRS ChannelSizeAddressReg; // 0x0A
	DMA_RESERVED reserved2; // 0x0C
	DMA_INTERRUPT_VECTOR InterruptVectorReg; // 0x0E
};

#endif
