// Program Information ////////////////////////////////////////////////////////
/**
 * @file NameType.cpp
 *
 * @brief Implementation file for NameType class
 * 
 * @details Implements the constructor method of the NameType class
 *
 * @author Michael Leverington (edited by Alex Caceres)
 *
 * @version 1.00 (21 October 2015)
 *
 * @Note Requires NameType.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef BST_CLASS_CPP
#define BST_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "BSTClass.h"
#include <new>
#include <iostream>

using namespace std;

// Class Implementation  //////////////////////////////////////////////////////

template<typename DataType>
BSTNode<DataType>::BSTNode
       (
        const DataType &nodeData, // in: data value
        BSTNode *leftPtr,         // in: left node pointer
        BSTNode *rightPtr         // in: right node pointer
       )
     : dataItem( nodeData ), left( leftPtr ), right( rightPtr )
   {
    // data placed in initializers
   }

template<typename DataType>
BSTClass<DataType>::BSTClass
       (
        // no parameters
       )
     : rootNode( NULL )
   {
    // data placed in initializers
   }
           
template<typename DataType>
BSTClass<DataType>::BSTClass
       ( 
        const BSTClass<DataType> &copied 
       )
     : rootNode( NULL )
   {
    copyTree( copied );
   }

template<typename DataType>
BSTClass<DataType>::~BSTClass
       (
        // no parameters
       )
   {
    clearTree();
   }

template <typename DataType>
const BSTClass<DataType>& BSTClass<DataType>:: operator = 
                                                    ( const BSTClass &rhTree )
   {
    if( this != &rhTree ) 
       {
        clearTree();
        copyTree( rhTree );
       }

    return *this;
   }

template<typename DataType>
void BSTClass<DataType>::copyTree
       ( 
        const BSTClass<DataType> &copiedTree 
       )
   {
    copyTreeHelper( rootNode, copiedTree.rootNode );
   }

template<typename DataType>
void BSTClass<DataType>::clearTree
       (       
        // no parameters
       )
   {
    clearTreeHelper( rootNode );

    rootNode = NULL;
   }

template <typename DataType>
void BSTClass<DataType>::insert
       ( 
        const DataType &newData 
       )
   {
    insertHelper( rootNode, newData);
   }

/**
 * @brief Locates a specific item in the tree
 *
 * @details Returns the helper function that takes in the rootnode and the dataItem
 *                  
 * @param out: DataType &value
 *
 * @note None
 */

template <typename DataType>
bool BSTClass<DataType>::findItem
       ( 
        DataType &dataItem 
       ) const
{
       
   return findItemHelper(rootNode, dataItem );
   
}

/**
 * @brief Locates an item in the tree and removes it
 *
 * @details Returns a bool and calls the helper function to remove an item
 *                  
 * @param out: DataType &dataItem
 *
 * @note In order to get the remove to work, I created two helper functions. One checks for the cases of 0 children, and 1 child)
 *       A second helper function was created to find the minimum
 */
template <typename DataType>
bool BSTClass<DataType>::removeItem
       ( 
        const DataType &dataItem 
       )
   {
   
       bool check = true;
       removeItemHelper(rootNode,dataItem,check);
       
       return check;
       
  
   }

template<typename DataType>
bool BSTClass<DataType>::isEmpty
       ( 
        // no parameters
       ) const
   {
    return ( rootNode == NULL );
   }

template<typename DataType>
void BSTClass<DataType>::preOrderTraversal
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

template<typename DataType>
void BSTClass<DataType>::inOrderTraversal
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

template<typename DataType>
void BSTClass<DataType>::postOrderTraversal
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

template<typename DataType>
int BSTClass<DataType>::getHeight
       (
        // no parameters
       ) const
   {
    return getHeightHelper( rootNode );
   }


/**
 * @brief Primary function that obtains the width at the row, and is used in the get max width and min width function
 *
 * @details The helper function for the getWidth at row function is recursively called and takes in the int row parameter
 *                  
 * @param out: int row
 *
 * @note None
 */
template<typename DataType>
int BSTClass<DataType>::getWidthAtRow
       ( 
        int row    // in: row of width to get
       ) const
   
   {
     return getWidthAtRowHelper(rootNode, 0, 0, row);
   }

/**
 * @brief Obtains the maximum width of the tree
 *
 * @details Created two integer variables of depth and width
 *          Used a for loop to go through the tree and then recursively called
 *          getWidthAtRow
 *
 * @param out: Given variables of int&maxWidth and int&maxWidthRow
 *
 * @note None
 */
