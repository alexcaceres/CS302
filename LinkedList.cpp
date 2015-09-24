// Program Information ////////////////////////
/*
    File Name:      LinkedList.cpp
    
    Description:    Implementing a Linked List Class
*/
// Version Revision Information //////////////
/*
    1.00 (09/02/2015) - Alexandra Caceres
*/

//////// Header files ////////

#include "ListNode.h"
#include "LinkedList.h"

//// Function Implementations ////



//// Default constructor ////

LinkedList::LinkedList (int maxSize)
    {
        head = cursor = NULL;
        size = 0;
        capacity = maxSize; 
    }

//// Copy Constructor ////

LinkedList::LinkedList (const LinkedList& other)
    {
        head = cursor = NULL;
        size = 0;
        this->isAssigned(other);
    }

//// Deconstructor ////

LinkedList::~LinkedList()
    {
        ListNode* temp;
        if(!isEmpty())
	    {
		    cursor = temp = head;
	    }
	
	        while(temp != NULL)
	        {
	            int dummy;
	            removeAtCursor(dummy);
	            temp = head;		
	
	        }
    }

//// Inserts data items before the cursor ////

bool LinkedList::insertBeforeCursor( int newDataItem )
    {
        ListNode* search = NULL;
        ListNode* newNode = NULL;
 
        if(!isFull())
  	        {
  	            newNode = new ListNode(newDataItem, NULL);
  	        if(isEmpty())
  	            {
  	                head = cursor = newNode;
  	            }
  	            else if(head == cursor)
  	                {
  	                    newNode->next = cursor;
  	                    head = cursor;
  	                    head = newNode;
  	                    cursor = newNode;
  	                }
  	                else
  	                    {
  	                        search = cursor;
  	                        goToPrior();
  	                        cursor->next = newNode;
  	                        newNode->next = search;
  	                        cursor = newNode;
  	                    }
  	
                        	size++;
  		
  	                        search = NULL;
  	                        newNode = NULL;
  	
  	            return true;
  	        }
  	
  	return false;
    }  

//// Inserts data after the cursor ////

bool LinkedList::insertAfterCursor( int newDataItem )
    {
	    if(isFull())
	        {
	        	return false;
	        }
	        if(isEmpty())
		        {
			        head = new ListNode(newDataItem, NULL);
			        cursor = head;
			        size++;
			        return true;
		        }
			
			        cursor->next = new ListNode(newDataItem, cursor->next);
			        size++;
			        cursor = cursor->next;
			        return true;
	
    }
 
bool LinkedList::replaceBeforeCursor( int newDataItem )    
    {    
        ListNode* temp = NULL;
 		    if(isEmpty() || cursor == head)
 		        {
 			        return false;
		        }
			
 				temp = cursor;
 				goToPrior();
 				cursor->dataItem = newDataItem;
 				cursor = temp;
 				temp = NULL;
 			
 	    return true;			
    }
    
//// Replaces the data item where the cursor is located ////
   
 bool LinkedList::replaceAtCursor( int newDataItem )
    {
 	    if(isEmpty())
 			{ 
 			    return false;
 			}
 				else
 				    {
 				        cursor->dataItem = newDataItem;
 				    }
 			
 		return true;
    }
    
//// Replaces the data item after the cursor ////
    
bool LinkedList::replaceAfterCursor( int newDataItem )
    {
		if(goToNext() == true)
			{
				cursor-> dataItem = newDataItem;
			}
			
			return true;
    }	

//// Removes the data item at the cursor ////

bool LinkedList::removeAtCursor( int &dataVal )
    {
        if(!isEmpty())
	        {
		        if(head == cursor)
		            {
			            cursor = cursor->next;
			            head->next = NULL;
			            delete head;
			            head = cursor;
			            size--;
			            return true;
		            }
	                    else if( cursor-> next == NULL)
	                        {
	                        	ListNode* temp = cursor;
	                        	goToPrior();
	                        	cursor->next = NULL;
	                        	delete temp;
	                        	size--;
	                        	return true;
	                        }
		                 else    
	                        {
			                    ListNode* temp = cursor;
			                    goToPrior();
	                            cursor->next = temp->next;
			                    temp->next = NULL;
			                    delete temp;
		                        if(cursor->next != NULL)
                                    {
			                        cursor = cursor->next;
		                            size--;
	                                return true;
			                        }
		
	                        }
	          }
	return false;
    
}
 
