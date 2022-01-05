#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include "timerGeneral9_14_STM32F446.h"
#include "gpio_STM32F446.h"

//Static Prototypes--------------------------------------------------------------
static void PWM_PinInit(uint8_t timerNum);
static void Activate_Clock(uint8_t timerNum);
static TIM9_14_CONTROL1* Get_TimerControlReg(uint8_t timerNum);
static TIM9_14_STATUS* Get_TimerStatusReg(uint8_t timerNum);
static TIM9_14_EVENTGEN* Get_TimerEventGenReg(uint8_t timerNum);
static TIM9_14_PRESCALER* Get_TimerPrescalerReg(uint8_t timerNum);
static TIM9_14_AUTORELOAD* Get_TimerAutoReloadReg(uint8_t timerNum);
static TIM9_14_COUNTER* Get_TimerCounterReg(uint8_t timerNum);
static TIM9_14_CAPTURECOMP_MODE1* Get_TimerCaptureCompMode1Reg(uint8_t timerNum);
static TIM9_14_CAPTURECOMP_ENABLE* Get_TimerCaptureCompEnableReg(uint8_t timerNum);
static TIM9_14_CAPTURECOMPx* Get_TimerCaptureCompReg(uint8_t timerNum, uint8_t captCompNum);


//Global Variables------------------------------------------------------------------
TIM9_10_11_CLOCK *const Clock9_11 = ADDR_TIM9_10_11_CLOCK;
TIM12_13_14_CLOCK *const Clock12_14 = ADDR_TIM12_13_14_CLOCK;
//TIMER 9
TIM9_14_CONTROL1 *const TIMControl_9 = ADDR_TIM9_CONTROL1;
TIM9_14_STATUS *const TIMStatus_9 = ADDR_TIM9_STATUS;
TIM9_14_EVENTGEN *const TIMEventGen_9 = ADDR_TIM9_EVENTGEN;
TIM9_14_PRESCALER *const TIMPrescaler_9 = ADDR_TIM9_PRESCALER;
TIM9_14_AUTORELOAD *const TIMAutoReld_9 = ADDR_TIM9_AUTORELOAD;
TIM9_14_COUNTER *const TIMCount_9 = ADDR_TIM9_COUNTER;
TIM9_14_CAPTURECOMP_MODE1 *const TIMCaptrCompMode1_9 = ADDR_TIM9_CAPTURECOMP_MODE1;
TIM9_14_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler_9 = ADDR_TIM9_CAPTURECOMP_ENABLE;
TIM9_14_CAPTURECOMPx *const TIMCaptrComp1_9 = ADDR_TIM9_CAPTURECOMP1;
TIM9_14_CAPTURECOMPx *const TIMCaptrComp2_9 = ADDR_TIM9_CAPTURECOMP2;

//TIMER 10
TIM9_14_CONTROL1 *const TIMControl_10 = ADDR_TIM10_CONTROL1;
TIM9_14_STATUS *const TIMStatus_10 = ADDR_TIM10_STATUS;
TIM9_14_EVENTGEN *const TIMEventGen_10 = ADDR_TIM10_EVENTGEN;
TIM9_14_PRESCALER *const TIMPrescaler_10 = ADDR_TIM10_PRESCALER;
TIM9_14_AUTORELOAD *const TIMAutoReld_10 = ADDR_TIM10_AUTORELOAD;
TIM9_14_COUNTER *const TIMCount_10 = ADDR_TIM10_COUNTER;
TIM9_14_CAPTURECOMP_MODE1 *const TIMCaptrCompMode1_10 = ADDR_TIM10_CAPTURECOMP_MODE1;
TIM9_14_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler_10 = ADDR_TIM10_CAPTURECOMP_ENABLE;
TIM9_14_CAPTURECOMPx *const TIMCaptrComp1_10 = ADDR_TIM10_CAPTURECOMP1;

//TIMER 11
TIM9_14_CONTROL1 *const TIMControl_11 = ADDR_TIM11_CONTROL1;
TIM9_14_STATUS *const TIMStatus_11 = ADDR_TIM11_STATUS;
TIM9_14_EVENTGEN *const TIMEventGen_11 = ADDR_TIM11_EVENTGEN;
TIM9_14_PRESCALER *const TIMPrescaler_11 = ADDR_TIM11_PRESCALER;
TIM9_14_AUTORELOAD *const TIMAutoReld_11 = ADDR_TIM11_AUTORELOAD;
TIM9_14_COUNTER *const TIMCount_11 = ADDR_TIM11_COUNTER;
TIM9_14_CAPTURECOMP_MODE1 *const TIMCaptrCompMode1_11 = ADDR_TIM11_CAPTURECOMP_MODE1;
TIM9_14_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler_11 = ADDR_TIM11_CAPTURECOMP_ENABLE;
TIM9_14_CAPTURECOMPx *const TIMCaptrComp1_11 = ADDR_TIM11_CAPTURECOMP1;

