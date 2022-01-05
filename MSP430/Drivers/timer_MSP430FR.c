#include <stdint.h>
#include <stddef.h>
//#include <stdio.h>
#include "timer_MSP430FR.h"
#include "digital_io_MSP430FR.h"

//Static Prototypes--------------------------------------------------------------
static void PWM_PinInit(char* timerID);
static TIM_A_CONTROL* Get_TimAControlReg(char* timerNum);
static TIMx_COUNTER* Get_CounterReg(char* timerNum);
static TIM_A_CAPTURECOMP_CONTROLx* Get_TimACaptCompReg(char* timerNum);
static TIMx_CAPTURECOMPx* Get_CaptComp0Reg(char* timerNum);
static TIMx_CAPTURECOMPx* Get_CaptComp1Reg(char* timerNum);

//Global Variables------------------------------------------------------------------
//TIMER A0
TIM_A_CONTROL *const TimControl_A0 = ADDR_TIM_A0_CONTROL;
TIMx_COUNTER *const TimCount_A0 = ADDR_TIM_A0_COUNTER;
TIM_A_CAPTURECOMP_CONTROLx *const TimCaptCompControl_A0 = ADDR_TIM_A0_CAPTURECOMP_CONTROL0;
TIMx_CAPTURECOMPx *const TimCaptComp0_A0 = ADDR_TIM_A0_CAPTURECOMP0;
TIMx_CAPTURECOMPx *const TimCaptComp1_A0 = ADDR_TIM_A0_CAPTURECOMP1;
//TIMER A1
TIM_A_CONTROL *const TimControl_A1 = ADDR_TIM_A1_CONTROL;
TIMx_COUNTER *const TimCount_A1 = ADDR_TIM_A1_COUNTER;
TIM_A_CAPTURECOMP_CONTROLx *const TimCaptCompControl_A1 = ADDR_TIM_A1_CAPTURECOMP_CONTROL0;
TIMx_CAPTURECOMPx *const TimCaptComp0_A1 = ADDR_TIM_A1_CAPTURECOMP0;
TIMx_CAPTURECOMPx *const TimCaptComp1_A1 = ADDR_TIM_A1_CAPTURECOMP1;
//TIMER B0
TIM_B_CONTROL *const TimControl_B0 = ADDR_TIM_B_CONTROL;
TIMx_COUNTER *const TimCount_B0 = ADDR_TIM_B_COUNTER;
TIM_B_CAPTURECOMP_CONTROLx *const TimCaptCompControl_B0 = ADDR_TIM_B_CAPTURECOMP_CONTROL0;
TIMx_CAPTURECOMPx *const TimCaptComp0_B0 = ADDR_TIM_B_CAPTURECOMP0;
TIMx_CAPTURECOMPx *const TimCaptComp1_B0 = ADDR_TIM_B_CAPTURECOMP1;

/**
- CLOCK SPEED: According to '3.2 Clock System Operation'
		+ MCLK & SMCLK = DCOCLK
		+ Then they are divided by 8
		+-----------------------------
		+ DCOCLK = 1MHz
		+ SMCLK & MCLK = 1 MHz / 8
		+ SMCLK & MCLK = 125KHz
**/
void Timer_Start(char* timerID, E_TimerPrescaler prescale, uint32_t time) {
	
	if (timerID == "B0") { 

		PWM_PinInit(timerID);
		TimControl_B0->select_ClockSource = TIM_SM_CLOCK;

		TimCount_B0->rw_TimerCountValue = 0x00;
		TimControl_B0->rw_InputClockDivider = prescale;
		TimCaptComp0_B0->rw_CaptureCompareValue = time;

		TimControl_B0->rw_TimerMode = UP_MODE; //Start the timer.
	}
	
	else { 
	
		TIM_A_CONTROL *const TimControl = Get_TimAControlReg(timerID); 
		TIMx_CAPTURECOMPx *const TimCaptComp0 = Get_CaptComp0Reg(timerID);

		PWM_PinInit(timerID);
		TimControl->select_ClockSource = TIM_SM_CLOCK;
		
		TimControl->clearTimerCounter = 1;
		TimControl->rw_InputClockDivider = prescale;
		TimCaptComp0->rw_CaptureCompareValue = time;
		
		TimControl->rw_TimerMode = UP_MODE; //Start the timer.
	}
}

