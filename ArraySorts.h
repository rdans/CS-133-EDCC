//-----------------------------------------------------------------------------
//	File: ArraySort.h
//
//	functions:
//	void quickSort(Comparable** array, int fromIndex, int toIndex);
//	int partition(Comparable** array, int fromIndex, int toIndex);
//		void SortFirstMiddleLast(Comparable** array, int fromIndex,
//			int midIndex, int toIndex);
//		void insertionSort(Comparable** array, int size);
//		void safeRead(istream& sin, Comparable* d, const char* prompt);
//		void printArray(ostream & sout, Comparable **array, int size);
//-----------------------------------------------------------------------------
#ifndef ARRAYSORT_H
#define ARRAYSORT_H
#include <iostream>
#include "DateTime.h"
using namespace std;
using namespace RD_DATETIME;
const int MAXINPUT = 4;
//-------------------------------------------------------------------------------------------
//    File:             ArraySorts.h
//
//    Title:            ArraySorts Class
//
//    Description:		This file contains the class definition for ArraySorts
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
//			void quickSort(Comparable** array, int fromIndex, int toIndex);	
//			int partition(Comparable** array, int fromIndex, int toIndex);
//			void SortFirstMiddleLast(Comparable** array, int fromIndex,
//			int midIndex, int toIndex);
//			void insertionSort(Comparable** array, int size);
//			void safeRead(istream& sin, Comparable* d, const char* prompt);
//			void printArray(ostream & sout, Comparable **array, int size);
//
//    History Log:
//                      4/7/08  RD  completed version 1.0
// ----------------------------------------------------------------------------
namespace RD_DATETIME
{	
	void quickSort(Comparable** array, int fromIndex, int toIndex);	
	int partition(Comparable** array, int fromIndex, int toIndex);
	void swap(Comparable** array, int i, int j);
	void SortFirstMiddleLast(Comparable** array, int fromIndex,
		int midIndex, int toIndex);	
	void insertionSort(Comparable** array, int size);	
	void safeRead(istream& sin, Comparable* d, const char* prompt);
	void printArray(ostream & sout, Comparable **array, int size);
}
#endif