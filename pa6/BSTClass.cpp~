 // Program Information ////////////////////////////////////////////////////////
/**
 * @file BSTClass.cpp
 *
 * @brief Implementation file for Binary Search Tree class
 * 
 * @details Specifies all data of the BST class
 *
 * @author Alexandra Caceres
 *
 * @version October 15, 2015
 *
 * @Note None
 */
 
// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
#include "BSTClass.h"

using namespace std;

// Precompiler directives /////////////////////////////////////////////////////  

#ifndef BST_CLASS_CPP
#define BST_CLASS_CPP

/**
 * @brief  Node Default Constructor
 *
 * @details Constructs empty BST Node
 *                 
 * @param out: None
 *
 * @note None
 */
 
template <typename DataType>
BSTNode<DataType>::BSTNode( const DataType &nodeData, BSTNode *leftPtr, BSTNode *rightPtr ) : dataItem(nodeData), left(leftPtr), right(rightPtr)
    {

    }   

/**
 * @brief Default BST Class Constructor
 *
 * @details Constructs the BST Class        
 *          
 * @param out: None
 *
 * @note None
 */
template <typename DataType>
BSTClass<DataType>::BSTClass() : rootNode(NULL)
    {
   
    }

/**
 * @brief BST Class Copy Constructor
 *
 * @details Places the data into the object               
 *          
 * @param out: new copied object
 *
 * @note None
 */
 
template <typename DataType>       
BSTClass<DataType>::BSTClass( const BSTClass<DataType> &copied ) : rootNode(NULL)
    {
      copyTree(copied);
    }

/**
 * @brief Destructor
 *
 * @details Calls clearTree() which removes the data
 *                  
 * @param out: None
 *
 * @note None
 */
template <typename DataType>
BSTClass<DataType>:: ~BSTClass() 
    {
      clearTree();
    }

/**
 * @brief Overloaded Assignment operator
 *
 * @details Assigns data to other DataType
 *                  
 * @param out: assigned name
 *
 * @note None
 */
template <typename DataType>     
const BSTClass<DataType> &BSTClass<DataType>::operator=(const BSTClass<DataType> &rhData )
    {
    
        if(this != &rhData)
        {
            copyTree(rhData);
        }
            return *this;
   
    }

/**
 * @brief Function to copy a tree
 *
 * @details Copies over tree to destination
 *                  
 * @param out: &copied
 *
 * @note Used in assignment operator and in copy constructor
 */
template <typename DataType>    
void BSTClass<DataType>::copyTree( const BSTClass<DataType> &copied )
    {
        clearTree();
        copyTreeHelper(copied.rootNode);            
    }

/**
 * @brief Helper function for copy tree
 *
 * @details Uses parameters and recursion to aid in copying the tree
 *                  
 * @param out: BSTNode pointer result to use in recursion for the left and right
 *
 * @note None
 */
template <typename DataType>    
void BSTClass<DataType>::copyTreeHelper(BSTNode <DataType> *result )
    {
        if(result != NULL)
        {
            insert(result->dataItem);
            copyTreeHelper(result -> left);
            copyTreeHelper(result -> right);
        }
    }

/**
 * @brief clearTree() function
 *
 * @details Removes any data in the tree
 *                  
 * @param out: None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::clearTree()
    {
        cleartreeHelper(rootNode);
        rootNode = NULL;	
    }

/**
 * @brief Helper function for clearTree
 *
 * @details Uses recursion to remove data in the tree
 *                  
 * @param out: BSTNode pointer result
 *
 * @note Uses recursion to call itself and remove data from the tree in clearTree() function
 */
template <typename DataType>
void BSTClass<DataType>::cleartreeHelper(BSTNode<DataType> *result)
    {
        if(result != NULL)
        {
            cleartreeHelper(result->left);
            cleartreeHelper(result->right);
            delete result;
            result = NULL;
        }   
    }

/**
 * @brief Insertion function
 *
 * @details Inserts data into the tree
 *                  
 * @param out: &newData
 *
 * @note Requires the use of a helper function for insertion
 */
template <typename DataType>
void BSTClass<DataType>::insert( const DataType &newData )
    {
   
   if(rootNode == NULL)
        {
            rootNode = new BSTNode<DataType> (newData, NULL, NULL);
        
        }   
         else
            insertNodeHelper(rootNode, newData);
    }

/**
 * @brief Insertion helper function
 *
 * @details Compares value with the temp->dataItem, also creates a new BSTNode if the pointer is at null
 *                  
 * @param out: BSTNode pointer and &value
 *
 * @note Requires the use of compareTo function in NameType.cpp
 */
template <typename DataType>
void BSTClass<DataType>::insertNodeHelper(BSTNode<DataType> *temp, const DataType &value)
    {
         if(value.compareTo(temp->dataItem) < 0)
              {
                  if ( temp->left == NULL)
                      {
                         temp->left = new BSTNode<DataType> (value, NULL, NULL);
                      }
                            else 
                            {
                            insertNodeHelper((temp->left), value);
                            }  
              }
                   
                   else if(value.compareTo(temp->dataItem) > 0)
                     {
                        if( temp->right == NULL)
                             {
                             temp->right = new BSTNode<DataType> (value, NULL, NULL);
                             }
                                else
                                {
                                insertNodeHelper((temp->right), value);
                                }
                     }
           
    }

