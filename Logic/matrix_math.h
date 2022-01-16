#pragma once

typedef struct matrix Matrix;

//DECLARATIONS
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
 * @brief 
 * 
 * @param matrix 
 * @return ** Matrix* 
 */
Matrix* Get_MatrixInverse(Matrix *matrix);


struct matrix {
    double** matrix;
    int rowNum;
    int columnNum;
};