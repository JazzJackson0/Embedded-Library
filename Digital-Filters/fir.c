#include "fir.h"
#include <stdlib.h>

//Static Prototypes
static firFilter* fir_updateInput(firFilter *filter, double newSample);


firFilter* fir_Init(int tapSize, double *coefficients) {

    firFilter *filter;
    filter->tapSize = tapSize;
    filter->currentPosition = 0;
    filter->sample_values = calloc(tapSize, sizeof(double));
    filter->filteredOutputs = calloc(tapSize, sizeof(double));
    filter->coefficients = calloc(tapSize, sizeof(double));
    filter->coefficients = coefficients;

    return filter;
}


firFilter* FIRCalculator(firFilter *filter, double newSample) {
    
    filter = fir_updateInput(filter, newSample);
    
    for (int i = 0; i < filter->tapSize ; i++) {

        filter->filteredOutputs[filter->currentPosition - 1] += 
            filter->coefficients[i] * filter->sample_values[i];
    }

    return filter;
}

//Helper Functions---------------------------------------------------------------------
static firFilter* fir_updateInput(firFilter *filter, double newSample) {
    
    if (filter->currentPosition == filter->tapSize) { filter->currentPosition == 0; }

    filter->sample_values[filter->currentPosition] = newSample;
    filter->currentPosition++;

    return filter;
}


/*
 * 			TO-DO
 * 			-----
 *  - Test Code
 *
 *  - 
 *  
 *  - 
 *  */