//MSP430FR59xx Driver
#ifndef RTC_H_
#define RTC_H_
//x69 Series only uses RTC B

/*RTC Pins ----------------------------------
		+ RTC Clock Calibration Output: P1-0 	[(Secondary Function)-(Direction Pin: 1)]
		------------------------------------*/

#include <stdint.h>

//DECLARATIONS
void RTC_Init(char rtcID);
void Set_Time(char rtcID, uint8_t hour, uint8_t minute, uint8_t second);
//Get yearCentury, yearTens, and yearUnits to be 1 number that you split
void Set_Date(char rtcID, uint8_t day, uint8_t month, uint8_t weekday, uint8_t yearCentury, uint8_t yearTens, uint8_t yearUnits);
void Set_TimeAlarm(char rtcID, uint8_t hour, uint8_t minute);
void Set_DateAlarm(char rtcID, uint8_t weekday, uint8_t monthDay);
void Get_Time(char rtcID);
void Get_Date(char rtcID);

//RTC
typedef struct _rtcB RTCB;
typedef struct _rtcC RTCC;
#define RTC_BASE 0x0400
#define ADDR_RTCB ( (RTCB*) ((RTC_BASE) + 0xA0) )
#define ADDR_RTCC ( (RTCC*) ((RTC_BASE) + 0x00) ) // GET RTC_C ADDRESS
/*RTC_B only supports Calendar Mode, not Counter Mode*/
/*RTC_C supports Calendar Mode and Counter Mode, 
as well as offset calibration, and temperature compensation.*/


//RTC_CONTROL1 Register
/*Interrupt Events*/
#define MINUTE_CHANGED 0x00
#define HOUR_CHANGED 0x01
#define MIDNIGHT_0000 0x02
#define NOON_1200 0x03

//RTC_CONTROL3 Register
/*Calibration Frequency*/
#define NONE 0x00
#define HZ_512 0x01
#define HZ_256 0x02
#define HZ_1 0x03

//RTC_PRESCALE_TIMERx_CONTROL Registers For RTC_B and RTC_C
/*Prescale Timer Interrupt Intervals AND Prescale Timer Clock Divisors*/
#define RTC_DIV_2 0x00
#define RTC_DIV_4 0x01
#define RTC_DIV_8 0x02
#define RTC_DIV_16 0x03
#define RTC_DIV_32 0x04
#define RTC_DIV_64 0x05
#define RTC_DIV_128 0x06
#define RTC_DIV_256 0x07

//RTC_C_CONTROL1
/*RTC Events for Calendar Mode Or Counter Mode*/
#define MIN_CHANGE_OR_8BIT_OVERFLOW 0x00
#define HOUR_CHANGE_OR_16BIT_OVERFLOW 0x01
#define MIDNIGHT0000_OR_24BIT_OVERFLOW 0x02
#define NOON1200_OR_32BIT_OVERFLOW 0x03
/*Clock Source*/
#define CRYSTAL_OSC_32KHZ 0x00
#define OUTPUT_FROM_TIMER1 0x03

//RTC_C_CONTROL3
/*Calibration Frequency*/
#define NO_FREQ 0x00
#define HZ_512 0x01
#define HZ_256 0x02
#define HZ_1 0x03

//RTC_C_PRESCALE_TIMER1_CONTROL
/*Clock Source*/
#define CRYSTAL_OSC_32KHZ 0x00
#define OUTPUT_FROM_TIMER0 0x03


typedef struct {
	const uint16_t reserved:16;
}RTC_RESERVED;


/*RTC_B AND RTC_C
--------------------------------------------------*/
typedef struct {
	volatile uint8_t rtcReadyInterruptOccurred:1;
	volatile uint8_t rtcAlarmInterruptOccurred:1;
	volatile uint8_t rtcTimeEventInterruptOccurred:1;
	volatile uint8_t crystalOscillator32kHzFaultInterruptOccurred:1;
	volatile uint8_t enable_rtcReadyInterrupt:1;
	volatile uint8_t enable_rtcAlarmInterrupt:1;
	volatile uint8_t enable_rtcTimeEventInterrupt:1;
	volatile uint8_t enable_crystalOscillator32kHzFaultInterrupt:1;
}RTC_CONTROL0;


