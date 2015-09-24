// Program Information ////////////////////////////////////////////////////////
/**
 * @file PriorityQueue.h
 *
 * @brief Definition file for PriorityQueue class
 * 
 * @author Alexandra Caceres
 * 
 * @details Specifies all member methods of the PriorityQueue class
 *
 * @version 1.00 (16 September 2015)
 *
 * @Note None
 */
 
// Header files ///////////////////////////////////////////////////////////////
 
#include <iostream>
#include "SimpleVector.h"

using namespace std;

// Class constants /////////////////////////////////////////////////////////////

template <class DataType>
class PriorityQueue{
        public:
        
        
       //Internal Constant
        static const int Front = 0;
      
        
       //Constructors
       
       PriorityQueue();
       PriorityQueue(const PriorityQueue &copiedQueue);
               
       //Destructors
               
       ~PriorityQueue();
       
       //Assignment Operator
       const PriorityQueue& operator=(const PriorityQueue &newQueue);
       
       // Modifiers
       bool enqueue(int Priority, char* Process) throw (logic_error);
       bool dequeue(DataType priority) throw (logic_error);
       
       //Accessor
       int getSize() const; 
       
       // checks if the list is clear and empty
       bool clear();
       bool isEmpty() const;
       
       // allows for the beginning of the list to be peeked at
       void peekAtFront (DataType& data) throw (logic_error);
       
       //print function
       void showStructure( char  PQ);
                
        private:
        
                
                int rear;
                SimpleVector<DataType> Queue;
};

// Terminating precompiler directives  ////////////////////////////////////////
