//MSP430FR59xx Driver
#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

typedef enum _ADCClockSource E_ADCClockSource;
typedef enum _ClockDivider E_ClockDivider;
typedef enum _ADCPreDivider E_ADCPreDivider;
typedef enum _DataFormat E_DataFormat;
typedef enum _Resolution E_Resolution;
typedef enum _SamplePeriod E_SamplePeriod;
typedef enum _ConversionNum E_ConversionNum;
typedef enum _ConversionChannel E_ConversionChannel;
typedef enum _DiffSignal_ConvChannel E_DiffSignal_ConvChannel;
typedef enum _ConversionMemory E_ConversionMemory;

//DECLARATIONS
void ADC_SetClockSpeed(E_ADCClockSource clockSource, E_ClockDivider clockDivide, E_ADCPreDivider preDivide);
void ADC_ConversionChannelSetup(E_ConversionChannel conversionChannel, E_DiffSignal_ConvChannel diffSigChannel, E_ConversionMemory memAddress);
void ADC_Init(E_DataFormat dataFormat, E_Resolution resolution, E_SamplePeriod cycles, E_ConversionNum numOfConversions, E_ConversionMemory memAddress);
int16_t ADC_Read(E_ConversionMemory memAddress);

#define ADC 0x0800

#define ADDR_ADC_CONTROL0 ( (ADC_CONTROL0*) ((ADC) + 0x00) )
#define ADDR_ADC_CONTROL1 ( (ADC_CONTROL1*) ((ADC) + 0x02) )
#define ADDR_ADC_CONTROL2 ( (ADC_CONTROL2*) ((ADC) + 0x04) )
#define ADDR_ADC_CONTROL3 ( (ADC_CONTROL3*) ((ADC) + 0x06) )
#define ADDR_ADC_CONVERSION_MEMORY0 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x60) )
#define ADDR_ADC_CONVERSION_MEMORY1 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x62) )
#define ADDR_ADC_CONVERSION_MEMORY2 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x64) )
#define ADDR_ADC_CONVERSION_MEMORY3 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x66) )
#define ADDR_ADC_CONVERSION_MEMORY4 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x68) )
#define ADDR_ADC_CONVERSION_MEMORY5 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x6A) )
#define ADDR_ADC_CONVERSION_MEMORY6 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x6C) )
#define ADDR_ADC_CONVERSION_MEMORY7 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x6E) )
#define ADDR_ADC_CONVERSION_MEMORY8 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x70) )
#define ADDR_ADC_CONVERSION_MEMORY9 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x72) )
#define ADDR_ADC_CONVERSION_MEMORY10 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x74) )
#define ADDR_ADC_CONVERSION_MEMORY11 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x76) )
#define ADDR_ADC_CONVERSION_MEMORY12 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x78) )
#define ADDR_ADC_CONVERSION_MEMORY13 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x7A) )
#define ADDR_ADC_CONVERSION_MEMORY14 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x7C) )
#define ADDR_ADC_CONVERSION_MEMORY15 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x7E) )
#define ADDR_ADC_CONVERSION_MEMORY16 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x80) )
#define ADDR_ADC_CONVERSION_MEMORY17 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x82) )
#define ADDR_ADC_CONVERSION_MEMORY18 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x84) )
#define ADDR_ADC_CONVERSION_MEMORY19 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x86) )
#define ADDR_ADC_CONVERSION_MEMORY20 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x88) )
#define ADDR_ADC_CONVERSION_MEMORY21 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x8A) )
#define ADDR_ADC_CONVERSION_MEMORY22 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x8C) )
#define ADDR_ADC_CONVERSION_MEMORY23 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x8E) )
#define ADDR_ADC_CONVERSION_MEMORY24 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x90) )
#define ADDR_ADC_CONVERSION_MEMORY25 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x92) )
#define ADDR_ADC_CONVERSION_MEMORY26 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x94) )
#define ADDR_ADC_CONVERSION_MEMORY27 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x96) )
#define ADDR_ADC_CONVERSION_MEMORY28 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x98) )
#define ADDR_ADC_CONVERSION_MEMORY29 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x9A) )
#define ADDR_ADC_CONVERSION_MEMORY30 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x9C) )
#define ADDR_ADC_CONVERSION_MEMORY31 ( (ADC_CONVERSION_MEMORYx*) ((ADC) + 0x9E) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL0 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x20) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL1 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x22) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL2 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x24) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL3 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x26) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL4 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x28) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL5 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x2A) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL6 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x2C) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL7 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x2E) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL8 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x30) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL9 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x32) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL10 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0X34) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL11 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x36) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL12 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x38) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL13 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x3A) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL14 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x3C) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL15 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x3E) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL16 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x40) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL17 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x42) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL18 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x44) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL19 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x46) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL20 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x48) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL21 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x4A) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL22 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x4C) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL23 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x4E) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL24 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x50) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL25 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x52) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL26 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x54) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL27 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x56) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL28 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x58) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL29 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x5A) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL30 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x5C) )
#define ADDR_ADC_CONVERSION_MEMORY_CONTROL31 ( (ADC_CONVERSION_MEMORY_CONTROLx*) ((ADC) + 0x5E) )
#define ADDR_ADC_WINDOW_COMPARATOR_HIGH_THRESHOLD ( (ADC_WINDOW_COMPARATOR_HIGH_THRESHOLD*) ((ADC) + 0x0A) )
#define ADDR_ADC_WINDOW_COMPARATOR_LOW_THRESHOLD ( (ADC_WINDOW_COMPARATOR_LOW_THRESHOLD*) ((ADC) + 0x08) )
#define ADDR_ADC_INTERRUPT_ENABLE0 ( (ADC_INTERRUPT_ENABLE0*) ((ADC) + 0x12) )
#define ADDR_ADC_INTERRUPT_ENABLE1 ( (ADC_INTERRUPT_ENABLE1*) ((ADC) + 0x14) )
#define ADDR_ADC_INTERRUPT_ENABLE2 ( (ADC_INTERRUPT_ENABLE2*) ((ADC) + 0x16) )
#define ADDR_ADC_INTERRUPT_FLAG0 ( (ADC_INTERRUPT_FLAG0*) ((ADC) + 0x0C) )
#define ADDR_ADC_INTERRUPT_FLAG1 ( (ADC_INTERRUPT_FLAG1*) ((ADC) + 0x0E) )
#define ADDR_ADC_INTERRUPT_FLAG2 ( (ADC_INTERRUPT_FLAG2*) ((ADC) + 0x10) )
#define ADDR_ADC_INTERRUPT_VECTOR ( (ADC_INTERRUPT_VECTOR*) ((ADC) + 0x18) )

