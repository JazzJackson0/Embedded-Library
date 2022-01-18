#include <assert.h>
#include <stdlib.h>
#include "motormix_algo.h"

void Motor_MixTest();

int main(int argc, char *argv[]) {

    Motor_MixTest();
    return 0;
}


/**
 * @brief 
 * 
 * @return ** void 
 */
void Motor_MixTest() {
    
    assert(0.0 == Motor_Mix(0.0, 0.0, 0.0, 0.0)->front_Right);
    assert(0.0 == Motor_Mix(0.0, 0.0, 0.0, 0.0)->front_Left);
    assert(0.0 == Motor_Mix(0.0, 0.0, 0.0, 0.0)->back_Right);
    assert(0.0 == Motor_Mix(0.0, 0.0, 0.0, 0.0)->back_Left);
}