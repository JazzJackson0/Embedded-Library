#include "complex_nums.h"
#include <math.h>


complexNum* Get_SinusoidalBasis(double angle) {

    complexNum *result;

    result->realPart = cos(angle);
    result->imaginaryPart = -sin(angle);

    return result;
}

complexNum* Set_Z(double angle, double magnitude_r, int n) {

    complexNum *z = Get_SinusoidalBasis(angle);

    if (n == 0) { magnitude_r = 1; }
    
    if (n > 1) { 
        
        for (int i = 2; i <= n; i++) { magnitude_r *= magnitude_r; }

     }

    z->realPart *= (1 / magnitude_r);
    z->imaginaryPart *= (1 / magnitude_r);

    return z;
}