//ADC_CONTROL1 Register
/*Conversion Sequence Modes*/
#define SINGLE_CH_SINGLE_CONV 0x00
#define SEQUENCE_OF_CH 0x01
#define REPEAT_SINGLE_CH 0x02
#define REPEAT_SEQUENCE_OF_CH 0x03

//ADC_CONVERSION_MEMORY_CONTROLx
/*Max and Min Voltage Measure Thresholds*/
#define MAX_AVCC_MIN_AVSS 0x00
#define MAX_VREF_MIN_AVSS 0x01
#define MAX_VEREFMINUS__MIN_AVSS 0x02
#define MAX_VEREFPLUS_BUFF_MIN_AVSS 0x03
#define MAX_VEREFPLUS_MIN_AVSS 0x04
#define MAX_AVCC_MIN_VEREFPLUS_BUFF 0x05
#define MAX_AVCC_MIN_VEREFPLUS 0x06
#define MAX_VREF_BUFF_MIN_VEREFPLUS 0x07
#define MAX_AVCC_MIN_VREF_BUFF 0x09
#define MAX_VEREFPLUS_MIN_VREF_BUFF 0x0B
#define MAX_AVCC_MIN_VEREFMINUS 0x0C
#define MAX_VREF_BUFF_MIN_VEREFMINUS 0x0D
#define MAX_VEREFPLUS_MIN_VEREFMINUS 0x0E
#define MAX_VEREFPLUS_BUFF_MIN_VEREFMINUS 0x0F

//Enums----------------------------------------------------------------------
/*Clock Source*/
enum _ADCClockSource {
	ADC12OSC_MODOSC = 0x00,
	ADC_A_CLOCK = 0x01,
	ADC_M_CLOCK = 0x02,
	ADC_SM_CLOCK = 0x03
};
	
/*Clock Divider*/
enum _ClockDivider {
	ADC_DIV_1 = 0x00,
	ADC_DIV_2 = 0x01,
	ADC_DIV_3 = 0x02,
	ADC_DIV_4 = 0x03,
	ADC_DIV_5 = 0x04,
	ADC_DIV_6 = 0x05,
	ADC_DIV_7 = 0x06,
	ADC_DIV_8 = 0x07
};
	
