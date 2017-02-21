#include "ArraySorts.h"

namespace RD_DATETIME
{
	//-----------------------------------------------------------------------------
	//	  Function:			quickSort(Comparable** array, int fromIndex, int toIndex)
	//	  Description:		Function to run the quickSort
	//    
	//    Input:			None
	// 
	//    Output:			None
	// 
	//    Calls:            partition
	// 
	//    Called By:		main()
	// 
	//    Parameters:		Comparable** array
	//						int fromIndex
	//						int toIndex
	// 
	//    Returns:          n/a 
	//
	//    History Log:
	//                           4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------	
	void quickSort(Comparable** array, int fromIndex, int toIndex)
	{
		if ((toIndex - fromIndex) + 1 >= MAXINPUT)
		{
			int middle = partition(array, fromIndex, toIndex);
			quickSort(array, fromIndex, middle);
			quickSort(array, middle + 1, toIndex);
		}
		else
			insertionSort(array, toIndex + 1);

	}
	//-----------------------------------------------------------------------------
	//    Class:			ArraySort
	//	  Method:			swap(Comparable** array, int i, int j)
	//
	//	  Description:		swap two elements in an array
	// 
	//    Calls:             none
	//
	//	  Called by:		quicksort
	// 
	//    Parameters:		Comparable**, int, int
	//
	//    History Log:
	//                          4/27/2016 RD  completed version 1.0
	//							5/23/2016  RD  completed version 1.1
	//-----------------------------------------------------------------------------

	void swap(Comparable** array, int i, int j)
	{
		Comparable* temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}

	//-----------------------------------------------------------------------------
	//	  Function:			partition(Comparable** array, int fromIndex, int toIndex)
	//	  Description:		Compare the first element from index and last number to Index 
	//    
	//    Input:			None
	// 
	//    Output:			None
	// 
	//    Calls:            SortFirstMiddleLast()
	// 
	//    Called By:		main()
	// 
	//    Parameters:		Comparable** array
	//						int fromIndex
	//						int toIndex
	// 
	//    Returns:          n/a 
	//
	//    History Log:
	//                           4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------	

	int partition(Comparable** array, int fromIndex, int toIndex)
	{
		int middle = (fromIndex + toIndex) / 2;
		int pivot = toIndex - 1;
		int start = fromIndex + 1;
		int end = toIndex - 2;
		SortFirstMiddleLast(array, fromIndex, middle, toIndex);

		swap(array, middle, pivot);

		while (start <= end)
		{
			while (*array[start] < *array[pivot])
				start++;
			while (*array[end] > *array[pivot])
				end--;
			if (start < end)
			{
				swap(array, start, end);
				start++;
				end--;
			}
			else
				break;
		}

		swap(array, start, end);

		return start;
	}

	//-----------------------------------------------------------------------------
	//	  Function:			SortFirstMiddleLast(Comparable** array, int fromIndex
	//											, int midIndex, int toIndex)
	//	  Description:		Sort the element in the first, middle,. or last
	//    
	//    Input:			None
	// 
	//    Output:			None
	// 
	//    Calls:            n/a
	// 
	//    Called By:		partition()
	// 
	//    Parameters:		Comparable** array
	//						int fromIndex
	//						int toIndex
	// 
	//    Returns:          n/a 
	//
	//    History Log:
	//                           4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------	

	void SortFirstMiddleLast(Comparable** array, int fromIndex
								, int midIndex, int toIndex)
	{
		if (*array[midIndex] < *array[fromIndex])
		{
			swap(array, midIndex, fromIndex);
		}
		if (*array[midIndex] > *array[toIndex])
		{
			swap(array, midIndex, fromIndex);
		}
		if (*array[midIndex] < *array[fromIndex])
		{
			swap(array, midIndex, fromIndex);
		}

	}

	//-----------------------------------------------------------------------------
	//	  Function:			insertionSort(Comparable** array, int size)
	//	  Description:		function that run the insertion sort
	//    
	//    Input:			None
	// 
	//    Output:			None
	// 
	//    Calls:            n/a
	// 
	//    Called By:		main()
	// 
	//    Parameters:		Comparable** array
	//						int size
	// 
	//    Returns:          n/a 
	//
	//    History Log:
	//                           4/27/2016  RD  completed version 1.0
	// ----------------------------------------------------------------------------	

	void insertionSort(Comparable** array, int size)
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < size; i++)
		{
			Comparable* a = array[i];
			j = i - 1;
			while (j >= 0 && *array[j] > *a)
			{
				array[j + 1] = array[j];
				j--;
			}
			array[j + 1] = a;
		}

	}

	//-----------------------------------------------------------------------------
	//	  Function:		safeRead(istream& sin, Comparable* d, const char* re)
	//	  Description:	safely reads in a DateTime (d) from sin.
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
		while (!sin)
		{		// read in number--enter loop if fail
			sin.clear();		// clear fail
			sin.ignore(BUFFERSIZE, '\n');	// read past newline
			cout << prompt;  // re-prompt
			d->input(sin);
		}
		sin.ignore(BUFFERSIZE, '\n');  // read past newline once input succeeds
	}

	//-----------------------------------------------------------------------------
	//	  Function:	void printArray(ostream & sout, Comparable **a, int size)
	//	  Description:	can print out an array of DateTime *
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
		for (int i = 0; i < size; i++)
		{
			a[i]->print(sout);
			sout << endl;
		}
		sout << endl;
	}

}