#include <stdint.h>
#include <stddef.h>
#include "digital_io_MSP430FR.h"

//Static Prototypes------------------------------------------------------
static PORTx_FUNCTION_SELECT0* Get_Function0Register(char port);
static PORTx_FUNCTION_SELECT1* Get_Function1Register(char port);
static PORTx_FUNCTION_SELECT_COMPLEMENT* Get_FunctionCompRegister(char port);
static PORTx_DIRECTION* Get_DirectionRegister(char port);
static PORTx_INPUT* Get_InputRegister(char port);
static PORTx_OUTPUT* Get_OutputRegister(char port);
static PORTx_PULLUP_PULLDOWN* Get_PUpPDownRegister(char port);

//Global Variables-------------------------------------------------------

//Watchdog Timer (Turn Off)
WATCHDOG_CONTROL *const watchdog = ADDR_WATCHDOG_CONTROL;

//Port 1
PORTx_DIRECTION *const PINDirection_1 = ADDR_PORT1_DIRECTION;
PORTx_INPUT *const PINInput_1 = ADDR_PORT1_INPUT;
PORTx_OUTPUT *const PINOutput_1 = ADDR_PORT1_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_1 = ADDR_PORT1_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_1 = ADDR_PORT1_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_1 = ADDR_PORT1_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_1 = ADDR_PORT1_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_1 = ADDR_PORT1_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_1 = ADDR_PORT1_INTERRUPT_ENABLE;
//Port 2
PORTx_DIRECTION *const PINDirection_2 = ADDR_PORT2_DIRECTION;
PORTx_INPUT *const PINInput_2 = ADDR_PORT2_INPUT;
PORTx_OUTPUT *const PINOutput_2 = ADDR_PORT2_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_2 = ADDR_PORT2_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_2 = ADDR_PORT2_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_2 = ADDR_PORT2_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_2 = ADDR_PORT2_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_2 = ADDR_PORT2_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_2 = ADDR_PORT2_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_2 = ADDR_PORT2_INTERRUPT_FLAG;
//Port 3
PORTx_DIRECTION *const PINDirection_3 = ADDR_PORT3_DIRECTION;
PORTx_INPUT *const PINInput_3 = ADDR_PORT3_INPUT;
PORTx_OUTPUT *const PINOutput_3 = ADDR_PORT3_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_3 = ADDR_PORT3_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_3 = ADDR_PORT3_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_3 = ADDR_PORT3_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_3 = ADDR_PORT3_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_3 = ADDR_PORT3_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_3 = ADDR_PORT3_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_3 = ADDR_PORT3_INTERRUPT_FLAG;
//Port 4
PORTx_DIRECTION *const PINDirection_4 = ADDR_PORT4_DIRECTION;
PORTx_INPUT *const PINInput_4 = ADDR_PORT4_INPUT;
PORTx_OUTPUT *const PINOutput_4 = ADDR_PORT4_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_4 = ADDR_PORT4_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_4 = ADDR_PORT4_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_4 = ADDR_PORT4_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_4 = ADDR_PORT4_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_4 = ADDR_PORT4_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_4 = ADDR_PORT4_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_4 = ADDR_PORT4_INTERRUPT_FLAG;
/*
//Port 5
PORTx_DIRECTION *const PINDirection_5 = ADDR_PORT1_DIRECTION;
PORTx_INPUT *const PINInput_5 = ADDR_PORT1_INPUT;
PORTx_OUTPUT *const PINOutput_5 = ADDR_PORT1_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_5 = ADDR_PORT1_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_5 = ADDR_PORT1_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_5 = ADDR_PORT1_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_5 = ADDR_PORT1_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_5 = ADDR_PORT1_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_5 = ADDR_PORT1_INTERRUPT_ENABLE;
//Port 6
PORTx_DIRECTION *const PINDirection_6 = ADDR_PORT2_DIRECTION;
PORTx_INPUT *const PINInput_6 = ADDR_PORT2_INPUT;
PORTx_OUTPUT *const PINOutput_6 = ADDR_PORT2_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_6 = ADDR_PORT2_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_6 = ADDR_PORT2_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_6 = ADDR_PORT2_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_6 = ADDR_PORT2_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_6 = ADDR_PORT2_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_6 = ADDR_PORT2_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_6 = ADDR_PORT2_INTERRUPT_FLAG;
//Port 7
PORTx_DIRECTION *const PINDirection_7 = ADDR_PORT3_DIRECTION;
PORTx_INPUT *const PINInput_7 = ADDR_PORT3_INPUT;
PORTx_OUTPUT *const PINOutput_7 = ADDR_PORT3_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_7 = ADDR_PORT3_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_7 = ADDR_PORT3_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_7 = ADDR_PORT3_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_7 = ADDR_PORT3_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_7 = ADDR_PORT3_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_7 = ADDR_PORT3_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_7 = ADDR_PORT3_INTERRUPT_FLAG;
//Port 8
PORTx_DIRECTION *const PINDirection_8 = ADDR_PORT4_DIRECTION;
PORTx_INPUT *const PINInput_8 = ADDR_PORT4_INPUT;
PORTx_OUTPUT *const PINOutput_8 = ADDR_PORT4_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_8 = ADDR_PORT4_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_8 = ADDR_PORT4_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_8 = ADDR_PORT4_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_8 = ADDR_PORT4_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_8 = ADDR_PORT4_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_8 = ADDR_PORT4_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_8 = ADDR_PORT4_INTERRUPT_FLAG;
//Port 9
PORTx_DIRECTION *const PINDirection_9 = ADDR_PORT1_DIRECTION;
PORTx_INPUT *const PINInput_9 = ADDR_PORT9_INPUT;
PORTx_OUTPUT *const PINOutput_9 = ADDR_PORT1_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_9 = ADDR_PORT1_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_9 = ADDR_PORT1_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_9 = ADDR_PORT1_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_9 = ADDR_PORT1_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_9 = ADDR_PORT1_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_9 = ADDR_PORT1_INTERRUPT_ENABLE;
//Port 10
PORTx_DIRECTION *const PINDirection_10 = ADDR_PORT10_DIRECTION;
PORTx_INPUT *const PINInput_10 = ADDR_PORT10_INPUT;
PORTx_OUTPUT *const PINOutput_10 = ADDR_PORT10_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_10 = ADDR_PORT10_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_10 = ADDR_PORT10_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_10 = ADDR_PORT10_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_10 = ADDR_PORT10_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_10 = ADDR_PORT10_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_10 = ADDR_PORT10_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_10 = ADDR_PORT10_INTERRUPT_FLAG;
//Port 11
PORTx_DIRECTION *const PINDirection_11 = ADDR_PORT11_DIRECTION;
PORTx_INPUT *const PINInput_11 = ADDR_PORT11_INPUT;
PORTx_OUTPUT *const PINOutput_11 = ADDR_PORT11_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_11 = ADDR_PORT11_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_11 = ADDR_PORT11_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_11 = ADDR_PORT11_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_11 = ADDR_PORT11_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_11 = ADDR_PORT11_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_11 = ADDR_PORT11_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_11 = ADDR_PORT11_INTERRUPT_FLAG;
//Port A
PORTx_DIRECTION *const PINDirection_A = ADDR_PORTA_DIRECTION;
PORTx_INPUT *const PINInput_A = ADDR_PORTA_INPUT;
PORTx_OUTPUT *const PINOutput_A = ADDR_PORTA_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_A = ADDR_PORTA_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_A = ADDR_PORTA_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_A = ADDR_PORTA_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_A = ADDR_PORTA_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_A = ADDR_PORTA_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_A = ADDR_PORTA_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_A = ADDR_PORTA_INTERRUPT_FLAG;
//Port B
PORTx_DIRECTION *const PINDirection_B = ADDR_PORTB_DIRECTION;
PORTx_INPUT *const PINInput_B = ADDR_PORTB_INPUT;
PORTx_OUTPUT *const PINOutput_B = ADDR_PORTB_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_B = ADDR_PORTB_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_B = ADDR_PORTB_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_B = ADDR_PORTB_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_B = ADDR_PORTB_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_B = ADDR_PORTB_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_B = ADDR_PORTB_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_B = ADDR_PORTB_INTERRUPT_FLAG;
//Port C
PORTx_DIRECTION *const PINDirection_C = ADDR_PORTC_DIRECTION;
PORTx_INPUT *const PINInput_C = ADDR_PORTC_INPUT;
PORTx_OUTPUT *const PINOutput_C = ADDR_PORTC_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_C = ADDR_PORTC_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_C = ADDR_PORTC_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_C = ADDR_PORTC_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_C = ADDR_PORTC_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_C = ADDR_PORTC_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_C = ADDR_PORTC_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_C = ADDR_PORTC_INTERRUPT_FLAG;
//Port D
PORTx_DIRECTION *const PINDirection_D = ADDR_PORTD_DIRECTION;
PORTx_INPUT *const PINInput_D = ADDR_PORTD_INPUT;
PORTx_OUTPUT *const PINOutput_D = ADDR_PORTD_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_D = ADDR_PORTD_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_D = ADDR_PORTD_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_D = ADDR_PORTD_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_D = ADDR_PORTD_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_D = ADDR_PORTD_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_D = ADDR_PORTD_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_D = ADDR_PORTD_INTERRUPT_FLAG;
//Port E
PORTx_DIRECTION *const PINDirection_E = ADDR_PORTE_DIRECTION;
PORTx_INPUT *const PINInput_E = ADDR_PORTE_INPUT;
PORTx_OUTPUT *const PINOutput_E = ADDR_PORTE_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_E = ADDR_PORTE_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_E = ADDR_PORTE_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_E = ADDR_PORTE_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_E = ADDR_PORTE_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_E = ADDR_PORTE_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_E = ADDR_PORTE_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_E = ADDR_PORTE_INTERRUPT_FLAG;
//Port F
PORTx_DIRECTION *const PINDirection_F = ADDR_PORTF_DIRECTION;
PORTx_INPUT *const PINInput_F = ADDR_PORTF_INPUT;
PORTx_OUTPUT *const PINOutput_F = ADDR_PORTF_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_F = ADDR_PORTF_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_F = ADDR_PORTF_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_F = ADDR_PORTF_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_F = ADDR_PORTF_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_F = ADDR_PORTF_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_F = ADDR_PORTF_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_F = ADDR_PORTF_INTERRUPT_FLAG;
//Port G
PORTx_DIRECTION *const PINDirection_G = ADDR_PORTG_DIRECTION;
PORTx_INPUT *const PINInput_G = ADDR_PORTG_INPUT;
PORTx_OUTPUT *const PINOutput_G = ADDR_PORTG_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_G = ADDR_PORTG_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_G = ADDR_PORTG_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_G = ADDR_PORTG_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_G = ADDR_PORTG_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_G = ADDR_PORTG_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_G = ADDR_PORTG_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_G = ADDR_PORTG_INTERRUPT_FLAG;
//Port H
PORTx_DIRECTION *const PINDirection_H = ADDR_PORTH_DIRECTION;
PORTx_INPUT *const PINInput_H = ADDR_PORTH_INPUT;
PORTx_OUTPUT *const PINOutput_H = ADDR_PORTH_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_H = ADDR_PORTH_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_H = ADDR_PORTH_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_H = ADDR_PORTH_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_H = ADDR_PORTH_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_H = ADDR_PORTH_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_H = ADDR_PORTH_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_H = ADDR_PORTH_INTERRUPT_FLAG;
//Port I
PORTx_DIRECTION *const PINDirection_I = ADDR_PORTI_DIRECTION;
PORTx_INPUT *const PINInput_I = ADDR_PORTI_INPUT;
PORTx_OUTPUT *const PINOutput_I = ADDR_PORTI_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_I = ADDR_PORTI_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_I = ADDR_PORTI_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_I = ADDR_PORTI_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_I = ADDR_PORTI_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_I = ADDR_PORTI_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_I = ADDR_PORTI_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_I = ADDR_PORTI_INTERRUPT_FLAG;
*/
//Port J
PORTx_DIRECTION *const PINDirection_J = ADDR_PORTJ_DIRECTION;
PORTx_INPUT *const PINInput_J = ADDR_PORTJ_INPUT;
PORTx_OUTPUT *const PINOutput_J = ADDR_PORTJ_OUTPUT;
PORTx_PULLUP_PULLDOWN *const PINPUpPDwn_J = ADDR_PORTJ_PULLUP_PULLDOWN;
PORTx_FUNCTION_SELECT0 *const PINFunction0_J = ADDR_PORTJ_FUNCTION_SELECT0;
PORTx_FUNCTION_SELECT1 *const PINFunction1_J = ADDR_PORTJ_FUNCTION_SELECT1;
PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp_J = ADDR_PORTJ_FUNCTION_SELECT_COMPLEMENT;
PORTx_INTERRUPT_EDGE_SELECT *const PINIntEdge_J = ADDR_PORTJ_INTERRUPT_EDGE_SELECT;
PORTx_INTERRUPT_ENABLE *const PINIntEnable_J = ADDR_PORTJ_INTERRUPT_ENABLE;
PORTx_INTERRUPT_FLAG *const PINIntFlag_J = ADDR_PORTJ_INTERRUPT_FLAG;

