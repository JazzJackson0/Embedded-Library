#include <assert.h>
#include <stdlib.h>
#include "kalman_filter.h"

void kalman_filterTest();
void kalmanInitTest();
double initialState[3] = { 0.0,
                           0.0,
                           0.0 };

double stateTransMatrix[3][3] = { {0.0, 0.0, 0.0},
                                  {0.0, 0.0, 0.0},
                                  {0.0, 0.0, 0.0} };

double inputMatrix[3][2] = { {0.0, 0.0},
                             {0.0, 0.0},
                             {0.0, 0.0} };


int main(int argc, char *argv[]) {

    kalman_filterTest();
    kalmanInitTest();
    return 0;
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void kalmanInitTest() {
    KalmanFilter *kf = KalmanInit(initialState, 
        &stateTransMatrix, &inputMatrix, 3, 2, 3);

    assert(0.0 == kf->updatedStateEstimate->matrix[0][0]);
    assert(0.0 == kf->updatedStateEstimate->matrix[0][1]);

    // Check 
    assert(0.0 == kf->updatedCovariance->matrix[0][0]);
    assert(0.0 == kf->updatedCovariance->matrix[0][1]);
    assert(0.0 == kf->updatedCovariance->matrix[1][0]);
    assert(0.0 == kf->updatedCovariance->matrix[1][1]);

    // Check

}


/**
 * @brief 
 * 
 * @return ** void 
 */
void kalman_filterTest() {
    KalmanFilter *kf = KalmanInit(initialState, 
        &stateTransMatrix, &inputMatrix, 3, 2, 3);

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
 *  - 
 *
 *  - 
 *  
 *  - 
 *  */