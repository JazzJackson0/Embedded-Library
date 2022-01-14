#pragma once

typedef struct fir firFilter;

//DECLARATIONS
/**
 * @brief 
 * 
 * @param tapSize 
 * @return ** firFilter* 
 */
firFilter* fir_Init(int tapSize);
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