PORT_UNLOCK *const portUnlock = ADDR_PORT_UNLOCK;


void Pin_Init(char port, uint8_t pinNum, E_PinType direction, E_FunctionType function, E_PullUpDown pUppDwn) {
	
	portUnlock->clearBitToUnlockIOPorts = 0;
	
	PORTx_DIRECTION *const PINDirection = Get_DirectionRegister(port);
	PORTx_INPUT *const PINInput = Get_InputRegister(port);
	PORTx_OUTPUT *const PINOutput = Get_OutputRegister(port);
	PORTx_PULLUP_PULLDOWN *const PINPUpPDwn = Get_PUpPDownRegister(port);
	PORTx_FUNCTION_SELECT0 *const PINFunction0 = Get_Function0Register(port);
	PORTx_FUNCTION_SELECT1 *const PINFunction1 = Get_Function1Register(port);
	PORTx_FUNCTION_SELECT_COMPLEMENT *const PINFucntionComp = Get_FunctionCompRegister(port);
	
	switch (pinNum) {
		
		case 0 : 
			//Check for Pin Functions
			if (function == PRIMARY_F) {
				
				PINFunction0->pin0_ModuleFunctionSelectBit0 = 1;
				PINFunction1->pin0_ModuleFunctionSelectBit1 = 0;
				PINDirection->p0_InMode0_OutMode1 = direction;
			}
			else if (function == SECONDARY_F) {
				
				PINFunction0->pin0_ModuleFunctionSelectBit0 = 0;
				PINFunction1->pin0_ModuleFunctionSelectBit1 = 1;
				PINDirection->p0_InMode0_OutMode1 = direction;
			}
			
			else if (function == TERTIARY_F) {
				
				PINFucntionComp->p0_SetSelect0AndSelect1 = 1;
				PINDirection->p0_InMode0_OutMode1 = direction;
			}
			
			else if (function == NO_F) {
				
				//Set Pin Direction with No Extra Function
				PINDirection->p0_InMode0_OutMode1 = direction;
				
				//Set PullUp-PullDown Settings (If Input Direction is Chosen)
				if (direction == IN && pUppDwn == P_DOWN) {
					
					PINPUpPDwn->enable_PullUpPullDwnPin0 = 1;
					PINOutput->p0_LowOrPullDwn0_HighOrPullUp1 = 0;
				}
				
				else if (direction == IN && pUppDwn == P_UP) {
					
					PINPUpPDwn->enable_PullUpPullDwnPin0 = 1;
					PINOutput->p0_LowOrPullDwn0_HighOrPullUp1 = 1;
				}
				
				else if (direction == IN && pUppDwn == NO_PULL) { PINPUpPDwn->enable_PullUpPullDwnPin0 = 0; }
			}
			break;
		case 1 : 
			//Check for Pin Functions
			if (function == PRIMARY_F) {
				
				PINFunction0->pin1_ModuleFunctionSelectBit0 = 1;
				PINFunction1->pin1_ModuleFunctionSelectBit1 = 0;
				PINDirection->p1_InMode0_OutMode1 = direction;
			}
			else if (function == SECONDARY_F) {
				
				PINFunction0->pin1_ModuleFunctionSelectBit0 = 0;
				PINFunction1->pin1_ModuleFunctionSelectBit1 = 1;
				PINDirection->p1_InMode0_OutMode1 = direction;
			}
			
			else if (function == TERTIARY_F) {
				
				PINFucntionComp->p1_SetSelect0AndSelect1 = 1;
				PINDirection->p1_InMode0_OutMode1 = direction;
			}
			
			else if (function == NO_F) {
				
				//Set Pin Direction with No Extra Function
				PINDirection->p1_InMode0_OutMode1 = direction;
				
				//Set PullUp-PullDown Settings (If Input Direction is Chosen)
				if (direction == IN && pUppDwn == P_DOWN) {
					
					PINPUpPDwn->enable_PullUpPullDwnPin1 = 1;
					PINOutput->p1_LowOrPullDwn0_HighOrPullUp1 = 0;
				}
				
				else if (direction == IN && pUppDwn == P_UP) {
					
					PINPUpPDwn->enable_PullUpPullDwnPin1 = 1;
					PINOutput->p1_LowOrPullDwn0_HighOrPullUp1 = 1;
				}
				
				else if (direction == IN && pUppDwn == NO_PULL) { PINPUpPDwn->enable_PullUpPullDwnPin1 = 0; }
			}
			break;
		case 2 : 
			//Check for Pin Functions
			if (function == PRIMARY_F) {
				
				PINFunction0->pin2_ModuleFunctionSelectBit0 = 1;
				PINFunction1->pin2_ModuleFunctionSelectBit1 = 0;
				PINDirection->p2_InMode0_OutMode1 = direction;
			}
			else if (function == SECONDARY_F) {
				
				PINFunction0->pin2_ModuleFunctionSelectBit0 = 0;
				PINFunction1->pin2_ModuleFunctionSelectBit1 = 1;
				PINDirection->p2_InMode0_OutMode1 = direction;
			}
			
			else if (function == TERTIARY_F) {
				
				PINFucntionComp->p2_SetSelect0AndSelect1 = 1;
				PINDirection->p2_InMode0_OutMode1 = direction;
			}
			
			else if (function == NO_F) {
				
				//Set Pin Direction with No Extra Function
				PINDirection->p2_InMode0_OutMode1 = direction;
				
				//Set PullUp-PullDown Settings (If Input Direction is Chosen)
				if (direction == IN && pUppDwn == P_DOWN) {
					
					PINPUpPDwn->enable_PullUpPullDwnPin2 = 1;
					PINOutput->p2_LowOrPullDwn0_HighOrPullUp1 = 0;
				}
				
				else if (direction == IN && pUppDwn == P_UP) {
					
					PINPUpPDwn->enable_PullUpPullDwnPin2 = 1;
					PINOutput->p2_LowOrPullDwn0_HighOrPullUp1 = 1;
				}
				
				else if (direction == IN && pUppDwn == NO_PULL) { PINPUpPDwn->enable_PullUpPullDwnPin2 = 0; }
			}
			break;
		case 3 : 
			//Check for Pin Functions
			if (function == PRIMARY_F) {
				
				PINFunction0->pin3_ModuleFunctionSelectBit0 = 1;
				PINFunction1->pin3_ModuleFunctionSelectBit1 = 0;
				PINDirection->p3_InMode0_OutMode1 = direction;
			}
			else if (function == SECONDARY_F) {
				
				PINFunction0->pin3_ModuleFunctionSelectBit0 = 0;
				PINFunction1->pin3_ModuleFunctionSelectBit1 = 1;
				PINDirection->p3_InMode0_OutMode1 = direction;
			}
			
			else if (function == TERTIARY_F) {
				
				PINFucntionComp->p3_SetSelect0AndSelect1 = 1;
				PINDirection->p3_InMode0_OutMode1 = direction;
			}
			
			else if (function == NO_F) {
				
				//Set Pin Direction with No Extra Function
				PINDirection->p3_InMode0_OutMode1 = direction;
				
				//Set PullUp-PullDown Settings (If Input Direction is Chosen)
				if (direction == IN && pUppDwn == P_DOWN) {
					
					PINPUpPDwn->enable_PullUpPullDwnPin3 = 1;
					PINOutput->p3_LowOrPullDwn0_HighOrPullUp1 = 0;
				}
				
				else if (direction == IN && pUppDwn == P_UP) {
					
					PINPUpPDwn->enable_PullUpPullDwnPin3 = 1;
					PINOutput->p3_LowOrPullDwn0_HighOrPullUp1 = 1;
				}
				
				else if (direction == IN && pUppDwn == NO_PULL) { PINPUpPDwn->enable_PullUpPullDwnPin3 = 0; }
			}
			break;
		case 4 : 
			//Check for Pin Functions
			if (function == PRIMARY_F) {
				
				PINFunction0->pin4_ModuleFunctionSelectBit0 = 1;
				PINFunction1->pin4_ModuleFunctionSelectBit1 = 0;
				PINDirection->p4_InMode0_OutMode1 = direction;
			}
			else if (function == SECONDARY_F) {
				
				PINFunction0->pin4_ModuleFunctionSelectBit0 = 0;
				PINFunction1->pin4_ModuleFunctionSelectBit1 = 1;
				PINDirection->p4_InMode0_OutMode1 = direction;
			}
			
			else if (function == TERTIARY_F) {
				
				PINFucntionComp->p4_SetSelect0AndSelect1 = 1;
				PINDirection->p4_InMode0_OutMode1 = direction;
			}
			
			else if (function == NO_F) {
				
				//Set Pin Direction with No Extra Function
				PINDirection->p4_InMode0_OutMode1 = direction;
				
				//Set PullUp-PullDown Settings (If Input Direction is Chosen)
				if (direction == IN && pUppDwn == P_DOWN) {
					
					PINPUpPDwn->enable_PullUpPullDwnPin4 = 1;
					PINOutput->p4_LowOrPullDwn0_HighOrPullUp1 = 0;
				}
				
				else if (direction == IN && pUppDwn == P_UP) {
					
					PINPUpPDwn->enable_PullUpPullDwnPin4 = 1;
					PINOutput->p4_LowOrPullDwn0_HighOrPullUp1 = 1;
				}
				
				else if (direction == IN && pUppDwn == NO_PULL) { PINPUpPDwn->enable_PullUpPullDwnPin4 = 0; }
			}
			break;
		case 5 : 
			//Check for Pin Functions
			if (function == PRIMARY_F) {
				
				PINFunction0->pin5_ModuleFunctionSelectBit0 = 1;
				PINFunction1->pin5_ModuleFunctionSelectBit1 = 0;
				PINDirection->p5_InMode0_OutMode1 = direction;
			}
			else if (function == SECONDARY_F) {
				
				PINFunction0->pin5_ModuleFunctionSelectBit0 = 0;
				PINFunction1->pin5_ModuleFunctionSelectBit1 = 1;
				PINDirection->p5_InMode0_OutMode1 = direction;
			}
			
			else if (function == TERTIARY_F) {
				
				PINFucntionComp->p5_SetSelect0AndSelect1 = 1;
				PINDirection->p5_InMode0_OutMode1 = direction;
			}
			
			else if (function == NO_F) {
				
				//Set Pin Direction with No Extra Function
				PINDirection->p5_InMode0_OutMode1 = direction;
				
				//Set PullUp-PullDown Settings (If Input Direction is Chosen)
				if (direction == IN && pUppDwn == P_DOWN) {
					
					PINPUpPDwn->enable_PullUpPullDwnPin5 = 1;
					PINOutput->p5_LowOrPullDwn0_HighOrPullUp1 = 0;
				}
				
				else if (direction == IN && pUppDwn == P_UP) {
					
					PINPUpPDwn->enable_PullUpPullDwnPin5 = 1;
					PINOutput->p5_LowOrPullDwn0_HighOrPullUp1 = 1;
				}
				
				else if (direction == IN && pUppDwn == NO_PULL) { PINPUpPDwn->enable_PullUpPullDwnPin5 = 0; }
			}
			break;
		case 6 : 
			//Check for Pin Functions
			if (function == PRIMARY_F) {
				
				PINFunction0->pin6_ModuleFunctionSelectBit0 = 1;
				PINFunction1->pin6_ModuleFunctionSelectBit1 = 0;
				PINDirection->p6_InMode0_OutMode1 = direction;
			}
			else if (function == SECONDARY_F) {
				
				PINFunction0->pin6_ModuleFunctionSelectBit0 = 0;
				PINFunction1->pin6_ModuleFunctionSelectBit1 = 1;
				PINDirection->p6_InMode0_OutMode1 = direction;
			}
			
			else if (function == TERTIARY_F) {
				
				PINFucntionComp->p6_SetSelect0AndSelect1 = 1;
				PINDirection->p6_InMode0_OutMode1 = direction;
			}
			
			else if (function == NO_F) {
				
				//Set Pin Direction with No Extra Function
				PINDirection->p6_InMode0_OutMode1 = direction;
				
				//Set PullUp-PullDown Settings (If Input Direction is Chosen)
				if (direction == IN && pUppDwn == P_DOWN) {
					
					PINPUpPDwn->enable_PullUpPullDwnPin6 = 1;
					PINOutput->p6_LowOrPullDwn0_HighOrPullUp1 = 0;
				}
				
				else if (direction == IN && pUppDwn == P_UP) {
					
					PINPUpPDwn->enable_PullUpPullDwnPin6 = 1;
					PINOutput->p6_LowOrPullDwn0_HighOrPullUp1 = 1;
				}
				
				else if (direction == IN && pUppDwn == NO_PULL) { PINPUpPDwn->enable_PullUpPullDwnPin6 = 0; }
			}
			break;
		case 7 : 
			//Check for Pin Functions
			if (function == PRIMARY_F) {
				
				PINFunction0->pin7_ModuleFunctionSelectBit0 = 1;
				PINFunction1->pin7_ModuleFunctionSelectBit1 = 0;
				PINDirection->p7_InMode0_OutMode1 = direction;
			}
			else if (function == SECONDARY_F) {
				
				PINFunction0->pin7_ModuleFunctionSelectBit0 = 0;
				PINFunction1->pin7_ModuleFunctionSelectBit1 = 1;
				PINDirection->p7_InMode0_OutMode1 = direction;
			}
			
			else if (function == TERTIARY_F) {
				
				PINFucntionComp->p7_SetSelect0AndSelect1 = 1;
				PINDirection->p7_InMode0_OutMode1 = direction;
			}
			
			else if (function == NO_F) {
				
				//Set Pin Direction with No Extra Function
				PINDirection->p7_InMode0_OutMode1 = direction;
				
				//Set PullUp-PullDown Settings (If Input Direction is Chosen)
				if (direction == IN && pUppDwn == P_DOWN) {
					
					PINPUpPDwn->enable_PullUpPullDwnPin7 = 1;
					PINOutput->p7_LowOrPullDwn0_HighOrPullUp1 = 0;
				}
				
				else if (direction == IN && pUppDwn == P_UP) {
					
					PINPUpPDwn->enable_PullUpPullDwnPin7 = 1;
					PINOutput->p7_LowOrPullDwn0_HighOrPullUp1 = 1;
				}
				
				else if (direction == IN && pUppDwn == NO_PULL) { PINPUpPDwn->enable_PullUpPullDwnPin7 = 0; }
			}
			break;
	}
		
	
}


