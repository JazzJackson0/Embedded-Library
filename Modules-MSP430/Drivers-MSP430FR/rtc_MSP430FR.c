#include <stdint.h>
//#include <stdio.h>
#include "rtc_MSP430FR.h"


//Global Variables-------------------------------------------------------
RTC_CONTROL1 *const rtcControl1 = ADDR_RTCB_CONTROL1;
RTC_CONTROL2 *const rtcControl2 = ADDR_RTCB_CONTROL2;
RTC_CONTROL3 *const rtcControl3 = ADDR_RTCB_CONTROL3;
RTC_SECONDS_BCD *const seconds = ADDR_RTCB_SECONDS_BCD;
RTC_MINUTES_BCD *const minutes = ADDR_RTCB_MINUTES_BCD;
RTC_HOURS_BCD *const hours = ADDR_RTCB_HOURS_BCD;
RTC_DAYOFWEEK *const dayOfWeek = ADDR_RTCB_DAYOFWEEK;
RTC_DAYOFMONTH_BCD *const dayOfMonth = ADDR_RTCB_DAYOFMONTH_BCD;
RTC_MONTH_BCD *const months = ADDR_RTCB_MONTH_BCD;
RTC_YEAR_BCD *const years = ADDR_RTCB_YEAR_BCD;
RTC_MINUTESALARM_BCD *const minuteAlarm = ADDR_RTCB_MINUTESALARM_BCD;
RTC_HOURSALARM_BCD *const hourAlarm = ADDR_RTCB_HOURSALARM_BCD;
RTC_DAYOFWEEK_ALARM *const dayOfWeekAlarm = ADDR_RTCB_DAYOFWEEK_ALARM;
RTC_DAYOFMONTH_ALARM_BCD *const dayOfMonthAlarm = ADDR_RTCB_DAYOFMONTH_ALARM_BCD;

void RTC_Init(void) {
	
	//Turn Off Watchdog Timer
	Watchdog_Off();
	rtcControl1->enable_BCDCounting = 1;
}

void Set_Time(uint8_t hour, uint8_t minute, uint8_t second) {
	
	seconds->rw_SecondsLowDigit = (second < 10) ? second : second % 10;
	seconds->rw_SecondsHighDigit = (second < 10) ? 0 : second / 10;
	minutes->rw_MinutesLowDigit = (minute < 10) ? minute : minute % 10;
	minutes->rw_MinutesHighDigit = (minute < 10) ? 0 : minute / 10;
	hours->rw_HoursLowDigit = (hour < 10) ? hour : hour % 10;
	hours->rw_HoursHighDigit = (hour < 10) ? 0 : hour / 10;
}

void Set_Date(uint8_t day, uint8_t month, uint8_t weekday, uint8_t yearCentury, uint8_t yearTens, uint8_t yearUnits) {
	
	dayOfWeek->rw_DayOfWeek = weekday;
	dayOfMonth->rw_DayOfMonthLowDigit = (day < 10) ? day : day % 10;
	dayOfMonth->rw_DayOfMonthHighDigit = (day < 10) ? 0 : day / 10;
	months->rw_MonthsLowDigit = (month < 10) ? month : month % 10;
	months->rw_MonthsHighDigit = (month < 10) ? 0 : month / 10;
	years->rw_YearLowestDigit = yearUnits; 
	years->rw_Decade = yearTens;
	years->rw_CenturyLowDigit = (yearCentury < 10) ? yearCentury : yearCentury % 10;
	years->rw_CenturyHighDigit = (yearCentury < 10) ? 0 : yearCentury / 10;
}

void Set_TimeAlarm(uint8_t hour, uint8_t minute) {

	minuteAlarm->rw_MinutesLowDigit = (minute < 10) ? minute : minute % 10;
	minuteAlarm->rw_MinutesHighDigit = (minute < 10) ? 0 : minute / 10;
	minuteAlarm->enable_MinutesAlarm = 1;
	hourAlarm->rw_HoursLowDigit = (hour < 10) ? hour : hour % 10;
	hourAlarm->rw_HoursHighDigit = (hour < 10) ? 0 : hour / 10;
	hourAlarm->enable_HoursAlarm = 1;
}


void Set_DateAlarm(uint8_t weekday, uint8_t monthDay) {

	dayOfWeekAlarm->rw_DayOfWeek = weekday;
	dayOfWeekAlarm->enable_DayOfWeekAlarm = 1;
	dayOfMonthAlarm->rw_DayOfMonthLowDigit = (monthDay < 10) ? monthDay : monthDay % 10;
	dayOfMonthAlarm->rw_DayOfMonthHighDigit = (monthDay < 10) ? 0 : monthDay / 10;
	dayOfMonthAlarm->enable_DayOfMonthAlarm = 1;
}

void Get_Time(void) { 
	
	if (rtcControl1->rtcReady == 1) {
		
		uint8_t second2 = seconds->rw_SecondsLowDigit;
		uint8_t second1 = seconds->rw_SecondsHighDigit;
		uint8_t minute2 = minutes->rw_MinutesLowDigit;
		uint8_t minute1 = minutes->rw_MinutesHighDigit;
		uint8_t hour2 = hourAlarm->rw_HoursLowDigit;
		uint8_t hour1 = hourAlarm->rw_HoursHighDigit;
	
		//printf("%u%u:%u%u:%u%u", hour1, hour2, minute1, minute2, second1, second2);
	}
}

void Get_Date(void) { 
	
	if (rtcControl1->rtcReady == 1) {
		
		uint8_t date2 = dayOfMonth->rw_DayOfMonthLowDigit;
		uint8_t date1 = dayOfMonth->rw_DayOfMonthHighDigit;
		uint8_t month2 = months->rw_MonthsLowDigit;
		uint8_t month1 = months->rw_MonthsHighDigit;
		uint8_t weekday = dayOfWeek->rw_DayOfWeek;
		uint8_t year4 = years->rw_YearLowestDigit;
		uint8_t year3 = years->rw_Decade;
		uint8_t year2 = years->rw_CenturyLowDigit;
		uint8_t year1 = years->rw_CenturyHighDigit;
		char *weekString;
		
		switch (weekday) {
			case 0 : 
				weekString = "Sunday";
				break;
			case 1 : 
				weekString = "Monday";
				break;
			case 2 : 
				weekString = "Tuesday";
				break;
			case 3 : 
				weekString = "Wednesday";
				break;
			case 4 : 
				weekString = "Thursday";
				break;
			case 5 : 
				weekString = "Friday";
				break;
			case 6 : 
				weekString = "Saturday";
				break;
		}
		
		//printf("%s: %u%u/%u%u/%u%u%u%u", weekString, month1, month2, date1, date2, year1, year2, year3, year4 );
	}
}

