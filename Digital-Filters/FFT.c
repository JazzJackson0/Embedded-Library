#include <math.h>
#include <stdlib.h>
#include "FFT.h"
#include "../Logic/complex_nums.h"

//Macros
#define PI 3.141592
#define _1HZ (2 * PI)

//Static Prototypes
static int get_closest_powerOf2(float benchmark);


K_Values* radix2_FFT(float sample_frequency, int resolution, double *sample_vals) {
    
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
    
    complexNum *upperK = malloc((k_vals->numOfValues / 2) * sizeof(complexNum));
    complexNum *lowerK = malloc((k_vals->numOfValues / 2) * sizeof(complexNum));
    complexNum *Evens = malloc(sizeof(complexNum));
    complexNum *Odds = malloc(sizeof(complexNum));
    complexNum Wn;
    complexNum twiddleXOdds;

    // Switch Indices: This simulates the Bit Reversal procedure. This way is way less of a headache.
    int j = 0; 
    double tempVal;
    
    for (int i = 1; i < tapSize - 1; i++) {
        
        int tapSizeSlice = tapSize / 2;
      
      while ( j >= tapSizeSlice ) {
          
          j = j - tapSizeSlice;
          tapSizeSlice = tapSizeSlice / 2; 
      }
        
      j = j + tapSizeSlice;
                   
      if (i < j) {
          tempVal = sample_vals[i];
          sample_vals[i] = sample_vals[j];
          sample_vals[j] = tempVal;
      }
       
    }

    complexNum *sample_vals_complexVersion = ValuetoComplexNum(sample_vals, (int) sample_frequency);
    
    
    // Calculation
    for (int m = 1; m <= M_stages; m++) {

        int n_Point_DFT = (int) pow(2, m);
        int num_ofDFTs = tapSize / n_Point_DFT;
        int dft_Width = n_Point_DFT / 2;

        for (int widthIndex = 0; widthIndex < dft_Width; widthIndex++) { // Width of each butterfly

            if (widthIndex != 0) { // if R = 0 then Wn^0 = (1 + j0)

                // Set up Twiddle Factor
                int R = num_ofDFTs * widthIndex;
                Wn.realPart = cos((_1HZ * R) / tapSize);
                Wn.imaginaryPart = -sin((_1HZ * R) / tapSize);
            }
            
            int upperLowerIndex = 0;
            // loop over each n-point DFT in the current Stage
            for (int upperK_Index = widthIndex; upperK_Index < tapSize; upperK_Index += n_Point_DFT) { 

                *Evens = sample_vals_complexVersion[upperK_Index]; 
                *Odds = sample_vals_complexVersion[upperK_Index + dft_Width]; 
                lowerK = Evens;
                upperK = Odds;

                if (widthIndex != 0) {  
                   
                    //Multiply Sum of Odds by the Twiddle Factor (Multiplying 2 Complex Nums)
                    twiddleXOdds.realPart = (Odds->realPart * Wn.realPart) - (Odds->imaginaryPart * Wn.imaginaryPart); 
                    twiddleXOdds.imaginaryPart = (Odds->realPart * Wn.imaginaryPart) + (Odds->imaginaryPart * Wn.realPart);   
                }

                else {
                    
                    twiddleXOdds.realPart = Odds->imaginaryPart;
                    twiddleXOdds.imaginaryPart = Odds->imaginaryPart;
                }

                // Calculate Lower k (Addition) Where k = 0, 2, 4, 6, ..., n
                lowerK[upperLowerIndex].realPart = Evens->realPart + twiddleXOdds.realPart;
                lowerK[upperLowerIndex].imaginaryPart = Evens->imaginaryPart + twiddleXOdds.imaginaryPart;

                // Calculate Upper k (Subtraction) Where k = 1, 3, 5, 7, ..., n
                upperK[upperLowerIndex].realPart = Evens->realPart - twiddleXOdds.realPart;
                upperK[upperLowerIndex].imaginaryPart = Evens->imaginaryPart - twiddleXOdds.imaginaryPart;
                upperLowerIndex++;
            }
        }
    }

    k_vals->lower = lowerK;
    k_vals->upper = upperK;

    //free(upperK);
    //free(lowerK);
    //free(Evens);
    //free(Odds);
    upperK = ((void*)0); //Will freeing upperK and lowerK ruin k_vals->lower & upper??????????
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