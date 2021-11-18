#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include "timerGeneral2_5_STM32F446.h"
#include "gpio_STM32F446.h"

//Static Prototypes--------------------------------------------------------------
static void PWM_PinInit(uint8_t timerNum);
static void Activate_Clock(uint8_t timerNum);
static TIM2_5_CONTROL1* Get_TimerControlReg(uint8_t timerNum);
static TIM2_5_STATUS* Get_TimerStatusReg(uint8_t timerNum);
static TIM2_5_EVENTGEN* Get_TimerEventGenReg(uint8_t timerNum);
static TIM2_5_PRESCALER* Get_TimerPrescalerReg(uint8_t timerNum);
static TIM2_5_AUTORELOAD* Get_TimerAutoReloadReg(uint8_t timerNum);
static TIM2_5_COUNTER* Get_TimerCounterReg(uint8_t timerNum);
static TIM2_5_CAPTURECOMP_MODE1* Get_TimerCaptureCompMode1Reg(uint8_t timerNum);
static TIM2_5_CAPTURECOMP_MODE2* Get_TimerCaptureCompMode2Reg(uint8_t timerNum);
static TIM2_5_CAPTURECOMP_ENABLE* Get_TimerCaptureCompEnableReg(uint8_t timerNum);
static TIM2_5_CAPTURECOMPx* Get_TimerCaptureCompReg(uint8_t timerNum, uint8_t captCompNum);

//Global Variables------------------------------------------------------------------
TIM2_5_CLOCK *const Clock2_5 = ADDR_TIM2_5_CLOCK;

//TIMER 2
TIM2_5_CONTROL1 *const TIMControl_2 = ADDR_TIM2_CONTROL1;
TIM2_5_STATUS *const TIMStatus_2 = ADDR_TIM2_STATUS;
TIM2_5_EVENTGEN *const TIMEventGen_2 = ADDR_TIM2_EVENTGEN;
TIM2_5_PRESCALER *const TIMPrescaler_2 = ADDR_TIM2_PRESCALER;
TIM2_5_AUTORELOAD *const TIMAutoReld_2 = ADDR_TIM2_AUTORELOAD;
TIM2_5_COUNTER *const TIMCount_2 = ADDR_TIM2_COUNTER;
TIM2_5_CAPTURECOMP_MODE1 *const TIMCaptrCompMode1_2 = ADDR_TIM2_CAPTURECOMP_MODE1;
TIM2_5_CAPTURECOMP_MODE2 *const TIMCaptrCompMode2_2 = ADDR_TIM2_CAPTURECOMP_MODE2;
TIM2_5_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler_2 = ADDR_TIM2_CAPTURECOMP_ENABLE;
TIM2_5_CAPTURECOMPx *const TIMCaptrComp1_2 = ADDR_TIM2_CAPTURECOMP1;
TIM2_5_CAPTURECOMPx *const TIMCaptrComp2_2 = ADDR_TIM2_CAPTURECOMP2;
TIM2_5_CAPTURECOMPx *const TIMCaptrComp3_2 = ADDR_TIM2_CAPTURECOMP3;
TIM2_5_CAPTURECOMPx *const TIMCaptrComp4_2 = ADDR_TIM2_CAPTURECOMP4;

//TIMER 3
TIM2_5_CONTROL1 *const TIMControl_3 = ADDR_TIM3_CONTROL1;
TIM2_5_STATUS *const TIMStatus_3 = ADDR_TIM3_STATUS;
TIM2_5_EVENTGEN *const TIMEventGen_3 = ADDR_TIM3_EVENTGEN;
TIM2_5_PRESCALER *const TIMPrescaler_3 = ADDR_TIM3_PRESCALER;
TIM2_5_AUTORELOAD *const TIMAutoReld_3 = ADDR_TIM3_AUTORELOAD;
TIM2_5_COUNTER *const TIMCount_3 = ADDR_TIM3_COUNTER;
TIM2_5_CAPTURECOMP_MODE1 *const TIMCaptrCompMode1_3 = ADDR_TIM3_CAPTURECOMP_MODE1;
TIM2_5_CAPTURECOMP_MODE2 *const TIMCaptrCompMode2_3 = ADDR_TIM3_CAPTURECOMP_MODE2;
TIM2_5_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler_3 = ADDR_TIM3_CAPTURECOMP_ENABLE;
TIM2_5_CAPTURECOMPx *const TIMCaptrComp1_3 = ADDR_TIM3_CAPTURECOMP1;
TIM2_5_CAPTURECOMPx *const TIMCaptrComp2_3 = ADDR_TIM3_CAPTURECOMP2;
TIM2_5_CAPTURECOMPx *const TIMCaptrComp3_3 = ADDR_TIM3_CAPTURECOMP3;
TIM2_5_CAPTURECOMPx *const TIMCaptrComp4_3 = ADDR_TIM3_CAPTURECOMP4;

