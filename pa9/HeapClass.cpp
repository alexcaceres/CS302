// Program Information ////////////////////////////////////////////////////////
/**
 * @file HeapClass.cpp
 *
 * @brief Implementation file for HeapClass
 * 
 * @details Implements all member actions for the HeapClass
 *
 * @author Michael Leverington and Alexandra Caceres
 *
 * @version 1.00 (11 November 2015)
 *
 * @Note Requires HeapClass.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef HEAP_CLASS_CPP
#define HEAP_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "HeapClass.h"
#include <new>

using namespace std;

// Class Implementation  //////////////////////////////////////////////////////

template<typename KeyType, typename DataType>
HeapNode<KeyType, DataType>::HeapNode
       (
        const KeyType &nodeKey,   // in: key value
        const DataType &nodeData, // in: data value
        HeapNode *parentPtr,      // in: parent pointer
        HeapNode *leftPtr,         // in: left node pointer
        HeapNode *rightPtr         // in: right node pointer
       )
     : keyItem( nodeKey ), dataItem( nodeData ), parent( parentPtr ), 
       left( leftPtr ), right( rightPtr )
   {
    // data placed in initializers
   }

template<typename KeyType, typename DataType>
HeapClass<KeyType, DataType>::HeapClass
       (
        // no parameters
       )
     : rootNode( NULL )
   {
    // data placed in initializers
   }
           
template<typename KeyType, typename DataType>
HeapClass<KeyType, DataType>::HeapClass
       ( 
        const HeapClass<KeyType, DataType> &copied 
       )
     : rootNode( NULL )
   {
    copyTree( copied );
   }

template<typename KeyType, typename DataType>
HeapClass<KeyType, DataType>::~HeapClass
       (
        // no parameters
       )
   {
    clearTree();
   }

template<typename KeyType, typename DataType>
const HeapClass<KeyType, DataType>& HeapClass<KeyType, DataType>:: operator = 
                                                    ( const HeapClass &rhTree )
   {
    if( this != &rhTree ) 
       {
        clearTree();
        copyTree( rhTree );
       }

    return *this;
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::copyTree
       ( 
        const HeapClass<KeyType, DataType> &copiedTree 
       )
   {
    copyTreeHelper( rootNode, NULL, copiedTree.rootNode );
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::clearTree
       (       
        // no parameters
       )
   {
    clearTreeHelper( rootNode );

    rootNode = NULL;
   }
   
/**
* @brief Inserts an item into the tree
*
* @details Takes into account if it is complete, uses addItemHelper function for recursion
*
* @param in:  newKey, newData
*
* @note Uses addItemHelper
*/
template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::addItem
       ( 
        const KeyType &newKey,
        const DataType &newData
       )
   {
       HeapNode<KeyType, DataType> *begin = NULL;
       addItemHelper(newKey, newData, begin, rootNode, -1);    
   }

/**
* @brief Recursive function to aid in inserting an item in the heap
*
* @details from the last position bottom up of the heap node
*          node is trickled up until it is in correct spot
*         
* @param in: newKey, newData, parentPtr, workingPtr, row
*
* @note None
*/
template<typename KeyType, typename DataType>   
bool HeapClass<KeyType, DataType>::addItemHelper(const KeyType &newKey, const DataType &newData, HeapNode<KeyType, DataType> *&parentPtr, HeapNode<KeyType, DataType> *&workingPtr, int row)
{
    
    int lHeight = getLeftHeight();
      
    bool check;
    bool isFandC; // full and complete
    
    isFandC = (lHeight == getRightHeight());

    if(isFandC)
    {
        check = row == (lHeight-1);  
    }
    else
    {
        check = row == (lHeight-2); 
    }

    if(check && !workingPtr) 
    {
        workingPtr = new HeapNode<KeyType, DataType>(newKey, newData, parentPtr, NULL, NULL);
        trickleUp(workingPtr); // calls trickle up to place node in correct spot
        return true;
    }
    
    else if(check && workingPtr) 
    {
        return false;
    }

    if(workingPtr->left && workingPtr->right) // left and right children
    {   
        // checks both left and right path
        if(addItemHelper(newKey, newData, workingPtr, workingPtr->left, row+1))
        {
            return true;
        }
        
        return addItemHelper(newKey, newData, workingPtr, workingPtr->right, row+1);
    } 
    
   
    else if(workingPtr->left && !workingPtr->right)  // when parent only has left child
    {
        return addItemHelper(newKey, newData, workingPtr, workingPtr->right, row+1);
    }
    else  // this will add to make complete
    
    {
        return addItemHelper(newKey, newData, workingPtr, workingPtr->left, row+1);
    }
}
        

