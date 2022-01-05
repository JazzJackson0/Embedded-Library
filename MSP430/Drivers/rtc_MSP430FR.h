//MSP430FR59xx Driver
#ifndef RTC_H_
#define RTC_H_
#include <stdint.h>

void RTC_Init(void);
void Set_Time(uint8_t hour, uint8_t minute, uint8_t second);
void Set_Date(uint8_t day, uint8_t month, uint8_t weekday, uint8_t yearCentury, uint8_t yearTens, uint8_t yearUnits);
void Set_TimeAlarm(uint8_t hour, uint8_t minute);
void Set_DateAlarm(uint8_t weekday, uint8_t monthDay);
void Get_Time(void);
void Get_Date(void);


//x69 Series only uses RTC B

/*RTC Pins ----------------------------------
		+ RTC Clock Calibration Output: P1-0 	[(Secondary Function)-(Direction Pin: 1)]
		------------------------------------*/

/*RTC_B only supports Calendar Mode, not Counter Mode*/
/*RTC_C supports Calendar Mode and Counter Mode, as well as offset calibration, and temperature compensation.*/

#define RTC_B 0x04A0
//#define RTC_C 0x

//RTC B
#define ADDR_RTCB_CONTROL0 ( (RTC_CONTROL0*) ((RTC_B) + 0x00) ) //RTC_C_CONTROL_LOW Register Corresponds with this.

#define ADDR_RTCB_CONTROL1 ( (RTC_CONTROL1*) ((RTC_B) + 0x01) )
#define ADDR_RTCB_CONTROL2 ( (RTC_CONTROL2*) ((RTC_B) + 0x02) )
#define ADDR_RTCB_CONTROL3 ( (RTC_CONTROL3*) ((RTC_B) + 0x03) )

#define ADDR_RTCB_SECONDS_HEX ( (RTC_SECONDS_HEX*) ((RTC_B) + 0x10) )
#define ADDR_RTCB_SECONDS_BCD ( (RTC_SECONDS_BCD*) ((RTC_B) + 0x10) )
#define ADDR_RTCB_MINUTES_HEX ( (RTC_MINUTES_HEX*) ((RTC_B) + 0x11) )
#define ADDR_RTCB_MINUTES_BCD ( (RTC_MINUTES_BCD*) ((RTC_B) + 0x11) )
#define ADDR_RTCB_HOURS_HEX ( (RTC_HOURS_HEX*) ((RTC_B) + 0x12) )
#define ADDR_RTCB_HOURS_BCD ( (RTC_HOURS_BCD*) ((RTC_B) + 0x12) )
#define ADDR_RTCB_DAYOFWEEK ( (RTC_DAYOFWEEK*) ((RTC_B) + 0x13) )
#define ADDR_RTCB_DAYOFMONTH_HEX ( (RTC_DAYOFMONTH_HEX*) ((RTC_B) + 0x14) )
#define ADDR_RTCB_DAYOFMONTH_BCD ( (RTC_DAYOFMONTH_BCD*) ((RTC_B) + 0x14) )
#define ADDR_RTCB_MONTH_HEX ( (RTC_MONTH_HEX*) ((RTC_B) + 0x15) )
#define ADDR_RTCB_MONTH_BCD ( (RTC_MONTH_BCD*) ((RTC_B) + 0x15) )
#define ADDR_RTCB_YEAR_HEX ( (RTC_YEAR_HEX*) ((RTC_B) + 016x) )
#define ADDR_RTCB_YEAR_BCD ( (RTC_YEAR_BCD*) ((RTC_B) + 0x16) )
#define ADDR_RTCB_MINUTESALARM_HEX ( (RTC_MINUTESALARM_HEX*) ((RTC_B) + 0x18) )
#define ADDR_RTCB_MINUTESALARM_BCD ( (RTC_MINUTESALARM_BCD*) ((RTC_B) + 0x18) )
#define ADDR_RTCB_HOURSALARM_HEX ( (RTC_HOURSALARM_HEX*) ((RTC_B) + 0x19) )
#define ADDR_RTCB_HOURSALARM_BCD ( (RTC_HOURSALARM_BCD*) ((RTC_B) + 0x19) )
#define ADDR_RTCB_DAYOFWEEK_ALARM ( (RTC_DAYOFWEEK_ALARM*) ((RTC_B) + 0x1A) )
#define ADDR_RTCB_DAYOFMONTH_ALARM_HEX ( (RTC_DAYOFMONTH_ALARM_HEX*) ((RTC_B) + 0x1B) )
#define ADDR_RTCB_DAYOFMONTH_ALARM_BCD ( (RTC_DAYOFMONTH_ALARM_BCD*) ((RTC_B) + 0x1B) )

