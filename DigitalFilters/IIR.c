#include "IIR.h"


//Static Prototypes
static void iir_updateInput(iirFilter *filter, double newSample);


iirFilter* iir_Init(int feedBackNum, double *feedBack_coefs, 
    int feedForwardNum, double *feedForward_coefs) {

    iirFilter *filter = malloc(sizeof(iirFilter));
    filter->feedBackNum = feedBackNum;
    filter->feedForwardNum = feedForwardNum;
    filter->feedBackPosition = 0;
    filter->feedForwardPosition = 0;

    filter->sample_values = calloc(feedForwardNum, sizeof(double));
    filter->feedForward_coefs = calloc(feedForwardNum, sizeof(double));

    filter->feedBack_coefs = calloc(feedBackNum, sizeof(double));
    filter->filteredOutputs = calloc(feedBackNum, sizeof(double));
    
    filter->feedBack_coefs = feedBack_coefs;
    filter->feedForward_coefs = feedForward_coefs;

    return filter;
}

void iir_DeInit(iirFilter* iir) {

    free(iir->sample_values);
    free(iir->feedForward_coefs);
    free(iir->feedBack_coefs);
    free(iir->filteredOutputs);
    free(iir);
}


void IIRCalculator(iirFilter *filter, double newSample) {
    
    double sum = 0.0;
    iir_updateInput(filter, newSample);

    if (filter->feedBackPosition == filter->feedBackNum) { filter->feedBackPosition = 0; }

    //Sum Input Samples
    for (int i = 0; i < filter->feedForwardNum; i++) {

         sum += (filter->feedForward_coefs[i] * filter->sample_values[i]);
    }

    //Sum Previous Output Calcs
    for (int i = 0; i < filter->feedBackNum ; i++) {

        sum += (filter->feedBack_coefs[i] * filter->filteredOutputs[i]); 
    }
    
    filter->filteredOutputs[filter->feedBackPosition] = sum;
    filter->feedBackPosition++;
}

//Helper Functions------------------------------------------------------------------------
static void iir_updateInput(iirFilter *filter, double newSample) {
    
    if (filter->feedForwardPosition == filter->feedForwardNum) { filter->feedForwardPosition = 0; }

    filter->sample_values[filter->feedForwardPosition] = newSample;
    filter->feedForwardPosition++;
}


/*
 * 			TO-DO
 * 			-----
 *  - Make sure you are using the correct previous output i.e., a(0)*(y - 1), a(1)*(y - 2)
 *
 *  - 
 *  
 *  - 
 *  */