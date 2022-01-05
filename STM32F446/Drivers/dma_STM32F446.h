//STM32F446 Driver
#ifndef DMA_H_
#define DMA_H_

#include <stdint.h>

void DMA_Init(void);

/*DMA Pins ---------------------------
		+ No Pins Needed
		------------------------------------*/

#define CLOCK 0x40023800
#define AHB1 0x30
#define DMA1 0x40026000
#define DMA2 0x40026400

#define DMAx DMA1

//CLOCK
#define ADDR_DMA_CLOCK ( (DMA_CLOCK*) ((CLOCK) + AHB1) )

#define ADDR_DMA_LOW_INTERRUPT_STATUS ( (DMA_LOW_INTERRUPT_STATUS*) ((DMAx) + 0x00) )
#define ADDR_DMA_HIGH_INTERRUPT_STATUS ( (DMA_HIGH_INTERRUPT_STATUS*) ((DMAx) + 0x04) )
#define ADDR_DMA_LOW_INTERRUPT_FLAGCLEAR ( (DMA_LOW_INTERRUPT_FLAGCLEAR*) ((DMAx) + 0x08) )
#define ADDR_DMA_HIGH_INTERRUPT_FLAGCLEAR ( (DMA_HIGH_INTERRUPT_FLAGCLEAR*) ((DMAx) + 0x0C) )

#define ADDR_DMA_STREAM0_CONFIG ( (DMA_STREAMx_CONFIG*) ((DMAx) + 0x10) )
#define ADDR_DMA_STREAM1_CONFIG ( (DMA_STREAMx_CONFIG*) ((DMAx) + 0x28) )
#define ADDR_DMA_STREAM2_CONFIG ( (DMA_STREAMx_CONFIG*) ((DMAx) + 0x40) )
#define ADDR_DMA_STREAM3_CONFIG ( (DMA_STREAMx_CONFIG*) ((DMAx) + 0x58) )
#define ADDR_DMA_STREAM4_CONFIG ( (DMA_STREAMx_CONFIG*) ((DMAx) + 0x70) )
#define ADDR_DMA_STREAM5_CONFIG ( (DMA_STREAMx_CONFIG*) ((DMAx) + 0x88) )
#define ADDR_DMA_STREAM6_CONFIG ( (DMA_STREAMx_CONFIG*) ((DMAx) + 0xA0) )
#define ADDR_DMA_STREAM7_CONFIG ( (DMA_STREAMx_CONFIG*) ((DMAx) + 0xB8) )

#define ADDR_DMA_STREAM0_NUMBEROF_DATA ( (DMA_STREAMx_NUMBEROF_DATA*) ((DMAx) + 0x14) )
#define ADDR_DMA_STREAM1_NUMBEROF_DATA ( (DMA_STREAMx_NUMBEROF_DATA*) ((DMAx) + 0x2C) )
#define ADDR_DMA_STREAM2_NUMBEROF_DATA ( (DMA_STREAMx_NUMBEROF_DATA*) ((DMAx) + 0x44) )
#define ADDR_DMA_STREAM3_NUMBEROF_DATA ( (DMA_STREAMx_NUMBEROF_DATA*) ((DMAx) + 0x5C) )
#define ADDR_DMA_STREAM4_NUMBEROF_DATA ( (DMA_STREAMx_NUMBEROF_DATA*) ((DMAx) + 0x74) )
#define ADDR_DMA_STREAM5_NUMBEROF_DATA ( (DMA_STREAMx_NUMBEROF_DATA*) ((DMAx) + 0x8C) )
#define ADDR_DMA_STREAM6_NUMBEROF_DATA ( (DMA_STREAMx_NUMBEROF_DATA*) ((DMAx) + 0xA4) )
#define ADDR_DMA_STREAM7_NUMBEROF_DATA ( (DMA_STREAMx_NUMBEROF_DATA*) ((DMAx) + 0xBC) )