template<typename DataType>
void BSTClass<DataType>::getMaxWidth
       (
        int &maxWidth,     // out: max width found
        int &maxWidthRow   // out: row at which max width found
       ) const
   {
   
     int depth = 0;
     maxWidth = 0;
     int width = 0;
        
      
    for(depth = 0; depth < getHeight(); depth++)
    {
        width = getWidthAtRow(depth);
    
        if(width > maxWidth)
            {
              maxWidth = width;
              maxWidthRow = depth;
            }     
    }
 
    
  }

/**
 * @brief Obtains the minimum width of the tree
 *
 * @details Created two integer variables of min and width
 *          Used the toPower function to access the powers in the tree to calculate
 *          Used a for loop to go through the tree and then recursively called
 *          getWidthAtRow
 *
 * @param out: Given variables of int&minWidth and int&minWidthRow
 *
 * @note None
 */
template<typename DataType>
void BSTClass<DataType>::getMinWidth
      (
        int &minWidth,        // out: min width found
        int &minWidthRow      // out: row at which min width found
       ) const
{

     int index;
     int width = 0;
     int min = toPower(2, getHeight()-1);
      
        for(index = 0; index < getHeight(); index++)
        {
            width = getWidthAtRow(index);
    
            if(width < min)
            {
                minWidth = width;
                minWidthRow = index;
                min = width;
            }
   
        }
  
}

/**
 * @brief Obtains the bottom width of the tree
 *
 * @details Returns the function getWidthAtRow taking in the getHeight - 1
 *          This obtains the bottom width because of the getHeight always being subtracted by 1
 *
 * @param out: None
 *
 * @note None
 */
template<typename DataType>
int BSTClass<DataType>::getBottomWidth
       (
        // no parameters
       ) const
   {
    
    return getWidthAtRow(getHeight() -1); 
   }

template<typename DataType>
bool BSTClass<DataType>::isCompleteTree
       (
        // no parameters
       ) const
   {
    int depth;

    if( rootNode != NULL )
       {
        checkDepth( INITIALIZE, getHeight() - 1 );

        for( depth = 0; depth < getHeight() - 1; depth++ )
           {
            if( getWidthAtRow( depth ) != toPower( 2, depth ) )
               {
                return false;
               }
           }
       }

    isCompleteTreeHelper( rootNode, getHeight() - 1, 0 );

    return checkDepth( GET_RESULT, 0 );
   }

/**
 * @brief Checks if the tree is considered to be full
 *
 * @details A tree is full if it has two children or none at all
 *          Returns the helper function that takes in rootNode as a parameter
 *
 * @param out: None
 *
 * @note None
 */
template<typename DataType>
bool BSTClass<DataType>::isFullTree
       (
        // no parameters
       ) const
   {
    return isFullTreeHelper(rootNode);
   }

template<typename DataType>
void BSTClass<DataType>::showStructure
       ( 
        // no parameters
       ) const
   {
    int height = getHeight();

    showStructureHelper( rootNode, height, 0 );

    cout << endl;
   }

template<typename DataType>
void BSTClass<DataType>::showStructureHelper
       ( 
        BSTNode<DataType> *workingPtr,
        int fullHeight,
        int presentHeight
       ) const
   {
    char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
    int acctNum;

    if( workingPtr != NULL )
       {
        showStructureHelper( workingPtr->left, fullHeight, presentHeight + 1 );

        cout << endl;
        showTabs( fullHeight - presentHeight );

        workingPtr->dataItem.getAccount( acctName, acctNum, acctType );

        cout << acctName << endl;

        showStructureHelper( workingPtr->right, fullHeight, presentHeight + 1 );
       }
   }

template<typename DataType>
int BSTClass<DataType>::getHeightHelper
       (
        BSTNode<DataType> *workingPtr
       ) const
   {
    int sizeLeft, sizeRight;

    if( workingPtr != NULL )
       {
        sizeLeft = getHeightHelper( workingPtr->left ) + 1;
        sizeRight = getHeightHelper( workingPtr->right ) + 1;

        if( sizeLeft > sizeRight )
           {
            return sizeLeft;
           }

        return sizeRight;
       }

    return 0;
   }

template<typename DataType>
void BSTClass<DataType>::copyTreeHelper
       ( 
        BSTNode<DataType> *&workingPtr,      // local working pointer
        const BSTNode<DataType> *sourcePtr  // incoming source pointer
       )
   {
    if( sourcePtr != NULL )
       {
        workingPtr = new BSTNode<DataType>( sourcePtr->dataItem, NULL, NULL );
        copyTreeHelper( workingPtr->left, sourcePtr->left );
        copyTreeHelper( workingPtr->right, sourcePtr->right );
       }
   }

