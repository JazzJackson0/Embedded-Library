//ATmega328/P Driver
#ifndef TIMER_COUNTER_H_
#define TIMER_COUNTER_H_
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

#include <stdint.h>

typedef enum _ClockSpeed E_ClockSpeed;

//DECLARATIONS
/**
 * @brief Initialize and Start Timer
 * 
 * @param timerID Timer ID (0-2)
 * @param clockSpeed Timer Clock Speed 
 * 					(NO_CLOCK, FULL_CLOCK, _DIV_x: Where x = 8, 64, 256, 1024, XTALCLOCK_FALLEDGE, 
 * 					XTALCLOCK_RISEEDGE)
 * @param time Time Goal: Example: Let (Clock Speed / Prescaler) = 1000Hz/Sec
 * 							---- For 1sec Time Goal: Time = 1000(Hz)
 * 						|||  00:00 ---> Time Goal |||  RESET
 *						|||  00:00 ---> Time Goal |||  RESET |||  ETC...)
 * @return ** void 
 */
void Timer_Start(uint8_t timerID, E_ClockSpeed clockSpeed, uint16_t time);
/**
 * @brief Initialize and Start Timer. Timer will not repeat, but will return 1 upon
 * 			reaching time goal.
 * 
 * @param timerID Timer ID (0-2)
 * @param clockSpeed Timer Clock Speed
 * @param time Time Goal: Example: Let (Clock Speed / Prescaler) = 1000Hz/Sec
 * 							---- For 1sec Time Goal: Time = 1000(Hz)
 * 						|||  00:00 ---> Time Goal |||  RESET
 *						|||  00:00 ---> Time Goal |||  RESET |||  ETC...)
 * @return ** uint8_t Value 1 is returned upon completion of timer.
 */
uint8_t OneShotTimer_Start(uint8_t timerID, E_ClockSpeed clockSpeed, uint16_t time);
/**
 * @brief Initialize PWM
 * 
 * @param timerID Timer ID (0-2)
 * @param clockSpeed Timer Clock Speed
 * @param time Time Goal: Example: Let (Clock Speed / Prescaler) = 1000Hz/Sec
 * 							---- For 1sec Time Goal: Time = 1000(Hz)
 * 						|||  00:00 ---> Time Goal |||  RESET
 *						|||  00:00 ---> Time Goal |||  RESET |||  ETC...)
 * @param dutyCycle PWM Duty Cycle 
 * @return ** void 
 */
void PWM_Init(uint8_t timerID, E_ClockSpeed clockSpeed, uint16_t time, float dutyCycle);
/**
 * @brief Update PWM with new Duty Cycle
 * 
 * @param timerID Timer ID (0-2)
 * @param time Time Goal: Example: Let (Clock Speed / Prescaler) = 1000Hz/Sec
 * 							---- For 1sec Time Goal: Time = 1000(Hz)
 * 						|||  00:00 ---> Time Goal |||  RESET
 *						|||  00:00 ---> Time Goal |||  RESET |||  ETC...)
 * @param dutyCycle PWM Duty Cycle
 * @return ** void 
 */
void PWM_Update(uint8_t timerID, uint16_t time, float dutyCycle);
/**
 * @brief Stop Timer mid-count.
 * 
 * @param timerID Timer ID (0-2)
 * @return ** uint16_t 
 */
uint16_t Stop_Timer(uint8_t timerID);


//TIMER (Powered by AVR Clock Control Unit)
typedef struct _timer0_2 TIMER0_2;
typedef struct _timer1 TIMER1;
typedef struct _interrupt_masks INT_MASK;
typedef struct _interrupt_flags INT_FLAG;
#define ATMEGA_BASEADDRESS 0x0000
//--------
#define ADDR_POWER_REDUCTION_TIM ( (POWER_REDUCTION_TIM*) ((ATMEGA_BASEADDRESS) + 0x64) ) //Found in Power Management Section
#define ADDR_GENERAL_TIM_CONTROL ( (GENERAL_TIM_CONTROL*) ((ATMEGA_BASEADDRESS) + 0x23) )//0,1,2
#define ADDR_TIM0 ( (TIMER0_2*) ((ATMEGA_BASEADDRESS) + 0x24) )
#define ADDR_TIM1 ( (TIMER1*) ((ATMEGA_BASEADDRESS) + 0x80) )
#define ADDR_TIM2 ( (TIMER0_2*) ((ATMEGA_BASEADDRESS) + 0xB0) )
#define ADDR_INT_MASK ( (INT_MASK*) ((ATMEGA_BASEADDRESS) + 0x6E) )
#define ADDR_INT_FLAG ( (INT_FLAG*) ((ATMEGA_BASEADDRESS) + 0x35) )


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
	NO_CLOCK = 0x00, FULL_CLOCK = 0x01, _DIV_8 = 0x02,
	_DIV_64 = 0x03, _DIV_256 = 0x04, _DIV_1024 = 0x05,
	XTALCLOCK_FALLEDGE = 0x06, XTALCLOCK_RISEEDGE = 0x07
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
	const uint8_t reserved:8;
}TIMER_RESERVED;

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
	volatile uint8_t rw_CounterValue:8;
}TIM1_COUNTERVALUE_LOW;

