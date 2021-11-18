#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include "timer_counter_ATmega328.h"
#include "io_ports_ATmega328.h"

//Static Prototypes-----------------------------------------------------------------
static TIMx_CONTROLA* Get_ControlA(uint8_t timerID);
static TIM0_2_CONTROLB* Get_0_2ControlB(uint8_t timerID);
static TIM0_2_COUNTERVALUE* Get_0_2TimCountVal(uint8_t timerID);
static TIM0_2_OUTPUTCOMPARE_A* Get_0_2OutCompA(uint8_t timerID);
static TIM0_2_OUTPUTCOMPARE_B* Get_0_2OutCompB(uint8_t timerID);
static TIM0_2_INTERRUPT_FLAGS* Get_0_2InteruptFlags(uint8_t timerID);
static TIM0_2_INTERRUPT_MASK* Get_0_2InteruptMask(uint8_t timerID);

//Global Variables------------------------------------------------------------------
//TIMER 0
POWER_REDUCTION_TIM *const TimPower = ADDR_POWER_REDUCTION_TIM;
GENERAL_TIM_CONTROL *const GeneralControl = ADDR_GENERAL_TIM_CONTROL;

TIMx_CONTROLA *const ControlA_0 = ADDR_TIM0_CONTROLA;
TIM0_2_CONTROLB *const ControlB_0 = ADDR_TIM0_CONTROLB;
TIM0_2_COUNTERVALUE *const TimCountVal_0 = ADDR_TIM0_COUNTERVALUE;
TIM0_2_OUTPUTCOMPARE_A *const OutCompA_0 = ADDR_TIM0_OUTPUTCOMPARE_A;
TIM0_2_OUTPUTCOMPARE_B *const OutCompB_0 = ADDR_TIM0_OUTPUTCOMPARE_B;
TIM0_2_INTERRUPT_FLAGS *const InterruptFlags_0 = ADDR_TIM0_INTERRUPT_FLAGS;
TIM0_2_INTERRUPT_MASK *const InterruptMask_0 = ADDR_TIM0_INTERRUPT_MASK;

//TIMER 1
TIMx_CONTROLA *const ControlA_1 = ADDR_TIM1_CONTROLA;
TIM1_CONTROLB *const ControlB_1 = ADDR_TIM1_CONTROLB;
TIM1_CONTROLC *const ControlC_1 = ADDR_TIM1_CONTROLC;
TIM1_COUNTERVALUE_LOW *const TimCountValLow_1 = ADDR_TIM1_COUNTERVALUE_LOW;
TIM1_COUNTERVALUE_HIGH *const TimCountValHigh_1 = ADDR_TIM1_COUNTERVALUE_HIGH;
TIM1_OUTPUTCOMPARE_A_LOW *const OutCompALow_1 = ADDR_TIM1_OUTPUTCOMPARE_A_LOW;
TIM1_OUTPUTCOMPARE_A_HIGH *const OutCompAHigh_1 = ADDR_TIM1_OUTPUTCOMPARE_A_HIGH;
TIM1_OUTPUTCOMPARE_B_LOW *const OutCompBLow_1 = ADDR_TIM1_OUTPUTCOMPARE_B_LOW;
TIM1_OUTPUTCOMPARE_B_HIGH *const OutCompBHigh_1 = ADDR_TIM1_OUTPUTCOMPARE_B_HIGH;
TIM1_INTERRUPT_FLAGS *const InterruptFlags_1 = ADDR_TIM1_INTERRUPT_FLAGS;
TIM1_INTERRUPT_MASK *const InterruptMask_1 = ADDR_TIM1_INTERRUPT_MASK;

//TIMER 2
TIMx_CONTROLA *const ControlA_2 = ADDR_TIM2_CONTROLA;
TIM0_2_CONTROLB *const ControlB_2 = ADDR_TIM2_CONTROLB;
TIM0_2_COUNTERVALUE *const TimCountVal_2 = ADDR_TIM2_COUNTERVALUE;
TIM0_2_OUTPUTCOMPARE_A *const OutCompA_2 = ADDR_TIM2_OUTPUTCOMPARE_A;
TIM0_2_OUTPUTCOMPARE_B *const OutCompB_2 = ADDR_TIM2_OUTPUTCOMPARE_B;
TIM0_2_INTERRUPT_FLAGS *const InterruptFlags_2 = ADDR_TIM2_INTERRUPT_FLAGS;
TIM0_2_INTERRUPT_MASK *const InterruptMask_2 = ADDR_TIM2_INTERRUPT_MASK;


