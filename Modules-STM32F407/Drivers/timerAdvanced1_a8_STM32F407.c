#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include "timerAdvanced1_a8_STM32F407.h"
#include "gpio_STM32F407.h"

//Static Prototypes--------------------------------------------------------------
static void PWM_PinInit(uint8_t timerNum);
static void Activate_Clock(uint8_t timerNum);
static TIM1_A8_CONTROL1* Get_TimerControlReg(uint8_t timerNum);
static TIM1_A8_STATUS* Get_TimerStatusReg(uint8_t timerNum);
static TIM1_A8_EVENTGEN* Get_TimerEventGenReg(uint8_t timerNum);
static TIM1_A8_PRESCALER* Get_TimerPrescalerReg(uint8_t timerNum);
static TIM1_A8_AUTORELOAD* Get_TimerAutoReloadReg(uint8_t timerNum);
static TIM1_A8_COUNTER* Get_TimerCounterReg(uint8_t timerNum);
static TIM1_A8_CAPTURECOMP_MODE1* Get_TimerCaptureCompMode1Reg(uint8_t timerNum);
static TIM1_A8_CAPTURECOMP_MODE2* Get_TimerCaptureCompMode2Reg(uint8_t timerNum);
static TIM1_A8_CAPTURECOMP_ENABLE* Get_TimerCaptureCompEnableReg(uint8_t timerNum);
static TIM1_A8_CAPTURECOMPx* Get_TimerCaptureCompReg(uint8_t timerNum, uint8_t captCompNum);

//Global Variables------------------------------------------------------------------
TIM1_8_CLOCK *const Adv1_8Clock = ADDR_TIM1_8_CLOCK;

//TIMER 1
TIM1_A8_CONTROL1 *const TIMControl_1 = ADDR_TIM1_CONTROL1;
TIM1_A8_STATUS *const TIMStatus_1 = ADDR_TIM1_STATUS;
TIM1_A8_EVENTGEN *const TIMEventGen_1 = ADDR_TIM1_EVENTGEN;
TIM1_A8_PRESCALER *const TIMPrescaler_1 = ADDR_TIM1_PRESCALER;
TIM1_A8_AUTORELOAD *const TIMAutoReld_1 = ADDR_TIM1_AUTORELOAD;
TIM1_A8_COUNTER *const TIMCount_1 = ADDR_TIM1_COUNTER;
TIM1_A8_CAPTURECOMP_MODE1 *const TIMCaptrCompMode1_1 = ADDR_TIM1_CAPTURECOMP_MODE1;
TIM1_A8_CAPTURECOMP_MODE2 *const TIMCaptrCompMode2_1 = ADDR_TIM1_CAPTURECOMP_MODE2;
TIM1_A8_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler_1 = ADDR_TIM1_CAPTURECOMP_ENABLE;
TIM1_A8_CAPTURECOMPx *const TIMCaptrComp1_1 = ADDR_TIM1_CAPTURECOMP1;
TIM1_A8_CAPTURECOMPx *const TIMCaptrComp2_1 = ADDR_TIM1_CAPTURECOMP2;
TIM1_A8_CAPTURECOMPx *const TIMCaptrComp3_1 = ADDR_TIM1_CAPTURECOMP3;
TIM1_A8_CAPTURECOMPx *const TIMCaptrComp4_1 = ADDR_TIM1_CAPTURECOMP4;

//TIMER 8
TIM1_A8_CONTROL1 *const TIMControl_8 = ADDR_TIM8_CONTROL1;
TIM1_A8_STATUS *const TIMStatus_8 = ADDR_TIM8_STATUS;
TIM1_A8_EVENTGEN *const TIMEventGen_8 = ADDR_TIM8_EVENTGEN;
TIM1_A8_PRESCALER *const TIMPrescaler_8 = ADDR_TIM8_PRESCALER;
TIM1_A8_AUTORELOAD *const TIMAutoReld_8 = ADDR_TIM8_AUTORELOAD;
TIM1_A8_COUNTER *const TIMCount_8 = ADDR_TIM8_COUNTER;
TIM1_A8_CAPTURECOMP_MODE1 *const TIMCaptrCompMode1_8 = ADDR_TIM8_CAPTURECOMP_MODE1;
TIM1_A8_CAPTURECOMP_MODE2 *const TIMCaptrCompMode2_8 = ADDR_TIM8_CAPTURECOMP_MODE2;
TIM1_A8_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler_8 = ADDR_TIM8_CAPTURECOMP_ENABLE;
TIM1_A8_CAPTURECOMPx *const TIMCaptrComp1_8 = ADDR_TIM8_CAPTURECOMP1;
TIM1_A8_CAPTURECOMPx *const TIMCaptrComp2_8 = ADDR_TIM8_CAPTURECOMP2;
TIM1_A8_CAPTURECOMPx *const TIMCaptrComp3_8 = ADDR_TIM8_CAPTURECOMP3;
TIM1_A8_CAPTURECOMPx *const TIMCaptrComp4_8 = ADDR_TIM8_CAPTURECOMP4;


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
uint8_t AdvancedTimer_Start(uint8_t timerNum, uint16_t prescaler, uint16_t time) {
	
	Activate_Clock(timerNum);
	
	TIM1_A8_CONTROL1 *const TIMControl = Get_TimerControlReg(timerNum);
	TIM1_A8_PRESCALER *const TIMPrescaler = Get_TimerPrescalerReg(timerNum);
	TIM1_A8_AUTORELOAD *const TIMAutoReld = Get_TimerAutoReloadReg(timerNum);
	TIM1_A8_COUNTER *const TIMCount = Get_TimerCounterReg(timerNum);
	
	TIMPrescaler->rw_PrescalerValue = prescaler;
	TIMAutoReld->rw_AutoReloadValue = time;
	TIMCount->rw_CounterValue = 0x00;
	TIMControl->enable_AutoReloadPreload = 1;
	TIMControl->enable_Counter = 1;
	
	return 1;
}

