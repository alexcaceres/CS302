// Program Information ////////////////////////////////////////////////////////
/**
 * @file QkSorter.cpp
 * 
 * @brief Implementation file for QkSorter,
 *        derived from SorterClass
 * 
 * @author Alexandra Caceres
 *
 * @details Implements virtual member methods of the QkSorter
 *
 * @version 1.00 (27 September 2015)
 *
 * @Note Requires QkSorter.h, SorterClass.cpp, SimpleVector.cpp,
 * 
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef QKSORTER_CPP
#define QKSORTER_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "QkSorter.h"
#include "SorterClass.cpp"
#include "SimpleVector.cpp"
#include <iostream>

/**
 * @brief Default constructor
 *
 * @details Constructs sorter class with default vector class initialization
 *          
 * @param None
 *
 * @note None
 */
QkSorter::QkSorter 
     (
      // no parameters
     )
       : SorterClass<DateType>()
   {
    // construct parent
   }

/**
 * @brief Initialization constructor
 *
 * @details Constructs sorter class with specified vector class initialization
 *          
 * @param in: initial capacity
 *
 * @note None
 */
QkSorter::QkSorter 
     (
      int initialCapacity // in: initial capacity for vector
     )
       : SorterClass<DateType>( initialCapacity )
   {
    // construct parent
   }

/**
 * @brief Copy constructor
 *
 * @details Constructs sorter class with copied object
 *          
 * @param in: other SorterClass object
 *
 * @note None
 */
QkSorter::QkSorter
     (
      const SorterClass<DateType> &copiedSorter // in: other sorter class object
     )
       : SorterClass<DateType>( copiedSorter )
   {
    // construct parent
   }

/**
 * @brief Class destructor
 *
 * @details Destructs test sorter class
 *          
 * @param in: None
 *
 * @note Implements SorterClass -> SimpleVector destructor
 */
QkSorter::~QkSorter
     (
      // no parameters
     )
   {
    // parent class (SorterClass) destructs
   }

/**
 * @brief Object comparison, necessary for sorting
 *
 * @details Compares objects mathematically, 
 *          returns value < 0 if lhO < rhO
 *          returns  0 if lhO = rhO
 *          returns value > 0 if lhO > rhO
 *          
 * @param in: Left hand object, right hand object
 *
 * @note Simple mathematical base operation; assumed to be overridden
 */
int QkSorter::compareTo 
     (
      const DateType &lhObject, // in: leftHandObject
      const DateType &rhObject  // in: rightHandObject
     )
   {
    int diff = makeYear( lhObject.date ) - makeYear( rhObject.date );

    if( diff != 0 )
       {
        return diff;
       }

    diff = makeMonth( lhObject.date ) - makeMonth( rhObject.date );

    if( diff != 0 )
       {
        return diff;
       }

    return makeDate( lhObject.date ) - makeDate( rhObject.date );
   }

/**
 * @brief Sorting operation
 *
 * @details Virtual sort method that is overridden
 *          to use various sorting strategies
 *          
 * @param in: None
 *
 * @note Derived methods use specific strategy to sort objects
 * @note Sets sort success flag to true at start;
 *       supporting operations used to create dates, months, years
 *       will set the flag to false if there is an incorrect date;
 *       method returns success flag
 */
bool QkSorter::sort
       (
        // no parameters
       )
   {
    
    int lowestIndex = 0;
    int highestIndex = getSize()-1;
    sortSuccess = true;

    quickSort(lowestIndex, highestIndex);
    
    

    return sortSuccess;
   }
/**
 * @brief QuickSorting operation
 *
 * @details Quick sort method that takes a left and a right
 *          DateType leftObj, midObj
 *          
 * @param in: int left, int right
 *
 * @note Derived methods use specific strategy to sort objects
 * @note Sets sort success flag to true at start;
 *       supporting operations used to create dates, months, years
 *       Partition and recursion occurs
 *       method returns success flag
 */
void QkSorter::quickSort(int left, int right)
 {

      int first = left, second = right;
      
      DateType leftObj, midObj;
      int index;
      int pivotValue = first;
      first++;

 

      // partition 

      if (first >= second) 
       {
            return;
       }
                getValueAt(pivotValue,midObj);
               
                
             for(index = second; index >= first; index--)
                {
                  getValueAt(index, leftObj);
                 
                
                 if( compareTo( leftObj, midObj ) >= 0 ) 
                    {
                      swap(second, index);
                      second--;
                    }
                }
            swap(second, index);
            
           

       // recursion 

        quickSort(left, second-1);
        quickSort(second+1, right);
}

/**
 * @brief Swaps date types
 *
 * @details Swaps date types for use with some sorting algorithms
 *          
 * @param in: None
 *
 * @note Requires access of vector data, swapping of strings,
 *       and resetting vector data at locations
 */
void QkSorter::swap
       ( 
        int one,   // in: index of one of two to be swapped
        int other  // in: index other of two to be swapped
       )
   {
    DateType temp, oneDate, otherDate;

    getValueAt( one, oneDate );
    getValueAt( other, otherDate );

    setValueAt( other, oneDate );
    setValueAt( one, otherDate );
   }


/**
 * @brief Makes an integer date
 *
 * @details Creates integer date from the text at the first part of the string
 *          
 * @param in: String data
 *
 * @note Checks for legitimate dates, sets sort success flag to false
 *       if date not possible
 */
