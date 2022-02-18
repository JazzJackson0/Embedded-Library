#include "fir.h"
#include <stdlib.h>

//Static Prototypes
static void fir_updateInput(firFilter *filter, double newSample);


firFilter* fir_Init(int tapSize, double *coefficients) {

    firFilter *filter = malloc(sizeof(firFilter));
    filter->tapSize = tapSize;
    filter->currentPosition = 0;
    filter->sample_values = calloc(tapSize, sizeof(double));
    filter->filteredOutputs = calloc(tapSize, sizeof(double));
    filter->coefficients = calloc(tapSize, sizeof(double));
    filter->coefficients = coefficients;

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