void AdvancedPWM_Start(uint8_t timerNum, uint8_t captCompNum, uint16_t prescaler, uint16_t time, float dutycycle) {
	
	TIM1_A8_CONTROL1 *const TIMControl = Get_TimerControlReg(timerNum);
	TIM1_A8_PRESCALER *const TIMPrescaler = Get_TimerPrescalerReg(timerNum);
	TIM1_A8_AUTORELOAD *const TIMAutoReld = Get_TimerAutoReloadReg(timerNum);
	TIM1_A8_COUNTER *const TIMCount = Get_TimerCounterReg(timerNum);
	TIM1_A8_CAPTURECOMP_MODE1 *const TIMCaptrCompMode1 = Get_TimerCaptureCompMode1Reg(timerNum);
	TIM1_A8_CAPTURECOMP_MODE2 *const TIMCaptrCompMode2 = Get_TimerCaptureCompMode2Reg(timerNum);
	TIM1_A8_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler = Get_TimerCaptureCompEnableReg(timerNum);
	
	TIM1_A8_CAPTURECOMPx *const TIMCaptrComp1 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	TIM1_A8_CAPTURECOMPx *const TIMCaptrComp2 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	TIM1_A8_CAPTURECOMPx *const TIMCaptrComp3 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	TIM1_A8_CAPTURECOMPx *const TIMCaptrComp4 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	
	Activate_Clock(timerNum);
	PWM_PinInit(timerNum);
	
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
			
		case 3 :
			TIMCaptrCompMode2->OutputCompareMode.rw_OutputComp3Mode = PWM_ACTIVE_UNTIL_MATCH;
			TIMCaptrComp3->rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp3 = 1;
			break;
			
		case 4 :
			TIMCaptrCompMode2->OutputCompareMode.rw_OutputComp4Mode = PWM_ACTIVE_UNTIL_MATCH;
			TIMCaptrComp4->rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp4 = 1;
			break;
	}
		
	TIMControl->enable_Counter = 1;		
}

void AdvancedPWM_Update(uint8_t timerNum, uint8_t captCompNum, uint16_t time, float dutycycle) {
	
	TIM1_A8_CONTROL1 *const TIMControl = Get_TimerControlReg(timerNum);
	TIM1_A8_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler = Get_TimerCaptureCompEnableReg(timerNum);
	
	TIM1_A8_CAPTURECOMPx *const TIMCaptrComp1 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	TIM1_A8_CAPTURECOMPx *const TIMCaptrComp2 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	TIM1_A8_CAPTURECOMPx *const TIMCaptrComp3 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	TIM1_A8_CAPTURECOMPx *const TIMCaptrComp4 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	
	switch (captCompNum) {
		
		case 1 :
			TIMCaptrComp1->rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp1 = 1;
			break;
			
		case 2 :
			TIMCaptrComp2->rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp2 = 1;
			break;
			
		case 3 :
			TIMCaptrComp3->rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp3 = 1;
			break;
			
		case 4 :
			TIMCaptrComp4->rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp4 = 1;
			break;
	}
		
	TIMControl->enable_Counter = 1;	
}

//Helper Functions--------------------------------------------------------------------------------------------------------------

