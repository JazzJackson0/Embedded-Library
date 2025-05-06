#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct matrix Matrix;

//DECLARATIONS
/**
 * @brief Initialize matrix
 * 
 * @param rows Matrix Row Size
 * @param columns Matrix Column Size
 * @return ** Matrix
 */
Matrix MatrixInit(int rows, int columns);

/**
 * @brief Deinitialize matrix
 * 
 * @param m 
 */
void MatrixDeInit(Matrix m);

/**
 * @brief Populate matrix with given values.
 * 
 * @param m The Matrix you want to populate.
 * @param data 2D Array of data to place in a given matrix.
 * @return ** void 
 */
void PopulateMatrix(Matrix m, double *data);

/**
 * @brief Add two matrices
 * 
 * @param m1 Left Matrix
 * @param m2 Right Matrix
 * @return ** Matrix Matrix Sum
 */
Matrix AddMatrices(Matrix m1, Matrix m2);
/**
 * @brief Subtract two matrices
 * 
 * @param m1 Left Matrix
 * @param m2 Right Matrix
 * @return ** Matrix Matrix Difference
 */
Matrix SubtractMatrices(Matrix m1, Matrix m2);
/**
 * @brief Multiply two matrices
 * 
 * @param m1 Left Matrix
 * @param m2 Right Matrix
 * @return ** Matrix Matrix Product
 */
Matrix MultiplyMatrices(Matrix m1, Matrix m2);
/**
 * @brief Get transpose of a given matrix
 * 
 * @param matrix Matrix to transpose
 * @return ** Matrix Transposed matrix
 */
Matrix Get_MatrixTranspose(Matrix matrix);
/**
 * @brief Function to calculate and store inverse, returns 0 if
 *          matrix is singular, or if it is not square.
 * 
 * @param A Matrix to Invert
 * @param inverse Storage for Inverted matrix
 * @return ** int 1 is returned upon successful inversion
 *              0 is returned if matrix is singular or if it is not square.
 */
int Get_MatrixInverse(Matrix A, Matrix *inverse);


struct matrix {
    double** matrix;
    int rowNum;
    int columnNum;
};