/*CONTROL Registers for RTC_B
--------------------------------------------------*/
typedef struct {
	volatile uint8_t rtc_InterruptEvent:2;
	const uint8_t reserved0:2;
	volatile uint8_t rtcReady:1;
	const uint8_t reserved1:1;
	volatile uint8_t stop_RTC:1;
	volatile uint8_t enable_BCDCounting:1;
}RTC_CONTROL1;

typedef struct {
	volatile uint8_t rw_RTCCalibration:6;
	const uint8_t reserved:1;
	volatile uint8_t frequencyAdjustedUp0_frequencyAdjustedDown1:1;
}RTC_CONTROL2;

typedef struct {
	volatile uint8_t rw_RTCCalibrationFrequency:2;
	const uint8_t reserved:6;
}RTC_CONTROL3;

/*CONTROL Registers for RTC_C
--------------------------------------------------*/

typedef struct {
	volatile uint8_t rtc_CKey:8;
}RTC_CONTROL0_HIGH;

typedef struct {
	volatile uint8_t rw_RTCEventCalendarOrCounterMode:2;
	volatile uint8_t select_ClockSource:2;
	volatile uint8_t rtcReady:1;
	volatile uint8_t counterMode0_calendarMode1:1;
	volatile uint8_t stopCounterORStopCalendar:1;
	volatile uint8_t binaryHex0_BCD1:1;
}RTC_C_CONTROL1;

typedef struct {
	volatile uint8_t rw_CalibrationFrequency:2;
	const uint8_t reserved:6;
}RTC_C_CONTROL3;

typedef struct {
	volatile uint16_t rw_OffsetErrorCalibration:8;
	const uint16_t reserved:7;
	volatile uint16_t downCalibration0_upCalibration:1;
}RTC_OFFSET_CALIBRATION;

typedef struct {
	volatile uint16_t rw_TemperatureCompensation:8;
	const uint16_t reserved:5;
	volatile uint16_t tempCompValueInputSucessfully:1;
	volatile uint16_t tempCompReadyForNewValue:1;
	volatile uint16_t downCalibration0_upCalibration:1;
}RTC_TEMP_COMP;


/*RTC_B AND RTC_C
--------------------------------------------------*/
typedef union {
	struct {
		volatile uint8_t rw_Seconds:6;
		const uint8_t reserved:2;
	}HEX;

	struct {
		volatile uint8_t rw_SecondsLowDigit:4;
		volatile uint8_t rw_SecondsHighDigit:3;
		const uint8_t reserved:1;
	}BCD;
}RTC_SECONDS;

typedef union {
	struct {
		volatile uint8_t rw_Minutes:6;
		const uint8_t reserved:2;
	}HEX;

	struct {
		volatile uint8_t rw_MinutesLowDigit:4;
		volatile uint8_t rw_MinutesHighDigit:3;
		const uint8_t reserved:1;
	}BCD;
}RTC_MINUTES;

typedef union {
	struct {
		volatile uint8_t rw_Hours:5;
		const uint8_t reserved:3;
	}HEX;

	struct {
		volatile uint8_t rw_HoursLowDigit:4;
		volatile uint8_t rw_HoursHighDigit:2;
		const uint8_t reserved:2;
	}BCD;
}RTC_HOURS;


typedef struct {
	volatile uint8_t rw_DayOfWeek:3;
	const uint8_t reserved:5;
}RTC_DAYOFWEEK;


typedef union {
	union {
		struct {
			volatile uint8_t rw_Seconds:6;
			const uint8_t reserved:2;
		}HEX;

		struct {
			volatile uint8_t rw_SecondsLowDigit:4;
			volatile uint8_t rw_SecondsHighDigit:3;
			const uint8_t reserved:1;
		}BCD;
	}Seconds;

	struct {
		volatile uint8_t rw_CounterValue:8;
	}Counter1;
}RTC_SECONDS_OR_COUNT;


typedef union {
	union {
		struct {
			volatile uint8_t rw_Minutes:6;
			const uint8_t reserved:2;
		}HEX;

		struct {
			volatile uint8_t rw_MinutesLowDigit:4;
			volatile uint8_t rw_MinutesHighDigit:3;
			const uint8_t reserved:1;
		}BCD;
	}Minutes;

	struct {
		volatile uint8_t rw_CounterValue:8;
	}Counter2;
}RTC_MINUTES_OR_COUNT;


