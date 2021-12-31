#pragma once

typedef struct matrix Matrix;

Matrix* Add_Matrices(Matrix *m1, Matrix *m2);
Matrix* Subtract_Matrices(Matrix *m1, Matrix *m2);
Matrix* Multiply_Matrices(Matrix *m1, Matrix *m2);
Matrix* Get_MatrixTranspose(Matrix *matrix);
Matrix* Get_MatrixInverse(Matrix *matrix);


struct matrix {
    double** matrix;
    int matrix_rowNum;
    int matrix_columnNum;
};