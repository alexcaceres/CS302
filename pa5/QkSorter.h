// Program Information ////////////////////////////////////////////////////////
/**
 * @file QkSorter.h
 *
 * @brief Definition file for QkSorter class,
 *        derived from SorterClass
 * 
 * @author Alexandra Caceres
 * 
 * @details Specifies all member methods of the QkSorter Class
 *
 * @version 1.00 (27 September 2015)
 *
 * @Note Requires DateType.h, SorterClass.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef QKSORTER_H
#define QKSORTER_H

// Header files ///////////////////////////////////////////////////////////////

#include "DateType.h"
#include "SorterClass.h"

// Class definition  //////////////////////////////////////////////////////////

class QkSorter: public SorterClass<DateType>
  {
    public: 

      // local constants
      static const char NULL_CHAR = '\0';
      static const char SPACE = ' ';
      static const int MONTH_NAME_WIDTH = 3;
      static const int MAX_YEAR_ALLOWED = 3000;
      static const int NUM_MONTHS = 12;
      static const int MONTH_NAME_SIZE = 4;

      // Constructors
      QkSorter();
      QkSorter( int initialCapacity ); 
      QkSorter( const SorterClass<DateType> &copiedSorter );

      // Destructor
      virtual ~QkSorter();

      
      // Virtual Functions Defined
       
         // Compare Two elements
         virtual int compareTo( const DateType &lhObject,
                                                  const DateType &rhObject );  

         // Sort List Using compareTo()
         virtual bool sort(); 
         void quickSort(int left, int right);
        void swap( int one,int other);
        
    private:

      // sort success flag
      bool sortSuccess;


      // make usable values for testing
      int makeDate( const char *str );
      int makeMonth( const char *str );
      int makeYear( const char *str );
      int strToInt( int startIndex, const char *str );
      int findSpace( int startIndex, const char *str );
      bool compMonth( const char *testStr, 
                                      int startIndex, const char *testMonth );
      char toUpper( char testChar );
      bool isDigit( char testDigit );
      bool isLeapYear( int year );
  };

  #endif // ifndef QKSORTER_CLASS_H


