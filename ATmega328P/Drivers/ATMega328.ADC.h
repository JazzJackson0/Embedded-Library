//ATmega328/P Driver
#ifndef ADC_H_
#define ADC_H_
#include <stdint.h>
//#include <stdio.h>
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


typedef enum _Channel E_Channel;
typedef enum _ADCClockDivide E_ADCClockDivide;
typedef enum _AutoTrigSrc E_AutoTrigSrc;

//DECLARATIONS
/**
 * @brief Initialize ADC.
 * 			
 * @param channel ADC Channel (ADC_0 - ADC_5)
 * @param clockDivide ADC Clock Speed Divider: 
 * 						(ADC_DIV_2 - ADC_DIV_128: In intervals of 2^n, where n = [1 - 7])
 * 						 |||  ATmega defaults to 8MHz RC Prescaled to 1MHz
 * 						|||  Arduino Uno Board overrides ATmega and defaults to 
 * 							16MHz external xtal oscillator
 * @param autoTrigSrc ADC will start a conversion on a positive edge of the selected trigger signal.
 * @return ** void 
 */
void ADC_Init(E_Channel channel, E_ADCClockDivide clockDivide, E_AutoTrigSrc autoTrigSrc);
/**
 * @brief Start Conversion and Read ADC Result
 * 
 * @return ** int16_t Conversion Result
 */
int16_t ADC_Read(void);


//ADC (Powered by AVR Clock Control Unit)
typedef struct _adc ADCx;
#define ATMEGA_BASEADDRESS 0x0000
#define ADDR_POWER_REDUCTION_ADC ( (POWER_REDUCTION_ADC*) ((ATMEGA_BASEADDRESS) + 0x64) ) //Found in Power Management Section (Clear ADC Bit)
#define ADDR_ADC ( ( ADCx*) ((ATMEGA_BASEADDRESS) + 0x00) )


/*Analog Voltage References*/
#define INTERNAL_VREF_OFF 0x00
#define AVC_WITH_EXT_CAPACITOR 0x01
#define INTERNAL_1V_WITH_EXT_CAPACITOR 0x03

//Enums----------------------------------------------------------------------
//ADC_MUTEX_SELECT Register
/*Analog Channels*/
enum _Channel {
	ADC_0 = 0x00, ADC_1 = 0x01, ADC_2 = 0x02,
	ADC_3 = 0x03, ADC_4 = 0x04, ADC_5 = 0x05
};

//ADC_CONTROL_STATUS_A Register
/*Prescaler Values*/
enum _ADCClockDivide {
	ADC_DIV_2 = 0x00, ADC_DIV_4 = 0x02,
	ADC_DIV_8 = 0x03, ADC_DIV_16 = 0x04,
	ADC_DIV_32 = 0x05, ADC_DIV_64 = 0x06,
	ADC_DIV_128 = 0x07
};

//ADC_CONTROL_STATUS_B Register
/*Auto Trigger Sources*/
enum _AutoTrigSrc {
	FREE_RUN = 0x01, ANALOG_COMPARE = 0x02,
	EXTI_REQUEST0 = 0x03, TIMERCOUNTER0_COMP_MATCH_A = 0x04,
	TIMERCOUNTER0_OVERFLOW = 0x05, TIMERCOUNTER1_COMP_MATCH_B = 0x06,
	TIMERCOUNTER1_OVERFLOW = 0x07, TIMERCOUNTER1_CAPTURE_EVENT = 0x08
};

//Registers------------------------------------------------------------------
typedef struct {
	const uint8_t reserved:8;
}ADC_RESERVED;

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

typedef union {
	struct {
		volatile uint8_t read_ADCConversionResult:8;
	}LeftAdjust;

	struct {
		const uint8_t reserved:6;
		volatile uint8_t read_ADCConversionResult:2;
	}RightAdjust;
}ADC_DATA_HIGH;

typedef union {
	struct {
		const uint8_t reserved:6;
		volatile uint8_t read_ADCConversionResult:2;
	}LeftAdjust;

	struct {
		volatile uint8_t read_ADCConversionResult:8;
	}RightAdjust;
}ADC_DATA_LOW;

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


struct _adc {
	ADC_DATA_LOW DataLowReg; // 0x78
	ADC_DATA_HIGH DataHighReg; // 0x79
	ADC_CONTROL_STATUS_A ControlStatusAReg; // 0x7A
	ADC_CONTROL_STATUS_B ControlStatusBReg; // 0x7B
	ADC_MUTEX_SELECT MutexSelectReg; // 0x7C
	ADC_RESERVED reserved; // 0x7D
	ADC_DIGITAL_INPUT_DISABLE DigitalInputDisableReg; // 0x7E
};

#endif
