#ifndef ULTRASONIC_HCSRO4_H_
#define ULTRASONIC_HCSRO4_H_

typedef struct read_funcs UltraSonicFuncs;

//DECLARATIONS
/**
 * @brief 
 * 
 * @param port 
 * @param pinNum 
 * @param pinOutFunc 
 * @return ** void 
 */
void ultrasonicInit(char port, uint8_t pinNum, void (*pinOutFunc)(char, uint8_t, uint8_t));

/**
 * @brief 
 * 
 * @param functions 
 * @param outPort 
 * @param outPinNum 
 * @param inPort 
 * @param inPinNum 
 * @param timerNum 
 * @return ** uint8_t 
 */
uint8_t ultrasonicRead(UltraSonicFuncs *functions, char outPort, uint8_t outPinNum, char inPort, 
	uint8_t inPinNum, uint8_t timerNum);


//Structs---------------------------------------------------------
struct read_funcs {
	void (*pinOutFunc)(char, uint8_t, uint8_t);
	uint8_t (*getPinInFunc)(char, uint8_t);
	uint16_t (*stopTimeFunc)(uint8_t);
};

#endif
