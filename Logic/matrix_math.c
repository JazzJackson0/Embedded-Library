#include "matrix_math.h"
#include <stdlib.h>
#include <stdio.h>

Matrix* MatrixInit(int rows, int columns) {
    Matrix *m = malloc(sizeof(Matrix));

    m->rowNum = rows;
    m->columnNum = columns;
    m->matrix = (double**) malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) { m->matrix[i] = (double*) calloc(columns, sizeof(double)); }
    return m;
}


Matrix* Add_Matrices(Matrix *m1, Matrix *m2) {

    if (m1->columnNum != m2->columnNum && m1->rowNum != m2->rowNum) {
        perror("Matrix dimensions do not match.");
        exit(1);
    }

    Matrix *sum = MatrixInit(m1->rowNum, m1->columnNum);

    for (int m = 0; m < m1->rowNum; m++) {

        for (int n = 0; n < m1->columnNum; n++) {
            sum->matrix[m][n] = m1->matrix[m][n] + m2->matrix[m][n];
        }
    }

    return sum;
}

Matrix* Subtract_Matrices(Matrix *m1, Matrix *m2) {

    if (m1->columnNum != m2->columnNum && m1->rowNum != m2->rowNum) {
        perror("Matrix dimensions do not match.");
        exit(1);
    }
    Matrix *difference = MatrixInit(m1->rowNum, m1->columnNum);
    
    for (int m = 0; m < m1->rowNum; m++) {

        for (int n = 0; n < m1->columnNum; n++) {
            difference->matrix[m][n] = m1->matrix[m][n] - m2->matrix[m][n];
        }
    }

    return difference;
}

Matrix* Multiply_Matrices(Matrix *m1, Matrix *m2) {

    if (m1->columnNum != m2->rowNum) {
        perror("Matrix dimensions do not match.");
        exit(1);
    }
    Matrix *product = MatrixInit(m1->rowNum, m2->columnNum);

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
    
    Matrix *matrixT = MatrixInit(matrix->columnNum, matrix->rowNum);

    // YOU NEED TO HANDLE THE CASE OF A SINGLE VECTOR.

    for (int i = 0; i < matrix->rowNum; i++) {

        for (int j = 0; j < matrix->columnNum; j++) {

            matrixT->matrix[j][i] = matrix->matrix[i][j];
        }
    }

    return matrixT;
}


Matrix* Get_MatrixInverse(Matrix *matrix) {

    //Not yet implemented
    Matrix *matrixI = MatrixInit(matrix->rowNum, matrix->columnNum);

    return matrixI;
}


/*
 * 			TO-DO
 * 			-----
 *  - Write Matrix_Inverse code
 *
 *  - Write code for vector transpose
 *  
 *  - 
 *  */