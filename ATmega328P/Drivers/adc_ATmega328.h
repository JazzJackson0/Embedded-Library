//ATmega328/P Driver
#ifndef ADC_H_
#define ADC_H_

/*ADC Pins ---------------------------

		+ ADC Input Channel 0 (ADC0): PC0
		+ ADC Input Channel 1 (ADC1): PC1
		+ ADC Input Channel 2 (ADC2): PC2
		+ ADC Input Channel 3 (ADC3): PC3
		+ ADC Input Channel 4 (ADC4): PC4
		+ ADC Input Channel 5 (ADC5): PC5
		+ ADC Input Channel 6 (ADC6): ADC6
		+ ADC Input Channel 7 (ADC7): ADC7
		
		+ AIN0: PD6
		+ AIN1: PD7
		------------------------------------*/

#include <stdint.h>
//Powered by AVR Clock Control Unit

typedef enum _Channel E_Channel;
typedef enum _ADCClockDivide E_ADCClockDivide;
typedef enum _AutoTrigSrc E_AutoTrigSrc;

void ADC_Init_and_Start(E_Channel channel, E_ADCClockDivide clockDivide, E_AutoTrigSrc autoTrigSrc);
int16_t ADC_Read(void);

#define ATMEGA_BASEADDRESS 0x0000

#define ADDR_POWER_REDUCTION_ADC ( (POWER_REDUCTION_ADC*) ((ATMEGA_BASEADDRESS) + 0x64) ) //Found in Power Management Section (Clear ADC Bit)
#define ADDR_ADC_MUTEX_SELECT ( (ADC_MUTEX_SELECT*) ((ATMEGA_BASEADDRESS) + 0x7C) )
#define ADDR_ADC_CONTROL_STATUS_A ( (ADC_CONTROL_STATUS_A*) ((ATMEGA_BASEADDRESS) + 0x7A) )
#define ADDR_ADC_DATA_LOW_RIGHT ( (ADC_DATA_LOW_RIGHT*) ((ATMEGA_BASEADDRESS) + 0x78) )
#define ADDR_ADC_DATA_HIGH_RIGHT ( (ADC_DATA_HIGH_RIGHT*) ((ATMEGA_BASEADDRESS) + 0x79) )
#define ADDR_ADC_DATA_LOW_LEFT ( (ADC_DATA_LOW_LEFT*) ((ATMEGA_BASEADDRESS) + 0x78) )
#define ADDR_ADC_DATA_HIGH_LEFT ( (ADC_DATA_HIGH_LEFT*) ((ATMEGA_BASEADDRESS) + 0x79) )
#define ADDR_ADC_CONTROL_STATUS_B ( (ADC_CONTROL_STATUS_B*) ((ATMEGA_BASEADDRESS) + 0x7B) )
#define ADDR_ADC_DIGITAL_INPUT_DISABLE ( (ADC_DIGITAL_INPUT_DISABLE*) ((ATMEGA_BASEADDRESS) + 0x7E) )

/*Analog Voltage References*/
#define INTERNAL_VREF_OFF 0x00
#define AVC_WITH_EXT_CAPACITOR 0x01
#define INTERNAL_1V_WITH_EXT_CAPACITOR 0x03

//Enums----------------------------------------------------------------------
//ADC_MUTEX_SELECT Register
/*Analog Channels*/
enum _Channel {
	ADC_0 = 0x00,
	ADC_1 = 0x01,
	ADC_2 = 0x02,
	ADC_3 = 0x03,
	ADC_4 = 0x04,
	ADC_5 = 0x05
};

//ADC_CONTROL_STATUS_A Register
/*Prescaler Values*/
enum _ADCClockDivide {
	ADC_DIV_2 = 0x00,
	ADC_DIV_4 = 0x02,
	ADC_DIV_8 = 0x03,
	ADC_DIV_16 = 0x04,
	ADC_DIV_32 = 0x05,
	ADC_DIV_64 = 0x06,
	ADC_DIV_128 = 0x07
};

//ADC_CONTROL_STATUS_B Register
/*Auto Trigger Sources*/
enum _AutoTrigSrc {
	FREE_RUN = 0x01,
	ANALOG_COMPARE = 0x02,
	EXTI_REQUEST0 = 0x03,
	TIMERCOUNTER0_COMP_MATCH_A = 0x04,
	TIMERCOUNTER0_OVERFLOW = 0x05,
	TIMERCOUNTER1_COMP_MATCH_B = 0x06,
	TIMERCOUNTER1_OVERFLOW = 0x07,
	TIMERCOUNTER1_CAPTURE_EVENT = 0x08
};

//Registers------------------------------------------------------------------
typedef struct {
	volatile uint8_t adcOn0_adcOff1:1;
	const uint8_t reserved:7;
}POWER_REDUCTION_ADC;

typedef struct {
	volatile uint8_t rw_AnalogChannel:4;
	const uint8_t reserved:1;
	volatile uint8_t rightAdjustedADCResult0_leftAdjustedADCResult1:1;
	volatile uint8_t rw_ADCVoltageReference:2;
}ADC_MUTEX_SELECT;

typedef struct {
	volatile uint8_t rw_PrescalerValue:3;
	volatile uint8_t enable_ADCConversionCompleteInterrupt:1;
	volatile uint8_t adcConversionCompleteInterruptOccurred:1;
	volatile uint8_t enable_ADCAutoTrigger:1;
	volatile uint8_t start_ADCConversion:1;
	volatile uint8_t enable_ADC:1;
}ADC_CONTROL_STATUS_A;

typedef struct {
	volatile uint8_t read_ADCConversionResultLow:8;
}ADC_DATA_LOW_RIGHT;

typedef struct {
	const uint8_t reserved:6;
	volatile uint8_t read_ADCConversionResultHigh:2;
}ADC_DATA_HIGH_RIGHT;

typedef struct {
	const uint8_t reserved:6;
	volatile uint8_t read_ADCConversionResultLow:2;
}ADC_DATA_LOW_LEFT;

typedef struct {
	volatile uint8_t read_ADCConversionResultHigh:8;
}ADC_DATA_HIGH_LEFT;

typedef struct {
	volatile uint8_t rw_AutoTriggerSource:3;
	const uint8_t reserved0:3;
	volatile uint8_t enable_AnalogComparatorMutex:1;
	const uint8_t reserved1:1;
}ADC_CONTROL_STATUS_B;

typedef struct {
	volatile uint8_t disableInput_Pin0:1;
	volatile uint8_t disableInput_Pin1:1;
	volatile uint8_t disableInput_Pin2:1;
	volatile uint8_t disableInput_Pin3:1;
	volatile uint8_t disableInput_Pin4:1;
	volatile uint8_t disableInput_Pin5:1;
	volatile uint8_t disableInput_Pin6:1;
	volatile uint8_t disableInput_Pin7:1;
}ADC_DIGITAL_INPUT_DISABLE;

#endif
