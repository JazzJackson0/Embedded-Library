#pragma once

typedef struct q Quaternion;

//DECLARATIONS
/**
 * @brief 
 * 
 * @param q 
 * @param p 
 * @return ** Quaternion* 
 */
Quaternion* MultiplyQuaternions(Quaternion *q, Quaternion *p);
/**
 * @brief 
 * 
 * @param q 
 * @param p 
 * @return ** Quaternion* 
 */
Quaternion* DivideQuaternions(Quaternion *q, Quaternion *p);
/**
 * @brief 
 * 
 * @param vector 
 * @param q 
 * @return ** Quaternion* 
 */
Quaternion* Rotate_Vector(double *vector, Quaternion *q);
/**
 * @brief 
 * 
 * @param q 
 * @param angle 
 * @return ** Quaternion* 
 */
Quaternion* RotateByAngle(Quaternion *q, double angle);
/**
 * @brief 
 * 
 * @param q 
 * @return ** Quaternion* 
 */
Quaternion* NormalizeQuaternion(Quaternion *q);
/**
 * @brief 
 * 
 * @param q 
 * @return ** double 
 */
double Get_QuaternionLength(Quaternion *q);
/**
 * @brief 
 * 
 * @param q 
 * @return ** Quaternion* 
 */
Quaternion* Get_QuaternionInverse(Quaternion *q);
/**
 * @brief 
 * 
 * @param q 
 * @return ** Quaternion* 
 */
Quaternion* Get_QuaternionConjugate(Quaternion *q);


//Structs
struct q {
    double q0;
    double q1;
    double q2;
    double q3;
};

