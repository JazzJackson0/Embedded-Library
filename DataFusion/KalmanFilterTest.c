#include <assert.h>
#include <stdlib.h>
#include "KalmanFilter.h"
#include "../Logic/MatrixMath.h"

void kalman_filterTest();
void kalmanInitTest();
double initialState[3] = { 0.0,
                           0.0,
                           0.0 };

double stateTransData[3][3] = { {0.0, 0.0, 0.0},
                                {0.0, 0.0, 0.0},
                                {0.0, 0.0, 0.0} };

double inputMData[3][2] = { {0.0, 0.0},
                           {0.0, 0.0},
                           {0.0, 0.0} };

double measurementMData[3][3] = { {0.0, 0.0, 0.0},
                                  {0.0, 0.0, 0.0},
                                  {0.0, 0.0, 0.0} };

double PData[3][3] = { {0.0, 0.0, 0.0},
                        {0.0, 0.0, 0.0},
                        {0.0, 0.0, 0.0} };

double QData[3][3] = { {0.0, 0.0, 0.0},
                        {0.0, 0.0, 0.0},
                        {0.0, 0.0, 0.0} };

double RData[3][3] = { {0.0, 0.0, 0.0},
                        {0.0, 0.0, 0.0},
                        {0.0, 0.0, 0.0} };


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

    Matrix *fmatrix = MatrixInit(3, 3);
    PopulateMatrix(fmatrix, (double *)&stateTransData);

    Matrix *bmatrix = MatrixInit(3, 2);
    PopulateMatrix(bmatrix, (double *)&inputMData);

    Matrix *hmatrix = MatrixInit(3, 2);
    PopulateMatrix(hmatrix, (double *)&measurementMData);

    Matrix *pmatrix = MatrixInit(3, 3);
    PopulateMatrix(pmatrix, (double *)&PData);

    Matrix *qmatrix = MatrixInit(3, 3);
    PopulateMatrix(qmatrix, (double *)&QData);

    Matrix *rmatrix = MatrixInit(3, 3);
    PopulateMatrix(rmatrix, (double *)&RData);

    KalmanFilter *kf = KalmanInit(initialState, 
        fmatrix, bmatrix, hmatrix, pmatrix, qmatrix, rmatrix);

    assert(0.0 == kf->updatedStateEstimate->matrix[0][0]);
    assert(0.0 == kf->updatedStateEstimate->matrix[0][1]);

    // Check 
    assert(0.0 == kf->updatedCovariance->matrix[0][0]);
    assert(0.0 == kf->updatedCovariance->matrix[0][1]);
    assert(0.0 == kf->updatedCovariance->matrix[1][0]);
    assert(0.0 == kf->updatedCovariance->matrix[1][1]);

    // Check

    free(fmatrix);
    free(bmatrix);
    free(pmatrix);
    free(qmatrix);
    free(rmatrix);

}


/**
 * @brief 
 * 
 * @return ** void 
 */
void kalman_filterTest() {
    Matrix *fmatrix = MatrixInit(3, 3);
    PopulateMatrix(fmatrix, (double *)&stateTransData);

    Matrix *bmatrix = MatrixInit(3, 3);
    PopulateMatrix(bmatrix, (double *)&inputMData);

    Matrix *hmatrix = MatrixInit(3, 2);
    PopulateMatrix(hmatrix, (double *)&measurementMData);

    Matrix *pmatrix = MatrixInit(3, 3);
    PopulateMatrix(pmatrix, (double *)&PData);

    Matrix *qmatrix = MatrixInit(3, 3);
    PopulateMatrix(qmatrix, (double *)&QData);

    Matrix *rmatrix = MatrixInit(3, 3);
    PopulateMatrix(rmatrix, (double *)&RData);

    KalmanFilter *kf = KalmanInit(initialState, 
        fmatrix, bmatrix, hmatrix, pmatrix, qmatrix, rmatrix);

    kalman_filter(kf);
    assert(0.0 == kf->updatedStateEstimate->matrix[0][0]);
    assert(0.0 == kf->updatedStateEstimate->matrix[0][1]);

    assert(0.0 == kf->updatedCovariance->matrix[0][0]);
    assert(0.0 == kf->updatedCovariance->matrix[0][1]);
    assert(0.0 == kf->updatedCovariance->matrix[1][0]);
    assert(0.0 == kf->updatedCovariance->matrix[1][1]);


    free(fmatrix);
    free(bmatrix);
    free(pmatrix);
    free(qmatrix);
    free(rmatrix);
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