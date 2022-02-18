#pragma once

typedef struct iir iirFilter;

//DECLARATIONS
/**
 * @brief Initialize IIR Filter
 * 
 * @param feedBackNum Number of Feedback Coefficients
 * @param feedBack_coefs Feedback Coefficients
 * @param feedForwardNum Number of Feedforward Coefficients
 * @param feedForward_coefs Feedforward Coefficients
 * @return ** iirFilter* Initialized IIR Filter
 */
iirFilter* iir_Init(int feedBackNum, double *feedBack_coefs, 
    int feedForwardNum, double *feedForward_coefs);
/**
 * @brief Filter incoming sample.
 * 
 * @param filter IIR Filter to be updated
 * @param newSample New sample to be filtered
 * @return ** void 
 */
void IIRCalculator(iirFilter *filter, double newSample);

//Structs
struct iir {
    int feedBackNum;
    int feedForwardNum;

    int feedBackPosition;
    int feedForwardPosition;

    double* feedForward_coefs;
    double* feedBack_coefs;

    double* sample_values;
    double* filteredOutputs;
};


