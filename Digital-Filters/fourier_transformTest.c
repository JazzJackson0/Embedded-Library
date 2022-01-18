#include <assert.h>
#include <stdlib.h>
#include "fourier_transform.h"

void fourier_transformTest();
void IDFTTest();
float samples[] = {1.2, 5.7, 4.7};
float freq_vals[] = {1.0, 2.0, 3.0};

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
    frequencyBin_data *binData = fourier_transform(samples, 1);
    assert(0.0 == binData->amplitude);
    assert(0.0 == binData->realPart);
    assert(0.0 == binData->complexPart);
    assert(0.0 == binData->phase);
    assert(0.0 == binData->nyquist_magnitude);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void IDFTTest() {
    IDFT_sample_data *sampleData = IDFT(freq_vals, 1);
    assert(0.0 == sampleData->realPart);
    assert(0.0 == sampleData->complexPart);
}