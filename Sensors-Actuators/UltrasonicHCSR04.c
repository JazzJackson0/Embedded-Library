#include <stdint.h>
#include "UltrasonicHCSR04.h"

//Static Prototypes
static void msDelay(int delay);

//------------
void ultrasonicInit(char port, uint8_t pinNum, void (*pinOutFunc)(char, uint8_t, uint8_t)) {
	
	(*pinOutFunc)(port, pinNum, 1);
	msDelay(0); //1 ms delay to init (10us is all that's really needed though)
}


uint8_t ultrasonicRead(UltraSonicFuncs *functions, char outPort, uint8_t outPinNum, char inPort, 
	uint8_t inPinNum, uint8_t timerNum) {
	
	functions->pinOutFunc(outPort, outPinNum, 0); // Trig Low
	msDelay(0); //1ms Low Time (In place of 2us Low Time)
	functions->pinOutFunc(outPort, outPinNum, 1); // Trig High
	msDelay(0); //1 ms pulse to start (10us is all that's really needed though)
	functions->pinOutFunc(outPort, outPinNum, 0); // Trig Low
	
	outCompTimerStart(); // HOW TO HANDLE TIMER START?

	while (functions->getPinInFunc(inPort, inPinNum) == 0);// Hold while Echo is Low
	return functions->stopTimeFunc(timerNum); //Currently only available for Arduino drivers
}


//Helper Functions------------------------------------------------------------------------
static void msDelay(int delay) {
	
	for (; delay > 0; delay--) {

		int i;
		for (i = 0; i < 3195; i++);
	}
}

/*
 * 			TO-DO
 * 			-----
 *  - HOW TO HANDLE TIMER START? - line 25
 *
 *  - Test Code
 *  
 *  - 
 *  */



