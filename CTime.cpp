//-----------------------------------------------------------------------------
//	File: CTime.cpp
//
//	class: CTime
//	methods:
//		CTime::CTime()
//		CTime::CTime(int hour, int minute, int second)
//		void CTime::setCurrentTime()
//		bool CTime::operator==(const Comparable &other)const
//		bool CTime::operator<(const Comparable &other)const
//		void CTime::setHour(short hour) 
//		void CTime::setMinute(short minute)
//		void CTime::setSecond(short second)
//		void CTime::print(ostream& sout)const
//		void CTime::input(istream& sin)
//
//-----------------------------------------------------------------------------

#include "CTime.h"
namespace RD_DATETIME
{
	//-----------------------------------------------------------------------------
	//		method:			CTime(short day, short month, short year) -- constructor
	//
	//		description:	creates a new CTime object
	// 
	//    Calls:            n/a
	// 
	//    Called By:		ostream& operator<<(ostream& sout, const CTime &c)
	// 
	//    Parameters:		int hour 		-- hour to set
	//						int minute		-- minute to set
	//						int second		-- second to set
	//
	//    History Log:
	//                           4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------
	
	CTime::CTime(short hour, short minute, short second)
	{
		if (hour == -1 && minute == -1 && second == -1)
			setCurrentTime();
		else
		{
			setHour(hour);
			setMinute(minute);
			setSecond(second);
		}
	}
//-----------------------------------------------------------------------------
//    Class:			CTime
//		method:			setCurrentTime()
//
//		description:	sets the time from the system clock
//    
//    Input:			None
// 
//    Output:			None
// 
//    Calls:            none
// 
//    Called By:		constructor, mutators
// 
//    Parameters:		none
// 
//    Returns:          n/a 
//
//    History Log:
//                           4/27/2016  RD  completed version 1.0
// ----------------------------------------------------------------------------
	void CTime::setCurrentTime()
	{
		time_t rawtime;
		tm *currentTimePtr;
		time(&rawtime);
		currentTimePtr = localtime(&rawtime);

		m_hour = currentTimePtr->tm_hour;
		m_minute = currentTimePtr->tm_min;
		m_second = currentTimePtr->tm_sec;
	}

	//-----------------------------------------------------------------------------
	//    Class:			CTime
	//		method:			operator==(const Comparable& other)const
	//
	//		description:	true if the two objects are exactly the same
	// 
	//    Parameters:		const Comparable &other  -- the other Time to compare
	//
	//	  Exceptions:		throws bad_cast if other is not a Time
	// 
	//    Returns:          true if the two objects are exactly the same
	//
	//    History Log:
	//                           4/27/2016  RD  completed version 1.0
	//-----------------------------------------------------------------------------
	
	bool CTime::operator==(const Comparable &other)const
	{
		try
		{
			const CTime &otherTime = dynamic_cast<const CTime&>(other);
			if (m_hour == otherTime.m_hour && m_minute ==
				otherTime.m_minute && m_second == otherTime.m_second)
				return true;
			return false;
		}
		catch (bad_cast e)
		{
			return false;
		}
	}

	//-----------------------------------------------------------------------------
	//    Class:			CTime
	//		method:			lessThan(const Comparable& other)const
	//
	//		description:	true if the current object is before other
	// 
	//    Parameters:		const Comparable &other  -- the other Time to compare
	// 
	//    Returns:          true if the current object is before other
	//
	//    History Log:
	//                           4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------

	bool CTime::operator<(const Comparable &other)const
	{
		const CTime &otherTime = dynamic_cast<const CTime&>(other);
		int thisTime = m_hour * ONEHOURINSECOND + m_minute * MAXMINSEC + m_second;
		int anotherTime = otherTime.getHour() * ONEHOURINSECOND 
			+ otherTime.getMinute() * MAXMINSEC + otherTime.getSecond() * MAXMINSEC;

		if (thisTime < anotherTime)
			return true;
		else
			return false;
	}

	//-----------------------------------------------------------------------------
	//    Class			: CTime
	//	  Method		: setHour(short hour)
	//	  Description	: sets the bound of the proper hour 
	//	  Parameter		: short hour	
	//    History Log	:
	//                     4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------

	void CTime::setHour(short hour)
	{
		if (hour >= 0 && hour <= MAXHOUR)
			m_hour = hour;
		else
			m_hour = 0;
	}

