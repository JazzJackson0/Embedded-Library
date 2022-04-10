#include <assert.h>
#include <stdlib.h>
#include "FFT.h"

void radix2_FFTTest();

int main(int argc, char *argv[]) {

    radix2_FFTTest();
    return 0;
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void radix2_FFTTest() {
    // Not Yet Implemented
    double samples[] = {0.0, 0.707, 1.0, 0.707, 0.0, -0.707, -1.0, -0.707};

    K_Values *k_vals = radix2_FFT(8.0, 8, samples);
    
    
    double t1 = k_vals->lower[0].realPart;
    double t2 = k_vals->lower[0].imaginaryPart;
    double t3 = k_vals->lower[1].realPart;
    double t4 = k_vals->lower[1].imaginaryPart;
    double t5 = k_vals->lower[2].realPart;
    double t6 = k_vals->lower[2].imaginaryPart;
    double t7 = k_vals->lower[3].realPart;
    double t8 = k_vals->lower[3].imaginaryPart;

    double t9 = k_vals->upper[0].realPart;
    double t10 = k_vals->upper[0].imaginaryPart;
    double t11 = k_vals->upper[1].realPart;
    double t12 = k_vals->upper[1].imaginaryPart;
    double t13 = k_vals->upper[2].realPart;
    double t14 = k_vals->upper[2].imaginaryPart;
    double t15 = k_vals->upper[3].realPart;
    double t16 = k_vals->upper[3].imaginaryPart;
    


    assert(0 == k_vals->numOfValues);
    assert(0.0 == k_vals->upper[0].realPart);
    assert(0.0 == k_vals->upper[0].imaginaryPart);
    assert(0.0 == k_vals->lower[0].realPart);
    assert(0.0 == k_vals->lower[0].imaginaryPart);

    assert(0.0 == k_vals->upper[1].realPart);
    assert(0.0 == k_vals->upper[1].imaginaryPart);
    assert(0.0 == k_vals->lower[1].realPart);
    assert(0.0 == k_vals->lower[1].imaginaryPart);

    assert(0.0 == k_vals->upper[2].realPart);
    assert(0.0 == k_vals->upper[2].imaginaryPart);
    assert(0.0 == k_vals->lower[2].realPart);
    assert(0.0 == k_vals->lower[2].imaginaryPart);

    assert(0.0 == k_vals->upper[3].realPart);
    assert(0.0 == k_vals->upper[3].imaginaryPart);
    assert(0.0 == k_vals->lower[3].realPart);
    assert(0.0 == k_vals->lower[3].imaginaryPart);

}