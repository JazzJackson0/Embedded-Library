#include <assert.h>
#include <stdlib.h>
#include "FIR.h"

void fir_InitTest();
void FIRCalculatorTest();
void FIRCalculatorTest2();
firFilter *fir;
double coefs[] = {5.0, 6.0};

int main(int argc, char *argv[]) {

    fir_InitTest();
    FIRCalculatorTest();
    FIRCalculatorTest2();
    return 0;
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void fir_InitTest() {
    fir = fir_Init(2, coefs);
    assert(2 == fir->tapSize);
    assert(0 == fir->currentPosition);
    assert(5.0 == fir->coefficients[0]);
    assert(6.0 == fir->coefficients[1]);
    /* Pointers
    assert(2, fir->sample_values);
    assert(2, fir->filteredOutputs);*/

    fir_DeInit(fir);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void FIRCalculatorTest() {
    fir = fir_Init(2, coefs);
    FIRCalculator(fir, 49.0);

    assert((49.0 * 5.0) + (0.0 * 6.0) == fir->filteredOutputs[0]);
    assert(1 == fir->currentPosition);

    fir_DeInit(fir);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void FIRCalculatorTest2() {
    fir = fir_Init(2, coefs);
    FIRCalculator(fir, 49.0);

    assert((49.0 * 5.0) + (0.0 * 6.0) == fir->filteredOutputs[0]);
    assert(1 == fir->currentPosition);
    FIRCalculator(fir, 37.0);

    assert((49.0 * 5.0) + (37.0 * 6.0) == fir->filteredOutputs[1]);
    assert(2 == fir->currentPosition);
    FIRCalculator(fir, 23.0);

    assert((23.0 * 5.0) + (37.0 * 6.0) == fir->filteredOutputs[0]);
    assert(1 == fir->currentPosition);

    fir_DeInit(fir);
}