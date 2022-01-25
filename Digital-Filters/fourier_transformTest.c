#include <assert.h>
#include <stdlib.h>
#include "fourier_transform.h"

void fourier_transformTest();
void IDFTTest();
float samples[] = {1.0, 2.0, 3.0};
float samples2[] = {0.0, 0.707, 1.0, 0.707, 0.0, -0.707, -1.0, -0.707};
float freq_vals[] = {4.0, 5.0, 6.0};

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
    frequencyBin_data *binData = fourier_transform(samples2, 8);
    
    float t1 = binData->realPart[0];
    float t2 = binData->complexPart[0];
    float t3 = binData->amplitude[0];
    float t4 = binData->nyquist_magnitude[0];

    
    float t5 = binData->realPart[1];
    float t6 = binData->complexPart[1];
    float t7 = binData->amplitude[1];
    float t8 = binData->nyquist_magnitude[1];

    
    float t9 = binData->realPart[2];
    float t10 = binData->complexPart[2];
    float t11 = binData->amplitude[2];
    float t12 = binData->nyquist_magnitude[2];

    
    float t13 = binData->realPart[7];
    float t14 = binData->complexPart[7];
    float t15 = binData->amplitude[7];
    float t16 = binData->nyquist_magnitude[7];
   
    //float t4 = binData->phase[0];

    assert(0.0 == binData->realPart[0]);
    assert(0.0 == binData->complexPart[0]);
    assert(0.0 == binData->amplitude[0]);
    assert(0.0 == binData->nyquist_magnitude[0]);
    //assert(0.0 == binData->phase);

}

/**
 * @brief 
 * 
 * @return ** void 
 */
void IDFTTest() {
    IDFT_sample_data *sampleData = IDFT(freq_vals, 1);
    assert(0.0 == sampleData->realPart[0]);
    assert(0.0 == sampleData->complexPart[0]);
}