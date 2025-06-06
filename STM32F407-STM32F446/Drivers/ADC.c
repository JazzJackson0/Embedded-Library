#include "ADC.h"


//Static Prototypes------------------------------------------------------------
static void ADC_PinInit(uint8_t adcNumber);
static void ADCClockSelect(uint8_t adcNumber);
static ADCx* Get_ADC(char adcNum);
static void Set_ChannelSamplePeriod(ADCx *ADC, E_Channel adcChannel, E_SamplePeriod cycles);

//Global Variables-------------------------------------------------------
ADC_CLOCK *const ADCClock = ADDR_ADC_CLOCK;
//ADC
CommonADCRegisters *const CommonRegs = ADDR_COMMON_ADC_REG;
ADCx *const ADC1 = ADDR_ADC1;
ADCx *const ADC2 = ADDR_ADC2;
ADCx *const ADC3 = ADDR_ADC3;


void ADCRegularChannel_Init(uint8_t adcNumber, E_Channel adcChannel, 
	uint8_t conversionOrderNum, E_SamplePeriod cycles) {
	
	ADCx *const ADC = Get_ADC(adcNumber);

	//Set-up Channel for Analog signal.
	ADC->ControlReg2.enable_ADC = 0;
	Set_ChannelSamplePeriod(ADC, adcChannel, cycles);
	
	switch (conversionOrderNum) {
		
		case 1 :
			ADC->RegularSequenceReg3.rw_1stRegSequenceConversion = adcChannel;
			break;
		case 2 :
			ADC->RegularSequenceReg3.rw_2ndRegSequenceConversion = adcChannel;
			break;
		case 3 :
			ADC->RegularSequenceReg3.rw_3rdRegSequenceConversion = adcChannel;
			break;
		case 4 :
			ADC->RegularSequenceReg3.rw_4thRegSequenceConversion = adcChannel;
			break;
		case 5 :
			ADC->RegularSequenceReg3.rw_5thRegSequenceConversion = adcChannel;
			break;
		case 6 :
			ADC->RegularSequenceReg3.rw_6thRegSequenceConversion = adcChannel;
			break;
		case 7 :
			ADC->RegularSequenceReg2.rw_7thRegSequenceConversion = adcChannel;
			break;
		case 8 :
			ADC->RegularSequenceReg2.rw_8thRegSequenceConversion = adcChannel;
			break;
		case 9 :
			ADC->RegularSequenceReg2.rw_9thRegSequenceConversion = adcChannel;
			break;
		case 10 :
			ADC->RegularSequenceReg2.rw_10thRegSequenceConversion = adcChannel;
			break;
		case 11 :
			ADC->RegularSequenceReg2.rw_11thRegSequenceConversion = adcChannel;
			break;
		case 12 :
			ADC->RegularSequenceReg2.rw_12thRegSequenceConversion = adcChannel;
			break;
		case 13 :
			ADC->RegularSequenceReg1.rw_13thRegSequenceConversion = adcChannel;
			break;
		case 14 :
			ADC->RegularSequenceReg1.rw_14thRegSequenceConversion = adcChannel;
			break;
		case 15 :
			ADC->RegularSequenceReg1.rw_15thRegSequenceConversion = adcChannel;
			break;
		case 16 :
			ADC->RegularSequenceReg1.rw_16thRegSequenceConversion = adcChannel;
			break;
	}
}


void ADC_RegularInit(uint8_t adcNumber, E_Resolution resolution, E_SingleCont singleContinuous, 
	E_ConversionNum numOfConversions) {
	
	ADC_PinInit(adcNumber);
	ADCClockSelect(adcNumber);
	ADCx *const ADC = Get_ADC(adcNumber);
	
	ADC->ControlReg1.rw_Resolution = resolution;
	ADC->ControlReg2.singleConvert0_continuousConvert1 = singleContinuous;
	ADC->RegularSequenceReg1.rw_NumOfConversionsInRegSequence = numOfConversions;
	ADC->ControlReg2.enable_ADC = 1; 
}