/*Clock Pre-Divider*/
enum _ADCPreDivider {
	ADC_PRE_DIV_1 = 0x00,
	ADC_PRE_DIV_4 = 0x01,
	ADC_PRE_DIV_32 = 0x02,
	ADC_PRE_DIV_64 = 0x03
};


enum _DataFormat {
	SIGNED = 1,
	UNSIGNED = 0
};

//ADC_CONTROL2 Register
/*Resolution*/
enum _Resolution {
	_8BIT_ADC = 0x00,
	_10BIT_ADC = 0x01,
	_12BIT_ADC = 0x02
};

//ADC_CONTROL0 Register
/*Sample Period Lengths*/
enum _SamplePeriod {
	CYCLE_4 = 0x00,
	CYCLE_8 = 0x01,
	CYCLE_16 = 0x02,
	CYCLE_32 = 0x03,
	CYCLE_64 = 0x04,
	CYCLE_96 = 0x05,
	CYCLE_128 = 0x06,
	CYCLE_192 = 0x07,
	CYCLE_256 = 0x08,
	CYCLE_384 = 0x09,
	CYCLE_512 = 0x0A
};

enum _ConversionNum {
	CONTINUOUS = 1,
	SINGLE = 0
};

//ADC_CONVERSION_MEMORY_CONTROLx
/*Input Channels for Non-Differential Input*/
enum _ConversionChannel {
	A0 = 0x00,
	A1 = 0x01,
	A2 = 0x02,
	A3 = 0x03,
	A4 = 0x04,
	A5 = 0x05,
	A6 = 0x06,
	A7 = 0x07,
	A8 = 0x08,
	A9 = 0x09,
	A10 = 0x0A,
	A11 = 0x0B,
	A12 = 0x0C,
	A13 = 0x0D,
	A14 = 0x0E,
	A15 = 0x0F,
	A16 = 0x10,
	A17 = 0x11,
	A18 = 0x12,
	A19 = 0x13,
	A20 = 0x14,
	A21 = 0x15,
	A22 = 0x16,
	A23 = 0x17,
	A24 = 0x18,
	A25 = 0x19,
	A26 = 0x1A,
	A27 = 0x1B,
	A28 = 0x1C,
	A29 = 0x1D,
	A30 = 0x1E,
	A31 = 0x1F,
	NO_CH = 0x20
};

/*Input Channels for Differential Signal Input*/
enum _DiffSignal_ConvChannel {
	A0POS_A1NEG = 0x00,
	A2POS_A3NEG = 0x02,
	A4POS_A5NEG = 0x04,
	A6POS_A7NEG = 0x06,
	A8POS_A9NEG = 0x08,
	A10POS_A11NEG = 0x0A,
	A12POS_A13NEG = 0x0C,
	A14POS_A15NEG = 0x0E,
	A16POS_A17NEG = 0x10,
	A18POS_A19NEG = 0x12,
	A20POS_A21NEG = 0x14,
	A22POS_A23NEG = 0x16,
	A24POS_A25NEG = 0x18,
	A26POS_A27NEG = 0x1A,
	A28POS_A29NEG = 0x1C,
	A30POS_A31NEG = 0x1E,
	NO_DIF_CH = 0x20
};

enum _ConversionMemory {
	MEM0 = 0x0,
	MEM1 = 0x1,
	MEM2 = 0x2,
	MEM3 = 0x3,
	MEM4 = 0x4,
	MEM5 = 0x5,
	MEM6 = 0x6,
	MEM7 = 0x7,
	MEM8 = 0x8,
	MEM9 = 0x9,
	MEM10 = 0x0A,
	MEM11 = 0x0B,
	MEM12 = 0x0C,
	MEM13 = 0x0D,
	MEM14 = 0x0E,
	MEM15 = 0x0F,
	MEM16 = 0x10,
	MEM17 = 0x11,
	MEM18 = 0x12,
	MEM19 = 0x13,
	MEM20 = 0x14,
	MEM21 = 0x15,
	MEM22 = 0x16,
	MEM23 = 0x17,
	MEM24 = 0x18,
	MEM25 = 0x19,
	MEM26 = 0x1A,
	MEM27 = 0x1B,
	MEM28 = 0x1C,
	MEM29 = 0x1D,
	MEM30 = 0x1E,
	MEM31 = 0x1F
};

