#include <stdint.h>
#include "digital_io_MSP430FR.h"

//Static Prototypes------------------------------------------------------
static void Watchdog_Off(void);
static PORTSx* Get_Port(char port);


//Global Variables-------------------------------------------------------
//Watchdog Timer (Turn Off)
WATCHDOG_CONTROL *const watchdog = ADDR_WATCHDOG_CONTROL;
//Ports
PORTSx *const PORT1 = ADDR_PORT1;
PORTSx *const PORT2 = ADDR_PORT2;
PORTSx *const PORT3 = ADDR_PORT3;
PORTSx *const PORT4 = ADDR_PORT4;
PORTSx *const PORTJ = ADDR_PORTJ;
PORT_UNLOCK *const PortUnlock = ADDR_PORT_UNLOCK;



void Pin_Init(char port, uint8_t pinNum, E_PinType direction, E_FunctionType function, E_PullUpDown pUppDwn) {
	
	PortUnlock->clearBitToUnlockIOPorts = 0;
	Watchdog_Off();
	PORTSx *const PORT = Get_Port(port);
	
	switch (pinNum) {
		case 0 : 
			PORT->FunctionSelect0Reg.pin0_ModuleFunctionSelectBit0 = 0;
			PORT->FunctionSelect1Reg.pin0_ModuleFunctionSelectBit1 = 0;
			PORT->DirectionReg.p0_InMode0_OutMode1 = direction;
			
			//Check for Pin Functions
			if (function == PRIMARY_F) { PORT->FunctionSelect0Reg.pin0_ModuleFunctionSelectBit0 = 1; }
			else if (function == SECONDARY_F) { PORT->FunctionSelect1Reg.pin0_ModuleFunctionSelectBit1 = 1; }
			else if (function == TERTIARY_F) { PORT->FunctionSelectComplementReg.p0_SetSelect0AndSelect1 = 1; }
			
			else if (function == NO_F) {
				
				PORT->PullUpPullDownReg.enable_PullUpPullDwnPin0 = 0;
				//Set PullUp-PullDown Settings (If Input Direction is Chosen)
				if (direction == IN && pUppDwn == P_DOWN) {
					PORT->PullUpPullDownReg.enable_PullUpPullDwnPin0 = 1;
					PORT->OutputReg.p0_LowOrPullDwn0_HighOrPullUp1 = 0;
				}
				
				else if (direction == IN && pUppDwn == P_UP) {
					PORT->PullUpPullDownReg.enable_PullUpPullDwnPin0 = 1;
					PORT->OutputReg.p0_LowOrPullDwn0_HighOrPullUp1 = 1;
				}
			}
			break;

		case 1 : 
			PORT->FunctionSelect0Reg.pin1_ModuleFunctionSelectBit0 = 0;
			PORT->FunctionSelect1Reg.pin1_ModuleFunctionSelectBit1 = 0;
			PORT->DirectionReg.p1_InMode0_OutMode1 = direction;
			
			//Check for Pin Functions
			if (function == PRIMARY_F) { PORT->FunctionSelect0Reg.pin1_ModuleFunctionSelectBit0 = 1; }
			else if (function == SECONDARY_F) { PORT->FunctionSelect1Reg.pin1_ModuleFunctionSelectBit1 = 1; }
			else if (function == TERTIARY_F) { PORT->FunctionSelectComplementReg.p1_SetSelect0AndSelect1 = 1; }
			
			else if (function == NO_F) {
				
				PORT->PullUpPullDownReg.enable_PullUpPullDwnPin0 = 0;
				//Set PullUp-PullDown Settings (If Input Direction is Chosen)
				if (direction == IN && pUppDwn == P_DOWN) {
					PORT->PullUpPullDownReg.enable_PullUpPullDwnPin1 = 1;
					PORT->OutputReg.p1_LowOrPullDwn0_HighOrPullUp1 = 0;
				}
				
				else if (direction == IN && pUppDwn == P_UP) {
					PORT->PullUpPullDownReg.enable_PullUpPullDwnPin1 = 1;
					PORT->OutputReg.p1_LowOrPullDwn0_HighOrPullUp1 = 1;
				}
			}
			break;

		case 2 : 
			PORT->FunctionSelect0Reg.pin2_ModuleFunctionSelectBit0 = 0;
			PORT->FunctionSelect1Reg.pin2_ModuleFunctionSelectBit1 = 0;
			PORT->DirectionReg.p2_InMode0_OutMode1 = direction;
			
			//Check for Pin Functions
			if (function == PRIMARY_F) { PORT->FunctionSelect0Reg.pin2_ModuleFunctionSelectBit0 = 1; }
			else if (function == SECONDARY_F) { PORT->FunctionSelect1Reg.pin2_ModuleFunctionSelectBit1 = 1; }
			else if (function == TERTIARY_F) { PORT->FunctionSelectComplementReg.p2_SetSelect0AndSelect1 = 1; }
			
			else if (function == NO_F) {
				
				PORT->PullUpPullDownReg.enable_PullUpPullDwnPin0 = 0;
				//Set PullUp-PullDown Settings (If Input Direction is Chosen)
				if (direction == IN && pUppDwn == P_DOWN) {
					PORT->PullUpPullDownReg.enable_PullUpPullDwnPin2 = 1;
					PORT->OutputReg.p2_LowOrPullDwn0_HighOrPullUp1 = 0;
				}
				
				else if (direction == IN && pUppDwn == P_UP) {
					PORT->PullUpPullDownReg.enable_PullUpPullDwnPin2 = 1;
					PORT->OutputReg.p2_LowOrPullDwn0_HighOrPullUp1 = 1;
				}
			}
			break;

		case 3 : 
			PORT->FunctionSelect0Reg.pin3_ModuleFunctionSelectBit0 = 0;
			PORT->FunctionSelect1Reg.pin3_ModuleFunctionSelectBit1 = 0;
			PORT->DirectionReg.p3_InMode0_OutMode1 = direction;
			
			//Check for Pin Functions
			if (function == PRIMARY_F) { PORT->FunctionSelect0Reg.pin3_ModuleFunctionSelectBit0 = 1; }
			else if (function == SECONDARY_F) { PORT->FunctionSelect1Reg.pin3_ModuleFunctionSelectBit1 = 1; }
			else if (function == TERTIARY_F) { PORT->FunctionSelectComplementReg.p3_SetSelect0AndSelect1 = 1; }
			
			else if (function == NO_F) {
				
				PORT->PullUpPullDownReg.enable_PullUpPullDwnPin0 = 0;
				//Set PullUp-PullDown Settings (If Input Direction is Chosen)
				if (direction == IN && pUppDwn == P_DOWN) {
					PORT->PullUpPullDownReg.enable_PullUpPullDwnPin3 = 1;
					PORT->OutputReg.p3_LowOrPullDwn0_HighOrPullUp1 = 0;
				}
				
				else if (direction == IN && pUppDwn == P_UP) {
					PORT->PullUpPullDownReg.enable_PullUpPullDwnPin3 = 1;
					PORT->OutputReg.p3_LowOrPullDwn0_HighOrPullUp1 = 1;
				}
			}
			break;

		case 4 : 
			PORT->FunctionSelect0Reg.pin4_ModuleFunctionSelectBit0 = 0;
			PORT->FunctionSelect1Reg.pin4_ModuleFunctionSelectBit1 = 0;
			PORT->DirectionReg.p4_InMode0_OutMode1 = direction;
			
			//Check for Pin Functions
			if (function == PRIMARY_F) { PORT->FunctionSelect0Reg.pin4_ModuleFunctionSelectBit0 = 1; }
			else if (function == SECONDARY_F) { PORT->FunctionSelect1Reg.pin4_ModuleFunctionSelectBit1 = 1; }
			else if (function == TERTIARY_F) { PORT->FunctionSelectComplementReg.p4_SetSelect0AndSelect1 = 1; }
			
			else if (function == NO_F) {
				
				PORT->PullUpPullDownReg.enable_PullUpPullDwnPin0 = 0;
				//Set PullUp-PullDown Settings (If Input Direction is Chosen)
				if (direction == IN && pUppDwn == P_DOWN) {
					PORT->PullUpPullDownReg.enable_PullUpPullDwnPin4 = 1;
					PORT->OutputReg.p4_LowOrPullDwn0_HighOrPullUp1 = 0;
				}
				
				else if (direction == IN && pUppDwn == P_UP) {
					PORT->PullUpPullDownReg.enable_PullUpPullDwnPin4 = 1;
					PORT->OutputReg.p4_LowOrPullDwn0_HighOrPullUp1 = 1;
				}
			}
			break;

		case 5 : 
			PORT->FunctionSelect0Reg.pin5_ModuleFunctionSelectBit0 = 0;
			PORT->FunctionSelect1Reg.pin5_ModuleFunctionSelectBit1 = 0;
			PORT->DirectionReg.p5_InMode0_OutMode1 = direction;
			
			//Check for Pin Functions
			if (function == PRIMARY_F) { PORT->FunctionSelect0Reg.pin5_ModuleFunctionSelectBit0 = 1; }
			else if (function == SECONDARY_F) { PORT->FunctionSelect1Reg.pin5_ModuleFunctionSelectBit1 = 1; }
			else if (function == TERTIARY_F) { PORT->FunctionSelectComplementReg.p5_SetSelect0AndSelect1 = 1; }
			
			else if (function == NO_F) {
				
				PORT->PullUpPullDownReg.enable_PullUpPullDwnPin5 = 0;
				//Set PullUp-PullDown Settings (If Input Direction is Chosen)
				if (direction == IN && pUppDwn == P_DOWN) {
					PORT->PullUpPullDownReg.enable_PullUpPullDwnPin5 = 1;
					PORT->OutputReg.p5_LowOrPullDwn0_HighOrPullUp1 = 0;
				}
				
				else if (direction == IN && pUppDwn == P_UP) {
					PORT->PullUpPullDownReg.enable_PullUpPullDwnPin5 = 1;
					PORT->OutputReg.p5_LowOrPullDwn0_HighOrPullUp1 = 1;
				}
			}
			break;

		case 6 : 
			PORT->FunctionSelect0Reg.pin6_ModuleFunctionSelectBit0 = 0;
			PORT->FunctionSelect1Reg.pin6_ModuleFunctionSelectBit1 = 0;
			PORT->DirectionReg.p6_InMode0_OutMode1 = direction;
			
			//Check for Pin Functions
			if (function == PRIMARY_F) { PORT->FunctionSelect0Reg.pin6_ModuleFunctionSelectBit0 = 1; }
			else if (function == SECONDARY_F) { PORT->FunctionSelect1Reg.pin6_ModuleFunctionSelectBit1 = 1; }
			else if (function == TERTIARY_F) { PORT->FunctionSelectComplementReg.p6_SetSelect0AndSelect1 = 1; }
			
			else if (function == NO_F) {
				
				PORT->PullUpPullDownReg.enable_PullUpPullDwnPin6 = 0;
				//Set PullUp-PullDown Settings (If Input Direction is Chosen)
				if (direction == IN && pUppDwn == P_DOWN) {
					PORT->PullUpPullDownReg.enable_PullUpPullDwnPin6 = 1;
					PORT->OutputReg.p6_LowOrPullDwn0_HighOrPullUp1 = 0;
				}
				
				else if (direction == IN && pUppDwn == P_UP) {
					PORT->PullUpPullDownReg.enable_PullUpPullDwnPin6 = 1;
					PORT->OutputReg.p6_LowOrPullDwn0_HighOrPullUp1 = 1;
				}
			}
			break;

		case 7 : 
			PORT->FunctionSelect0Reg.pin7_ModuleFunctionSelectBit0 = 0;
			PORT->FunctionSelect1Reg.pin7_ModuleFunctionSelectBit1 = 0;
			PORT->DirectionReg.p7_InMode0_OutMode1 = direction;
			
			//Check for Pin Functions
			if (function == PRIMARY_F) { PORT->FunctionSelect0Reg.pin7_ModuleFunctionSelectBit0 = 1; }
			else if (function == SECONDARY_F) { PORT->FunctionSelect1Reg.pin7_ModuleFunctionSelectBit1 = 1; }
			else if (function == TERTIARY_F) { PORT->FunctionSelectComplementReg.p7_SetSelect0AndSelect1 = 1; }
			
			else if (function == NO_F) {
				
				PORT->PullUpPullDownReg.enable_PullUpPullDwnPin7 = 0;
				//Set PullUp-PullDown Settings (If Input Direction is Chosen)
				if (direction == IN && pUppDwn == P_DOWN) {
					PORT->PullUpPullDownReg.enable_PullUpPullDwnPin7 = 1;
					PORT->OutputReg.p7_LowOrPullDwn0_HighOrPullUp1 = 0;
				}
				
				else if (direction == IN && pUppDwn == P_UP) {
					PORT->PullUpPullDownReg.enable_PullUpPullDwnPin7 = 1;
					PORT->OutputReg.p7_LowOrPullDwn0_HighOrPullUp1 = 1;
				}
			}
			break;
		}
}


