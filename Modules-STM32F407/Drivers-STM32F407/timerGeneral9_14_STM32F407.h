//STM32F407 Driver
#ifndef TIMERGENERAL9_14_H_
#define TIMERGENERAL9_14_H_
//Genreal Purpose Timers 9-15

#include <stdint.h>

uint8_t GeneralTimer9_14_Start(uint8_t timerNum, uint16_t prescaler, uint16_t time);
void GeneralTimer9_14_PWM_Start(uint8_t timerNum, uint8_t captCompNum, uint16_t prescaler, uint16_t time, float dutycycle);
void GeneralTimer9_14_PWM_Update(uint8_t timerNum, uint8_t captCompNum, uint16_t time, float dutycycle);

#define CLOCK 0x40023800

#define APB2 0x44
#define TIM9 0x40014000
#define TIM10 0x40014400
#define TIM11 0x40014800

#define APB1 0x40
#define TIM12 0x40001800
#define TIM13 0x40001C00
#define TIM14 0x40002000

//CLOCKS
#define ADDR_TIM9_10_11_CLOCK ( (TIM9_10_11_CLOCK*) ((CLOCK) + APB2) )
#define ADDR_TIM12_13_14_CLOCK ( (TIM12_13_14_CLOCK*) ((CLOCK) + APB1) )

//TIMER 9
#define ADDR_TIM9_CONTROL1 ( (TIM9_14_CONTROL1*) ((TIM9) + 0x00) )
#define ADDR_TIM9_SLAVEMODE_CONTROL ( (TIM9_AND_12_SLAVEMODE_CONTROL*) ((TIM9) + 0x08) )
#define ADDR_TIM9_INTERRUPT_ENABLE ( (TIM9_14_DMAINTERRUPT_ENABLE*) ((TIM9) + 0x0C) )
#define ADDR_TIM9_STATUS ( (TIM9_14_STATUS*) ((TIM9) + 0x10) )
#define ADDR_TIM9_EVENTGEN ( (TIM9_14_EVENTGEN*) ((TIM9) + 0x14) )
#define ADDR_TIM9_CAPTURECOMP_MODE1 ( (TIM9_14_CAPTURECOMP_MODE1*) ((TIM9) + 0x18) )
#define ADDR_TIM9_CAPTURECOMP_ENABLE ( (TIM9_14_CAPTURECOMP_ENABLE*) ((TIM9) + 0x20) )
#define ADDR_TIM9_COUNTER ( (TIM9_14_COUNTER*) ((TIM9) + 0x24) )
#define ADDR_TIM9_PRESCALER ( (TIM9_14_PRESCALER*) ((TIM9) + 0x28) )
#define ADDR_TIM9_AUTORELOAD ( (TIM9_14_AUTORELOAD*) ((TIM9) + 0x2C) )
#define ADDR_TIM9_CAPTURECOMP1 ( (TIM9_14_CAPTURECOMPx*) ((TIM9) + 0x34) )
#define ADDR_TIM9_CAPTURECOMP2 ( (TIM9_14_CAPTURECOMPx*) ((TIM9) + 0x38) )

//TIMER 10
#define ADDR_TIM10_CONTROL1 ( (TIM9_14_CONTROL1*) ((TIM10) + 0x00) )
#define ADDR_TIM10_INTERRUPT_ENABLE ( (TIM9_14_DMAINTERRUPT_ENABLE*) ((TIM10) + 0x0C) )
#define ADDR_TIM10_STATUS ( (TIM9_14_STATUS*) ((TIM10) + 0x10) )
#define ADDR_TIM10_EVENTGEN ( (TIM9_14_EVENTGEN*) ((TIM10) + 0x14) )
#define ADDR_TIM10_CAPTURECOMP_MODE1 ( (TIM9_14_CAPTURECOMP_MODE1*) ((TIM10) + 0x18) )
#define ADDR_TIM10_CAPTURECOMP_ENABLE ( (TIM9_14_CAPTURECOMP_ENABLE*) ((TIM10) + 0x20) )
#define ADDR_TIM10_COUNTER ( (TIM9_14_COUNTER*) ((TIM10) + 0x24) )
#define ADDR_TIM10_PRESCALER ( (TIM9_14_PRESCALER*) ((TIM10) + 0x28) )
#define ADDR_TIM10_AUTORELOAD ( (TIM9_14_AUTORELOAD*) ((TIM10) + 0x2C) )
#define ADDR_TIM10_CAPTURECOMP1 ( (TIM9_14_CAPTURECOMPx*) ((TIM10) + 0x34) )