//TIMER 12
TIM9_14_CONTROL1 *const TIMControl_12 = ADDR_TIM12_CONTROL1;
TIM9_14_STATUS *const TIMStatus_12 = ADDR_TIM12_STATUS;
TIM9_14_EVENTGEN *const TIMEventGen_12 = ADDR_TIM12_EVENTGEN;
TIM9_14_PRESCALER *const TIMPrescaler_12 = ADDR_TIM12_PRESCALER;
TIM9_14_AUTORELOAD *const TIMAutoReld_12 = ADDR_TIM12_AUTORELOAD;
TIM9_14_COUNTER *const TIMCount_12 = ADDR_TIM12_COUNTER;
TIM9_14_CAPTURECOMP_MODE1 *const TIMCaptrCompMode1_12 = ADDR_TIM12_CAPTURECOMP_MODE1;
TIM9_14_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler_12 = ADDR_TIM12_CAPTURECOMP_ENABLE;
TIM9_14_CAPTURECOMPx *const TIMCaptrComp1_12 = ADDR_TIM12_CAPTURECOMP1;
TIM9_14_CAPTURECOMPx *const TIMCaptrComp2_12 = ADDR_TIM12_CAPTURECOMP2;

//TIMER 13
TIM9_14_CONTROL1 *const TIMControl_13 = ADDR_TIM13_CONTROL1;
TIM9_14_STATUS *const TIMStatus_13 = ADDR_TIM13_STATUS;
TIM9_14_EVENTGEN *const TIMEventGen_13 = ADDR_TIM13_EVENTGEN;
TIM9_14_PRESCALER *const TIMPrescaler_13 = ADDR_TIM13_PRESCALER;
TIM9_14_AUTORELOAD *const TIMAutoReld_13 = ADDR_TIM13_AUTORELOAD;
TIM9_14_COUNTER *const TIMCount_13 = ADDR_TIM13_COUNTER;
TIM9_14_CAPTURECOMP_MODE1 *const TIMCaptrCompMode1_13 = ADDR_TIM13_CAPTURECOMP_MODE1;
TIM9_14_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler_13 = ADDR_TIM13_CAPTURECOMP_ENABLE;
TIM9_14_CAPTURECOMPx *const TIMCaptrComp1_13 = ADDR_TIM13_CAPTURECOMP1;

//TIMER 14
TIM9_14_CONTROL1 *const TIMControl_14 = ADDR_TIM14_CONTROL1;
TIM9_14_STATUS *const TIMStatus_14 = ADDR_TIM14_STATUS;
TIM9_14_EVENTGEN *const TIMEventGen_14 = ADDR_TIM14_EVENTGEN;
TIM9_14_PRESCALER *const TIMPrescaler_14 = ADDR_TIM14_PRESCALER;
TIM9_14_AUTORELOAD *const TIMAutoReld_14 = ADDR_TIM14_AUTORELOAD;
TIM9_14_COUNTER *const TIMCount_14 = ADDR_TIM14_COUNTER;
TIM9_14_CAPTURECOMP_MODE1 *const TIMCaptrCompMode1_14 = ADDR_TIM14_CAPTURECOMP_MODE1;
TIM9_14_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler_14 = ADDR_TIM14_CAPTURECOMP_ENABLE;
TIM9_14_CAPTURECOMPx *const TIMCaptrComp1_14 = ADDR_TIM14_CAPTURECOMP1;



/*  
	Prescaler Example: 
		Clock Speed / Presclaler = Number of Hz per Second

	Time Example: 
		00:00 -------------> Time (Auto Reload)
				  RESET
		00:00 -------------> Time (Auto Reload)
				  ETC...
				  
	Example:
		Let (Clock Speed / Prescaler) = 1000Hz/Sec
		If Time = 1000Hz, then Time = 1 sec	
*/
uint8_t GeneralTimer9_14_Start(uint8_t timerNum, uint16_t prescaler, uint16_t time) {
	
	Activate_Clock(timerNum);
	
	TIM9_14_CONTROL1 *const TIMControl = Get_TimerControlReg(timerNum);
	TIM9_14_PRESCALER *const TIMPrescaler = Get_TimerPrescalerReg(timerNum);
	TIM9_14_AUTORELOAD *const TIMAutoReld = Get_TimerAutoReloadReg(timerNum);
	TIM9_14_COUNTER *const TIMCount = Get_TimerCounterReg(timerNum);

	TIMPrescaler->rw_PrescalerValue = prescaler;
	TIMAutoReld->rw_AutoReloadValue = time;
	TIMCount->rw_CounterValue = 0x00;
	TIMControl->enable_AutoReloadPreload = 1;
	TIMControl->enable_Counter = 1;
	
	return 1;
}