void Timer_Start(uint8_t timerID, E_ClockSpeed clockSpeed, uint16_t time) {
	
	if (timerID == 1) {
		
		TimPower->tim0On0_tim0Off1 = 0;	
		TimCountValLow_1->rw_CounterValueLowByte = 0;
		TimCountValHigh_1->rw_CounterValueHighByte = 0;
		
		//Timer Start Sequence
		ControlB_1->select_ClockSource = clockSpeed;

		OutCompALow_1->rw_OutputCompAValueLowByte = time;
		OutCompAHigh_1->rw_OutputCompAValueHighByte = time >> 8;
		ControlA_1->rw_ChannelAOutputCompareMode = NORMAL;// No Output
		
		//Start Timer
		GeneralControl->reset_Tim0AndTim1Prescaler = 1;
	}
	
	else {
		
		TIM0_2_CONTROLB *const ControlB = Get_0_2ControlB(timerID);
		TIM0_2_COUNTERVALUE *const TimCountVal = Get_0_2TimCountVal(timerID);
		TIM0_2_OUTPUTCOMPARE_A *const OutCompA = Get_0_2OutCompA(timerID);
		TIM0_2_OUTPUTCOMPARE_B *const OutCompB = Get_0_2OutCompB(timerID);
		TIMx_CONTROLA *const ControlA = Get_ControlA(timerID);
		
		TimPower->tim0On0_tim0Off1 = 0;	
		TimCountVal->rw_CounterValue = 0;
		
		//Timer Start Sequence
		ControlB->select_ClockSource = clockSpeed;
		OutCompA->rw_OutputCompareRegAValue = time;
		ControlA->rw_ChannelAOutputCompareMode = NORMAL;// No Output
		
		//Start Timer
		if (timerID == 2) { GeneralControl->reset_Tim2Prescaler = 1; }
		else { GeneralControl->reset_Tim0AndTim1Prescaler = 1; }
	}
}

uint8_t OneShotTimer_Start(uint8_t timerID, E_ClockSpeed clockSpeed, uint16_t time) {
	
	if (timerID == 1) { 

		TimPower->tim0On0_tim0Off1 = 0;	
		InterruptMask_1->enable_OverflowInterrupt = 1;
		Timer_Start(timerID, clockSpeed, time);

		while (InterruptFlags_1->overflowInterruptOccurred != 1);
		return 1;		
	}
	
	else {
		
		TIM0_2_INTERRUPT_FLAGS *const InterruptFlags = Get_0_2InteruptFlags(timerID); 
		TIM0_2_INTERRUPT_MASK *const InterruptMask = Get_0_2InteruptMask(timerID);
		
		TimPower->tim0On0_tim0Off1 = 0;	
		InterruptMask->enable_OverflowInterrupt = 1;
		Timer_Start(timerID, clockSpeed, time);

		while (InterruptFlags->overflowInterruptOccurred != 1);
		return 1;
	}
}


void PWM_Init(uint8_t timerID, E_ClockSpeed clockSpeed, uint16_t time, float dutyCycle) {
	

	if (timerID == 1) {
		
		TimPower->tim0On0_tim0Off1 = 0;
		
		TimCountValLow_1->rw_CounterValueLowByte = 0;
		TimCountValHigh_1->rw_CounterValueHighByte = 0;
		ControlA_1->rw_ChannelBOutputCompareMode = HIGH_AT_START_LOW_ON_MATCH;
		ControlA_1->rw_WaveFormGenerationModePart1 = P1_FAST_PWM_MAXVAL_IS_OUTCOMPVAL_A;
		ControlB_1->rw_WaveFormGenerationModePart2 = P2_FAST_PWM_MAXVAL_IS_OUTCOMPVAL_A;
		
		ControlB_1->select_ClockSource = clockSpeed;
		OutCompALow_1->rw_OutputCompAValueLowByte = time;
		OutCompAHigh_1->rw_OutputCompAValueHighByte = time >> 8;
		OutCompBLow_1->rw_OutputCompBValueLowByte = (uint16_t) (dutyCycle * time);
		OutCompBHigh_1->rw_OutputCompBValueHighByte = (uint16_t) (dutyCycle * time) >> 8;
		
		//Start Timer
		GeneralControl->reset_Tim0AndTim1Prescaler = 1;
	}
	
	else {
		
		TIM0_2_CONTROLB *const ControlB = Get_0_2ControlB(timerID);
		TIM0_2_COUNTERVALUE *const TimCountVal = Get_0_2TimCountVal(timerID);
		TIM0_2_OUTPUTCOMPARE_A *const OutCompA = Get_0_2OutCompA(timerID);
		TIM0_2_OUTPUTCOMPARE_B *const OutCompB = Get_0_2OutCompB(timerID);
		TimCountVal->rw_CounterValue = 0;
		
		
		TIMx_CONTROLA *const ControlA = Get_ControlA(timerID);
		TimPower->tim0On0_tim0Off1 = 0;
		
		ControlA->rw_ChannelBOutputCompareMode = HIGH_AT_START_LOW_ON_MATCH;
		ControlA->rw_WaveFormGenerationModePart1 = P1_FAST_PWM_MAXVAL_IS_OUTCOMPVAL_A;
		ControlB->rw_WaveFormGenerationModePart2 = P2_FAST_PWM_MAXVAL_IS_OUTCOMPVAL_A;
		
		ControlB->select_ClockSource = clockSpeed;
		OutCompA->rw_OutputCompareRegAValue = time;
		OutCompB->rw_OutputCompareRegBValue = (dutyCycle * time);
		
		//Start Timer
		if (timerID == 2) { GeneralControl->reset_Tim2Prescaler = 1; }
		else { GeneralControl->reset_Tim0AndTim1Prescaler = 1; }
	}
}