//TIMER 11
#define ADDR_TIM11_CONTROL1 ( (TIM9_14_CONTROL1*) ((TIM11) + 0x00) )
#define ADDR_TIM11_INTERRUPT_ENABLE ( (TIM9_14_DMAINTERRUPT_ENABLE*) ((TIM11) + 0x0C) )
#define ADDR_TIM11_STATUS ( (TIM9_14_STATUS*) ((TIM11) + 0x10) )
#define ADDR_TIM11_EVENTGEN ( (TIM9_14_EVENTGEN*) ((TIM11) + 0x14) )
#define ADDR_TIM11_CAPTURECOMP_MODE1 ( (TIM9_14_CAPTURECOMP_MODE1*) ((TIM11) + 0x18) )
#define ADDR_TIM11_CAPTURECOMP_ENABLE ( (TIM9_14_CAPTURECOMP_ENABLE*) ((TIM11) + 0x20) )
#define ADDR_TIM11_COUNTER ( (TIM9_14_COUNTER*) ((TIM11) + 0x24) )
#define ADDR_TIM11_PRESCALER ( (TIM9_14_PRESCALER*) ((TIM11) + 0x28) )
#define ADDR_TIM11_AUTORELOAD ( (TIM9_14_AUTORELOAD*) ((TIM11) + 0x2C) )
#define ADDR_TIM11_CAPTURECOMP1 ( (TIM9_14_CAPTURECOMPx*) ((TIM11) + 0x34) )


//TIMER 12
#define ADDR_TIM12_CONTROL1 ( (TIM9_14_CONTROL1*) ((TIM12) + 0x00) )
#define ADDR_TIM12_SLAVEMODE_CONTROL ( (TIM9_AND_12_SLAVEMODE_CONTROL*) ((TIM12) + 0x08) )
#define ADDR_TIM12_INTERRUPT_ENABLE ( (TIM9_14_DMAINTERRUPT_ENABLE*) ((TIM12) + 0x0C) )
#define ADDR_TIM12_STATUS ( (TIM9_14_STATUS*) ((TIM12) + 0x10) )
#define ADDR_TIM12_EVENTGEN ( (TIM9_14_EVENTGEN*) ((TIM12) + 0x14) )
#define ADDR_TIM12_CAPTURECOMP_MODE1 ( (TIM9_14_CAPTURECOMP_MODE1*) ((TIM12) + 0x18) )
#define ADDR_TIM12_CAPTURECOMP_ENABLE ( (TIM9_14_CAPTURECOMP_ENABLE*) ((TIM12) + 0x20) )
#define ADDR_TIM12_COUNTER ( (TIM9_14_COUNTER*) ((TIM12) + 0x24) )
#define ADDR_TIM12_PRESCALER ( (TIM9_14_PRESCALER*) ((TIM12) + 0x28) )
#define ADDR_TIM12_AUTORELOAD ( (TIM9_14_AUTORELOAD*) ((TIM12) + 0x2C) )
#define ADDR_TIM12_CAPTURECOMP1 ( (TIM9_14_CAPTURECOMPx*) ((TIM12) + 0x34) )
#define ADDR_TIM12_CAPTURECOMP2 ( (TIM9_14_CAPTURECOMPx*) ((TIM12) + 0x38) )

