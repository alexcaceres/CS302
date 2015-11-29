// Program Information ////////////////////////////////////////////////////////
/**
 * @file SolverClass.cpp
 *
 * @brief Implementation file for class that attempts to locate smaller
 *        inside a larger container rectangle
 * 
 * @author Alexandra Caceres
 * 
 * @details Implements all member methods of the Solver class
 *
 * @version 1.00 (3 November 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef SOLVERCLASS_CPP
#define SOLVERCLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include <stdexcept>
#include <iostream>
#include "SolverClass.h"

using namespace std;


/**
 * @brief Initialization constructor
 *
 * @details Constructs SolverClass, a bool of display is set to false
 *          Uses grow and subtracts the capacity from the letters(25)
 *          Excludes the letter 'O'
 *          
 * @param in: None
 *
 * @note None
 */
SolverClass::SolverClass() : display(false)
{
   store.grow(numLetters - store.getCapacity());
}

/**
 * @brief Destructor for SolverClass
 *
 * @details Nothing in the destructor
 *          
 * @param in: None
 *
 * @note None
 */
SolverClass::~SolverClass()
{
}

/**
 * @brief Finds the solution for the rectangles inserted in, requires a helper function
 *
 * @details Returns the helper function
 *          
 * @param in: None
 *
 * @note None
 */
bool SolverClass::findSolution()
{
      
    return findSolutionHelper();
}

/**
 * @brief Helper function for findSolution
 *
 * @details Checks for a solution, uses two bools to check for empty space
 *          Checks for rotation, recursively backtracks to find the solution
 *          
 * @param in: None
 *
 * @note None
 */
bool SolverClass::findSolutionHelper()
{
    
    int row;
    int col;
    
    int next = 0;
    
    if(isSolution())
    {
        return true;
    }
    
    else if(!checkEmptySpace(row,col))
    {
        return false;
    }
    
    while(getNext(next))
    {
        
        if(checkForFill(row, col, store[next]))
        {
            
            fill(row,col,store[next]);
            store[next].setUsedState(true);
        
            if(findSolutionHelper())
                {
                    return true;
                }  
         unfill((store[next]).getIDLetter());
         store[next].setUsedState(false);
        }
        
       store[next].rotate();
       if(checkForFill(row,col, store[next]))
       {
       fill(row,col,store[next]);
       store[next].setUsedState(true);
       
       if(findSolutionHelper())
       {
        return true;
       }
       
       unfill(store[next].getIDLetter());
       store[next].setUsedState(false);
       }
       
       store[next].rotate();
       next++;
      }
      
      return false;
      
}
       


/**
 * @brief Sets the area of the large rectangles into which the smaller rectangles are placed
 *
 * @details Checks for the height and width if greater than 1, then returns true
 *          If both greater than 1, the SimpleMatrix is able to pass in the parameter
 *          and the background letter of 'O'
 *          
 * @param in: height, width
 *
 * @note None
 */
bool SolverClass::setContainerRectangle( int height, int width )
{

    if(height > 1 && width > 1)
        {
            gridSpace = SimpleMatrix<char> (height, width,'O');
            return true;
        }
        
        return false;
        
}

/**
 * @brief Adds the rectangles length and width in to aid in the 
 *        solution finding process
 *
 * @details Gives the rectangle its identifying letter
 *          Checks the height and width added together if greater than 1
 *          increments the variable check and previous location
 *          
 * @param in: height, width
 *
 * @note None
 */
bool SolverClass::addInsideRectangle( int height, int width )
{

    int check = 0;
    char prevLoc = 'A';
    
    if(height + width > 1)
        {
            
            while(store[check].getWidth() != 0)
            {
                check++;
            }
       
       if(char(prevLoc+check) == 0)
       {
        check++;
       }
       
       
       store[check] = Rectangle(height, width, char(prevLoc+check));
       store.incrementSize();
        
        return true;
      }
      return false;
       
}

/**
 * @brief Sets the display flag function to be true if user wants the display method to show
 *
 * @details If set to false, the diplay will not show
 *          Created a bool display in .h file to set it to the parameter.
 *          
 * @param in: setFlag
 *
 * @note None
 */
void SolverClass::setDisplayFlag( bool setFlag )
{

   display = setFlag;
}

/**
 * @brief Displays the field
 *
 * @details Will not run unless a displa field flag is set
 *          Made atRow and atCol varaibles as well as accessed the number of
 *          rows and columns. If the display flag is set, then two for loops are used
 *          Outputs the matrix
 *          
 * @param in: None
 *
 * @note None
 */