template <typename DataType>
void BSTClass<DataType>::clearTreeHelper
       ( 
        BSTNode<DataType> *workingPtr 
       )
   {
    if ( workingPtr != NULL )
       {
        clearTreeHelper( workingPtr->left );
        clearTreeHelper( workingPtr->right );
        delete workingPtr;
       }
   }

template <typename DataType>
void BSTClass<DataType>::insertHelper
       ( 
        BSTNode<DataType> *&workingPtr,
        const DataType &newData
       )
   {
    if ( workingPtr == NULL )
       {
        workingPtr = new BSTNode<DataType>( newData, NULL, NULL );
       }

    else if ( newData.compareTo( workingPtr->dataItem ) < 0 )
       {
        insertHelper( workingPtr->left, newData );
       }

    else if ( newData.compareTo( workingPtr->dataItem ) > 0 )
       {
        insertHelper( workingPtr->right, newData);
       }

    else
       {
        workingPtr->dataItem = newData;
       }
   }


/**
 * @brief Helper function for removing an item from the tree
 *
 * @details Uses recursion to remove items using the temp at either left or right, and the value
 *          Checks the case for 0 children and the case for 1 child 
 *          Also calls another additional helper function to find the minimum item recursively
 *                  
 * @param out: BSTNode pointer, &value, and a bool remove
 *
 * @note None
 */
template <typename DataType>
BSTNode<DataType>* BSTClass<DataType>::removeItemHelper(BSTNode<DataType> *temp, DataType const &value, bool remove )
    {
        if (temp == NULL) 
        {
            return temp;
        }
        
        else if(value.compareTo(temp->dataItem) < 0)
        {
            temp->left = removeItemHelper(temp->left,value, true);
        }
        else if(value.compareTo(temp->dataItem) > 0)
        {
            temp->right = removeItemHelper(temp->right, value, true);
        }
    
    else {
        // Case 1: 0 Children
        if(temp->left == NULL && temp->right == NULL)
        {
            delete temp;
            temp = NULL;
        }
        
        // Case 2: One Child
        else if(temp->left == NULL)
        {
            BSTNode<DataType> *root = temp;
            temp = temp->right;
            delete root;
            root = NULL;
            remove = true;
      
        }    
    
        else if(temp->right == NULL)
        {
        BSTNode <DataType> *root = temp;
        temp = temp->left;
        delete root;
        root = NULL;
        remove = true;
        } 
    
    else
    {
      BSTNode<DataType> *temporary = findSmallestSub(temp->right);
      temp->dataItem = temporary->dataItem;
      temp->right = removeItemHelper(temp->right, temporary->dataItem, true);
    }
  }
  return temp;
}
      
/**
 * @brief Created as a helper function to the remove to find the smallest data item in the tree at the right
 *
 * @details if the pointer at the left does not equal NULL in a while loop, the pointer is then set to pointer->left
 *          Used a for loop to go through the tree and then recursively called
 *          returns the pointer
 *
 * @param out: BSTNode<DataType> *ptr
 *
 * @note None
 */
template <typename DataType>
BSTNode<DataType>* BSTClass<DataType>::findSmallestSub(BSTNode<DataType> *ptr) const
{

    
    while(ptr->left != NULL) 
    {
        ptr = ptr->left;
    }
    return ptr;
  
}

/**
 * @brief Helper function for finding a specific item in the tree
 *
 * @details Created two char pointers to obtain the name, account number, and account type
 *          Then I used the compareTo function within 3 if statements and I recursively called the function
 *          When recursively called, the item is able to be located
 *        
 * @param out: BSTNode pointer and &value
 *
 * @note None
 */
template <typename DataType>
bool BSTClass<DataType>::findItemHelper(BSTNode <DataType> *temp, DataType &value ) const
    {
        char *nameData = new char[MAX_STR_LEN];   // created to obtain the information aside from the name
        int acctNum;   
        char *acctType = new char[MAX_STR_LEN];
             
             if ( temp == NULL ) 
             {  
                return false;
             }
             else if ( value.compareTo(temp->dataItem) == 0) // within this statement, we use set and get to obtain the required info
             {
                
                temp->dataItem.getAccount(nameData, acctNum, acctType);
                value.setAccount(nameData, acctNum, acctType);
                return true;
             }
             
             if ( value.compareTo(temp->dataItem) < 0)     
                    {
                        return findItemHelper( temp->left, value );
                    }
             else if( value.compareTo(temp->dataItem) > 0)
                    {
                        return findItemHelper( temp->right, value );
                    }
                    
                    
                    delete nameData;
                    delete acctType;
                    nameData = acctType = NULL;  
                   
         return true;      
    }