//TIMER 4
TIM2_5_CONTROL1 *const TIMControl_4 = ADDR_TIM4_CONTROL1;
TIM2_5_STATUS *const TIMStatus_4 = ADDR_TIM4_STATUS;
TIM2_5_EVENTGEN *const TIMEventGen_4 = ADDR_TIM4_EVENTGEN;
TIM2_5_PRESCALER *const TIMPrescaler_4 = ADDR_TIM4_PRESCALER;
TIM2_5_AUTORELOAD *const TIMAutoReld_4 = ADDR_TIM4_AUTORELOAD;
TIM2_5_COUNTER *const TIMCount_4 = ADDR_TIM4_COUNTER;
TIM2_5_CAPTURECOMP_MODE1 *const TIMCaptrCompMode1_4 = ADDR_TIM4_CAPTURECOMP_MODE1;
TIM2_5_CAPTURECOMP_MODE2 *const TIMCaptrCompMode2_4 = ADDR_TIM4_CAPTURECOMP_MODE2;
TIM2_5_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler_4 = ADDR_TIM4_CAPTURECOMP_ENABLE;
TIM2_5_CAPTURECOMPx *const TIMCaptrComp1_4 = ADDR_TIM4_CAPTURECOMP1;
TIM2_5_CAPTURECOMPx *const TIMCaptrComp2_4 = ADDR_TIM4_CAPTURECOMP2;
TIM2_5_CAPTURECOMPx *const TIMCaptrComp3_4 = ADDR_TIM4_CAPTURECOMP3;
TIM2_5_CAPTURECOMPx *const TIMCaptrComp4_4 = ADDR_TIM4_CAPTURECOMP4;

//TIMER 5
TIM2_5_CONTROL1 *const TIMControl_5 = ADDR_TIM5_CONTROL1;
TIM2_5_STATUS *const TIMStatus_5 = ADDR_TIM5_STATUS;
TIM2_5_EVENTGEN *const TIMEventGen_5 = ADDR_TIM5_EVENTGEN;
TIM2_5_PRESCALER *const TIMPrescaler_5 = ADDR_TIM5_PRESCALER;
TIM2_5_AUTORELOAD *const TIMAutoReld_5 = ADDR_TIM5_AUTORELOAD;
TIM2_5_COUNTER *const TIMCount_5 = ADDR_TIM5_COUNTER;
TIM2_5_CAPTURECOMP_MODE1 *const TIMCaptrCompMode1_5 = ADDR_TIM5_CAPTURECOMP_MODE1;
TIM2_5_CAPTURECOMP_MODE2 *const TIMCaptrCompMode2_5 = ADDR_TIM5_CAPTURECOMP_MODE2;
TIM2_5_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler_5 = ADDR_TIM5_CAPTURECOMP_ENABLE;
TIM2_5_CAPTURECOMPx *const TIMCaptrComp1_5 = ADDR_TIM5_CAPTURECOMP1;
TIM2_5_CAPTURECOMPx *const TIMCaptrComp2_5 = ADDR_TIM5_CAPTURECOMP2;
TIM2_5_CAPTURECOMPx *const TIMCaptrComp3_5 = ADDR_TIM5_CAPTURECOMP3;
TIM2_5_CAPTURECOMPx *const TIMCaptrComp4_5 = ADDR_TIM5_CAPTURECOMP4;


