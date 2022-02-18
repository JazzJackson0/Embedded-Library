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
    
    assert(2 == iir->feedBackNum);
    assert(2 == iir->feedForwardNum);
    assert(0 == iir->feedBackPosition);
    assert(0 == iir->feedForwardPosition);
    assert(12.0 == iir->feedBack_coefs[0]);
    assert(20.0 == iir->feedBack_coefs[1]);
    assert(4.0 == iir->feedForward_coefs[0]);
    assert(4.9 == iir->feedForward_coefs[1]);
    
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
    IIRCalculator(iir, 35.0);

    assert((35.0 * 4.0) + (0.0 * 4.9) + (0.0 * 12.0) + (0.0 * 20.0) 
        == iir->filteredOutputs[0]);
    assert(1 == iir->feedBackPosition);
    assert(1 == iir->feedForwardPosition);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void IIRCalculatorTest2() {
    iir = iir_Init(2, fBack_coefs, 2, fForward_coefs); 
    IIRCalculator(iir, 35.0);

    assert((35.0 * 4.0) + (0.0 * 4.9) + (0.0 * 12.0) + (0.0 * 20.0) 
        == iir->filteredOutputs[0]);
    assert(1 == iir->feedBackPosition);
    assert(1 == iir->feedForwardPosition);
    IIRCalculator(iir, 44.0);

    assert((35.0 * 4.0) + (44.0 * 4.9) + (140.0 * 12.0) + (0.0 * 20.0) 
        == iir->filteredOutputs[1]);
    assert(2 == iir->feedBackPosition);
    assert(2 == iir->feedForwardPosition);
    IIRCalculator(iir, 7.0);

    double t1 = (7.0 * 4.0) + (44.0 * 4.9) + (140.0 * 12.0) + (2035.6 * 20.0) ;
    double t2 = iir->filteredOutputs[0];
    assert((7.0 * 4.0) + (44.0 * 4.9) + (140.0 * 12.0) + (2035.6 * 20.0) 
        == iir->filteredOutputs[0]);
    assert(1 == iir->feedBackPosition);
    assert(1 == iir->feedForwardPosition);
}