#define ADDR_RTCB_PRESCALE_TIMER0_CONTROL ( (RTC_PRESCALE_TIMER0_CONTROL*) ((RTC_B) + 0x08) )
#define ADDR_RTCB_PRESCALE_TIMER1_CONTROL ( (RTC_PRESCALE_TIMER1_CONTROL*) ((RTC_B) + 0x0A) )

#define ADDR_RTCB_PRESCALE_TIMER0_COUNTER ( (RTC_PRESCALE_TIMER0_COUNTER*) ((RTC_B) + 0x0C) )
#define ADDR_RTCB_PRESCALE_TIMER1_COUNTER ( (RTC_PRESCALE_TIMER1_COUNTER*) ((RTC_B) + 0x0D) )
#define ADDR_RTCB_INTERRUPT_VECTOR ( (RTC_INTERRUPT_VECTOR*) ((RTC_B) + 0x0E) )
#define ADDR_RTCB_BINARY_TO_BCD ( (RTC_BINARY_TO_BCD*) ((RTC_B) + 0x1C) )
#define ADDR_RTCB_BCD_TO_BINARY ( (RTC_BCD_TO_BINARY*) ((RTC_B) + 0x1E) )



//RTC C
#define ADDR_RTC_CONTROL0 ( (RTC_CONTROL0*) ((RTC_C) + 0x00) ) //RTC_C_CONTROL_LOW Register Corresponds with this.

#define ADDR_RTC_CONTROL0_HIGH ( (RTC_CONTROL0_HIGH*) ((RTC_C) + 0x01) )
#define ADDR_RTC_C_CONTROL1 ( (RTC_C_CONTROL1*) ((RTC_C) + 0x02) )
#define ADDR_RTC_C_CONTROL3 ( (RTC_C_CONTROL3*) ((RTC_C) + 0x03) )
#define ADDR_RTC_OFFSET_CALIBRATION ( (RTC_OFFSET_CALIBRATION*) ((RTC_C) + 0x04) )
#define ADDR_RTC_TEMP_COMP ( (RTC_TEMP_COMP*) ((RTC_C) + 0x06) )
#define ADDR_RTC_COUNTER1 ( (RTC_COUNTER1*) ((RTC_C) + 0x10) )
#define ADDR_RTC_COUNTER2 ( (RTC_COUNTER2*) ((RTC_C) + 0x11) )
#define ADDR_RTC_COUNTER3 ( (RTC_COUNTER3*) ((RTC_C) + 0x12) )
#define ADDR_RTC_COUNTER4 ( (RTC_COUNTER4*) ((RTC_C) + 0x13) )

#define ADDR_RTCC_SECONDS_HEX ( (RTC_SECONDS_HEX*) ((RTC_C) + 0x10) )
#define ADDR_RTCC_SECONDS_BCD ( (RTC_SECONDS_BCD*) ((RTC_C) + 0x10) )
#define ADDR_RTCC_MINUTES_HEX ( (RTC_MINUTES_HEX*) ((RTC_C) + 0x11) )
#define ADDR_RTCC_MINUTES_BCD ( (RTC_MINUTES_BCD*) ((RTC_C) + 0x11) )
#define ADDR_RTCC_HOURS_HEX ( (RTC_HOURS_HEX*) ((RTC_C) + 0x12) )
#define ADDR_RTCC_HOURS_BCD ( (RTC_HOURS_BCD*) ((RTC_C) + 0x12) )
#define ADDR_RTCC_DAYOFWEEK ( (RTC_DAYOFWEEK*) ((RTC_C) + 0x13) )
#define ADDR_RTCC_DAYOFMONTH_HEX ( (RTC_DAYOFMONTH_HEX*) ((RTC_C) + 0x14) )
#define ADDR_RTCC_DAYOFMONTH_BCD ( (RTC_DAYOFMONTH_BCD*) ((RTC_C) + 0x14) )
#define ADDR_RTCC_MONTH_HEX ( (RTC_MONTH_HEX*) ((RTC_C) + 0x15) )
#define ADDR_RTCC_MONTH_BCD ( (RTC_MONTH_BCD*) ((RTC_C) + 0x15) )
#define ADDR_RTCC_YEAR_HEX ( (RTC_YEAR_HEX*) ((RTC_C) + 016x) )
#define ADDR_RTCC_YEAR_BCD ( (RTC_YEAR_BCD*) ((RTC_C) + 0x16) )
#define ADDR_RTCC_MINUTESALARM_HEX ( (RTC_MINUTESALARM_HEX*) ((RTC_C) + 0x18) )
#define ADDR_RTCC_MINUTESALARM_BCD ( (RTC_MINUTESALARM_BCD*) ((RTC_C) + 0x18) )
#define ADDR_RTCC_HOURSALARM_HEX ( (RTC_HOURSALARM_HEX*) ((RTC_C) + 0x19) )
#define ADDR_RTCC_HOURSALARM_BCD ( (RTC_HOURSALARM_BCD*) ((RTC_C) + 0x19) )
#define ADDR_RTCC_DAYOFWEEK_ALARM ( (RTC_DAYOFWEEK_ALARM*) ((RTC_C) + 0x1A) )
#define ADDR_RTCC_DAYOFMONTH_ALARM_HEX ( (RTC_DAYOFMONTH_ALARM_HEX*) ((RTC_C) + 0x1B) )
#define ADDR_RTCC_DAYOFMONTH_ALARM_BCD ( (RTC_DAYOFMONTH_ALARM_BCD*) ((RTC_C) + 0x1B) )

