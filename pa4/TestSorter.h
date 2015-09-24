// Program Information ////////////////////////////////////////////////////////
/**
 * @file TestSorter.h
 *
 * @brief Definition file for TestSorter class
 * 
 * @author Alexandra Caceres
 * 
 * @details Specifies all member methods of the TestSorter
 *
 * @version 1.00 (20 September 2015)
 *
 * @Note Requires DateType.h
 */

// Precompiler directives /////////////////////////////////////////////////////


#ifndef TESTSORTER_H
#define TESTSORTER_H

// Header files ///////////////////////////////////////////////////////////////

#include "DateType.h"
#include "SorterClass.h"
#include "SorterClass.cpp"
#include "SimpleVector.cpp"
#include "SimpleVector.h"

// Class definition  //////////////////////////////////////////////////////////

class TestSorter: public SorterClass<DateType>
{
        public:
            
            // constructers
            TestSorter();
            TestSorter (int initial);
            TestSorter (const TestSorter& copied);
           
            // destructor
            ~TestSorter();
           
            // virtual compare function
            int compareTo( const DateType &lhObject, 
                                                    const DateType &rhObject); 
            // virtual bubble sort function
            bool sort();
            
            // retrieves to be used in compare function
            int getMonth(const char *date, int &index);
              
            // string functions
            void strcopy(char* dest, char* src);
            int strlength(char* string);
            
            
        private:
        
      
            bool strcomp (char* string1, char* string2);
            SorterClass<DateType> sortData;
};


  #endif // ifndef TESTSORTER_H