uint8_t Pin_GetInput(char port, uint8_t pinNum) {
	
	
	PORTx_INPUT *const PINInput = Get_InputRegister(port);
	
	switch (pinNum) {
		
		case 0 : 
			return PINInput->read_Pin0;
		case 1 :
			return PINInput->read_Pin1;
		case 2 :
			return PINInput->read_Pin2;
		case 3 :
			return PINInput->read_Pin3;
		case 4 : 
			return PINInput->read_Pin4;
		case 5 :
			return PINInput->read_Pin5;
		case 6 :
			return PINInput->read_Pin6;
		case 7 :
			return PINInput->read_Pin7;
		default :
			return 42;
	}
}

void Pin_Out(char port, uint8_t pinNum, uint8_t pinState) {
	
	PORTx_OUTPUT *const PINOutput = Get_OutputRegister(port);
	
	switch (pinNum) {
		
		case 0 : 
			PINOutput->p0_LowOrPullDwn0_HighOrPullUp1 = pinState;
			break;
		case 1 :
			PINOutput->p1_LowOrPullDwn0_HighOrPullUp1 = pinState;
			break;
		case 2 :
			PINOutput->p2_LowOrPullDwn0_HighOrPullUp1 = pinState;
			break;
		case 3 :
			PINOutput->p3_LowOrPullDwn0_HighOrPullUp1 = pinState;
			break;
		case 4 : 
			PINOutput->p4_LowOrPullDwn0_HighOrPullUp1 = pinState;
			break;
		case 5 :
			PINOutput->p5_LowOrPullDwn0_HighOrPullUp1 = pinState;
			break;
		case 6 :
			PINOutput->p6_LowOrPullDwn0_HighOrPullUp1 = pinState;
			break;
		case 7 :
			PINOutput->p7_LowOrPullDwn0_HighOrPullUp1 = pinState;
			break;
	}
}

