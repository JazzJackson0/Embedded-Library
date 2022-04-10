#include "MSP430FR.Timer.h"

//Static Prototypes--------------------------------------------------------------
static void PWM_PinInit(char* timerID);
static TIMERAx* Get_TimerA(char* timerID);

//Global Variables------------------------------------------------------------------
//TIMER
TIMERAx *const Tim_A0 = ADDR_TIM_A0;
TIMERAx *const Tim_A1 = ADDR_TIM_A1;
TIMERAx *const Tim_A2 = ADDR_TIM_A2;
TIMERAx *const Tim_A3 = ADDR_TIM_A3;
TIMERBx *const Tim_B0 = ADDR_TIM_B0;


void Timer_Start(char* timerID, E_TimerPrescaler prescale, uint32_t time) {
	
	if (timerID == "B0") { 

		TIMERBx *const TIMER = Tim_B0;

		PWM_PinInit(timerID);
		TIMER->ControlReg.select_ClockSource = TIM_SM_CLOCK;

		TIMER->CounterReg.rw_TimerCountValue = 0x00;
		TIMER->ControlReg.rw_InputClockDivider = prescale;
		TIMER->CaptureCompReg0.rw_CaptureCompareValue = time;

		TIMER->ControlReg.rw_TimerMode = UP_MODE; //Start the timer.
	}
	
	else { 
		
		TIMERAx *const TIMER = Get_TimerA(timerID);

		PWM_PinInit(timerID);
		TIMER->ControlReg.select_ClockSource = TIM_SM_CLOCK;
		
		TIMER->ControlReg.clearTimerCounter = 1;
		TIMER->ControlReg.rw_InputClockDivider = prescale;
		TIMER->CaptureCompReg0.rw_CaptureCompareValue = time;
		
		TIMER->ControlReg.rw_TimerMode = UP_MODE; //Start the timer.
	}
}

void PWM_Start(char* timerID, E_TimerPrescaler prescale, uint32_t time, float dutyCyclePercent) {

	if ( dutyCyclePercent > 100.0 ) { dutyCyclePercent = 100.0; }
	if ( dutyCyclePercent < 0.0 ) { dutyCyclePercent = 0.0; }
	
	if (timerID == "B0") { 
		
		TIMERBx *const TIMER = Tim_B0;

		PWM_PinInit(timerID);
		TIMER->ControlReg.select_ClockSource = TIM_SM_CLOCK;
		
		TIMER->CounterReg.rw_TimerCountValue = 0x00;
		TIMER->ControlReg.rw_InputClockDivider = prescale;

		TIMER->CaptureCompControlReg1.compareMode0_captureMode1 = 0;
		TIMER->CaptureCompControlReg1.rw_CaptureMode = CAPTURE_ON_RISE;
		TIMER->CaptureCompControlReg1.rw_OutputMode = TOGGLE; //CHECK TOGGLE IN DATASHEET!!!!!!!!
		TIMER->CaptureCompControlReg0.compareMode0_captureMode1 = 0;
		TIMER->CaptureCompControlReg0.rw_CaptureMode = CAPTURE_ON_FALL; //CHECK THIS IN DATASHEET!!!!!!!!
		TIMER->CaptureCompControlReg0.rw_OutputMode = SET_RESET;
		
		
		//WHAT PIN IS THE MODULATED OUTPUT ON???????????????????
		TIMER->CaptureCompReg1.rw_CaptureCompareValue = ((dutyCyclePercent / 100) * time); //Output HIGH until this value.
		TIMER->CaptureCompReg0.rw_CaptureCompareValue = time; //Output LOW until this value.
		
		TIMER->ControlReg.rw_TimerMode = UP_MODE; //Start the timer.
	}
	
	else { 
		
		TIMERAx *const TIMER = Get_TimerA(timerID);
		
		PWM_PinInit(timerID);
		TIMER->ControlReg.select_ClockSource = TIM_SM_CLOCK;
		
		TIMER->ControlReg.clearTimerCounter = 1;
		TIMER->ControlReg.rw_InputClockDivider = prescale;

		TIMER->CaptureCompControlReg1.compareMode0_captureMode1 = 0;
		TIMER->CaptureCompControlReg1.rw_CaptureMode = CAPTURE_ON_RISE;
		TIMER->CaptureCompControlReg1.rw_OutputMode = TOGGLE; //CHECK TOGGLE IN DATASHEET!!!!!!!!
		TIMER->CaptureCompControlReg0.compareMode0_captureMode1 = 0;
		TIMER->CaptureCompControlReg0.rw_CaptureMode = CAPTURE_ON_FALL; //CHECK THIS IN DATASHEET!!!!!!!!
		TIMER->CaptureCompControlReg0.rw_OutputMode = SET_RESET;
		
		//WHAT PIN IS THE MODULATED OUTPUT ON???????????????????
		TIMER->CaptureCompReg1.rw_CaptureCompareValue = ((dutyCyclePercent / 100) * time); //Output HIGH until this value.
		TIMER->CaptureCompReg0.rw_CaptureCompareValue = time; //Output LOW until this value.
		
		TIMER->ControlReg.rw_TimerMode = UP_MODE; //Start the timer.
	}
}

void PWM_Update(char* timerID, uint32_t time, float dutyCyclePercent) {

	if ( dutyCyclePercent > 100.0 ) { dutyCyclePercent = 100.0; }
	if ( dutyCyclePercent < 0.0 ) { dutyCyclePercent = 0.0; }
	
	if (timerID == "B0") { 
		TIMERBx *const TIMER = Tim_B0;
		
		TIMER->CaptureCompReg1.rw_CaptureCompareValue = ((dutyCyclePercent / 100) * time);
		TIMER->ControlReg.rw_TimerMode = UP_MODE; //Start the timer.
	}
	
	else { 
		TIMERAx *const TIMER = Get_TimerA(timerID);
	
		TIMER->CaptureCompReg1.rw_CaptureCompareValue = ((dutyCyclePercent / 100) * time);
		TIMER->ControlReg.rw_TimerMode = UP_MODE; //Start the timer.
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

static TIMERAx* Get_TimerA(char* timerID) {

	if (timerID == "A0") { return Tim_A0; }
	else if (timerID == "A1") { return Tim_A1; }
	else if (timerID == "A2") { return Tim_A2; }
	else if (timerID == "A3") { return Tim_A3; }
	return NULL;
}

