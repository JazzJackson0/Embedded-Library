#include <stdint.h>
#include <stddef.h>
//#include <stdio.h>
#include "adc_MSP430FR.h"
#include "digital_io_MSP430FR.h"

//Static Prototypes----------------------------------------------------
static void ADC_PinInit(void);
static ADC_CONVERSION_MEMORY_CONTROLx* Get_ConversionMemoryControlReg(E_ConversionMemory memAddress);
static ADC_CONVERSION_MEMORYx* Get_ConversionMemoryReg(E_ConversionMemory memAddress);

//Global Variables-------------------------------------------------------
//ADC
ADC_CONTROL0 *const ADCControl0 = ADDR_ADC_CONTROL0;
ADC_CONTROL1 *const ADCControl1 = ADDR_ADC_CONTROL1;
ADC_CONTROL2 *const ADCControl2 = ADDR_ADC_CONTROL2;
ADC_CONTROL3 *const ADCControl3 = ADDR_ADC_CONTROL3;
ADC_WINDOW_COMPARATOR_HIGH_THRESHOLD *const ADCWinCompHigh = ADDR_ADC_WINDOW_COMPARATOR_HIGH_THRESHOLD;
ADC_WINDOW_COMPARATOR_LOW_THRESHOLD *const ADCWinCompLow = ADDR_ADC_WINDOW_COMPARATOR_LOW_THRESHOLD;

ADC_CONVERSION_MEMORYx *const ADCConvertMem_0 = ADDR_ADC_CONVERSION_MEMORY0;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_1 = ADDR_ADC_CONVERSION_MEMORY1;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_2 = ADDR_ADC_CONVERSION_MEMORY2;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_3 = ADDR_ADC_CONVERSION_MEMORY3;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_4 = ADDR_ADC_CONVERSION_MEMORY4;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_5 = ADDR_ADC_CONVERSION_MEMORY5;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_6 = ADDR_ADC_CONVERSION_MEMORY6;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_7 = ADDR_ADC_CONVERSION_MEMORY7;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_8 = ADDR_ADC_CONVERSION_MEMORY8;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_9 = ADDR_ADC_CONVERSION_MEMORY9;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_10 = ADDR_ADC_CONVERSION_MEMORY10;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_11 = ADDR_ADC_CONVERSION_MEMORY11;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_12 = ADDR_ADC_CONVERSION_MEMORY12;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_13 = ADDR_ADC_CONVERSION_MEMORY13;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_14 = ADDR_ADC_CONVERSION_MEMORY14;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_15 = ADDR_ADC_CONVERSION_MEMORY15;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_16 = ADDR_ADC_CONVERSION_MEMORY16;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_17 = ADDR_ADC_CONVERSION_MEMORY17;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_18 = ADDR_ADC_CONVERSION_MEMORY18;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_19 = ADDR_ADC_CONVERSION_MEMORY19;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_20 = ADDR_ADC_CONVERSION_MEMORY20;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_21 = ADDR_ADC_CONVERSION_MEMORY21;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_22 = ADDR_ADC_CONVERSION_MEMORY22;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_23 = ADDR_ADC_CONVERSION_MEMORY23;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_24 = ADDR_ADC_CONVERSION_MEMORY24;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_25 = ADDR_ADC_CONVERSION_MEMORY25;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_26 = ADDR_ADC_CONVERSION_MEMORY26;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_27 = ADDR_ADC_CONVERSION_MEMORY27;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_28 = ADDR_ADC_CONVERSION_MEMORY28;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_29 = ADDR_ADC_CONVERSION_MEMORY29;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_30 = ADDR_ADC_CONVERSION_MEMORY30;
ADC_CONVERSION_MEMORYx *const ADCConvertMem_31 = ADDR_ADC_CONVERSION_MEMORY31;


ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_0 = ADDR_ADC_CONVERSION_MEMORY_CONTROL0;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_1 = ADDR_ADC_CONVERSION_MEMORY_CONTROL1;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_2 = ADDR_ADC_CONVERSION_MEMORY_CONTROL2;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_3 = ADDR_ADC_CONVERSION_MEMORY_CONTROL3;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_4 = ADDR_ADC_CONVERSION_MEMORY_CONTROL4;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_5 = ADDR_ADC_CONVERSION_MEMORY_CONTROL5;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_6 = ADDR_ADC_CONVERSION_MEMORY_CONTROL6;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_7 = ADDR_ADC_CONVERSION_MEMORY_CONTROL7;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_8 = ADDR_ADC_CONVERSION_MEMORY_CONTROL8;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_9 = ADDR_ADC_CONVERSION_MEMORY_CONTROL9;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_10 = ADDR_ADC_CONVERSION_MEMORY_CONTROL10;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_11 = ADDR_ADC_CONVERSION_MEMORY_CONTROL11;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_12 = ADDR_ADC_CONVERSION_MEMORY_CONTROL12;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_13 = ADDR_ADC_CONVERSION_MEMORY_CONTROL13;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_14 = ADDR_ADC_CONVERSION_MEMORY_CONTROL14;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_15 = ADDR_ADC_CONVERSION_MEMORY_CONTROL15;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_16 = ADDR_ADC_CONVERSION_MEMORY_CONTROL16;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_17 = ADDR_ADC_CONVERSION_MEMORY_CONTROL17;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_18 = ADDR_ADC_CONVERSION_MEMORY_CONTROL18;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_19 = ADDR_ADC_CONVERSION_MEMORY_CONTROL19;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_20 = ADDR_ADC_CONVERSION_MEMORY_CONTROL20;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_21 = ADDR_ADC_CONVERSION_MEMORY_CONTROL21;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_22 = ADDR_ADC_CONVERSION_MEMORY_CONTROL22;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_23 = ADDR_ADC_CONVERSION_MEMORY_CONTROL23;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_24 = ADDR_ADC_CONVERSION_MEMORY_CONTROL24;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_25 = ADDR_ADC_CONVERSION_MEMORY_CONTROL25;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_26 = ADDR_ADC_CONVERSION_MEMORY_CONTROL26;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_27 = ADDR_ADC_CONVERSION_MEMORY_CONTROL27;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_28 = ADDR_ADC_CONVERSION_MEMORY_CONTROL28;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_29 = ADDR_ADC_CONVERSION_MEMORY_CONTROL29;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_30 = ADDR_ADC_CONVERSION_MEMORY_CONTROL30;
ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl_31 = ADDR_ADC_CONVERSION_MEMORY_CONTROL31;
	
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
	
	ADCControl1->select_ClockSource = clockSource;
	ADCControl1->rw_ClockDivider = clockDivide;
	ADCControl1->rw_ADCClockPreDivider = preDivide;
}