void Watchdog_Off(void) {
	
	watchdog->stop_WatchdogTimer = 1;
}

//Helper Functions---------------------------------------------------------------------------

static PORTx_FUNCTION_SELECT0* Get_Function0Register(char port) {
	
	switch (port) {
		
		case '1' :
			return PINFunction0_1;
		case '2' :
			return PINFunction0_2;
		case '3' :
			return PINFunction0_3;
		case '4' :
			return PINFunction0_4;
		/*case '5' :
			return PINFunction0_5;
		case '6' :
			return PINFunction0_6;
		case '7' :
			return PINFunction0_7;
		case '8' :
			return PINFunction0_8;
		case '9' :
			return PINFunction0_9;
		case '10' :
			return PINFunction0_10;
		case '11' :
			return PINFunction0_11;
		case 'A' :
			return PINFunction0_A;
		case 'B' :
			return PINFunction0_B;
		case 'C' :
			return PINFunction0_C;
		case 'D' :
			return PINFunction0_D;
		case 'E' :
			return PINFunction0_E;
		case 'F' :
			return PINFunction0_F;
		case 'G' :
			return PINFunction0_G;
		case 'H' :
			return PINFunction0_H;
		case 'I' :
			return PINFunction0_I;*/
		case 'J' :
			return PINFunction0_J;
		default :
			return NULL;
	}
}

