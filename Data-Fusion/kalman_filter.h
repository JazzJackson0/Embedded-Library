#pragma once
#include "../Logic/matrix_math.h"

typedef struct kalman KalmanFilter;

//DECLARATIONS
/**
 * @brief 
 * 
 * @param k_filter 
 * @return ** KalmanFilter* 
 */
KalmanFilter* kalman_filter(KalmanFilter *k_filter);

//Structs
struct kalman {
    
    // Fx
    Matrix *state_trans_matrix;
    Matrix *oldStateEstimate; 

    // Bu
    Matrix *input_matrix;
    Matrix *input_vector; /* Incoming measurements */
    
    // H
    Matrix *measurement_matrix;

    // Lw
    Matrix *process_model_noise_matrix;
    Matrix *process_model_noise_vector;
    
    // Mv
    Matrix *measurement_model_noise_matrix;
    Matrix *measurement_noise_vector;

    Matrix *innovation;
    Matrix *innovationCovariance;
    Matrix *kalmanGainMatrix;

    Matrix *expectedCovariance;
    Matrix *expectedStateEstimate;

    Matrix *updatedCovariance;
    Matrix *updatedStateEstimate;
    
    Matrix *autoCorrelatoinQ;
    Matrix *autoCorrelatoinR;

    Matrix *oldCovariance;

    // This one might end up being temporary
    Matrix *sensorValues;

};