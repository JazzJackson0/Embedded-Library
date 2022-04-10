#include <assert.h>
#include <stdlib.h>
#include "FourierTransform.h"
#include "../Logic/ComplexNums.h"

void fourier_transformTest();
void IDFTTest();
float samples[] = {0.0, 0.707, 1.0, 0.707, 0.0, -0.707, -1.0, -0.707};
float freq_vals[] = {0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

int main(int argc, char *argv[]) {

    fourier_transformTest();
    IDFTTest();
    return 0;
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void fourier_transformTest() {
    frequencyBin_data *binData = fourier_transform(samples, 8);
   
    //float t4 = binData->phase[0];

    assert(0.0 == binData->realPart[0]);
    assert(0.0 == binData->imaginaryPart[0]);
    assert(0.0 == binData->amplitude[0]);
    assert(0.0 == binData->nyquist_magnitude[0]);
    //assert(0.0 == binData->phase);

    assert(binData->realPart[1] < 0.001);
    assert((float)-3.9996984 == binData->imaginaryPart[1]);
    assert((float)0.9999246 == binData->amplitude[1]);
    assert((float)7.9993968 == binData->nyquist_magnitude[1]);
    //assert(0.0 == binData->phase);

    assert(binData->realPart[2] < 0.001);
    assert(binData->imaginaryPart[2] < 0.001);
    assert(binData->amplitude[2] < 0.001);
    assert(binData->nyquist_magnitude[2] < 0.001);

    assert(binData->realPart[3] < 0.001);
    assert(binData->imaginaryPart[3] < 0.001);
    assert(binData->amplitude[3] < 0.001);
    assert(binData->nyquist_magnitude[3] < 0.001);

}

/**
 * @brief 
 * 
 * @return ** void 
 */
void IDFTTest() {
    //Not Implemented Yet
    complexNum *sampleData = IDFT(freq_vals, 8);
    
    double t1a = sampleData[0].realPart;
    double t1b = sampleData[0].imaginaryPart;

    double t2a = sampleData[1].realPart;
    double t2b = sampleData[1].imaginaryPart;

    double t3a = sampleData[2].realPart;
    double t3b = sampleData[2].imaginaryPart;

    double t4a = sampleData[3].realPart;
    double t4b = sampleData[3].imaginaryPart;

    double t5a = sampleData[4].realPart;
    double t5b = sampleData[4].imaginaryPart;

    double t6a = sampleData[5].realPart;
    double t6b = sampleData[5].imaginaryPart;

    double t7a = sampleData[6].realPart;
    double t7b = sampleData[6].imaginaryPart;

    double t8a = sampleData[7].realPart;
    double t8b = sampleData[7].imaginaryPart;

    assert(0.0 == sampleData[0].realPart);
    assert(0.0 == sampleData[0].imaginaryPart);
}