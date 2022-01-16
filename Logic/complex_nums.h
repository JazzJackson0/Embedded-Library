#pragma once

typedef struct c complexNum;

//DECLARATIONS
/**
 * @brief 
 * 
 * @param angle 
 * @return ** complexNum*
 */
complexNum* Get_SinusoidalBasis(double angle);
/**
 * @brief 
 * 
 * @param angle 
 * @param magnitude_r 
 * @param n 
 * @return ** complexNum* 
 */
complexNum* Set_Z(double angle, double magnitude_r, int n);

/**
 * @brief 
 * 
 * @param realValues 
 * @param numOfValues 
 * @return ** complexNum* 
 */
complexNum* ValuetoComplexNum(double *realValues, int numOfValues);


// Structs
struct c {
    double realPart;
    double imaginaryPart;
};



