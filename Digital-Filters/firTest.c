#include <assert.h>
#include <stdlib.h>
#include "fir.h"

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
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void FIRCalculatorTest() {
    fir = fir_Init(2, coefs);
    firFilter *firNew;
    firNew = FIRCalculator(fir, 49.0);

    assert(0.0 == firNew->filteredOutputs[0]);
    assert(1 == firNew->currentPosition);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void FIRCalculatorTest2() {
    fir = fir_Init(2, coefs);
    firFilter *firNew;
    firNew = FIRCalculator(fir, 49.0);

    assert(0.0 == firNew->filteredOutputs[0]);
    assert(1 == firNew->currentPosition);
    firNew = FIRCalculator(firNew, 37.0);

    assert(0.0 == firNew->filteredOutputs[1]);
    assert(2 == firNew->currentPosition);
    firNew = FIRCalculator(firNew, 23.0);

    assert(0.0 == firNew->filteredOutputs[0]);
    assert(0 == firNew->currentPosition);
}