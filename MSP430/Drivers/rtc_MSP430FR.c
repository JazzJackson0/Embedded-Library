#include <stdint.h>
//#include <stdio.h>
#include "rtc_MSP430FR.h"


//Global Variables-------------------------------------------------------
RTCB *const RTC_B = ADDR_RTCB;
RTCC *const RTC_C = ADDR_RTCC;

void RTC_Init(char rtcID) {

	//Turn Off Watchdog Timer
	//Watchdog_Off(); CANT...

	if (rtcID == 'B') { 
		RTCB *const RTC = RTC_B;
		RTC->ControlReg1.enable_BCDCounting = 1; 
	}
	else if (rtcID == 'C') { 
		RTCC *const RTC = RTC_C;
		RTC->ControlReg1.binaryHex0_BCD1 = 1; 
	}
}

void Set_Time(char rtcID, uint8_t hour, uint8_t minute, uint8_t second) {
	
	if (rtcID == 'B') {
		RTCB *const RTC = RTC_B;
		RTC->SecondsReg.BCD.rw_SecondsLowDigit = (second < 10) ? second : second % 10;
		RTC->SecondsReg.BCD.rw_SecondsHighDigit = (second < 10) ? 0 : second / 10;
		RTC->MinutesReg.BCD.rw_MinutesLowDigit = (minute < 10) ? minute : minute % 10;
		RTC->MinutesReg.BCD.rw_MinutesHighDigit = (minute < 10) ? 0 : minute / 10;
		RTC->HoursReg.BCD.rw_HoursLowDigit = (hour < 10) ? hour : hour % 10;
		RTC->HoursReg.BCD.rw_HoursHighDigit = (hour < 10) ? 0 : hour / 10;
	}

	if (rtcID == 'C') {
		RTCC *const RTC = RTC_C;
		RTC->SecondsRegOrCountReg1.Seconds.BCD.rw_SecondsLowDigit = (second < 10) ? second : second % 10;
		RTC->SecondsRegOrCountReg1.Seconds.BCD.rw_SecondsHighDigit = (second < 10) ? 0 : second / 10;
		RTC->MinutesRegOrCountReg2.Minutes.BCD.rw_MinutesLowDigit = (minute < 10) ? minute : minute % 10;
		RTC->MinutesRegOrCountReg2.Minutes.BCD.rw_MinutesHighDigit = (minute < 10) ? 0 : minute / 10;
		RTC->HoursRegOrCountReg3.Hours.BCD.rw_HoursLowDigit = (hour < 10) ? hour : hour % 10;
		RTC->HoursRegOrCountReg3.Hours.BCD.rw_HoursHighDigit = (hour < 10) ? 0 : hour / 10;
	}
}

void Set_Date(char rtcID, uint8_t day, uint8_t month, uint8_t weekday, uint8_t yearCentury, uint8_t yearTens, uint8_t yearUnits) {
	//Get yearCentury, yearTens, and yearUnits to be 1 number that you split
	if (rtcID == 'B') { 
		RTCB *const RTC = RTC_B;
		RTC->DayOfWeekReg.rw_DayOfWeek = weekday;
		RTC->DayOfMonthReg.BCD.rw_DayOfMonthLowDigit = (day < 10) ? day : day % 10;
		RTC->DayOfMonthReg.BCD.rw_DayOfMonthHighDigit = (day < 10) ? 0 : day / 10;
		RTC->MonthReg.BCD.rw_MonthsLowDigit = (month < 10) ? month : month % 10;
		RTC->MonthReg.BCD.rw_MonthsHighDigit = (month < 10) ? 0 : month / 10;
		RTC->YearReg.BCD.rw_YearLowestDigit = yearUnits; 
		RTC->YearReg.BCD.rw_Decade = yearTens;
		RTC->YearReg.BCD.rw_CenturyLowDigit = (yearCentury < 10) ? yearCentury : yearCentury % 10;
		RTC->YearReg.BCD.rw_CenturyHighDigit = (yearCentury < 10) ? 0 : yearCentury / 10;
	}

	else if (rtcID == 'C') { 
		RTCC *const RTC = RTC_C;
		RTC->DayOfWeekRegOrCountReg4.DayOfWeek.rw_DayOfWeek = weekday;
		RTC->DayOfMonthReg.BCD.rw_DayOfMonthLowDigit = (day < 10) ? day : day % 10;
		RTC->DayOfMonthReg.BCD.rw_DayOfMonthHighDigit = (day < 10) ? 0 : day / 10;
		RTC->MonthReg.BCD.rw_MonthsLowDigit = (month < 10) ? month : month % 10;
		RTC->MonthReg.BCD.rw_MonthsHighDigit = (month < 10) ? 0 : month / 10;
		RTC->YearReg.BCD.rw_YearLowestDigit = yearUnits; 
		RTC->YearReg.BCD.rw_Decade = yearTens;
		RTC->YearReg.BCD.rw_CenturyLowDigit = (yearCentury < 10) ? yearCentury : yearCentury % 10;
		RTC->YearReg.BCD.rw_CenturyHighDigit = (yearCentury < 10) ? 0 : yearCentury / 10;
	}
}

