//-----------------------------------------------------------------------------
//	File: DateTime.h
//
//	class: DateTime
//  method: 
//			DateTime::DateTime() 
//			DateTime(short day, short month, short year, int hour, int minute, int second)
//			DateTime::DateTime(const Date &date, const CTime &time)
//			virtual void input(istream& sin);
//			virtual void print(ostream& sout)const;
//			virtual bool operator==(const Comparable &other)const;
//			virtual bool operator!=(const Comparable &other)const
//			virtual bool operator<(const Comparable &other)const;
//			virtual bool operator>(const Comparable &other)const
//			virtual bool operator<=(const Comparable &other)const
//			virtual bool operator>=(const Comparable &other)const
//			ostream& operator<<(ostream& sout, const DateTime& datetime);
//	        istream& operator>>(istream& sin, DateTime& datetime);
//-----------------------------------------------------------------------------
#ifndef DATETIME_H
#define DATETIME_H
#include "Date.h"
#include "CTime.h"
using namespace std;

//-------------------------------------------------------------------------------------------
//    Class:			DateTime
//
//    File:             DateTime.h
//
//    Title:            DateTime Class
//
//    Description:		This file contains the class definition for DateTime
//
//    Programmer:		Reinaldo Daniswara
//   
//    Date:             4/28/2016
// 
//    Version:          1.0
//  
//    Environment:   Hardware: Intel core i7 
//                   Software: windows 10
//
//    Compiles under Microsoft Visual Studio 2015
// 
//	  class Comparable:
//			Abstract Base class  -- allows for comparison 
//	  Properties:
//		 none
//		 
//	  Methods:
//		pure virtuals:
//			virtual void input(istream& sin);
//			virtual void print(ostream& sout)const;
//			virtual bool operator==(const Comparable &other)const;
//			virtual bool operator!=(const Comparable &other)const
//			virtual bool operator<(const Comparable &other)const;
//			virtual bool operator>(const Comparable &other)const
//			virtual bool operator<=(const Comparable &other)const
//			virtual bool operator>=(const Comparable &other)const
//
//    History Log:
//                      4/7/08  RD  completed version 1.0
// ----------------------------------------------------------------------------

namespace RD_DATETIME
{
	class DateTime : public Date, public CTime
	{
	public:
		DateTime::DateTime() : CTime(0, 0, 0), Date(1, 1, LOWYEAR) {}
		DateTime(short day, short month, short year, int hour, int minute, int second) :
			CTime(hour, minute, second), Date(day, month, year){}
		DateTime::DateTime(const Date &date, const CTime &time)
			: Date(date.getDayOfMonth(), date.getMonth(), date.getYear()),
			CTime(time.getHour(), time.getMinute(), time.getSecond()) {}
			
		virtual void input(istream& sin);
		virtual void print(ostream& sout)const;
		virtual bool operator==(const Comparable &other)const;
		virtual bool operator!=(const Comparable &other)const
		{
			return !((*this) == other);
		}
		virtual bool operator<(const Comparable &other)const;
		virtual bool operator>(const Comparable &other)const
		{
			return !((*this) < other) && !((*this) == other);
		}
		virtual bool operator<=(const Comparable &other)const
		{
			return !((*this) > other);
		}
		virtual bool operator>=(const Comparable &other)const
		{
			return !((*this) < other);
		}
	};
	ostream& operator<<(ostream& sout, const DateTime& datetime);
	istream& operator>>(istream& sin, DateTime& datetime);
}
#endif