

/*
 * Matrix Calculator Library
 * Author: Ryan Kane
 *
 * Library includes function for each matrix operation,
 * as well as helper functions for inputting and
 * allocating the matrices
 */

#include "Matrix.h"


/*
 *	Function: add
 *	------------------------------
 *	Gets two matrices as parameters, and adds them together
 *
 *	@param matrix1
 *	 First input matrix(2D array) to be added
 *	@param matrix2
 *	 Second input matrix(2D array) to be added
 *	@param rows
 *	 Number of rows in both matrices
 *	@param columns
 *	 Number of columns in both matrices
 *
 *	@return new_matrix
 *	 The sum of the 2 input matrices
 */
float** add(float** matrix1, float** matrix2, float** result, int rows, int columns)
{
    //float** new_matrix = allocate_matrix(rows, columns);

    // Perform Add operation
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}


/*
 *	Function: subtract
 *	------------------------------
 *	Gets two matrices as parameters, and subtracts matrix 2 from matrix 1
 *
 *	@param matrix1
 *	 First input matrix(2D array) to be added
 *	@param matrix2
 *	 Second input matrix(2D array) to be added
 *	@param rows
 *	 Number of rows in both matrices
 *	@param columns
 *	 Number of columns in both matrices
 *
 *	@return new_matrix
 *	 The difference of the 2 input matrices
 */
float** subtract(float** matrix1, float** matrix2, float** result, int rows, int columns)
{
    //float** new_matrix = allocate_matrix(rows, columns);

    // Perform SUB operation
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}


/*
 *	Function: multiply
 *	------------------------------
 *	Gets two matrices as parameters, then calculates the dot product
 *
 *	@param matrix1
 *	 First input matrix(2D array) to be added
 *	@param matrix2
 *	 Second input matrix(2D array) to be added
 *	@param rows1
 *	 Number of rows in matrix 1
 *	@param columns1
 *	 Number of columns in matrix 1
 *	@param rows2
 *	 Number of rows in matrix 2
 *	@param columns2
 *	 Number of columns in matrix 2
 *
 *	@return new_matrix
 *	 The product of the 2 input matrices
 */
float** multiply(float** matrix1, float** matrix2, float** result, int rows1, int columns1, int rows2, int columns2)
{
    // Check for valid dimensions for multiplication
    if(columns1 != rows2) {
        printf("Invalid matrix dimensions");
        exit(1);
    }

    // Allocate new array
    //float** new_matrix = allocate_matrix(rows1, columns2);

    // float sum = 0;
    float sum;
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < columns2; j++) {
            sum = 0.0;
            for(int k = 0; k < columns1; k++) {
                sum = sum + (matrix1[i][k] * matrix2[k][j]);
            }
            result[i][j] = sum;
        }
    }
    return result;
}





/*
 *	Function: allocate_matrix
 *	------------------------------
 *	Return an int** pointing to a correctly allocated matrix based on rows/columns
 *
 *	rows: number of rows desired for the matrix
 *	columns: number of columns desired for the matrix
 *
 *	returns: An int** of size [rows][columns]
 */
float** allocate_matrix(int rows, int columns) {
    float ** arr = (float **) malloc(rows * sizeof(float *));
    for(int i = 0; i < rows; i++) {
        arr[i] = (float *) malloc(columns * sizeof(float));
        
        for(int j=0;j<columns; j++ )
            arr[i][j] = 0.0;
    }
    return arr;
}

