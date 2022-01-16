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
    double values[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    K_Values *k_vals = radix2_FFT(3.0, 3, values);
    
    assert(0, k_vals->numOfValues);
    assert(0.0, k_vals->upper[0]);
    assert(0.0, k_vals->lower[0]);
    assert(0.0, k_vals->upper[1]);
    assert(0.0, k_vals->lower[1]);
    assert(0.0, k_vals->upper[2]);
    assert(0.0, k_vals->lower[2]);
    assert(0.0, k_vals->upper[3]);
    assert(0.0, k_vals->lower[3]);
    assert(0.0, k_vals->upper[4]);
    assert(0.0, k_vals->lower[4]);

}