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
    
    assert(0 == k_vals->numOfValues);
    assert(0.0 == k_vals[0].upper->realPart);
    assert(0.0 == k_vals[0].upper->imaginaryPart);
    assert(0.0 == k_vals[0].lower->realPart);
    assert(0.0 == k_vals[0].lower->imaginaryPart);

    assert(0.0 == k_vals[1].upper->realPart);
    assert(0.0 == k_vals[1].upper->imaginaryPart);
    assert(0.0 == k_vals[1].lower->realPart);
    assert(0.0 == k_vals[1].lower->imaginaryPart);

    assert(0.0 == k_vals[2].upper->realPart);
    assert(0.0 == k_vals[2].upper->imaginaryPart);
    assert(0.0 == k_vals[2].lower->realPart);
    assert(0.0 == k_vals[2].lower->imaginaryPart);

    assert(0.0 == k_vals[3].upper->realPart);
    assert(0.0 == k_vals[3].upper->imaginaryPart);
    assert(0.0 == k_vals[3].lower->realPart);
    assert(0.0 == k_vals[3].lower->imaginaryPart);

    assert(0.0 == k_vals[4].upper->realPart);
    assert(0.0 == k_vals[4].upper->imaginaryPart);
    assert(0.0 == k_vals[4].lower->realPart);
    assert(0.0 == k_vals[4].lower->imaginaryPart);

    

}