#pragma once
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "../Logic/ComplexNums.h"

typedef struct binData frequencyBin_data;

//DECLARATIONS
/**
 * @brief Run a fourier transform on signal sample data and output 
 *        the signal's frequency information.
 * 
 * @param sample_values Signal samples 
 * @param samples_per_sec Number of samples taken per second (Sample Frequency)
 * @return ** frequencyBin_data* Frequency domain data for a given signal.
 */
frequencyBin_data* fourier_transform(float *sample_values, int const samples_per_sec);
/**
 * @brief Run an inverse fourier transform on frequency data and output 
 *        the values needed to create a signal of the given frequencies.
 * 
 * @param frequency_values Desired Frequencies
 * @param samples_per_sec Desired FIR tap-size
 * @return ** complexNum* Values to be used as FIR Coefficients
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