/**  
	Prescaler Example: 
		Clock Speed / Presclaler = Number of Hz per Second

	Time Example: 
		00:00 -------------> Time (Auto Reload)
				  RESET
		00:00 -------------> Time (Auto Reload)
				  ETC...
				  
	Example:
		Let (Clock Speed / Prescaler) = 1000Hz/Sec
		If the parameter time = 1000(Hz), then Time = 1 sec	
**/
uint8_t GeneralTimer2_5_Start(uint8_t timerNum, uint16_t prescaler, uint16_t time) {
	
	Activate_Clock(timerNum);
	
	TIM2_5_CONTROL1 *const TIMControl = Get_TimerControlReg(timerNum);
	TIM2_5_PRESCALER *const TIMPrescaler = Get_TimerPrescalerReg(timerNum);
	TIM2_5_AUTORELOAD *const TIMAutoReld = Get_TimerAutoReloadReg(timerNum);
	TIM2_5_COUNTER *const TIMCount = Get_TimerCounterReg(timerNum);

	TIMPrescaler->rw_PrescalerValue = prescaler;
	TIMAutoReld->rw_AutoReloadValue = time;
	TIMCount->rw_CounterValue = 0x00;
	TIMControl->enable_AutoReloadPreload = 1;
	TIMControl->enable_Counter = 1;
	
	return 1;
}

void GeneralTimer2_5_PWM_Start(uint8_t timerNum, uint8_t captCompNum, uint16_t prescaler, uint16_t time, float dutycycle) {
	
	Activate_Clock(timerNum);
	
	TIM2_5_CONTROL1 *const TIMControl = Get_TimerControlReg(timerNum);
	TIM2_5_PRESCALER *const TIMPrescaler = Get_TimerPrescalerReg(timerNum);
	TIM2_5_AUTORELOAD *const TIMAutoReld = Get_TimerAutoReloadReg(timerNum);
	TIM2_5_COUNTER *const TIMCount = Get_TimerCounterReg(timerNum);
	TIM2_5_CAPTURECOMP_MODE1 *const TIMCaptrCompMode1 = Get_TimerCaptureCompMode1Reg(timerNum);
	TIM2_5_CAPTURECOMP_MODE2 *const TIMCaptrCompMode2 = Get_TimerCaptureCompMode2Reg(timerNum);
	TIM2_5_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler = Get_TimerCaptureCompEnableReg(timerNum);
	
	TIM2_5_CAPTURECOMPx *const TIMCaptrComp1 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	TIM2_5_CAPTURECOMPx *const TIMCaptrComp2 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	TIM2_5_CAPTURECOMPx *const TIMCaptrComp3 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	TIM2_5_CAPTURECOMPx *const TIMCaptrComp4 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	
	PWM_PinInit(timerNum);
	
	TIMPrescaler->rw_PrescalerValue = prescaler;
	TIMAutoReld->rw_AutoReloadValue = time;
	TIMCount->rw_CounterValue = 0x00;
	TIMControl->enable_AutoReloadPreload = 1;
	TIMControl->enable_Counter = 1;

	switch (captCompNum) {
		
		case 1 :
			TIMCaptrCompMode1->OutputCompareMode.rw_OutputComp1Mode = PWM_ACTIVE_UNTIL_MATCH;
			TIMCaptrComp1->NormalCaptureComp.rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp1 = 1;
			break;
			
		case 2 :
			TIMCaptrCompMode1->OutputCompareMode.rw_OutputComp2Mode = PWM_ACTIVE_UNTIL_MATCH;
			TIMCaptrComp2->NormalCaptureComp.rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp2 = 1;
			break;
			
		case 3 :
			TIMCaptrCompMode2->OutputCompareMode.rw_OutputComp3Mode = PWM_ACTIVE_UNTIL_MATCH;
			TIMCaptrComp3->NormalCaptureComp.rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp3 = 1;
			break;
			
		case 4 :
			TIMCaptrCompMode2->OutputCompareMode.rw_OutputComp4Mode = PWM_ACTIVE_UNTIL_MATCH;
			TIMCaptrComp4->NormalCaptureComp.rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp4 = 1;
			break;
	}
		
	TIMControl->enable_Counter = 1;		
}

