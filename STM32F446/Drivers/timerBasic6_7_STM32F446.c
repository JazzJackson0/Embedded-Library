#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include "timerBasic6_7_STM32F446.h"
#include "gpio_STM32F446.h"

//Static Prototypes--------------------------------------------------------------
static void Activate_Clock(uint8_t timerNum);
static TIM6_7_CONTROL1* Get_TimerControl1Reg(uint8_t timerNum);
static TIM6_7_STATUS* Get_TimerStatusReg(uint8_t timerNum);
static TIM6_7_EVENTGEN* Get_TimerEventGenReg(uint8_t timerNum);
static TIM6_7_PRESCALER* Get_TimerPrescalerReg(uint8_t timerNum);
static TIM6_7_AUTORELOAD* Get_TimerAutoReloadReg(uint8_t timerNum);
static TIM6_7_COUNTER* Get_TimerCounterReg(uint8_t timerNum);

//Global Variables------------------------------------------------------------------
TIM6_7_CLOCK *const Basic6_7Clock = ADDR_TIM6_7_CLOCK;

//TIMER 6
TIM6_7_CONTROL1 *const TIMControl1_6 = ADDR_TIM6_CONTROL1;
TIM6_7_STATUS *const TIMStatus_6 = ADDR_TIM6_STATUS;
TIM6_7_EVENTGEN *const TIMEventGen_6 = ADDR_TIM6_EVENTGEN;
TIM6_7_PRESCALER *const TIMPrescaler_6 = ADDR_TIM6_PRESCALER;
TIM6_7_AUTORELOAD *const TIMAutoReld_6 = ADDR_TIM6_AUTORELOAD;
TIM6_7_COUNTER *const TIMCount_6 = ADDR_TIM6_COUNTER;

//TIMER 7
TIM6_7_CONTROL1 *const TIMControl1_7 = ADDR_TIM7_CONTROL1;
TIM6_7_STATUS *const TIMStatus_7 = ADDR_TIM7_STATUS;
TIM6_7_EVENTGEN *const TIMEventGen_7 = ADDR_TIM7_EVENTGEN;
TIM6_7_PRESCALER *const TIMPrescaler_7 = ADDR_TIM7_PRESCALER;
TIM6_7_AUTORELOAD *const TIMAutoReld_7 = ADDR_TIM7_AUTORELOAD;
TIM6_7_COUNTER *const TIMCount_7 = ADDR_TIM7_COUNTER;


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
uint8_t BasicTimer_Start(uint8_t timerNum, uint16_t prescaler, uint16_t time) {
	
	Activate_Clock(timerNum);
	
	TIM6_7_CONTROL1 *const TIMControl1 = Get_TimerControl1Reg(timerNum);
	TIM6_7_PRESCALER *const TIMPrescaler = Get_TimerPrescalerReg(timerNum);
	TIM6_7_AUTORELOAD *const TIMAutoReld = Get_TimerAutoReloadReg(timerNum);
	TIM6_7_COUNTER *const TIMCount = Get_TimerCounterReg(timerNum);
	
	TIMPrescaler->rw_PrescalerValue = prescaler;
	TIMAutoReld->rw_AutoReloadValue = time;
	TIMCount->rw_CounterValue = 0x00;
	TIMControl1->enable_AutoReloadPreload = 1;
	TIMControl1->enable_Counter = 1;
	
	return 1;
}

uint8_t BasicOneShotTimer_Start(uint8_t timerNum, uint16_t prescaler, uint16_t time) {
	
	Activate_Clock(timerNum);
	
	TIM6_7_CONTROL1 *const TIMControl1 = Get_TimerControl1Reg(timerNum);
	TIM6_7_PRESCALER *const TIMPrescaler = Get_TimerPrescalerReg(timerNum);
	TIM6_7_AUTORELOAD *const TIMAutoReld = Get_TimerAutoReloadReg(timerNum);
	TIM6_7_COUNTER *const TIMCount = Get_TimerCounterReg(timerNum);
	
	TIMPrescaler->rw_PrescalerValue = prescaler;
	TIMAutoReld->rw_AutoReloadValue = time;
	TIMCount->rw_CounterValue = 0x00;
	TIMControl1->enable_AutoReloadPreload = 1;
	TIMControl1->enable_OnePulseMode = 1;
	TIMControl1->enable_Counter = 1;
	
	while (TIMControl1->enable_Counter == 1);
	
	return 1;
}

//Helper Functions--------------------------------------------------------------------------------------------------------------

static void Activate_Clock(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 6 : 
			Basic6_7Clock->tim6_StartTick = 1;
			break;
		case 7 : 
			Basic6_7Clock->tim7_StartTick = 1;	
			break;
	}
}

static TIM6_7_CONTROL1* Get_TimerControl1Reg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 :
			return TIMControl1_6;
		case 8 :
			return TIMControl1_7;
		default :
			return NULL;
	}
}

static TIM6_7_STATUS* Get_TimerStatusReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 :
			return TIMStatus_6;
		case 8 :
			return TIMStatus_7;
		default :
			return NULL;
	}
}

static TIM6_7_EVENTGEN* Get_TimerEventGenReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 :
			return TIMEventGen_6;
		case 8 :
			return TIMEventGen_7;
		default :
			return NULL;
	}
}

static TIM6_7_PRESCALER* Get_TimerPrescalerReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 :
			return TIMPrescaler_6;
		case 8 :
			return TIMPrescaler_7;
		default :
			return NULL;
	}
}

static TIM6_7_AUTORELOAD* Get_TimerAutoReloadReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 :
			return TIMAutoReld_6;
		case 8 :
			return TIMAutoReld_7;
		default :
			return NULL;
	}
}

static TIM6_7_COUNTER* Get_TimerCounterReg(uint8_t timerNum) {
	
	switch (timerNum) {
		
		case 1 :
			return TIMCount_6;
		case 8 :
			return TIMCount_7;
		default :
			return NULL;
	}
}