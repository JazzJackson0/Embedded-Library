//STM32F446 Driver
#ifndef TIMERGENERAL2_5_H_
#define TIMERGENERAL2_5_H_
//Genreal Purpose Timers 2-5

#include <stdint.h>

uint8_t GeneralTimer2_5_Start(uint8_t timerNum, uint16_t prescaler, uint16_t time);
void GeneralTimer2_5_PWM_Start(uint8_t timerNum, uint8_t captCompNum, uint16_t prescaler, uint16_t time, float dutycycle);
void GeneralTimer2_5_PWM_Update(uint8_t timerNum, uint8_t captCompNum, uint16_t time, float dutycycle);

#define CLOCK 0x40023800
#define APB1 0x40
#define TIM2 0x40000000
#define TIM3 0x40000400
#define TIM4 0x40000800
#define TIM5 0x40000C00

//CLOCK
#define ADDR_TIM2_5_CLOCK ( (TIM2_5_CLOCK*) ((CLOCK) + APB1) )

//TIMER 2
#define ADDR_TIM2_CONTROL1 ( (TIM2_5_CONTROL1*) ((TIM2) + 0x00) )
#define ADDR_TIM2_CONTROL2 ( (TIM2_5_CONTROL2*) ((TIM2) + 0x04) )
#define ADDR_TIM2_SLAVEMODE_CONTROL ( (TIM2_5_SLAVEMODE_CONTROL*) ((TIM2) + 0x08) )
#define ADDR_TIM2_DMAINTERRUPT_ENABLE ( (TIM2_5_DMAINTERRUPT_ENABLE*) ((TIM2) + 0x0C) )
#define ADDR_TIM2_STATUS ( (TIM2_5_STATUS*) ((TIM2) + 0x10) )
#define ADDR_TIM2_EVENTGEN ( (TIM2_5_EVENTGEN*) ((TIM2) + 0x14) )
#define ADDR_TIM2_CAPTURECOMP_MODE1 ( (TIM2_5_CAPTURECOMP_MODE1*) ((TIM2) + 0x18) )
#define ADDR_TIM2_CAPTURECOMP_MODE2 ( (TIM2_5_CAPTURECOMP_MODE2*) ((TIM2) + 0x1C) )
#define ADDR_TIM2_CAPTURECOMP_ENABLE ( (TIM2_5_CAPTURECOMP_ENABLE*) ((TIM2) + 0x20) )
#define ADDR_TIM2_COUNTER ( (TIM2_5_COUNTER*) ((TIM2) + 0x24) )
#define ADDR_TIM2_PRESCALER ( (TIM2_5_PRESCALER*) ((TIM2) + 0x28) )
#define ADDR_TIM2_AUTORELOAD ( (TIM2_5_AUTORELOAD*) ((TIM2) + 0x2C) )
#define ADDR_TIM2_CAPTURECOMP1 ( (TIM2_5_CAPTURECOMPx*) ((TIM2) + 0x34) )
#define ADDR_TIM2_CAPTURECOMP2 ( (TIM2_5_CAPTURECOMPx*) ((TIM2) + 0x38) )
#define ADDR_TIM2_CAPTURECOMP3 ( (TIM2_5_CAPTURECOMPx*) ((TIM2) + 0x3C) )
#define ADDR_TIM2_CAPTURECOMP4 ( (TIM2_5_CAPTURECOMPx*) ((TIM2) + 0x40) )
#define ADDR_TIM2_DMA_CONTROL ( (TIM2_5_DMA_CONTROL*) ((TIM2) + 0x48) )
#define ADDR_TIM2_DMA_FULLTXADDRESS ( (TIM2_5_DMA_FULLTXADDRESS*) ((TIM2) + 0x4C) )
#define ADDR_TIM2_OPTION ( (TIM2_OPTION*) ((TIM2) + 0x50) )


