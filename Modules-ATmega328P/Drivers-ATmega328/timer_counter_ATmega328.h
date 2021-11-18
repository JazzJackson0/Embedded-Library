//ATmega328/P Driver
#ifndef TIMER_COUNTER_H_
#define TIMER_COUNTER_H_
#include <stdint.h>

typedef enum _ClockSpeed E_ClockSpeed;

void Timer_Start(uint8_t timerID, E_ClockSpeed clockSpeed, uint16_t time);
uint8_t OneShotTimer_Start(uint8_t timerID, E_ClockSpeed clockSpeed, uint16_t time);
void PWM_Init(uint8_t timerID, E_ClockSpeed clockSpeed, uint16_t time, float dutyCycle);
void PWM_Update(uint8_t timerID, uint16_t time, float dutyCycle);
uint16_t Stop_Timer(uint8_t timerID);

/*TIMER Pins ---------------------------		
		+ Timer/Counter0 External Counter (Input): PC4
		+ Timer/Counter0 Output Compare Match A (Output): PD6
		+ Timer/Counter0 Output Compare Match B (Output): PD5
		
		+ Timer/Counter1 External Counter (Input): PD5
		+ Timer/Counter1 Input Capture (Input): PB0
		+ Timer/Counter1 Output Compare Match A (Output): PB1
		+ Timer/Counter1 Output Compare Match B (Output): PB2
		
		+ Timer/Counter2 Output Compare Match A (Output): PB3
		+ Timer/Counter2 Output Compare Match B (Output): PD3
		------------------------------------*/
		
/*
TIM0 = 8-Bit Timer/Counter. With PWM Capability
TIM1 = 16-Bit Timer/Counter. With PWM Capability
TIM2 = 8-Bit Timer/Counter. With PWM Capability AND Asynchronous Operation 
*/

//Powered by AVR Clock Control Unit
#define ATMEGA_BASEADDRESS 0x0000

#define ADDR_GENERAL_TIM_CONTROL ( (GENERAL_TIM_CONTROL*) ((ATMEGA_BASEADDRESS) + 0x23) )//0,1,2
#define ADDR_POWER_REDUCTION_TIM ( (POWER_REDUCTION_TIM*) ((ATMEGA_BASEADDRESS) + 0x64) ) //Found in Power Management Section
//TIM0
#define ADDR_TIM0_CONTROLA ( (TIMx_CONTROLA*) ((ATMEGA_BASEADDRESS) + 0x24) )
#define ADDR_TIM0_CONTROLB ( (TIM0_2_CONTROLB*) ((ATMEGA_BASEADDRESS) + 0x25) )
#define ADDR_TIM0_INTERRUPT_MASK ( (TIM0_2_INTERRUPT_MASK*) ((ATMEGA_BASEADDRESS) + 0x6E) )
#define ADDR_TIM0_COUNTERVALUE ( (TIM0_2_COUNTERVALUE*) ((ATMEGA_BASEADDRESS) + 0x26) )
#define ADDR_TIM0_OUTPUTCOMPARE_A ( (TIM0_2_OUTPUTCOMPARE_A*) ((ATMEGA_BASEADDRESS) + 0x27) )
#define ADDR_TIM0_OUTPUTCOMPARE_B ( (TIM0_2_OUTPUTCOMPARE_B*) ((ATMEGA_BASEADDRESS) + 0x28) )
#define ADDR_TIM0_INTERRUPT_FLAGS ( (TIM0_2_INTERRUPT_FLAGS*) ((ATMEGA_BASEADDRESS) + 0x15) )