void GeneralTimer2_5_PWM_Update(uint8_t timerNum, uint8_t captCompNum, uint16_t time, float dutycycle) {
	
	TIM2_5_CONTROL1 *const TIMControl = Get_TimerControlReg(timerNum);
	TIM2_5_CAPTURECOMP_ENABLE *const TIMCaptrCompEnabler = Get_TimerCaptureCompEnableReg(timerNum);
	
	TIM2_5_CAPTURECOMPx *const TIMCaptrComp1 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	TIM2_5_CAPTURECOMPx *const TIMCaptrComp2 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	TIM2_5_CAPTURECOMPx *const TIMCaptrComp3 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	TIM2_5_CAPTURECOMPx *const TIMCaptrComp4 = Get_TimerCaptureCompReg(timerNum, captCompNum);
	
	switch (captCompNum) {
		
		case 1 :
			TIMCaptrComp1->NormalCaptureComp.rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp1 = 1;
			break;
			
		case 2 :
			TIMCaptrComp2->NormalCaptureComp.rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp2 = 1;
			break;
			
		case 3 :
			TIMCaptrComp3->NormalCaptureComp.rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp3 = 1;
			break;
			
		case 4 :
			TIMCaptrComp4->NormalCaptureComp.rw_CaptureCompValue = (dutycycle * time);
			TIMCaptrCompEnabler->enable_CaptComp4 = 1;
			break;
	}
		
	TIMControl->enable_Counter = 1;	
}

//Helper Functions--------------------------------------------------------------------------------------------------------------

/**
TIMER Pins ---------------------------
		
		+ TIM2_CH1: PA15 (AF1)
		+ TIM2_CH2: PA1, PB3 (AF1)
		+ TIM2_CH3: PA2, PB10 (AF1)
		+ TIM2_CH4: PA3, PB11 (AF1)
		+ TIM2_CH1_ETR: PA0, PA5 (AF1)
		+ TIM2_ETR: PA15 (AF1)

		+ TIM3_CH1: PA6, PB4, PC6 (AF2)
		+ TIM3_CH2: PA7, PB5, PC7 (AF2)
		+ TIM3_CH3: PB0, PC8 (AF2)
		+ TIM3_CH4: PB1, PC9 (AF2)
		+ TIM3_ETR: PD2 (AF2)

		+ TIM4_CH1: PB6, PD12 (AF2)
		+ TIM4_CH2: PB7, PD13 (AF2)
		+ TIM4_CH3: PB8, PD14 (AF2)
		+ TIM4_CH4: PB9, PD15 (AF2)
		+ TIM4_ETR: PE0 (AF2)
		
		+ TIM5_CH1: PA0, PH10 (AF2)
		+ TIM5_CH2: PA1, PH11 (AF2)
		+ TIM5_CH3: PA2, PH12 (AF2)
		+ TIM5_CH4: PA3, PI0 (AF2)
		------------------------------------
**/
static void PWM_PinInit(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 2 :
			Pin_Init('A', 15, AF1); //Channel 1
			Pin_Init('A', 1, AF1); //Channel 2
			Pin_Init('A', 2, AF1); //Channel 3
			Pin_Init('A', 3, AF1); //Channel 4
			break;
		case 3 :
			Pin_Init('A', 6, AF2); //Channel 1
			Pin_Init('A', 7, AF2); //Channel 2
			Pin_Init('B', 0, AF2); //Channel 3
			Pin_Init('B', 1, AF2); //Channel 4
			break;
		case 4 :
			Pin_Init('B', 6, AF2); //Channel 1
			Pin_Init('B', 7, AF2); //Channel 2
			Pin_Init('B', 8, AF2); //Channel 3
			Pin_Init('B', 9, AF2); //Channel 4
			break;
		case 5 :
			Pin_Init('A', 0, AF2); //Channel 1
			Pin_Init('A', 1, AF2); //Channel 2
			Pin_Init('A', 2, AF2); //Channel 3
			Pin_Init('A', 3, AF2); //Channel 4
			break;
	}
}


static void Activate_Clock(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 2 : 
			Clock2_5->tim2_StartTick = 1;
			break;
		case 3 : 
			Clock2_5->tim3_StartTick = 1;	
			break;
		case 4 : 
			Clock2_5->tim4_StartTick = 1;	
			break;
		case 5 : 
			Clock2_5->tim5_StartTick = 1;	
			break;
	}
}

static TIM2_5_CONTROL1* Get_TimerControlReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 2 :
			return TIMControl_2;
		case 3 :
			return TIMControl_3;
		case 4 :
			return TIMControl_4;
		case 5 :
			return TIMControl_5;
		default :
			return NULL;
	}
}

