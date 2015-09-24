// Program Information ////////////////////////
/*
    File Name:      SimpleVector.cpp
    
    Description:    Implementation for a Vector
*/
// Version Revision Information //////////////
/*
    1.00 (09/09/2015) - Alexandra Caceres
*/

//////// Header files ////////

#include "SimpleVector.h"

//////// Function Implementations ////////



//////// Constructors ////////


/**
* @brief Implementation of SimpleVector default constructor
*
* @details Default constructor for SimpleVector class
*
* @param None
*
* @note vectorCapacity, and vectorSize
*/

template <class DataType>
SimpleVector<DataType>::SimpleVector() : vectorCapacity(10), vectorSize(0)
    {
        vectorData = new DataType[vectorCapacity];    
    }

/**
* @brief Implementation of SimpleVector parameterized constructor
*
* @details Paramaterized constructor for SimpleVector class
*
* @param newCapacity
*
* @note vectorCapacity, vectorSize, vectorData
*/

   
template <class DataType>
SimpleVector<DataType>::SimpleVector( int newCapacity ):vectorCapacity(newCapacity),vectorSize(0), vectorData(NULL)
    {
       if(vectorCapacity > 0)
        {
            vectorData = new DataType[newCapacity];
        }
    }
  
/**
* @brief Implementation of SimpleVector parameterized constructor
*
* @details Paramaterized constructor for SimpleVector class
*
* @param newCapacity and fillValue
*
* @note vectorCapacity, vectorSize, vectorData
*/  
    
template <class DataType>   
SimpleVector<DataType>::SimpleVector( int newCapacity, const DataType &fillValue ) : vectorCapacity(newCapacity),vectorSize(0),vectorData(NULL)
    {
        int buffer;
       
        if(vectorCapacity > 0)
        {
            vectorData = new DataType[newCapacity];
        }
                for(buffer = 0; buffer < vectorCapacity; buffer++)
                {   
                    vectorData[buffer] = fillValue;
                    incrementSize();
                }
        
    }

/**
* @brief Implementation of SimpleVector copy constructor
*
* @details Copy constructor for SimpleVector class
*
* @param copiedVector
*
* @note vectorData
*/  

template <class DataType>    
SimpleVector<DataType>::SimpleVector( const SimpleVector &copiedVector ) : vectorData(NULL)
    { 
        *this = copiedVector;
    }
    
/**
* @brief Implementation of SimpleVector destructor
*
* @details Destructor for SimpleVector class
*
* @param none
*
* @note The data is deleted
*/      

template <class DataType>
SimpleVector<DataType>::~SimpleVector( )
    {
        delete[] vectorData;
    }
    
//////// Assignment operator ///////  

/**
* @brief Implementation of SimpleVector assignment operator
*
* @details Assignment operator for SimpleVector class
*
* @param rhVector
*
* @note The data is copied from one vector to another vecotr
*/  

template <class DataType> 
const SimpleVector<DataType>& SimpleVector<DataType>::operator=( const SimpleVector &rhVector ) 
    {
        vectorCapacity = rhVector.getCapacity();
        if(this != &rhVector)
        {
          vectorSize = rhVector.getSize();
                
            if(vectorData != NULL)
            {
                delete vectorData;
                vectorData = NULL;
            }
            if(vectorCapacity > 0)
            {
                vectorData = new DataType[vectorCapacity];
                copyVector(vectorData, rhVector.vectorData);
            }
        }
            return *this;
            
} 

////////  Access function retrieves the capacity ////////

/**
* @brief Implementation of SimpleVector accessors
*
* @details getCapacity accessor for SimpleVector class
*
* @param None
*
* @note Retrieves the capacity
*/  
            
template <class DataType>
int SimpleVector<DataType>::getCapacity() const
    {
        return vectorCapacity;
    }

//////// Access function retrieves the size ////////

/**
* @brief Implementation of SimpleVector accessors
*
* @details getSize accessor for SimpleVector class
*
* @param None
*
* @note Retrieves the vector size
*/  

