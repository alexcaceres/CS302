// Program Information ////////////////////////////////////////////////////////
/**
 * @file HashClass.cpp
 *
 * @brief Implementation file for HashClass class
 * 
 * @details Implements the constructor method of the HashClass class
 *
 * @author Michael Leverington and Alexandra Caceres
 *
 * @version 1.00 (17 November 2015)
 *
 * @Note Requires HashClass.h, SimpleVector.cpp
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef HASH_CLASS_CPP
#define HASH_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "HashClass.h"
#include "SimpleVector.cpp"
#include <new>

using namespace std;

// Class Implementation  //////////////////////////////////////////////////////


/**
* @brief Constructor for HashNode class
*
* @details Constructs the HashNode class
*          Sets data to newData and nextPtr to next;
*
* @param in: &newData, HashNode *next
*
* @note None
*/
template<typename DataType>
HashNode<DataType>::HashNode
       ( 
        const DataType &newData, HashNode *next 
       )
     : data(newData), nextPtr(next)
   {
    // no parameters
   }

/**
* @brief Constructor for HashClass class
*
* @details Constructs the HashClass class
*          Sets tableLength to 0, hashLetterCount to DEFAULT_HASH_LETTER_COUNT
*          and list()
*
* @param in: None
*
* @note None
*/
template<typename DataType>
HashClass<DataType>::HashClass
       (
        // no parameters
       )
     : tableLength(0), hashLetterCount(DEFAULT_HASH_LETTER_COUNT), list()
   {
    // data placed in initializers
   }

/**
* @brief Copy Constructor
*
* @details tableLength and hashLetterCount are defaulted
*
* @param in: hashtable to be copied 
*
* @note Uses the assignment operator (*this = copied)
*/           
template<typename DataType>
HashClass<DataType>::HashClass
       ( 
        const HashClass<DataType> &copied 
       )
     :tableLength(copied.tableLength), 
       hashLetterCount(copied.hashLetterCount), list(copied.tableLength)
   {
    *this = copied;
   }

/**
* @brief Destructor
*
* @details Deletes list by calling clearList();
*
* @param None
*
* @note Uses clearList function
*/
template<typename DataType>
HashClass<DataType>::~HashClass
       (
        // no parameters
       )
   {
    clearList();
   }

/**
* @brief Overloaded Assignment Operator
*
* @details Is used in the copy constructor
*
* @param in: &rhHashTable
*
* @note Uses many additional functions such as isEmpty(), clearList(), and copy slot
*/
template <typename DataType>
const HashClass<DataType>& HashClass<DataType>:: operator = 
                                              ( const HashClass &rhHashTable )
   {
   
    int index;
    if(this != &rhHashTable)
    {   
        if(!isEmpty())
        {
            clearList();
        }
            
            setTableLength(rhHashTable.tableLength);
            hashLetterCount = rhHashTable.hashLetterCount;
          
    
        for(index = 0; index < tableLength; index++)
        {
            copySlot(rhHashTable.list[index], index);
        }

    }
   
    return *this;
 
   }

/**
* @brief Sets the length for the hashTable
*
* @details uses grow and shrink to resize
*          size corresponds with table length
*
* @param in: int newTableLength
*
* @note None
*/
template <typename DataType>
void HashClass<DataType>::setTableLength
       ( 
        int newTableLength
       )
   {
        int index;
        tableLength = newTableLength;
        
        for(index = 0; list.getSize() < tableLength; index++)
        {
            list.incrementSize();
        }
        
            if(list.getCapacity() > tableLength)
            {
                list.shrink(list.getCapacity() - tableLength);
            }
            
            else if(list.getCapacity() < tableLength)
            {
                list.grow(tableLength - list.getCapacity());
            }
        
   }

/**
* @brief Sets the letter count for the hash
*
* @details sets hashLetterCount = newHashLetterCount
*
* @param in: int newHashLetterCount
*
* @note None
*/
template <typename DataType>
void HashClass<DataType>::setHashLetterCount
       ( 
        int newHashLetterCount
       )
   {
    hashLetterCount = newHashLetterCount;
   }

/**
* @brief Adds item to the hashTable
*
* @details adds item to the hashtable
*          using three pointers of HashNode<DataType>
*          returns true if the item was added
*          
* @param in: &newData
*
* @note None
*/
template <typename DataType>
bool HashClass<DataType>::addItem
       ( 
        const DataType &newData 
       )
   {
   
    HashNode<DataType> *before = NULL;
    HashNode<DataType> *working;
    HashNode<DataType> *newNode;
    
    int index = hash(newData) % tableLength;
    working = list[index];
    
    newNode = new HashNode<DataType> (newData, NULL);
    
    if(!newNode)
    {
    return false;
    }
    
        while(working)
        {
            before = working;
            working = working->nextPtr;
        }


        if(before)
        {
            before->nextPtr = newNode;
        }
        else
        {
            list[index] = newNode;
        }
        
    return true;
   }

/**
* @brief Finds an item in the hash table
*
* @details if item is found, returns true
*          HashNode<DataType> pointer
*          returns false if no item is found
*
* @param in: &dataItem
*
* @note None
*/
template <typename DataType>
bool HashClass<DataType>::findItem
       ( 
        const DataType &dataItem
       ) const
   {
     
     HashNode<DataType> *lookUp = NULL;
     int index = hash(dataItem) % tableLength;
     lookUp = list[index];

    while(lookUp)
    {
        if(lookUp->data.compareTo(dataItem) == 0)
        {
            return true;
        }
        
        lookUp = lookUp->nextPtr;
    }

    return false;
   }

