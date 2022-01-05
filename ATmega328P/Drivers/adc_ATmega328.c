#include <stdint.h>
#include <stdio.h>
#include "adc_ATmega328.h"


//Global Variables-------------------------------------------------------
//ADC
POWER_REDUCTION_ADC *const adcPower = ADDR_POWER_REDUCTION_ADC;
ADC_MUTEX_SELECT *const adcMutex = ADDR_ADC_MUTEX_SELECT;
ADC_CONTROL_STATUS_A *const controlStatA = ADDR_ADC_CONTROL_STATUS_A;
ADC_DATA_LOW_RIGHT *const datLowR = ADDR_ADC_DATA_LOW_RIGHT;
ADC_DATA_HIGH_RIGHT *const datHighR = ADDR_ADC_DATA_HIGH_RIGHT;
ADC_CONTROL_STATUS_B *const controlStatB = ADDR_ADC_CONTROL_STATUS_B;
ADC_DIGITAL_INPUT_DISABLE *const disableDigitIn = ADDR_ADC_DIGITAL_INPUT_DISABLE;

/**
- Arduino Uno Clock Speed
		+ATmega defaults to 8MHz RC Prescaled to 1MHz
		+Arduino Uno Board overrides ATmega and defaults to 16MHz external xtal oscillator 
**/
void ADC_Init_and_Start(E_Channel channel, E_ADCClockDivide clockDivide, E_AutoTrigSrc autoTrigSrc) {
	
	adcPower->adcOn0_adcOff1 = 0;
	
	adcMutex->rw_AnalogChannel = channel;
	adcMutex->rightAdjustedADCResult0_leftAdjustedADCResult1 = 0;
	controlStatA->rw_PrescalerValue = clockDivide;
	
	controlStatA->enable_ADC = 1;
	
	controlStatB->rw_AutoTriggerSource = autoTrigSrc;
	controlStatA->enable_ADCAutoTrigger = 1;
	
	controlStatA->start_ADCConversion = 1; //Starts the first conversion in Free Run Mode
}

int16_t ADC_Read(void) {
	
	while (controlStatA->start_ADCConversion == 1);
	uint8_t low = datLowR->read_ADCConversionResultLow;
	uint8_t high = datHighR->read_ADCConversionResultHigh;
	
	return (uint16_t) high | low; //Test this type of return
}

