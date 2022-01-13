#include <stdint.h>
//#include <stdio.h>
#include "adc_MSP430FR.h"
#include "digital_io_MSP430FR.h"

//Static Prototypes----------------------------------------------------
static void ADC_PinInit(void);

//Global Variables-------------------------------------------------------
//ADC
ADCx *const ADC_x = ADDR_ADC;
MEM_CTRL_ACCESSx *const MEM_CTRL_x = ADDR_MEM_CTRL;
MEM_ACCESSx *const MEM_x = ADDR_MEM;


/**
- CLOCK SPEED: According to '3.2 Clock System Operation'
		+ MCLK & SMCLK = DCOCLK
		+ Then they are divided by 8
		+-----------------------------
		+ DCOCLK = 1MHz
		+ SMCLK & MCLK = 1 MHz / 8
		+ SMCLK & MCLK = 125KHz
**/
void ADC_SetClockSpeed(E_ADCClockSource clockSource, E_ClockDivider clockDivide, E_ADCPreDivider preDivide) {
	
	ADCx *const ADC = ADC_x;
	
	ADC->ControlReg1.select_ClockSource = clockSource;
	ADC->ControlReg1.rw_ClockDivider = clockDivide;
	ADC->ControlReg1.rw_ADCClockPreDivider = preDivide;
}


void ADC_ConversionChannelSetup(E_ConversionChannel conversionChannel, E_DiffSignal_ConvChannel diffSigChannel, E_ConversionMemory memAddress) {
	
	uint8_t x = memAddress;
	ADCx *const ADC = ADC_x;
	MEM_CTRL_ACCESSx *const MEM_CTRL = MEM_CTRL_x;
	
	if (conversionChannel == NONE) { MEM_CTRL->RegisterAccess[x].rw_InputChannel = diffSigChannel; }
	
	else if (diffSigChannel == NONE) { MEM_CTRL->RegisterAccess[x].rw_InputChannel = conversionChannel; }
	
	ADC->ControlReg3.rw_ConversionStartAddress = memAddress;
}


void ADC_Init(E_DataFormat dataFormat, E_Resolution resolution, E_SamplePeriod cycles, E_ConversionNum numOfConversions, E_ConversionMemory memAddress) {
	
	uint8_t x = memAddress;
	ADCx *const ADC = ADC_x;
	MEM_CTRL_ACCESSx *const MEM_CTRL = MEM_CTRL_x;
	
	ADC->ControlReg2.unsignedBinaryDataFormat0_signedBinaryDataFormat1 = dataFormat;
	ADC->ControlReg2.rw_Resolution = resolution;
	
	ADC->ControlReg0.sampleOnRiseEdge0_sampleOnRiseEdgeThenAuto1 = numOfConversions;
	ADC->ControlReg0.rw_ADCSamplePeriodLengthReg0To7 = cycles;
	
	MEM_CTRL->RegisterAccess[x].rw_MaxAndMinVoltageMeasureThresholds = MAX_AVCC_MIN_AVSS;
	
	ADC_PinInit();
	ADC->ControlReg0.enable_ADC = 1;
	ADC->ControlReg0.enable_ADCConversion = 1;
}

int16_t ADC_Read(E_ConversionMemory memAddress) {
	
	uint8_t x = memAddress;
	ADCx *const ADC = ADC_x;
	MEM_CTRL_ACCESSx *const MEM_CTRL = MEM_CTRL_x;
	MEM_ACCESSx *const MEM = MEM_x;

	if (memAddress )
	ADC->ControlReg0.start_SampleAndConversion = 1;

	while (ADC->ControlReg1.sequenceSampleOrConversionActive == 1 
		&& MEM_CTRL->RegisterAccess[x].endOfSequence != 1);
	return MEM->RegisterAccess[x].rw_bitConversionResults;
}

//Helper Functions--------------------------------------------------------------------------------------------------------

/**
ADC Pins -------------------------------
		+ ADC External Negative Ref Voltage: P1-0 	[(Tertiary Function)]
		+ ADC External Positive Ref Voltage: P1-1 	[(Tertiary Function)]
		+ ADC A0 Analog Input: P1-0 				[(Tertiary Function)]
		+ ADC A1 Analog Input: P1-1 				[(Tertiary Function)]
		+ ADC A2 Analog Input: P1-2 				[(Tertiary Function)]
		+ ADC A3 Analog Input: P1-3 				[(Tertiary Function)]
		+ ADC A4 Analog Input: P1-4 				[(Tertiary Function)]
		+ ADC A5 Analog Input: P1-5 				[(Tertiary Function)]
		+ ADC A6 Analog Input: P2-3 				[(Tertiary Function)]
		+ ADC A7 Analog Input: P2-4 				[(Tertiary Function)]
		+ ADC A8 Analog Input: P4-0 				[(Tertiary Function)]
		+ ADC A9 Analog Input: P4-1 				[(Tertiary Function)]
		+ ADC A10 Analog Input: P4-2 				[(Tertiary Function)]
		+ ADC A11 Analog Input: P4-3 				[(Tertiary Function)]
		+ ADC A12 Analog Input: P3-0 				[(Tertiary Function)]
		+ ADC A13 Analog Input: P3-1 				[(Tertiary Function)]
		+ ADC A14 Analog Input: P3-2 				[(Tertiary Function)]
		+ ADC A15 Analog Input: P3-3 				[(Tertiary Function)]
		------------------------------------
**/
static void ADC_PinInit(void) {

	Pin_Init('4', 2, NONE, TERTIARY_F, NO_PULL);
}