//TIMER 13
#define ADDR_TIM13_CONTROL1 ( (TIM9_14_CONTROL1*) ((TIM13) + 0x00) )
#define ADDR_TIM13_INTERRUPT_ENABLE ( (TIM9_14_DMAINTERRUPT_ENABLE*) ((TIM13) + 0x0C) )
#define ADDR_TIM13_STATUS ( (TIM9_14_STATUS*) ((TIM13) + 0x10) )
#define ADDR_TIM13_EVENTGEN ( (TIM9_14_EVENTGEN*) ((TIM13) + 0x14) )
#define ADDR_TIM13_CAPTURECOMP_MODE1 ( (TIM9_14_CAPTURECOMP_MODE1*) ((TIM13) + 0x18) )
#define ADDR_TIM13_CAPTURECOMP_ENABLE ( (TIM9_14_CAPTURECOMP_ENABLE*) ((TIM13) + 0x20) )
#define ADDR_TIM13_COUNTER ( (TIM9_14_COUNTER*) ((TIM13) + 0x24) )
#define ADDR_TIM13_PRESCALER ( (TIM9_14_PRESCALER*) ((TIM13) + 0x28) )
#define ADDR_TIM13_AUTORELOAD ( (TIM9_14_AUTORELOAD*) ((TIM13) + 0x2C) )
#define ADDR_TIM13_CAPTURECOMP1 ( (TIM9_14_CAPTURECOMPx*) ((TIM13) + 0x34) )

//TIMER 14
#define ADDR_TIM14_CONTROL1 ( (TIM9_14_CONTROL1*) ((TIM14) + 0x00) )
#define ADDR_TIM14_INTERRUPT_ENABLE ( (TIM9_14_DMAINTERRUPT_ENABLE*) ((TIM14) + 0x0C) )
#define ADDR_TIM14_STATUS ( (TIM9_14_STATUS*) ((TIM14) + 0x10) )
#define ADDR_TIM14_EVENTGEN ( (TIM9_14_EVENTGEN*) ((TIM14) + 0x14) )
#define ADDR_TIM14_CAPTURECOMP_MODE1 ( (TIM9_14_CAPTURECOMP_MODE1*) ((TIM14) + 0x18) )
#define ADDR_TIM14_CAPTURECOMP_ENABLE ( (TIM9_14_CAPTURECOMP_ENABLE*) ((TIM14) + 0x20) )
#define ADDR_TIM14_COUNTER ( (TIM9_14_COUNTER*) ((TIM14) + 0x24) )
#define ADDR_TIM14_PRESCALER ( (TIM9_14_PRESCALER*) ((TIM14) + 0x28) )
#define ADDR_TIM14_AUTORELOAD ( (TIM9_14_AUTORELOAD*) ((TIM14) + 0x2C) )
#define ADDR_TIM14_CAPTURECOMP1 ( (TIM9_14_CAPTURECOMPx*) ((TIM14) + 0x34) )


#define ADDR_TIM11_OPTION ( (TIM11_OPTION*) (() + 0x50) )

//TIM9_14_CONTROL1
/*Alignment Mode*/
#define EDGE_ALIGN 0x00
#define CENTER_ALIGN_DOWNCOUNT 0x01
#define CENTER_ALIGN_UPCOUNT 0x02
#define CENTER_ALIGN_UP_DOWN 0x03
/*Alignment Mode*/
#define TIMCLOCK 0x00
#define TIMCLOCK_x2 0x01
#define TIMCLOCK_x4 0x02

//TIM9_14_SLAVEMODE_CONTROL & TIM9_14_CAPTURECOMP_MODE1 (For Input Capture Filter)
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

//TIM9_14_CAPTURECOMP_MODE1
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
#define G9_14_NO_PRESCALE 0x00
#define CAPTURE_EVERY_2EVENTS 0x01
#define CAPTURE_EVERY_4EVENTS 0x02
#define CAPTURE_EVERY_8EVENTS 0x03


typedef struct {
	const uint32_t reserved0:16;
	volatile uint32_t tim9_StartTick:1;
	volatile uint32_t tim10_StartTick:1;
	volatile uint32_t tim11_StartTick:1;
	const uint32_t reserved1:13;
}TIM9_10_11_CLOCK ;

typedef struct {
	const uint32_t reserved0:6;
	volatile uint32_t tim12_StartTick:1;
	volatile uint32_t tim13_StartTick:1;
	volatile uint32_t tim14_StartTick:1;
	const uint32_t reserved:23;
}TIM12_13_14_CLOCK ;

typedef struct {
	volatile uint16_t enable_Counter:1;
	volatile uint16_t disable_UpdateEventGeneration:1;
	volatile uint16_t updateOnOverflowOrUGBit0_updateOnOverflow1:1;
	volatile uint16_t enable_OnePulseMode:1;
	const uint16_t reserved0:3;
	volatile uint16_t enable_AutoReloadPreload:1;
	volatile uint16_t rw_ClockDivisionRatio:2;
	const uint16_t reserved1:6;
}TIM9_14_CONTROL1;

