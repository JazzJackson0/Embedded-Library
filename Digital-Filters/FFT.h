#pragma once
#include "../Logic/complex_nums.h"

typedef struct k K_Values;

//DECLARATIONS
/**
 * @brief 
 * 
 * @param sample_frequency 
 * @param resolution 
 * @param sample_vals 
 * @return ** K_Values* 
 */
K_Values* radix2_FFT(float sample_frequency, int resolution, double *sample_vals);

//Structs

struct k {
    complexNum *upper;
    complexNum *lower;
    int numOfValues;
};