//Registers------------------------------------------------------------------
typedef struct {
	volatile uint16_t start_SampleAndConversion:1;
	volatile uint16_t enable_ADCConversion:1; //Enables Conversion Process
	const uint16_t reserved0:2;
	volatile uint16_t enable_ADC:1; //Enables Sampling Process
	const uint16_t reserved1:2;
	volatile uint16_t sampleOnRiseEdge0_sampleOnRiseEdgeThenAuto1:1;
	volatile uint16_t rw_ADCSamplePeriodLengthReg0To7:4;
	volatile uint16_t rw_ADCSamplePeriodLengthReg8To23:4;
}ADC_CONTROL0;

typedef struct {
	volatile uint16_t sequenceSampleOrConversionActive:1;
	volatile uint16_t rw_ConversionSequenceMode:2;
	volatile uint16_t select_ClockSource:2;
	volatile uint16_t rw_ClockDivider:3;
	volatile uint16_t invert_SampleInputSignal:1;
	volatile uint16_t sampleSignalFromInput0_sampleSignalFromTimer1:1;
	volatile uint16_t rw_SampleAndHoldSource:3;
	volatile uint16_t rw_ADCClockPreDivider:2;
	const uint16_t reserved:1;
}ADC_CONTROL1;

typedef struct {
	volatile uint16_t enable_LowPowerMode:1;
	const uint16_t reserved0:2;
	volatile uint16_t unsignedBinaryDataFormat0_signedBinaryDataFormat1:1;
	volatile uint16_t rw_Resolution:2;
	const uint16_t reserved1:10;
}ADC_CONTROL2;

typedef struct {
	volatile uint16_t rw_ConversionStartAddress:5;
	const uint16_t reserved0:1;
	volatile uint16_t externalPinFor31Ch0_internalHalfAVCCFor31Ch1:1;
	volatile uint16_t externalPinFor30Ch0_internalHalfAVCCFor30Ch1:1;
	volatile uint16_t externalPinFor29Ch0_internalHalfAVCCFor29Ch1:1;
	volatile uint16_t externalPinFor28Ch0_internalHalfAVCCFor28Ch1:1;
	volatile uint16_t externalPinFor27Ch0_internalHalfAVCCFor27Ch1:1;
	volatile uint16_t externalPinFor26Ch0_internalHalfAVCCFor26Ch1:1;
	const uint16_t reserved1:4;
}ADC_CONTROL3;

typedef struct {
	volatile uint16_t rw_bitConversionResults:16;
}ADC_CONVERSION_MEMORYx;

typedef struct {
	volatile uint16_t rw_InputChannel:5;
	const uint16_t reserved0:2;
	volatile uint16_t endOfSequence:1;
	volatile uint16_t rw_MaxAndMinVoltageMeasureThresholds:4;
	const uint16_t reserved1:1;
	volatile uint16_t singleEndedMode0_differentialMode1:1;
	volatile uint16_t enable_ComparatorWindow:1;
	const uint16_t reserved2:1;
}ADC_CONVERSION_MEMORY_CONTROLx;

typedef struct {
	volatile uint16_t rw_WindowComparatorHighThreshold:1;
}ADC_WINDOW_COMPARATOR_HIGH_THRESHOLD;

typedef struct {
	volatile uint16_t rw_WindowComparatorLowThreshold:1;
}ADC_WINDOW_COMPARATOR_LOW_THRESHOLD;

typedef struct {
	volatile uint16_t enable_ADCBit0Interrupt:1;
	volatile uint16_t enable_ADCBit1Interrupt:1;
	volatile uint16_t enable_ADCBit2Interrupt:1;
	volatile uint16_t enable_ADCBit3Interrupt:1;
	volatile uint16_t enable_ADCBit4Interrupt:1;
	volatile uint16_t enable_ADCBit5Interrupt:1;
	volatile uint16_t enable_ADCBit6Interrupt:1;
	volatile uint16_t enable_ADCBit7Interrupt:1;
	volatile uint16_t enable_ADCBit8Interrupt:1;
	volatile uint16_t enable_ADCBit9Interrupt:1;
	volatile uint16_t enable_ADCBit10Interrupt:1;
	volatile uint16_t enable_ADCBit11Interrupt:1;
	volatile uint16_t enable_ADCBit12Interrupt:1;
	volatile uint16_t enable_ADCBit13Interrupt:1;
	volatile uint16_t enable_ADCBit14Interrupt:1;
	volatile uint16_t enable_ADCBit15Interrupt:1;
}ADC_INTERRUPT_ENABLE0;