static PORTx_FUNCTION_SELECT1* Get_Function1Register(char port) {
	
	switch (port) {
		
		case '1' :
			return PINFunction1_1;
		case '2' :
			return PINFunction1_2;
		case '3' :
			return PINFunction1_3;
		case '4' :
			return PINFunction1_4;
		/*case '5' :
			return PINFunction1_5;
		case '6' :
			return PINFunction1_6;
		case '7' :
			return PINFunction1_7;
		case '8' :
			return PINFunction1_8;
		case '9' :
			return PINFunction1_9;
		case '10' :
			return PINFunction1_10;
		case '11' :
			return PINFunction1_11;
		case 'A' :
			return PINFunction1_A;
		case 'B' :
			return PINFunction1_B;
		case 'C' :
			return PINFunction1_C;
		case 'D' :
			return PINFunction1_D;
		case 'E' :
			return PINFunction1_E;
		case 'F' :
			return PINFunction1_F;
		case 'G' :
			return PINFunction1_G;
		case 'H' :
			return PINFunction1_H;
		case 'I' :
			return PINFunction1_I;*/
		case 'J' :
			return PINFunction1_J;
		default :
			return NULL;
	}
}

static PORTx_FUNCTION_SELECT_COMPLEMENT* Get_FunctionCompRegister(char port) {
	
	switch (port) {
		
		case '1' :
			return PINFucntionComp_1;
		case '2' :
			return PINFucntionComp_2;
		case '3' :
			return PINFucntionComp_3;
		case '4' :
			return PINFucntionComp_4;
		/*case '5' :
			return PINFucntionComp_5;
		case '6' :
			return PINFucntionComp_6;
		case '7' :
			return PINFucntionComp_7;
		case '8' :
			return PINFucntionComp_8;
		case '9' :
			return PINFucntionComp_9;
		case '10' :
			return PINFucntionComp_10;
		case '11' :
			return PINFucntionComp_11;
		case 'A' :
			return PINFucntionComp_A;
		case 'B' :
			return PINFucntionComp_B;
		case 'C' :
			return PINFucntionComp_C;
		case 'D' :
			return PINFucntionComp_D;
		case 'E' :
			return PINFucntionComp_E;
		case 'F' :
			return PINFucntionComp_F;
		case 'G' :
			return PINFucntionComp_G;
		case 'H' :
			return PINFucntionComp_H;
		case 'I' :
			return PINFucntionComp_I;*/
		case 'J' :
			return PINFucntionComp_J;
		default :
			return NULL;
	}
}

