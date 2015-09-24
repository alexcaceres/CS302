 // Program Information ////////////////////////////////////////////////////////
/**
 * @file TestSorter.cpp
 * 
 * @brief Implementation file for TestSorter
 * 
 * @author Alexandra Caceres
 *
 * @details Implements all member methods of the TestSorter
 *
 * @version 1.00 (23 September 2015)
 *
 * @Note Requires SorterClass.h, TestSorter.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef TESTSORTER_CPP
#define TESTSORTER_CPP

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include "TestSorter.h"


/**
 * @brief Default constructor
 *
 * @details Constructs testsorter class with default sorterclass class initialization
 *          
 * @param None
 *
 * @note None
 */
 
TestSorter::TestSorter() : SorterClass<DateType>()
{
}
          
/**
 * @brief Initialization constructor
 *
 * @details Constructs sorter class with specified sorter class initialization
 *          
 * @param initial
 *
 * @note None
 */
TestSorter::TestSorter (int initial) : SorterClass<DateType>(initial)
{
}           

/**
 * @brief  Copy constructor
 *
 * @details Constructs sorter class with copied object
 *          
 * @param in: initial capacity
 *
 * @note None
 */
TestSorter::TestSorter (const TestSorter& copied) : SorterClass<DateType>(copied)
{

}


/**
 * @brief Class destructor
 *
 * @details Destructs testsorter class
 *          
 * @param in: None
 *
 * @note Implements SimpleVector destructor
 */
