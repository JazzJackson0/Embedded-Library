#include <math.h>
#include <stdlib.h>
#include "FFT.h"
#include "../Logic/complex_nums.h"

//Macros
#define PI 3.141592
#define _1HZ (2 * PI)

//Static Prototypes
static int get_closest_powerOf2(float benchmark);
static int bitReverse(int num, unsigned int numOfBits);


K_Values* radix2_FFT(float sample_frequency, int resolution, double *sample_vals) {

    complexNum *sample_values = ValuetoComplexNum(sample_vals, (int) sample_frequency);
    
    float x = ((float) sample_frequency / resolution);
    float benchmark = x * sample_frequency;
    int tapSize = get_closest_powerOf2(benchmark);
    int M_stages = log10(tapSize) / log10(2);
    int upperK_Index;

    // k_vals will hold the output values
    K_Values *k_vals = malloc(sizeof(K_Values));
    k_vals->numOfValues = (int) sample_frequency;
    k_vals->lower = calloc(k_vals->numOfValues, sizeof(complexNum));
    k_vals->upper = calloc(k_vals->numOfValues, sizeof(complexNum));

    complexNum Wn;
    complexNum *upperK = malloc(sizeof(complexNum));
    complexNum *lowerK = malloc(sizeof(complexNum));
    complexNum *Evens = malloc(sizeof(complexNum));
    complexNum *Odds = malloc(sizeof(complexNum));
    complexNum twiddleXOdds;

    // Reverse Bits
    unsigned int N = (unsigned int) tapSize;
    complexNum *temp_values = malloc(sizeof(complexNum));

    for (int i = 0; i < N; i++) {

        int new_i = bitReverse(i, (unsigned int)M_stages);
        temp_values[i] = sample_values[i];

        if (i < new_i) {
            
            sample_values[i] = sample_values[new_i];
            sample_values[new_i] = temp_values[i];
        }
        
    }
    
    free(temp_values);
    temp_values = ((void*)0);
    
    
    // Calculation
    for (int m = 1; m <= M_stages; m++) {

        int n_Point_DFT = (int) pow(2, m);
        int num_ofDFTs = tapSize / n_Point_DFT;
        int dft_Width = n_Point_DFT / 2;

        for (int R = 0; R < dft_Width; R++) { // Number of operations per n-Point DFT

            if (R != 0) { // if R = 0 then Wn^0 = (1 + j0)

                //Set up Twiddle Factor
                Wn.realPart = cos((_1HZ * num_ofDFTs * R) / tapSize);
                Wn.imaginaryPart = -sin((_1HZ * num_ofDFTs * R) / tapSize);
            }
            

            for (int upperK_Index = R; upperK_Index < tapSize; upperK_Index += n_Point_DFT) { // loop over each n-point DFT in the current Stage

                *Evens = sample_values[upperK_Index];
                *Odds = Evens[dft_Width];
                lowerK = Evens;
                upperK = Odds;

                if (R != 0) {  
                   
                    //Multiply Sum of Odds by the Twiddle Factor (Multiplying 2 Complex Nums)
                    twiddleXOdds.realPart = (Odds->realPart * Wn.realPart) - (Odds->imaginaryPart * Wn.imaginaryPart); 
                    twiddleXOdds.imaginaryPart = (Odds->realPart * Wn.imaginaryPart) + (Odds->imaginaryPart * Wn.realPart);   
                }

                else {
                    
                    twiddleXOdds.realPart = Odds->imaginaryPart;
                    twiddleXOdds.imaginaryPart = Odds->imaginaryPart;
                }

                // Calculate Lower k (Addition)
                lowerK->realPart = Evens->realPart + twiddleXOdds.realPart;
                lowerK->imaginaryPart = Evens->imaginaryPart + twiddleXOdds.imaginaryPart;

                // Calculate Upper k (Subtraction)
                upperK->realPart = Evens->realPart - twiddleXOdds.realPart;
                upperK->imaginaryPart = Evens->imaginaryPart - twiddleXOdds.imaginaryPart;
            }
        }
    }

    k_vals->lower = lowerK;
    k_vals->upper = upperK;

    free(upperK);
    free(lowerK);
    free(Evens);
    free(Odds);
    upperK = ((void*)0);
    lowerK = ((void*)0);
    Evens = ((void*)0);
    Odds = ((void*)0);

    return k_vals;

}



//Helper Functions------------------------------------------------------------------------------
static int get_closest_powerOf2(float benchmark) {

    int k = 0;

    while (k < 50) { //50 is an arbitrary cap

        int powerOf2 = pow(2, k);
        if (powerOf2 > benchmark) { return powerOf2; }
        k++;
    }
    return 0;
}

static int bitReverse(int num, unsigned int numOfBits) {

    unsigned int reverseNum, temp;

    for (unsigned int i = 0; i < numOfBits; i++) {

        temp = (num & (1 << i));
        if (temp) { 

            reverseNum |= (1 << (numOfBits - 1) - i);
        }

    return reverseNum;

    }
}



/*
 * 			TO-DO
 * 			-----
 *  - Needs major debugging
 *      + lowerK and upperK should ideally be an array of output values.
 *      + They should not be overwritten with new values. Check this.
 *
 *  - UNIT TESTING!!!!
 *  
 *  - 
 *  */