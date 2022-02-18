#include <assert.h>
#include <stdlib.h>
#include "MatrixMath.h"

void MatirxInitTest();
void PopulateMatrixTest();
void Add_MatricesTest_2x2();
void Subtract_MatricesTest_2x2();
void Multiply_MatricesTest_2x2();
void Get_MatrixTransposeTest_2x2();
void Get_MatrixInverseTest();

Matrix *m1;
Matrix *m2;
double Data[2][2] = { {1.0, 2.0},
                      {3.0, 4.0} };

int main(int argc, char *argv[]) {

    MatirxInitTest();
    PopulateMatrixTest();
    Add_MatricesTest_2x2();
    Subtract_MatricesTest_2x2();
    Multiply_MatricesTest_2x2();
    Get_MatrixTransposeTest_2x2();
    Get_MatrixInverseTest();
    return 0;
}


/**
 * @brief 
 * 
 * @return ** void 
 */
void MatirxInitTest() {
    m1 = MatrixInit(2, 2);

    assert(2 == m1->rowNum);
    assert(2 == m1->columnNum);

    assert(0.0 == m1->matrix[0][0]);
    assert(0.0 == m1->matrix[0][1]);
    assert(0.0 == m1->matrix[1][0]);
    assert(0.0 == m1->matrix[1][1]);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void PopulateMatrixTest() {
    m1 = MatrixInit(2, 2);
    PopulateMatrix(m1, (double *)&Data);
    assert(1.0 == m1->matrix[0][0]);
    assert(2.0 == m1->matrix[0][1]);
    assert(3.0 == m1->matrix[1][0]);
    assert(4.0 == m1->matrix[1][1]);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Add_MatricesTest_2x2() {
    m1 = MatrixInit(2, 2);
    m1->matrix[0][0] = 2.0;
    m1->matrix[0][1] = 2.0;
    m1->matrix[1][0] = 2.0;
    m1->matrix[1][1] = 2.0;

    m2 = MatrixInit(2, 2);
    m2->matrix[0][0] = 3.0;
    m2->matrix[0][1] = 3.0;
    m2->matrix[1][0] = 3.0;
    m2->matrix[1][1] = 3.0;

    assert(2 == Add_Matrices(m1, m2)->rowNum);
    assert(2 == Add_Matrices(m1, m2)->columnNum);

    assert(5.0 == Add_Matrices(m1, m2)->matrix[0][0]);
    assert(5.0 == Add_Matrices(m1, m2)->matrix[0][1]);
    assert(5.0 == Add_Matrices(m1, m2)->matrix[1][0]);
    assert(5.0 == Add_Matrices(m1, m2)->matrix[1][1]);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Subtract_MatricesTest_2x2() {
    m1 = MatrixInit(2, 2);
    m1->matrix[0][0] = 10.0;
    m1->matrix[0][1] = 10.0;
    m1->matrix[1][0] = 10.0;
    m1->matrix[1][1] = 10.0;

    m2 = MatrixInit(2, 2);
    m2->matrix[0][0] = 3.0;
    m2->matrix[0][1] = 3.0;
    m2->matrix[1][0] = 3.0;
    m2->matrix[1][1] = 3.0;

    assert(2 == Subtract_Matrices(m1, m2)->rowNum);
    assert(2 == Subtract_Matrices(m1, m2)->columnNum);

    assert(7.0 == Subtract_Matrices(m1, m2)->matrix[0][0]);
    assert(7.0 == Subtract_Matrices(m1, m2)->matrix[0][1]);
    assert(7.0 == Subtract_Matrices(m1, m2)->matrix[1][0]);
    assert(7.0 == Subtract_Matrices(m1, m2)->matrix[1][1]);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Multiply_MatricesTest_2x2() {
    m1 = MatrixInit(2, 2);
    m1->matrix[0][0] = 10.0;
    m1->matrix[0][1] = 10.0;
    m1->matrix[1][0] = 10.0;
    m1->matrix[1][1] = 10.0;

    m2 = MatrixInit(2, 2);
    m2->matrix[0][0] = 3.0;
    m2->matrix[0][1] = 3.0;
    m2->matrix[1][0] = 3.0;
    m2->matrix[1][1] = 3.0;

    assert(2 == Multiply_Matrices(m1, m2)->rowNum);
    assert(2 == Multiply_Matrices(m1, m2)->columnNum);

    //double what = Multiply_Matrices(m1, m2)->matrix[0][0];
    assert(60.0 == Multiply_Matrices(m1, m2)->matrix[0][0]);
    assert(60.0 == Multiply_Matrices(m1, m2)->matrix[0][1]);
    assert(60.0 == Multiply_Matrices(m1, m2)->matrix[1][0]);
    assert(60.0 == Multiply_Matrices(m1, m2)->matrix[1][1]);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Get_MatrixTransposeTest_2x2() {
    m1 = MatrixInit(2, 2);
    m1->matrix[0][0] = 1.0;
    m1->matrix[0][1] = 2.0;
    m1->matrix[1][0] = 3.0;
    m1->matrix[1][1] = 4.0;

    assert(2 == Get_MatrixTranspose(m1)->rowNum);
    assert(2 == Get_MatrixTranspose(m1)->columnNum);

    assert(1.0 == Get_MatrixTranspose(m1)->matrix[0][0]);
    assert(3.0 == Get_MatrixTranspose(m1)->matrix[0][1]);
    assert(2.0 == Get_MatrixTranspose(m1)->matrix[1][0]);
    assert(4.0 == Get_MatrixTranspose(m1)->matrix[1][1]);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Get_MatrixInverseTest() {
    
    m1 = MatrixInit(2, 2);
    Matrix *inverse = MatrixInit(2, 2);
    m1->matrix[0][0] = 1.0;
    m1->matrix[0][1] = 2.0;
    m1->matrix[1][0] = 3.0;
    m1->matrix[1][1] = 4.0;

    assert(1 == Get_MatrixInverse(m1, inverse));

    assert(-2.0 == inverse->matrix[0][0]);
    assert(1.0 == inverse->matrix[0][1]);
    assert(1.5 == inverse->matrix[1][0]);
    assert(-0.5 == inverse->matrix[1][1]);
}


/*
 * 			TO-DO
 * 			-----
 *  - Add Test for PopulateMatrix()
 *  - Add tests for mismatched matrix dimension errors
 *
 *  - free memory?
 *  
 *  - More complex addition, multiplication, etc examples
 *  */