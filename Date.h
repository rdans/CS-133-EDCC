//-----------------------------------------------------------------------------
//	File: Date.h
//
//	class: Date
//-----------------------------------------------------------------------------
#ifndef DATE_H
#define DATE_H
//-----------------------------------------------------------------------------
//    Class:			Date
//
//    File:             Date.h
//
//    Title:            Date Class
//
//    Description:		This file contains the class definition for Date
//
//    Programmer:		Reinaldo Daniswara
//   
//    Date:             4/29/2016
// 
//    Version:          1.0
//  
//    Environment:   Hardware: Intel core i7 
//                   Software: windows 10
//
//    Compiles under Microsoft Visual Studio 2015
// 
//	  class Date:
//
//	  Properties:
//			short m_year;		// full year, i.e., 2006
//			short m_month;		// 0 - 11
//			short m_dayOfMonth; // 1 - days in that month
//			short m_dayOfYear;  // 1 - 365 or 366
//			short m_dayOfWeek;	// 0 - 6
//
//	  Methods:
//			Inline:
//				Static:
//					static bool isLeapYear(short year) 
//						true if year is a leap year; false otherwise
//					static short daysInMonth(short month, short year) 
//						returns the number of days in month for that year
//					static const char* monthName(int monthNum) 
//						returns a string representation of monthNum
//					static const char* weekdayName(int weekdayNum) 
//						returns a string representation of weekdayNum
//				Non-Static:
//					short getDayOfWeek()const
//					short getDayOfMonth()const
//					short getMonth()const
//					short getYear()const
//					short getDayOfYear()const
//
//			Non-inline:
//					
//					virtual bool equals(const Comparable &other)const
//					virtual lessthan(const Comparable &other)const
//					virtual void input(istream& sin)
//					virtual void print(ostream& sout)const
//
//					void setMonth(short monthIn)
//					void setYear(short yearIn)
//					void setCurrentDate(void)
//					void setDayOfYear(void)
//					void setDayOfWeek(void)
//					void setDayOfMonth(short dayOfMonth)
//					Date tomorrow()const
//					Date yesterday()const
//					short countLeaps(short year)const
//					void print(ostream& sout)const;
//
//    History Log:
//                      4/27/2016 RD  completed version 1.0
// ----------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Comparable.h"
#include <string>
using namespace std;

namespace RD_DATETIME
{
	const short LOWYEAR = 1760;
    const short DAYSINYEAR = 365;
    const short STARTDAYOFWEEK = 2;
    const short MONTHSINYEAR = 12;
	const short DAYSINWEEK = 7;
	const short LEAP = 1;
	const short DAYOFWEEK1 = 100;
	const short DAYOFWEEK2 = 400;
	const int numberOfDays[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
	const int DaysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	const string DayName[] =
	{ "Monday", "Tuesday", "Wednesday", "Thursday", "Friday",
		"Saturday","Sunday"};

	const string MonthName[] =
	{ "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November",
		"December"};

	class Date : virtual public Comparable
	{
	public:
		Date(short day = -1, short month = -1 , short year = -1);
		virtual ~Date(void) {}
		// pure virtuals that MUST be defined
		virtual bool operator==(const Comparable &other)const;
		virtual bool operator!=(const Comparable &other)const
			{return !((*this) == other);}
		virtual bool operator<(const Comparable &other)const;
		virtual bool operator>(const Comparable &other)const
			{return !((*this) < other) && !((*this) == other);}
		virtual bool operator<=(const Comparable &other)const
			{return !((*this) > other);}
		virtual bool operator>=(const Comparable &other)const
			{return !((*this) < other);}
		virtual void input(istream& sin);
		virtual void print(ostream& sout)const;
	
		// mutators
	private:
		void setDayOfYear(void);
		void setDayOfWeek(void);
	public:
		void setCurrentDate(void);
		void setDayOfMonth(short dayOfMonth);
		void setMonth(short monthIn);
		void setYear(short yearIn);
		short countLeaps(short year)const;
		
		//accessors
		short getDayOfWeek()const {return m_dayOfWeek;}
		short getDayOfMonth()const {return m_dayOfMonth;}
		short getMonth()const {return m_month;}
		short getYear()const {return m_year;}
		short getDayOfYear()const {return m_dayOfYear;}

		Date tomorrow()const;
		Date yesterday()const;

		//statics
		static bool isLeapYear(short year)
		{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0 && year % 100 != 0)
			return true;
		else
			return false;
		}

		static short daysInMonth(short month, short year)
		{
			return (isLeapYear(year) && month == 1) ? (DaysMonth[month] + LEAP) : DaysMonth[month];
		}
		static const char* monthName(int monthNum)
		{
			return MonthName[monthNum].c_str();
		}
		static const char* weekdayName(int weekdayNum)
		{
			return DayName[weekdayNum].c_str();
		}
		
	protected:
		short m_year;  // full year, i.e., 2012
		short m_month; // 0 - 11
		short m_dayOfMonth; // 1 - days in that month
		short m_dayOfYear;  // 1 - 365 or 366
		short m_dayOfWeek;	// 0 - 6
	};
	
	ostream& operator<<(ostream& sout, const Date& date);
	istream& operator>>(istream& sin, Date& date);
}
#endif
