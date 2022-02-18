#ifndef ACK_MOVE_H
#define ACK_MOVE_H
// Ackerman Steering

// DECLARATIONS
/**
 * @brief Initialize the Motors for Ackerman Steering
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
 * @brief Turns Robot Right |||  Turns the orientation motor to the right
 *                          ||| Rotation is perpendicular to wheel rotation
 * 
 * @param speed Sets speed of motor (Range (In Percent): 1 - 100)
 * @return ** void 
 */
void RightTurn(float speed);

/**
 * @brief Turns Robot Left |||  Turns the orientation motor to the leftt
 *                          ||| Rotation is perpendicular to wheel rotation
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