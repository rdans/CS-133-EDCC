#include "ArraySort.h"
namespace RD_ARRAYSORT
{
//-----------------------------------------------------------------------------
//		function:		safeRead(istream& sin, Comparable* d, const char* re)
//		description:	safely reads in a DateTime (d) from sin.
//						Re-prompts and re-enters if input is invalid
//    
//    Input:			Comparable* d from sin
// 
//    Output:			None
// 
//    Calls:            none
// 
//    Called By:		main
// 
//    Parameters:		istream& sin  -- the input stream
//						Comparable* d -- pointer to the object input
//						const char* prompt  -- prompt, if necessary
// 
//    Returns:          n/a 
//
//    History Log:
//                           2/9/08  RD  completed version 1.0
// ----------------------------------------------------------------------------	
	void safeRead(istream& sin, Comparable* d, const char* prompt)
	{
		const int BUFFERSIZE = 256;
		d->input(sin);
		while(!sin)
		{		// read in number--enter loop if fail
			sin.clear();		// clear fail
			sin.ignore(BUFFERSIZE, '\n');	// read past newline
			cout << prompt;  // re-prompt
			d->input(sin);
		}
		sin.ignore(BUFFERSIZE, '\n');  // read past newline once input succeeds
	}

//-----------------------------------------------------------------------------
//		function:	void printArray(ostream & sout, Comparable **a, int size)
//		description:	can print out an array of DateTime *
//    
//    Input:			None
// 
//    Output:			Comparable* d sout
// 
//    Calls:            none
// 
//    Called By:		main
// 
//    Parameters:		ostream& sout  -- the output stream
//						Comparable** a -- array of pointers to the objects
//						int size  -- number of elements in the array
// 
//    Returns:          n/a 
//
//    History Log:
//                           2/9/08  RD  completed version 1.0
// ----------------------------------------------------------------------------	
	void printArray(ostream & sout, Comparable **a, int size)
	{
		for(int i = 0; i < size; i++)
		{
			a[i]->print(sout);
			sout << endl;
		}
		sout << endl;
	}
}

