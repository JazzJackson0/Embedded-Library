//MSP430FR59xx Driver
#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>

typedef enum _TimerPrescaler E_TimerPrescaler;

void Timer_Start(char* timerID, E_TimerPrescaler prescale, uint32_t time);
void PWM_Start(char* timerID, E_TimerPrescaler prescale, uint32_t time, float dutyCycle);
void PWM_Update(char* timerID, uint32_t time, float dutycycle);

#define TIMER_A0 0x0340
#define TIMER_A1 0x0380
#define TIMER_A2 0x0400
#define TIMER_A3 0x0440
#define TIMER_B0 0x03C0

//TIMER A0 (CAPTCOMP 5 - 6 not used with x69 Series)
#define ADDR_TIM_A0_CONTROL ( (TIM_A_CONTROL*) ((TIMER_A0) + 0x00) )
#define ADDR_TIM_A0_COUNTER ( (TIMx_COUNTER*) ((TIMER_A0) + 0x10) )

#define ADDR_TIM_A0_CAPTURECOMP_CONTROL0 ( (TIM_A_CAPTURECOMP_CONTROLx*) ((TIMER_A0) + 0x02) )
#define ADDR_TIM_A0_CAPTURECOMP_CONTROL1 ( (TIM_A_CAPTURECOMP_CONTROLx*) ((TIMER_A0) + 0x04) )
#define ADDR_TIM_A0_CAPTURECOMP_CONTROL2 ( (TIM_A_CAPTURECOMP_CONTROLx*) ((TIMER_A0) + 0x06) )
#define ADDR_TIM_A0_CAPTURECOMP_CONTROL3 ( (TIM_A_CAPTURECOMP_CONTROLx*) ((TIMER_A0) + 0x08) )
#define ADDR_TIM_A0_CAPTURECOMP_CONTROL4 ( (TIM_A_CAPTURECOMP_CONTROLx*) ((TIMER_A0) + 0x0A) )

#define ADDR_TIM_A0_CAPTURECOMP0 ( (TIMx_CAPTURECOMPx*) ((TIMER_A0) + 0x12) )
#define ADDR_TIM_A0_CAPTURECOMP1 ( (TIMx_CAPTURECOMPx*) ((TIMER_A0) + 0x14) )
#define ADDR_TIM_A0_CAPTURECOMP2 ( (TIMx_CAPTURECOMPx*) ((TIMER_A0) + 0x16) )
#define ADDR_TIM_A0_CAPTURECOMP3 ( (TIMx_CAPTURECOMPx*) ((TIMER_A0) + 0x18) )
#define ADDR_TIM_A0_CAPTURECOMP4 ( (TIMx_CAPTURECOMPx*) ((TIMER_A0) + 0x1A) )

#define ADDR_TIM_A0_INTERRUPT_VECTOR ( (TIMx_INTERRUPT_VECTOR*) ((TIMER_A0) + 0x2E) )
#define ADDR_TIM_A0_EXPANSION ( (TIMx_EXPANSION*) ((TIMER_A0) + 0x20) )

//TIMER A1 (CAPTCOMP 3 - 6 not used with x69 Series)
#define ADDR_TIM_A1_CONTROL ( (TIM_A_CONTROL*) ((TIMER_A1) + 0x00) )
#define ADDR_TIM_A1_COUNTER ( (TIMx_COUNTER*) ((TIMER_A1) + 0x10) )

#define ADDR_TIM_A1_CAPTURECOMP_CONTROL0 ( (TIM_A_CAPTURECOMP_CONTROLx*) ((TIMER_A1) + 0x02) )
#define ADDR_TIM_A1_CAPTURECOMP_CONTROL1 ( (TIM_A_CAPTURECOMP_CONTROLx*) ((TIMER_A1) + 0x04) )
#define ADDR_TIM_A1_CAPTURECOMP_CONTROL2 ( (TIM_A_CAPTURECOMP_CONTROLx*) ((TIMER_A1) + 0x06) )

#define ADDR_TIM_A1_CAPTURECOMP0 ( (TIMx_CAPTURECOMPx*) ((TIMER_A1) + 0x12) )
#define ADDR_TIM_A1_CAPTURECOMP1 ( (TIMx_CAPTURECOMPx*) ((TIMER_A1) + 0x14) )
#define ADDR_TIM_A1_CAPTURECOMP2 ( (TIMx_CAPTURECOMPx*) ((TIMER_A1) + 0x16) )

#define ADDR_TIM_A1_INTERRUPT_VECTOR ( (TIMx_INTERRUPT_VECTOR*) ((TIMER_A1) + 0x2E) )
#define ADDR_TIM_A1_EXPANSION ( (TIMx_EXPANSION*) ((TIMER_A1) + 0x20) )

//TIMER A2 (CAPTCOMP 2 - 6 not used with x69 Series)
#define ADDR_TIM_A2_CONTROL ( (TIM_A_CONTROL*) ((TIMER_A2) + 0x00) )
#define ADDR_TIM_A2_COUNTER ( (TIMx_COUNTER*) ((TIMER_A2) + 0x10) )

#define ADDR_TIM_A2_CAPTURECOMP_CONTROL0 ( (TIM_A_CAPTURECOMP_CONTROLx*) ((TIMER_A2) + 0x02) )
#define ADDR_TIM_A2_CAPTURECOMP_CONTROL1 ( (TIM_A_CAPTURECOMP_CONTROLx*) ((TIMER_A2) + 0x04) )