//TIM1
#define ADDR_TIM1_CONTROLA ( (TIMx_CONTROLA*) ((ATMEGA_BASEADDRESS) + 0x80) )
#define ADDR_TIM1_CONTROLB ( (TIM1_CONTROLB*) ((ATMEGA_BASEADDRESS) + 0x81) )
#define ADDR_TIM1_CONTROLC ( (TIM1_CONTROLC*) ((ATMEGA_BASEADDRESS) + 0x82) )
#define ADDR_TIM1_COUNTERVALUE_LOW ( (TIM1_COUNTERVALUE_LOW*) ((ATMEGA_BASEADDRESS) + 0x84) )
#define ADDR_TIM1_COUNTERVALUE_HIGH ( (TIM1_COUNTERVALUE_HIGH*) ((ATMEGA_BASEADDRESS) + 0x85) )
#define ADDR_TIM1_INPUPTCAPTURE_LOW ( (TIM1_INPUPTCAPTURE_LOW*) ((ATMEGA_BASEADDRESS) + 0x86) )
#define ADDR_TIM1_INPUPTCAPTURE_HIGH ( (TIM1_INPUPTCAPTURE_HIGH*) ((ATMEGA_BASEADDRESS) + 0x87) )
#define ADDR_TIM1_OUTPUTCOMPARE_A_LOW ( (TIM1_OUTPUTCOMPARE_A_LOW*) ((ATMEGA_BASEADDRESS) + 0x88) )
#define ADDR_TIM1_OUTPUTCOMPARE_A_HIGH ( (TIM1_OUTPUTCOMPARE_A_HIGH*) ((ATMEGA_BASEADDRESS) + 0x89) )
#define ADDR_TIM1_OUTPUTCOMPARE_B_LOW ( (TIM1_OUTPUTCOMPARE_B_LOW*) ((ATMEGA_BASEADDRESS) + 0x8A) )
#define ADDR_TIM1_OUTPUTCOMPARE_B_HIGH ( (TIM1_OUTPUTCOMPARE_B_HIGH*) ((ATMEGA_BASEADDRESS) + 0x8B) )
#define ADDR_TIM1_INTERRUPT_MASK ( (TIM1_INTERRUPT_MASK*) ((ATMEGA_BASEADDRESS) + 0x6F) )
#define ADDR_TIM1_INTERRUPT_FLAGS ( (TIM1_INTERRUPT_FLAGS*) ((ATMEGA_BASEADDRESS) + 0x16) )

//TIM2
#define ADDR_TIM2_CONTROLA ( (TIMx_CONTROLA*) ((ATMEGA_BASEADDRESS) + 0xB0) )
#define ADDR_TIM2_CONTROLB ( (TIM0_2_CONTROLB*) ((ATMEGA_BASEADDRESS) + 0xB1) )
#define ADDR_TIM2_COUNTERVALUE ( (TIM0_2_COUNTERVALUE*) ((ATMEGA_BASEADDRESS) + 0xB2) )
#define ADDR_TIM2_OUTPUTCOMPARE_A ( (TIM0_2_OUTPUTCOMPARE_A*) ((ATMEGA_BASEADDRESS) + 0xB3) )
#define ADDR_TIM2_OUTPUTCOMPARE_B ( (TIM0_2_OUTPUTCOMPARE_B*) ((ATMEGA_BASEADDRESS) + 0xB4) )
#define ADDR_TIM2_INTERRUPT_MASK ( (TIM0_2_INTERRUPT_MASK*) ((ATMEGA_BASEADDRESS) + 0x70) )
#define ADDR_TIM2_INTERRUPT_FLAGS ( (TIM0_2_INTERRUPT_FLAGS*) ((ATMEGA_BASEADDRESS) + 0x17) )
#define ADDR_TIM2_ASYNCHRONOUS_STATUS ( (TIM2_ASYNCHRONOUS_STATUS*) ((ATMEGA_BASEADDRESS) + 0xB6) )


//TIMx_CONTROLA
/*Waveform Generation Modes Part 1*/
#define P1_NORMAL_MAXVAL_IS_0xFF 0x00
#define P1_PWM_PHASE_CORRECT_MAXVAL_IS_0xFF 0x01
#define P1_CTC_MAXVAL_IS_OUTCOMPVAL_A 0x02
#define P1_FAST_PWM_MAXVAL_IS_0xFF 0x03
#define P1_PHASECORRECT_PWM_MAXVAL_IS_OUTCOMPVAL_A 0x01
#define P1_FAST_PWM_MAXVAL_IS_OUTCOMPVAL_A 0x03
/*Waveform Generation Modes Part 1 (ONLY FOR TIMER 1)*/
#define TIM1_P1_NORMAL_MAXVAL_IS_0xFFFF 0x00
#define TIM1_P1_PWM_PHASE_CORRECT_8BIT 0x01
#define TIM1_P1_PWM_PHASE_CORRECT_9BIT 0x02
#define TIM1_P1_PWM_PHASE_CORRECT_10BIT 0x03
#define TIM1_P1_CTC_MAXVAL_IS_OUTCOMPVAL_A 0x00
#define TIM1_P1_FAST_PWM_8BIT 0x01
#define TIM1_P1_FAST_PWM_9BIT 0x02
#define TIM1_P1_FAST_PWM_10BIT 0x03
#define TIM1_P1_PHASE_AND_FREQ_CORRECT_PWM_MAXVAL_IS_INCAPTVAL 0x00
#define TIM1_P1_PHASE_AND_FREQ_CORRECT_PWM_MAXVAL_IS_OUTCOMPVAL_A 0x01
#define TIM1_P1_PHASECORRECT_PWM_MAXVAL_IS_INCAPTVAL 0x02
#define TIM1_P1_PHASECORRECT_PWM_MAXVAL_IS_OUTCOMPVAL_A 0x03
#define TIM1_P1_CTC_MAXVAL_IS_INCAPTVAL 0x00
#define TIM1_P1_FAST_PWM_MAXVAL_IS_INCAPTVAL 0x02
#define TIM1_P1_FAST_PWM_MAXVAL_IS_OUTCOMPVAL_A 0x03
/*Compare Output Modes*/
/*1------Compare Output Mode: Non-PWM*/
#define NORMAL 0x00
#define TOGGLE_PIN_ON_MATCH 0x01
#define GO_LOW_ON_MATCH 0x02
#define GO_HIGH_ON_MATCH 0x03
/*2------Compare Output Mode: Fast PWM*/
//NORMAL Can be used here 
#define NORMAL_OR_TOGGLE_ON_MATCH 0x01
#define HIGH_AT_START_LOW_ON_MATCH 0x02
#define LOW_AT_START_HIGH_ON_MATCH 0x00 0x03
/*3------Compare Output Mode: Phase Correct PWM*/
//NORMAL Can be used here 
//SET_OUTCOMP_AT_START_CLEAR_ON_MATCH Can be used here
#define LOW_GOING_UP_HIGH_GOING_DOWN 0x02
#define HIGH_GOING_UP_LOW_GOING_DOWN 0x03