/**
* @brief Trickles up the heap until the node is greater than the parent
*
* @details  Replace the root of the heap with the last element on the last level.
            Compare the new root with its children; if they are in the correct order, stop.
            Swaps the element with its smallest child 
*
* @param in: workingPtr
*
* @note None
*/

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::trickleUp(HeapNode<KeyType, DataType> *workingPtr)
{
       if(!workingPtr->parent)
    {
        return;
    }

    KeyType keyTemp = workingPtr->keyItem;
    DataType dataTemp = workingPtr->dataItem;

    if(compareTo(workingPtr, workingPtr->parent) < 0)
    {
        workingPtr->keyItem = workingPtr->parent->keyItem;
        workingPtr->dataItem = workingPtr->parent->dataItem;
        
        workingPtr->parent->keyItem = keyTemp;
        workingPtr->parent->dataItem = dataTemp;
    }
    else
    {
        return;
    }

    trickleUp(workingPtr->parent); 
}

/**
* @brief Removes the root node item and uses removeItemHelper function
*
* @details returns false if there is no item to remoove in the root node
*          returns true if the root node is removed and replaced
*
* @param in: returnedDataItem, returnedKeyItem
*
* @note None
*/
template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::removeItem
       ( 
        DataType &returnedDataItem,
        KeyType &returnedKeyItem 
       )
   {
   if(isEmpty())
    {
        return false;
    }
    else
    {
        returnedKeyItem = rootNode->keyItem;
        returnedDataItem = rootNode->dataItem;

        return removeItemHelper(rootNode, 0);
    }
   }


/**
* @brief If there is a rightmost item in tree, that replaces the rootnode
* 
* @details Uses the trickle down function recursively to aid in removing an item
*          Checks all possible paths for removing an item
*
* @param in: workingPtr, integer row
*
* @note None
*/
template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::removeItemHelper(HeapNode<KeyType, DataType> *&workingPtr, int row)
{

    bool check = row == (getLeftHeight()-1);

    if(!workingPtr)
    {
        return false;
    }

    if(check) 
    {
        if(workingPtr != rootNode)
        {
            rootNode->keyItem = workingPtr->keyItem;
            rootNode->dataItem = workingPtr->dataItem;
        }
        
        delete workingPtr;
        workingPtr = NULL;
        
        trickleDown(rootNode); // place node in correct spot
        return true;
    }

    if(removeItemHelper(workingPtr->right, row+1))
    {
        return true;
    }
    
    return removeItemHelper(workingPtr->left, row+1);
    
}

/**
* @brief Trickles down to find the correct position in the tree
*
* @details Recursive function to trickle down and check the order
*          The nodes are swapped if the parent is not less than the children
*
* @param in: workingPtr
*
* @note None
*/
template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::trickleDown(HeapNode<KeyType, DataType> *workingPtr)
{

    HeapNode<KeyType, DataType> *temp = NULL;
    KeyType keyTemp;
    DataType dataTemp;
  
    if(!workingPtr || !workingPtr->left)  // there is no node or no children for a check
    {
        return;
    }

    keyTemp = workingPtr->keyItem;
    dataTemp = workingPtr->dataItem;

    if(!workingPtr->right) // no right child
    {   // checking if current node is more than left child
        if(compareTo(workingPtr, workingPtr->left) >= 0)
        {
            temp = workingPtr->left;
        }
        else
        {
            return;
        }
    } // find least child to be swapped with current if two children exist
    else if(workingPtr->right)
    {
        if(compareTo(workingPtr->right, workingPtr->left) <= 0)
        {
            temp = workingPtr->right;
        }
        else
        {
            temp = workingPtr->left;
        }
    }
 
    if(compareTo(workingPtr, temp) > 0)
    {
        workingPtr->keyItem = temp->keyItem;
        workingPtr->dataItem = temp->dataItem;
        
        temp->keyItem = keyTemp;
        temp->dataItem = dataTemp;
    }
    // recursive call to check if node in new position is correct
    trickleDown(temp);
}


