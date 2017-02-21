//-----------------------------------------------------------------------------
//	File: Date.cpp
//
//	class: Date
//	methods:
//		Date::Date(short day, short month, short year)
//		bool Date::operator==(const Comparable &other)const
//		bool Date::operator<(const Comparable &other)const
//		void Date::setCurrentDate(void)
//		void Date::setDayOfWeek(void)
//		void Date::setDayOfYear(void)
//		short Date::countLeaps(short year)const
//		void Date::setDayOfMonth(short dayOfMonth)
//		void Date::setMonth(short month)
//		void Date::setYear(short year)
//		Date Date::tomorrow() const
//		Date Date::yesterday() const
//-----------------------------------------------------------------------------
#include "Date.h"

namespace RD_DATETIME
{
//-----------------------------------------------------------------------------
//	  Method:			Date(short day, short month, short year) -- constructor
//
//	  Description:	creates a new Date object
// 
//    Calls:            setCurrentDate()
//						setDayOfYear()
//						setDayOfWeek()
// 
//    Called By:		main()
// 
//    Parameters:		short day		-- day to set
//						short month		-- month to set
//						short year		-- month to set
//
//    History Log:
//                           4/27/2016  RD  completed version 1.0
// ----------------------------------------------------------------------------
	Date::Date(short day, short month, short year)
	{
		setCurrentDate();
		if (month >= 0 && month < MONTHSINYEAR)
			m_month = month;
		if (year >= LOWYEAR)
			m_year = year;
		if (day <= daysInMonth(month, year) && day >= 1)
			m_dayOfMonth = day;

		setDayOfYear();
		setDayOfWeek();
    }

//-----------------------------------------------------------------------------
//    Class:			Date
//	  Method:			operator==(const Comparable& other)const
//
//	  Description:	true if the two objects are exactly the same
// 
//    Parameters:		const Comparable &other  -- the other Date to compare
//
//	  Exceptions:		throws bad_cast if other is not a Date
//
//	  Call:				none
//	  Called by:		main(), setDayOfYear(), input(), yeseterday(), tomorrow()
// 
//    Returns:          true if the two objects are exactly the same
//
//    History Log:
//                           4/27/2016  RD  completed version 1.0
//-----------------------------------------------------------------------------
	bool Date::operator==(const Comparable &other)const
	{
		try
		{
			const Date &otherDate = dynamic_cast<const Date&>(other);
			if(m_year == otherDate.m_year && m_dayOfYear ==
				otherDate.m_dayOfYear)
				return true;
			return false;   
		}
		catch(bad_cast e)
		{
			return false;
		}
    }
//-----------------------------------------------------------------------------
//    Class:			Date
//	  Method:			lessThan(const Comparable& other)const
//
//	  Description:		true if the current object is before other
//
//	  Call:				none
//	  Called by:		constructor, countleaps()
// 
// 
//    Parameters:		const Comparable &other  -- the other Date to compare
// 
//    Returns:          true if the current object is before other
//
//    History Log:
//                           4/27/2016  RD  completed version 1.0
// ----------------------------------------------------------------------------
	bool Date::operator<(const Comparable &other)const
	{
			const Date &otherDate = dynamic_cast<const Date&>(other);
			if (m_year < otherDate.getYear())
				return true;
			if (m_year == otherDate.getYear())
			{
				if (m_month < otherDate.getMonth())
					return true;
				else if (m_month == otherDate.getMonth())
				{
					if (m_dayOfMonth < otherDate.getDayOfMonth())
						return true;
				}
			}
			return false;
    }

//-----------------------------------------------------------------------------
//    Class:			Date
//	  Method:			setCurrentDate()
//
//	  Description:	sets the date from the system clock
// 
//    Called By:		constructor, mutators
//
//    History Log:
//                           4/27/2016  RD  completed version 1.0
// ----------------------------------------------------------------------------
	void Date::setCurrentDate(void)
	{
		time_t rawtime;
		tm *currentTimePtr;
		time(&rawtime);
		currentTimePtr = localtime(&rawtime);

		m_year = currentTimePtr->tm_year + 1900;
		m_month = currentTimePtr->tm_mon;
		m_dayOfMonth = currentTimePtr->tm_mday;
		setDayOfYear();
        setDayOfWeek();
	}

//-----------------------------------------------------------------------------
//    Class:			Date
//	  Method:			setDayOfWeek(void)
//
//    Description:	sets the proper day of the week
//	  Calls:			none
//	  Called by:		constructor(), setCurrentDate(), 
//						setDayOfMonth(), setYear(), setMonth()
//
//    History Log:
//                           4/27/2016  RD  completed version 1.0
// ----------------------------------------------------------------------------
	void Date::setDayOfWeek(void)
    {
		static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
		int yr = m_year;
		yr -= (m_month + 1) < 3;
		m_dayOfWeek = ((yr + yr / (STARTDAYOFWEEK * STARTDAYOFWEEK) - yr / 
			DAYOFWEEK1 + yr / DAYOFWEEK2 + t[m_month] + m_dayOfMonth) - 1) % DAYSINWEEK;
    }

//-----------------------------------------------------------------------------
//    Class:			Date
//	  Method:			setDayOfYear(void)
//
//	  Description:	sets the proper day of the year
//	  Calls:			none
//	  Called by:		constructor(), setCurrentDate(), 
//						setDayOfMonth(), setYear(), setMonth()
//    History Log:
//                           4/27/2016  RD  completed version 1.0
// ----------------------------------------------------------------------------
	void Date::setDayOfYear(void)
    {
		if (isLeapYear(m_year) && m_month > 1)
			m_dayOfYear = numberOfDays[m_month - 1] + m_dayOfMonth + 1;
		else if (m_month == 0)
			m_dayOfYear = m_dayOfMonth;
		else
			m_dayOfYear = numberOfDays[m_month - 1] + m_dayOfMonth;
    }

//-----------------------------------------------------------------------------
//    Class:			Date
//	  Method:			countLeaps(short year)const
//
//	  Description:	returns the number of leap years from 1760 to year
// 
//    Calls:            isLeapYear(short)
// 
//    Returns:          the number of leap years from 1760 to year 
//
//    History Log:
//                           4/27/2016  RD  completed version 1.0
//-----------------------------------------------------------------------------
	short Date::countLeaps(short year)const
    { 
          short leaps = 0;
          for(short i = LOWYEAR; i < year; i++)
              if(isLeapYear(i))
                 leaps++; 
          return leaps;
    }

//-----------------------------------------------------------------------------
//    Class:			Date
//	  Method:			setDayOfMonth(short dayOfMonth)
//
//	  Description:	mutator for m_dayOfMonth
// 
//    Calls:            daysInMonth(short, short)
//						setDayOfYear()
//						setDayOfWeek()
// 
//    Parameters:		dayOfMonth --  day of month to set
//
//    History Log:
//                           4/27/2016  RD  completed version 1.0
//-----------------------------------------------------------------------------
	void Date::setDayOfMonth(short dayOfMonth)
    {
		if (dayOfMonth >= 1 && dayOfMonth <= daysInMonth(m_month, m_year))
			m_dayOfMonth = dayOfMonth;
		else
			m_dayOfMonth = 1;
			
		setDayOfYear();  
		setDayOfWeek();
    }
  
//-----------------------------------------------------------------------------
//    Class:			Date
//	  Method:			setMonth(short dmonth)
//
//	  Description:	mutator for m_month
// 
//    Calls:            daysInMonth(short, short)
//						setDayOfYear()
//						setDayOfWeek()
//    Called By:		n/a
// 
//    Parameters:		month --  month to set
//
//    History Log:
//                           4/27/2016  RD  completed version 1.0
//-----------------------------------------------------------------------------
	void Date::setMonth(short month)
    {
		if (month >= 0 && month < MONTHSINYEAR)
			m_month = month;
		else
			m_month = 0;
		setDayOfYear();
		setDayOfWeek();
    }
 
//-----------------------------------------------------------------------------
//    Class:			Date
//	  Method:			setYear(short year)
//
//	  Description:	mutator for m_year
// 
//    Calls:            isLeapYear(short)
//						setDayOfYear()
//						setDayOfWeek()
// 
//    Parameters:		year --  year to set
//
//    History Log:
//                           4/27/2016  RD  completed version 1.0
//-----------------------------------------------------------------------------
	void Date::setYear(short year)
    {
		if (year >= LOWYEAR)
			m_year = year;
		else
			m_year = LOWYEAR;
		setDayOfYear();
		setDayOfWeek();
	}

