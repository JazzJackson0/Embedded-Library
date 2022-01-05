#include <math.h>
#include "fourier_transform.h"

#define PI 3.141592
#define _1HZ (2 * PI)

frequencyBin_data* fourier_transform(float sample_values[], int const samples_per_sec) {

    frequencyBin_data *frequency_bins = 0;

    for (int k = 0; k < samples_per_sec / 2; k++) { //Keeping Number of Frequency bins calculated under the Nyquist Limit
        
        for (int n = 0; n < samples_per_sec; n++) {

            //x[n] * (cos(basis) + jsin(basis)) + ... + ...
            float sinusoidal_basis = ((_1HZ * k * n) / samples_per_sec);
            frequency_bins[k].realPart += (sample_values[n] * cos(sinusoidal_basis));
            frequency_bins[k].complexPart += (sample_values[n] * sin(sinusoidal_basis));
        }
        // Get Magnitude (The Nyquist Version)
        float realPartSquared = (frequency_bins[k].realPart * 2) * (frequency_bins[k].realPart * 2);
        float complexPartSquared = (frequency_bins[k].complexPart * 2) * (frequency_bins[k].complexPart * 2);
        frequency_bins[k].nyquist_magnitude = (float) sqrt( realPartSquared + complexPartSquared );

        //Get Amplitude
        frequency_bins[k].amplitude = frequency_bins[k].nyquist_magnitude / samples_per_sec;
    }

    return frequency_bins;
}

IDFT_sample_data* IDFT(float frequency_values[], int const samples_per_sec) {

    IDFT_sample_data *sample_coefficients = 0;

    for (int k = 0; k < samples_per_sec; k++) {
        
        for (int n = 0; n < samples_per_sec; n++) {

            //x[n] * (cos(basis) + jsin(basis)) + ... + ...
            float sinusoidal_basis = ((_1HZ * k * n) / samples_per_sec);
            sample_coefficients[k].realPart += (frequency_values[n] * cos(sinusoidal_basis));
            sample_coefficients[k].complexPart += (frequency_values[n] * sin(sinusoidal_basis));
        }

        sample_coefficients[k].realPart /= samples_per_sec;
        sample_coefficients[k].complexPart /= samples_per_sec;
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