template <class DataType>
int SimpleVector<DataType>::getSize() const
    {
        return vectorSize;
    }
    
//////// Index access ////////

/**
* @brief Implementation of SimpleVector index access functions
*
* @details Index access function for SimpleVector class
*
* @param index
*
* @note Throws a logic error if the index is invalid and returns the index of the vectorData
*/  

template <class DataType>
DataType & SimpleVector<DataType>::operator [ ] ( int index ) throw ( logic_error )
    {
        if(index == vectorSize)
        {
            grow(1);
        }
        else if(index > vectorCapacity)
        {
            throw logic_error("Index invalid.");
        }
        
         return vectorData[index];
    }
    
/**
* @brief Implementation of SimpleVector index access function
*
* @details Index access function for SimpleVector class
*
* @param index
*
* @note throws a logic error if the index is invalid and returns the index of the vectorData
*/     

template <class DataType>
const DataType & SimpleVector<DataType>::operator [ ] ( int index ) const throw ( logic_error )
    {
        if(index < 0 || index >= vectorCapacity)
        {
            throw logic_error("Index invalid.");
        }
            return vectorData[index];
    }

//////// The vector will grow by a given quantity ////////

/**
* @brief Implementation of SimpleVector grow function
*
* @details Grow function for SimpleVector class
*
* @param growBy
*
* @note Allows the vector to grow by a given quantity
*/  
 
template <class DataType>
void SimpleVector<DataType>::grow( int growBy )
    {
        // allows for a greater capacity
       
        int newCapacity = vectorCapacity + growBy;
        
        // new memory is allocated
        
        DataType* tempVector = new DataType[newCapacity];
            if( vectorSize > 0)
            {    
                copyVector(tempVector,vectorData);
                delete[] vectorData;
                vectorData = tempVector;
            }       
 
    }
 
//////// The vector will shrink by a given quantity ////////

/**
* @brief Implementation of SimpleVector shrink function
*
* @details Shrink function for SimpleVector class
*
* @param shrinkBy
*
* @note Allows vector to be shrunk to zero but will throw a logic error if an attempt to shrink to less than zero is made
*/  

template <class DataType>
void SimpleVector<DataType>::shrink( int shrinkBy ) throw ( logic_error )
    {
        // used to create a smaller capacity
        
        int newCapacity = vectorCapacity - shrinkBy;
        DataType* tempVector;
        
            if(shrinkBy > vectorCapacity)
                {
                    // throws error if a size smaller than zero is attempted
                    
                    throw logic_error ("Not able to shrink");
                }
            
            vectorCapacity = newCapacity;
            
            // allocates new memory
            tempVector = new DataType[newCapacity];
                
                if(vectorSize > vectorCapacity)
                    {
                        vectorSize = vectorCapacity;
                    }
                if( vectorCapacity > 0)
                    {
                        copyVector(tempVector, vectorData);
                        delete[] vectorData;
                        vectorData = tempVector;
                    }
                 
     }
//////// Increments the size ////////

/**
* @brief Implementation of SimpleVector increment size function
*
* @details Increment size function for SimpleVector class
*
* @param none
*
* @note The size is incremented
*/  
   
template <class DataType>
void SimpleVector<DataType>::incrementSize()
    {
        vectorSize++;  
    }
 
//////// Decrements the size /////////

/**
* @brief Implementation of SimpleVector decrement size function
*
* @details Decrement size function for SimpleVector class
*
* @param none
*
* @note The size is decremented
*/  

template <class DataType>
void SimpleVector<DataType>::decrementSize()
    {
        vectorSize--;
    }
 
//////// copies the vector ////////

/**
* @brief Implementation of SimpleVector copy vector function
*
* @details Copy vector function for SimpleVector class
*
* @param DataType *dest, DataType *src
*
* @note The vector is copied
*/  

template <class DataType>
void SimpleVector<DataType>::copyVector( DataType *dest, DataType *src )
    {
        int newCopy = 0;
        for(newCopy= 0; newCopy < vectorSize; newCopy++)
        {
            // copies the data in the vector over
            dest[newCopy] = src[newCopy];
        }
    }