int QkSorter::makeDate
       ( 
        const char *str  // in: date string
       )
   {
    int startIndex = 0;
    int maxDate, date = strToInt( startIndex, str );

    switch( makeMonth( str ) )
       {
        case 4: case 6: case 9: case 11:
           maxDate = 30;
           break;

        case 2:
           if( isLeapYear( makeYear( str ) ) )
              {
               maxDate = 29;
              }
           else
              {
               maxDate = 28;
              }
           break;

        default:
           maxDate = 31;
           break;
       }

    if( date > 0 && date <= maxDate )
       {
        return date;
       }

    sortSuccess = false;

    return 0;
   }

/**
 * @brief Makes an integer month
 *
 * @details Creates integer month from the text in the middle of the string
 *          
 * @param in: String data
 *
 * @note Checks for legitimate months, sets sort success flag to false
 *       if date not possible
 */
int QkSorter::makeMonth
       ( 
        const char *str  // in: date string
       )
   {
    const int NUM_MONTHS = 12;
    int monthIndex, startIndex = 0;
    char monthNames[ NUM_MONTHS ][ MONTH_NAME_SIZE ] = 
             { "APR", "AUG", "DEC", "FEB", "MAR", "MAY", 
                                  "JAN", "JUL", "JUN", "NOV", "OCT", "SEP" };
    int monthNums[ NUM_MONTHS ] = { 4, 8, 12, 2, 3, 5, 1, 7, 6, 11, 10, 9 };

    startIndex = findSpace( startIndex, str ) + 1;

    for( monthIndex = 0; monthIndex < NUM_MONTHS; monthIndex++ )
       {
        if( compMonth( str, startIndex, monthNames[ monthIndex ] ) )
           {
            return monthNums[ monthIndex ];
           }
       }

    sortSuccess = false;

    return 0;
   }

/**
 * @brief Makes an integer year
 *
 * @details Creates integer year from the text at the end of the string
 *          
 * @param in: String data
 *
 * @note Checks for legitimate years, sets sort success flag to false
 *       if year is below zero or above arbitrarily set limit
 *       in .h file
 */
int QkSorter::makeYear
       ( 
        const char *str  // in: date string 
       )
   {
    int startIndex = 0;
    int year;

    startIndex = findSpace( startIndex, str ) + 1;
    startIndex = findSpace( startIndex, str ) + 1;

    year = strToInt( startIndex, str );

    if( year < 0 || year > MAX_YEAR_ALLOWED )
       {
        sortSuccess = false;

        return 0;
       }

    return year;
   }

/**
 * @brief Converts substring segment to integer
 *
 * @details Given index starting location, acquires all contiquous digits,
 *          converts them to an integer value
 *          
 * @param in: starting index
 * @param in: String data
 *
 * @note None
 */
int QkSorter::strToInt
       ( 
        int startIndex,  // in: start index through string
        const char *str  // in: string
       )
   {
    int val, leftShiftFactor = 10;

    val = int( str[ startIndex ] - '0' );

    startIndex++;

    while( isDigit( str[ startIndex ] ) )
       {
        val *= leftShiftFactor;

        val += int( str[ startIndex ] - '0' );

        startIndex++;
       }

    return val;
   }

/**
 * @brief Finds the next space in a string
 *
 * @details Given a starting index, finds the next space in a string
 *          in order to find the next date component
 *          
 * @param in: starting index
 * @param in: String data
 *
 * @note None
 */
int QkSorter::findSpace
       ( 
        int startIndex,   // in: start index through string
        const char *str   // in: string
       )
   {
    while( str[ startIndex ] != SPACE && str[ startIndex ] != NULL_CHAR )
       {
        startIndex++;      
       }

    return startIndex;
   }

/**
 * @brief Compares a test name to a specified month name
 *
 * @details The first three letters of a test string are compared to
 *          a given three letter month name
 *          
 * @param in: test-month string
 * @param in: starting index
 * @param in: given month string
 *
 * @note Sets all letters to upper case, and is tested against
 *       an upper case three-letter month
 * @note Month name is allowed to be longer, but first three letters
 *       must be correct
 */
bool QkSorter::compMonth
       ( 
        const char *testStr,  // in: string tested for month
        int startIndex,  // in: index to start month test
        const char *testMonth // in: month string to compare to
       )
   {
    int endIndex = startIndex + MONTH_NAME_WIDTH;
    int testIndex = 0;

    while( startIndex < endIndex )
       {
        if( toUpper( testStr[ startIndex ] ) != testMonth[ testIndex ] )
           {
            return false;
           }

        startIndex++; testIndex++;
       }

    return true;
   }

/**
 * @brief Sets lower case to upper case letter
 *
 * @details Only operates on lower case letters; all other letters
 *          are returned unchanged
 *          
 * @param in: test character/letter
 *
 * @note None
 */
char QkSorter::toUpper
       ( 
        char testChar
       )
   {
    if( testChar >= 'a' && testChar <= 'z' )
       {
        testChar = char( testChar - 'a' + 'A' );
       }

    return testChar;
   }

/**
 * @brief Verifies character as digit
 *
 * @details Checks for character digit between '0' and '9'
 *          
 * @param in: test character/letter
 *
 * @note None
 */
bool QkSorter::isDigit
       ( 
        char testDigit  // in: test character/digit
       )
   {
    return ( testDigit >= '0' && testDigit <= '9' );
   }

/**
 * @brief Verifies leap year
 *
 * @details Checks for leap year using standard algorithm
 *          
 * @param in: year value
 *
 * @note None
 */
bool QkSorter::isLeapYear( int year )
   {
    return ( year % 4 == 0 && year % 100 != 0 ) || ( year % 400 == 0 );
   }




#endif // ifndef QkSorter_CPP





