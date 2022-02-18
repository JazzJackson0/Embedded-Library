#include <assert.h>
#include <stdlib.h>
#include "MotormixAlgo.h"

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
    _4Motors *Motor = Motor_Mix(100.0, 5.0, 20.0, 30.0);
    assert(80.0 == Motor->front_Right);
    assert(10.0 == Motor->front_Left);
    assert(30.0 == Motor->back_Right);
    assert(-20.0 == Motor->back_Left);
}