static PORTx_DIRECTION* Get_DirectionRegister(char port) {
	
	switch (port) {
		
		case '1' :
			return PINDirection_1;
		case '2' :
			return PINDirection_2;
		case '3' :
			return PINDirection_3;
		case '4' :
			return PINDirection_4;
		/*case '5' :
			return PINDirection_5;
		case '6' :
			return PINDirection_6;
		case '7' :
			return PINDirection_7;
		case '8' :
			return PINDirection_8;
		case '9' :
			return PINDirection_9;
		case '10' :
			return PINDirection_10;
		case '11' :
			return PINDirection_11;
		case 'A' :
			return PINDirection_A;
		case 'B' :
			return PINDirection_B;
		case 'C' :
			return PINDirection_C;
		case 'D' :
			return PINDirection_D;
		case 'E' :
			return PINDirection_E;
		case 'F' :
			return PINDirection_F;
		case 'G' :
			return PINDirection_G;
		case 'H' :
			return PINDirection_H;
		case 'I' :
			return PINDirection_I;*/
		case 'J' :
			return PINDirection_J;
		default :
			return NULL;
	}
}

static PORTx_INPUT* Get_InputRegister(char port) {
	
	switch (port) {
		
		case '1' :
			return PINInput_1;
		case '2' :
			return PINInput_2;
		case '3' :
			return PINInput_3;
		case '4' :
			return PINInput_4;
		/*case '5' :
			return PINInput_5;
		case '6' :
			return PINInput_6;
		case '7' :
			return PPINInput_7;
		case '8' :
			return PINInput_8;
		case '9' :
			return PINInput_9;
		case '10' :
			return PINInput_10;
		case '11' :
			return PINInput_11;
		case 'A' :
			return PINInput_A;
		case 'B' :
			return PINInput_B;
		case 'C' :
			return PINInput_C;
		case 'D' :
			return PINInput_D;
		case 'E' :
			return PINInput_E;
		case 'F' :
			return PINInput_F;
		case 'G' :
			return PINInput_G;
		case 'H' :
			return PINInput_H;
		case 'I' :
			return PINInput_I;*/
		case 'J' :
			return PINInput_J;
		default :
			return NULL;
	}
}

