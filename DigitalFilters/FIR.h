#pragma once
#include <stdlib.h>

typedef struct fir firFilter;

//DECLARATIONS
/**
 * @brief Initialize FIR Filter
 * 
 * @param tapSize Filter Tap-Size
 * @param coefficients Filter Coefficients
 * @return ** firFilter* Initialized FIR Filter
 */
firFilter* fir_Init(int tapSize, double *coefficients);
/**
 * @brief Filter incoming sample.
 * 
 * @param filter FIR Filter to be updated
 * @param newSample New sample to be filtered
 * @return ** void 
 */
void FIRCalculator(firFilter *filter, double newSample);

/**
 * @brief Deallocate memory allocated to filter
 * 
 * @param filter 
 */
void fir_DeInit(firFilter* filter);

//Structs
struct fir {

    int tapSize;
    double* sample_values;
    int currentPosition;
    double* coefficients;
    double* filteredOutputs;
};