//TIMER 3
#define ADDR_TIM3_CONTROL1 ( (TIM2_5_CONTROL1*) ((TIM3) + 0x00) )
#define ADDR_TIM3_CONTROL2 ( (TIM2_5_CONTROL2*) ((TIM3) + 0x04) )
#define ADDR_TIM3_SLAVEMODE_CONTROL ( (TIM2_5_SLAVEMODE_CONTROL*) ((TIM3) + 0x08) )
#define ADDR_TIM3_DMAINTERRUPT_ENABLE ( (TIM2_5_DMAINTERRUPT_ENABLE*) ((TIM3) + 0x0C) )
#define ADDR_TIM3_STATUS ( (TIM2_5_STATUS*) ((TIM3) + 0x10) )
#define ADDR_TIM3_EVENTGEN ( (TIM2_5_EVENTGEN*) ((TIM3) + 0x14) )
#define ADDR_TIM3_CAPTURECOMP_MODE1 ( (TIM2_5_CAPTURECOMP_MODE1*) ((TIM3) + 0x18) )
#define ADDR_TIM3_CAPTURECOMP_MODE2 ( (TIM2_5_CAPTURECOMP_MODE2*) ((TIM3) + 0x1C) )
#define ADDR_TIM3_CAPTURECOMP_ENABLE ( (TIM2_5_CAPTURECOMP_ENABLE*) ((TIM3) + 0x20) )
#define ADDR_TIM3_COUNTER ( (TIM2_5_COUNTER*) ((TIM3) + 0x24) )
#define ADDR_TIM3_PRESCALER ( (TIM2_5_PRESCALER*) ((TIM3) + 0x28) )
#define ADDR_TIM3_AUTORELOAD ( (TIM2_5_AUTORELOAD*) ((TIM3) + 0x2C) )
#define ADDR_TIM3_CAPTURECOMP1 ( (TIM2_5_CAPTURECOMPx*) ((TIM3) + 0x34) )
#define ADDR_TIM3_CAPTURECOMP2 ( (TIM2_5_CAPTURECOMPx*) ((TIM3) + 0x38) )
#define ADDR_TIM3_CAPTURECOMP3 ( (TIM2_5_CAPTURECOMPx*) ((TIM3) + 0x3C) )
#define ADDR_TIM3_CAPTURECOMP4 ( (TIM2_5_CAPTURECOMPx*) ((TIM3) + 0x40) )
#define ADDR_TIM3_DMA_CONTROL ( (TIM2_5_DMA_CONTROL*) ((TIM3) + 0x48) )
#define ADDR_TIM3_DMA_FULLTXADDRESS ( (TIM2_5_DMA_FULLTXADDRESS*) ((TIM3) + 0x4C) )

//TIMER 4
#define ADDR_TIM4_CONTROL1 ( (TIM2_5_CONTROL1*) ((TIM4) + 0x00) )
#define ADDR_TIM4_CONTROL2 ( (TIM2_5_CONTROL2*) ((TIM4) + 0x04) )
#define ADDR_TIM4_SLAVEMODE_CONTROL ( (TIM2_5_SLAVEMODE_CONTROL*) ((TIM4) + 0x08) )
#define ADDR_TIM4_DMAINTERRUPT_ENABLE ( (TIM2_5_DMAINTERRUPT_ENABLE*) ((TIM4) + 0x0C) )
#define ADDR_TIM4_STATUS ( (TIM2_5_STATUS*) ((TIM4) + 0x10) )
#define ADDR_TIM4_EVENTGEN ( (TIM2_5_EVENTGEN*) ((TIM4) + 0x14) )
#define ADDR_TIM4_CAPTURECOMP_MODE1 ( (TIM2_5_CAPTURECOMP_MODE1*) ((TIM4) + 0x18) )
#define ADDR_TIM4_CAPTURECOMP_MODE2 ( (TIM2_5_CAPTURECOMP_MODE2*) ((TIM4) + 0x1C) )
#define ADDR_TIM4_CAPTURECOMP_ENABLE ( (TIM2_5_CAPTURECOMP_ENABLE*) ((TIM4) + 0x20) )
#define ADDR_TIM4_COUNTER ( (TIM2_5_COUNTER*) ((TIM4) + 0x24) )
#define ADDR_TIM4_PRESCALER ( (TIM2_5_PRESCALER*) ((TIM4) + 0x28) )
#define ADDR_TIM4_AUTORELOAD ( (TIM2_5_AUTORELOAD*) ((TIM4) + 0x2C) )
#define ADDR_TIM4_CAPTURECOMP1 ( (TIM2_5_CAPTURECOMPx*) ((TIM4) + 0x34) )
#define ADDR_TIM4_CAPTURECOMP2 ( (TIM2_5_CAPTURECOMPx*) ((TIM4) + 0x38) )
#define ADDR_TIM4_CAPTURECOMP3 ( (TIM2_5_CAPTURECOMPx*) ((TIM4) + 0x3C) )
#define ADDR_TIM4_CAPTURECOMP4 ( (TIM2_5_CAPTURECOMPx*) ((TIM4) + 0x40) )
#define ADDR_TIM4_DMA_CONTROL ( (TIM2_5_DMA_CONTROL*) ((TIM4) + 0x48) )
#define ADDR_TIM4_DMA_FULLTXADDRESS ( (TIM2_5_DMA_FULLTXADDRESS*) ((TIM4) + 0x4C) )