void PWM_Update(uint8_t timerID, uint16_t time, float dutyCycle) {

	if (timerID == 1) { 
	
		OutCompBLow_1->rw_OutputCompBValueLowByte = (uint16_t) (dutyCycle * time);
		OutCompBHigh_1->rw_OutputCompBValueHighByte = (uint16_t) (dutyCycle * time) >> 8;
		
		//Start Timer
		GeneralControl->reset_Tim0AndTim1Prescaler = 1;
	}
	
	else {
		
		TIM0_2_OUTPUTCOMPARE_B *const OutCompB = Get_0_2OutCompB(timerID);
	
		OutCompB->rw_OutputCompareRegBValue = (dutyCycle * time);
		
		//Start Timer
		if (timerID == 2) { GeneralControl->reset_Tim2Prescaler = 1; }
		else { GeneralControl->reset_Tim0AndTim1Prescaler = 1; }
	}
}

/**
Stops the Timer and returns the current time value.
**/
uint16_t Stop_Timer(uint8_t timerID) {
	
	if (timerID == 1) {
		
		ControlC_1->forceOutputCompareA = 1;
		return (uint16_t) (TimCountValHigh_1->rw_CounterValueHighByte << 8)| TimCountValLow_1->rw_CounterValueLowByte;
	}
	
	else {
		
		TIM0_2_CONTROLB *const ControlB = Get_0_2ControlB(timerID);
		TIM0_2_COUNTERVALUE *const TimCountVal = Get_0_2TimCountVal(timerID);
		
		ControlB->forceOutputCompareA = 1;
		return (uint16_t) TimCountVal->rw_CounterValue;
	}
}



//Helper Functions-------------------------------------------------------------------------------------------------------------

static TIMx_CONTROLA* Get_ControlA(uint8_t timerID) {
	
	switch (timerID) {
		
		case 0 :
			return ControlA_0;
		case 1 :
			return ControlA_1;
		case 2 :
			return ControlA_2;
		default :
			return NULL;
	}
}


static TIM0_2_CONTROLB* Get_0_2ControlB(uint8_t timerID) {
	
	switch (timerID) {
		
		case 0 :
			return ControlB_0;
		case 2 :
			return ControlB_2;
		default :
			return NULL;
	}
}

static TIM0_2_COUNTERVALUE* Get_0_2TimCountVal(uint8_t timerID) {
	
	switch (timerID) {
		
		case 0 :
			return TimCountVal_0;
		case 2 :
			return TimCountVal_2;
		default :
			return NULL;
	}
}

static TIM0_2_OUTPUTCOMPARE_A* Get_0_2OutCompA(uint8_t timerID) {
	
	switch (timerID) {
		
		case 0 :
			return OutCompA_0;
		case 2 :
			return OutCompA_2;
		default :
			return NULL;
	}
}

static TIM0_2_OUTPUTCOMPARE_B* Get_0_2OutCompB(uint8_t timerID) {
	
	switch (timerID) {
		
		case 0 :
			return OutCompB_0;
		case 2 :
			return OutCompB_2;
		default :
			return NULL;
	}
}

static TIM0_2_INTERRUPT_FLAGS* Get_0_2InteruptFlags(uint8_t timerID) {
	
	switch (timerID) {
		
		case 0 :
			return InterruptFlags_0;
		case 2 :
			return InterruptFlags_2;
		default :
			return NULL;
	}
}

static TIM0_2_INTERRUPT_MASK* Get_0_2InteruptMask(uint8_t timerID) {
	
	switch (timerID) {
		
		case 0 :
			return InterruptMask_0;
		case 2 :
			return InterruptMask_2;
		default :
			return NULL;
	}
}