typedef union {
	union {
		struct {
			volatile uint8_t rw_Hours:5;
			const uint8_t reserved:3;
		}HEX;

		struct {
			volatile uint8_t rw_HoursLowDigit:4;
			volatile uint8_t rw_HoursHighDigit:2;
			const uint8_t reserved:2;
		}BCD;
	}Hours;

	struct {
		volatile uint8_t rw_CounterValue:8;
	}Counter3;
}RTC_HOURS_OR_COUNT;


typedef union {
	struct {
		volatile uint8_t rw_DayOfWeek:3;
		const uint8_t reserved:5;
	}DayOfWeek;

	struct {
		volatile uint8_t rw_CounterValue:8;
	}Counter4;
}RTC_DAYOFWEEK_OR_COUNT;


typedef union {
	struct {
		volatile uint8_t rw_DayOfMonth:5;
		const uint8_t reserved:3;
	}HEX;

	struct {
		volatile uint8_t rw_DayOfMonthLowDigit:4;
		volatile uint8_t rw_DayOfMonthHighDigit:2;
		const uint8_t reserved:2;
	}BCD;
}RTC_DAYOFMONTH;

typedef union {
	struct {
		volatile uint8_t rw_Months:4;
		const uint8_t reserved:4;
	}HEX;

	struct {
		volatile uint8_t rw_MonthsLowDigit:4;
		volatile uint8_t rw_MonthsHighDigit:1;
		const uint8_t reserved:3;
	}BCD;
}RTC_MONTH;

typedef union {
	struct {
		volatile uint16_t rw_YearLowByte:8;
		volatile uint16_t rw_YearHighByte:4;
		const uint16_t reserved:4;
	}HEX;

	struct {
		volatile uint16_t rw_YearLowestDigit:4;
		volatile uint16_t rw_Decade:4;
		volatile uint16_t rw_CenturyLowDigit:4;
		volatile uint16_t rw_CenturyHighDigit:3;
		const uint16_t reserved:1;
	}BCD;
}RTC_YEAR;

typedef union {
	struct {
		volatile uint8_t rw_Minutes:6;
		const uint8_t reserved:1;
		volatile uint8_t enable_MinutesAlarm:1;
	}HEX;

	struct {
		volatile uint8_t rw_MinutesLowDigit:4;
		volatile uint8_t rw_MinutesHighDigit:3;
		volatile uint8_t enable_MinutesAlarm:1;
	}BCD;
}RTC_MINUTESALARM;

typedef union {
	struct {
		volatile uint8_t rw_Hours:5;
		const uint8_t reserved:2;
		volatile uint8_t enable_HoursAlarm:1;
	}HEX;

	struct {
		volatile uint8_t rw_HoursLowDigit:4;
		volatile uint8_t rw_HoursHighDigit:2;
		const uint8_t reserved:1;
		volatile uint8_t enable_HoursAlarm:1;
	}BCD;
}RTC_HOURSALARM;

typedef struct {
	volatile uint8_t rw_DayOfWeek:3;
	const uint8_t reserved:4;
	volatile uint8_t enable_DayOfWeekAlarm:1;
}RTC_DAYOFWEEK_ALARM;

typedef union {
	struct {
		volatile uint8_t rw_DayOfMonth:5;
		const uint8_t reserved:2;
		volatile uint8_t enable_DayOfMonthAlarm:1;
	}HEX;

	struct {
		volatile uint8_t rw_DayOfMonthLowDigit:4;
		volatile uint8_t rw_DayOfMonthHighDigit:2;
		const uint8_t reserved:1;
		volatile uint8_t enable_DayOfMonthAlarm:1;
	}BCD;
}RTC_DAYOFMONTH_ALARM;

/*RTC_PRESCALE_TIMER0_CONTROL Registers for RTC_B
--------------------------------------------------*/
typedef struct {
	volatile uint16_t prescaleTimer0InterruptOccurred:1;
	volatile uint16_t enable_PrescaleTimer0Interrupt:1;
	volatile uint16_t rw_PrescaleTimer0InterruptInterval:3;
	const uint16_t reserved:11;
}RTC_PRESCALE_TIMER0_CONTROL;

typedef struct {
	volatile uint16_t prescaleTimer1InterruptOccurred:1;
	volatile uint16_t enable_PrescaleTimer1Interrupt:1;
	volatile uint16_t rw_PrescaleTimer1InterruptInterval:3;
	const uint16_t reserved:11;
}RTC_PRESCALE_TIMER1_CONTROL;