void SolverClass::displayField() const
{
    int atRow;
    int atCol;
    
    int rows = gridSpace.getNumRows();
    int cols = gridSpace.getNumCols();
    
    if(display)
        {
            for(atRow = 0; atRow < rows; atRow++)
            {
                for(atCol = 0; atCol < cols; atCol++)
                {
                    cout << gridSpace[atRow][atCol] << " ";
                }
                
    cout << endl;
            }
    cout << endl;
        }
}


/**
 * @brief Helper function to fill and aid in finding solution
 *
 * @details Calls upon fill and obtains the width, height and the ID letter
 *          Then the variable atRow and atCol are used in a double for loop
 *                 
 * @param in: row, col, Rectangle fill
 *
 * @note None
 */
void SolverClass::fill(int row, int col, Rectangle fill)
{
    int atRow;
    int atCol;
    int width = fill.getWidth();
    int height = fill.getHeight();
    char letter = fill.getIDLetter();

    for(atRow = row; atRow < height+row; atRow++)
    {
        for(atCol = col; atCol < width+col; atCol++)
        {
            gridSpace[atRow][atCol] = letter;
        }
    }
    
 }
 
 /**
 * @brief Helper function to unfill and aid in finding a solution
 *
 * @details Sets the variables of width and height to obtain the number of rows
 *          and the number of columns. Checks if the gridSpace[row][col] is ==
 *          to the parameter and is so then the gridSpace[row][col] is equal to 
 *          the background letter O
 *          
 * @param in: a char variable
 *
 * @note None
 */
 
void SolverClass::unfill(char nfill)
 {
 
    int row;
    int col;
    
    int width = gridSpace.getNumCols();
    int height = gridSpace.getNumRows();
    
    for(row = 0; row < height; row++)
    {
        for(col = 0; col < width; col++)
        {
            if(gridSpace[row][col] == nfill)
                {
                    gridSpace[row][col] = 'O';
                }
        }
    }
    
} 

/**
 * @brief Checks for a fill and aids in finding the solution
 *
 * @details Uses the variables of height and width and accesses fill to
 *          obtain the height added with the row and the width added with
 *          the col.
 *          
 * @param in: row, col, Rectangle fill
 *
 * @note None
 */
 
bool SolverClass::checkForFill(int row, int col, Rectangle fill)   
{
    int atRow;
    int atCol;
    
    int height;
    int width;
    
    height = fill.getHeight() + row;
    width = fill.getWidth() + col;
 
 
    if(height <= gridSpace.getNumRows() && width <= gridSpace.getNumCols())
    {
        for(atRow = row; atRow < height; atRow++)
        {
            for(atCol = col; atCol < width; atCol++)
            {
                 if(gridSpace[atRow][atCol] != 'O')
                 {
                    return false;
                 }
            }
        }
        return true;
    }
  
 return false;   
}
  
/**
 * @brief Find the next available rectangle in the matrix
 *
 * @details Returns true if there is an available rectangle and false if there isnt
 *                   
 * @param in: An integer that is passed by reference &nextRect, specifies starting point
 *
 * @note None
 */
          
bool SolverClass::getNext(int &nextRect)   
{
    int loc;
    
    if(nextRect != -1)
    {
        loc = nextRect;
    }
    
    else
    {
        loc = 0;
    }
   
    while(loc < store.getSize())
    {
        if(!store[loc].isUsed())
        {
            nextRect = loc;
            return true;
        }
            loc++;
    }

    return false;
    
}

/**
 * @brief Aids in finding a solution by checking if there is empty space
 *
 * @details Accessed the number of rows and columns and then within a double for loop,
 *          white space is checked for, function returns false
 *          
 * @param in: row, col
 *
 * @note None
 */
 
bool SolverClass::checkEmptySpace(int &row, int &col)
{
    
    int atCol;
    int atRow;
    
    atRow = gridSpace.getNumRows();
    atCol = gridSpace.getNumCols();
    
    for(col = 0; col < atCol; col++)
    {
        for(row = 0; row < atRow; row++)
        {
            if(gridSpace[row][col] == 'O')
                {
                    return true;
                }
        }
    }
    
return false;
      
}  
  
/**
 * @brief Checks if there is a solution when finding a solution
 *
 * @details Passes in dummy values and checks if there is no empty space and returns
            true, also checks if there is not an available rectangle and returns false
 *          
 * @param in: None
 *
 * @note None
 */
 
bool SolverClass::isSolution()
{
    bool check_space = false;
    bool check_rects = false;
    int dummy;
    int dummyval;
    
    if(!checkEmptySpace(dummy, dummyval))
    {
        check_space = true;
    }
    dummy = -1;
    if(!getNext(dummy))
    {
        check_rects = true;
    }
    
    return (check_space && check_rects);
}

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef SOLVERCLASS_CPP