#define ADDR_RTCC_PRESCALE_TIMER0_CONTROL ( (RTC_PRESCALE_TIMER0_CONTROL*) ((RTC_C) + 0x08) )
#define ADDR_RTCC_PRESCALE_TIMER1_CONTROL ( (RTC_PRESCALE_TIMER1_CONTROL*) ((RTC_C) + 0x0A) )

#define ADDR_RTCC_PRESCALE_TIMER0_COUNTER ( (RTC_PRESCALE_TIMER0_COUNTER*) ((RTC_C) + 0x0C) )
#define ADDR_RTCC_PRESCALE_TIMER1_COUNTER ( (RTC_PRESCALE_TIMER1_COUNTER*) ((RTC_C) + 0x0D) )
#define ADDR_RTCC_INTERRUPT_VECTOR ( (RTC_INTERRUPT_VECTOR*) ((RTC_C) + 0x0E) )
#define ADDR_RTCC_BINARY_TO_BCD ( (RTC_BINARY_TO_BCD*) ((RTC_C) + 0x1C) )
#define ADDR_RTCC_BCD_TO_BINARY ( (RTC_BCD_TO_BINARY*) ((RTC_C) + 0x1E) )

#define ADDR_RTC_SECONDS_HEX_BKUP0 ( (RTC_SECONDS_HEX_BKUP*) ((RTC_C) + 0x30) )
#define ADDR_RTC_SECONDS_BCD_BKUP0 ( (RTC_SECONDS_BCD_BKUP*) ((RTC_C) + 0x30) )
#define ADDR_RTC_MINUTES_HEX_BKUP0 ( (RTC_MINUTES_HEX_BKUP*) ((RTC_C) + 0x31) )
#define ADDR_RTC_MINUTES_BCD_BKUP0 ( (RTC_MINUTES_BCD_BKUP*) ((RTC_C) + 0x31) )
#define ADDR_RTC_HOURS_HEX_BKUP0 ( (RTC_HOURS_HEX_BKUP*) ((RTC_C) + 0x32) )
#define ADDR_RTC_HOURS_BCD_BKUP0 ( (RTC_HOURS_BCD_BKUP*) ((RTC_C) + 0x32) )
#define ADDR_RTC_DAYOFMONTH_HEX_BKUP0 ( (RTC_DAYOFMONTH_HEX_BKUP*) ((RTC_C) + 0x33) )
#define ADDR_RTC_DAYOFMONTH_BCD_BKUP0 ( (RTC_DAYOFMONTH_BCD_BKUP*) ((RTC_C) + 0x33) )
#define ADDR_RTC_MONTH_HEX_BKUP0 ( (RTC_MONTH_HEX_BKUP*) ((RTC_C) + 0x34) )
#define ADDR_RTC_MONTH_BCD_BKUP0 ( (RTC_MONTH_BCD_BKUP*) ((RTC_C) + 0x34) )
#define ADDR_RTC_YEAR_HEX_BKUP0 ( (RTC_YEAR_HEX_BKUP*) ((RTC_C) + 0x36) )
#define ADDR_RTC_YEAR_BCD_BKUP0 ( (RTC_YEAR_BCD_BKUP*) ((RTC_C) + 0x36) )

