#include <assert.h>
#include <stdlib.h>
#include "thrust.h"

void Calculate_UpwardForceTest();
void Calculate_UpwardForcePerMotorTest();
void ThrustNewtons_to_ThrustGramsTest();

int main(int argc, char *argv[]) {

    Calculate_UpwardForceTest();
    Calculate_UpwardForcePerMotorTest();
    ThrustNewtons_to_ThrustGramsTest();
    return 0;
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Calculate_UpwardForceTest() {
    assert(0.0 == Calculate_UpwardForce(0.0, 2));
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Calculate_UpwardForcePerMotorTest() {
    assert(0.0 == Calculate_UpwardForcePerMotor(0.0, 4));
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void ThrustNewtons_to_ThrustGramsTest() {
    assert(0.0 == ThrustNewtons_to_ThrustGrams(0.0));
}