template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::isEmpty
       ( 
        // no parameters
       ) const
   {
    return ( rootNode == NULL );
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::preOrderTraversal
       (
        // no parameters
       ) const
   {
    if( rootNode != NULL )
       {
        preOrderTraversalHelper( rootNode );
        cout << endl;
       }

    else
       {
        cout << "Tree is empty" << endl;
       }
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::inOrderTraversal
       (
        // no parameters
       ) const
   {
    if( rootNode != NULL )
       {
        inOrderTraversalHelper( rootNode );
        cout << endl;
       }

    else
       {
        cout << "Tree is empty" << endl;
       }
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::postOrderTraversal
       (
        // no parameters
       ) const
   {
    if( rootNode != NULL )
       {
        postOrderTraversalHelper( rootNode );
        cout << endl;
       }

    else
       {
        cout << "Tree is empty" << endl;
       }
   }

template<typename KeyType, typename DataType>
int HeapClass<KeyType, DataType>::getLeftHeight
       (
        // no parameters
       ) const
   {
    return getHeightHelper( rootNode, 'L' );
   }

template<typename KeyType, typename DataType>
int HeapClass<KeyType, DataType>::getRightHeight
       (
        // no parameters
       ) const
   {
    return getHeightHelper( rootNode, 'R' );
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::showStructure
       ( 
        // no parameters
       ) const
   {
    int height = getLeftHeight();

    if( rootNode != NULL )
       {
        showStructureHelper( rootNode, height, 0 );

        cout << endl << "Left Height: " << getLeftHeight() 
             << ", Right Height: "  << getRightHeight() << endl;
       }

    else
       {
        cout << "Empty Tree" << endl;
       }

    cout << endl;
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::showStructureHelper
       ( 
        HeapNode<KeyType, DataType> *workingPtr,
        int fullHeight,
        int presentHeight
       ) const
   {
    char patientName[ MAX_STR_LEN ], medicalCode[ MAX_STR_LEN ];
    char patientGender;

    if( workingPtr != NULL )
       {
        showStructureHelper( workingPtr->left, fullHeight, presentHeight + 1 );

        cout << endl;
        showTabs( fullHeight - presentHeight );

        workingPtr->dataItem.getAccount( patientName, medicalCode, patientGender );

        cout << patientName;

        cout << ", " << int( workingPtr->keyItem ) << endl;

        showStructureHelper( workingPtr->right, fullHeight, presentHeight + 1 );
       }
   }

template<typename KeyType, typename DataType>
int HeapClass<KeyType, DataType>::getHeightHelper
       (
        HeapNode<KeyType, DataType> *workingPtr,
        char leftRightIndicator
       ) const
   {
    if( workingPtr != NULL )
       {
        if( leftRightIndicator == 'L' )
           {
            return 1 + getHeightHelper( workingPtr->left, leftRightIndicator );
           }

        return 1 + getHeightHelper( workingPtr->right, leftRightIndicator );
       }

    return 0;
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::copyTreeHelper
       ( 
        HeapNode<KeyType, DataType> *&workingPtr,      // local working pointer
        HeapNode<KeyType, DataType> *parentPtr,      // local parent pointer
        const HeapNode<KeyType, DataType> *sourcePtr  // incoming source pointer
       )
   {
    if( sourcePtr != NULL )
       {
        workingPtr = new HeapNode<KeyType, DataType>( sourcePtr->keyItem, 
                                  sourcePtr->dataItem, parentPtr, NULL, NULL );
        copyTreeHelper( workingPtr->left, workingPtr, sourcePtr->left );
        copyTreeHelper( workingPtr->right, workingPtr, sourcePtr->right );
       }
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::clearTreeHelper
       ( 
        HeapNode<KeyType, DataType> *workingPtr 
       )
   {
    if ( workingPtr != NULL )
       {
        clearTreeHelper( workingPtr->left );
        clearTreeHelper( workingPtr->right );
        delete workingPtr;
       }
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::preOrderTraversalHelper
       ( 
        HeapNode<KeyType, DataType> *workingPtr 
       ) const
   {
    char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
    int acctNum;

    if( workingPtr != NULL )
       {
        workingPtr->dataItem.getAccount( acctName, acctNum, acctType );

        cout << acctName << endl;

        preOrderTraversalHelper( workingPtr->left );

        preOrderTraversalHelper( workingPtr->right );
       }
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::inOrderTraversalHelper
       ( 
        HeapNode<KeyType, DataType> *workingPtr 
       ) const
   {
    char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
    int acctNum;

    if( workingPtr != NULL )
       {
        inOrderTraversalHelper( workingPtr->left );
   
        workingPtr->dataItem.getAccount( acctName, acctNum, acctType );
    
        cout << acctName << endl;

        inOrderTraversalHelper( workingPtr->right );
       }
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::postOrderTraversalHelper
       ( 
        HeapNode<KeyType, DataType> *workingPtr 
       ) const
   {
    char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
    int acctNum;

    if( workingPtr != NULL )
       {
        postOrderTraversalHelper( workingPtr->left );

        postOrderTraversalHelper( workingPtr->right );

        workingPtr->dataItem.getAccount( acctName, acctNum, acctType );

        cout << acctName << endl;
       }
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::showTabs 
       ( 
        int numTabs 
       ) const
   {
    int counter;

    for( counter = 0; counter < numTabs; counter++ )
       {
        cout << TAB;
       }
   }
 
 
/**
* @brief Compares the keys
*
* @details returns -1 if left key is < right key
*          returns 0 if the keys are equal
*          returns 1 if left key > right key
*
* @param in: leftPtr, rightPtr
*
* @note Accesses the other compare to as well if the keys happen to be equal
*/
template<typename KeyType, typename DataType>
int HeapClass<KeyType, DataType>::compareTo(HeapNode<KeyType, DataType> *leftPtr,HeapNode<KeyType, DataType> *rightPtr)
{
    if(leftPtr->keyItem < rightPtr->keyItem)
    {
        return -1;
    }
    else if(leftPtr->keyItem > rightPtr->keyItem)
    {
        return 1;
    }
    else if(leftPtr->keyItem == rightPtr->keyItem)
    {
    
        return leftPtr->dataItem.compareTo(rightPtr->dataItem);
    }
}   
   

#endif	// define HEAP_CLASS_CPP


