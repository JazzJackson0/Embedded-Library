#ifndef ULTRASONIC_HCSRO4_H_
#define ULTRASONIC_HCSRO4_H_

typedef struct read_funcs UltraSonicFuncs;

//DECLARATIONS
/**
 * @brief Initializes the HCSRO4 Ultrasonic Sensor
 * 
 * @param port Desired Port to connect TRIG Pin to (Actually not sure if its TRIG or ECHO)
 * @param pinNum Desired Pin to connect TRIG Pin to (Actually not sure if its TRIG or ECHO)
 * @param pinOutFunc Pin Output Function
 * @return ** void 
 */
void ultrasonicInit(char port, uint8_t pinNum, void (*pinOutFunc)(char, uint8_t, uint8_t));

/**
 * @brief Read Data from the Ultrasonic Sensor
 * 
 * @param functions Struct of the device specific gpio and timer functions.
 * @param outPort Desired Port to connect TRIG Pin to
 * @param outPinNum Desired Pin to connect TRIG Pin to
 * @param inPort Desired Port to connect ECHO Pin to 
 * @param inPinNum Desired Pin to connect ECHO Pin to 
 * @param timerNum Timer Number
 * @return ** uint8_t Ultrasonic Sensor Data (Time between Trig and Echo)
 */
uint8_t ultrasonicRead(UltraSonicFuncs *functions, char outPort, uint8_t outPinNum, char inPort, 
	uint8_t inPinNum, uint8_t timerNum);


//Structs---------------------------------------------------------

/**
 * @brief |||  Pin Out Function |||  Pin In Function |||  Stop Timer Function
 * 
 */
struct read_funcs {
	void (*pinOutFunc)(char, uint8_t, uint8_t);
	uint8_t (*getPinInFunc)(char, uint8_t);
	uint16_t (*stopTimeFunc)(uint8_t);
};

#endif
