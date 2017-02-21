//-----------------------------------------------------------------------------
//	File: Driver.cpp
//  
//-----------------------------------------------------------------------------
#include "DateTime.h"
#include "ArraySorts.h"

using namespace std;
using namespace RD_DATETIME;

//-------------------------------------------------------------------------------------------
//    Function:			main()
//
//    File:             Driver.cpp
//
//    Title:            "Making a Date, Marking Time"
//
//    Description:		This file contains function main() which tests DateTime, Date, and CTime
//	  
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
//    Input:			Date and Time
// 
//    Output:			Screen display of Date and Time
// 
//    Calls:            DateTime, Date, CTime classes and related functions
// 
//    Called By:		n/a
// 
//    Parameters:		None
// 
//    Returns:          EXIT_SUCCESS  = successful 
//						EXIT_FAILURE; = program fail
//
//    History Log:
//                           4/28/2016  RD  completed version 1.0
// ----------------------------------------------------------------------------

int main(void)
{
	try
	{
		Date date1;
		CTime time1;
		DateTime datetime1;
		Comparable **cpp;
		int length = 0;

		cout << "Welcome to Date and Time by Reinaldo" << endl;
		cout << "The current date and time is: " << endl;
		cout << date1 << " and the time is " << time1 << endl;
		cout << "How many Date and Time do you want to input? ";
		cin >> length;
		cpp = new Comparable*[length];

		for (int i = 0; i < length; i++)
		{
			cout << "Date and Time #" << (i + 1) << " (dd/mm/yyyy hh:mm:ss): ";
			cpp[i] = new DateTime;
			safeRead(cin, cpp[i], "Enter a valid Date and Time format");
			cpp[i]->print(cout);
			cout << endl << endl;
		}

		cout << "Please enter new dates ONLY" << endl;
		for (int i = 0; i < length; i++)
		{
			cpp[i] = new Date;
			cout << "Enter date #" << (i + 1) << " : ";
			safeRead(cin, cpp[i], "Enter a valid Date format");
			cpp[i]->print(cout);
			cout << endl << endl;
		}

		quickSort(cpp, 0, length - 1);
		cout << "------------After Date Sort----------" << endl;
		printArray(cout, cpp, length);

		for (int i = 0; i < length; i++)
		{
			Date datetime = dynamic_cast<Date&>(*cpp[i]);
			cout << "The day before date #" << (i + 1) << " (after sort) is " << datetime.yesterday() << endl;
			cout << "The day after date #" << (i + 1) << " (after sort) is " << datetime.tomorrow() << endl;;
		}

		cout << endl << "Please enter new times ONLY" << endl;
		for (int i = 0; i < length; i++)
		{
			cpp[i] = new CTime;
			cout << "Enter time #" << (i + 1) << " : ";
			safeRead(cin, cpp[i], "Enter a valid Date format");
			cpp[i]->print(cout);
			cout << endl << endl;
		}

		quickSort(cpp, 0, length - 1);
		cout << "------------After Time Sort----------" << endl;
		printArray(cout, cpp, length);

		for (int i = 0; i < length; i++)
			delete cpp[i];
		delete[] cpp;
		cin.get();
		cin.get();
		cin.get();
		return EXIT_SUCCESS;
	}
	catch (exception e)
	{
		cerr << "program terminated: " << e.what();
		cin.ignore();
		return EXIT_FAILURE;
	}
}