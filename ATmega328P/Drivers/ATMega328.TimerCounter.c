#include "ATmega328.TimerCounter.h"

//Static Prototypes-----------------------------------------------------------------
static TIMER0_2* Get_Timer0_2(uint8_t timerID);

//Global Variables------------------------------------------------------------------
//TIMER
POWER_REDUCTION_TIM *const TimPower = ADDR_POWER_REDUCTION_TIM;
GENERAL_TIM_CONTROL *const GeneralControl = ADDR_GENERAL_TIM_CONTROL;
TIMER0_2 *const TIM0 = ADDR_TIM0;
TIMER1 *const TIM1 = ADDR_TIM1;
TIMER0_2 *const TIM2 = ADDR_TIM2;
INT_MASK *const TIM_INT_MASK = ADDR_INT_MASK;
INT_FLAG *const TIM_INT_FLAG = ADDR_INT_FLAG;


void Timer_Start(uint8_t timerID, E_ClockSpeed clockSpeed, uint16_t time) {
	
	if (timerID == 1) {
		TIMER1 *const TIMER = TIM1;
		TimPower->tim0On0_tim0Off1 = 0;	
		TIMER->CounterValueLowReg.rw_CounterValue = 0;
		TIMER->CounterValueHighReg.rw_CounterValue = 0;
		
		//Timer Start Sequence
		TIMER->ControlBReg.select_ClockSource = clockSpeed;

		TIMER->OutputCompareALowReg.rw_OutputCompAValue = time;
		TIMER->OutputCompareAHighReg.rw_OutputCompAValue = time >> 8;
		TIMER->ControlAReg.rw_ChannelAOutputCompareMode = NORMAL;// No Output
		
		//Start Timer
		GeneralControl->reset_Tim0AndTim1Prescaler = 1;
	}
	
	else {
		TIMER0_2 *const TIMER = Get_Timer0_2(timerID);
		TimPower->tim0On0_tim0Off1 = 0;	
		TIMER->CounterValueReg.rw_CounterValue = 0;
		
		//Timer Start Sequence
		TIMER->ControlBReg.select_ClockSource = clockSpeed;
		TIMER->OutputCompareAReg.rw_OutputCompareValue = time;
		TIMER->ControlAReg.rw_ChannelAOutputCompareMode = NORMAL;// No Output
		
		//Start Timer
		if (timerID == 2) { GeneralControl->reset_Tim2Prescaler = 1; }
		else { GeneralControl->reset_Tim0AndTim1Prescaler = 1; }
	}
}

uint8_t OneShotTimer_Start(uint8_t timerID, E_ClockSpeed clockSpeed, uint16_t time) {
	
	INT_MASK *const MASK = TIM_INT_MASK;
	INT_FLAG *const FLAG = TIM_INT_FLAG;

	if (timerID == 1) { 
		TIMER1 *const TIMER = TIM1;
		TimPower->tim0On0_tim0Off1 = 0;	
		MASK->Tim1InterruptMaskReg.enable_OverflowInterrupt = 1;
		Timer_Start(timerID, clockSpeed, time);

		while (FLAG->Tim1InterruptFlagsReg.overflowInterruptOccurred != 1);
		return 1;		
	}
	
	else {
		TIMER0_2 *const TIMER = Get_Timer0_2(timerID);
		
		TimPower->tim0On0_tim0Off1 = 0;	
		switch (timerID) {
			case 0:
				MASK->Tim0InterruptMaskReg.enable_OverflowInterrupt = 1;
				break;
			case 2:
				MASK->Tim2InterruptMaskReg.enable_OverflowInterrupt = 1;
				break;
		}
		Timer_Start(timerID, clockSpeed, time);

		switch (timerID) {
			case 0:
				while (FLAG->Tim0InterruptFlagsReg.overflowInterruptOccurred != 1);
				return 1;
			case 2:
				while (FLAG->Tim2InterruptFlagsReg.overflowInterruptOccurred != 1);
				return 1;
		}
	}
}


