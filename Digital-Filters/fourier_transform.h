#pragma once
#include <complex.h>

typedef struct binData frequencyBin_data;

//DECLARATIONS
/**
 * @brief 
 * 
 * @param sample_values 
 * @param samples_per_sec 
 * @return ** frequencyBin_data* 
 */
frequencyBin_data* fourier_transform(float *sample_values, int const samples_per_sec);
/**
 * @brief 
 * 
 * @param frequency_values 
 * @param samples_per_sec 
 * @return ** IDFT_sample_data* 
 */
complexNum* IDFT(float *frequency_values, int const samples_per_sec);

//Structs
struct binData {
    //Fourier Coefficients
    float* realPart;
    float* imaginaryPart;

    float* nyquist_magnitude;
    float* amplitude;
    float* phase; //Ignoring Phase for now...
};

