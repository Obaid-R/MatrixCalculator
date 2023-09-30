#include "Matrix.h"

/*
Function: Constructor for MatrixType
Purpose: Initializes the number of rows and columns to 0 for the matrix
Parameters: N/A
Returns: N/A
*/
MatrixType::MatrixType()
{
    numRows = 0;
    numCols = 0;
}

/*
Function: SetSize
Purpose: Sets the number of rows and columns to desired number for the matrix
Parameters: Desired row and column size
Returns: Void
*/
void MatrixType::SetSize(int rowSize, int colSize)
{
    numRows = rowSize;
    numCols = colSize;
}

/*
Function: StoreItem
Purpose: Stores the desired item at the specified position in the matrix
Parameters: Item to store, row and column of position of storage
Returns: Void
*/
void MatrixType::StoreItem(int item, int row, int col)
{
    values[row][col] = item;
}

/*
Function: Add
Purpose: If two matrices are add compatible, adds them together
Parameters: Other operand matrix and the resultant matrix
Returns: Void
*/
void MatrixType::Add(MatrixType otherOperand, MatrixType& result)
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            result.values[i][j] = values[i][j] + otherOperand.values[i][j];
        }
    }
}

/*
Function: Sub
Purpose: If two matrices are subtract compatible, subtracts second matrix from first matrix
Parameters: Other operand matrix and the resultant matrix
Returns: Void
*/
void MatrixType::Sub(MatrixType otherOperand, MatrixType& result)
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            result.values[i][j] = values[i][j] - otherOperand.values[i][j];
        }
    }
}

/*
Function: Mult
Purpose: If two matrices are multiplication compatible, performs matrix multiplication on both matrices
Parameters: Other operand matrix and the resultant matrix
Returns: Void
*/
void MatrixType::Mult(MatrixType otherOperand, MatrixType& result)
{
    int sum = 0;
    // Rows of the first matrix
    for (int i = 0; i < numRows; i++)
    {
        // Columns of the second matrix
        for (int j = 0; j < otherOperand.numCols; j++)
        {
            // Columns of the first matrix which is equal to the rows of the second matrix
            for (int k = 0; k < numCols; k++)
            {
                sum += values[i][k] * otherOperand.values[k][j];
            }
            result.values[i][j] = sum;
            sum = 0;
        }
    }
}

/*
Function: Print
Purpose: Prints all the values in the given matrix
Parameters: N/A
Returns: Void
*/
void MatrixType::Print()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            cout << values[i][j] << " ";
        }
        cout << endl;
    }
}

/*
Function: AddSubCompatible
Purpose: Checks if the dimensions of two matrices are the same
Parameters: Other operand matrix
Returns: Bool
*/
bool MatrixType::AddSubCompatible(MatrixType otherOperand)
{
    if (numRows == otherOperand.numRows && numCols == otherOperand.numCols)
    {
        return true;
    }

    return false;
}

/*
Function: MultCompatible
Purpose: Checks if the number of columns of the first matrix and the number of rows of the second matrix are the same
Parameters: Other operand matrix
Returns: Bool
*/
bool MatrixType::MultCompatible(MatrixType otherOperand)
{
    if (numCols == otherOperand.numRows)
    {
        return true;
    }

    return false;
}