#define ADDR_TIM_A2_CAPTURECOMP0 ( (TIMx_CAPTURECOMPx*) ((TIMER_A2) + 0x12) )
#define ADDR_TIM_A2_CAPTURECOMP1 ( (TIMx_CAPTURECOMPx*) ((TIMER_A2) + 0x14) )

#define ADDR_TIM_A2_INTERRUPT_VECTOR ( (TIMx_INTERRUPT_VECTOR*) ((TIMER_A2) + 0x2E) )
#define ADDR_TIM_A2_EXPANSION ( (TIMx_EXPANSION*) ((TIMER_A2) + 0x20) )

//TIMER A3 (CAPTCOMP 2 - 6 not used with x69 Series)
#define ADDR_TIM_A3_CONTROL ( (TIM_A_CONTROL*) ((TIMER_A3) + 0x00) )
#define ADDR_TIM_A3_COUNTER ( (TIMx_COUNTER*) ((TIMER_A3) + 0x10) )

#define ADDR_TIM_A3_CAPTURECOMP_CONTROL0 ( (TIM_A_CAPTURECOMP_CONTROLx*) ((TIMER_A3) + 0x02) )
#define ADDR_TIM_A3_CAPTURECOMP_CONTROL1 ( (TIM_A_CAPTURECOMP_CONTROLx*) ((TIMER_A3) + 0x04) )

#define ADDR_TIM_A3_CAPTURECOMP0 ( (TIMx_CAPTURECOMPx*) ((TIMER_A3) + 0x12) )
#define ADDR_TIM_A3_CAPTURECOMP1 ( (TIMx_CAPTURECOMPx*) ((TIMER_A3) + 0x14) )

#define ADDR_TIM_A3_INTERRUPT_VECTOR ( (TIMx_INTERRUPT_VECTOR*) ((TIMER_A3) + 0x2E) )
#define ADDR_TIM_A3_EXPANSION ( (TIMx_EXPANSION*) ((TIMER_A3) + 0x20) )

//TIMER B0
#define ADDR_TIM_B_CONTROL ( (TIM_B_CONTROL*) ((TIMER_B0) + 0x00) )
#define ADDR_TIM_B_COUNTER ( (TIMx_COUNTER*) ((TIMER_B0) + 0x10) )

#define ADDR_TIM_B_CAPTURECOMP_CONTROL0 ( (TIM_B_CAPTURECOMP_CONTROLx*) ((TIMER_B0) + 0x02) )
#define ADDR_TIM_B_CAPTURECOMP_CONTROL1 ( (TIM_B_CAPTURECOMP_CONTROLx*) ((TIMER_B0) + 0x04) )
#define ADDR_TIM_B_CAPTURECOMP_CONTROL2 ( (TIM_B_CAPTURECOMP_CONTROLx*) ((TIMER_B0) + 0x06) )
#define ADDR_TIM_B_CAPTURECOMP_CONTROL3 ( (TIM_B_CAPTURECOMP_CONTROLx*) ((TIMER_B0) + 0x08) )
#define ADDR_TIM_B_CAPTURECOMP_CONTROL4 ( (TIM_B_CAPTURECOMP_CONTROLx*) ((TIMER_B0) + 0x0A) )
#define ADDR_TIM_B_CAPTURECOMP_CONTROL5 ( (TIM_B_CAPTURECOMP_CONTROLx*) ((TIMER_B0) + 0x0C) )
#define ADDR_TIM_B_CAPTURECOMP_CONTROL6 ( (TIM_B_CAPTURECOMP_CONTROLx*) ((TIMER_B0) + 0x0C) )

#define ADDR_TIM_B_CAPTURECOMP0 ( (TIMx_CAPTURECOMPx*) ((TIMER_B0) + 0x12) )
#define ADDR_TIM_B_CAPTURECOMP1 ( (TIMx_CAPTURECOMPx*) ((TIMER_B0) + 0x14) )
#define ADDR_TIM_B_CAPTURECOMP2 ( (TIMx_CAPTURECOMPx*) ((TIMER_B0) + 0x16) )
#define ADDR_TIM_B_CAPTURECOMP3 ( (TIMx_CAPTURECOMPx*) ((TIMER_B0) + 0x18) )
#define ADDR_TIM_B_CAPTURECOMP4 ( (TIMx_CAPTURECOMPx*) ((TIMER_B0) + 0x1A) )
#define ADDR_TIM_B_CAPTURECOMP5 ( (TIMx_CAPTURECOMPx*) ((TIMER_B0) + 0x1C) )
#define ADDR_TIM_B_CAPTURECOMP6 ( (TIMx_CAPTURECOMPx*) ((TIMER_B0) + 0x1E) )

#define ADDR_TIM_B_INTERRUPT_VECTOR ( (TIMx_INTERRUPT_VECTOR*) ((TIMER_B0) + 0x2E) )
#define ADDR_TIM_B_EXPANSION ( (TIMx_EXPANSION*) ((TIMER_B0) + 0x20) )

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
	DIV_1 = 0x00,
	DIV_2 = 0x01,
	DIV_4 = 0x02,
	DIV_8 = 0x03
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

#endif