void PWM_Start(char* timerID, E_TimerPrescaler prescale, uint32_t time, float dutyCycle) {

	
	if (timerID == "B0") { 
		
		PWM_PinInit(timerID);
		TimControl_B0->select_ClockSource = TIM_SM_CLOCK;
		
		TimCount_B0->rw_TimerCountValue = 0x00;
		TimControl_B0->rw_InputClockDivider = prescale;

		TimCaptCompControl_B0->compareMode0_captureMode1 = 0;
		TimCaptCompControl_B0->rw_CaptureMode = CAPTURE_ON_RISE;
		TimCaptCompControl_B0->rw_OutputMode = SET_RESET;
		
		//WHAT PIN IS THE MODULATED OUTPUT ON???????????????????
		TimCaptComp1_B0->rw_CaptureCompareValue = (dutyCycle * time); //Output HIGH until this value.
		TimCaptComp0_B0->rw_CaptureCompareValue = time; //Output LOW until this value.
		
		TimControl_B0->rw_TimerMode = UP_MODE; //Start the timer.
	}
	
	else { 
		
		TIM_A_CONTROL *const TimControl = Get_TimAControlReg(timerID);
		TIM_A_CAPTURECOMP_CONTROLx *const TimCaptCompControl = Get_TimACaptCompReg(timerID); 
		TIMx_CAPTURECOMPx *const TimCaptComp0 = Get_CaptComp0Reg(timerID);
		TIMx_CAPTURECOMPx *const TimCaptComp1 = Get_CaptComp1Reg(timerID);
		
		PWM_PinInit(timerID);
		TimControl->select_ClockSource = TIM_SM_CLOCK;
		
		TimControl->clearTimerCounter = 1;
		TimControl->rw_InputClockDivider = prescale;

		TimCaptCompControl->compareMode0_captureMode1 = 0;
		TimCaptCompControl->rw_CaptureMode = CAPTURE_ON_RISE;
		TimCaptCompControl->rw_OutputMode = SET_RESET;
		
		//WHAT PIN IS THE MODULATED OUTPUT ON???????????????????
		TimCaptComp1->rw_CaptureCompareValue = (dutyCycle * time); //Output HIGH until this value.
		TimCaptComp0->rw_CaptureCompareValue = time; //Output LOW until this value.
		
		TimControl->rw_TimerMode = UP_MODE; //Start the timer.
	}
}

void PWM_Update(char* timerID, uint32_t time, float dutycycle) {

	if (timerID == "B0") { 
	
		TimCaptComp1_B0->rw_CaptureCompareValue = (dutycycle * time);
		TimControl_B0->rw_TimerMode = UP_MODE; //Start the timer.
	}
	
	else { 
		
		TIM_A_CONTROL *const TimControl = Get_TimAControlReg(timerID); 
		TIMx_CAPTURECOMPx *const TimCaptComp1 = Get_CaptComp1Reg(timerID);
	
		TimCaptComp1->rw_CaptureCompareValue = (dutycycle * time);
		TimControl->rw_TimerMode = UP_MODE; //Start the timer.
	}
}

//Helper Functions--------------------------------------------------------------------------------------------------------------

