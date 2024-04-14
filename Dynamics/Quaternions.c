#include "Quaternions.h"


const double degree2Rad = 3.141592 / 180;

Quaternion* MultiplyQuaternions(Quaternion *q, Quaternion *p) {

    Quaternion *r = malloc(sizeof(Quaternion));
    r->q0 = ((q->q0 * p->q0) - (q->q1 * p->q1) - (q->q2 * p->q2) - (q->q3 * p->q3));
    r->q1 = ((q->q0 * p->q1) - (q->q1 * p->q0) - (q->q2 * p->q3) - (q->q3 * p->q2));
    r->q2 = ((q->q0 * p->q2) - (q->q1 * p->q3) - (q->q2 * p->q0) - (q->q3 * p->q1));
    r->q3 = ((q->q0 * p->q3) - (q->q1 * p->q2) - (q->q2 * p->q1) - (q->q3 * p->q0));

    return r;
}

Quaternion* DivideQuaternions(Quaternion *q, Quaternion *p) {

    Quaternion *r = MultiplyQuaternions(q, Get_QuaternionInverse(p));

    return r;
}

Quaternion* Rotate_Vector(double *vector, Quaternion *q) {

    Quaternion *P = malloc(sizeof(Quaternion));
    P->q0 = vector[0];
    P->q1 = vector[1];
    P->q2 = vector[2];
    P->q3 = vector[3];

    return MultiplyQuaternions(MultiplyQuaternions(q, P), Get_QuaternionConjugate(q));
}

Quaternion* RotateByAngle(Quaternion *q, double angle) {

    Quaternion *r = malloc(sizeof(Quaternion));
    double sinCalculation = sin( (angle / 2) * degree2Rad);

    r->q0 = cos((angle / 2) * degree2Rad);
    r->q1 = q->q1 * sinCalculation;
    r->q2 = q->q2 * sinCalculation;
    r->q3 = q->q3 * sinCalculation;

    return r;
}


Quaternion* NormalizeQuaternion(Quaternion *q) {

    Quaternion *r = malloc(sizeof(Quaternion));
    double error = 1 - Get_QuaternionLength(q);
    double denominator = sqrt((1 - error));

    r->q0 /= denominator;
    r->q1 /= denominator;
    r->q2 /= denominator;
    r->q3 /= denominator;

    return r;
}

double Get_QuaternionLength(Quaternion *q) {
    
    return sqrt( (q->q0 * q->q0) + (q->q1 * q->q1) + (q->q2 * q->q2) + (q->q3 * q->q3) );
}

Quaternion* Get_QuaternionInverse(Quaternion *q) {

    Quaternion *r = Get_QuaternionConjugate(q);
    double length = Get_QuaternionLength(q);
    r->q0 /= length;
    r->q1 /= length;
    r->q2 /= length;
    r->q3 /= length;

    return r;
}

Quaternion* Get_QuaternionConjugate(Quaternion *q) {

    Quaternion *r = malloc(sizeof(Quaternion));
    r->q0 = q->q0;
    r->q1 = q->q1 * -1.0;
    r->q2 = q->q2 * -1.0;
    r->q3 = q->q3 * -1.0;

    return r;
}

void recycle_quaternion(Quaternion *q) {
    free(q);
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

