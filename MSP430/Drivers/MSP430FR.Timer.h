//MSP430FR59xx Driver
#ifndef TIMER_H_
#define TIMER_H_
#include <stdint.h>
//#include <stdio.h>
#include "MSP430FR.DigitalIO.h"

typedef enum _TimerPrescaler E_TimerPrescaler;

//DECLARATIONS
/**
 * @brief Initialize and Start Timer
 * 
 * @param timerID Timer ID (A0-A3, B0)
 * @param prescale Clock Prescaler value (DIV_x: Where x = 1, 2, 4, 8)
 * @param time Time Goal: Example: Let (Clock Speed / Prescaler) = 1000Hz/Sec
 * 							---- For 1sec Time Goal: Time = 1000(Hz)
 * 						|||  00:00 ---> Time Goal |||  RESET
 *						|||  00:00 ---> Time Goal |||  RESET |||  ETC...)
 * @return ** void 
 */
void Timer_Start(char* timerID, E_TimerPrescaler prescale, uint32_t time);
/**
 * @brief Initialize and Start Pulse Width Modulation
 * 
 * @param timerID Timer ID (A0-A3, B0)
 * @param prescale Clock Prescaler value
 * @param time Time Goal: Example: Let (Clock Speed / Prescaler) = 1000Hz/Sec
 * 							---- For 1sec Time Goal: Time = 1000(Hz)
 * 						|||  00:00 ---> Time Goal |||  RESET
 *						|||  00:00 ---> Time Goal |||  RESET |||  ETC...)
 * @param dutyCyclePercent PWM Duty Cycle as a percentage value (0% - 100%).
 * @return ** void 
 */
void PWM_Start(char* timerID, E_TimerPrescaler prescale, uint32_t time, float dutyCyclePercent);
/**
 * @brief Update Pulse Width Modulation with new Duty Cycle
 * 
 * @param timerID Timer ID (A0-A3, B0)
 * @param time Time Goal: Example: Let (Clock Speed / Prescaler) = 1000Hz/Sec
 * 							---- For 1sec Time Goal: Time = 1000(Hz)
 * 						|||  00:00 ---> Time Goal |||  RESET
 *						|||  00:00 ---> Time Goal |||  RESET |||  ETC...)
 * @param dutyCyclePercent PWM Duty Cycle as a percentage value (0% - 100%).
 * @return ** void 
 */
void PWM_Update(char* timerID, uint32_t time, float dutyCyclePercent);

//TIMER
typedef struct _timerA TIMERAx;
typedef struct _timerB TIMERBx;
#define TIMER_BASE 0x300
#define ADDR_TIM_A0 ( (TIMERAx*) ((TIMER_BASE) + 0x40) )
#define ADDR_TIM_A1 ( (TIMERAx*) ((TIMER_BASE) + 0x80) )
#define ADDR_TIM_A2 ( (TIMERAx*) ((TIMER_BASE) + 0x100) )
#define ADDR_TIM_A3 ( (TIMERAx*) ((TIMER_BASE) + 0x140) )
#define ADDR_TIM_B0 ( (TIMERBx*) ((TIMER_BASE) + 0xC0) )


//TIM_x_CONTROL
/*Mode Types*/
#define STOP_MODE 0x00
#define UP_MODE 0x01
#define CONTINUOUS_MODE 0x02
#define UPDOWN_MODE 0x03

/*Clock Source*/
#define TIM_TAx_CLOCK 0x00
#define TIM_A_CLOCK 0x01
#define TIM_SM_CLOCK 0x02
#define TIM_IN_CLOCK 0x03

//TIM_B_CONTROL
/*Counter Length*/
#define TIMB_DIV_1 0x00
#define TIMB_DIV_2 0x01
#define TIMB_DIV_4 0x02
#define TIMB_DIV_8 0x03

//TIM_x_CAPTURECOMP_CONTROL
/*Output Mode*/
#define BITVAL_OUT 0x00
#define SET 0x01
#define TOGGLE_RESET 0x02
#define SET_RESET 0x03
#define TOGGLE 0x04
#define RESET 0x05
#define TOGGLE_SET 0x06
#define RESET_SET 0x07
/*Input Signal*/
#define CCIxA 0x00
#define CCIxB 0x01
#define GND 0x02
#define VCC 0x03
/*Capture Mode*/
#define NO_CAPTURE 0x00
#define CAPTURE_ON_RISE 0x01
#define CAPTURE_ON_FALL 0x02
#define CAPTURE_ON_RISE_AND_FALL 0x03

//TIMx_EXPANSION
/*Input Clock Divider*/
#define TIM_EX_DIV_1 0x00
#define TIM_EX_DIV_2 0x01
#define TIM_EX_DIV_3 0x02
#define TIM_EX_DIV_4 0x03
#define TIM_EX_DIV_5 0x04
#define TIM_EX_DIV_6 0x05
#define TIM_EX_DIV_7 0x06
#define TIM_EX_DIV_8 0x07

//Enums-------------------------------------------------------------------------------------
//TIM_x_CONTROL
/*Input Clock Divider*/
enum _TimerPrescaler {
	DIV_1 = 0x00, DIV_2 = 0x01,
	DIV_4 = 0x02, DIV_8 = 0x03
};

//Registers---------------------------------------------------------------------------------
typedef struct {
	volatile uint16_t timerAInterruptOccurred:1;
	volatile uint16_t enable_TimerAInterrupt:1;
	volatile uint16_t clearTimerCounter:1;
	const uint16_t reserved0:1;
	volatile uint16_t rw_TimerMode:2;
	volatile uint16_t rw_InputClockDivider:2;
	volatile uint16_t select_ClockSource:2;
	const uint16_t reserved1:6;
}TIM_A_CONTROL;