/*RTC_PRESCALE_TIMER0_CONTROL Registers for RTC_C
--------------------------------------------------*/
typedef struct {
	volatile uint16_t prescaleTimer0InterruptOccurred:1;
	volatile uint16_t enable_PrescaleTimer0Interrupt:1;
	volatile uint16_t rw_PrescaleTimer0InterruptInterval:3;
	const uint16_t reserved0:3;
	volatile uint8_t stop_PrescaleTimer0:1;
	const uint8_t reserved1:2;
	volatile uint16_t rw_PrescaleTimer0ClockDivisor:3;
	const uint8_t reserved2:2;
}RTC_C_PRESCALE_TIMER0_CONTROL;

typedef struct {
	volatile uint16_t prescaleTimer1InterruptOccurred:1;
	volatile uint16_t enable_PrescaleTimer1Interrupt:1;
	volatile uint16_t rw_PrescaleTimer1InterruptInterval:3;
	const uint16_t reserved0:3;
	volatile uint8_t stop_PrescaleTimer1:1;
	const uint8_t reserved1:2;
	volatile uint16_t rw_PrescaleTimer1ClockDivisor:3;
	volatile uint16_t rw_PrescaleTimer1ClockSource:2;
}RTC_C_PRESCALE_TIMER1_CONTROL;


/*RTC_B AND RTC_C
--------------------------------------------------*/
typedef struct {
	volatile uint8_t rw_PrescaleTimer0CounterValue:8; 
}RTC_PRESCALE_TIMER0_COUNTER;  //Automatically configured to provide a 1-s clock interval.

typedef struct {
	volatile uint8_t rw_PrescaleTimer1CounterValue:8;
}RTC_PRESCALE_TIMER1_COUNTER;  //Automatically configured to provide a 1-s clock interval.

typedef struct {
	volatile uint16_t read_HighestPriorityInterruptPending:16;
}RTC_INTERRUPT_VECTOR;

typedef struct {
	volatile uint16_t write12BitBinaryNum_read16BitBCDConversion:16;
}RTC_BINARY_TO_BCD;

typedef struct {
	volatile uint16_t write16BitBCDNum_read12BitBinaryConversion:16;
}RTC_BCD_TO_BINARY;




/*RTC_C More Control Registers
--------------------------------------------------*/
typedef struct {
	volatile uint8_t enable_TamperDetectWithTimeStamp:1;
	volatile uint8_t auxvcc3PowerCycleEnabled:1;
	const uint8_t reserved:6;
}RTC_TIME_CAPTURECONTROL0;

typedef struct {
	volatile uint8_t tamperEventOccurred:1;
	volatile uint8_t enable_TamperEventInterrupt:1;
	const uint8_t reserved:6;
}RTC_TIME_CAPTURECONTROL1;

typedef struct {
	volatile uint8_t tamperEventOccurred:1;
	const uint8_t reserved0:1;
	volatile uint8_t eventOnRiseEdge0_eventOnFallEdge1:1;
	volatile uint8_t enable_PullUpPullDown:1;
	volatile uint8_t inputIsHigh:1;
	volatile uint8_t rtccapPinxAsInput0_rtccapPinxAsOutput1:1;
	volatile uint8_t outputLow0_outputHigh1:1;
	const uint8_t reserved1:1;
}RTC_DETECTPIN_CONTROL;

struct _rtcB {
	RTC_CONTROL0 ControlReg0; // 0x00
	RTC_CONTROL1 ControlReg1; // 0x01
	RTC_CONTROL2 ControlReg2; // 0x02
	RTC_CONTROL3 ControlReg3; // 0x03
	RTC_RESERVED reserved0; // 0x04
	RTC_RESERVED reserved1; // 0x06
	RTC_PRESCALE_TIMER0_CONTROL PrescaleTimer0ControlReg; // 0x08
	RTC_PRESCALE_TIMER1_CONTROL PrescaleTimer1ControlReg; // 0x0A
	RTC_PRESCALE_TIMER0_COUNTER PrescaleTimer0CounterReg; // 0x0C
	RTC_PRESCALE_TIMER1_COUNTER PrescaleTimer1CounterReg; // 0x0D
	RTC_INTERRUPT_VECTOR InterruptVectorReg; // 0x0E
	RTC_SECONDS SecondsReg; // 0x10
	RTC_MINUTES MinutesReg; // 0x11
	RTC_HOURS HoursReg; // 0x12
	RTC_DAYOFWEEK DayOfWeekReg; // 0x13
	RTC_DAYOFMONTH DayOfMonthReg; // 0x14
	RTC_MONTH MonthReg; // 0x15
	RTC_YEAR YearReg; // 0x16
	RTC_MINUTESALARM MinutesAlarmReg; // 0x18
	RTC_HOURSALARM HoursAlarmReg; // 0x19
	RTC_DAYOFWEEK_ALARM DayOfWeekAlarmReg; // 0x1A
	RTC_DAYOFMONTH_ALARM DayOfMonthAlarmReg; // 0x1B
	RTC_BINARY_TO_BCD BinaryToBDCReg; // 0x1C
	RTC_BCD_TO_BINARY BCDToBinaryReg; // 0x1E
};