static PORTx_OUTPUT* Get_OutputRegister(char port) {
	
	switch (port) {
		
		case '1' :
			return PINOutput_1;
		case '2' :
			return PINOutput_2;
		case '3' :
			return PINOutput_3;
		case '4' :
			return PINOutput_4;
		/*case '5' :
			return PINOutput_5;
		case '6' :
			return PINOutput_6;
		case '7' :
			return PINOutput_7;
		case '8' :
			return PINOutput_8;
		case '9' :
			return PINOutput_9;
		case '10' :
			return PINOutput_10;
		case '11' :
			return PINOutput_11;
		case 'A' :
			return PINOutput_A;
		case 'B' :
			return PINOutput_B;
		case 'C' :
			return PINOutput_C;
		case 'D' :
			return PINOutput_D;
		case 'E' :
			return PINOutput_E;
		case 'F' :
			return PINOutput_F;
		case 'G' :
			return PINOutput_G;
		case 'H' :
			return PINOutput_H;
		case 'I' :
			return PINOutput_I;*/
		case 'J' :
			return PINOutput_J;
		default :
			return NULL;
	}
}

static PORTx_PULLUP_PULLDOWN* Get_PUpPDownRegister(char port) {
	
	switch (port) {
		
		case '1' :
			return PINPUpPDwn_1;
		case '2' :
			return PINPUpPDwn_2;
		case '3' :
			return PINPUpPDwn_3;
		case '4' :
			return PINPUpPDwn_4;
		/*case '5' :
			return PINPUpPDwn_5;
		case '6' :
			return PINPUpPDwn_6;
		case '7' :
			return PINPUpPDwn_7;
		case '8' :
			return PINPUpPDwn_8;
		case '9' :
			return PINPUpPDwn_9;
		case '10' :
			return PINPUpPDwn_10;
		case '11' :
			return PINPUpPDwn_11;
		case 'A' :
			return PINPUpPDwn_A;
		case 'B' :
			return PINPUpPDwn_B;
		case 'C' :
			return PINPUpPDwn_C;
		case 'D' :
			return PINPUpPDwn_D;
		case 'E' :
			return PINPUpPDwn_E;
		case 'F' :
			return PINPUpPDwn_F;
		case 'G' :
			return PINPUpPDwn_G;
		case 'H' :
			return PINPUpPDwn_H;
		case 'I' :
			return PINPUpPDwn_I;*/
		case 'J' :
			return PINPUpPDwn_J;
		default :
			return NULL;
	}
}