int16_t ADC_ReadRegularChannel(uint8_t adcNumber) {
	
	//How to handle continuous readings??
	ADCx *const ADC = Get_ADC(adcNumber);
	ADC->ControlReg2.start_RegChannelConversion = 1;
	while (ADC->StatusReg.regChannelEndOfConversion == 0);	
	return ADC->RegularDataReg.read_RegularConversionDataResult;
}

//Helper Functions--------------------------------------------------------------------------------------------------------------
static void ADC_PinInit(uint8_t adcNumber) {
	
	switch (adcNumber) {
		
		case 3 : 
			Pin_Init('F', 6, IN);
			break;
		case 12 :
			Pin_Init('A', 4, IN);
			break;
		case 123 :
			Pin_Init('A', 0, IN);
			break;
	}
}

static void ADCClockSelect(uint8_t adcNumber) {
	
	switch(adcNumber) {
		
		case 3 :
			ADCClock->adc3_StartTick = 1;
			break;
		case 12 :
			ADCClock->adc1_StartTick = 1;
			ADCClock->adc2_StartTick = 1;
			break;
		case 123 :
			ADCClock->adc1_StartTick = 1;
			ADCClock->adc2_StartTick = 1;
			ADCClock->adc3_StartTick = 1;
			break;
	}
}

static ADCx* Get_ADC(char adcNum) {

	switch(adcNum) {

		case 1:
			return ADC1;
		case 2:
			return ADC2;
		case 3:
			return ADC3;
		default:
			return ((void*)0);
	}
}

static void Set_ChannelSamplePeriod(ADCx *ADC, E_Channel adcChannel, E_SamplePeriod cycles) {
	
	switch (adcChannel) {
		case 0 :
			ADC->SampleTimeReg2.rw_Channel0SamplePeriod = cycles;
			break;
		case 1 :
			ADC->SampleTimeReg2.rw_Channel1SamplePeriod = cycles;
			break;
		case 2 :
			ADC->SampleTimeReg2.rw_Channel2SamplePeriod = cycles;
			break;
		case 3 :
			ADC->SampleTimeReg2.rw_Channel3SamplePeriod = cycles;
			break;
		case 4 :
			ADC->SampleTimeReg2.rw_Channel4SamplePeriod = cycles;
			break;
		case 5 :
			ADC->SampleTimeReg2.rw_Channel5SamplePeriod = cycles;
			break;
		case 6 :
			ADC->SampleTimeReg2.rw_Channel6SamplePeriod = cycles;
			break;
		case 7 :
			ADC->SampleTimeReg2.rw_Channel7SamplePeriod = cycles;
			break;
		case 8 :
			ADC->SampleTimeReg2.rw_Channel8SamplePeriod = cycles;
			break;
		case 9 :
			ADC->SampleTimeReg2.rw_Channel9SamplePeriod = cycles;
			break;
		case 10 :
			ADC->SampleTimeReg1.rw_Channel10SamplePeriod = cycles;
			break;
		case 11 :
			ADC->SampleTimeReg1.rw_Channel11SamplePeriod = cycles;
			break;
		case 12 :
			ADC->SampleTimeReg1.rw_Channel12SamplePeriod = cycles;
			break;
		case 13 :
			ADC->SampleTimeReg1.rw_Channel13SamplePeriod = cycles;
			break;
		case 14 :
			ADC->SampleTimeReg1.rw_Channel14SamplePeriod = cycles;
			break;
		case 15 :
			ADC->SampleTimeReg1.rw_Channel15SamplePeriod = cycles;
			break;
		case 16 :
			ADC->SampleTimeReg1.rw_Channel16SamplePeriod = cycles;
			break;
		case 17 :
			ADC->SampleTimeReg1.rw_Channel17SamplePeriod = cycles;
			break;
		case 18 :
			ADC->SampleTimeReg1.rw_Channel18SamplePeriod = cycles;
			break;
	}
}		