template<typename DataType>
void BSTClass<DataType>::isCompleteTreeHelper
       ( 
        BSTNode<DataType> *workingPtr,  // in: pointer to tree node
        int testDepth,                  // in: depth to test for
        int currentDepth                // in: current depth
       ) const
   {
    if( workingPtr != NULL )
       {
        isCompleteTreeHelper( workingPtr->left, testDepth, currentDepth + 1 );
        isCompleteTreeHelper( workingPtr->right, testDepth, currentDepth + 1 );
       }

    else
       {
        checkDepth( AT_BOTTOM, currentDepth - 1 );
       }
   }

template<typename DataType>
void BSTClass<DataType>::preOrderTraversalHelper
       ( 
        BSTNode<DataType> *workingPtr 
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

template<typename DataType>
void BSTClass<DataType>::inOrderTraversalHelper
       ( 
        BSTNode<DataType> *workingPtr 
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

template<typename DataType>
void BSTClass<DataType>::postOrderTraversalHelper
       ( 
        BSTNode<DataType> *workingPtr 
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

template<typename DataType>
void BSTClass<DataType>::showTabs 
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

template<typename DataType>
bool BSTClass<DataType>::checkDepth
       ( 
        int cmdCode,       // in: informs system where to set
        int depth          // in: present depth information
       ) const
   {
    static int depthHolder = 0;
    static int counter = 0;
    static bool fullState = false;
    static bool leftState = false;
    static bool rightState = false;

    switch( cmdCode )
       {
        case INITIALIZE:
           depthHolder = depth;
           break;

        case AT_BOTTOM:
           if( counter == 1 && depth == depthHolder )
              {
               leftState = true;
               fullState = true;
              }

           else if( leftState && !rightState )
              {
               if( depth == depthHolder - 1 )
                  {
                   rightState = true;

                   depthHolder = depth;
                  }
              }

           else if( leftState && rightState && fullState )
              {
               if( depth != depthHolder )
                  {
                   fullState = false;
                  }
              } 
           break;
       }

    counter++;

    return fullState;
   }

template<typename DataType>
int BSTClass<DataType>::toPower
       ( 
        int base,    // in: base
        int exponent // in: times to multiply base by itself
       ) const
   {
    int index, result = 1;
   
    for( index = 0; index < exponent; index++ )
       {
        result *= base;
       }

    return result;
   }
 
/**
 * @brief Helper function to obtain the width at the row
 *
 * @details Passed in 4 parameters, one pointer, and three integers
 *          If tree was not equal to the null, then the counter was returned
 *          If the pointer to either the left or the right does not equal null, 
 *          then increment the counter
 *
 * @param out: BSTNode pointer, int variables of counter, temp and maxWidthRow
 *
 * @note None
 */
template<typename DataType>  
int BSTClass<DataType>::getWidthAtRowHelper(BSTNode<DataType> *tree, int counter, int temp, int maxWidthRow) const
{
    
    if(!(tree))
        {
            return counter;
        }
        
        bool check = (maxWidthRow - temp) == 1;
        
        if(maxWidthRow == 0)
        {
            return 1;
        }
        
        if(check)
        {
            if(tree->left != NULL)
            {
                counter++;
            }
            if(tree->right != NULL)
            {
                counter++;
            }
       }
        else
         
        return getWidthAtRowHelper(tree->left, counter, temp+1, maxWidthRow) 
        + getWidthAtRowHelper(tree->right,counter, temp+1, maxWidthRow);
        

        return counter;

}   

/**
 * @brief Helper function to check if the tree is considered full
 *
 * @details Checked if the tree is not null and returned true
 *          Then created a bool for the left and the right and set the pointer to each
 *          Then I checked the left and the right and recursively called the helper function to each bool
 *
 * @param out: Given variables of int&maxWidth and int&maxWidthRow
 *
 * @note None
 */
template <typename DataType>
bool BSTClass<DataType>::isFullTreeHelper(BSTNode<DataType> *tree) const

 {
    if(!(tree))
    {
        return true;
    }

    bool left = tree->left;
    bool right = tree->right;

        if(!(left ^ right))
        {
            return isFullTreeHelper(tree->left) && isFullTreeHelper(tree->right);
        }
            else
            {
            return false;
            }
  }
#endif	// define BST_CLASS_CPP


