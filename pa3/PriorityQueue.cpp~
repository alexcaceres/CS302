// Program Information ////////////////////////////////////////////////////////
/**
 * @file PriorityQueue.cpp
 * 
 * @author Alexandra Caceres
 *
 * @brief Implementation file for PriorityQueue class
 * 
 * @details Implements all member methods of the PriorityQueue class
 *
 * @version 1.00 (16 September 2015)
 *
 * @Note Requires PriorityQueue.h
 */
 
// Header files /////////////////////////////////////////////////////////////// 
 
#include "PriorityQueue.h"
#include <iostream>

using namespace std;

/**
 * @brief Default constructor
 *
 * @details Constructs rear to 0 
 *          
 * @param None
 *
 * @note rear is set to 0
 */
template <class DataType> 
PriorityQueue<DataType>::PriorityQueue() 
    : rear(0) {}

/**
 * @brief Copy constructor
 *
 * @details sets rear and queue to loc.rear and loc.Queue
 *          
 * @param loc which is the parameter
 *
 * @note 
 */    
template<class DataType>
PriorityQueue<DataType>::PriorityQueue(const PriorityQueue &loc)  
    : rear(loc.rear), Queue(loc.Queue) {}

/**
 * @brief Destructor
 *
 * @details It sets the front and rear to default values of 0
 *          
 * @param None
 *
 * @note 
 */
template<class DataType>
PriorityQueue<DataType>::~PriorityQueue()
    {
        rear = 0;
    }

/**
 * @brief Assignment Operator
 *
 * @details Assigns the date from right hand object to this object
 *          
 * @param &src
 *
 * @note if this != &src, then the assignment occurs
 */
template<class DataType>
const PriorityQueue<DataType>&PriorityQueue<DataType>::operator = (const PriorityQueue& src)
    {
        
        if(this != &src)
            {
                Queue = src.Queue;
            }
             return *this;
    }
    
/**
 * @brief queue size accessor
 *
 * @details returns size of this vector
 *          
 * @param None
 *
 * @note None
 */
template<class DataType>
int PriorityQueue<DataType>::getSize() const
    {
        return Queue.getSize();
    }

/**
 * @brief Checks if it is empty
 *
 * @details returns true if the size ==0
 *          
 * @param None
 *
 * @note None
 */
template<class DataType>
bool PriorityQueue<DataType>::isEmpty() const
    {
    // if the size is equal to 0, then there is a return of true because the list is empty
    if(getSize()== 0)
        {
            return true;
        }
        else
            {
                return false;
            }
    }

/**
 * @brief Takes the position back to the front of the queue
 *
 * @details returns to the beginning of the queue
 *          
 * @param object parameter 
 *
 * @note An exception handling error is thrown
 */
template <class DataType>
void PriorityQueue<DataType>::peekAtFront(DataType& object) throw ( logic_error )
    {
        if(!isEmpty())
            {
                object = Queue[Front];
            }
            else 
            {
                // exception handling
                throw logic_error("Peek has failed. The queue is empty.");
            }
    }

/**
 * @brief Shows the structure of what is being compiled 
 *
 * @details Prints out the prioritized queue
 *          
 * @param PQueue
 *
 * @note Checks if the list is not empty before printing
 */
template <class DataType>
void PriorityQueue<DataType>::showStructure(char PQueue)
    {
       int index;
       
       if(!isEmpty())
       {
            cout << "  List " << PQueue;
            cout << " ( " << rear << "/" << Queue.getCapacity() << "):";
            for( index = 0; index < getSize(); index++)
            {             
                 // the priority and the process is accessed to prin
                 cout << "[" << Queue[index].priority << "/" << Queue[index].process << "]";   
            }         
        }
           else 
           {
                cout << "  Empty List";
           }
                cout << endl;
    }

/**
 * @brief Enqueue function
 *
 * @details Allows for data to be added into the list
 *          
 * @param Priority and Process
 *
 * @note An exception handling error is thrown
 */
template <class DataType>
bool PriorityQueue<DataType>:: enqueue(int Priority, char* Process) throw (logic_error)
    {
        //int index;
        //int newIndex;
     
        DataType objectA (Priority, Process);
        //DataType objectB = Queue[rear];
        
        // enqueues at the front
            if( isEmpty())
                {
                    rear += 1;
                    Queue[Front] = objectA;
                    Queue.incrementSize();
                    return true;
                }
           
                // checks for the bounds
                
                if( Priority > 5 || Priority < 1)
                    {    
                         throw logic_error("Priority is out of range");
                    }
                  
                    if(Queue.getSize() == Queue.getCapacity())
                        {
                            Queue.grow(Queue.getCapacity());
                  
                        }    
                     if( Priority >= Queue[Front].priority)
                        {
                            Queue[rear] = objectA;
                            Queue.incrementSize();
                            rear += 1;
                            return true;
                         }
                     else
                     {
                     Queue[rear] = objectA;
                     Queue.incrementSize();
                     rear +=1;
                      
                     }                           
                    // resize the queue 
                    // my attempt at fixing the enqueue        
                 
                          /*   for(index = 0; index < Queue.getSize(); index++)
                                {
                                    if(Priority < Queue[index-1].priority)
                                        {
                                            for(newIndex = rear; newIndex > index; index--)
                                            {
                                                Queue[newIndex] = Queue[newIndex-1];
                                               
                                            }
                                        
                                       Queue[index] = objectA;
                                       Queue[rear+1] = objectB;
                                          
                                        }
                                } 
                                
                            Queue[rear+1] = objectA;
                            Queue.incrementSize();
                            rear +=1;
                            */
                            return true;
}

/**
 * @brief Dequeue function
 *
 * @details Removes data items from list
 *          
 * @param priority
 *
 * @note Throws an exception handling error
 */
template <class DataType>
bool PriorityQueue<DataType>:: dequeue(DataType priority) throw (logic_error)
    {
        int index;
        if( isEmpty())
            {
                priority = Queue[Front];
                // if the list is empty, an error is thrown because there can be no dequeue
                throw logic_error("Queue is Empty" );
            }
            
            for(index = Front; index < rear; index++)
                {
                    Queue[index] = Queue[index+1];
                }
                // decrements rear
                rear--;
                return true;
    }

// Terminating precompiler directives  ////////////////////////////////////////
       
