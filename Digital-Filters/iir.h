#pragma once

typedef struct iir iirFilter;

//DECLARATIONS
/**
 * @brief 
 * 
 * @param feedBackNum 
 * @param feedBack_coefs
 * @param feedForwardNum
 * @param feedForward_coefs 
 * @return ** iirFilter* 
 */
iirFilter* iir_Init(int feedBackNum, double *feedBack_coefs, 
    int feedForwardNum, double *feedForward_coefs);
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