//TIM0_2CONTROLB
/*Waveform Generation Modes Part 2*/
#define P2_NORMAL_MAXVAL_IS_0xFF 0x00
#define P2_PWM_PHASE_CORRECT_MAXVAL_IS_0xFF 0x00
#define P2_CTC_MAXVAL_IS_OUTCOMPVAL_A 0x00
#define P2_FAST_PWM_MAXVAL_IS_0xFF 0x00
#define P2_PHASECORRECT_PWM_MAXVAL_IS_OUTCOMPVAL_A 0x01
#define P2_FAST_PWM_MAXVAL_IS_OUTCOMPVAL_A 0x01

//TIM1_CONTROLB
/*Waveform Generation Modes Part 2 (ONLY FOR TIMER 1)*/
#define TIM1_P2_NORMAL_MAXVAL_IS_0xFFFF 0x00
#define TIM1_P2_PWM_PHASE_CORRECT_8BIT 0x00
#define TIM1_P2_PWM_PHASE_CORRECT_9BIT 0x00
#define TIM1_P2_PWM_PHASE_CORRECT_10BIT 0x00
#define TIM1_P2_CTC_MAXVAL_IS_OUTCOMPVAL_A 0x01
#define TIM1_P2_FAST_PWM_8BIT 0x01
#define TIM1_P2_FAST_PWM_9BIT 0x01
#define TIM1_P2_FAST_PWM_10BIT 0x01
#define TIM1_P2_PHASE_AND_FREQ_CORRECT_PWM_MAXVAL_IS_INCAPTVAL 0x02
#define TIM1_P2_PHASE_AND_FREQ_CORRECT_PWM_MAXVAL_IS_OUTCOMPVAL_A 0x02
#define TIM1_P2_PHASECORRECT_PWM_MAXVAL_IS_INCAPTVAL 0x02
#define TIM1_P2_PHASECORRECT_PWM_MAXVAL_IS_OUTCOMPVAL_A 0x02
#define TIM1_P2_CTC_MAXVAL_IS_INCAPTVAL 0x03
#define TIM1_P2_FAST_PWM_MAXVAL_IS_INCAPTVAL 0x03
#define TIM1_P2_FAST_PWM_MAXVAL_IS_OUTCOMPVAL_A 0x03

//Enums--------------------------------------------------------------------------------------------------

//TIMx_CONTROLB
/*Clock Source*/
enum _ClockSpeed {
	NO_CLOCK = 0x00,
	FULL_CLOCK = 0x01,
	_DIV_8 = 0x02,
	_DIV_64 = 0x03,
	_DIV_256 = 0x04,
	_DIV_1024 = 0x05,
	EXTERNALCLOCK_FALLEDGE = 0x06,
	EXTERNALCLOCK_RISEEDGE = 0x07
};

//Registers----------------------------------------------------------------------------------------------
typedef struct {
    const uint8_t reserved0:4;
    volatile uint8_t tim1On0_tim1Off1:1;
	volatile uint8_t tim0On0_tim0Off1:1;
	volatile uint8_t tim2On0_tim2Off1:1;
    const uint8_t reserved1:1;
}POWER_REDUCTION_TIM;

typedef struct {
	volatile uint8_t reset_Tim0AndTim1Prescaler:1;
	volatile uint8_t reset_Tim2Prescaler:1;
	const uint8_t reserved:5;
	volatile uint8_t enable_SyncMode:1;
}GENERAL_TIM_CONTROL;

