#include "ATmega328.ADC.h"


//Global Variables-------------------------------------------------------
//ADC
POWER_REDUCTION_ADC *const ADCPower = ADDR_POWER_REDUCTION_ADC;
ADCx *const ADC = ADDR_ADC;


void ADC_Init(E_Channel channel, E_ADCClockDivide clockDivide, E_AutoTrigSrc autoTrigSrc) {
	
	ADCPower->adcOn0_adcOff1 = 0;
	
	ADC->MutexSelectReg.rw_AnalogChannel = channel;
	ADC->MutexSelectReg.rightAdjustedADCResult0_leftAdjustedADCResult1 = 0;
	ADC->ControlStatusAReg.rw_PrescalerValue = clockDivide;
	
	ADC->ControlStatusAReg.enable_ADC = 1;
	
	ADC->ControlStatusBReg.rw_AutoTriggerSource = autoTrigSrc;
	ADC->ControlStatusAReg.enable_ADCAutoTrigger = 1;
	
	//ADC->ControlStatusAReg.start_ADCConversion = 1; //Starts the first conversion in Free Run Mode
}

int16_t ADC_Read(void) {
	
	ADC->ControlStatusAReg.start_ADCConversion = 1;
	while (ADC->ControlStatusAReg.start_ADCConversion == 1);
	uint8_t low = ADC->DataLowReg.RightAdjust.read_ADCConversionResult;
	uint8_t high = ADC->DataHighReg.RightAdjust.read_ADCConversionResult;
	
	return (uint16_t) high | low; //Test this type of return
}