struct _rtcC {
	RTC_CONTROL0 ControlReg0; // 0x00
	RTC_CONTROL0_HIGH ControlHighReg0; // 0x01
	RTC_C_CONTROL1 ControlReg1; // 0x02
	RTC_C_CONTROL3 ControlReg3; // 0x03
	RTC_OFFSET_CALIBRATION OffsetCalibrationReg; // 0x04
	RTC_TEMP_COMP TempCompReg; // 0x06
	RTC_PRESCALE_TIMER1_CONTROL PrescaleTimer1ControlReg; // 0x08
	RTC_PRESCALE_TIMER0_CONTROL PrescaleTimer0ControlReg; // 0x0A
	RTC_PRESCALE_TIMER0_COUNTER PrescaleTimer0CounterReg; // 0x0C
	RTC_PRESCALE_TIMER1_COUNTER PrescaleTimer1CounterReg; // 0x0D
	RTC_INTERRUPT_VECTOR InterruptVectorReg; // 0x0E
	RTC_SECONDS_OR_COUNT SecondsRegOrCountReg1; // 0x10
	RTC_MINUTES_OR_COUNT MinutesRegOrCountReg2; // 0x11
	RTC_HOURS_OR_COUNT HoursRegOrCountReg3; // 0x12
	RTC_DAYOFWEEK_OR_COUNT DayOfWeekRegOrCountReg4; // 0x13
	RTC_DAYOFMONTH DayOfMonthReg; // 0x14
	RTC_MONTH MonthReg; // 0x15
	RTC_YEAR YearReg; // 0x16
	RTC_MINUTESALARM MinutesAlarmReg; // 0x18
	RTC_HOURSALARM HoursAlarmReg; // 0x19
	RTC_DAYOFWEEK_ALARM DayOfWeekAlarmReg; // 0x1A
	RTC_DAYOFMONTH_ALARM DayOfMonthAlarmReg; // 0x1B
	RTC_BINARY_TO_BCD BinaryToBDCReg; // 0x1C
	RTC_BCD_TO_BINARY BCDToBinaryReg; // 0x1E
	RTC_TIME_CAPTURECONTROL0 CaptureControl0Reg; // 0x20
	RTC_TIME_CAPTURECONTROL1 CaptureControl1Reg; // 0x21
	RTC_DETECTPIN_CONTROL DetectPiinControlReg0; // 0x22
	RTC_DETECTPIN_CONTROL DetectPiinControlReg1; // 0x23
	RTC_RESERVED reserved0; // 0x24
	RTC_RESERVED reserved1; // 0x26
	RTC_RESERVED reserved2; // 0x28
	RTC_RESERVED reserved3; // 0x2A
	RTC_RESERVED reserved4; // 0x2C
	RTC_RESERVED reserved5; // 0x2E
	RTC_SECONDS SecondsBackupReg0; // 0x30
	RTC_MINUTES MinutesBackupReg0; // 0x31
	RTC_HOURS HoursBackupReg0; // 0x32
	RTC_DAYOFMONTH DayOfMonthBackupReg0; // 0x33
	RTC_MONTH MonthBackupReg0; // 0x34
	const uint8_t reserved6:8; // 0x35
	RTC_YEAR YearBackupReg0; // 0x36
	RTC_SECONDS SecondsBackupReg1; // 0x38
	RTC_MINUTES MinutesBackupReg1; // 0x39
	RTC_HOURS HoursBackupReg1; // 0x3A
	RTC_DAYOFMONTH DayOfMonthBackupReg1; // 0x3B
	RTC_MONTH MonthBackupReg1; // 0x3C
	const uint8_t reserved7:8; // 0x3D
	RTC_YEAR YearBackupReg1; // 0x3E
};

#endif