/**
 * @brief Finditem function
 *
 * @details Searchs for a specific name within the tree
 *                  
 * @param out: &searchDataItem
 *
 * @note None
 */
template <typename DataType>
bool BSTClass<DataType>::findItem( const DataType &searchDataItem ) const
    {
    return false;
    }


/**
 * @brief Remove Item function
 *
 * @details Removes a specific item from the tree
 *                  
 * @param out: &dataItem
 *
 * @note None
 */
template <typename DataType>
bool BSTClass<DataType>::removeItem( const DataType &dataItem )
    {
    return false;
    }

/**
 * @brief Checks if the tree is empty
 *
 * @details if the rootNode is at the NULL, then return that the tree is empty
 *                  
 * @param out: None
 *
 * @note None
 */
template <typename DataType>
bool BSTClass<DataType>::isEmpty() const
    {
        if( rootNode == NULL)
		    {
			return true;
		    }
		    return false;
    }

/**
 * @brief Preorder Traversal function
 *
 * @details checks if tree is empty, if not, calls the helper function
 *                  
 * @param out: None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::preOrderTraversal() const
    {
        if(isEmpty())
        {
            cout << "Tree is empty" << endl;
        }
        helpPre(rootNode);
    }   

/**
 * @brief Helper function for preorder traversal
 *
 * @details visits the root, traverses the left subtree, then the right subtree
 *                  
 * @param out: assigned name
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::helpPre(BSTNode<DataType> *result) const
    {       
     
      if (result != NULL)
        {
            cout << result-> dataItem << endl;
            helpPre(result -> left);
            helpPre(result -> right);
        }
    }

/**
 * @brief Inorder Traversal function
 *
 * @details Checks if the tree is empty, if not then calls the helper function
 *                  
 * @param out: None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::inOrderTraversal() const
    {
        if(isEmpty())
        {
            cout << "Tree is empty" << endl;
        }
            helpIn(rootNode);
    
    }

/**
 * @brief Helper function for in order traversal
 *
 * @details Traverses left subtree, visits the root, traverses the right subtree
 *                  
 * @param out: BSTNode pointer
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::helpIn(BSTNode<DataType> *result) const
    {
 
        if (result != NULL)
        {  
            helpIn(result->left);
            cout << result->dataItem << endl;
            helpIn(result->right);
        }
    

    }

/**
 * @brief Function for PostOrder Traversal
 *
 * @details Checks if the tree is empty, if not, calls the helper function
 *                  
 * @param out: None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::postOrderTraversal() const
    {
        if(isEmpty())
        {
            cout << "Tree is empty" << endl;
        }
            helpPost(rootNode);

}

/**
 * @brief Helper function for post order traversal
 *
 * @details Traverses left subtree, traverses the right subtree, visit the root
 *                  
 * @param out: BSTNode pointer
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::helpPost(BSTNode<DataType> *result) const
    {

        if(result != NULL)
        {
            helpPost(result->left);
            helpPost(result->right);
            cout << result->dataItem << endl;
        }

    }   

/**
 * @brief Retrieves the height function
 *
 * @details Checks if the tree is empty, and returns if it is, if not calls the helper function
 *                  
 * @param out: None
 *
 * @note None
 */
template <typename DataType>
int BSTClass<DataType>::getHeight() const
    {
        if( isEmpty())
        {
            return 0;
        }
        return getHeightHelper(rootNode);
    }

/**
 * @brief Helper function for getHeight
 *
 * @details sets integers to 0, then checks if the pointer at the left or the right is NULL, recursively calls itself
 *                  
 * @param out: BSTNode pointer
 *
 * @note None
 */
template <typename DataType>
int BSTClass<DataType>::getHeightHelper(BSTNode <DataType> *result ) const
    {

        if(result == 0)
        {
            return 0;
        }
        int heightLeft = 0;
        int heightRight = 0; 
   
            if(result->left != NULL)
            {
                heightLeft = getHeightHelper(result->left);
            }
   
            if(result->right != NULL)
            {
                heightRight = getHeightHelper(result->right);
            }
      
            if(heightLeft > heightRight)
            {
                return heightLeft+1;
            }
                else
            {
                return heightRight+1;
            }   
    
    }

/**
 * @brief Print function for the trees
 *
 * @details The helper function for the print is called at parameters, rootNode and 0
 *                  
 * @param out: None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::showStructure() const
    {
      cout << endl;
      helpshowStructure(rootNode,0);
    }

/**
 * @brief Helper function for the print(show structure)
 *
 * @details sets an integer to equal the parameter + 1 and creates an index
 *          a while loop is used to compare index with the variable subtracted from getHeight()
 *          recursively call the showStructure
 *                 
 * @param out: BSTNode pointer and an integer track
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::helpshowStructure(BSTNode <DataType> *current, int track) const
    {
            
        int numTab = track+1;
        int index = 0;
        if(current == NULL)
        {
            return;
            
        }          
            helpshowStructure(current->left, track+1);
            for(index = 0; index <= getHeight() - numTab; index++)
            {
                cout << TAB;
            }
            cout << current->dataItem << endl << endl;
            helpshowStructure(current->right, track+1);      
    }

#endif
