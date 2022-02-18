#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "ComplexNums.h"

void Get_SinusoidalBasisTest();
void Set_ZTest_n0();
void Set_ZTest_n1();
void Set_ZTest_n2();
void ValuetoComplexNumTest();

complexNum c1;

int main(int argc, char *argv[]) {

    Get_SinusoidalBasisTest();
    Set_ZTest_n0();
    Set_ZTest_n1();
    Set_ZTest_n2();
    ValuetoComplexNumTest();
    return 0;
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Get_SinusoidalBasisTest() {

    assert(cos(30.0) == Get_SinusoidalBasis(30.0)->realPart);
    assert(-sin(30.0) == Get_SinusoidalBasis(30.0)->imaginaryPart);
}

/**
 * @brief Testing when When n = 0
 *      The output should be the cos and -sin of the input angle
 *          divided by the magnitude (r) ^ 0.
 * 
 * @return ** void 
 */
void Set_ZTest_n0() {

    assert(cos(30.0) == Set_Z(30.0, 5.0, 0)->realPart);
    assert(-sin(30.0) == Set_Z(30.0, 5.0, 0)->imaginaryPart);
}

/**
 * @brief Testing when When n = 1
 *          The output should be the cos and -sin of the input angle
 *          divided by the magnitude (r) ^ 1.
 * @return ** void 
 */
void Set_ZTest_n1() {

    assert((cos(30.0) / 5.0) == Set_Z(30.0, 5.0, 1)->realPart);
    assert((-sin(30.0) / 5.0) == Set_Z(30.0, 5.0, 1)->imaginaryPart);
}

/**
 * @brief Testing when When n > 1
 *          The output should be the cos and -sin of the input angle
 *          divided by the magnitude (r) ^ n.
 * @return ** void 
 */
void Set_ZTest_n2() {

    assert((cos(30.0) / (5.0 * 5.0)) == Set_Z(30.0, 5.0, 2)->realPart);
    assert((-sin(30.0) / (5.0 * 5.0)) == Set_Z(30.0, 5.0, 2)->imaginaryPart);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void ValuetoComplexNumTest() {
    
    double values[] = {3.7, 9.2};
    complexNum *cNum = ValuetoComplexNum(values, 2);
    assert(3.7 == cNum[0].realPart);
    assert(9.2 == cNum[1].realPart);
}