static TIM2_5_STATUS* Get_TimerStatusReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 2 :
			return TIMStatus_2;
		case 3 :
			return TIMStatus_3;
		case 4 :
			return TIMStatus_4;
		case 5 :
			return TIMStatus_5;
		default :
			return NULL;
	}
}

static TIM2_5_EVENTGEN* Get_TimerEventGenReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 2 :
			return TIMEventGen_2;
		case 3 :
			return TIMEventGen_3;
		case 4 :
			return TIMEventGen_4;
		case 5 :
			return TIMEventGen_5;
		default :
			return NULL;
	}
}

static TIM2_5_PRESCALER* Get_TimerPrescalerReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 2 :
			return TIMPrescaler_2;
		case 3 :
			return TIMPrescaler_3;
		case 4 :
			return TIMPrescaler_4;
		case 5 :
			return TIMPrescaler_5;
		default :
			return NULL;
	}
}

static TIM2_5_AUTORELOAD* Get_TimerAutoReloadReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 2 :
			return TIMAutoReld_2;
		case 3 :
			return TIMAutoReld_3;
		case 4 :
			return TIMAutoReld_4;
		case 5 :
			return TIMAutoReld_5;
		default :
			return NULL;
	}
}

static TIM2_5_COUNTER* Get_TimerCounterReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 2 :
			return TIMCount_2;
		case 3 :
			return TIMCount_3;
		case 4 :
			return TIMCount_4;
		case 5 :
			return TIMCount_5;
		default :
			return NULL;
	}
}

static TIM2_5_CAPTURECOMP_MODE1* Get_TimerCaptureCompMode1Reg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 2 :
			return TIMCaptrCompMode1_2;
		case 3 :
			return TIMCaptrCompMode1_3;
		case 4 :
			return TIMCaptrCompMode1_4;
		case 5 :
			return TIMCaptrCompMode1_5;
		default :
			return NULL;
	}
}

static TIM2_5_CAPTURECOMP_MODE2* Get_TimerCaptureCompMode2Reg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 2 :
			return TIMCaptrCompMode2_2;
		case 3 :
			return TIMCaptrCompMode2_3;
		case 4 :
			return TIMCaptrCompMode2_4;
		case 5 :
			return TIMCaptrCompMode2_5;
		default :
			return NULL;
	}
}

static TIM2_5_CAPTURECOMP_ENABLE* Get_TimerCaptureCompEnableReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 2 :
			return TIMCaptrCompEnabler_2;
		case 3 :
			return TIMCaptrCompEnabler_3;
		case 4 :
			return TIMCaptrCompEnabler_4;
		case 5 :
			return TIMCaptrCompEnabler_5;
		default :
			return NULL;
	}
}

static TIM2_5_CAPTURECOMPx* Get_TimerCaptureCompReg(uint8_t timerNum, uint8_t captCompNum) {
	
	switch (timerNum) {
		
		case 2 :
			if (captCompNum == 1) { return TIMCaptrComp1_2; }
			if (captCompNum == 2) { return TIMCaptrComp2_2; }
			if (captCompNum == 3) { return TIMCaptrComp3_2; }
			if (captCompNum == 4) { return TIMCaptrComp4_2; }
		case 3 :
			if (captCompNum == 1) { return TIMCaptrComp1_3; }
			if (captCompNum == 2) { return TIMCaptrComp2_3; }
			if (captCompNum == 3) { return TIMCaptrComp3_3; }
			if (captCompNum == 4) { return TIMCaptrComp4_3; }
		case 4 :
			if (captCompNum == 1) { return TIMCaptrComp1_4; }
			if (captCompNum == 2) { return TIMCaptrComp2_4; }
			if (captCompNum == 3) { return TIMCaptrComp3_4; }
			if (captCompNum == 4) { return TIMCaptrComp4_4; }
		case 5 :
			if (captCompNum == 1) { return TIMCaptrComp1_5; }
			if (captCompNum == 2) { return TIMCaptrComp2_5; }
			if (captCompNum == 3) { return TIMCaptrComp3_5; }
			if (captCompNum == 4) { return TIMCaptrComp4_5; }
		default :
			return NULL;
	}
}

