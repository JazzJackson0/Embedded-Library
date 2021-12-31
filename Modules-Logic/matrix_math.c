#include "matrix_math.h"



Matrix* Add_Matrices(Matrix *m1, Matrix *m2) {

    Matrix *sum;
    sum->matrix_rowNum = m1->matrix_rowNum;
    sum->matrix_columnNum = m1->matrix_columnNum;
    
    for (int m = 0; m < m1->matrix_rowNum; m++) {

        for (int n = 0; n < m1->matrix_columnNum; n++) {
            sum->matrix[m][n] = m1->matrix[m][n] + m2->matrix[m][n];
        }
    }

    return sum;
}

Matrix* Subtract_Matrices(Matrix *m1, Matrix *m2) {

    Matrix *difference;
    difference->matrix_rowNum = m1->matrix_rowNum;
    difference->matrix_columnNum = m1->matrix_columnNum;
    
    for (int m = 0; m < m1->matrix_rowNum; m++) {

        for (int n = 0; n < m1->matrix_columnNum; n++) {
            difference->matrix[m][n] = m1->matrix[m][n] - m2->matrix[m][n];
        }
    }

    return difference;
}

Matrix* Multiply_Matrices(Matrix *m1, Matrix *m2) {

    Matrix *product;
    product->matrix_rowNum = m1->matrix_rowNum;
    product->matrix_columnNum = m2->matrix_columnNum;

    for (int i = 0; i < m2->matrix_columnNum; i++) {

        for (int j = 0; j < m1->matrix_rowNum; j++) {
            
            for (int k = 0; k < m2->matrix_rowNum; k++) { //Elements
                
                product->matrix[j][i] += m1->matrix[j][k] * m2->matrix[k][i];
            }
        }
    }

    return product;
}


Matrix* Get_MatrixTranspose(Matrix *matrix) {
    
    Matrix *matrixT;
    matrixT->matrix_rowNum = matrix->matrix_columnNum;
    matrixT->matrix_columnNum = matrix->matrix_rowNum;

    for (int i = 0; i < matrix->matrix_rowNum; i++) {

        for (int j = 0; j < matrix->matrix_columnNum; j++) {

            matrixT->matrix[j][i] = matrix->matrix[i][j];
        }
    }

    return matrix;
}


Matrix* Get_MatrixInverse(Matrix *matrix) {

    //Not yet implemented
    Matrix *matrixI;
    matrixI->matrix_rowNum = matrix->matrix_rowNum;
    matrixI->matrix_columnNum = matrix->matrix_columnNum;
    

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