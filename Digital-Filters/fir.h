#pragma once

typedef struct fir firFilter;

//DECLARATIONS
/**
 * @brief 
 * 
 * @param tapSize 
 * @param coefficients
 * @return ** firFilter* 
 */
firFilter* fir_Init(int tapSize, double *coefficients);
/**
 * @brief 
 * 
 * @param filter 
 * @param newSample 
 * @return ** firFilter* 
 */
firFilter* FIRCalculator(firFilter *filter, double newSample);

//Structs
struct fir {

    int tapSize;
    double* sample_values;
    int currentPosition;
    double* coefficients;
    double* filteredOutputs;
};