#define ADDR_DMA_STREAM0_PERIPHERAL_ADDRESS ( (DMA_STREAMx_PERIPHERAL_ADDRESS*) ((DMAx) + 0x18) )
#define ADDR_DMA_STREAM1_PERIPHERAL_ADDRESS ( (DMA_STREAMx_PERIPHERAL_ADDRESS*) ((DMAx) + 0x30) )
#define ADDR_DMA_STREAM2_PERIPHERAL_ADDRESS ( (DMA_STREAMx_PERIPHERAL_ADDRESS*) ((DMAx) + 0x48) )
#define ADDR_DMA_STREAM3_PERIPHERAL_ADDRESS ( (DMA_STREAMx_PERIPHERAL_ADDRESS*) ((DMAx) + 0x60) )
#define ADDR_DMA_STREAM4_PERIPHERAL_ADDRESS ( (DMA_STREAMx_PERIPHERAL_ADDRESS*) ((DMAx) + 0x78) )
#define ADDR_DMA_STREAM5_PERIPHERAL_ADDRESS ( (DMA_STREAMx_PERIPHERAL_ADDRESS*) ((DMAx) + 0x90) )
#define ADDR_DMA_STREAM6_PERIPHERAL_ADDRESS ( (DMA_STREAMx_PERIPHERAL_ADDRESS*) ((DMAx) + 0xA8) )
#define ADDR_DMA_STREAM7_PERIPHERAL_ADDRESS ( (DMA_STREAMx_PERIPHERAL_ADDRESS*) ((DMAx) + 0xC0) )

#define ADDR_DMA_STREAM0_MEMORY0_ADDRESS ( (DMA_STREAMx_MEMORY0_ADDRESS*) ((DMAx) + 0x1C) )
#define ADDR_DMA_STREAM1_MEMORY0_ADDRESS ( (DMA_STREAMx_MEMORY0_ADDRESS*) ((DMAx) + 0x34) )
#define ADDR_DMA_STREAM2_MEMORY0_ADDRESS ( (DMA_STREAMx_MEMORY0_ADDRESS*) ((DMAx) + 0x4C) )
#define ADDR_DMA_STREAM3_MEMORY0_ADDRESS ( (DMA_STREAMx_MEMORY0_ADDRESS*) ((DMAx) + 0x64) )
#define ADDR_DMA_STREAM4_MEMORY0_ADDRESS ( (DMA_STREAMx_MEMORY0_ADDRESS*) ((DMAx) + 0x7C) )
#define ADDR_DMA_STREAM5_MEMORY0_ADDRESS ( (DMA_STREAMx_MEMORY0_ADDRESS*) ((DMAx) + 0x94) )
#define ADDR_DMA_STREAM6_MEMORY0_ADDRESS ( (DMA_STREAMx_MEMORY0_ADDRESS*) ((DMAx) + 0xAC) )
#define ADDR_DMA_STREAM7_MEMORY0_ADDRESS ( (DMA_STREAMx_MEMORY0_ADDRESS*) ((DMAx) + 0xC4) )

#define ADDR_DMA_STREAM0_MEMORY1_ADDRESS ( (DMA_STREAMx_MEMORY1_ADDRESS*) ((DMAx) + 0x20) )
#define ADDR_DMA_STREAM1_MEMORY1_ADDRESS ( (DMA_STREAMx_MEMORY1_ADDRESS*) ((DMAx) + 0x38) )
#define ADDR_DMA_STREAM2_MEMORY1_ADDRESS ( (DMA_STREAMx_MEMORY1_ADDRESS*) ((DMAx) + 0x50) )
#define ADDR_DMA_STREAM3_MEMORY1_ADDRESS ( (DMA_STREAMx_MEMORY1_ADDRESS*) ((DMAx) + 0x68) )
#define ADDR_DMA_STREAM4_MEMORY1_ADDRESS ( (DMA_STREAMx_MEMORY1_ADDRESS*) ((DMAx) + 0x80) )
#define ADDR_DMA_STREAM5_MEMORY1_ADDRESS ( (DMA_STREAMx_MEMORY1_ADDRESS*) ((DMAx) + 0x98) )
#define ADDR_DMA_STREAM6_MEMORY1_ADDRESS ( (DMA_STREAMx_MEMORY1_ADDRESS*) ((DMAx) + 0xB0) )
#define ADDR_DMA_STREAM7_MEMORY1_ADDRESS ( (DMA_STREAMx_MEMORY1_ADDRESS*) ((DMAx) + 0xC8) )