void PWM_Start(uint8_t timerID, E_ClockSpeed clockSpeed, uint16_t time, float dutyCyclePercent) {
	
	if ( dutyCyclePercent > 100.0 ) { dutyCyclePercent = 100.0; }
	if ( dutyCyclePercent < 0.0 ) { dutyCyclePercent = 0.0; }

	if (timerID == 1) {
		TIMER1 *const TIMER = TIM1;
		TimPower->tim0On0_tim0Off1 = 0;
		
		TIMER->CounterValueLowReg.rw_CounterValue = 0;
		TIMER->CounterValueHighReg.rw_CounterValue = 0;
		TIMER->ControlAReg.rw_ChannelBOutputCompareMode = HIGH_AT_START_LOW_ON_MATCH;
		TIMER->ControlAReg.rw_WaveFormGenerationModePart1 = P1_FAST_PWM_MAXVAL_IS_OUTCOMPVAL_A;
		TIMER->ControlBReg.rw_WaveFormGenerationModePart2 = P2_FAST_PWM_MAXVAL_IS_OUTCOMPVAL_A;
		
		TIMER->ControlBReg.select_ClockSource = clockSpeed;
		TIMER->OutputCompareALowReg.rw_OutputCompAValue = time;
		TIMER->OutputCompareAHighReg.rw_OutputCompAValue = time >> 8;
		TIMER->OutputCompareBLowReg.rw_OutputCompBValue = (uint16_t) ((dutyCyclePercent / 100) * time);
		TIMER->OutputCompareBHighReg.rw_OutputCompBValue = (uint16_t) ((dutyCyclePercent / 100) * time) >> 8;
		
		//Start Timer
		GeneralControl->reset_Tim0AndTim1Prescaler = 1;
	}
	
	else {
		TIMER0_2 *const TIMER = Get_Timer0_2(timerID);
		TIMER->CounterValueReg.rw_CounterValue = 0;
		TimPower->tim0On0_tim0Off1 = 0;
		
		TIMER->ControlAReg.rw_ChannelBOutputCompareMode = HIGH_AT_START_LOW_ON_MATCH;
		TIMER->ControlAReg.rw_WaveFormGenerationModePart1 = P1_FAST_PWM_MAXVAL_IS_OUTCOMPVAL_A;
		TIMER->ControlBReg.rw_WaveFormGenerationModePart2 = P2_FAST_PWM_MAXVAL_IS_OUTCOMPVAL_A;
		
		TIMER->ControlBReg.select_ClockSource = clockSpeed;
		TIMER->OutputCompareAReg.rw_OutputCompareValue = time;
		TIMER->OutputCompareBReg.rw_OutputCompareValue = ((dutyCyclePercent / 100) * time);
		
		//Start Timer
		if (timerID == 2) { GeneralControl->reset_Tim2Prescaler = 1; }
		else { GeneralControl->reset_Tim0AndTim1Prescaler = 1; }
	}
}


void PWM_Update(uint8_t timerID, uint16_t time, float dutyCyclePercent) {

	if ( dutyCyclePercent > 100.0 ) { dutyCyclePercent = 100.0; }
	if ( dutyCyclePercent < 0.0 ) { dutyCyclePercent = 0.0; }

	if (timerID == 1) { 
		TIMER1 *const TIMER = TIM1;
		TIMER->OutputCompareBLowReg.rw_OutputCompBValue = (uint16_t) ((dutyCyclePercent / 100) * time);
		TIMER->OutputCompareBHighReg.rw_OutputCompBValue = (uint16_t) ((dutyCyclePercent / 100) * time) >> 8;
		
		//Start Timer
		GeneralControl->reset_Tim0AndTim1Prescaler = 1;
	}
	
	else {
		TIMER0_2 *const TIMER = Get_Timer0_2(timerID);
		TIMER->OutputCompareBReg.rw_OutputCompareValue = ((dutyCyclePercent / 100) * time);
		
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
		TIMER1 *const TIMER = TIM1;
		TIMER->ControlCReg.forceOutputCompareA = 1;
		return (uint16_t) (TIMER->CounterValueHighReg.rw_CounterValue << 8) 
			| TIMER->CounterValueLowReg.rw_CounterValue;
	}
	
	else {
		TIMER0_2 *const TIMER = Get_Timer0_2(timerID);
		TIMER->ControlBReg.forceOutputCompareA = 1;
		return (uint16_t) TIMER->CounterValueReg.rw_CounterValue;
	}
}



//Helper Functions-------------------------------------------------------------------------------------------------------------

static TIMER0_2* Get_Timer0_2(uint8_t timerID) {
	
	switch (timerID) {
		
		case 0 :
			return TIM0;
		case 2 :
			return TIM2;
		default :
			return ((void*)0);
	}
}