typedef struct {
	volatile uint16_t timerBInterruptOccurred:1;
	volatile uint16_t enable_TimerBInterrupt:1;
	const uint16_t reserved0:1;
	volatile uint16_t rw_TimerMode:2;
	volatile uint16_t rw_InputClockDivider:2;
	volatile uint16_t select_ClockSource:2;
	volatile uint16_t rw_CounterLength:2;
	volatile uint16_t rw_UpdateControlParameters:2;
	const uint16_t reserved1:1;
}TIM_B_CONTROL;

typedef struct {
	volatile uint16_t rw_TimerCountValue:16;
}TIMx_COUNTER;

typedef struct {
	volatile uint16_t captureCompareInterruptOccurred:1;
	volatile uint16_t captureOverflowOccurred:1;
	volatile uint16_t lowOutput0_highOutput1:1;
	volatile uint16_t read_CaptureCompareInput:1;
	volatile uint16_t enable_CaptureCompareInterrupt:1;
	volatile uint16_t rw_OutputMode:3;
	volatile uint16_t compareMode0_captureMode1:1;
	const uint16_t reserved:1;
	volatile uint16_t read_SyncedCaptureCompareInput:1;
	volatile uint16_t asyncCapture0_syncCapture1:1;
	volatile uint16_t rw_CaptureCompareInputSignal:2;
	volatile uint16_t rw_CaptureMode:2;
}TIM_A_CAPTURECOMP_CONTROLx;

typedef struct {
	volatile uint16_t captureCompareInterruptOccurred:1;
	volatile uint16_t captureOverflowOccurred:1;
	volatile uint16_t lowOutput0_highOutput1:1;
	volatile uint16_t read_CaptureCompareInput:1;
	volatile uint16_t enable_CaptureCompareInterrupt:1;
	volatile uint16_t rw_OutputMode:3;
	volatile uint16_t compareMode0_captureMode1:1;
	volatile uint16_t rw_CompareLatchLoadEvent:2;
	volatile uint16_t asyncCapture0_syncCapture1:1;
	volatile uint16_t rw_CaptureCompareInputSignal:2;
	volatile uint16_t rw_CaptureMode:2;
}TIM_B_CAPTURECOMP_CONTROLx;

typedef struct {
	volatile uint16_t rw_CaptureCompareValue:16;
}TIMx_CAPTURECOMPx;

typedef struct {
	volatile uint16_t read_HighestPriorityInterruptPending:16;
}TIMx_INTERRUPT_VECTOR;

typedef struct {
	volatile uint16_t rw_InputClockDivider:3;
	const uint16_t reserved:13;
}TIMx_EXPANSION;

struct _timerA {
	TIM_A_CONTROL ControlReg; // 0x00
	TIMx_COUNTER CounterReg; // 0x10
	TIM_A_CAPTURECOMP_CONTROLx CaptureCompControlReg0; // 0x02
	TIM_A_CAPTURECOMP_CONTROLx CaptureCompControlReg1; // 0x04
	TIM_A_CAPTURECOMP_CONTROLx CaptureCompControlReg2; // 0x06 (Not Available For: A2-A3)
	TIM_A_CAPTURECOMP_CONTROLx CaptureCompControlReg3; // 0x08 (Not Available For: A1-A3)
	TIM_A_CAPTURECOMP_CONTROLx CaptureCompControlReg4; // 0x0A (Not Available For: A1-A3)
	TIMx_CAPTURECOMPx CaptureCompReg0; // 0x12
	TIMx_CAPTURECOMPx CaptureCompReg1; // 0x14
	TIMx_CAPTURECOMPx CaptureCompReg2; // 0x16 (Not Available For: A2-A3)
	TIMx_CAPTURECOMPx CaptureCompReg3; // 0x18 (Not Available For: A1-A3)
	TIMx_CAPTURECOMPx CaptureCompReg4; // 0x1A (Not Available For: A1-A3)
	TIMx_INTERRUPT_VECTOR InterruptVectorReg; // 0x2E 
	TIMx_EXPANSION ExpansionReg; // 0x20
};

struct _timerB {
	TIM_B_CONTROL ControlReg; // 0x00
	TIMx_COUNTER CounterReg; // 0x10
	TIM_B_CAPTURECOMP_CONTROLx CaptureCompControlReg0; // 0x02
	TIM_B_CAPTURECOMP_CONTROLx CaptureCompControlReg1; // 0x04
	TIM_B_CAPTURECOMP_CONTROLx CaptureCompControlReg2; // 0x06
	TIM_B_CAPTURECOMP_CONTROLx CaptureCompControlReg3; // 0x08
	TIM_B_CAPTURECOMP_CONTROLx CaptureCompControlReg4; // 0x0A
	TIM_B_CAPTURECOMP_CONTROLx CaptureCompControlReg5; // 0x0C
	TIM_B_CAPTURECOMP_CONTROLx CaptureCompControlReg6; // 0x0E????
	TIMx_CAPTURECOMPx CaptureCompReg0; // 0x12
	TIMx_CAPTURECOMPx CaptureCompReg1; // 0x14
	TIMx_CAPTURECOMPx CaptureCompReg2; // 0x16
	TIMx_CAPTURECOMPx CaptureCompReg3; // 0x18
	TIMx_CAPTURECOMPx CaptureCompReg4; // 0x1A
	TIMx_CAPTURECOMPx CaptureCompReg5; // 0x1C
	TIMx_CAPTURECOMPx CaptureCompReg6; // 0x1E
	TIMx_INTERRUPT_VECTOR InterruptVectorReg; // 0x2E 
	TIMx_EXPANSION ExpansionReg; // 0x20
};

#endif
