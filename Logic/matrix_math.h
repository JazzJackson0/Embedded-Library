#pragma once

typedef struct matrix Matrix;

//DECLARATIONS
/**
 * @brief 
 * 
 * @param rows 
 * @param columns 
 * @return ** Matrix* 
 */
Matrix* MatrixInit(int rows, int columns);

/**
 * @brief 
 * 
 * @param m Pointer to the Matrix you want to populate.
 * @param data 2D Array of data to place in a given matrix.
 * @return ** void 
 */
void PopulateMatrix(Matrix *m, double *data);

/**
 * @brief 
 * 
 * @param m1 
 * @param m2 
 * @return ** Matrix* 
 */
Matrix* Add_Matrices(Matrix *m1, Matrix *m2);
/**
 * @brief 
 * 
 * @param m1 
 * @param m2 
 * @return ** Matrix* 
 */
Matrix* Subtract_Matrices(Matrix *m1, Matrix *m2);
/**
 * @brief 
 * 
 * @param m1 
 * @param m2 
 * @return ** Matrix* 
 */
Matrix* Multiply_Matrices(Matrix *m1, Matrix *m2);
/**
 * @brief 
 * 
 * @param matrix 
 * @return ** Matrix* 
 */
Matrix* Get_MatrixTranspose(Matrix *matrix);
/**
 * @brief Function to calculate and store inverse, returns 0 if
 *          matrix is singular, or if it is not square.
 * 
 * @param A 
 * @param inverse 
 * @return ** int 
 */
int Get_MatrixInverse(Matrix *A, Matrix *inverse);


struct matrix {
    double** matrix;
    int rowNum;
    int columnNum;
};