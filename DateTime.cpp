#include "DateTime.h"

namespace RD_DATETIME
{
	//-----------------------------------------------------------------------------
	//    Class			: DateTime
	//	  Method		: input(istream& sin) 
	//	  Description	: create a function to allow user input month, date, year, 
	//					  hour, minute, and second
	//	  Parameter		: istream& sin
	//    History Log	:
	//                     4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------
	void DateTime::input(istream& sin) 
	{
		try
		{
			Date thisDate = dynamic_cast<Date&>(*this);
			CTime thisTime = dynamic_cast<CTime&>(*this);

			thisDate.input(sin);

			while (isspace(sin.peek()))
				sin.get();

			thisTime.input(sin);

			*this = DateTime(thisDate, thisTime);
		}
		catch (bad_cast)
		{
			cout << "Cast failed...";
		}
	}

	//-----------------------------------------------------------------------------
	//    Class			: DateTime
	//	  Method		: print(ostream& sout)const
	//	  Description	: print out date and time to console
	//	  Parameter		: ostream& sout	
	//    History Log	:
	//                     4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------

	void DateTime::print(ostream& sout)const 
	{
		const Date thisDate = dynamic_cast<const Date&>(*this);
		const CTime thisTime = dynamic_cast<const CTime&>(*this);
		thisDate.print(sout);
		sout << "   ";
		thisTime.print(sout);
	}

	//-----------------------------------------------------------------------------
	//    Class:			DateTime
	//		method:			operator==(const Comparable& other)const
	//
	//		description:	true if the two objects are exactly the same
	// 
	//    Parameters:		const Comparable &other  
	//
	//	  Exceptions:		throws bad_cast if different
	// 
	//    Returns:          true if the two objects are exactly the same
	//						false if the two objects are different
	//
	//    History Log:
	//                           4/27/2016  RD  completed version 1.0
	//-----------------------------------------------------------------------------


	bool DateTime::operator==(const Comparable &other)const 
	{
		try 
		{
			const Date &otherDate = dynamic_cast<const Date&>(other);
			const CTime &otherTime = dynamic_cast<const CTime&>(other);
			const Date &thisDate = dynamic_cast<const Date&>(*this);
			const CTime &thisTime = dynamic_cast<const CTime&>(*this);

			if ((otherDate.getYear() == thisDate.getYear()) &&
				(otherTime.getHour() == thisTime.getHour()) && 
				(otherDate.getDayOfMonth() == thisDate.getDayOfMonth()) &&
				(otherTime.getMinute() == thisTime.getMinute()) && 
				(otherDate.getMonth() == thisDate.getMonth()) &&
				(otherTime.getSecond() == thisTime.getSecond()))
				return true;
			else
				return false;
		}
		catch (bad_cast e)
		{
			return false;
		}
	}

	//-----------------------------------------------------------------------------
	//    Class:			DateTime
	//		method:			lessThan(const Comparable& other)const
	//
	//		description:	true if the current object is before other
	// 
	//    Parameters:		const Comparable &other  -- the other Date to compare
	// 
	//    Returns:          true if the current object is before other
	//
	//    History Log:
	//                           4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------


	bool DateTime::operator<(const Comparable &other)const 
	{
		const DateTime &otherDateTime = dynamic_cast<const DateTime&>(other);
		Date otherDate(otherDateTime.getDayOfMonth(),
			otherDateTime.getMonth(), otherDateTime.getYear());
		CTime otherTime(otherDateTime.getHour(),
			otherDateTime.getMinute(), otherDateTime.getSecond());

		if (Date::operator < (otherDate))
			return true;
		if (Date::operator < (otherDate) && CTime::operator <(otherTime))
			return true;
		else
			return false;
	}
	
	//-------------------------------------------------------------------------------------------
	//    Class:			DateTime
	//
	//    function          ostream& operator<<(ostream& sout, const DateTime& datetime)
	//
	//    Description:		displays date and time to sout
	//
	//    Programmer:		Reinaldo Daniswara
	//   
	//    Date:             4/27/2016
	// 
	//    Version:          1.0
	//
	//	  Input:			None	
	//				
	//	  Output:			date and time to sout
	//	
	//	  Called by:		print methods of DateTime
	//	
	//    Parameters:		ostream & sout  -- the stream used for output
	//						const DateTime& datetime -- DateTime
	//	
	//	  Returns:          ostream & sout 	
	//	
	//    History Log:
	//                      4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------

	ostream& operator<<(ostream& sout, const DateTime& datetime) 
	{
		datetime.print(sout);
		return sout;
	}
	
	//-------------------------------------------------------------------------------------------
	//    Class:			DateTime
	//
	//    function          istream& operator>>(istream& sin, DateTime & datetime)
	//
	//    Description:		inputs date and time to sout
	//
	//    Programmer:		Reinaldo Daniswara
	//   
	//    Date:             4/27/2016
	// 
	//    Version:          1.0
	//
	//	  Input:			None	
	//				
	//	  Output:			date and time  from sin
	//	
	//	  Called by:		print methods of DateTime
	//	
	//    Parameters:		istream& sin  -- the stream used for input
	//						DateTime & datetime
	//	
	//	  Returns:          istream& sin 	
	//	
	//    History Log:
	//                      4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------

	istream& operator>>(istream& sin, DateTime & datetime) 
	{
		datetime.input(sin);
		return sin;
	}
}