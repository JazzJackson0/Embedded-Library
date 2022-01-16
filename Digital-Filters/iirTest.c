#include <assert.h>
#include <stdlib.h>
#include "iir.h"

void iir_InitTest();
void IIRCalculatorTest();
void IIRCalculatorTest2();
iirFilter *iir;
double fBack_coefs[] = {12.0, 20.0};
double fForward_coefs[] = {4.0, 4.9};

int main(int argc, char *argv[]) {

    iir_InitTest();
    IIRCalculatorTest();
    IIRCalculatorTest2();
    return 0;
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void iir_InitTest() {
    iir = iir_Init(2, fBack_coefs, 2, fForward_coefs);
    
    assert(2, iir->feedBackNum);
    assert(2, iir->feedForwardNum);
    assert(0, iir->feedBackPosition);
    assert(0, iir->feedForwardPosition);
    assert(12.0, iir->feedBack_coefs[0]);
    assert(20.0, iir->feedBack_coefs[1]);
    assert(4.0, iir->feedForward_coefs[0]);
    assert(4.9, iir->feedForward_coefs[1]);
    
    /* Pointers
    assert(0.0, iir->sample_values);
    assert(0.0, iir->filteredOutputs);*/
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void IIRCalculatorTest() {
    iir = iir_Init(2, fBack_coefs, 2, fForward_coefs); 
    iirFilter *iirNew;
    iirNew = IIRCalculator(iir, 35.0);

    assert(0.0, iirNew->filteredOutputs[0]);
    assert(1, iirNew->feedBackPosition);
    assert(1, iirNew->feedForwardPosition);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void IIRCalculatorTest2() {
    iir = iir_Init(2, fBack_coefs, 2, fForward_coefs); 
    iirFilter *iirNew;
    iirNew = IIRCalculator(iir, 35.0);

    assert(0.0, iirNew->filteredOutputs[0]);
    assert(1, iirNew->feedBackPosition);
    assert(1, iirNew->feedForwardPosition);
    iirNew = IIRCalculator(iirNew, 44.0);

    assert(0.0, iirNew->filteredOutputs[1]);
    assert(2, iirNew->feedBackPosition);
    assert(2, iirNew->feedForwardPosition);
    iirNew = IIRCalculator(iirNew, 7.0);

    assert(0.0, iirNew->filteredOutputs[0]);
    assert(0, iirNew->feedBackPosition);
    assert(0, iirNew->feedForwardPosition);
}