	//-----------------------------------------------------------------------------
	//    Class			: Date
	//	  Method		: input(istream& sin) 
	//	  Description	: create a function to allow user input month, day, year
	//	  Parameter		: istream& sin
	//    History Log	:
	//                     4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------

	void Date:: input(istream& sin)
	{
		int inDate = -1;
		int inMonth = -1;
		int inYear = -1;

		sin >> inDate;
		while (isspace(sin.peek()))
			sin.get();
		if (sin.peek() == '/')
		{
			sin.get();
			sin >> inMonth;
			inMonth--;
			setMonth(inMonth);
			setDayOfMonth(inDate);
			while (isspace(sin.peek()))
				sin.get();

			if (sin.peek() == '/')
			{
				sin.get();
				sin >> inYear;
				setYear(inYear);
				setDayOfYear();
				setDayOfWeek();
			}
		}
		else
		{
			*this = Date(inDate, -1, -1);
		}
	}

	//-----------------------------------------------------------------------------
	//    Class			: Date
	//	  Method		: print(ostream& sout)const
	//	  Description	: print out day name, month name, and year
	//	  Called by		: print methods of date class
	//	  Parameter		: ostream& sout	
	//    History Log	:
	//                     4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------

	void Date::print(ostream& sout)const
	{
		sout << DayName[m_dayOfWeek] << "," << MonthName[m_month] << " " << m_dayOfMonth << " " << m_year ;
	}

