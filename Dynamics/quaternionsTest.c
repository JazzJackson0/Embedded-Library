#include <assert.h>
#include <stdlib.h>
#include "quaternions.h"

void MultiplyQuaternionsTest();
void DivideQuaternionsTest();
void Rotate_VectorTest();
void RotateByAngleTest();
void NormalizeQuaternionTest();
void Get_QuaternionLengthTest();
void Get_QuaternionInverseTest();
void Get_QuaternionConjugateTest();

Quaternion q1;
Quaternion q2;

int main(int argc, char *argv[]) {

    MultiplyQuaternionsTest();
    DivideQuaternionsTest();
    Rotate_VectorTest();
    RotateByAngleTest();
    NormalizeQuaternionTest();
    Get_QuaternionLengthTest();
    Get_QuaternionInverseTest();
    Get_QuaternionConjugateTest();
    return 0;
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void MultiplyQuaternionsTest() {

    q1.q0 = 0.0;
    q1.q1 = 0.0;
    q1.q2 = 0.0;
    q1.q3 = 0.0;

    q2.q0 = 0.0;
    q2.q1 = 0.0;
    q2.q2 = 0.0;
    q2.q3 = 0.0;

    assert(0.0, MultiplyQuaternions(&q1, &q2)->q0);
    assert(0.0, MultiplyQuaternions(&q1, &q2)->q1);
    assert(0.0, MultiplyQuaternions(&q1, &q2)->q2);
    assert(0.0, MultiplyQuaternions(&q1, &q2)->q3);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void DivideQuaternionsTest() {
    q1.q0 = 0.0;
    q1.q1 = 0.0;
    q1.q2 = 0.0;
    q1.q3 = 0.0;

    q2.q0 = 0.0;
    q2.q1 = 0.0;
    q2.q2 = 0.0;
    q2.q3 = 0.0;

    assert(0.0, DivideQuaternions(&q1, &q2)->q0);
    assert(0.0, DivideQuaternions(&q1, &q2)->q1);
    assert(0.0, DivideQuaternions(&q1, &q2)->q2);
    assert(0.0, DivideQuaternions(&q1, &q2)->q3);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Rotate_VectorTest() {
    q1.q0 = 0.0;
    q1.q1 = 0.0;
    q1.q2 = 0.0;
    q1.q3 = 0.0;

    double *vector;
    vector[0] = 0.0;
    vector[1] = 0.0;
    vector[2] = 0.0;
    vector[3] = 0.0;

    assert(0.0, Rotate_Vector(vector, &q1));
    assert(0.0, Rotate_Vector(vector, &q1));
    assert(0.0, Rotate_Vector(vector, &q1));
    assert(0.0, Rotate_Vector(vector, &q1));
}

void RotateByAngleTest() {
    q1.q0 = 0.0;
    q1.q1 = 0.0;
    q1.q2 = 0.0;
    q1.q3 = 0.0;

    assert(0.0, RotateByAngle(&q1, 0.0));
    assert(0.0, RotateByAngle(&q1, 0.0));
    assert(0.0, RotateByAngle(&q1, 0.0));
    assert(0.0, RotateByAngle(&q1, 0.0));
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void NormalizeQuaternionTest() {
    q1.q0 = 0.0;
    q1.q1 = 0.0;
    q1.q2 = 0.0;
    q1.q3 = 0.0;

    assert(0.0, NormalizeQuaternion(&q1));
    assert(0.0, NormalizeQuaternion(&q1));
    assert(0.0, NormalizeQuaternion(&q1));
    assert(0.0, NormalizeQuaternion(&q1));
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Get_QuaternionLengthTest() {
    q1.q0 = 0.0;
    q1.q1 = 0.0;
    q1.q2 = 0.0;
    q1.q3 = 0.0;

    assert(0.0, Get_QuaternionLength(&q1));
    assert(0.0, Get_QuaternionLength(&q1));
    assert(0.0, Get_QuaternionLength(&q1));
    assert(0.0, Get_QuaternionLength(&q1));
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Get_QuaternionInverseTest() {
    q1.q0 = 0.0;
    q1.q1 = 0.0;
    q1.q2 = 0.0;
    q1.q3 = 0.0;

    assert(0.0, Get_QuaternionInverse(&q1)->q0);
    assert(0.0, Get_QuaternionInverse(&q1)->q1);
    assert(0.0, Get_QuaternionInverse(&q1)->q2);
    assert(0.0, Get_QuaternionInverse(&q1)->q3);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Get_QuaternionConjugateTest() {
    q1.q0 = 0.0;
    q1.q1 = 0.0;
    q1.q2 = 0.0;
    q1.q3 = 0.0;

    assert(0.0, Get_QuaternionConjugate(&q1)->q0);
    assert(0.0, Get_QuaternionConjugate(&q1)->q1);
    assert(0.0, Get_QuaternionConjugate(&q1)->q2);
    assert(0.0, Get_QuaternionConjugate(&q1)->q3);
}