void GeneralTimer9_14_PWM_Start(uint8_t timerNum, uint8_t captCompNum, uint16_t prescaler, uint16_t time, float dutycycle) {
	
	Activate_Clock(timerNum);
	PWM_PinInit(timerNum);
	
	TIM9_14_CONTROL1 *const TIMControl = Get_TimerControlReg(timerNum);
	TIM9_14_PRESCALER *const TIMPrescaler = Get_TimerPrescalerReg(timerNum);
	TIM9_14_AUTORELOAD *const TIMAutoReld = Get_TimerAutoReloadReg(timerNum);
	TIM9_14_COUNTER *const TIMCount = Get_TimerCounterReg(timerNum);
	TIM9_14_CAPTURECOMP_MODE1 *const TIMCaptrCompMode1 = Get_TimerCaptureCompMode1Reg(timerNum);
	TIM9_14_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler = Get_TimerCaptureCompEnableReg(timerNum);
	
	TIM9_14_CAPTURECOMPx *const TIMCaptrComp1 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	TIM9_14_CAPTURECOMPx *const TIMCaptrComp2 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	
	TIMPrescaler->rw_PrescalerValue = prescaler;
	TIMAutoReld->rw_AutoReloadValue = time;
	TIMCount->rw_CounterValue = 0x00;
	TIMControl->enable_AutoReloadPreload = 1;
	TIMControl->enable_Counter = 1;

	switch (captCompNum) {
		
		case 1 :
			TIMCaptrCompMode1->OutputCompareMode.rw_OutputComp1Mode = PWM_ACTIVE_UNTIL_MATCH;
			TIMCaptrComp1->rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp1 = 1;
			break;
			
		case 2 :
			TIMCaptrCompMode1->OutputCompareMode.rw_OutputComp2Mode = PWM_ACTIVE_UNTIL_MATCH;
			TIMCaptrComp2->rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp2 = 1;
			break;
	}
		
	TIMControl->enable_Counter = 1;		
}

void GeneralTimer9_14_PWM_Update(uint8_t timerNum, uint8_t captCompNum, uint16_t time, float dutycycle) {
	
	TIM9_14_CONTROL1 *const TIMControl = Get_TimerControlReg(timerNum);
	TIM9_14_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler = Get_TimerCaptureCompEnableReg(timerNum);
	
	TIM9_14_CAPTURECOMPx *const TIMCaptrComp1 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	TIM9_14_CAPTURECOMPx *const TIMCaptrComp2 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	
	switch (captCompNum) {
		
		case 1 :
			TIMCaptrComp1->rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp1 = 1;
			break;
			
		case 2 :
			TIMCaptrComp2->rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp2 = 1;
			break;
	}
		
	TIMControl->enable_Counter = 1;	
}

//Helper Functions--------------------------------------------------------------------------------------------------------------

/**
TIMER Pins ---------------------------
		+ TIM9_CH1: PA2, PE5 (AF3)
		+ TIM9_CH2: PA3, PE6 (AF3)
		
		+ TIM10_CH1: PB8, PF6 (AF3)
		
		+ TIM11_CH1: PB9, PF7 (AF3)

		+ TIM12_CH1: PB14, PH6 (AF9)
		+ TIM12_CH2: PB15, PH9 (AF9)
		
		+ TIM13_CH1: PA6, PF8 (AF9)
		
		+ TIM14_CH1: PA7, PF9 (AF9)
		------------------------------------
**/
void PWM_PinInit(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 9 :
			Pin_Init('A', 2, AF3); //Channel 1
			Pin_Init('A', 3, AF3); //Channel 2
			break;
		case 10 :
			Pin_Init('B', 8, AF3); //Channel 1
			break;
		case 11 :
			Pin_Init('B', 9, AF3); //Channel 1
			break;
		case 12 :
			Pin_Init('B', 14, AF9); //Channel 1
			Pin_Init('B', 15, AF9); //Channel 2
			break;
		case 13 :
			Pin_Init('A', 6, AF9); //Channel 1
			break;
		case 14 :
			Pin_Init('A', 7, AF9); //Channel 1
			break;
	}
}

