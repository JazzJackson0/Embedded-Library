#include "iir.h"
#include <stdlib.h>

//Static Functions
static iirFilter* iir_updateInput(iirFilter *filter, double newSample);


iirFilter* iir_Init(int feedBackNum, int feedForwardNum) {

    iirFilter *filter;
    filter->feedBackNum = feedBackNum;
    filter->feedForwardNum = feedForwardNum;
    filter->feedBackPosition = 0;
    filter->feedForwardPosition = 0;

    filter->sample_values = calloc(feedForwardNum, sizeof(double));
    filter->feedForward_coefs = calloc(feedForwardNum, sizeof(double));

    filter->feedBack_coefs = calloc(feedBackNum, sizeof(double));
    filter->filteredOutputs = calloc(feedBackNum, sizeof(double));

    return filter;
}


iirFilter* IIRCalculator(iirFilter *filter, double newSample) {
    
    double sum;
    filter = iir_updateInput(filter, newSample);

    
    if (filter->feedBackPosition == filter->feedBackNum) { filter->feedBackPosition == 0; }

    //Sum Input Samples
    for (int i = 0; i < filter->feedForwardNum ; i++) {

         sum += (filter->feedForward_coefs[i] * filter->sample_values[i]);
    }

    //Sum Previous Output Calcs
    for (int i = 0; i < filter->feedBackNum ; i++) {

        sum += (filter->feedBack_coefs[i] * filter->filteredOutputs[i]); 
    }
    
    filter->filteredOutputs[filter->feedBackNum] = sum;
    filter->feedBackNum++;

    return filter;
}

//Helper Functions------------------------------------------------------------------------
static iirFilter* iir_updateInput(iirFilter *filter, double newSample) {
    
    if (filter->feedForwardPosition == filter->feedForwardNum) { filter->feedForwardPosition == 0; }

    filter->sample_values[filter->feedForwardPosition] = newSample;
    filter->feedForwardPosition++;

    return filter;
}


/*
 * 			TO-DO
 * 			-----
 *  - Make sure you are using the correct previous output i.e., a(0)*(y - 1), a(1)*(y - 2)
 *
 *  - Test Code
 *  
 *  - 
 *  */