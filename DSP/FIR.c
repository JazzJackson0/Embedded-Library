#include "FIR.h"

//Static Prototypes
static void fir_updateInput(firFilter *filter, double newSample);


firFilter fir_Init(int tapSize, double *coefficients) {

    firFilter filter = {
        tapSize,
        calloc(tapSize, sizeof(double)),
        0,
        coefficients,
        calloc(tapSize, sizeof(double))
    };

    return filter;
}


void FIRCalculator(firFilter *filter, double newSample) {
    
    double sum = 0.0;
    fir_updateInput(filter, newSample);
    
    for (int i = 0; i < filter->tapSize ; i++) {

        sum += filter->coefficients[i] * filter->sample_values[i];
    }

    filter->filteredOutputs[filter->currentPosition - 1] = sum;
}

void fir_DeInit(firFilter* filter) {
    free(filter->sample_values);
    free(filter->filteredOutputs);
    free(filter->coefficients);
}

//Helper Functions---------------------------------------------------------------------
static void fir_updateInput(firFilter *filter, double newSample) {
    
    if (filter->currentPosition == filter->tapSize) { filter->currentPosition = 0; }

    filter->sample_values[filter->currentPosition] = newSample;
    filter->currentPosition++;
}


/*
 * 			TO-DO
 * 			-----
 *  - 
 *
 *  - 
 *  
 *  - 
 *  */