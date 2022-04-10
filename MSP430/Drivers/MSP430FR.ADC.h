//MSP430FR59xx Driver
#ifndef ADC_H_
#define ADC_H_
#include <stdint.h>
//#include <stdio.h>
#include "MSP430FR.DigitalIO.h"

typedef enum _ADCClockSource E_ADCClockSource;
typedef enum _ClockDivider E_ClockDivider;
typedef enum _ADCPreDivider E_ADCPreDivider;
typedef enum _DataFormat E_DataFormat;
typedef enum _Resolution E_Resolution;
typedef enum _SamplePeriod E_SamplePeriod;
typedef enum _singleContinuous E_SingleContinuous;
typedef enum _ConversionChannel E_ConversionChannel;
typedef enum _DiffSignal_ConvChannel E_DiffSignal_ConvChannel;
typedef enum _ConversionMemory E_ConversionMemory;

//DECLARATIONS
/**
 * @brief Set ADC Clock source and speed.
 * 
 * @param clockSource Clock Source: (ADC12OSC_MODOSC, ADC_A_CLOCK, ADC_M_CLOCK, ADC_SM_CLOCK) 
 * 						|||  SMCLK & MCLK = DCOCLK(1MHz) / 8  = 125KHz 
 * 						|||  According to '3.2 Clock System Operation'
 * @param preDivide ADC CLock 'Pre-Division' Prescaler Value. The First Prescale of the ADC Clock. 
 * 					(ADC_PRE_DIV_x: Where x = 1, 4, 32, 64)
 * @param clockDivide ADC Clock Prescaler Value. The Second Prescale of the ADC Clock. 
 * 					(ADC_DIV_1 - ADC_DIV_8)
 * @return ** void 
 */
void ADC_SetClockSpeed(E_ADCClockSource clockSource, E_ADCPreDivider preDivide,
	E_ClockDivider clockDivide);
/**
 * @brief Initialize Conversion Channel
 * 
 * @param conversionChannel ADC Conversion Channel Number (NO_CH, A0 - A31)
 * @param diffSigChannel ADC Differential Signal Conversion Channel Number
 * 						(NO_DIF_CH, AxPOS_AyNEG: Where (x,y) = (0,1), (2,3), (4,5), ... (30,31))
 * @param memAddress Memory Adddress for Results of given conversion channel. (MEM0 - MEM31)
 * @return ** void 
 */
void ADC_ConversionChannelSetup(E_ConversionChannel conversionChannel, 
	E_DiffSignal_ConvChannel diffSigChannel, E_ConversionMemory memAddress);
/**
 * @brief Initialize ADC
 * 
 * @param dataFormat ADC Data Format: SIGNED or UNSIGNED data
 * @param resolution ADC Resolution (_8BIT_ADC, _10BIT_ADC, _12BIT_ADC)
 * @param cycles Number of Clock Cycles between ADC Conversions 
 * 				(CYCLE_4 - CYCLE_512: In intervals of 2^n, where n = [2 - 9])
 * @param singleContinuous A SINGLE conversion or CONTINUOUS conversions.
 * @param memAddress Memory Adddress for Results of given conversion channel. (MEM0 - MEM31)
 * @return ** void 
 */
void ADC_Init(E_DataFormat dataFormat, E_Resolution resolution, 
	E_SamplePeriod cycles, E_SingleContinuous singleContinuous, E_ConversionMemory memAddress);
/**
 * @brief Start Conversion and Read ADC Result
 * 
 * @param memAddress Memory Adddress for Results of given conversion channel. (MEM0 - MEM31)
 * @return ** int16_t Conversion Result
 */
int16_t ADC_Read(E_ConversionMemory memAddress);

//ADC
typedef struct _adc ADCx;
typedef struct _conversion_mem_ctrl CONVERSION_MEM_CTRL;
typedef struct _conversion_mem CONVERSION_MEM;
typedef union mem_ctrl_access MEM_CTRL_ACCESSx;
typedef union mem_access MEM_ACCESSx;
#define ADC_BASE 0x0800
#define ADDR_ADC ( (ADCx*) ((ADC_BASE) + 0x00) ) 
#define ADDR_MEM_CTRL ( (MEM_CTRL_ACCESSx*) ((ADC_BASE) + 0x20) ) 
#define ADDR_MEM ( (MEM_ACCESSx*) ((ADC_BASE) + 0x60) ) 


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
	ADC12OSC_MODOSC = 0x00, ADC_A_CLOCK = 0x01, ADC_M_CLOCK = 0x02,
	ADC_SM_CLOCK = 0x03
};
	
/*Clock Divider*/
enum _ClockDivider {
	ADC_DIV_1 = 0x00, ADC_DIV_2 = 0x01, ADC_DIV_3 = 0x02,
	ADC_DIV_4 = 0x03, ADC_DIV_5 = 0x04, ADC_DIV_6 = 0x05,
	ADC_DIV_7 = 0x06, ADC_DIV_8 = 0x07
};
	