//TIMER 5
#define ADDR_TIM5_CONTROL1 ( (TIM2_5_CONTROL1*) ((TIM5) + 0x00) )
#define ADDR_TIM5_CONTROL2 ( (TIM2_5_CONTROL2*) ((TIM5) + 0x04) )
#define ADDR_TIM5_SLAVEMODE_CONTROL ( (TIM2_5_SLAVEMODE_CONTROL*) ((TIM5) + 0x08) )
#define ADDR_TIM5_DMAINTERRUPT_ENABLE ( (TIM2_5_DMAINTERRUPT_ENABLE*) ((TIM5) + 0x0C) )
#define ADDR_TIM5_STATUS ( (TIM2_5_STATUS*) ((TIM5) + 0x10) )
#define ADDR_TIM5_EVENTGEN ( (TIM2_5_EVENTGEN*) ((TIM5) + 0x14) )
#define ADDR_TIM5_CAPTURECOMP_MODE1 ( (TIM2_5_CAPTURECOMP_MODE1*) ((TIM5) + 0x18) )
#define ADDR_TIM5_CAPTURECOMP_MODE2 ( (TIM2_5_CAPTURECOMP_MODE2*) ((TIM5) + 0x1C) )
#define ADDR_TIM5_CAPTURECOMP_ENABLE ( (TIM2_5_CAPTURECOMP_ENABLE*) ((TIM5) + 0x20) )
#define ADDR_TIM5_COUNTER ( (TIM2_5_COUNTER*) ((TIM5) + 0x24) )
#define ADDR_TIM5_PRESCALER ( (TIM2_5_PRESCALER*) ((TIM5) + 0x28) )
#define ADDR_TIM5_AUTORELOAD ( (TIM2_5_AUTORELOAD*) ((TIM5) + 0x2C) )
#define ADDR_TIM5_CAPTURECOMP1 ( (TIM2_5_CAPTURECOMPx*) ((TIM5) + 0x34) )
#define ADDR_TIM5_CAPTURECOMP2 ( (TIM2_5_CAPTURECOMPx*) ((TIM5) + 0x38) )
#define ADDR_TIM5_CAPTURECOMP3 ( (TIM2_5_CAPTURECOMPx*) ((TIM5) + 0x3C) )
#define ADDR_TIM5_CAPTURECOMP4 ( (TIM2_5_CAPTURECOMPx*) ((TIM5) + 0x40) )
#define ADDR_TIM5_DMA_CONTROL ( (TIM2_5_DMA_CONTROL*) ((TIM5) + 0x48) )
#define ADDR_TIM5_DMA_FULLTXADDRESS ( (TIM2_5_DMA_FULLTXADDRESS*) ((TIM5) + 0x4C) )
#define ADDR_TIM5_OPTION ( (TIM5_OPTION*) ((TIM5) + 0x50) )

//TIM2_5_CONTROL1
/*Alignment Mode*/
#define EDGE_ALIGN 0x00
#define CENTER_ALIGN_DOWNCOUNT 0x01
#define CENTER_ALIGN_UPCOUNT 0x02
#define CENTER_ALIGN_UP_DOWN 0x03
/*Alignment Mode*/
#define TIMCLOCK 0x00
#define TIMCLOCK_x2 0x01
#define TIMCLOCK_x4 0x02