#define ADDR_DMA_STREAM0_FIFO_CONTROL ( (DMA_STREAMx_FIFO_CONTROL*) ((DMAx) + 0x24) )
#define ADDR_DMA_STREAM1_FIFO_CONTROL ( (DMA_STREAMx_FIFO_CONTROL*) ((DMAx) + 0x3C) )
#define ADDR_DMA_STREAM2_FIFO_CONTROL ( (DMA_STREAMx_FIFO_CONTROL*) ((DMAx) + 0x54) )
#define ADDR_DMA_STREAM3_FIFO_CONTROL ( (DMA_STREAMx_FIFO_CONTROL*) ((DMAx) + 0x6C) )
#define ADDR_DMA_STREAM4_FIFO_CONTROL ( (DMA_STREAMx_FIFO_CONTROL*) ((DMAx) + 0x84) )
#define ADDR_DMA_STREAM5_FIFO_CONTROL ( (DMA_STREAMx_FIFO_CONTROL*) ((DMAx) + 0x9C) )
#define ADDR_DMA_STREAM6_FIFO_CONTROL ( (DMA_STREAMx_FIFO_CONTROL*) ((DMAx) + 0xB4) )
#define ADDR_DMA_STREAM7_FIFO_CONTROL ( (DMA_STREAMx_FIFO_CONTROL*) ((DMAx) + 0xCC) )

//DMA_STREAM_CONFIG Register
/*Data Transfer Direction*/
#define PERIPHERAL_TO_MEMORY 0x00
#define MEMORY_TO_PERIPHERAL 0x01
#define MEMORY_TO_MEMORY 0x02

/*Data Sizes*/
#define BIT_8 0x00
#define  BIT_16 0x01
#define BIT_32 0x02
/*Priority Levels*/
#define LOW_P 0x00
#define MEDIUM_P 0x01
#define HIGH_P 0x02
#define VERY_HIGH_P 0x03
/*Burst Transfer Configurations*/
#define SINGLE_BURST 0x00
#define BEAT4_BURST 0x01
#define BEAT8_BURST 0x02
#define BEAT16_BURST 0x03
/*Channels*/
#define CH_0 0x00
#define CH_1 0x01
#define CH_2 0x02
#define CH_3 0x03
#define CH_4 0x04
#define CH_5 0x05
#define CH_6 0x06
#define CH_7 0x07

//DMA_STREAMx_FIFO_CONTROL Register
/*FIFO Thresholds*/
#define FIFO_1_4TH 0x00
#define FIFO_1_HALF 0x01
#define FIFO_3_4THS 0x02
#define FIFO_FULL 0x03


typedef struct {
	const uint32_t reserved0:21;
	volatile uint32_t dma1_StartTick:1;
	volatile uint32_t dma2_StartTick:1;
	const uint32_t reserved1:9;
}DMA_CLOCK;

typedef struct {
	volatile uint32_t fifoErrorOnStream0:1;
	const uint32_t reserved0:1;
	volatile uint32_t directModeErrorOnStream0:1;
	volatile uint32_t transferErrorOnStream0:1;
	volatile uint32_t halfTransferEventOnStream0:1;
	volatile uint32_t transferCompleteOnStream0:1;

	volatile uint32_t fifoErrorOnStream1:1;
	const uint32_t reserved1:1;
	volatile uint32_t directModeErrorOnStream1:1;
	volatile uint32_t transferErrorOnStream1:1;
	volatile uint32_t halfTransferEventOnStream1:1;
	volatile uint32_t transferCompleteOnStream1:1;
	
	const uint32_t reserved2:4;
	
	volatile uint32_t fifoErrorOnStream2:1;
	const uint32_t reserved3:1;
	volatile uint32_t directModeErrorOnStream2:1;
	volatile uint32_t transferErrorOnStream2:1;
	volatile uint32_t halfTransferEventOnStream2:1;
	volatile uint32_t transferCompleteOnStream2:1;

	volatile uint32_t fifoErrorOnStream3:1;
	const uint32_t reserved4:1;
	volatile uint32_t directModeErrorOnStream3:1;
	volatile uint32_t transferErrorOnStream3:1;
	volatile uint32_t halfTransferEventOnStream3:1;
	volatile uint32_t transferCompleteOnStream3:1;
	
	const uint32_t reserved5:4;
}DMA_LOW_INTERRUPT_STATUS;


