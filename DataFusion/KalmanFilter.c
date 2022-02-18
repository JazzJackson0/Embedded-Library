#include <stdlib.h>
#include "KalmanFilter.h"
#include "../Logic/MatrixMath.h"

//Static Prototypes
static Matrix* Get_ExpectedStateEstimate(KalmanFilter *k_filter);
static Matrix* Get_ExpectedCovariace(KalmanFilter *k_filter);
static Matrix* Get_Innovation(KalmanFilter *k_filter, Matrix *sensorValues);
static Matrix* Get_InnovationCovariance(KalmanFilter *k_filter);
static Matrix* Get_KalmanGainMatrix(KalmanFilter *k_filter);
static Matrix* Get_UpdatedStateEstimate(KalmanFilter *k_filter);
static Matrix* Get_UpdatedCovariance(KalmanFilter *k_filter);

KalmanFilter* KalmanInit(double* initialState, Matrix *FMatrix, Matrix *BMatrix, 
    Matrix *HMatrix, Matrix *PMatrix, Matrix *QMatrix, Matrix *RMatrix) {
    
    KalmanFilter *kf = malloc(sizeof(KalmanFilter));

    int stateVars_n = FMatrix->rowNum;
    int inputs_p = BMatrix->columnNum;
    int outputs_m = RMatrix->rowNum;

    //State Transition Matrix (F)
    kf->state_trans_matrix = MatrixInit(stateVars_n, stateVars_n);
    // Initial State Est. Vector (x) & Updated State Estimate Vector (x+) 
    kf->updatedStateEstimate = MatrixInit(stateVars_n, 1);
    // Initial Covariance Matrix (P) & Updated Covariance Matrix (P+) 
    kf->updatedCovariance = MatrixInit(stateVars_n, stateVars_n);
    //Input Matrix (B)
    kf->input_matrix = MatrixInit(stateVars_n, inputs_p);
    //Input Vector (u)
    kf->input_vector = MatrixInit(inputs_p, 1);
    //Measurement Matrix (H)
    kf->measurement_matrix = MatrixInit(outputs_m, stateVars_n);
    // Process Model Noise Matrix (L)
    kf->process_model_noise_matrix = MatrixInit(inputs_p, stateVars_n);
    // Process Model Noise Vector (w)
    kf->process_model_noise_vector = MatrixInit(stateVars_n, 1);
    // Measurement Model Noise Matrix (M)
    kf->measurement_model_noise_matrix = MatrixInit(stateVars_n, outputs_m);
    // Measurement Model Noise Vector (v)
    kf->measurement_noise_vector = MatrixInit(outputs_m, 1);
    // Innovation Matrix (y)
    kf->innovation = MatrixInit(stateVars_n, 1);
    // Innovation Covariance Matrix (S)
    kf->innovationCovariance = MatrixInit(outputs_m, outputs_m);
    // Kalman Gain Matrix (K)
    kf->kalmanGainMatrix =  MatrixInit(stateVars_n, outputs_m);
    // Expected Covariance Matrix (P-)
    kf->expectedCovariance = MatrixInit(stateVars_n, stateVars_n);
    // Expected State Estimate Vector (x-)
    kf->expectedStateEstimate = MatrixInit(stateVars_n, 1);
    // Process Model Noise Auto Correlation Matrix (Q)
    kf->autoCorrelatoinQ = MatrixInit(stateVars_n, stateVars_n);
    // Measurement Model Noise Auto Correlation Matrix (R)
    kf->autoCorrelatoinR = MatrixInit(outputs_m, outputs_m);

    PopulateMatrix(kf->state_trans_matrix, FMatrix->matrix);
    PopulateMatrix(kf->input_matrix, BMatrix->matrix);
    PopulateMatrix(kf->measurement_matrix, HMatrix->matrix);
    PopulateMatrix(kf->updatedCovariance, PMatrix->matrix);
    PopulateMatrix(kf->autoCorrelatoinQ, QMatrix->matrix);
    PopulateMatrix(kf->autoCorrelatoinR, RMatrix->matrix);
    
    //Add values to Initial State vector, State Trans & Input Matrices
    for (int i = 0; i < stateVars_n; i++) {

        kf->updatedStateEstimate->matrix[i][0] = initialState[i];
    }

    return kf;
}

void kalman_filter(KalmanFilter *k_filter) {

    //Add timestep loop
    k_filter->expectedStateEstimate = Get_ExpectedStateEstimate(k_filter);
    k_filter->expectedCovariance = Get_ExpectedCovariace(k_filter);;
    k_filter->innovation = Get_Innovation(k_filter, k_filter->sensorValues);;
    k_filter->innovationCovariance = Get_InnovationCovariance(k_filter);;
    k_filter->kalmanGainMatrix = Get_KalmanGainMatrix(k_filter);;
    k_filter->updatedStateEstimate = Get_UpdatedStateEstimate(k_filter);;
    k_filter->updatedCovariance = Get_UpdatedCovariance(k_filter);;
}

//Helper Functions----------------------------------------------------------------------
static Matrix* Get_ExpectedStateEstimate(KalmanFilter *k_filter) {

    return Add_Matrices(Multiply_Matrices(k_filter->state_trans_matrix, k_filter->updatedStateEstimate), 
        Multiply_Matrices(k_filter->input_matrix, k_filter->input_vector));
}

static Matrix* Get_ExpectedCovariace(KalmanFilter *k_filter) {

    return Add_Matrices(Multiply_Matrices(Multiply_Matrices(k_filter->state_trans_matrix, 
        k_filter->updatedCovariance), Get_MatrixTranspose(k_filter->state_trans_matrix)), 
            k_filter->autoCorrelatoinQ);
}

static Matrix* Get_Innovation(KalmanFilter *k_filter, Matrix *sensorValues) {
    
    return Subtract_Matrices(sensorValues, 
        Multiply_Matrices(k_filter->measurement_matrix, k_filter->expectedStateEstimate)); 
}

static Matrix* Get_InnovationCovariance(KalmanFilter *k_filter) {

    return Add_Matrices( 
        Multiply_Matrices(
            Multiply_Matrices( k_filter->measurement_matrix, k_filter->expectedCovariance), 
                Get_MatrixTranspose(k_filter->measurement_matrix)), k_filter->autoCorrelatoinR);
}

static Matrix* Get_KalmanGainMatrix(KalmanFilter *k_filter) {

    Matrix *inverse = MatrixInit(k_filter->expectedCovariance->rowNum, 
       k_filter->expectedCovariance->columnNum);

    Matrix *result = Multiply_Matrices(
        Multiply_Matrices(k_filter->expectedCovariance, 
            Get_MatrixTranspose(k_filter->measurement_matrix)), 
                Get_MatrixInverse(k_filter->innovationCovariance, inverse));

    free(inverse);
    return result;
}

static Matrix* Get_UpdatedCovariance(KalmanFilter *k_filter) {

    return Subtract_Matrices(
        k_filter->expectedCovariance, Multiply_Matrices(
            Multiply_Matrices(k_filter->kalmanGainMatrix, k_filter->measurement_matrix),
                k_filter->expectedCovariance));
}

static Matrix* Get_UpdatedStateEstimate(KalmanFilter *k_filter) {

    return Add_Matrices(k_filter->expectedStateEstimate, 
        Multiply_Matrices(k_filter->kalmanGainMatrix, k_filter->innovation));
}



/*
 * 			TO-DO
 * 			-----
 *  - 
 *
 *  - Add timestep loop to kalman filter 
 *  
 *  - Test Code
 *  */