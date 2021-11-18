#include <stdint.h>
#include "dac_STM32F446.h"
#include "gpio_STM32F446.h"

//Static Prototypes------------------------------------------------------
static void DAC_PinInit(uint8_t dacNum);

//Global Variables-------------------------------------------------------
DAC_CLOCK *const DACClock = ADDR_DAC_CLOCK;
//DAC
DAC_CONTROL *const dacControl = ADDR_DAC_CONTROL;
DAC_CHx_12BIT_RIGHTALIGNED_DATAHOLD *const dac12Right = ADDR_DAC_CH1_12BIT_RIGHTALIGNED_DATAHOLD;
DAC_CHx_12BIT_LEFTALIGNED_DATAHOLD *const dac12Left = ADDR_DAC_CH1_12BIT_LEFTALIGNED_DATAHOLD;
DAC_CHx_8BIT_RIGHTALIGNED_DATAHOLD *const dac8Right = ADDR_DAC_CH1_8BIT_RIGHTALIGNED_DATAHOLD;
DAC_DUAL_12BIT_RIGHTALIGNED_DATAHOLD *const dacDual12Right = ADDR_DAC_DUAL_12BIT_RIGHTALIGNED_DATAHOLD;
DAC_DUAL_12BIT_LEFTALIGNED_DATAHOLD *const dacDual12Left = ADDR_DAC_DUAL_12BIT_LEFTALIGNED_DATAHOLD;
DAC_DUAL_8BIT_RIGHTALIGNED_DATAHOLD *const dacDual8Right = ADDR_DAC_DUAL_8BIT_RIGHTALIGNED_DATAHOLD;
DAC_CH1_DATA_OUTPUT *const ch1DataOut = ADDR_DAC_CH1_DATA_OUTPUT;
DAC_CH2_DATA_OUTPUT *const ch2DataOut = ADDR_DAC_CH2_DATA_OUTPUT;

void DAC_Init(uint8_t dacNum){
	
	//A Simple Init Process
	DAC_PinInit(dacNum);
	DACClock->dac_StartTick = 1;
}


/**
Sends Analog voltage value out to pin & also returns the value
**/
int16_t DAC_Out(uint8_t dacNum, int16_t digitalData) {
	
	/*I'm assuming converted digital value doesn't take up whole 16-Bit Space,
	So it should fit in 12-Bit space here (Check this during testing)*/
	dac12Right->rw_RightAlignedData12Bit = digitalData; 
	
	
	switch (dacNum) {
		
		case 1 : 
			dacControl->enable_DACChannel1 = 1;
			return ch1DataOut->read_Channel1DataOutput;
		case 2 :
			dacControl->enable_DACChannel2 = 1;
			return ch2DataOut->read_Channel2DataOutput;
		default :
			return 0;
	}
}

//Helper Functions--------------------------------------------------------------------------------------------------------------


/*DAC Pins ---------------------------
		These are 'Additional Functions' not 'Alternate Functions'
		Meaning: Functions are directly selected/enabled through peripheral registers.
		They are not selected through GPIOx_AFR registers.

		+ DAC_OUT1: PA4
		+ DAC_OUT2: PA5
		------------------------------------*/
		
static void DAC_PinInit(uint8_t dacNum) {
	
	switch (dacNum) {
		
		case 1 : 
			Pin_Init('A', 4, OUT);
			break;
		case 2 :
			Pin_Init('A', 5, OUT);
			break;
	}
}