	//-----------------------------------------------------------------------------
	//    Class			: CTime
	//	  Method		: setMinute(short minute)
	//	  Description	: sets the bound of the proper Minute 
	//	  Parameter		: short minute	
	//    History Log	:
	//                     4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------

	void CTime::setMinute(short minute)
	{
		if (minute >= 0 && minute <= MAXMINSEC)
			m_minute = minute;
		else
			m_minute = 0;
	}

	//-----------------------------------------------------------------------------
	//    Class			: CTime
	//	  Method		: setSecond(short second)
	//	  Description	: sets the bound of the proper second
	//	  Parameter		: short second	
	//    History Log	:
	//                     4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------

	void CTime::setSecond(short second)
	{
		if (second >= 0 && second <= MAXMINSEC)
			m_second = second;
		else
			m_second = 0;
	}

	//-----------------------------------------------------------------------------
	//    Class			: CTime
	//	  Method		: print(ostream& sout)const
	//	  Description	: print out hour, minute, and second to console
	//	  Parameter		: ostream& sout	
	//    History Log	:
	//                     4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------

	void CTime::print(ostream& sout)const
	{
		string hourstring = to_string(m_hour);
		string minutestring = to_string(m_minute);
		string secondstring = to_string(m_second);
	
		if (m_hour <10)
			hourstring = "0" + to_string(m_hour);
		if (m_minute < 10)
			minutestring = "0" + to_string(m_minute);
		if (m_second < 10)
			secondstring = "0" + to_string(m_second);


		sout << hourstring << ":" << minutestring << ":" << secondstring;
	}

	//-----------------------------------------------------------------------------
	//    Class			: CTime
	//	  Method		: input(istream& sin) 
	//	  Description	: create a function to allow user input hour, minute, and second
	//	  Calls			: SetSecond(), setMinute(), setHour()
	//	  Parameter		: istream& sin
	//    History Log	:
	//                     4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------

	void CTime::input(istream& sin)
	{
		int inHour = 0;
		int inMinute = 0;
		int inSecond = 0;
		sin >> inHour;
		setHour(inHour);

		while (isspace(sin.peek()))
			sin.get();
		if (sin.peek() == ':')
		{
			sin.get();
			sin >> inMinute;
			setMinute(inMinute);
			while (isspace(sin.peek()))
				sin.get();
			if (sin.peek() == ':')
			{
				sin.get();
				sin >> inSecond;
				setSecond(inSecond);
			}
		}
		else
		{
			setHour(inHour);
			setMinute(0);
			setSecond(0);
		}

	}

	//-------------------------------------------------------------------------------------------
	//    Class:			CTime
	//
	//    function          ostream& operator<<(ostream& sout, const CTime& ctime)
	//
	//    Description:		displays military time to sout
	//
	//    Programmer:		Reinaldo Daniswara
	//   
	//    Date:             4/27/2016
	// 
	//    Version:          1.0
	//
	//	  Input:			None	
	//				
	//	  Output:			military time to sout
	//	
	//	  Called by:		print methods of CTime
	//	
	//    Parameters:		ostream & sout  -- the stream used for output
	//						const CTime& ctime-- the CTime
	//	
	//	  Returns:          ostream & sout 	
	//	
	//    History Log:
	//                      4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------

	ostream& operator<<(ostream& sout, const CTime& ctime)
	{
		ctime.print(sout);
		return sout;
	}

	//-------------------------------------------------------------------------------------------
	//    Class:			CTime
	//
	//    function          istream& operator>>(istream& sin, CTime& ctime)
	//
	//    Description:		inputs military time to sout
	//
	//    Programmer:		Reinaldo Daniswara
	//   
	//    Date:             4/27/2016
	// 
	//    Version:          1.0
	//
	//	  Input:			None	
	//				
	//	  Output:			military time from sin
	//	
	//	  Called by:		print methods of CTime
	//	
	//    Parameters:		istream& sin  -- the stream used for input
	//						CTime& ctime-- the CTime
	//	
	//	  Returns:          istream& sin	
	//	
	//    History Log:
	//                      4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------

	istream& operator>>(istream& sin, CTime& ctime)
	{
		ctime.input(sin);
		return sin;
	}
}