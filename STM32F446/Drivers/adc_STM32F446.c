#include <stdint.h>
#include "adc_STM32F446.h"
#include "gpio_STM32F446.h"

//Static Prototypes------------------------------------------------------------
static void ADC_PinInit(uint8_t adcNumber);
static void ADCClockSelect(uint8_t adcNumber);
static void Set_ChannelSamplePeriod(E_Channel adcChannel, E_SamplePeriod cycles);

//Global Variables-------------------------------------------------------
ADC_CLOCK *const ADCClock = ADDR_ADC_CLOCK;
//ADC
ADC_STATUS *const adcStat = ADDR_ADC_STATUS;
ADC_CONTROL1 *const adcControl1 = ADDR_ADC_CONTROL1;
ADC_CONTROL2 *const adcControl2 = ADDR_ADC_CONTROL2;
ADC_COMMON_CONTROL *const adcCommonControl = ADDR_ADC_COMMON_CONTROL;
ADC_SAMPLETIME1 *const adcSampleTim1 = ADDR_ADC_SAMPLETIME1;
ADC_SAMPLETIME2 *const adcSampleTim2 = ADDR_ADC_SAMPLETIME2;
ADC_REGULAR_SEQUENCE1 *const adcRegSeq1 = ADDR_ADC_REGULAR_SEQUENCE1;
ADC_REGULAR_SEQUENCE2 *const adcRegSeq2 = ADDR_ADC_REGULAR_SEQUENCE2;
ADC_REGULAR_SEQUENCE3 *const adcRegSeq3 = ADDR_ADC_REGULAR_SEQUENCE3;
ADC_REGULAR_DATA *const adcRegData = ADDR_ADC_REGULAR_DATA;


void ADCRegularChannel_Init(E_Channel adcChannel, uint8_t conversionOrderNum, E_SamplePeriod cycles) {
	
	//Set-up Channel for Analog signal.
	adcControl2->enable_ADC = 0;
	Set_ChannelSamplePeriod(adcChannel, cycles);
	
	switch (conversionOrderNum) {
		
		case 1 :
			adcRegSeq3->rw_1stRegSequenceConversion = adcChannel;
			break;
		case 2 :
			adcRegSeq3->rw_2ndRegSequenceConversion = adcChannel;
			break;
		case 3 :
			adcRegSeq3->rw_3rdRegSequenceConversion = adcChannel;
			break;
		case 4 :
			adcRegSeq3->rw_4thRegSequenceConversion = adcChannel;
			break;
		case 5 :
			adcRegSeq3->rw_5thRegSequenceConversion = adcChannel;
			break;
		case 6 :
			adcRegSeq3->rw_6thRegSequenceConversion = adcChannel;
			break;
		case 7 :
			adcRegSeq2->rw_7thRegSequenceConversion = adcChannel;
			break;
		case 8 :
			adcRegSeq2->rw_8thRegSequenceConversion = adcChannel;
			break;
		case 9 :
			adcRegSeq2->rw_9thRegSequenceConversion = adcChannel;
			break;
		case 10 :
			adcRegSeq2->rw_10thRegSequenceConversion = adcChannel;
			break;
		case 11 :
			adcRegSeq2->rw_11thRegSequenceConversion = adcChannel;
			break;
		case 12 :
			adcRegSeq2->rw_12thRegSequenceConversion = adcChannel;
			break;
		case 13 :
			adcRegSeq1->rw_13thRegSequenceConversion = adcChannel;
			break;
		case 14 :
			adcRegSeq1->rw_14thRegSequenceConversion = adcChannel;
			break;
		case 15 :
			adcRegSeq1->rw_15thRegSequenceConversion = adcChannel;
			break;
		case 16 :
			adcRegSeq1->rw_16thRegSequenceConversion = adcChannel;
			break;
	}
}


void ADC_Init(uint8_t adcNumber, E_Resolution resolution, E_ConvertLen singleContinuous, E_ConversionNum numOfConversions) {
	
	ADC_PinInit(adcNumber);
	ADCClockSelect(adcNumber);
	
	adcControl1->rw_Resolution = resolution;
	adcControl2->singleConvert0_continuousConvert1 = singleContinuous;
	adcRegSeq1->rw_NumOfConversionsInRegSequence = numOfConversions;
	
	adcControl2->enable_ADC = 1; 
}