typedef struct {
	volatile uint8_t rw_WaveFormGenerationModePart1:2;
	const uint8_t reserved:2;
	volatile uint8_t rw_ChannelBOutputCompareMode:2;
	volatile uint8_t rw_ChannelAOutputCompareMode:2;
}TIMx_CONTROLA;

typedef struct {
	volatile uint8_t select_ClockSource:3;
	volatile uint8_t rw_WaveFormGenerationModePart2:1;
	const uint8_t reserved:2;
	volatile uint8_t forceOutputCompareB:1;
	volatile uint8_t forceOutputCompareA:1;
}TIM0_2_CONTROLB;

typedef struct {
	volatile uint8_t select_ClockSource:3;
	volatile uint8_t rw_WaveFormGenerationModePart2:1;
	const uint8_t reserved:2;
	volatile uint8_t fallEdgeTrig0_riseEdgeTrig1:1;
	volatile uint8_t enable_InputCaptNoiseCanceler:1;
}TIM1_CONTROLB;

typedef struct {
	const uint8_t reserved:6;
	volatile uint8_t forceOutputCompareB:1;
	volatile uint8_t forceOutputCompareA:1;
}TIM1_CONTROLC;

typedef struct {
	volatile uint8_t rw_CounterValue:8;
}TIM0_2_COUNTERVALUE;

typedef struct {
	volatile uint8_t rw_CounterValueLowByte:8;
}TIM1_COUNTERVALUE_LOW;

typedef struct {
	volatile uint8_t rw_CounterValueHighByte:8;
}TIM1_COUNTERVALUE_HIGH;

typedef struct {
	volatile uint8_t rw_OutputCompareRegAValue:8;
}TIM0_2_OUTPUTCOMPARE_A;

typedef struct {
	volatile uint8_t rw_OutputCompareRegBValue:8;
}TIM0_2_OUTPUTCOMPARE_B;

typedef struct {
	volatile uint8_t rw_InputCaptValueLowByte:8;
}TIM1_INPUPTCAPTURE_LOW;

typedef struct {
	volatile uint8_t rw_InputCaptValueHighByte:8;
}TIM1_INPUPTCAPTURE_HIGH;

typedef struct {
	volatile uint8_t rw_OutputCompAValueLowByte:8;
}TIM1_OUTPUTCOMPARE_A_LOW;

typedef struct {
	volatile uint8_t rw_OutputCompAValueHighByte:8;
}TIM1_OUTPUTCOMPARE_A_HIGH;

typedef struct {
	volatile uint8_t rw_OutputCompBValueLowByte:8;
}TIM1_OUTPUTCOMPARE_B_LOW;

typedef struct {
	volatile uint8_t rw_OutputCompBValueHighByte:8;
}TIM1_OUTPUTCOMPARE_B_HIGH;

typedef struct {
	volatile uint8_t enable_OverflowInterrupt:1;
	volatile uint8_t enable_OutputCompAMatchInterrupt:1;
	volatile uint8_t enable_OutputCompBMatchInterrupt:1;
	const uint8_t reserved:5;
}TIM0_2_INTERRUPT_MASK;

typedef struct {
	volatile uint8_t enable_OverflowInterrupt:1;
	volatile uint8_t enable_OutputCompAMatchInterrupt:1;
	volatile uint8_t enable_OutputCompBMatchInterrupt:1;
	const uint8_t reserved0:2;
	volatile uint8_t enable_InputCaptureInterrupt:1;
	const uint8_t reserved1:2;
}TIM1_INTERRUPT_MASK;

typedef struct {
	volatile uint8_t overflowInterruptOccurred:1;
	volatile uint8_t outputCompAMatchInterruptOccurred:1;
	volatile uint8_t outputCompBMatchInterruptOccurred:1;
	const uint8_t reserved:5;
}TIM0_2_INTERRUPT_FLAGS;

typedef struct {
	volatile uint8_t overflowInterruptOccurred:1;
	volatile uint8_t outputCompAMatchInterruptOccurred:1;
	volatile uint8_t outputCompBMatchInterruptOccurred:1;
	const uint8_t reserved0:2;
	volatile uint8_t inputCaptureInterruptOccurred:1;
	const uint8_t reserved1:2;
}TIM1_INTERRUPT_FLAGS;

typedef struct {
	volatile uint8_t controlRegBUpdateBusy:1;
	volatile uint8_t controlRegAUpdateBusy:1;
	volatile uint8_t outputCompRegBUpdateBusy:1;
	volatile uint8_t outputCompRegAUpdateBusy:1;
	volatile uint8_t counterValueUpdateBusy:1;
	volatile uint8_t enable_AsynchronousClockSource:1;
	volatile uint8_t enable_ExternalClockInput:1;
	const uint8_t reserved:1;
}TIM2_ASYNCHRONOUS_STATUS;

#endif
