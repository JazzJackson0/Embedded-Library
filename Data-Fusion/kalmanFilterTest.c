#include <assert.h>
#include <stdlib.h>
#include "kalman_filter.h"

void kalman_filterTest();

int main(int argc, char *argv[]) {

    kalman_filterTest();
    return 0;
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void kalman_filterTest() {
    KalmanFilter *kf;

    //State Transition Matrix (F)
    double state_trans_matrix[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->state_trans_matrix->columnNum = 2;
    kf->state_trans_matrix->rowNum = 2;
    kf->state_trans_matrix->matrix = state_trans_matrix;

    // Initial State Est. Vector (x) & Updated State Estimate Vector (x+)
    double updatedStateEstimate[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->updatedStateEstimate->columnNum = 2;
    kf->updatedStateEstimate->rowNum = 2;
    kf->updatedStateEstimate->matrix = updatedStateEstimate;

    // Initial Covariance Matrix (P) & Updated Covariance Matrix (P+)
    double updatedCovariance[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->updatedCovariance->columnNum = 2;
    kf->updatedCovariance->rowNum = 2;
    kf->updatedCovariance->matrix = updatedCovariance;

    //Input Matrix (B)
    double input_matrix[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->input_matrix->columnNum = 2;
    kf->input_matrix->rowNum = 2;
    kf->input_matrix->matrix = input_matrix;

    //Input Vector (u)
    double input_vector[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->input_vector->columnNum = 2;
    kf->input_vector->rowNum = 2;
    kf->input_vector->matrix = input_vector;
    
    //Measurement Matrix (H)
    double measurement_matrix[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->measurement_matrix->columnNum = 2;
    kf->measurement_matrix->rowNum = 2;
    kf->measurement_matrix->matrix = measurement_matrix;

    // Process Model Noise Matrix (L)
    double process_model_noise_matrix[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->process_model_noise_matrix->columnNum = 2;
    kf->process_model_noise_matrix->rowNum = 2;
    kf->process_model_noise_matrix->matrix = process_model_noise_matrix;

    // Process Model Noise Vector (w)
    double process_model_noise_vector[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->process_model_noise_vector->columnNum = 2;
    kf->process_model_noise_vector->rowNum = 2;
    kf->process_model_noise_vector->matrix = process_model_noise_vector;

    // Measurement Model Noise Matrix (M)
    double measurement_model_noise_matrix[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->measurement_model_noise_matrix->columnNum = 2;
    kf->measurement_model_noise_matrix->rowNum = 2;
    kf->measurement_model_noise_matrix->matrix = measurement_model_noise_matrix;

    // Measurement Model Noise Vector (v)
    double measurement_noise_vector[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->measurement_noise_vector->columnNum = 2;
    kf->measurement_noise_vector->rowNum = 2;
    kf->measurement_noise_vector->matrix = measurement_noise_vector;

    // Innovation Matrix (y)
    double innovation[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->innovation->columnNum = 2;
    kf->innovation->rowNum = 2;
    kf->innovation->matrix = innovation;

    // Innovation Covariance Matrix (S)
    double innovationCovariance[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->innovationCovariance->columnNum = 2;
    kf->innovationCovariance->rowNum = 2;
    kf->innovationCovariance->matrix = innovationCovariance;

    // Kalman Gain Matrix (K)
    double kalmanGainMatrix[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->kalmanGainMatrix->columnNum = 2;
    kf->kalmanGainMatrix->rowNum = 2;
    kf->kalmanGainMatrix->matrix = kalmanGainMatrix;

    // Expected Covariance Matrix (P-)
    double expectedCovariance[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->expectedCovariance->columnNum = 2;
    kf->expectedCovariance->rowNum = 2;
    kf->expectedCovariance->matrix = expectedCovariance;

    // Expected State Estimate Vector (x-)
    double expectedStateEstimate[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->expectedStateEstimate->columnNum = 2;
    kf->expectedStateEstimate->rowNum = 2;
    kf->expectedStateEstimate->matrix = expectedStateEstimate;

    // Auto Correlation Matrix 1 (Q)
    double autoCorrelatoinQ[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->autoCorrelatoinQ->columnNum = 2;
    kf->autoCorrelatoinQ->rowNum = 2;
    kf->autoCorrelatoinQ->matrix = autoCorrelatoinQ;

    // Auto Correlation Matrix 2 (R)
    double autoCorrelatoinR[][] = {{0.0, 0.0}, {0.0, 0.0}};
    kf->autoCorrelatoinR->columnNum = 2;
    kf->autoCorrelatoinR->rowNum = 2;
    kf->autoCorrelatoinR->matrix = autoCorrelatoinR;

    kf = kalman_filter(kf);
    assert(0.0 == kf->updatedStateEstimate->matrix[0][0]);
    assert(0.0 == kf->updatedStateEstimate->matrix[0][1]);

    assert(0.0 == kf->updatedCovariance->matrix[0][0]);
    assert(0.0 == kf->updatedCovariance->matrix[0][1]);
    assert(0.0 == kf->updatedCovariance->matrix[1][0]);
    assert(0.0 == kf->updatedCovariance->matrix[1][1]);

}


/*
 * 			TO-DO
 * 			-----
 *  - Deeeeefinitely make an init function.
 *
 *  - 
 *  
 *  - 
 *  */