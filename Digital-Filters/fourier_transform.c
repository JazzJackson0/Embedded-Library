#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "fourier_transform.h"

#define PI 3.141592
#define _1HZ (2 * PI)

frequencyBin_data* fourier_transform(float *sample_values, int const samples_per_sec) {

    frequencyBin_data *frequency_bins = malloc(sizeof(frequencyBin_data));
    frequency_bins->realPart = calloc(samples_per_sec, sizeof(float));
    frequency_bins->complexPart = calloc(samples_per_sec, sizeof(float));
    frequency_bins->amplitude = calloc(samples_per_sec, sizeof(float));
    frequency_bins->nyquist_magnitude = calloc(samples_per_sec, sizeof(float));
    frequency_bins->phase = calloc(samples_per_sec, sizeof(float));

    for (int k = 0; k < samples_per_sec / 2; k++) { //Keeping Number of Frequency bins calculated under the Nyquist Limit
        
        for (int n = 0; n < samples_per_sec; n++) {

            //x[n] * (cos(basis) + jsin(basis)) + ... + ...
            float sinusoidal_basis = ((_1HZ * k * n) / samples_per_sec);
            frequency_bins->realPart[k] += (sample_values[n] * cos(sinusoidal_basis));
            frequency_bins->complexPart[k] += (sample_values[n] * sin(sinusoidal_basis));
        }
        // Get Magnitude (The Nyquist Version)
        float realPartSquared = (frequency_bins->realPart[k] * 2) * (frequency_bins->realPart[k] * 2);
        float complexPartSquared = (frequency_bins->complexPart[k] * 2) * (frequency_bins->complexPart[k] * 2);
        frequency_bins->nyquist_magnitude[k] = (float) sqrt( realPartSquared + complexPartSquared );

        //Get Amplitude
        frequency_bins->amplitude[k] = frequency_bins->nyquist_magnitude[k] / samples_per_sec;
    }

    return frequency_bins;
}

IDFT_sample_data* IDFT(float *frequency_values, int const samples_per_sec) {

    IDFT_sample_data *sample_coefficients = malloc(sizeof(IDFT_sample_data));
    sample_coefficients->realPart = calloc(samples_per_sec, sizeof(float));
    sample_coefficients->complexPart = calloc(samples_per_sec, sizeof(float));

    for (int k = 0; k < samples_per_sec; k++) {
        
        for (int n = 0; n < samples_per_sec; n++) {

            //x[n] * (cos(basis) + jsin(basis)) + ... + ...
            float sinusoidal_basis = ((_1HZ * k * n) / samples_per_sec);
            sample_coefficients->realPart[k] += (frequency_values[n] * cos(sinusoidal_basis));
            sample_coefficients->complexPart[k] += (frequency_values[n] * sin(sinusoidal_basis));
        }

        sample_coefficients->realPart[k] /= samples_per_sec;
        sample_coefficients->complexPart[k] /= samples_per_sec;
    }
    return sample_coefficients;
}



/*
 * 			TO-DO
 * 			-----
 *  - Add Window Functions
 *
 *  - Test Code
 *  
 *  - 
 *  */