TestSorter::~TestSorter()
{
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
int TestSorter::compareTo( const DateType &lhObject,  const DateType &rhObject)
    {
    // variables to check the index, spacing and values
    int index1 = 0;
    int index2 = 0;
    int space1 = 0;
    int space2 = 0;
    int value1 = 0;
    int value2 = 0;
  
  
 // If i remove the while, it goes through the function but I dont think it compares them, if I leave the while, it begins to loop infinitely
 cout << "Happiness" << endl;
    while((lhObject.date[index1] != '\0') && (rhObject.date[index2] != '\0'))
        {
      
        if(space1 != 2)
            {
                index1++;
            }
        if(space2 != 2)
            {
                index2++;
            }
         
        if(lhObject.date[index1] == ' ')
            {
                space1++;
                index1++;
            }
        
        if(rhObject.date[index2] == ' ')
            {
            space2++;
            index2++;
            } 
        
      if(( space1 == 2) && (space2 == 2))
            {

                value1 = 0;
                value2 = 0;
                
                 
                while(lhObject.date[index1] != '\0');
                {
               
                    value1 *= 10;
                    value1 += lhObject.date[index1] - '0';
                    index1++;
                      
                }
                 
                while(rhObject.date[index2] != '\0');
                    {
                        value2 *= 10;
                        value2 += rhObject.date[index2] - '0';
                        index2++;
                    }
                if(value1 > value2)
                    {
                        return 1;
                    }
                
                if(value1 < value2)
                    {
                        return -1;
                    }
             }
         }
         

         index1 = 0;
         index2 = 0;
         space1 = 0;
         space2 = 0;
            cout << " Happiness2" << endl;    
                while(( lhObject.date[index1] != ' ') && (rhObject.date[index2] != ' '))
                {
                    if(space1 != 1)
                    {
                        index1++;
                    }
                    if(space2 != 1)
                    {
                        index2++;
                    }
                    
                    if(lhObject.date[index1] == ' ')
                    {
                        space1++;
                        index1++;
                    }
                     if(rhObject.date[index2] == ' ')
                    {
                        space2++;
                        index2++;
                    }
                   
                    if(( space1 == 1) && (space2 == 1))
                    {

                value1 = getMonth(lhObject.date, index1);
                value2 = getMonth(rhObject.date, index2);
                
                if(value1 > value2)
                {
                    return 1;
                }
                
                if(value1 < value2)
                    {
                        return -1;
                    }
                if( value1 == value2)
                {
                    break;
                }
            }
       }
              

    index1 = 0;
    index2 = 0;

    value1 = lhObject.date[index1] - '0';
    if(( lhObject.date[index1 - 1] == '9' ) && (rhObject.date[index1 - 1] == '0'))
        {
            value1 *= 10;
            value1 += lhObject.date[index1 - 1] - '0';
        }
     
         value2 = rhObject.date[index2] - '0';
         if(( rhObject.date[index2 - 1] == '9' ) && (lhObject.date[index2 - 1] == '0'))
            {
        value2 *= 10;
        value2 += rhObject.date[index2 - 1] - '0';
            }

         if(value1 > value2)
                {
                    return 1;
                }
                
                if(value1 < value2)
                    {
                        return -1;
                    }
                
                return 0;
 }

/**
 * @brief  Bubble Sort Function
 *
 * @details Sorts the data and checks for a swap of the data
 *          
 * @param in: none
 *
 * @note None
 */        
bool TestSorter::sort()
{
    DateType lhObject;
    DateType rhObject;
    DateType temp;
    int index = 0;
    bool swap;
    
    
        // do while with a swap
        do
        { swap = false;
        
            
        for(index = 0; index < ((*this).getSize() - 1) ; index++) 
            {
                // obtains the value
                (*this).getValueAt(index, lhObject);
                (*this).getValueAt(index+1, rhObject);

                    if( compareTo(lhObject, rhObject) == 1)
                        {

                          temp = lhObject;
                          // sets the value
                          (*this).setValueAt(index, rhObject);
                          (*this).setValueAt(index+1, temp);
                          swap = true;
                         }
                   
            }
      
       }
      while(swap);
      
      return true;
      }

/**
 * @brief  String copy
 *
 * @details Copies one string into another string
 *          
 * @param in: char* dest, char* src
 *
 * @note None
 */
void TestSorter:: strcopy(char* dest, char* src)
{
    int index;
    for( index = 0; index < (*this).getSize(); index++);
        {
        dest[index] = src[index];
        }
}

 /**
 * @brief  String Compare
 *
 * @details Compares one string to another string
 *          
 * @param in: char* string1, char* string2
 *
 * @note None
 */
bool TestSorter:: strcomp(char* string1, char* string2)
{
   int index = 0;
   while(string1[index] != '\0' && string2[index] != '\0')
    {
      if(string1[index] != string2[index])
        {
            return false;
        }
        index++;
    }
    if(string1[index] == string2[index])
        {
            return true;
        }
        return false;    
}

/**
 * @brief  String length function
 *
 * @details Returns the length of the string
 *          
 * @param in: char* string
 *
 * @note None
 */
int TestSorter:: strlength(char* string)
{
        int length;
        while((*string) != '\0')
        {
           string++;
           length++;
        }
        return length; 
}

/**
 * @brief  Get month function
 *
 * @details Retrieves the month by checking the first 3 letters of the month
 *          
 * @param in: const char *date, int &index
 *
 * @note Checks within if statements for the first letter and then moves on to the second if the letter is a multiple of the months
 */
int TestSorter:: getMonth(const char *date, int &index)
{
     char tempMonth[10];
     int numMonth = 0;
     int secIndex = 0;
     
     
     index++;

     while(date[index] != ' ')
     {
      tempMonth[secIndex] = date[index];
      index++;
      secIndex++;     
     }   
      tempMonth[secIndex] = '\0';
      secIndex = 0;
      
      
      
      if(tempMonth[0] == 'J' || tempMonth[0] == 'j')
        {
           if(tempMonth[1] == 'a')
                {
                    return numMonth - 1; // January
                }
           if(tempMonth[1] == 'u')
                {
                    if(tempMonth[2] == 'n')
                        {
                            return numMonth - 6;  // June
                        }
                 
                                return numMonth - 7;  // July
                }
         }
         
         
       if(tempMonth[0] == 'F' || tempMonth[0] == 'f')                          
         {
            return numMonth - 2;  // February         
         }     
              
       if(tempMonth[0] == 'M' || tempMonth[0] == 'm')      
         {
            if(tempMonth[2] == 'y')
                {
                    return numMonth - 5;  // May
                }
                    return numMonth - 3;  // March
                    
         }
        
       if(tempMonth[0] == 'A' || tempMonth[0] == 'a')
          {
            if(tempMonth[1] == 'p')
              {
                 return numMonth - 4;   // April
              }
                 return numMonth - 8;    // August
                            
          }
       
       if(tempMonth[0] == 'S' || tempMonth[0] == 's') 
          {
            return numMonth - 9;
          }
                 
       if(tempMonth[0] == 'O' || tempMonth[0] == 'o')
          {
            return numMonth - 10;
          }
  
       if(tempMonth[0] == 'N' || tempMonth[0] == 'n')
          {
            return numMonth - 11;
          }
            return numMonth - 12;
                                                  
}
        
        
#endif