/*Clock Pre-Divider*/
enum _ADCPreDivider {
	ADC_PRE_DIV_1 = 0x00, ADC_PRE_DIV_4 = 0x01,
	ADC_PRE_DIV_32 = 0x02, ADC_PRE_DIV_64 = 0x03
};


enum _DataFormat {
	SIGNED = 1, UNSIGNED = 0
};

//ADC_CONTROL2 Register
/*Resolution*/
enum _Resolution {
	_8BIT_ADC = 0x00, _10BIT_ADC = 0x01, _12BIT_ADC = 0x02
};

//ADC_CONTROL0 Register
/*Sample Period Lengths*/
enum _SamplePeriod {
	CYCLE_4 = 0x00, CYCLE_8 = 0x01, CYCLE_16 = 0x02,
	CYCLE_32 = 0x03, CYCLE_64 = 0x04, CYCLE_96 = 0x05,
	CYCLE_128 = 0x06, CYCLE_192 = 0x07, CYCLE_256 = 0x08,
	CYCLE_384 = 0x09, CYCLE_512 = 0x0A
};

enum _singleContinuous {
	CONTINUOUS = 1, SINGLE = 0
};

//ADC_CONVERSION_MEMORY_CONTROLx
/*Input Channels for Non-Differential Input*/
enum _ConversionChannel {
	NO_CH = 0x20, A0 = 0x00, A1 = 0x01, A2 = 0x02, A3 = 0x03,
	A4 = 0x04, A5 = 0x05, A6 = 0x06, A7 = 0x07,
	A8 = 0x08, A9 = 0x09, A10 = 0x0A, A11 = 0x0B,
	A12 = 0x0C, A13 = 0x0D, A14 = 0x0E, A15 = 0x0F,
	A16 = 0x10, A17 = 0x11, A18 = 0x12, A19 = 0x13,
	A20 = 0x14, A21 = 0x15, A22 = 0x16, A23 = 0x17,
	A24 = 0x18, A25 = 0x19, A26 = 0x1A, A27 = 0x1B,
	A28 = 0x1C, A29 = 0x1D, A30 = 0x1E, A31 = 0x1F
	
};

/*Input Channels for Differential Signal Input*/
enum _DiffSignal_ConvChannel {
	NO_DIF_CH = 0x20, A0POS_A1NEG = 0x00, A2POS_A3NEG = 0x02, 
	A4POS_A5NEG = 0x04, A6POS_A7NEG = 0x06, A8POS_A9NEG = 0x08, 
	A10POS_A11NEG = 0x0A, A12POS_A13NEG = 0x0C, A14POS_A15NEG = 0x0E, 
	A16POS_A17NEG = 0x10, A18POS_A19NEG = 0x12, A20POS_A21NEG = 0x14, 
	A22POS_A23NEG = 0x16, A24POS_A25NEG = 0x18, A26POS_A27NEG = 0x1A, 
	A28POS_A29NEG = 0x1C, A30POS_A31NEG = 0x1E
};