#define ADDR_RTC_MINUTESALARM_HEX_BKUP ( (RTC_MINUTESALARM_HEX_BKUP*) ((RTC_C) + 0x00) ) //Offset Not 0x00 LOOK FOR THESE
#define ADDR_RTC_MINUTESALARM_BCD_BKUP ( (RTC_MINUTESALARM_BCD_BKUP*) ((RTC_C) + 0x00) ) //Offset Not 0x00 LOOK FOR THESE
#define ADDR_RTC_HOURSALARM_HEX_BKUP ( (RTC_HOURSALARM_HEX_BKUP*) ((RTC_C) + 0x00) ) //Offset Not 0x00 LOOK FOR THESE
#define ADDR_RTC_HOURSALARM_BCD_BKUP ( (RTC_HOURSALARM_BCD_BKUP*) ((RTC_C) + 0x00) ) //Offset Not 0x00 LOOK FOR THESE
#define ADDR_RTC_DAYOFWEEK_ALARM_BKUP ( (RTC_DAYOFWEEK_ALARM_BKUP*) ((RTC_C) + 0x00) ) //Offset Not 0x00 LOOK FOR THESE
#define ADDR_RTC_DAYOFMONTH_ALARM_HEX_BKUP ( (RTC_DAYOFMONTH_ALARM_HEX_BKUP*) ((RTC_C) + 0x00) ) //Offset Not 0x00 LOOK FOR THESE
#define ADDR_RTC_DAYOFMONTH_ALARM_BCD_BKUP ( (RTC_DAYOFMONTH_ALARM_BCD_BKUP*) ((RTC_C) + 0x00) ) //Offset Not 0x00 LOOK FOR THESE

#define ADDR_RTC_TIME_CAPTURECONTROL0 ( (RTC_TIME_CAPTURECONTROL0*) ((RTC_C) + 0x20) )
#define ADDR_RTC_TIME_CAPTURECONTROL1 ( (RTC_TIME_CAPTURECONTROL1*) ((RTC_C) + 0x21) )
#define ADDR_RTC_DETECTPIN_CONTROL0 ( (RTC_DETECTPIN_CONTROL*) ((RTC_C) + 0x22) )
#define ADDR_RTC_DETECTPIN_CONTROL1 ( (RTC_DETECTPIN_CONTROL*) ((RTC_C) + 0x23) )


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

typedef struct {
	volatile uint8_t rw_Counter1Value:8;
}RTC_COUNTER1;

typedef struct {
	volatile uint8_t rw_Counter2Value:8;
}RTC_COUNTER2;

typedef struct {
	volatile uint8_t rw_Counter3Value:8;
}RTC_COUNTER3;

typedef struct {
	volatile uint8_t rw_Counter4Value:8;
}RTC_COUNTER4;


/*RTC_B AND RTC_C
--------------------------------------------------*/
typedef struct {
	volatile uint8_t rw_Seconds:6;
	const uint8_t reserved:2;
}RTC_SECONDS_HEX;

typedef struct {
	volatile uint8_t rw_SecondsLowDigit:4;
	volatile uint8_t rw_SecondsHighDigit:3;
	const uint8_t reserved:1;
}RTC_SECONDS_BCD;

typedef struct {
	volatile uint8_t rw_Minutes:6;
	const uint8_t reserved:2;
}RTC_MINUTES_HEX;

typedef struct {
	volatile uint8_t rw_MinutesLowDigit:4;
	volatile uint8_t rw_MinutesHighDigit:3;
	const uint8_t reserved:1;
}RTC_MINUTES_BCD;

typedef struct {
	volatile uint8_t rw_Hours:5;
	const uint8_t reserved:3;
}RTC_HOURS_HEX;

typedef struct {
	volatile uint8_t rw_HoursLowDigit:4;
	volatile uint8_t rw_HoursHighDigit:2;
	const uint8_t reserved:2;
}RTC_HOURS_BCD;

typedef struct {
	volatile uint8_t rw_DayOfWeek:3;
	const uint8_t reserved:5;
}RTC_DAYOFWEEK;

typedef struct {
	volatile uint8_t rw_DayOfMonth:5;
	const uint8_t reserved:3;
}RTC_DAYOFMONTH_HEX;

typedef struct {
	volatile uint8_t rw_DayOfMonthLowDigit:4;
	volatile uint8_t rw_DayOfMonthHighDigit:2;
	const uint8_t reserved:2;
}RTC_DAYOFMONTH_BCD;

typedef struct {
	volatile uint8_t rw_Months:4;
	const uint8_t reserved:4;
}RTC_MONTH_HEX;

typedef struct {
	volatile uint8_t rw_MonthsLowDigit:4;
	volatile uint8_t rw_MonthsHighDigit:1;
	const uint8_t reserved:3;
}RTC_MONTH_BCD;

typedef struct {
	volatile uint16_t rw_YearLowByte:8;
	volatile uint16_t rw_YearHighByte:4;
	const uint16_t reserved:4;
}RTC_YEAR_HEX;