//TIM2_5_CONTROL2
/*Master Mode*/
#define RESET 0x00
#define COUNTEN_SIGNAL_AS_TRIGOUT 0x01
#define UPDATEEVENT_AS_TRIGOUT 0x02
#define COMPARE_PULSE_AS_TRIGOUT 0x03
#define OUTCOMP1_AS_TRIGOUT 0x04
#define OUTCOMP2_AS_TRIGOUT 0x05
#define OUTCOMP3_AS_TRIGOUT 0x06
#define OUTCOMP4_AS_TRIGOUT 0x07

//TIM2_5_SLAVEMODE_CONTROL & TIM2_5_CAPTURECOMP_MODE1 (For Input Capture Filter)
/*Slave Mode Selection*/
#define DISABLE_SLAVEMODE 0x00
#define ENCODERMODE_1 0x01
#define ENCODERMODE_2 0x02
#define ENCODERMODE_3 0x03
#define EDGE_DETECT 0x04
#define RESET_MODE 0x05
#define GATED_MODE 0x06
#define TRIGGER_MODE 0x07
/*Trigger Selection*/
#define INTERNAL_TRIG0 0x00
#define INTERNAL_TRIG1 0x01
#define INTERNAL_TRIG2 0x02
#define INTERNAL_TRIG3 0x03
#define EDGE_DETECT 0x04
#define FILTERED_TIM_INPUT1 0x05
#define FILTERED_TIM_INPUT2 0x06
#define EXTERNAL_TRIG_INPUT 0x07
/*External Trigger Filter AND Input Capture Filter*/
#define NO_FILTER 0x00
#define _2EVENTVAL 0x01
#define _4EVENTVAL 0x02
#define _8EVENTVAL 0x03
#define DIV2_8EVENTVAL 0x04
#define DIV2_6EVENTVAL 0x05
#define DIV4_8EVENTVAL 0x06
#define DIV4_6EVENTVAL 0x07
#define DIV8_8EVENTVAL 0x08
#define DIV8_6EVENTVAL 0x09
#define DIV16_8EVENTVAL 0x0A
#define DIV16_5EVENTVAL 0x0B
#define DIV16_6EVENTVAL 0x0C
#define DIV32_8EVENTVAL 0x0D
#define DIV32_5EVENTVAL 0x0E
#define DIV32_6EVENTVAL 0x0F

//TIM2_5_CAPTURECOMP_MODE1
/*Output Compare Modes*/
#define FROZEN 0x00
#define ACTIVE_ON_MATCH 0x01
#define INACTIVE_ON_MATCH 0x02
#define TOGGLE_ON_MATCH 0x03
#define FORCE_INACTIVE 0x04
#define FORCE_ATCIVE 0x05
#define PWM_ACTIVE_UNTIL_MATCH 0x06
#define PWM_INACTIVE_UNTIL_MATCH 0x07
/*Choose Input Pin Mapping*/
#define MAPTO_TI1 0x01
#define MAPTO_TI2 0x02
#define MAPTO_TRC 0x03
/*Input Capture Prescaler*/
#define G2_5_NO_PRESCALE 0x00
#define CAPTURE_EVERY_2EVENTS 0x01
#define CAPTURE_EVERY_4EVENTS 0x02
#define CAPTURE_EVERY_8EVENTS 0x03


typedef struct {
	volatile uint32_t tim2_StartTick:1;
	volatile uint32_t tim3_StartTick:1;
	volatile uint32_t tim4_StartTick:1;
	volatile uint32_t tim5_StartTick:1;
	const uint32_t reserved:28;
}TIM2_5_CLOCK;

typedef struct {
	volatile uint16_t enable_Counter:1;
	volatile uint16_t disable_UpdateEventGeneration:1;
	volatile uint16_t updateOnOverflowUnderflowOrDMA:1;
	volatile uint16_t enable_OnePulseMode:1;
	volatile uint16_t upCounter0_downCounter1:1;
	volatile uint16_t rw_AlignmentMode:2;
	volatile uint16_t enable_AutoReloadPreload:1;
	volatile uint16_t rw_ClockDivisionRatio:2;
	const uint16_t reserved:6;
}TIM2_5_CONTROL1;