void ADC_ConversionChannelSetup(E_ConversionChannel conversionChannel, E_DiffSignal_ConvChannel diffSigChannel, E_ConversionMemory memAddress) {
	
	ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl = Get_ConversionMemoryControlReg(memAddress);
	
	if (conversionChannel == NONE) { ADCConvertMemControl->rw_InputChannel = diffSigChannel; }
	
	else if (diffSigChannel == NONE) { ADCConvertMemControl->rw_InputChannel = conversionChannel; }
	
	ADCControl3->rw_ConversionStartAddress = memAddress;
}


void ADC_Init(E_DataFormat dataFormat, E_Resolution resolution, E_SamplePeriod cycles, E_ConversionNum numOfConversions, E_ConversionMemory memAddress) {
	
	ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl = Get_ConversionMemoryControlReg(memAddress);
	
	ADCControl2->unsignedBinaryDataFormat0_signedBinaryDataFormat1 = dataFormat;
	ADCControl2->rw_Resolution = resolution;
	
	ADCControl0->sampleOnRiseEdge0_sampleOnRiseEdgeThenAuto1 = numOfConversions;
	ADCControl0->rw_ADCSamplePeriodLengthReg0To7 = cycles;
	
	ADCConvertMemControl->rw_MaxAndMinVoltageMeasureThresholds = MAX_AVCC_MIN_AVSS;
	
	ADC_PinInit();
	ADCControl0->enable_ADC = 1;
	ADCControl0->enable_ADCConversion = 1;
}

int16_t ADC_Read(E_ConversionMemory memAddress) {
	
	ADC_CONVERSION_MEMORYx *const ADCConvertMem = Get_ConversionMemoryReg(memAddress);
	ADC_CONVERSION_MEMORY_CONTROLx *const ADCConvertMemControl = Get_ConversionMemoryControlReg(memAddress);

	ADCControl0->start_SampleAndConversion = 1;

	while (ADCControl1->sequenceSampleOrConversionActive == 1 && ADCConvertMemControl->endOfSequence != 1);
	return ADCConvertMem->rw_bitConversionResults;
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
	
	Watchdog_Off();
	Pin_Init('4', 2, NONE, TERTIARY_F, NO_PULL);
}

