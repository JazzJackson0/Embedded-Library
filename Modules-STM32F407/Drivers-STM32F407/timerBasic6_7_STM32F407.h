//STM32F407 Driver
#ifndef TIMERBASIC6_7_H_
#define TIMERBASIC6_7_H_
//Basic Timers 6-7

#include <stdint.h>

/*TIMER Pins ---------------------------
		+ No Pins Needed
		------------------------------------*/
		
uint8_t BasicTimer_Start(uint8_t timerNum, uint16_t prescaler, uint16_t time);
uint8_t BasicOneShotTimer_Start(uint8_t timerNum, uint16_t prescaler, uint16_t time);

#define CLOCK 0x40023800
#define APB1 0x40
#define TIM6 0x40001000
#define TIM7 0x40001400


//CLOCK
#define ADDR_TIM6_7_CLOCK ( (TIM6_7_CLOCK*) ((CLOCK) + APB1) )

//TIMER 6
#define ADDR_TIM6_CONTROL1 ( (TIM6_7_CONTROL1*) ((TIM6) + 0x00) )
#define ADDR_TIM6_CONTROL2 ( (TIM6_7_CONTROL2*) ((TIM6) + 0x04) )
#define ADDR_TIM6_DMAINTERRUPT_ENABLE ( (TIM6_7_DMAINTERRUPT_ENABLE*) ((TIM6) + 0x0C) )
#define ADDR_TIM6_STATUS ( (TIM6_7_STATUS*) ((TIM6) + 0x10) )
#define ADDR_TIM6_EVENTGEN ( (TIM6_7_EVENTGEN*) ((TIM6) + 0x14) )
#define ADDR_TIM6_COUNTER ( (TIM6_7_COUNTER*) ((TIM6) + 0x24) )
#define ADDR_TIM6_PRESCALER ( (TIM6_7_PRESCALER*) ((TIM6) + 0x28) )
#define ADDR_TIM6_AUTORELOAD ( (TIM6_7_AUTORELOAD*) ((TIM6) + 0x2C) )

//TIMER 7
#define ADDR_TIM7_CONTROL1 ( (TIM6_7_CONTROL1*) ((TIM7) + 0x00) )
#define ADDR_TIM7_CONTROL2 ( (TIM6_7_CONTROL2*) ((TIM7) + 0x04) )
#define ADDR_TIM7_DMAINTERRUPT_ENABLE ( (TIM6_7_DMAINTERRUPT_ENABLE*) ((TIM7) + 0x0C) )
#define ADDR_TIM7_STATUS ( (TIM6_7_STATUS*) ((TIM7) + 0x10) )
#define ADDR_TIM7_EVENTGEN ( (TIM6_7_EVENTGEN*) ((TIM7) + 0x14) )
#define ADDR_TIM7_COUNTER ( (TIM6_7_COUNTER*) ((TIM7) + 0x24) )
#define ADDR_TIM7_PRESCALER ( (TIM6_7_PRESCALER*) ((TIM7) + 0x28) )
#define ADDR_TIM7_AUTORELOAD ( (TIM6_7_AUTORELOAD*) ((TIM7) + 0x2C) )

//TIM6_7_CONTROL2
/*Master Mode*/
#define RESET 0x00
#define COUNTEN_SIGNAL_AS_TRIGOUT 0x01
#define UPDATEEVENT_AS_TRIGOUT 0x02
#define COMPARE_PULSE_AS_TRIGOUT 0x03
#define OUTCOMP1_AS_TRIGOUT 0x04
#define OUTCOMP2_AS_TRIGOUT 0x05
#define OUTCOMP3_AS_TRIGOUT 0x06
#define OUTCOMP4_AS_TRIGOUT 0x07


typedef struct {
	const uint32_t reserved0:4;
	volatile uint32_t tim6_StartTick:1;
	volatile uint32_t tim7_StartTick:1;
	const uint32_t reserved1:26;
}TIM6_7_CLOCK;


typedef struct {
	volatile uint16_t enable_Counter:1;
	volatile uint16_t disable_UpdateEventGeneration:1;
	volatile uint16_t updateOnOverflowOrUGBit0_updateOnOverflow1:1;
	volatile uint16_t enable_OnePulseMode:1;
	const uint16_t reserved0:3;
	volatile uint16_t enable_AutoReloadPreload:1;
	const uint16_t reserved1:8;
}TIM6_7_CONTROL1;

typedef struct {
	const uint16_t reserved0:4;
	volatile uint16_t rw_MasterMode:3;
	const uint16_t reserved1:9;
}TIM6_7_CONTROL2;

typedef struct {
	volatile uint16_t enable_UpdateInterrupt:1;
	const uint16_t reserved0:7;
	volatile uint16_t enable_UpdateDMAReqInterrupt:1;
	const uint16_t reserved1:7;
}TIM6_7_DMAINTERRUPT_ENABLE;

typedef struct {
	volatile uint16_t updateInterruptOccurred:1;
	const uint16_t reserved:15;
}TIM6_7_STATUS;

typedef struct {
	volatile uint16_t generate_UpdateEvent:1;
	const uint16_t reserved:15;
}TIM6_7_EVENTGEN;

typedef struct {
	volatile uint16_t rw_CounterValue:16;
}TIM6_7_COUNTER;

typedef struct {
	volatile uint16_t rw_PrescalerValue:16;
}TIM6_7_PRESCALER;

typedef struct {
	volatile uint16_t rw_AutoReloadValue:16;
}TIM6_7_AUTORELOAD;

#endif
