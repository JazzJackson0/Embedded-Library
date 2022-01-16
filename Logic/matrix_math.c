#include "matrix_math.h"

Matrix* Add_Matrices(Matrix *m1, Matrix *m2) {

    Matrix *sum;
    sum->rowNum = m1->rowNum;
    sum->columnNum = m1->columnNum;
    
    for (int m = 0; m < m1->rowNum; m++) {

        for (int n = 0; n < m1->columnNum; n++) {
            sum->matrix[m][n] = m1->matrix[m][n] + m2->matrix[m][n];
        }
    }

    return sum;
}

Matrix* Subtract_Matrices(Matrix *m1, Matrix *m2) {

    Matrix *difference;
    difference->rowNum = m1->rowNum;
    difference->columnNum = m1->columnNum;
    
    for (int m = 0; m < m1->rowNum; m++) {

        for (int n = 0; n < m1->columnNum; n++) {
            difference->matrix[m][n] = m1->matrix[m][n] - m2->matrix[m][n];
        }
    }

    return difference;
}

Matrix* Multiply_Matrices(Matrix *m1, Matrix *m2) {

    Matrix *product;
    product->rowNum = m1->rowNum;
    product->columnNum = m2->columnNum;

    for (int i = 0; i < m2->columnNum; i++) {

        for (int j = 0; j < m1->rowNum; j++) {
            
            for (int k = 0; k < m2->rowNum; k++) { //Elements
                
                product->matrix[j][i] += m1->matrix[j][k] * m2->matrix[k][i];
            }
        }
    }

    return product;
}


Matrix* Get_MatrixTranspose(Matrix *matrix) {
    
    Matrix *matrixT;
    matrixT->rowNum = matrix->columnNum;
    matrixT->columnNum = matrix->rowNum;

    for (int i = 0; i < matrix->rowNum; i++) {

        for (int j = 0; j < matrix->columnNum; j++) {

            matrixT->matrix[j][i] = matrix->matrix[i][j];
        }
    }

    return matrix;
}


Matrix* Get_MatrixInverse(Matrix *matrix) {

    //Not yet implemented
    Matrix *matrixI;
    matrixI->rowNum = matrix->rowNum;
    matrixI->columnNum = matrix->columnNum;

    return matrixI;
}


/*
 * 			TO-DO
 * 			-----
 *  - Handle incompatible matrix dimension error
 *
 *  - Write Matrix_Inverse code
 *  
 *  - Test Code
 *  */