#pragma once

typedef struct iir iirFilter;

//DECLARATIONS
/**
 * @brief 
 * 
 * @param feedBackNum 
 * @param feedForwardNum 
 * @return ** iirFilter* 
 */
iirFilter* iir_Init(int feedBackNum, int feedForwardNum);
/**
 * @brief 
 * 
 * @param filter 
 * @param newSample 
 * @return ** iirFilter* 
 */
iirFilter* IIRCalculator(iirFilter *filter, double newSample);

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


