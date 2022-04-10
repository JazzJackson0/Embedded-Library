#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>     // for formatting stdint types 
#include "rtc_STM32F446.h"

//Global Variables-------------------------------------------------------
RTC_CONTROL *const rtcControl = ADDR_RTC_CONTROL;
RTC_TIME *const time = ADDR_RTC_TIME;
RTC_DATE *const date = ADDR_RTC_DATE;
RTC_INITIALIZATION_AND_STATUS *const rtcInitStat = ADDR_RTC_INITIALIZATION_AND_STATUS;
RTC_ALARM_A *const alarmA = ADDR_RTC_ALARM_A;

void RTC_Init(void) {
	
	rtcControl->hour24Form0_hourAMPMForm1 = 1;
	rtcControl->enable_AlarmA = 1;
}

void Set_Time(uint8_t hour, uint8_t minute, uint8_t second, uint8_t amPm) {
	
	time->rw_SecondUnits  = (second < 10) ? second : second % 10;
	time->rw_SecondTens  = (second < 10) ? 0 : second / 10;
	time->rw_MinuteUnits  = (minute < 10) ? minute : minute % 10;
	time->rw_MinuteTens  = (minute < 10) ? 0 : minute / 10;
	time->rw_HourUnits  = (hour < 10) ? hour : hour % 10;
	time->rw_HourTens  = (hour < 10) ? 0 : hour / 10;
	time->amOr24Hour0_pm1  = amPm;
}

void Set_Date(uint8_t day, uint8_t month, uint8_t year, uint8_t weekday) {
	
	date->rw_DateUnits  = (day < 10) ? day : day % 10;
	date->rw_DateTens  = (day < 10) ? 0 : day / 10;
	date->rw_MontUnits  = (month < 10) ? month : month % 10;
	date->rw_MonthTens  = (month < 10) ? 0 : month / 10;
	date->rw_WeekDayUnits  = weekday;
	date->rw_YearUnits  = (year < 10) ? year : year % 10;
	date->rw_YearTens  = (year < 10) ? 0 : year / 10;
}

void Set_TimeAlarm(uint8_t hour, uint8_t minute, uint8_t second, uint8_t amPm) {
	
	alarmA->rw_SecondUnits  = (second < 10) ? second : second % 10;
	alarmA->rw_SecondTens  = (second < 10) ? 0 : second / 10;
	alarmA->rw_MinuteUnits  = (minute < 10) ? minute : minute % 10;
	alarmA->rw_MinuteTens  = (minute < 10) ? 0 : minute / 10;
	alarmA->rw_HourUnits  = (hour < 10) ? hour : hour % 10;
	alarmA->rw_HourTens  = (hour < 10) ? 0 : hour / 10;
	alarmA->amOr24Hour0_pm1  = amPm;
}

void Set_DateAlarm(uint8_t day, uint8_t dateWeek) {
	
	alarmA->rw_DateUnits  = (day < 10) ? day : day % 10;
	alarmA->rw_DateTens  = (day < 10) ? 0 : day / 10;
	alarmA->dateUnits0_weekDay1 = dateWeek; //0 or 1
}

void Get_Time(void) {
	
	uint8_t second2 = time->rw_SecondUnits;
	uint8_t second1 = time->rw_SecondTens;
	uint8_t minute2 = time->rw_MinuteUnits;
	uint8_t minute1 = time->rw_MinuteTens;
	uint8_t hour2 = time->rw_HourUnits;
	uint8_t hour1 = time->rw_HourTens;
	uint8_t amPm = time->amOr24Hour0_pm1;
	
	char *hour12 = NULL;
	char pm[] = "PM";
	char am[] = "AM";
	hour12 = (amPm == 1) ? pm : am;
	
	printf("%u%u:%u%u:%u%u %s", hour1, hour2, minute1, minute2, second1, second2, hour12 );
	//you don't have to dereference the char * pointer to print its value. I have no idea why not.
}

void Get_Date(void) {
	
	uint8_t date2 = date->rw_DateUnits;
	uint8_t date1 = date->rw_DateTens;
	uint8_t month2 = date->rw_MontUnits;
	uint8_t month1 = date->rw_MonthTens;
	uint8_t weekday = date->rw_WeekDayUnits;
	uint8_t year2 = date->rw_YearUnits;
	uint8_t year1 = date->rw_YearTens;
	
	char *weekString;
	switch (weekday) {
		case SUNDAY : 
			weekString = "Sunday";
			break;
		case MONDAY : 
			weekString = "Monday";
			break;
		case TUESDAY : 
			weekString = "Tuesday";
			break;
		case WEDNESDAY : 
			weekString = "Wednesday";
			break;
		case THURSDAY : 
			weekString = "Thursday";
			break;
		case FRIDAY : 
			weekString = "Friday";
			break;
		case SATURDAY : 
			weekString = "Saturday";
			break;
	}
	
	printf("%s: %u%u/%u%u/%u%u", weekString, month1, month2, date1, date2, year1, year2 );
}

