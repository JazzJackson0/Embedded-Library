#pragma once

typedef struct fir firFilter;

//Functions
firFilter* fir_Init(int tapSize);
firFilter* FIRCalculator(firFilter *filter, double newSample);

//Structs
struct fir {

    int tapSize;
    double* sample_values;
    int currentPosition;
    double* coefficients;
    double* filteredOutputs;
};