enum _ConversionMemory {
	MEM0 = 0x0, MEM1 = 0x1, MEM2 = 0x2, MEM3 = 0x3,
	MEM4 = 0x4, MEM5 = 0x5, MEM6 = 0x6, MEM7 = 0x7,
	MEM8 = 0x8, MEM9 = 0x9, MEM10 = 0x0A, MEM11 = 0x0B,
	MEM12 = 0x0C, MEM13 = 0x0D, MEM14 = 0x0E, MEM15 = 0x0F,
	MEM16 = 0x10, MEM17 = 0x11, MEM18 = 0x12, MEM19 = 0x13,
	MEM20 = 0x14, MEM21 = 0x15, MEM22 = 0x16, MEM23 = 0x17,
	MEM24 = 0x18, MEM25 = 0x19, MEM26 = 0x1A, MEM27 = 0x1B,
	MEM28 = 0x1C, MEM29 = 0x1D, MEM30 = 0x1E, MEM31 = 0x1F
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

struct _adc {
	ADC_CONTROL0 ControlReg0; // 0x00
	ADC_CONTROL1 ControlReg1; // 0x02
	ADC_CONTROL2 ControlReg2; // 0x04
	ADC_CONTROL3 ControlReg3; // 0x06
	ADC_WINDOW_COMPARATOR_LOW_THRESHOLD WindowCompLowThreshReg; // 0x08
	ADC_WINDOW_COMPARATOR_HIGH_THRESHOLD WindowCompHighThreshReg; // 0x0A
	ADC_INTERRUPT_FLAG0 InterruptFlagReg0; // 0x0C
	ADC_INTERRUPT_FLAG1 InterruptFlagReg1; // 0x0E
	ADC_INTERRUPT_FLAG2 InterruptFlagReg2; // 0x10
	ADC_INTERRUPT_ENABLE0 InterruptEnableReg0; // 0x12
	ADC_INTERRUPT_ENABLE1 InterruptEnableReg1; // 0x14
	ADC_INTERRUPT_ENABLE2 InterruptEnableReg2; // 0x16
	ADC_INTERRUPT_VECTOR InterruptVector; // 0x18
};

struct _conversion_mem_ctrl {
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl0Reg; // 0x20
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl1Reg; // 0x22
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl2Reg; // 0x24
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl3Reg; // 0x26
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl4Reg; // 0x28
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl5Reg; // 0x2A
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl6Reg; // 0x2C
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl7Reg; // 0x2E
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl8Reg; // 0x30
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl9Reg; // 0x32
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl10Reg; // 0x34
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl11Reg; // 0x36
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl12Reg; // 0x38
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl13Reg; // 0x3A
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl14Reg; // 0x3C
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl15Reg; // 0x3E
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl16Reg; // 0x40
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl17Reg; // 0x42
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl18Reg; // 0x44
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl19Reg; // 0x46
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl20Reg; // 0x48
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl21Reg; // 0x4A
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl22Reg; // 0x4C
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl23Reg; // 0x4E
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl24Reg; // 0x50
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl25Reg; // 0x52
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl26Reg; // 0x54
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl27Reg; // 0x56
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl28Reg; // 0x58
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl29Reg; // 0x5A
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl30Reg; // 0x5C
	ADC_CONVERSION_MEMORY_CONTROLx ConversionMemControl31Reg; // 0x5E
};

struct _conversion_mem {
	ADC_CONVERSION_MEMORYx ConversionMem0Reg; // 0x60
	ADC_CONVERSION_MEMORYx ConversionMem1Reg; // 0x62
	ADC_CONVERSION_MEMORYx ConversionMem2Reg; // 0x64
	ADC_CONVERSION_MEMORYx ConversionMem3Reg; // 0x66
	ADC_CONVERSION_MEMORYx ConversionMem4Reg; // 0x68
	ADC_CONVERSION_MEMORYx ConversionMem5Reg; // 0x6A
	ADC_CONVERSION_MEMORYx ConversionMem6Reg; // 0x6C
	ADC_CONVERSION_MEMORYx ConversionMem7Reg; // 0x6E
	ADC_CONVERSION_MEMORYx ConversionMem8Reg; // 0x70
	ADC_CONVERSION_MEMORYx ConversionMem9Reg; // 0x72
	ADC_CONVERSION_MEMORYx ConversionMem10Reg; // 0x74
	ADC_CONVERSION_MEMORYx ConversionMem11Reg; // 0x76
	ADC_CONVERSION_MEMORYx ConversionMem12Reg; // 0x78
	ADC_CONVERSION_MEMORYx ConversionMem13Reg; // 0x7A
	ADC_CONVERSION_MEMORYx ConversionMem14Reg; // 0x7C
	ADC_CONVERSION_MEMORYx ConversionMem15Reg; // 0x7E
	ADC_CONVERSION_MEMORYx ConversionMem16Reg; // 0x80
	ADC_CONVERSION_MEMORYx ConversionMem17Reg; // 0x82
	ADC_CONVERSION_MEMORYx ConversionMem18Reg; // 0x84
	ADC_CONVERSION_MEMORYx ConversionMem19Reg; // 0x86
	ADC_CONVERSION_MEMORYx ConversionMem20Reg; // 0x88
	ADC_CONVERSION_MEMORYx ConversionMem21Reg; // 0x8A
	ADC_CONVERSION_MEMORYx ConversionMem22Reg; // 0x8C
	ADC_CONVERSION_MEMORYx ConversionMem23Reg; // 0x8E
	ADC_CONVERSION_MEMORYx ConversionMem24Reg; // 0x90
	ADC_CONVERSION_MEMORYx ConversionMem25Reg; // 0x92
	ADC_CONVERSION_MEMORYx ConversionMem26Reg; // 0x94
	ADC_CONVERSION_MEMORYx ConversionMem27Reg; // 0x96
	ADC_CONVERSION_MEMORYx ConversionMem28Reg; // 0x98
	ADC_CONVERSION_MEMORYx ConversionMem29Reg; // 0x9A
	ADC_CONVERSION_MEMORYx ConversionMem30Reg; // 0x9C
	ADC_CONVERSION_MEMORYx ConversionMem31Reg; // 0x9E
};

union mem_ctrl_access {
	CONVERSION_MEM_CTRL ConversionMemCtrl;
	
	ADC_CONVERSION_MEMORY_CONTROLx RegisterAccess[32];
};

union mem_access {
	CONVERSION_MEM ConversionMemCtrl;
	
	ADC_CONVERSION_MEMORYx RegisterAccess[32];
};

#endif