/**
TIMER Pins ---------------------------
		+ TIM1_CH1: PA8, PE9 (AF1)
		+ TIM1_CH2: PA9, PE11 (AF1)
		+ TIM1_CH3: PA10, PE13 (AF1)
		+ TIM1_CH4: PA11, PE14 (AF1)
		+ TIM1_CH1N: PA7 (AF1)
		+ TIM1_CH1N: PB13, PE8 (AF1)
		+ TIM1_CH2N: PB0, PB14, PE10 (AF1)
		+ TIM1_CH3N: PB1, PB15, PE12 (AF1)
		+ TIM1_ETR: PA12, PE7 (AF1)
		+ TIM1_BKIN: PA6, PB12, PE15 (AF1)
		
		+ TIM8_CH1: PC6, PI5 (AF3)
		+ TIM8_CH2: PC7, PI6 (AF3)
		+ TIM8_CH3: PC8, PI7 (AF3)
		+ TIM8_CH4: PC9, PI2 (AF3)
		+ TIM8_CH1N: PA5, PA7, PH13 (AF3)
		+ TIM8_CH2N: PB0, PB14, PH14 (AF3)
		+ TIM8_CH3N: PB1, PB15, PH15 (AF3)
		+ TIM8_ETR: PA0, PI3 (AF3)
		+ TIM8_BKIN: PA6, PI4 (AF3)
		------------------------------------
**/
static void PWM_PinInit(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 :
			Pin_Init('A', 8, AF1); //Channel 1
			Pin_Init('A', 9, AF1); //Channel 2
			Pin_Init('A', 10, AF1); //Channel 3
			Pin_Init('A', 11, AF1); //Channel 4
			break;
		case 8 :
			Pin_Init('C', 6, AF3); //Channel 1
			Pin_Init('C', 7, AF3); //Channel 2
			Pin_Init('C', 8, AF3); //Channel 3
			Pin_Init('C', 9, AF3); //Channel 4
			break;
	}
}


static void Activate_Clock(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 : 
			Adv1_8Clock->tim1_StartTick = 1;
			break;
		case 8 : 
			Adv1_8Clock->tim8_StartTick = 1;	
			break;
	}
}


static TIM1_A8_CONTROL1* Get_TimerControlReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 :
			return TIMControl_1;
		case 8 :
			return TIMControl_8;
		default :
			return NULL;
	}
}

static TIM1_A8_STATUS* Get_TimerStatusReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 :
			return TIMStatus_1;
		case 8 :
			return TIMStatus_8;
		default :
			return NULL;
	}
}

static TIM1_A8_EVENTGEN* Get_TimerEventGenReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 :
			return TIMEventGen_1;
		case 8 :
			return TIMEventGen_8;
		default :
			return NULL;
	}
}

static TIM1_A8_PRESCALER* Get_TimerPrescalerReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 :
			return TIMPrescaler_1;
		case 8 :
			return TIMPrescaler_8;
		default :
			return NULL;
	}
}

static TIM1_A8_AUTORELOAD* Get_TimerAutoReloadReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 :
			return TIMAutoReld_1;
		case 8 :
			return TIMAutoReld_8;
		default :
			return NULL;
	}
}

static TIM1_A8_COUNTER* Get_TimerCounterReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 :
			return TIMCount_1;
		case 8 :
			return TIMCount_8;
		default :
			return NULL;
	}
}

static TIM1_A8_CAPTURECOMP_MODE1* Get_TimerCaptureCompMode1Reg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 :
			return TIMCaptrCompMode1_1;
		case 8 :
			return TIMCaptrCompMode1_8;
		default :
			return NULL;
	}
}

static TIM1_A8_CAPTURECOMP_MODE2* Get_TimerCaptureCompMode2Reg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 :
			return TIMCaptrCompMode2_1;
		case 8 :
			return TIMCaptrCompMode2_8;
		default :
			return NULL;
	}
}

static TIM1_A8_CAPTURECOMP_ENABLE* Get_TimerCaptureCompEnableReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 :
			return TIMCaptrCompEnabler_1;
		case 8 :
			return TIMCaptrCompEnabler_8;
		default :
			return NULL;
	}
}

static TIM1_A8_CAPTURECOMPx* Get_TimerCaptureCompReg(uint8_t timerNum, uint8_t captCompNum) {
	
	switch (timerNum) {
		
		case 1 :
			if (captCompNum == 1) { return TIMCaptrComp1_1; }
			if (captCompNum == 2) { return TIMCaptrComp2_1; }
			if (captCompNum == 3) { return TIMCaptrComp3_1; }
			if (captCompNum == 4) { return TIMCaptrComp4_1; }
		case 8 :
			if (captCompNum == 1) { return TIMCaptrComp1_8; }
			if (captCompNum == 2) { return TIMCaptrComp2_8; }
			if (captCompNum == 3) { return TIMCaptrComp3_8; }
			if (captCompNum == 4) { return TIMCaptrComp4_8; }
		default :
			return NULL;
	}
}