typedef struct {
	volatile uint32_t fifoErrorOnStream4:1;
	const uint32_t reserved0:1;
	volatile uint32_t directModeErrorOnStream4:1;
	volatile uint32_t transferErrorOnStream4:1;
	volatile uint32_t halfTransferEventOnStream4:1;
	volatile uint32_t transferCompleteOnStream4:1;

	volatile uint32_t fifoErrorOnStream5:1;
	const uint32_t reserved1:1;
	volatile uint32_t directModeErrorOnStream5:1;
	volatile uint32_t transferErrorOnStream5:1;
	volatile uint32_t halfTransferEventOnStream5:1;
	volatile uint32_t transferCompleteOnStream5:1;
	
	const uint32_t reserved2:4;
	
	volatile uint32_t fifoErrorOnStream6:1;
	const uint32_t reserved3:1;
	volatile uint32_t directModeErrorOnStream6:1;
	volatile uint32_t transferErrorOnStream6:1;
	volatile uint32_t halfTransferEventOnStream6:1;
	volatile uint32_t transferCompleteOnStream6:1;

	volatile uint32_t fifoErrorOnStream7:1;
	const uint32_t reserved4:1;
	volatile uint32_t directModeErrorOnStream7:1;
	volatile uint32_t transferErrorOnStream7:1;
	volatile uint32_t halfTransferEventOnStream7:1;
	volatile uint32_t transferCompleteOnStream7:1;
	
	const uint32_t reserved5:4;
}DMA_HIGH_INTERRUPT_STATUS;


typedef struct {
	volatile uint32_t clearFIFOFlagOnStream0:1;
	const uint32_t reserved0:1;
	volatile uint32_t clearDirectModeFlagOnStream0:1;
	volatile uint32_t clearTransferFlagOnStream0:1;
	volatile uint32_t clearHalfTransferFlagOnStream0:1;
	volatile uint32_t clearTransferCompleteFlagOnStream0:1;

	volatile uint32_t clearFIFOFlagOnStream1:1;
	const uint32_t reserved1:1;
	volatile uint32_t clearDirectModeFlagOnStream1:1;
	volatile uint32_t clearTransferFlagOnStream1:1;
	volatile uint32_t clearHalfTransferFlagOnStream1:1;
	volatile uint32_t clearTransferCompleteFlagOnStream1:1;
	
	const uint32_t reserved2:4;
	
	volatile uint32_t clearFIFOFlagOnStream2:1;
	const uint32_t reserved3:1;
	volatile uint32_t clearDirectModeFlagOnStream2:1;
	volatile uint32_t clearTransferFlagOnStream2:1;
	volatile uint32_t clearHalfTransferFlagOnStream2:1;
	volatile uint32_t clearTransferCompleteFlagOnStream2:1;

	volatile uint32_t clearFIFOFlagOnStream3:1;
	const uint32_t reserved4:1;
	volatile uint32_t clearDirectModeFlagOnStream3:1;
	volatile uint32_t clearTransferFlagOnStream3:1;
	volatile uint32_t clearHalfTransferFlagOnStream3:1;
	volatile uint32_t clearTransferCompleteFlagOnStream3:1;
	
	const uint32_t reserved5:4;
}DMA_LOW_INTERRUPT_FLAGCLEAR;