void Set_TimeAlarm(char rtcID, uint8_t hour, uint8_t minute) {

	if (rtcID == 'B') { 
		RTCB *const RTC = RTC_B;
		RTC->MinutesAlarmReg.BCD.rw_MinutesLowDigit = (minute < 10) ? minute : minute % 10;
		RTC->MinutesAlarmReg.BCD.rw_MinutesHighDigit = (minute < 10) ? 0 : minute / 10;
		RTC->MinutesAlarmReg.BCD.enable_MinutesAlarm = 1;
		RTC->HoursAlarmReg.BCD.rw_HoursLowDigit = (hour < 10) ? hour : hour % 10;
		RTC->HoursAlarmReg.BCD.rw_HoursHighDigit = (hour < 10) ? 0 : hour / 10;
		RTC->HoursAlarmReg.BCD.enable_HoursAlarm = 1;
	}

	else if (rtcID == 'C') { 
		RTCC *const RTC = RTC_C;
		RTC->MinutesAlarmReg.BCD.rw_MinutesLowDigit = (minute < 10) ? minute : minute % 10;
		RTC->MinutesAlarmReg.BCD.rw_MinutesHighDigit = (minute < 10) ? 0 : minute / 10;
		RTC->MinutesAlarmReg.BCD.enable_MinutesAlarm = 1;
		RTC->HoursAlarmReg.BCD.rw_HoursLowDigit = (hour < 10) ? hour : hour % 10;
		RTC->HoursAlarmReg.BCD.rw_HoursHighDigit = (hour < 10) ? 0 : hour / 10;
		RTC->HoursAlarmReg.BCD.enable_HoursAlarm = 1;
	}
}


void Set_DateAlarm(char rtcID, uint8_t weekday, uint8_t monthDay) {

	if (rtcID == 'B') { 
		RTCB *const RTC = RTC_B;
		RTC->DayOfWeekAlarmReg.rw_DayOfWeek = weekday;
		RTC->DayOfWeekAlarmReg.enable_DayOfWeekAlarm = 1;
		RTC->DayOfMonthAlarmReg.BCD.rw_DayOfMonthLowDigit = (monthDay < 10) ? monthDay : monthDay % 10;
		RTC->DayOfMonthAlarmReg.BCD.rw_DayOfMonthHighDigit = (monthDay < 10) ? 0 : monthDay / 10;
		RTC->DayOfMonthAlarmReg.BCD.enable_DayOfMonthAlarm = 1;
	}

	else if (rtcID == 'C') { 
		RTCC *const RTC = RTC_C;
		RTC->DayOfWeekAlarmReg.rw_DayOfWeek = weekday;
		RTC->DayOfWeekAlarmReg.enable_DayOfWeekAlarm = 1;
		RTC->DayOfMonthAlarmReg.BCD.rw_DayOfMonthLowDigit = (monthDay < 10) ? monthDay : monthDay % 10;
		RTC->DayOfMonthAlarmReg.BCD.rw_DayOfMonthHighDigit = (monthDay < 10) ? 0 : monthDay / 10;
		RTC->DayOfMonthAlarmReg.BCD.enable_DayOfMonthAlarm = 1;
	}
	
}

