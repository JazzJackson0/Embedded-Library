#pragma once
#include "../Modules-Logic/complex_nums.h"

typedef struct k K_Values;

//Functions
K_Values* radix2_FFT(int sample_frequency, int resolution, complexNum *sample_values);

//Structs

struct k {
    complexNum *upper;
    complexNum *lower;
};