typedef struct {
	const uint16_t reserved0:3;
	volatile uint16_t dmaSendOnCaptCompEvent0_dmaSendOnUpdateEvent1:1;
	volatile uint16_t rw_MasterMode:3;
	volatile uint16_t channel1ToTimInput0_channel123toTimInput1:1;
	const uint16_t reserved1:8;
}TIM2_5_CONTROL2;

typedef struct {
	volatile uint16_t rw_SlaveModeSelection:3;
	const uint16_t reserved:1;
	volatile uint16_t rw_TriggerInputType:3;
	volatile uint16_t enable_DelayEventEffectForSync:1;
	volatile uint16_t rw_ExternalTriggerFilter:4;
	volatile uint16_t rw_ExternalTriggerPrescaler:2;
	volatile uint16_t enable_ExternalClock:1;
	volatile uint16_t polarityActiveHigh0_polarityActiveLow1:1;
}TIM2_5_SLAVEMODE_CONTROL;

typedef struct {
	volatile uint16_t enable_UpdateInterrupt:1;
	volatile uint16_t enable_CaptureComp1:1;
	volatile uint16_t enable_CaptureComp2:1;
	volatile uint16_t enable_CaptureComp3:1;
	volatile uint16_t enable_CaptureComp4:1;
	const uint16_t reserved0:1;
	volatile uint16_t enable_TriggerInterrupt:1;
	const uint16_t reserved1:1;
	volatile uint16_t enable_DMAReqInterrupt:1;
	volatile uint16_t enable_CaptureComp1DMAReq:1;
	volatile uint16_t enable_CaptureComp2DMAReq:1;
	volatile uint16_t enable_CaptureComp3DMAReq:1;
	volatile uint16_t enable_CaptureComp4DMAReq:1;
	const uint16_t reserved2:1;
	volatile uint16_t enable_TriggerDMAReq:1;
	const uint16_t reserved3:1;
}TIM2_5_DMAINTERRUPT_ENABLE;

typedef struct {
	volatile uint16_t updateInterruptOccurred:1;
	volatile uint16_t captureComp1InterruptOccurred:1;
	volatile uint16_t captureComp2InterruptOccurred:1;
	volatile uint16_t captureComp3InterruptOccurred:1;
	volatile uint16_t captureComp4InterruptOccurred:1;
	const uint16_t reserved0:1;
	volatile uint16_t triggerInterruptOccurred:1;
	const uint16_t reserved1:2;
	volatile uint16_t captureComp1OvercaptureOccurred:1;
	volatile uint16_t captureComp2OvercaptureOccurred:1;
	volatile uint16_t captureComp3OvercaptureOccurred:1;
	volatile uint16_t captureComp4OvercaptureOccurred:1;
	const uint16_t reserved2:3;
}TIM2_5_STATUS;

typedef struct {
	volatile uint16_t generate_UpdateEvent:1;
	volatile uint16_t generate_CaptureCompare1Event:1;
	volatile uint16_t generate_CaptureCompare2Event:1;
	volatile uint16_t generate_CaptureCompare3Event:1;
	volatile uint16_t generate_CaptureCompare4Event:1;
	const uint16_t reserved0:1;
	volatile uint16_t generate_TriggerEvent:1;
	const uint16_t reserved1:9;
}TIM2_5_EVENTGEN;

typedef union {
	struct {
		const uint16_t reserved0:2;
		volatile uint16_t enable_OutputComp1FastResponse:1;
		volatile uint16_t enable_OutputComp1Preload:1;
		volatile uint16_t rw_OutputComp1Mode:3;
		volatile uint16_t enable_OutputComp1ClearOnExternalTrig:1;
		const uint16_t reserved1:2;
		volatile uint16_t enable_OutputComp2FastResponse:1;
		volatile uint16_t enable_OutputComp2Preload:1;
		volatile uint16_t rw_OutputComp2Mode:3;
		volatile uint16_t enable_OutputComp2ClearOnExternalTrig:1;
	}OutputCompareMode;

	struct {
		volatile uint16_t rw_InputCapt1PinMapping:2;
		volatile uint16_t rw_InputCapt1Prescaler:2;
		volatile uint16_t rw_InputCapt1Filter:4;
		volatile uint16_t rw_InputCapt2PinMapping:2;
		volatile uint16_t rw_InputCapt2Prescaler:2;
		volatile uint16_t rw_InputCapt2Filter:4;
	}InputCaptureMode;
}TIM2_5_CAPTURECOMP_MODE1;

