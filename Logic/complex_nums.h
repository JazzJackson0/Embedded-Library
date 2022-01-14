#pragma once

typedef struct c complexNum;

//DECLARATIONS
/**
 * @brief 
 * 
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


// Structs
struct c {
    double realPart;
    double imaginaryPart;
};

