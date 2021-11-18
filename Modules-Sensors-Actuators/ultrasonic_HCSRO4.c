#include <stdint.h>
#include "ultrasonic_HCSRO4.h"


void ultrasonicInit(void) {
	
	pinData->readData0_writeData1 = 1;
	msDelay(0); //1 ms delay to init (10us is all that's really needed though)
}


uint8_t ultrasonicRead(void) {
	
	pinData->readData0_writeData1 = 0; //Trig Low
	msDelay(0); //1ms Low Time (In place of 2us Low Time)
	pinData->readData0_writeData1 = 1; //Trig High
	msDelay(0); //1 ms pulse to start (10us is all that's really needed though)
	pinData->readData0_writeData1 = 0; //Trig Low
	
	outCompTimerStart(); //Start Measuring
	while (pinData->readData0_writeData1 == 0);//Hold while Echo is Low
	tim2ControlB->forceOutputCompareB = 1; //Stop Measuring
	uint8_t measuredTime = tim2CountVal->rw_CounterValue;
	
	return measuredTime;
}

void msDelay(int delay) {
	
	for (; delay > 0; delay--) {

		int i;
		for (i = 0; i < 3195; i++);
	}
}