typedef struct {
	volatile uint16_t enable_ADCBit16Interrupt:1;
	volatile uint16_t enable_ADCBit17Interrupt:1;
	volatile uint16_t enable_ADCBit18Interrupt:1;
	volatile uint16_t enable_ADCBit19Interrupt:1;
	volatile uint16_t enable_ADCBit20Interrupt:1;
	volatile uint16_t enable_ADCBit21Interrupt:1;
	volatile uint16_t enable_ADCBit22Interrupt:1;
	volatile uint16_t enable_ADCBit23Interrupt:1;
	volatile uint16_t enable_ADCBit24Interrupt:1;
	volatile uint16_t enable_ADCBit25Interrupt:1;
	volatile uint16_t enable_ADCBit26Interrupt:1;
	volatile uint16_t enable_ADCBit27Interrupt:1;
	volatile uint16_t enable_ADCBit28Interrupt:1;
	volatile uint16_t enable_ADCBit29Interrupt:1;
	volatile uint16_t enable_ADCBit30Interrupt:1;
	volatile uint16_t enable_ADCBit31Interrupt:1;
}ADC_INTERRUPT_ENABLE1;

typedef struct {
	const uint16_t reserved0:1;
	volatile uint16_t enable_ResultOverLowThreshUnderHighThreshInterrupt:1;
	volatile uint16_t enable_BelowLowerLimitInterrupt:1;
	volatile uint16_t enable_ExceedsUpperLimitInterrupt:1;
	volatile uint16_t enable_OverflowInterrupt:1;
	volatile uint16_t enable_ConversionTimeOverflowInterrupt:1;
	volatile uint16_t enable_LocalReferenceBufferReadyInterrupt:1;
	const uint16_t reserved1:9;
}ADC_INTERRUPT_ENABLE2;

typedef struct {
	volatile uint16_t adcBit0HasResult:1;
	volatile uint16_t adcBit1HasResult:1;
	volatile uint16_t adcBit2HasResult:1;
	volatile uint16_t adcBit3HasResult:1;
	volatile uint16_t adcBit4HasResult:1;
	volatile uint16_t adcBit5HasResult:1;
	volatile uint16_t adcBit6HasResult:1;
	volatile uint16_t adcBit7HasResult:1;
	volatile uint16_t adcBit8HasResult:1;
	volatile uint16_t adcBit9HasResult:1;
	volatile uint16_t adcBit10HasResult:1;
	volatile uint16_t adcBit11HasResult:1;
	volatile uint16_t adcBit12HasResult:1;
	volatile uint16_t adcBit13HasResult:1;
	volatile uint16_t adcBit14HasResult:1;
	volatile uint16_t adcBit15HasResult:1;
}ADC_INTERRUPT_FLAG0;

typedef struct {
	volatile uint16_t adcBit16HasResult:1;
	volatile uint16_t adcBit17HasResult:1;
	volatile uint16_t adcBit18HasResult:1;
	volatile uint16_t adcBit19HasResult:1;
	volatile uint16_t adcBit20HasResult:1;
	volatile uint16_t adcBit21HasResult:1;
	volatile uint16_t adcBit22HasResult:1;
	volatile uint16_t adcBit23HasResult:1;
	volatile uint16_t adcBit24HasResult:1;
	volatile uint16_t adcBit25HasResult:1;
	volatile uint16_t adcBit26HasResult:1;
	volatile uint16_t adcBit27HasResult:1;
	volatile uint16_t adcBit28HasResult:1;
	volatile uint16_t adcBit29HasResult:1;
	volatile uint16_t adcBit30HasResult:1;
	volatile uint16_t adcBit31HasResult:1;
}ADC_INTERRUPT_FLAG1;

typedef struct {
	const uint16_t reserved0:1;
	volatile uint16_t resultOverLowThreshUnderHighThreshInterruptOccurred:1;
	volatile uint16_t belowLowerLimitInterruptOccurred:1;
	volatile uint16_t exceedsUpperLimitInterruptOccurred:1;
	volatile uint16_t overflowInterruptOccurred:1;
	volatile uint16_t conversionTimeOverflowInterruptOccurred:1;
	volatile uint16_t localReferenceBufferReadyInterruptOccurred:1;
	const uint16_t reserved1:9;
}ADC_INTERRUPT_FLAG2;

typedef struct {
	volatile uint16_t read_HighestPriorityInterruptPending:1;
}ADC_INTERRUPT_VECTOR;

#endif