	//-------------------------------------------------------------------------------------------
	//    Class:			Date
	//
	//    function          ostream& operator<<(ostream& sout, const Date& date)
	//
	//    Description:		displays date to sout
	//
	//    Programmer:		Reinaldo Daniswara
	//   
	//    Date:             4/27/2016
	// 
	//    Version:          1.0
	//
	//	  Input:			None	
	//				
	//	  Output:			date to sout
	//	
	//	  Called by:		print methods of Date
	//	
	//    Parameters:		ostream & sout  -- the stream used for output
	//						const Date& date-- the Date
	//	
	//	  Returns:          ostream & sout 	
	//	
	//    History Log:
	//                      4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------

	ostream& operator<<(ostream& sout, const Date& date)
	{
		date.print(sout);
		return sout;
	}

	//-------------------------------------------------------------------------------------------
	//    Class:			Date
	//
	//    function          istream& operator>>(istream& sin, Date& date)
	//
	//    Description:		inputs date to sout
	//
	//    Programmer:		Reinaldo Daniswara
	//   
	//    Date:             4/27/2016
	// 
	//    Version:          1.0
	//
	//	  Input:			None	
	//				
	//	  Output:			date from sin
	//	
	//	  Called by:		print methods of Date
	//	
	//    Parameters:		istream& sin  -- the stream used for input
	//						Date& date-- the CTime
	//	
	//	  Returns:          istream& sin
	//	
	//    History Log:
	//                      4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------

	istream& operator>>(istream& sin, Date& date)
	{
		date.input(sin);
			return sin;
	}

	//-----------------------------------------------------------------------------
	//	  Class:			Date
	//
	//	  Method:			tomorrow() const
	//
	//    Description:		increase day of the month, so it will display the date after
	// 
	//    Calls:            n/a
	// 
	//    Called By:		main()
	// 
	//    Parameters:		n/a
	//
	//    History Log:
	//                           4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------

	Date Date::tomorrow() const
	{
		if (m_dayOfMonth == daysInMonth(m_month, m_year))
		{
			if (m_month != 11)
				return Date(1, m_month + 1, m_year);
			else
				return Date(1, 0, m_year + 1);
		}
		else
			return Date(m_dayOfMonth + 1, m_month, m_year);
	}	

	//-----------------------------------------------------------------------------
	//	  Class:			Date
	//
	//	  Method:			yesterday() const
	//
	//    Description:		decrease day of the month, so it will display the date before
	// 
	//    Calls:            n/a
	// 
	//    Called By:		main()
	// 
	//    Parameters:		n/a
	//
	//    History Log:
	//                           4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------


	Date Date::yesterday() const
	{
		if (m_dayOfMonth == 1)
			return Date(DaysMonth[m_month], 11, m_year-1);
		else if (m_dayOfMonth == 1 && m_dayOfYear == 365)
			return Date(DaysMonth[m_month - 1], 12, m_year - 1);
		else
			return Date(m_dayOfMonth - 1, m_month, m_year);

	}
	 
}