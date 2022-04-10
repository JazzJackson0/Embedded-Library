#ifndef DIFF_MOVE_H
#define DIFF_MOVE_H
#include "../../Sensors-Actuators/Motor.h"

// DECLARATIONS
/**
 * @brief Initialize the Motors for Differential Steering
 * 
 * @return ** void 
 */
void DiffDriveInit();

/**
 * @brief Moves both wheels in a forward direction
 * 
 * @param speed Sets speed of motor (Range (In Percent): 1 - 100)
 * @return ** void 
 */
void Forward(float speed);

/**
 * @brief Moves both wheels in a backward direction
 * 
 * @param speed Sets speed of motor (Range (In Percent): 1 - 100)
 * @return ** void 
 */
void Reverse(float speed);

/**
 * @brief Turns Robot Right |||  Right wheel moves in backward direction
 *                          |||  Left wheel moves in forward direction
 * 
 * @param speed Sets speed of motor (Range (In Percent): 1 - 100)
 * @return ** void 
 */
void RightTurn(float speed);

/**
 * @brief Turns Robot Left |||  Left wheel moves in backward direction
 *                          |||  Right wheel moves in forward direction
 * 
 * @param speed Sets speed of motor (Range (In Percent): 1 - 100)
 * @return ** void 
 */
void LeftTurn(float speed);

/**
 * @brief Stops all wheel rotation
 * 
 * @return ** void 
 */
void StopBot();





#endif