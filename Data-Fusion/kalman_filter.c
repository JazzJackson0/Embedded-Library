#include "kalman_filter.h"
#include "../Logic/matrix_math.h"

//Static Prototypes
static Matrix* Set_InitialCovariance(KalmanFilter *k_filter);

static Matrix* Get_ExpectedStateEstimate(KalmanFilter *k_filter);
static Matrix* Get_ExpectedCovariace(KalmanFilter *k_filter);
static Matrix* Get_Innovation(KalmanFilter *k_filter, Matrix *sensorValues);
static Matrix* Get_InnovationCovariance(KalmanFilter *k_filter);
static Matrix* Get_KalmanGainMatrix(KalmanFilter *k_filter);
static Matrix* Get_UpdatedStateEstimate(KalmanFilter *k_filter);
static Matrix* Get_UpdatedCovariance(KalmanFilter *k_filter);


KalmanFilter* kalman_filter(KalmanFilter *k_filter) {

    //Add timestep loop
    k_filter->expectedStateEstimate = Get_ExpectedStateEstimate(k_filter);
    k_filter->expectedCovariance = Get_ExpectedCovariace(k_filter);;
    k_filter->innovation = Get_Innovation(k_filter, k_filter->sensorValues);;
    k_filter->innovationCovariance = Get_InnovationCovariance(k_filter);;
    k_filter->kalmanGainMatrix = Get_KalmanGainMatrix(k_filter);;
    k_filter->updatedStateEstimate = Get_UpdatedStateEstimate(k_filter);;
    k_filter->updatedCovariance = Get_UpdatedCovariance(k_filter);;

    return k_filter;
}

//Helper Functions----------------------------------------------------------------------
static Matrix* Get_ExpectedStateEstimate(KalmanFilter *k_filter) {

    return Add_Matrices(Multiply_Matrices(k_filter->state_trans_matrix, k_filter->oldStateEstimate), 
        Multiply_Matrices(k_filter->input_matrix, k_filter->input_vector));
}

static Matrix* Get_ExpectedCovariace(KalmanFilter *k_filter) {

    return Add_Matrices(Multiply_Matrices(Multiply_Matrices(k_filter->state_trans_matrix, 
        k_filter->oldCovariance), Get_MatrixTranspose(k_filter->state_trans_matrix)), 
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

    //Will not work until Get_MatrixInverse has been implemented
    return Multiply_Matrices(
            Multiply_Matrices(k_filter->expectedCovariance, 
                Get_MatrixTranspose(k_filter->measurement_matrix)), 
                    Get_MatrixInverse(k_filter->innovationCovariance));
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

static Matrix* Set_InitialCovariance(KalmanFilter *k_filter) {


}


/*
 * 			TO-DO
 * 			-----
 *  - Add timestep loop to kalman filter
 *
 *  - Test Code
 *  
 *  - 
 *  */