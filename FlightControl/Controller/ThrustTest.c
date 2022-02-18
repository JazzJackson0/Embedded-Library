#include <assert.h>
#include <stdlib.h>
#include "Thrust.h"

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
    assert( ((((float) 1200.0 * (float) 2) / (float) 1000)) * (float)9.81 
        == Calculate_UpwardForce(1200.0, 2));
        /*THIS ASSERTION FAILS EVEN THOUGH THE VALUES ARE THE EXACT FLIPPING SAME.
        NO IDEA WHY*/
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Calculate_UpwardForcePerMotorTest() {
    assert((float)(23.5440006 / 4) == Calculate_UpwardForcePerMotor(23.5440006, 4));
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void ThrustNewtons_to_ThrustGramsTest() {
    assert((float)((5.886 / 9.81) * 1000) == ThrustNewtons_to_ThrustGrams(5.886));
}