#pragma once
#include "../Logic/complex_nums.h"

typedef struct k K_Values;

//DECLARATIONS
/**
 * @brief 
 * 
 * @param sample_frequency 
 * @param resolution 
 * @param sample_values 
 * @return ** K_Values* 
 */
K_Values* radix2_FFT(int sample_frequency, int resolution, complexNum *sample_values);

//Structs

struct k {
    complexNum *upper;
    complexNum *lower;
};