typedef struct {
	volatile uint16_t rw_YearLowestDigit:4;
	volatile uint16_t rw_Decade:4;
	volatile uint16_t rw_CenturyLowDigit:4;
	volatile uint16_t rw_CenturyHighDigit:3;
	const uint16_t reserved:1;
}RTC_YEAR_BCD;

typedef struct {
	volatile uint8_t rw_Minutes:6;
	const uint8_t reserved:1;
	volatile uint8_t enable_MinutesAlarm:1;
}RTC_MINUTESALARM_HEX;

typedef struct {
	volatile uint8_t rw_MinutesLowDigit:4;
	volatile uint8_t rw_MinutesHighDigit:3;
	volatile uint8_t enable_MinutesAlarm:1;
}RTC_MINUTESALARM_BCD;

typedef struct {
	volatile uint8_t rw_Hours:5;
	const uint8_t reserved:2;
	volatile uint8_t enable_HoursAlarm:1;
}RTC_HOURSALARM_HEX;

typedef struct {
	volatile uint8_t rw_HoursLowDigit:4;
	volatile uint8_t rw_HoursHighDigit:2;
	const uint8_t reserved:1;
	volatile uint8_t enable_HoursAlarm:1;
}RTC_HOURSALARM_BCD;

typedef struct {
	volatile uint8_t rw_DayOfWeek:3;
	const uint8_t reserved:4;
	volatile uint8_t enable_DayOfWeekAlarm:1;
}RTC_DAYOFWEEK_ALARM;

typedef struct {
	volatile uint8_t rw_DayOfMonth:5;
	const uint8_t reserved:2;
	volatile uint8_t enable_DayOfMonthAlarm:1;
}RTC_DAYOFMONTH_ALARM_HEX;

typedef struct {
	volatile uint8_t rw_DayOfMonthLowDigit:4;
	volatile uint8_t rw_DayOfMonthHighDigit:2;
	const uint8_t reserved:1;
	volatile uint8_t enable_DayOfMonthAlarm:1;
}RTC_DAYOFMONTH_ALARM_BCD;

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

/*RTC_C Backup Registers
--------------------------------------------------*/
typedef struct {
	volatile uint8_t rw_Seconds:6;
	const uint8_t reserved:2;
}RTC_SECONDS_HEX_BKUP;

typedef struct {
	volatile uint8_t rw_SecondsLowDigit:4;
	volatile uint8_t rw_SecondsHighDigit:3;
	const uint8_t reserved:1;
}RTC_SECONDS_BCD_BKUP;

typedef struct {
	volatile uint8_t rw_Minutes:6;
	const uint8_t reserved:2;
}RTC_MINUTES_HEX_BKUP;

typedef struct {
	volatile uint8_t rw_MinutesLowDigit:4;
	volatile uint8_t rw_MinutesHighDigit:3;
	const uint8_t reserved:1;
}RTC_MINUTES_BCD_BKUP;

typedef struct {
	volatile uint8_t rw_Hours:5;
	const uint8_t reserved:3;
}RTC_HOURS_HEX_BKUP;

typedef struct {
	volatile uint8_t rw_HoursLowDigit:4;
	volatile uint8_t rw_HoursHighDigit:2;
	const uint8_t reserved:2;
}RTC_HOURS_BCD_BKUP;

typedef struct {
	volatile uint8_t rw_DayOfMonth:5;
	const uint8_t reserved:3;
}RTC_DAYOFMONTH_HEX_BKUP;

typedef struct {
	volatile uint8_t rw_DayOfMonthLowDigit:4;
	volatile uint8_t rw_DayOfMonthHighDigit:2;
	const uint8_t reserved:2;
}RTC_DAYOFMONTH_BCD_BKUP;

typedef struct {
	volatile uint8_t rw_Months:4;
	const uint8_t reserved:4;
}RTC_MONTH_HEX_BKUP;

typedef struct {
	volatile uint8_t rw_MonthsLowDigit:4;
	volatile uint8_t rw_MonthsHighDigit:1;
	const uint8_t reserved:3;
}RTC_MONTH_BCD_BKUP;

typedef struct {
	volatile uint16_t rw_YearLowByte:8;
	volatile uint16_t rw_YearHighByte:4;
	const uint16_t reserved:4;
}RTC_YEAR_HEX_BKUP;

typedef struct {
	volatile uint16_t rw_YearLowestDigit:4;
	volatile uint16_t rw_Decade:4;
	volatile uint16_t rw_CenturyLowDigit:4;
	volatile uint16_t rw_CenturyHighDigit:3;
	const uint16_t reserved:1;
}RTC_YEAR_BCD_BKUP;


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

#endif