static ADC_CONVERSION_MEMORY_CONTROLx* Get_ConversionMemoryControlReg(E_ConversionMemory memAddress) {
	
	switch (memAddress) {
		
		case MEM0 :
			return ADCConvertMemControl_0;
		case MEM1 :
			return ADCConvertMemControl_1;
		case MEM2 :
			return ADCConvertMemControl_2;
		case MEM3 :
			return ADCConvertMemControl_3;
		case MEM4 :
			return ADCConvertMemControl_4;
		case MEM5 :
			return ADCConvertMemControl_5;
		case MEM6 :
			return ADCConvertMemControl_6;
		case MEM7 :
			return ADCConvertMemControl_7;
		case MEM8 :
			return ADCConvertMemControl_8;
		case MEM9 :
			return ADCConvertMemControl_9;
		case MEM10 :
			return ADCConvertMemControl_10;
		case MEM11 :
			return ADCConvertMemControl_11;
		case MEM12 :
			return ADCConvertMemControl_12;
		case MEM13 :
			return ADCConvertMemControl_13;
		case MEM14 :
			return ADCConvertMemControl_14;
		case MEM15 :
			return ADCConvertMemControl_15;
		case MEM16 :
			return ADCConvertMemControl_16;
		case MEM17 :
			return ADCConvertMemControl_17;
		case MEM18 :
			return ADCConvertMemControl_18;
		case MEM19 :
			return ADCConvertMemControl_19;
		case MEM20 :
			return ADCConvertMemControl_20;
		case MEM21 :
			return ADCConvertMemControl_21;
		case MEM22 :
			return ADCConvertMemControl_22;
		case MEM23 :
			return ADCConvertMemControl_23;
		case MEM24 :
			return ADCConvertMemControl_24;
		case MEM25 :
			return ADCConvertMemControl_25;
		case MEM26 :
			return ADCConvertMemControl_26;
		case MEM27 :
			return ADCConvertMemControl_27;
		case MEM28 :
			return ADCConvertMemControl_28;
		case MEM29 :
			return ADCConvertMemControl_29;
		case MEM30 :
			return ADCConvertMemControl_30;
		case MEM31 :
			return ADCConvertMemControl_31;
		default :
			return NULL;
	}
}

static ADC_CONVERSION_MEMORYx* Get_ConversionMemoryReg(E_ConversionMemory memAddress) {
	
	switch (memAddress) {
		
		case MEM0 :
			return ADCConvertMem_0;
		case MEM1 :
			return ADCConvertMem_1;
		case MEM2 :
			return ADCConvertMem_2;
		case MEM3 :
			return ADCConvertMem_3;
		case MEM4 :
			return ADCConvertMem_4;
		case MEM5 :
			return ADCConvertMem_5;
		case MEM6 :
			return ADCConvertMem_6;
		case MEM7 :
			return ADCConvertMem_7;
		case MEM8 :
			return ADCConvertMem_8;
		case MEM9 :
			return ADCConvertMem_9;
		case MEM10 :
			return ADCConvertMem_10;
		case MEM11 :
			return ADCConvertMem_11;
		case MEM12 :
			return ADCConvertMem_12;
		case MEM13 :
			return ADCConvertMem_13;
		case MEM14 :
			return ADCConvertMem_14;
		case MEM15 :
			return ADCConvertMem_15;
		case MEM16 :
			return ADCConvertMem_16;
		case MEM17 :
			return ADCConvertMem_17;
		case MEM18 :
			return ADCConvertMem_18;
		case MEM19 :
			return ADCConvertMem_19;
		case MEM20 :
			return ADCConvertMem_20;
		case MEM21 :
			return ADCConvertMem_21;
		case MEM22 :
			return ADCConvertMem_22;
		case MEM23 :
			return ADCConvertMem_23;
		case MEM24 :
			return ADCConvertMem_24;
		case MEM25 :
			return ADCConvertMem_25;
		case MEM26 :
			return ADCConvertMem_26;
		case MEM27 :
			return ADCConvertMem_27;
		case MEM28 :
			return ADCConvertMem_28;
		case MEM29 :
			return ADCConvertMem_29;
		case MEM30 :
			return ADCConvertMem_30;
		case MEM31 :
			return ADCConvertMem_31;
		default :
			return NULL;
	}
}