static void Activate_Clock(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 9 : 
			Clock9_11->tim9_StartTick = 1;
			break;
		case 10 : 
			Clock9_11->tim10_StartTick = 1;	
			break;
		case 11 : 
			Clock9_11->tim11_StartTick = 1;	
			break;
		case 12 : 
			Clock12_14->tim12_StartTick = 1;	
			break;
		case 13 : 
			Clock12_14->tim13_StartTick = 1;	
			break;
		case 14 : 
			Clock12_14->tim14_StartTick = 1;	
			break;
	}
}


static TIM9_14_CONTROL1* Get_TimerControlReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 9 :
			return TIMControl_9;
		case 10 :
			return TIMControl_10;
		case 11 :
			return TIMControl_11;
		case 12 :
			return TIMControl_12;
		case 13 :
			return TIMControl_13;
		case 14 :
			return TIMControl_14;
		default :
			return NULL;
	}
}

static TIM9_14_STATUS* Get_TimerStatusReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 9 :
			return TIMStatus_9;
		case 10 :
			return TIMStatus_10;
		case 11 :
			return TIMStatus_11;
		case 12 :
			return TIMStatus_12;
		case 13 :
			return TIMStatus_13;
		case 14 :
			return TIMStatus_14;
		default :
			return NULL;
	}
}

static TIM9_14_EVENTGEN* Get_TimerEventGenReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 9 :
			return TIMEventGen_9;
		case 10 :
			return TIMEventGen_10;
		case 11 :
			return TIMEventGen_11;
		case 12 :
			return TIMEventGen_12;
		case 13 :
			return TIMEventGen_13;
		case 14 :
			return TIMEventGen_14;
		default :
			return NULL;
	}
}

static TIM9_14_PRESCALER* Get_TimerPrescalerReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 9 :
			return TIMPrescaler_9;
		case 10 :
			return TIMPrescaler_10;
		case 11 :
			return TIMPrescaler_11;
		case 12 :
			return TIMPrescaler_12;
		case 13 :
			return TIMPrescaler_13;
		case 14 :
			return TIMPrescaler_14;
		default :
			return NULL;
	}
}

static TIM9_14_AUTORELOAD* Get_TimerAutoReloadReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 9 :
			return TIMAutoReld_9;
		case 10 :
			return TIMAutoReld_10;
		case 11 :
			return TIMAutoReld_11;
		case 12 :
			return TIMAutoReld_12;
		case 13 :
			return TIMAutoReld_13;
		case 14 :
			return TIMAutoReld_14;
		default :
			return NULL;
	}
}

static TIM9_14_COUNTER* Get_TimerCounterReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 9 :
			return TIMCount_9;
		case 10 :
			return TIMCount_10;
		case 11 :
			return TIMCount_11;
		case 12 :
			return TIMCount_12;
		case 13 :
			return TIMCount_13;
		case 14 :
			return TIMCount_14;
		default :
			return NULL;
	}
}

static TIM9_14_CAPTURECOMP_MODE1* Get_TimerCaptureCompMode1Reg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 9 :
			return TIMCaptrCompMode1_9;
		case 10 :
			return TIMCaptrCompMode1_10;
		case 11 :
			return TIMCaptrCompMode1_11;
		case 12 :
			return TIMCaptrCompMode1_12;
		case 13 :
			return TIMCaptrCompMode1_13;
		case 14 :
			return TIMCaptrCompMode1_14;
		default :
			return NULL;
	}
}

static TIM9_14_CAPTURECOMP_ENABLE* Get_TimerCaptureCompEnableReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 9 :
			return TIMCaptrCompEnabler_9;
		case 10 :
			return TIMCaptrCompEnabler_10;
		case 11 :
			return TIMCaptrCompEnabler_11;
		case 12 :
			return TIMCaptrCompEnabler_12;
		case 13 :
			return TIMCaptrCompEnabler_13;
		case 14 :
			return TIMCaptrCompEnabler_14;
		default :
			return NULL;
	}
}

static TIM9_14_CAPTURECOMPx* Get_TimerCaptureCompReg(uint8_t timerNum, uint8_t captCompNum) {
	
	switch (timerNum) {
		
		case 9 :
			if (captCompNum == 1) { return TIMCaptrComp1_9; }
			if (captCompNum == 2) { return TIMCaptrComp2_9; }
		case 10 :
			return TIMCaptrComp1_10;
		case 11 :
			return TIMCaptrComp1_11;
		case 12 :
			if (captCompNum == 1) { return TIMCaptrComp1_12; }
			if (captCompNum == 2) { return TIMCaptrComp2_12; }
		case 13 :
			return TIMCaptrComp1_13;
		case 14 :
			return TIMCaptrComp1_14;
		default :
			return NULL;
	}
}