//// Clears the list ////

void LinkedList::clear()
    {
     	int temp;
    	while(!isEmpty())
    	{
		removeAtCursor(temp);
 	    }
    }
   
//// Used for the assignment operator and the copy constructor ////    

LinkedList& LinkedList::isAssigned( const LinkedList& other )
    {
    clear();
        if(!other.isEmpty())
       	{
        		ListNode* temp;
        		ListNode* temporary;
        		temp = cursor = head = new ListNode(other.head->dataItem, NULL);
        		temporary = other.head->next;  
    	while(temporary != NULL)
    		{
		    	temp-> next = new ListNode(temporary->dataItem, NULL);
		    	temp = temp-> next;
		    	temporary = temporary->next;
		if( temporary == other.cursor)
		    {
		    	cursor = temp;
		    }
		        temporary = temporary->next; 
	        }
	    }
		    else 
		    {
		        head = NULL;
		        cursor = NULL;
		    }
	                return *this;
    }
    
//// Assignment operator ////

LinkedList& LinkedList::operator = ( const LinkedList& other )
    {
	    return this->isAssigned(other);
    }   

//// Retrieves the data at the cursor ////

bool LinkedList::getDataAtCursor( int &dataVal ) const
    {	
	    if(!isEmpty())
		    {
		    dataVal =cursor->dataItem;
		    return true;
		    }
		
	        return false;
    }

//// Print Function ////

void LinkedList::showStructure( char listID ) const
    {
	    ListNode* temp = head;
	
	    if(!isEmpty())
		    {
		    	cout << "  List " << listID;
		    	cout << " (" << size << "/" << capacity << "): ";
			
		    	temp = head;
			
			while( temp != NULL)
			{
				if(temp == cursor)
					{
						cout << " [" << temp->dataItem << "]";
					}
				else
					{
		    			cout << " " << temp->dataItem;
					}
								    			temp = temp->next;
			}
			    			cout << endl;
		    }   
		
		        else 
	             {	                       
                    cout << "  Empty list" << endl;
                 }
		
       }
		
//// Checks if the list is empty ////				

bool LinkedList::isEmpty() const
{
	if( cursor == NULL && head == NULL && size ==0)
		{
			return true;
		}
		    return false;
}

//// Checks if the list is full ////

bool LinkedList::isFull() const
    {
    	if( size == capacity)
    		{
    			return true;
    		}
        		return false;
    }

//// Sends the cursor to the beginning ////

bool LinkedList::goToBeginning()
    {
        if(cursor == head)
    		{
    			return false;
    		}
    	else
        	{
        		cursor = head;
        		return true;
        	}

    }
    
//// Sends the cursor to the end ////
    
bool LinkedList::goToEnd()
    {
        if(!isEmpty() && cursor->next != NULL)
    		{
    			while(cursor->next != NULL)
    			{
        			cursor = cursor->next;
       			}
	                return true;
		    }
		            return false;
	
    }

//// Sends cursor to the next position ////

bool LinkedList::goToNext()
    {
        if(!isEmpty() && cursor->next != NULL)
    	{		
    		cursor = cursor-> next;
		    return true;
	    }
	        return false;
    }

//// Sends the cursor to the previous position ////

bool LinkedList::goToPrior()
    {
		if(!isEmpty() && cursor != head)
    		{
			ListNode* temp = head;		
			while(temp->next != cursor)
	    		{
	        		temp = temp-> next;
	       		}
			        cursor = temp;
    		        return true;
		
    		}
	    	    return false;
    }
	