int16_t ADC_ReadRegularChannel(void) {
	
	adcControl2->start_RegChannelConversion = 1;
	while (adcStat->regChannelEndOfConversion == 0);	
	return adcRegData->read_RegularConversionDataResult;
}

/**
dB(mW) – power relative to 1 milliwatt. In audio and telephony, 
dBm is typically referenced relative to a 600 Ω impedance, 
which corresponds to a voltage level of 0.775 volts or 775 millivolts
**/
float Decibel_Out(uint16_t analogVolt) {
	
	return analogVolt * 0.775;
	
}

//Helper Functions--------------------------------------------------------------------------------------------------------------
	
/**
ADC Pins ---------------------------
		These are 'Additional Functions' not 'Alternate Functions'
		Meaning: Functions are directly selected/enabled through peripheral registers.
		They are not selected through GPIOx_AFR registers.
		
		+ ADC3_IN4: PF6
		+ ADC3_IN5: PF7
		+ ADC3_IN6: PF8
		+ ADC3_IN7: PF9
		+ ADC3_IN8: PF10
		+ ADC3_IN9: PF3
		+ ADC3_IN14: PF4
		+ ADC3_IN15: PF5
	
		+ ADC12_IN4: PA4
		+ ADC12_IN5: PA5
		+ ADC12_IN6: PA6
		+ ADC12_IN7: PA7
		+ ADC12_IN8: PB0
		+ ADC12_IN9: PB1
		+ ADC12_IN14: PC4
		+ ADC12_IN15: PC5
		
		+ ADC123_IN0: PA0
		+ ADC123_IN1: PA1
		+ ADC123_IN2: PA2
		+ ADC123_IN3: PA3
		+ ADC123_IN10: PC0
		+ ADC123_IN11: PC1
		+ ADC123_IN12: PC2
		+ ADC123_IN13: PC3
		------------------------------------
**/
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

static void Set_ChannelSamplePeriod(E_Channel adcChannel, E_SamplePeriod cycles) {
	
	switch (adcChannel) {
		
		case 0 :
			adcSampleTim2->rw_Channel0SamplePeriod = cycles;
			break;
		case 1 :
			adcSampleTim2->rw_Channel1SamplePeriod = cycles;
			break;
		case 2 :
			adcSampleTim2->rw_Channel2SamplePeriod = cycles;
			break;
		case 3 :
			adcSampleTim2->rw_Channel3SamplePeriod = cycles;
			break;
		case 4 :
			adcSampleTim2->rw_Channel4SamplePeriod = cycles;
			break;
		case 5 :
			adcSampleTim2->rw_Channel5SamplePeriod = cycles;
			break;
		case 6 :
			adcSampleTim2->rw_Channel6SamplePeriod = cycles;
			break;
		case 7 :
			adcSampleTim2->rw_Channel7SamplePeriod = cycles;
			break;
		case 8 :
			adcSampleTim2->rw_Channel8SamplePeriod = cycles;
			break;
		case 9 :
			adcSampleTim2->rw_Channel9SamplePeriod = cycles;
			break;
		case 10 :
			adcSampleTim1->rw_Channel10SamplePeriod = cycles;
			break;
		case 11 :
			adcSampleTim1->rw_Channel11SamplePeriod = cycles;
			break;
		case 12 :
			adcSampleTim1->rw_Channel12SamplePeriod = cycles;
			break;
		case 13 :
			adcSampleTim1->rw_Channel13SamplePeriod = cycles;
			break;
		case 14 :
			adcSampleTim1->rw_Channel14SamplePeriod = cycles;
			break;
		case 15 :
			adcSampleTim1->rw_Channel15SamplePeriod = cycles;
			break;
		case 16 :
			adcSampleTim1->rw_Channel16SamplePeriod = cycles;
			break;
		case 17 :
			adcSampleTim1->rw_Channel17SamplePeriod = cycles;
			break;
		case 18 :
			adcSampleTim1->rw_Channel18SamplePeriod = cycles;
			break;
	}
}
		