uint8_t Pin_GetInput(char port, uint8_t pinNum) {
	
	PORTSx *const PORT = Get_Port(port);
	switch (pinNum) {
		
		case 0 : 
			return PORT->InputReg.read_Pin0;
		case 1 :
			return PORT->InputReg.read_Pin1;
		case 2 :
			return PORT->InputReg.read_Pin2;
		case 3 :
			return PORT->InputReg.read_Pin3;
		case 4 : 
			return PORT->InputReg.read_Pin4;
		case 5 :
			return PORT->InputReg.read_Pin5;
		case 6 :
			return PORT->InputReg.read_Pin6;
		case 7 :
			return PORT->InputReg.read_Pin7;
		default :
			return;
	}
}

void Pin_Out(char port, uint8_t pinNum, uint8_t pinState) {
	
	PORTSx *const PORT = Get_Port(port);
	switch (pinNum) {
		
		case 0 : 
			PORT->OutputReg.p0_LowOrPullDwn0_HighOrPullUp1 = pinState;
			break;
		case 1 :
			PORT->OutputReg.p1_LowOrPullDwn0_HighOrPullUp1 = pinState;
			break;
		case 2 :
			PORT->OutputReg.p2_LowOrPullDwn0_HighOrPullUp1 = pinState;
			break;
		case 3 :
			PORT->OutputReg.p3_LowOrPullDwn0_HighOrPullUp1 = pinState;
			break;
		case 4 : 
			PORT->OutputReg.p4_LowOrPullDwn0_HighOrPullUp1 = pinState;
			break;
		case 5 :
			PORT->OutputReg.p5_LowOrPullDwn0_HighOrPullUp1 = pinState;
			break;
		case 6 :
			PORT->OutputReg.p6_LowOrPullDwn0_HighOrPullUp1 = pinState;
			break;
		case 7 :
			PORT->OutputReg.p7_LowOrPullDwn0_HighOrPullUp1 = pinState;
			break;
	}
}

//Helper Functions---------------------------------------------------------------------------
static void Watchdog_Off(void) {
	
	watchdog->stop_WatchdogTimer = 1;
}

static PORTSx* Get_Port(char port) {

	switch(port) {

		case '1':
			return PORT1;
		case '2':
			return PORT2;
		case '3':
			return PORT3;
		case '4':
			return PORT4;
		case 'J':
			return PORTJ;
		default:
			return;
	}
}


