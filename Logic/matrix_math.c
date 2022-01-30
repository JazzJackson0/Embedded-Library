#include "matrix_math.h"
#include <stdlib.h>
#include <stdio.h>

//Static Prototypes
static void getCofactor(Matrix *A, Matrix *temp, int p, int q, int n);
static double determinant(Matrix *A, int n);
static void adjoint(Matrix *A, Matrix *adj);

Matrix* MatrixInit(int rows, int columns) {
    Matrix *m = malloc(sizeof(Matrix));

    m->rowNum = rows;
    m->columnNum = columns;
    m->matrix = (double**) malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) { m->matrix[i] = (double*) calloc(columns, sizeof(double)); }
    return m;
}

void PopulateMatrix(Matrix *m, double *data) {

    for (int i = 0; i < m->rowNum; i++) {

        for (int j = 0; j < m->columnNum; j++) {
            m->matrix[i][j] = *(data + (i * m->rowNum) + j);
        }
    }
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

int Get_MatrixInverse(Matrix *A, Matrix *inverse) {
    
    if (A->rowNum != A->columnNum) { return 0; }

    // Find determinant of A
    int det = determinant(A, A->rowNum);
    if (det == 0) {
        return 0;
    }
 
    // Find adjoint
    Matrix *adj = MatrixInit(A->rowNum, A->columnNum);
    adjoint(A, adj);
 
    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i = 0; i < A->rowNum; i++)
        for (int j = 0; j < A->rowNum; j++)
            inverse->matrix[i][j] = adj->matrix[i][j]/ det;
 
    return 1;
}



//Below is modified C++ code from GeeksforGeeks-------------------------------------------------
//All just to caluculate the freaking inverse.

// Function to get cofactor of A (sized: p x q) in temp. n is current
// dimension of A
static void getCofactor(Matrix *A, Matrix *temp, int p, int q, int n) {
    int i = 0, j = 0;
 
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++) {
        
        for (int col = 0; col < n; col++) {
            
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q) {
                temp->matrix[i][j++] = A->matrix[row][col];
 
                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

/* Recursive function for finding determinant of matrix.
   n is current dimension of A. */
static double determinant(Matrix *A, int n) {
    double D = 0; // Initialize result
    
    //  Base case : if matrix contains single element
    if (n == 1)
        return A->matrix[0][0];
    
    // To store cofactors
    Matrix *temp = MatrixInit(A->rowNum, A->columnNum);
 
    int sign = 1;  // To store sign multiplier
 
     // Iterate for each element of first row
    for (int f = 0; f < n; f++) {
        
        // Getting Cofactor of A[0][f]
        getCofactor(A, temp, 0, f, n);
        D += sign * A->matrix[0][f] * determinant(temp, n - 1);
 
        // terms are to be added with alternate sign
        sign = -sign;
    }
    free(temp);
    return D;
}
 
// Function to get adjoint of A in adj.
static void adjoint(Matrix *A, Matrix *adj) {
    if (adj->rowNum == 1) {
        adj->matrix[0][0] = 1;
        return;
    }
 
    // temp is used to store cofactors of A
    int sign = 1;
    Matrix *temp = MatrixInit(A->rowNum, A->columnNum);
 
    for (int i = 0; i < A->rowNum; i++) {
        
        for (int j = 0; j < A->rowNum; j++) {
            
            // Get cofactor of A[i][j]
            getCofactor(A, temp, i, j, A->rowNum);
 
            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i + j) % 2 == 0) ? 1: -1;
 
            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj->matrix[j][i] = (sign)*(determinant(temp, A->rowNum - 1));
        }
    }
}
 



/*
 * 			TO-DO
 * 			-----
 *  - Write code for vector transpose
 *
 *  - 
 *  
 *  - 
 *  */