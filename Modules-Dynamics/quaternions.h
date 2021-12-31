#pragma once

typedef struct q Quaternion;

//Functions
Quaternion* MultiplyQuaternions(Quaternion *q, Quaternion *p);
Quaternion* DivideQuaternions(Quaternion *q, Quaternion *p);
Quaternion* Rotate_Vector(double *vector, Quaternion *q);
Quaternion* RotateByAngle(Quaternion *q, double angle);
Quaternion* NormalizeQuaternion(Quaternion *q);
double Get_QuaternionLength(Quaternion *q);
Quaternion* Get_QuaternionInverse(Quaternion *q);
Quaternion* Get_QuaternionConjugate(Quaternion *q);




//Structs
struct q {
    double q0;
    double q1;
    double q2;
    double q3;
};

