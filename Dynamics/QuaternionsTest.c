#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "quaternions.h"

void MultiplyQuaternionsTest();
void DivideQuaternionsTest();
void Rotate_VectorTest();
void RotateByAngleTest();
void NormalizeQuaternionTest();
void Get_QuaternionLengthTest();
void Get_QuaternionInverseTest();
void Get_QuaternionConjugateTest();
const double degree2RadConvert = 3.141592 / 180;
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

    q1.q0 = 1.0;
    q1.q1 = 2.0;
    q1.q2 = 1.0;
    q1.q3 = 2.0;

    q2.q0 = 1.0;
    q2.q1 = 2.0;
    q2.q2 = 3.0;
    q2.q3 = 4.0;

    assert(-14.0 == MultiplyQuaternions(&q1, &q2)->q0);
    assert(-10.0 == MultiplyQuaternions(&q1, &q2)->q1);
    assert(-10.0 == MultiplyQuaternions(&q1, &q2)->q2);
    assert(-6.0 == MultiplyQuaternions(&q1, &q2)->q3);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Get_QuaternionLengthTest() {
    q1.q0 = 1.0;
    q1.q1 = 2.0;
    q1.q2 = 3.0;
    q1.q3 = 4.0;

    assert(sqrt( (q1.q0 * q1.q0) + (q1.q1 * q1.q1) + (q1.q2 * q1.q2) + (q1.q3 * q1.q3) )
        == Get_QuaternionLength(&q1));
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Get_QuaternionConjugateTest() {
    q1.q0 = 1.0;
    q1.q1 = 2.0;
    q1.q2 = 3.0;
    q1.q3 = 4.0;

    assert(1.0 == Get_QuaternionConjugate(&q1)->q0);
    assert(-2.0 == Get_QuaternionConjugate(&q1)->q1);
    assert(-3.0 == Get_QuaternionConjugate(&q1)->q2);
    assert(-4.0 == Get_QuaternionConjugate(&q1)->q3);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Get_QuaternionInverseTest() {
    q1.q0 = 1.0;
    q1.q1 = 2.0;
    q1.q2 = 3.0;
    q1.q3 = 4.0;

    assert(1.0 / sqrt( (q1.q0 * q1.q0) + (q1.q1 * q1.q1) + (q1.q2 * q1.q2) + (q1.q3 * q1.q3) )
        == Get_QuaternionInverse(&q1)->q0);
    assert(-2.0 / sqrt( (q1.q0 * q1.q0) + (q1.q1 * q1.q1) + (q1.q2 * q1.q2) + (q1.q3 * q1.q3) ) 
        == Get_QuaternionInverse(&q1)->q1);
    assert(-3.0 / sqrt( (q1.q0 * q1.q0) + (q1.q1 * q1.q1) + (q1.q2 * q1.q2) + (q1.q3 * q1.q3) ) 
        == Get_QuaternionInverse(&q1)->q2);
    assert(-4.0 / sqrt( (q1.q0 * q1.q0) + (q1.q1 * q1.q1) + (q1.q2 * q1.q2) + (q1.q3 * q1.q3) ) 
        == Get_QuaternionInverse(&q1)->q3);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void DivideQuaternionsTest() {
    q1.q0 = 1.0;
    q1.q1 = 2.0;
    q1.q2 = 1.0;
    q1.q3 = 2.0;

    q2.q0 = 1.0;
    q2.q1 = 2.0;
    q2.q2 = 3.0;
    q2.q3 = 4.0;

    double t1 = MultiplyQuaternions(&q1, Get_QuaternionInverse(&q2))->q0;
    double t2 = DivideQuaternions(&q1, &q2)->q0;

    assert(MultiplyQuaternions(&q1, Get_QuaternionInverse(&q2))->q0 
        == DivideQuaternions(&q1, &q2)->q0);
    assert(MultiplyQuaternions(&q1, Get_QuaternionInverse(&q2))->q1 
        == DivideQuaternions(&q1, &q2)->q1);
    assert(MultiplyQuaternions(&q1, Get_QuaternionInverse(&q2))->q2 
        == DivideQuaternions(&q1, &q2)->q2);
    assert(MultiplyQuaternions(&q1, Get_QuaternionInverse(&q2))->q3 
        == DivideQuaternions(&q1, &q2)->q3);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Rotate_VectorTest() {
    q1.q0 = 1.0;
    q1.q1 = 2.0;
    q1.q2 = 1.0;
    q1.q3 = 2.0;

    double vector[] = {1.0, 2.0, 3.0, 4.0};

    q2.q0 = 1.0;
    q2.q1 = 2.0;
    q2.q2 = 3.0;
    q2.q3 = 4.0;
    Quaternion *q_result = MultiplyQuaternions(&q1, &q2);

    assert(MultiplyQuaternions(q_result, Get_QuaternionConjugate(&q1))->q0 
        == Rotate_Vector(vector, &q1)->q0);
    assert(MultiplyQuaternions(q_result, Get_QuaternionConjugate(&q1))->q1 
        == Rotate_Vector(vector, &q1)->q1);
    assert(MultiplyQuaternions(q_result, Get_QuaternionConjugate(&q1))->q2 
        == Rotate_Vector(vector, &q1)->q2);
    assert(MultiplyQuaternions(q_result, Get_QuaternionConjugate(&q1))->q3 
        == Rotate_Vector(vector, &q1)->q3);
}

void RotateByAngleTest() {
    q1.q0 = 1.0;
    q1.q1 = 2.0;
    q1.q2 = 3.0;
    q1.q3 = 4.0;

    assert(cos((30.0 / 2) * degree2RadConvert) == RotateByAngle(&q1, 30.0)->q0);
    assert(q1.q1 * sin( (30.0 / 2) * degree2RadConvert) == RotateByAngle(&q1, 30.0)->q1);
    assert(q1.q2 * sin( (30.0 / 2) * degree2RadConvert) == RotateByAngle(&q1, 30.0)->q2);
    assert(q1.q3 * sin( (30.0 / 2) * degree2RadConvert) == RotateByAngle(&q1, 30.0)->q3);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void NormalizeQuaternionTest() {
    q1.q0 = 1.0;
    q1.q1 = 2.0;
    q1.q2 = 3.0;
    q1.q3 = 4.0;

    assert(q1.q0 /= sqrt( 1 - (1 - Get_QuaternionLength(&q1))) == NormalizeQuaternion(&q1)->q0);
    assert(q1.q1 /= sqrt( 1 - (1 - Get_QuaternionLength(&q1))) == NormalizeQuaternion(&q1)->q1);
    assert(q1.q2 /= sqrt( 1 - (1 - Get_QuaternionLength(&q1))) == NormalizeQuaternion(&q1)->q2);
    assert(q1.q3 /= sqrt( 1 - (1 - Get_QuaternionLength(&q1))) == NormalizeQuaternion(&q1)->q3);
}