typedef struct {
	volatile uint16_t rw_SlaveModeSelection:3;
	const uint16_t reserved0:1;
	volatile uint16_t rw_TriggerInputType:3;
	volatile uint16_t enable_DelayEventEffectForSync:1;
	const uint16_t reserved1:8;
}TIM9_AND_12_SLAVEMODE_CONTROL;

typedef struct {
	volatile uint16_t enable_UpdateInterrupt:1;
	volatile uint16_t enable_CaptureComp1:1;
	volatile uint16_t enable_CaptureComp2:1;
	const uint16_t reserved0:3;
	volatile uint16_t enable_TriggerInterrupt:1;
	const uint16_t reserved1:9;
}TIM9_14_INTERRUPT_ENABLE;

typedef struct {
	volatile uint16_t updateInterruptOccurred:1;
	volatile uint16_t captureComp1InterruptOccurred:1;
	volatile uint16_t captureComp2InterruptOccurred:1;
	const uint16_t reserved0:3;
	volatile uint16_t triggerInterruptOccurred:1;
	const uint16_t reserved1:2;
	volatile uint16_t captureComp1OvercaptureOccurred:1;
	volatile uint16_t captureComp2OvercaptureOccurred:1;
	const uint16_t reserved2:5;
}TIM9_14_STATUS;

typedef struct {
	volatile uint16_t generate_UpdateEvent:1;
	volatile uint16_t generate_CaptureCompare1Event:1;
	volatile uint16_t generate_CaptureCompare2Event:1;
	const uint16_t reserved0:3;
	volatile uint16_t generate_TriggerEvent:1;
	const uint16_t reserved1:9;
}TIM9_14_EVENTGEN;

typedef union {
	struct {
		const uint16_t reserved0:2;
		volatile uint16_t enable_OutputComp1FastResponse:1;
		volatile uint16_t enable_OutputComp1Preload:1;
		volatile uint16_t rw_OutputComp1Mode:3;
		const uint16_t reserved1:3;
		volatile uint16_t enable_OutputComp2FastResponse:1;
		volatile uint16_t enable_OutputComp2Preload:1;
		volatile uint16_t rw_OutputComp2Mode:3;
		const uint16_t reserved2:1;
	}OutputCompareMode;

	struct {
		volatile uint16_t rw_InputCapt1PinMapping:2;
		volatile uint16_t rw_InputCapt1Prescaler:2;
		volatile uint16_t rw_InputCapt1Filter:4;
		volatile uint16_t rw_InputCapt2PinMapping:2;
		volatile uint16_t rw_InputCapt2Prescaler:2;
		volatile uint16_t rw_InputCapt2Filter:4;
	}InputCaptureMode;
}TIM9_14_CAPTURECOMP_MODE1;

typedef struct {
	volatile uint16_t enable_CaptComp1:1;
	volatile uint16_t cc1Polarity_highOrPart1Input0_lowOrPart1Input1:1;
	const uint16_t reserved0:1;
	volatile uint16_t cc1PolarityPart2Input:1;
	volatile uint16_t enable_CaptComp2:1;
	volatile uint16_t cc2Polarity_highOrPart1Input0_lowOrPart1Input1:1;
	const uint16_t reserved1:1;
	volatile uint16_t cc2PolarityPart2Input:1;
	const uint16_t reserved2:8;
}TIM9_14_CAPTURECOMP_ENABLE;

typedef struct {
	volatile uint16_t rw_CounterValue:16;
}TIM9_14_COUNTER;

typedef struct {
	volatile uint16_t rw_PrescalerValue:16;
}TIM9_14_PRESCALER;

typedef struct {
	volatile uint16_t rw_AutoReloadValue:16;
}TIM9_14_AUTORELOAD;

typedef struct {
	volatile uint16_t rw_CaptureCompValue:16;
}TIM9_14_CAPTURECOMPx;

typedef struct {
	volatile uint16_t rw_InternalTrig1Remap:2; //No Macros For This
	const uint16_t reserved1:14;
}TIM11_OPTION;

#endif
