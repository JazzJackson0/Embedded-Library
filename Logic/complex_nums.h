#pragma once

typedef struct c complexNum;

// Function
complexNum* Get_SinusoidalBasis(double angle);
complexNum* Set_Z(double angle, double magnitude_r, int n);

// Structs
struct c {
    double realPart;
    double imaginaryPart;
};

