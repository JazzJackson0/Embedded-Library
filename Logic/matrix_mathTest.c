#include <assert.h>
#include <stdlib.h>
#include "matrix_math.h"

void Add_MatricesTest_2x2();
void Subtract_MatricesTest_2x2();
void Multiply_MatricesTest_2x2();
void Get_MatrixTransposeTest_2x2();
void Get_MatrixInverseTest();

Matrix m1;
Matrix m2;

int main(int argc, char *argv[]) {

    Add_MatricesTest_2x2();
    Subtract_MatricesTest_2x2();
    Multiply_MatricesTest_2x2();
    Get_MatrixTransposeTest_2x2();
    return 0;
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Add_MatricesTest_2x2() {
    m1.rowNum = 2;
    m1.columnNum = 2;
    m1.matrix[0][0] = 2.0;
    m1.matrix[0][1] = 2.0;
    m1.matrix[1][0] = 2.0;
    m1.matrix[1][1] = 2.0;

    m2.rowNum = 2;
    m2.columnNum = 2;
    m2.matrix[0][0] = 3.0;
    m2.matrix[0][1] = 3.0;
    m2.matrix[1][0] = 3.0;
    m2.matrix[1][1] = 3.0;

    assert(2 == Add_Matrices(&m1, &m2)->rowNum);
    assert(2 == Add_Matrices(&m1, &m2)->columnNum);

    assert(5.0 == Add_Matrices(&m1, &m2)->matrix[0][0]);
    assert(5.0 == Add_Matrices(&m1, &m2)->matrix[0][1]);
    assert(5.0 == Add_Matrices(&m1, &m2)->matrix[1][0]);
    assert(5.0 == Add_Matrices(&m1, &m2)->matrix[1][1]);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Subtract_MatricesTest_2x2() {
    m1.rowNum = 2;
    m1.columnNum = 2;
    m1.matrix[0][0] = 10.0;
    m1.matrix[0][1] = 10.0;
    m1.matrix[1][0] = 10.0;
    m1.matrix[1][1] = 10.0;

    m2.rowNum = 2;
    m2.columnNum = 2;
    m2.matrix[0][0] = 3.0;
    m2.matrix[0][1] = 3.0;
    m2.matrix[1][0] = 3.0;
    m2.matrix[1][1] = 3.0;

    assert(2 == Subtract_Matrices(&m1, &m2)->rowNum);
    assert(2 == Subtract_Matrices(&m1, &m2)->columnNum);

    assert(7.0 == Subtract_Matrices(&m1, &m2)->matrix[0][0]);
    assert(7.0 == Subtract_Matrices(&m1, &m2)->matrix[0][1]);
    assert(7.0 == Subtract_Matrices(&m1, &m2)->matrix[1][0]);
    assert(7.0 == Subtract_Matrices(&m1, &m2)->matrix[1][1]);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Multiply_MatricesTest_2x2() {
    m1.rowNum = 2;
    m1.columnNum = 2;
    m1.matrix[0][0] = 10.0;
    m1.matrix[0][1] = 10.0;
    m1.matrix[1][0] = 10.0;
    m1.matrix[1][1] = 10.0;

    m2.rowNum = 2;
    m2.columnNum = 2;
    m2.matrix[0][0] = 3.0;
    m2.matrix[0][1] = 3.0;
    m2.matrix[1][0] = 3.0;
    m2.matrix[1][1] = 3.0;

    assert(2 == Multiply_Matrices(&m1, &m2)->rowNum);
    assert(2 == Multiply_Matrices(&m1, &m2)->columnNum);

    assert(30.0 == Multiply_Matrices(&m1, &m2)->matrix[0][0]);
    assert(30.0 == Multiply_Matrices(&m1, &m2)->matrix[0][1]);
    assert(30.0 == Multiply_Matrices(&m1, &m2)->matrix[1][0]);
    assert(30.0 == Multiply_Matrices(&m1, &m2)->matrix[1][1]);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Get_MatrixTransposeTest_2x2() {
    m1.rowNum = 2;
    m1.columnNum = 2;
    m1.matrix[0][0] = 1.0;
    m1.matrix[0][1] = 2.0;
    m1.matrix[1][0] = 3.0;
    m1.matrix[1][1] = 4.0;

    assert(2 == Get_MatrixTranspose(&m1)->rowNum);
    assert(2 == Get_MatrixTranspose(&m1)->columnNum);

    assert(1.0 == Get_MatrixTranspose(&m1)->matrix[0][0]);
    assert(3.0 == Get_MatrixTranspose(&m1)->matrix[0][1]);
    assert(2.0 == Get_MatrixTranspose(&m1)->matrix[1][0]);
    assert(4.0 == Get_MatrixTranspose(&m1)->matrix[1][1]);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Get_MatrixInverseTest() {
    
}