/*TIMER Pins ---------------------------
		**Direction Pin: 0 for Input Capture | 1 for OutputCompare
		
		+ TimerA0 Input Clock: P1-2 		[(Secondary Function)-(Direction Pin: 0/1)]
		+ TimerA0 CaptureCompare 0-A: P1-6 	[(Tertiary Function)-(Direction Pin: 0/1)]
		+ TimerA0 CaptureCompare 1-A: P1-0 	[(Primary Function)-(Direction Pin: 0/1)]
		+ TimerA0 CaptureCompare 2-A: P1-1 	[(Primary Function)-(Direction Pin: 0/1)]
		+ TimerA0 CaptureCompare 0-B: P2-3 	[(Primary Function)-(Direction Pin: 0/1)]
		
		+ TimerA1 Input Clock: P1-1 		[(Secondary Function)-(Direction Pin: 0/1)]
		+ TimerA1 CaptureCompare 0-A: P1-7 	[(Tertiary Function)-(Direction Pin: 0/1)]
		+ TimerA1 CaptureCompare 1-A: P1-2 	[(Primary Function)-(Direction Pin: 0/1)]		
		+ TimerA1 CaptureCompare 2-A: P1-3 	[(Primary Function)-(Direction Pin: 0/1)]
		+ TimerA1 CaptureCompare 0-B: P2-4 	[(Primary Function)-(Direction Pin: 0/1)]
		
		+ TimerB0 CaptureCompare 1: P2-6 	[(Primary Function)-(Direction Pin: 1)]
		+ TimerB0 CaptureCompare 2: P2-2 	[(Primary Function)-(Direction Pin: 1)]
		+ TimerB0 CaptureCompare 0-A: P2-1 	[(Primary Function)-(Direction Pin: 0/1)]
		+ TimerB0 CaptureCompare 1-A: P1-4 	[(Primary Function)-(Direction Pin: 0/1)]
		+ TimerB0 CaptureCompare 2-A: P1-5 	[(Primary Function)-(Direction Pin: 0/1)]
		+ TimerB0 CaptureCompare 3-A: P3-4 	[(Primary Function)-(Direction Pin: 0/1)]
		+ TimerB0 CaptureCompare 4-A: P3-5 	[(Primary Function)-(Direction Pin: 0/1)]
		+ TimerB0 CaptureCompare 5-A: P3-6 	[(Primary Function)-(Direction Pin: 0/1)]
		+ TimerB0 CaptureCompare 6-A: P3-7 	[(Primary Function)-(Direction Pin: 0/1)]
		+ TimerB0 CaptureCompare 0-B: P2-5 	[(Primary Function)-(Direction Pin: 0/1)]
		+ TimerB0 CaptureCompare 3-B: P1-6 	[(Primary Function)-(Direction Pin: 0/1)]
		+ TimerB0 CaptureCompare 4-B: P1-7 	[(Primary Function)-(Direction Pin: 0/1)]
		+ TimerB0 CaptureCompare 5-B: P4-4 	[(Primary Function)-(Direction Pin: 0/1)]
		+ TimerB0 CaptureCompare 6-B: P2-0 	[(Primary Function)-(Direction Pin: 0/1)]
		------------------------------------*/
static void PWM_PinInit(char* timerID) {
	
	Watchdog_Off();

	if (timerID == "A0") {
		
		Pin_Init('1', 6, OUT, TERTIARY_F, NO_PULL); //Capture Comp 0-A
		Pin_Init('1', 0, OUT, PRIMARY_F, NO_PULL); //Capture Comp 1-A
	}
	
	else if (timerID == "A1") {
		
		Pin_Init('1', 7, OUT, TERTIARY_F, NO_PULL); //Capture Comp 0-A
		Pin_Init('1', 2, OUT, PRIMARY_F, NO_PULL); //Capture Comp 1-A
	}
	
	else if (timerID == "B0") {
		
		Pin_Init('2', 1, OUT, PRIMARY_F, NO_PULL); //Capture Comp 0-A
		Pin_Init('1', 4, OUT, PRIMARY_F, NO_PULL); //Capture Comp 1-A
	}
}

static TIM_A_CONTROL* Get_TimAControlReg(char* timerNum) {
	
	if (timerNum == "A0") { return TimControl_A0; }
	if (timerNum == "A1") { return TimControl_A1; }
	return NULL;
}

static TIMx_COUNTER* Get_CounterReg(char* timerNum) {
	
	if (timerNum == "A0") { return TimCount_A0; }
	if (timerNum == "A1") { return TimCount_A1; }
	if (timerNum == "B0") { return TimCount_B0; }
	return NULL;
}

static TIM_A_CAPTURECOMP_CONTROLx* Get_TimACaptCompReg(char* timerNum) {
	
	if (timerNum == "A0") { return TimCaptCompControl_A0; }
	if (timerNum == "A1") { return TimCaptCompControl_A1; }
	return NULL;
}

static TIMx_CAPTURECOMPx* Get_CaptComp0Reg(char* timerNum) {
	
	if (timerNum == "A0") { return TimCaptComp0_A0; }
	if (timerNum == "A1") { return TimCaptComp0_A1; }
	if (timerNum == "B0") { return TimCaptComp0_B0; }
	return NULL;
}

static TIMx_CAPTURECOMPx* Get_CaptComp1Reg(char* timerNum) {
	
	if (timerNum == "A0") { return TimCaptComp1_A0; }
	if (timerNum == "A1") { return TimCaptComp1_A1; }
	if (timerNum == "B0") { return TimCaptComp1_B0; }
	return NULL;
}