typedef union {
	struct {
		const uint16_t reserved0:2;
		volatile uint16_t enable_OutputComp3FastResponse:1;
		volatile uint16_t enable_OutputComp3Preload:1;
		volatile uint16_t rw_OutputComp3Mode:3;
		volatile uint16_t enable_OutputComp3ClearOnExternalTrig:1;
		const uint16_t reserved1:2;
		volatile uint16_t enable_OutputComp4FastResponse:1;
		volatile uint16_t enable_OutputComp4Preload:1;
		volatile uint16_t rw_OutputComp4Mode:3;
		volatile uint16_t enable_OutputComp4ClearOnExternalTrig:1;
	}OutputCompareMode;

	struct {
		volatile uint16_t rw_InputCapt3PinMapping:2;
		volatile uint16_t rw_InputCapt3Prescaler:2;
		volatile uint16_t rw_InputCapt3Filter:4;
		volatile uint16_t rw_InputCapt4PinMapping:2;
		volatile uint16_t rw_InputCapt4Prescaler:2;
		volatile uint16_t rw_InputCapt4Filter:4;
	}InputCaptureMode;
}TIM2_5_CAPTURECOMP_MODE2;

typedef struct {
	volatile uint16_t enable_CaptComp1:1;
	volatile uint16_t cc1Polarity_highOrPart1Input0_lowOrPart1Input1:1;
	const uint16_t reserved0:1;
	volatile uint16_t cc1PolarityPart2Input:1;
	volatile uint16_t enable_CaptComp2:1;
	volatile uint16_t cc2Polarity_highOrPart1Input0_lowOrPart1Input1:1;
	const uint16_t reserved1:1;
	volatile uint16_t cc2PolarityPart2Input:1;
	volatile uint16_t enable_CaptComp3:1;
	volatile uint16_t cc3Polarity_highOrPart1Input0_lowOrPart1Input1:1;
	const uint16_t reserved2:1;
	volatile uint16_t cc3PolarityPart2Input:1;
	volatile uint16_t enable_CaptComp4:1;
	volatile uint16_t cc4Polarity_highOrPart1Input0_lowOrPart1Input1:1;
	const uint16_t reserved3:1;
	volatile uint16_t cc4PolarityPart2Input:1;
}TIM2_5_CAPTURECOMP_ENABLE;

typedef struct {
	volatile uint16_t rw_CounterValue:16;
}TIM2_5_COUNTER;

typedef struct {
	volatile uint16_t rw_PrescalerValue:16;
}TIM2_5_PRESCALER;

typedef struct {
	volatile uint16_t rw_AutoReloadValue:16;
}TIM2_5_AUTORELOAD;

typedef union {
	struct {
		volatile uint32_t rw_CaptureCompValue:32;
	}HighCaptureComp;

	struct {
		volatile uint32_t rw_CaptureCompValue:16;
		const uint32_t reserved:16;
	}NormalCaptureComp;
}TIM2_5_CAPTURECOMPx;

typedef struct {
	volatile uint16_t rw_DAMBaseAddress:5;
	const uint16_t reserved0:3;
	volatile uint16_t rw_DMABurstLength:5;
	const uint16_t reserved1:3;
}TIM2_5_DMA_CONTROL;

typedef struct {
	volatile uint16_t rw_DMABurstAccessRegister:16;
}TIM2_5_DMA_FULLTXADDRESS;

typedef struct {
	const uint16_t reserved0:10;
	volatile uint16_t rw_InternalTrig1Remap:2; //No Macros For This
	const uint16_t reserved1:4;
}TIM2_OPTION;

typedef struct {
	const uint16_t reserved0:6;
	volatile uint16_t rw_TimerInput4Remap:2; //No Macros For This
	const uint16_t reserved1:8;
}TIM5_OPTION;

#endif