void Get_Time(char rtcID) { 
	
	if (rtcID == 'B') { 
		RTCB *const RTC = RTC_B;
		if (RTC->ControlReg1.rtcReady == 1) {
			
			uint8_t second2 = RTC->SecondsReg.BCD.rw_SecondsLowDigit;
			uint8_t second1 = RTC->SecondsReg.BCD.rw_SecondsHighDigit;
			uint8_t minute2 = RTC->MinutesReg.BCD.rw_MinutesLowDigit;
			uint8_t minute1 = RTC->MinutesReg.BCD.rw_MinutesHighDigit;
			uint8_t hour2 = RTC->HoursReg.BCD.rw_HoursLowDigit;
			uint8_t hour1 = RTC->HoursReg.BCD.rw_HoursHighDigit;
		
			//printf("%u%u:%u%u:%u%u", hour1, hour2, minute1, minute2, second1, second2);
		}
	}

	else if (rtcID == 'C') { 
		RTCC *const RTC = RTC_C;
		if (RTC->ControlReg1.rtcReady == 1) {
			
			uint8_t second2 = RTC->SecondsRegOrCountReg1.Seconds.BCD.rw_SecondsLowDigit;
			uint8_t second1 = RTC->SecondsRegOrCountReg1.Seconds.BCD.rw_SecondsHighDigit;
			uint8_t minute2 = RTC->MinutesRegOrCountReg2.Minutes.BCD.rw_MinutesLowDigit;
			uint8_t minute1 = RTC->MinutesRegOrCountReg2.Minutes.BCD.rw_MinutesHighDigit;
			uint8_t hour2 = RTC->HoursRegOrCountReg3.Hours.BCD.rw_HoursLowDigit;
			uint8_t hour1 = RTC->HoursRegOrCountReg3.Hours.BCD.rw_HoursHighDigit;
		
			//printf("%u%u:%u%u:%u%u", hour1, hour2, minute1, minute2, second1, second2);
		}
	}
}

void Get_Date(char rtcID) { 
	
	if (rtcID == 'B') { 
		RTCB *const RTC = RTC_B;
		if (RTC->ControlReg1.rtcReady == 1) {
			
			uint8_t date2 = RTC->DayOfMonthReg.BCD.rw_DayOfMonthLowDigit;
			uint8_t date1 = RTC->DayOfMonthReg.BCD.rw_DayOfMonthHighDigit;
			uint8_t month2 = RTC->MonthReg.BCD.rw_MonthsLowDigit;
			uint8_t month1 = RTC->MonthReg.BCD.rw_MonthsHighDigit;
			uint8_t weekday = RTC->DayOfWeekReg.rw_DayOfWeek;
			uint8_t year4 = RTC->YearReg.BCD.rw_YearLowestDigit;
			uint8_t year3 = RTC->YearReg.BCD.rw_Decade;
			uint8_t year2 = RTC->YearReg.BCD.rw_CenturyLowDigit;
			uint8_t year1 = RTC->YearReg.BCD.rw_CenturyHighDigit;
			char **weekString = ((void*)0);
			
			char weekList[][9] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
			for (int i = 0; i < 7; i++) {
				if (i == weekday) { weekString = (char**)(weekList + i); }
			}
			//printf("%s: %u%u/%u%u/%u%u%u%u", weekString, month1, month2, date1, date2, year1, year2, year3, year4 );
		}
	}

	else if (rtcID == 'C') { 
		RTCC *const RTC = RTC_C;
		if (RTC->ControlReg1.rtcReady == 1) {
			
			uint8_t date2 = RTC->DayOfMonthReg.BCD.rw_DayOfMonthLowDigit;
			uint8_t date1 = RTC->DayOfMonthReg.BCD.rw_DayOfMonthHighDigit;
			uint8_t month2 = RTC->MonthReg.BCD.rw_MonthsLowDigit;
			uint8_t month1 = RTC->MonthReg.BCD.rw_MonthsHighDigit;
			uint8_t weekday = RTC->DayOfWeekRegOrCountReg4.DayOfWeek.rw_DayOfWeek;
			uint8_t year4 = RTC->YearReg.BCD.rw_YearLowestDigit;
			uint8_t year3 = RTC->YearReg.BCD.rw_Decade;
			uint8_t year2 = RTC->YearReg.BCD.rw_CenturyLowDigit;
			uint8_t year1 = RTC->YearReg.BCD.rw_CenturyHighDigit;
			char **weekString = ((void*)0);
			
			char weekList[][9] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
			for (int i = 0; i < 7; i++) {
				if (i == weekday) { weekString = (char**)(weekList + i); }
			}
			//printf("%s: %u%u/%u%u/%u%u%u%u", weekString, month1, month2, date1, date2, year1, year2, year3, year4 );
		}
	}
}