typedef struct {
	volatile uint32_t clearFIFOFlagOnStream4:1;
	const uint32_t reserved0:1;
	volatile uint32_t clearDirectModeFlagOnStream4:1;
	volatile uint32_t clearTransferFlagOnStream4:1;
	volatile uint32_t clearHalfTransferFlagOnStream4:1;
	volatile uint32_t clearTransferCompleteFlagOnStream4:1;

	volatile uint32_t clearFIFOFlagOnStream5:1;
	const uint32_t reserved1:1;
	volatile uint32_t clearDirectModeFlagOnStream5:1;
	volatile uint32_t clearTransferFlagOnStream5:1;
	volatile uint32_t clearHalfTransferFlagOnStream5:1;
	volatile uint32_t clearTransferCompleteFlagOnStream5:1;
	
	const uint32_t reserved2:4;
	
	volatile uint32_t clearFIFOFlagOnStream6:1;
	const uint32_t reserved3:1;
	volatile uint32_t clearDirectModeFlagOnStream6:1;
	volatile uint32_t clearTransferFlagOnStream6:1;
	volatile uint32_t clearHalfTransferFlagOnStream6:1;
	volatile uint32_t clearTransferCompleteFlagOnStream6:1;

	volatile uint32_t clearFIFOFlagOnStream7:1;
	const uint32_t reserved4:1;
	volatile uint32_t clearDirectModeFlagOnStream7:1;
	volatile uint32_t clearTransferFlagOnStream7:1;
	volatile uint32_t clearHalfTransferFlagOnStream7:1;
	volatile uint32_t clearTransferCompleteFlagOnStream7:1;
	
	const uint32_t reserved5:4;
}DMA_HIGH_INTERRUPT_FLAGCLEAR;


typedef struct {
	volatile uint32_t enable_Stream:1;
	volatile uint32_t enable_DirectModeErrorInterrupt:1;
	volatile uint32_t enable_TransferErrorInterrupt:1;
	volatile uint32_t enable_HalfTransferInterrupt:1;
	volatile uint32_t enable_TransferCompleteFlag:1;
	volatile uint32_t dmaAsFlowController0_peripheralAsFlowController1:1;
	volatile uint32_t rw_DataTransferDirection:2;
	volatile uint32_t enable_CircularMode:1;
	volatile uint32_t enable_PeripheralIncrementMode:1;
	volatile uint32_t enable_MemoryIncrementMode:1;
	volatile uint32_t rw_PeripheralDataSize:2;
	volatile uint32_t rw_MemoryDataSize:2;
	volatile uint32_t enable_4BitAddressOffset:1;
	volatile uint32_t rw_PriorityLevel:2;
	volatile uint32_t enable_BufferSwitchAtEndOfTransfer:1;
	volatile uint32_t targetMem00_targetMem11:1;
	const uint32_t reserved0:1;
	volatile uint32_t rw_PeripheralTXBurstSize:2;
	volatile uint32_t rw_MemoryTXBurstSize:2;
	volatile uint32_t select_Channel:3;
	const uint32_t reserved:4;
}DMA_STREAMx_CONFIG;


typedef struct {
	volatile uint32_t rw_NumOfDataItemsToTransfer:16;
	const uint32_t reserved:16;
}DMA_STREAMx_NUMBEROF_DATA;


typedef struct {
	volatile uint32_t rw_PeripheralBaseAddress:32;
}DMA_STREAMx_PERIPHERAL_ADDRESS;


typedef struct {
	volatile uint32_t rw_Memory0BaseAddress:32;
}DMA_STREAMx_MEMORY0_ADDRESS;


typedef struct {
	volatile uint32_t rw_Memory1BaseAddress:32;
}DMA_STREAMx_MEMORY1_ADDRESS;


typedef struct {
	volatile uint32_t rw_FIFOThreshold:2;
	volatile uint32_t disable_DirectMode:1;
	volatile uint32_t read_FIFOStatus:3;
	const uint32_t reserved0:1;
	volatile uint32_t enable_FIFOErrorInterrupt:1;
	const uint32_t reserved1:24;
}DMA_STREAMx_FIFO_CONTROL;


#endif
