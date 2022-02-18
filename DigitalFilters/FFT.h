#pragma once
#include "../Logic/complex_nums.h"

typedef struct k K_Values;

//DECLARATIONS
/**
 * @brief Run a fast fourier transform on signal sample data and output 
 *        the signal's frequency information.
 * 
 * @param sample_frequency Number of samples taken per second
 * @param resolution Desired Resolution: Spacing between frequency bins
 * @param sample_vals Signal samples 
 * @return ** K_Values* Frequency domain data for a given signal.
 */
K_Values* radix2_FFT(float sample_frequency, int resolution, double *sample_vals);

//Structs

struct k {
    complexNum *upper;
    complexNum *lower;
    int numOfValues;
};