/**
* @brief Removes an item from the hash table
*
* @details if item found and removed, returns true
*          if item is not found and no removal, returns false
*
* @param in: &dataItem
*
* @note None
*/

template <typename DataType>
bool HashClass<DataType>::removeItem
       ( 
        const DataType &dataItem 
       )
   {
    
    bool changeH;
    int index = hash(dataItem) % tableLength;
    
    HashNode<DataType> *before = NULL;
    HashNode<DataType> *& head = list[index];
    HashNode<DataType> *lookUp;
    lookUp = head;

    while(lookUp)
    {
        changeH = (lookUp == head);
        
        if(lookUp->data.compareTo(dataItem) == 0)
        {
            if(changeH)
            {
                head = head->nextPtr;
            }
            else if(before)
            {
                before->nextPtr = lookUp->nextPtr;
            }

            delete lookUp;
            before = lookUp = NULL;

            return true;
        }

        before = lookUp;
        lookUp = lookUp->nextPtr;
    }

    return false;

   }


/**
* @brief Checks if hash table's list is empty
*
* @details if the list is empty, returns true, if not returns false
*
* @param None
*
* @note None
*/
template<typename DataType>
bool HashClass<DataType>::isEmpty
       ( 
        // no parameters
       ) const
   {
    
    int check;

        for(check = 0; check < tableLength; check++)
        {
            if(list[check])
            {
                return false;
            }
        }   

    return true;
    
   }

/**
* @brief Finds the mean chain length
*
* @details Uses a HashNode<DataType> pointer, an integer to keep track and then an index integer
*
* @param None
*
* @note Retrieves the chain length by going through the linked lists
*/
template<typename DataType>
double HashClass<DataType>::getChainLengthMean
       ( 
        // no parameters
       ) const
   {
   
        HashNode<DataType> *findMean = NULL;
        int track = 0;
        int index;
   
            for(index = 0; index < tableLength; index++)
            {
                findMean = list[index];
        
                while(findMean)
                {
                    track++;
                    findMean = findMean->nextPtr;
                }
            }
   
           return track/tableLength;
   }

/**
* @brief Finds the chain length median
*
* @details HashNode<DataType> pointer, count integer, and index integer
*          Counts the length of each chain and then compares
*          Returns the median chain length(max/2)
*
* @param in: None
*
* @note None
*/
template<typename DataType>
double HashClass<DataType>::getChainLengthMedian
       ( 
        // no parameters
       ) const
   {
    
    
    HashNode<DataType> *working;
    
    int count;
    int max = 0;
    int index = 0;
    
    for(int index = 0; index < tableLength; index++)
    {
        count = 0;
        working = list[index];
        
        if(working != NULL)
        {
            while(working->nextPtr != NULL)
            {
                count++;
                working = working->nextPtr;
            }
            
            count++;
        }
            if(count > max)
            {
                max = count;
            }
    }
    
    return max/2;

    
   }

/**
* @brief Shows the structure of the hash table
*
* @details Uses a for loop to print out the hashtable
*
* @param None
*
* @note Accesses the printSlot function to correctly show the structure
*/
template<typename DataType>
void HashClass<DataType>::showStructure
       (
       ) const 
   {
        int index;
        
        for(index = 0; index < tableLength; index++)
        {
            printSlot(list[index]);
        }
   }
 
      
/**
* @brief Clears the lists in the hash table
*
* @details Uses a for loop and within the for loop, calls the delete slot function
*          This deletes the linked lists in the hash table
*
* @param None
*
* @note None
*/
template<typename DataType>
void HashClass<DataType>::clearList()
    {
    
        int index;
    
            for(index = 0; index < tableLength; index++)
                {
                    deleteSlot(list[index]);
                }
    }


template<typename DataType>
int HashClass<DataType>::hash
       (
        const DataType &dataItem
       )
   {
        DataType tempData( dataItem );
    
        return tempData.hash( hashLetterCount, tableLength );
   }

/**
* @brief Prints the linked list
*
* @details The contents of the list are printed
*          If the list is empty, NULL is printed out
*          Uses get account in order to retrieve the information
*
* @param in: HashNode<DataType> *slot
*
* @note 
*/
template<typename DataType>
void HashClass<DataType>::printSlot(const HashNode<DataType> *slot) const
{
    char name[STD_STR_LEN];
    char dummy[10];
    char secdummy;

    if(!slot)
    {
        cout << "NULL" << endl;
    }
    else
    {
        while(slot)
        {
            slot->data.getAccount(name, dummy, secdummy);

            cout << "[ " << name << " ] ";
            slot = slot->nextPtr;
        }
        cout << endl;
    }
}


/**
* @brief Copies a linked list to the object
*
* @details Adds items to the list in the order they are found
*
* @param in: HashNode<DataType> *slot, int index
*
* @note None
*/
template <typename DataType>
void HashClass<DataType>::copySlot(const HashNode<DataType> *slot, int index)
{
    while(slot)
    {
        if(!addItem(slot->data)) // memory check
        {
            return;
        }
    
            slot = slot->nextPtr;
    }
}

/**
* @brief Deletes linked list
*
* @details deletes one list
*
* @param in: HashNode<DataType> *&slot
*
* @note None
*/
template<typename DataType>
void HashClass<DataType>::deleteSlot(HashNode<DataType> *&slot)
{
    
    HashNode<DataType> * working;
    while(slot)
    {
        working = slot;
        slot = slot->nextPtr;
        delete working;
        working = NULL;
    }
}

#endif	// define HASH_CLASS_CPP





