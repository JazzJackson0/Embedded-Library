#pragma once
#include <math.h>
#include <stdlib.h>

typedef struct q Quaternion;

//DECLARATIONS
/**
 * @brief Multiply two quaternions
 * 
 * @param q Left quaternion
 * @param p Right quaternion
 * @return ** Quaternion* Quaternion Product
 */
Quaternion* MultiplyQuaternions(Quaternion *q, Quaternion *p);
/**
 * @brief Divide two quaternions
 * 
 * @param q Left quaternion
 * @param p Right quaternion
 * @return ** Quaternion* Quaternion Quotient
 */
Quaternion* DivideQuaternions(Quaternion *q, Quaternion *p);
/**
 * @brief Rotate a given vector around a given quaternion
 * 
 * @param vector Vector t rotate
 * @param q Quaternion to rotate vector around.
 * @return ** Quaternion* Resulting quaternion
 */
Quaternion* Rotate_Vector(double *vector, Quaternion *q);
/**
 * @brief Rotate quaternion by given angle
 * 
 * @param q Quaternion to rotate
 * @param angle Angle of rotation
 * @return ** Quaternion* Rotated quaternion.
 */
Quaternion* RotateByAngle(Quaternion *q, double angle);
/**
 * @brief Normalize quaternion
 * 
 * @param q Quaternion to normalize
 * @return ** Quaternion* Normalized quaternion
 */
Quaternion* NormalizeQuaternion(Quaternion *q);
/**
 * @brief Get length of quaternion
 * 
 * @param q Quaternion to get length of
 * @return ** double Quaternion length
 */
double Get_QuaternionLength(Quaternion *q);
/**
 * @brief Get inverse of quaternion
 * 
 * @param q Quaternion to invert
 * @return ** Quaternion* Quaternion inverse
 */
Quaternion* Get_QuaternionInverse(Quaternion *q);
/**
 * @brief Get conjugate of quaternion
 * 
 * @param q Quaternion to congugate
 * @return ** Quaternion* Quaternion conjugate
 */
Quaternion* Get_QuaternionConjugate(Quaternion *q);

/**
 * @brief Deallocate memory allocated to Quaternion object
 * 
 * @param q 
 */
void recycle_quaternion(Quaternion *q);


//Structs
struct q {
    double q0;
    double q1;
    double q2;
    double q3;
};

