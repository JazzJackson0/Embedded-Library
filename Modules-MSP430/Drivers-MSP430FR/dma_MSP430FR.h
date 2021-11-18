//MSP430FR59xx Driver
#ifndef DMA_H_
#define DMA_H_
//x69 Series only uses Channels 0, 1, 2
#include <stdint.h>

void DMA_Init(void);

#define DMA_GENERAL_CONTROL 0x0500
#define DMA_CH0 0x0510
#define DMA_CH1 0x0520
#define DMA_CH2 0x0530

#define ADDR_DMA_CONTROL0 ( (DMA_CONTROL0*) ((DMA_GENERAL_CONTROL) + 0x00) )
#define ADDR_DMA_CONTROL1 ( (DMA_CONTROL1*) ((DMA_GENERAL_CONTROL) + 0x02) )
#define ADDR_DMA_CONTROL2 ( (DMA_CONTROL2*) ((DMA_GENERAL_CONTROL) + 0x04) )
#define ADDR_DMA_CONTROL3 ( (DMA_CONTROL3*) ((DMA_GENERAL_CONTROL) + 0x06) )
#define ADDR_DMA_CONTROL4 ( (DMA_CONTROL4*) ((DMA_GENERAL_CONTROL) + 0x08) )

#define ADDR_DMA_CH0_CONTROL ( (DMA_CHx_CONTROL*) ((DMA_CH0) + 0x00) )
#define ADDR_DMA_CH0_SOURCE_ADDRS ( (DMA_CHx_SOURCE_ADDRS*) ((DMA_CH0) + 0x02) )
#define ADDR_DMA_CH0_DESTINATION_ADDRS ( (DMA_CHx_DESTINATION_ADDRS*) ((DMA_CH0) + 0x06) )
#define ADDR_DMA_CH0_SIZE_ADDRS ( (DMA_CHx_SIZE_ADDRS*) ((DMA_CH0) + 0x0A) )

#define ADDR_DMA_CH1_CONTROL ( (DMA_CHx_CONTROL*) ((DMA_CH1) + 0x00) )
#define ADDR_DMA_CH1_SOURCE_ADDRS ( (DMA_CHx_SOURCE_ADDRS*) ((DMA_CH1) + 0x02) )
#define ADDR_DMA_CH1_DESTINATION_ADDRS ( (DMA_CHx_DESTINATION_ADDRS*) ((DMA_CH1) + 0x06) )
#define ADDR_DMA_CH1_SIZE_ADDRS ( (DMA_CHx_SIZE_ADDRS*) ((DMA_CH1) + 0x0A) )

#define ADDR_DMA_CH2_CONTROL ( (DMA_CHx_CONTROL*) ((DMA_CH2) + 0x00) )
#define ADDR_DMA_CH2_SOURCE_ADDRS ( (DMA_CHx_SOURCE_ADDRS*) ((DMA_CH2) + 0x02) )
#define ADDR_DMA_CH2_DESTINATION_ADDRS ( (DMA_CHx_DESTINATION_ADDRS*) ((DMA_CH2) + 0x06) )
#define ADDR_DMA_CH2_SIZE_ADDRS ( (DMA_CHx_SIZE_ADDRS*) ((DMA_CH2) + 0x0A) )

#define ADDR_DMA_CH3_CONTROL ( (DMA_CHx_CONTROL*) (() + 0x00) )
#define ADDR_DMA_CH3_SOURCE_ADDRS ( (DMA_CHx_SOURCE_ADDRS*) (() + 0x02) )
#define ADDR_DMA_CH3_DESTINATION_ADDRS ( (DMA_CHx_DESTINATION_ADDRS*) (() + 0x06) )
#define ADDR_DMA_CH3_SIZE_ADDRS ( (DMA_CHx_SIZE_ADDRS*) (() + 0x0A) )

#define ADDR_DMA_CH4_CONTROL ( (DMA_CHx_CONTROL*) (() + 0x00) )
#define ADDR_DMA_CH4_SOURCE_ADDRS ( (DMA_CHx_SOURCE_ADDRS*) (() + 0x02) )
#define ADDR_DMA_CH4_DESTINATION_ADDRS ( (DMA_CHx_DESTINATION_ADDRS*) (() + 0x06) )
#define ADDR_DMA_CH4_SIZE_ADDRS ( (DMA_CHx_SIZE_ADDRS*) (() + 0x0A) )

#define ADDR_DMA_CH5_CONTROL ( (DMA_CHx_CONTROL*) (() + 0x00) )
#define ADDR_DMA_CH5_SOURCE_ADDRS ( (DMA_CHx_SOURCE_ADDRS*) (() + 0x02) )
#define ADDR_DMA_CH5_DESTINATION_ADDRS ( (DMA_CHx_DESTINATION_ADDRS*) (() + 0x06) )
#define ADDR_DMA_CH5_SIZE_ADDRS ( (DMA_CHx_SIZE_ADDRS*) (() + 0x0A) )

#define ADDR_DMA_CH6_CONTROL ( (DMA_CHx_CONTROL*) (() + 0x00) )
#define ADDR_DMA_CH6_SOURCE_ADDRS ( (DMA_CHx_SOURCE_ADDRS*) (() + 0x02) )
#define ADDR_DMA_CH6_DESTINATION_ADDRS ( (DMA_CHx_DESTINATION_ADDRS*) (() + 0x06) )
#define ADDR_DMA_CH6_SIZE_ADDRS ( (DMA_CHx_SIZE_ADDRS*) (() + 0x0A) )

#define ADDR_DMA_CH7_CONTROL ( (DMA_CHx_CONTROL*) (() + 0x00) )
#define ADDR_DMA_CH7_SOURCE_ADDRS ( (DMA_CHx_SOURCE_ADDRS*) (() + 0x02) )
#define ADDR_DMA_CH7_DESTINATION_ADDRS ( (DMA_CHx_DESTINATION_ADDRS*) (() + 0x06) )
#define ADDR_DMA_CH7_SIZE_ADDRS ( (DMA_CHx_SIZE_ADDRS*) (() + 0x0A) )

#define ADDR_DMA_INTERRUPT_VECTOR ( (DMA_INTERRUPT_VECTOR*) ((DMA_GENERAL_CONTROL) + 0x0E) )

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

#endif
