#include <assert.h>
#include <stdlib.h>
#include "pid.h"

void PID_InitTest();
void PID_UpdateTest();
void Set_Tuning_ParametersTest();
void Set_Sample_TimeTest();
void Set_Output_LimitsTest();
void Set_PIDModeTest();
void Set_ControllerDirectionTest();


int main(int argc, char *argv[]) {

    PID_InitTest();
    PID_UpdateTest();
    Set_Tuning_ParametersTest();
    Set_Sample_TimeTest();
    Set_Output_LimitsTest();
    Set_PIDModeTest();
    Set_ControllerDirectionTest();
    return 0;
}


/**
 * @brief 
 * 
 * @return ** void 
 */
void PID_InitTest() {
    PIDController* pid = PID_Init();
    assert(0.0 == pid->proportional_gain);
    assert(0.0 == pid->integral_gain);
    assert(0.0 == pid->derivative_gain);
    assert(0.0 == pid->max_output);
    assert(0.0 == pid->min_output);
    assert(0.0 == pid->Integrator);
    assert(0.0 == pid->previous_error);
    assert(0.0 == pid->Differentiator);
    assert(0.0 == pid->previous_measurement);
    assert(0.0 == pid->current_measurement);
    assert(0.0 == pid->sample_time);
    assert(0.0 == pid->previous_time);
    assert(0 == pid->controller_direction);
    assert(1 == pid->inAutoMode);
    assert(0.0 == pid->output_data);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void PID_UpdateTest() {
    // Not Yet Implemented
    PIDController* pid = PID_Init();
    // Find a Library with e timekeeping function.
    PID_Update(pid, 0.0, 0.0, );
    assert(0.0 == pid->proportional_gain);
    assert(0.0 == pid->integral_gain);
    assert(0.0 == pid->derivative_gain);
    assert(0.0 == pid->max_output);
    assert(0.0 == pid->min_output);
    assert(0.0 == pid->Integrator);
    assert(0.0 == pid->previous_error);
    assert(0.0 == pid->Differentiator);
    assert(0.0 == pid->previous_measurement);
    assert(0.0 == pid->current_measurement);
    assert(0.0 == pid->sample_time);
    assert(0.0 == pid->previous_time);
    assert(0 == pid->controller_direction);
    assert(1 == pid->inAutoMode);
    assert(0.0 == pid->output_data);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Set_Tuning_ParametersTest() {
    // Not Yet Implemented
    PIDController* pid = PID_Init();
    Set_Tuning_Parameters(pid, 0.0, 0.0, 0.0);
    assert(0.0 == pid->proportional_gain);
    assert(0.0 == pid->integral_gain);
    assert(0.0 == pid->derivative_gain);

    pid->controller_direction = REVERSE;
    Set_Tuning_Parameters(pid, 0.0, 0.0, 0.0);
    assert(0.0 == pid->proportional_gain);
    assert(0.0 == pid->integral_gain);
    assert(0.0 == pid->derivative_gain);

    //Check for negatives
    Set_Tuning_Parameters(pid, 0.0, 0.0, 0.0);
    assert(0.0 == pid->proportional_gain);
    assert(0.0 == pid->integral_gain);
    assert(0.0 == pid->derivative_gain);

}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Set_Sample_TimeTest() {
    // Not Yet Implemented
    PIDController* pid = PID_Init();
    Set_Sample_Time(pid, 0.0);
    assert(0.0 == pid->integral_gain);
    assert(0.0 == pid->derivative_gain);
    assert(0.0 == pid->sample_time);
}

/**
 * @brief 
 * 
 */
void Set_Output_LimitsTest() {
    // Not Yet Implemented
    PIDController* pid = PID_Init();
    Set_Output_Limits(pid, 0.0, 0.0);
    assert(1 == pid->output_data);
    assert(0.0 == pid->min_output);
    assert(0.0 == pid->max_output);
    assert(0.0 == pid->Integrator);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Set_PIDModeTest() {
    PIDController* pid = PID_Init();
    Set_PIDMode(pid, 1);
    assert(1 == pid->inAutoMode);

    Set_PIDMode(pid, 0);
    assert(0 == pid->inAutoMode);
}

/**
 * @brief 
 * 
 * @return ** void 
 */
void Set_ControllerDirectionTest(){
    PIDController* pid = PID_Init();
    Set_ControllerDirection(pid, 1);
    assert(1 == pid->controller_direction);

    Set_ControllerDirection(pid, 0);
    assert(0 == pid->controller_direction);
}


/*
 * 			TO-DO
 * 			-----
 *  - Find a Library with e timekeeping function for PID_Update
 *
 *  - 
 *  
 *  - 
 *  */