typedef struct {
	volatile uint8_t rw_CounterValue:8;
}TIM1_COUNTERVALUE_HIGH;

typedef struct {
	volatile uint8_t rw_OutputCompareValue:8;
}TIM0_2_OUTPUTCOMPARE_A;

typedef struct {
	volatile uint8_t rw_OutputCompareValue:8;
}TIM0_2_OUTPUTCOMPARE_B;

typedef struct {
	volatile uint8_t rw_InputCaptValue:8;
}TIM1_INPUPTCAPTURE_LOW;

typedef struct {
	volatile uint8_t rw_InputCaptValue:8;
}TIM1_INPUPTCAPTURE_HIGH;

typedef struct {
	volatile uint8_t rw_OutputCompAValue:8;
}TIM1_OUTPUTCOMPARE_A_LOW;

typedef struct {
	volatile uint8_t rw_OutputCompAValue:8;
}TIM1_OUTPUTCOMPARE_A_HIGH;

typedef struct {
	volatile uint8_t rw_OutputCompBValue:8;
}TIM1_OUTPUTCOMPARE_B_LOW;

typedef struct {
	volatile uint8_t rw_OutputCompBValue:8;
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


struct _timer0_2 {
	TIMx_CONTROLA ControlAReg; // Tim0: 0x24 | Tim2: 0xB0
	TIM0_2_CONTROLB ControlBReg; // Tim0: 0x25 | Tim2: 0xB1
	TIM0_2_COUNTERVALUE CounterValueReg; // Tim0: 0x26 | Tim2: 0xB2
	TIM0_2_OUTPUTCOMPARE_A OutputCompareAReg; // Tim0: 0x27 | Tim2: 0xB3
	TIM0_2_OUTPUTCOMPARE_B OutputCompareBReg; // Tim0: 0x28	| Tim2: 0xB4
	TIMER_RESERVED reserved; // Tim2: 0xB5
	TIM2_ASYNCHRONOUS_STATUS Tim2_AsyncStatusReg; // Tim2: 0xB6
};

struct _timer1 {
	TIMx_CONTROLA ControlAReg; // 0x80
	TIM1_CONTROLB ControlBReg; // 0x81
	TIM1_CONTROLC ControlCReg; // 0x82
	TIMER_RESERVED reserved; // 0x83
	TIM1_COUNTERVALUE_LOW CounterValueLowReg; // 0x84
	TIM1_COUNTERVALUE_HIGH CounterValueHighReg; // 0x85
	TIM1_INPUPTCAPTURE_LOW InputCaptureLowReg; // 0x86
	TIM1_INPUPTCAPTURE_HIGH InputCaptureHighReg; // 0x87
	TIM1_OUTPUTCOMPARE_A_LOW OutputCompareALowReg; // 0x88
	TIM1_OUTPUTCOMPARE_A_HIGH OutputCompareAHighReg; // 0x89
	TIM1_OUTPUTCOMPARE_B_LOW OutputCompareBLowReg; // 0x8A
	TIM1_OUTPUTCOMPARE_B_HIGH OutputCompareBHighReg; // 0x8B
};

struct _interrupt_masks {
	TIM0_2_INTERRUPT_MASK Tim0InterruptMaskReg; // 0x6E
	TIM1_INTERRUPT_MASK Tim1InterruptMaskReg; // 0x6F
	TIM0_2_INTERRUPT_MASK Tim2InterruptMaskReg; // 0x70
};

struct _interrupt_flags {
	TIM0_2_INTERRUPT_FLAGS Tim0InterruptFlagsReg; // 0x35
	TIM1_INTERRUPT_FLAGS Tim1InterruptFlagsReg; // 0x36
	TIM0_2_INTERRUPT_FLAGS Tim2InterruptFlagsReg; // 0x37
};

#endif
