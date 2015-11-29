// Program Information ////////////////////////////////////////////////////////
/**
 * @file BSTClass.h
 *
 * @brief Definition file for Binary Search Tree class
 * 
 * @details Specifies all data of the BST class
 *
 * @author Michael Leverington modified by Alex Caceres
 *
 * @version 1.00 (21 October 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef BST_CLASS_H
#define BST_CLASS_H

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

// Class constants ////////////////////////////////////////////////////////////

   // None

// Class definition ///////////////////////////////////////////////////////////

template <typename DataType>
class BSTNode
   {
    public:

       BSTNode( const DataType &nodeData, BSTNode *leftPtr, BSTNode *rightPtr );

       DataType dataItem;

       BSTNode<DataType> *left;
       BSTNode<DataType> *right;
   };

template <typename DataType>
class BSTClass
   {
    public:

       // constants
       static const char TAB = '\t';
       static const int MAX_STR_LEN = 80;
       static const int INITIALIZE = 101;
       static const int AT_BOTTOM = 102;
       static const int GET_RESULT = 103;

       // constructor
       BSTClass();
       BSTClass( const BSTClass<DataType> &copied );

       // destructor
       ~BSTClass();

       // assignment operator
       const BSTClass &operator = (const BSTClass<DataType> &rhData );

       // modifiers
       void copyTree( const BSTClass<DataType> &copied );
       void clearTree();
       void insert( const DataType &newData );
       bool findItem( DataType &searchDataItem ) const;         
       bool removeItem( const DataType &dataItem );              
      
       
       

       // accessors
       bool isEmpty() const;
       void preOrderTraversal() const; 
       void inOrderTraversal() const;  
       void postOrderTraversal() const;
       int getHeight() const;
       int getWidthAtRow( int row ) const;                       
       void getMaxWidth( int &maxWidth, int &maxWidthRow ) const;  
       void getMinWidth( int &minWidth, int &minWidthRow ) const;  
       int getBottomWidth() const;                               
       bool isCompleteTree() const;                              
       bool isFullTree() const;                                  // assigned
       void showStructure() const;
 
    private:

       void showStructureHelper( BSTNode<DataType> *workingPtr, 
                                  int fullHeight, int presentHeight ) const;

       int getHeightHelper( BSTNode<DataType> *workingPtr ) const;

       void copyTreeHelper( BSTNode<DataType> *&workingPtr, 
                                       const BSTNode<DataType> *sourcePtr );

       void clearTreeHelper( BSTNode<DataType> *workingPtr );

       void insertHelper( BSTNode<DataType> *&workingPtr, 
                                                  const DataType &newData );

       void isCompleteTreeHelper( BSTNode<DataType> *workingPtr, 
                                    int testDepth, int currentDepth ) const;

       void preOrderTraversalHelper( BSTNode<DataType> *workingPtr) const;
       void inOrderTraversalHelper( BSTNode<DataType> *workingPtr) const;
       void postOrderTraversalHelper( BSTNode<DataType> *workingPtr) const;
       void showTabs( int numTabs ) const;
       bool checkDepth( int cmdCode, int depth ) const;
       int toPower( int base, int exponent ) const;
       bool findItemHelper(BSTNode <DataType> *temp, DataType &value ) const;
       BSTNode<DataType>*removeItemHelper(BSTNode<DataType> *temp,const DataType &value, bool remove );
       BSTNode<DataType>* findSmallestSub(BSTNode<DataType> *ptr) const;
       int getWidthAtRowHelper(BSTNode<DataType> *tree, int counter, int temp, int maxWidthRow) const;
       bool isFullTreeHelper(BSTNode<DataType> *tree) const;  
       BSTNode<DataType> *rootNode;    
   };

#endif	// define BST_CLASS_H



