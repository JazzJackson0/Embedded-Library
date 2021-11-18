#include <stdint.h>
#include <stddef.h>
#include "gpio_STM32F407.h"

//Static Prototypes-----------------------------------------------------------------
static void Pin_AltFunc(char port, uint8_t pinNum, E_PinModes altFunction);
static void ClockStart_Choice(char port);
static GPIOx_MODE* ModeReg_Choice(char port);
static GPIOx_OUTPUTSPEED* OutSpeedReg_Choice(char port);
static GPIOx_PULLUP_PULLDOWN* PUpPDownReg_Choice(char port);
static GPIOx_INPUT* InputReg_Choice(char port);
static GPIOx_OUTPUT* OutputReg_Choice(char port);
static GPIOx_ALTERNATE_FUNCT_LOW* AltLowReg_Choice(char port);
static GPIOx_ALTERNATE_FUNCT_HIGH* AltHighReg_Choice(char port);


//Global Variables------------------------------------------------------------------
GPIOx_CLOCK *const GPIOClock = ADDR_GPIOx_CLOCK;
//GPIOA
GPIOx_MODE *const A_PinMode = ADDR_GPIOA_MODE;
GPIOx_OUTPUTSPEED *const A_OutSpeed = ADDR_GPIOA_OUTPUTSPEED;
GPIOx_PULLUP_PULLDOWN *const A_PUpPDwn = ADDR_GPIOA_PULLUP_PULLDOWN;
GPIOx_INPUT *const A_Input = ADDR_GPIOA_INPUT;
GPIOx_OUTPUT *const A_Output = ADDR_GPIOA_OUTPUT;
GPIOx_ALTERNATE_FUNCT_LOW *const A_PinAltFuncLow = ADDR_GPIOA_ALTERNATE_FUNCT_LOW;
GPIOx_ALTERNATE_FUNCT_HIGH *const A_PinAltFuncHigh = ADDR_GPIOA_ALTERNATE_FUNCT_HIGH;
//GPIOB
GPIOx_MODE *const B_PinMode = ADDR_GPIOB_MODE;
GPIOx_OUTPUTSPEED *const B_OutSpeed = ADDR_GPIOB_OUTPUTSPEED;
GPIOx_PULLUP_PULLDOWN *const B_PUpPDwn = ADDR_GPIOB_PULLUP_PULLDOWN;
GPIOx_INPUT *const B_Input = ADDR_GPIOB_INPUT;
GPIOx_OUTPUT *const B_Output = ADDR_GPIOB_OUTPUT;
GPIOx_ALTERNATE_FUNCT_LOW *const B_PinAltFuncLow = ADDR_GPIOB_ALTERNATE_FUNCT_LOW;
GPIOx_ALTERNATE_FUNCT_HIGH *const B_PinAltFuncHigh = ADDR_GPIOB_ALTERNATE_FUNCT_HIGH;
//GPIOC
GPIOx_MODE *const C_PinMode = ADDR_GPIOC_MODE;
GPIOx_OUTPUTSPEED *const C_OutSpeed = ADDR_GPIOC_OUTPUTSPEED;
GPIOx_PULLUP_PULLDOWN *const C_PUpPDwn = ADDR_GPIOC_PULLUP_PULLDOWN;
GPIOx_INPUT *const C_Input = ADDR_GPIOC_INPUT;
GPIOx_OUTPUT *const C_Output = ADDR_GPIOC_OUTPUT;
GPIOx_ALTERNATE_FUNCT_LOW *const C_PinAltFuncLow = ADDR_GPIOC_ALTERNATE_FUNCT_LOW;
GPIOx_ALTERNATE_FUNCT_HIGH *const C_PinAltFuncHigh = ADDR_GPIOC_ALTERNATE_FUNCT_HIGH;
//GPIOD
GPIOx_MODE *const D_PinMode = ADDR_GPIOD_MODE;
GPIOx_OUTPUTSPEED *const D_OutSpeed = ADDR_GPIOD_OUTPUTSPEED;
GPIOx_PULLUP_PULLDOWN *const D_PUpPDwn = ADDR_GPIOD_PULLUP_PULLDOWN;
GPIOx_INPUT *const D_Input = ADDR_GPIOD_INPUT;
GPIOx_OUTPUT *const D_Output = ADDR_GPIOD_OUTPUT;
GPIOx_ALTERNATE_FUNCT_LOW *const D_PinAltFuncLow = ADDR_GPIOD_ALTERNATE_FUNCT_LOW;
GPIOx_ALTERNATE_FUNCT_HIGH *const D_PinAltFuncHigh = ADDR_GPIOD_ALTERNATE_FUNCT_HIGH;
//GPIOE
GPIOx_MODE *const E_PinMode = ADDR_GPIOE_MODE;
GPIOx_OUTPUTSPEED *const E_OutSpeed = ADDR_GPIOE_OUTPUTSPEED;
GPIOx_PULLUP_PULLDOWN *const E_PUpPDwn = ADDR_GPIOE_PULLUP_PULLDOWN;
GPIOx_INPUT *const E_Input = ADDR_GPIOE_INPUT;
GPIOx_OUTPUT *const E_Output = ADDR_GPIOE_OUTPUT;
GPIOx_ALTERNATE_FUNCT_LOW *const E_PinAltFuncLow = ADDR_GPIOE_ALTERNATE_FUNCT_LOW;
GPIOx_ALTERNATE_FUNCT_HIGH *const E_PinAltFuncHigh = ADDR_GPIOE_ALTERNATE_FUNCT_HIGH;
//GPIOF
GPIOx_MODE *const F_PinMode = ADDR_GPIOF_MODE;
GPIOx_OUTPUTSPEED *const F_OutSpeed = ADDR_GPIOF_OUTPUTSPEED;
GPIOx_PULLUP_PULLDOWN *const F_PUpPDwn = ADDR_GPIOF_PULLUP_PULLDOWN;
GPIOx_INPUT *const F_Input = ADDR_GPIOF_INPUT;
GPIOx_OUTPUT *const F_Output = ADDR_GPIOF_OUTPUT;
GPIOx_ALTERNATE_FUNCT_LOW *const F_PinAltFuncLow = ADDR_GPIOF_ALTERNATE_FUNCT_LOW;
GPIOx_ALTERNATE_FUNCT_HIGH *const F_PinAltFuncHigh = ADDR_GPIOF_ALTERNATE_FUNCT_HIGH;
//GPIOG
GPIOx_MODE *const G_PinMode = ADDR_GPIOG_MODE;
GPIOx_OUTPUTSPEED *const G_OutSpeed = ADDR_GPIOG_OUTPUTSPEED;
GPIOx_PULLUP_PULLDOWN *const G_PUpPDwn = ADDR_GPIOG_PULLUP_PULLDOWN;
GPIOx_INPUT *const G_Input = ADDR_GPIOG_INPUT;
GPIOx_OUTPUT *const G_Output = ADDR_GPIOG_OUTPUT;
GPIOx_ALTERNATE_FUNCT_LOW *const G_PinAltFuncLow = ADDR_GPIOG_ALTERNATE_FUNCT_LOW;
GPIOx_ALTERNATE_FUNCT_HIGH *const G_PinAltFuncHigh = ADDR_GPIOG_ALTERNATE_FUNCT_HIGH;
//GPIOH
GPIOx_MODE *const H_PinMode = ADDR_GPIOH_MODE;
GPIOx_OUTPUTSPEED *const H_OutSpeed = ADDR_GPIOH_OUTPUTSPEED;
GPIOx_PULLUP_PULLDOWN *const H_PUpPDwn = ADDR_GPIOH_PULLUP_PULLDOWN;
GPIOx_INPUT *const H_Input = ADDR_GPIOH_INPUT;
GPIOx_OUTPUT *const H_Output = ADDR_GPIOH_OUTPUT;
GPIOx_ALTERNATE_FUNCT_LOW *const H_PinAltFuncLow = ADDR_GPIOH_ALTERNATE_FUNCT_LOW;
GPIOx_ALTERNATE_FUNCT_HIGH *const H_PinAltFuncHigh = ADDR_GPIOH_ALTERNATE_FUNCT_HIGH;
//GPIOI
GPIOx_MODE *const I_PinMode = ADDR_GPIOI_MODE;
GPIOx_OUTPUTSPEED *const I_OutSpeed = ADDR_GPIOI_OUTPUTSPEED;
GPIOx_PULLUP_PULLDOWN *const I_PUpPDwn = ADDR_GPIOI_PULLUP_PULLDOWN;
GPIOx_INPUT *const I_Input = ADDR_GPIOI_INPUT;
GPIOx_OUTPUT *const I_Output = ADDR_GPIOI_OUTPUT;
GPIOx_ALTERNATE_FUNCT_LOW *const I_PinAltFuncLow = ADDR_GPIOI_ALTERNATE_FUNCT_LOW;
GPIOx_ALTERNATE_FUNCT_HIGH *const I_PinAltFuncHigh = ADDR_GPIOI_ALTERNATE_FUNCT_HIGH;



void Pin_Init(char port, uint8_t pinNum, E_PinModes modeType) {
	
	ClockStart_Choice(port);
	
	GPIOx_MODE *const PinMode = ModeReg_Choice(port);
	
	switch(pinNum) {
	
		case 0 :
			if (modeType != IN && modeType != OUT && modeType != ANALOG) {
				
				PinMode->rw_Pin0_Mode = 0x00;
				PinMode->rw_Pin0_Mode = AF;
				Pin_AltFunc(port, pinNum, modeType);
			}
			else if (modeType >= 0x10){
				
				modeType = modeType - 0x10;
				PinMode->rw_Pin0_Mode = 0x00;
				PinMode->rw_Pin0_Mode = modeType;
			}
			break;
		case 1 :
			if (modeType != IN && modeType != OUT && modeType != ANALOG) {
				
				PinMode->rw_Pin1_Mode = 0x00;
				PinMode->rw_Pin1_Mode = AF;
				Pin_AltFunc(port, pinNum, modeType);
			}
			else if (modeType >= 0x10){
				
				modeType = modeType - 0x10;
				PinMode->rw_Pin1_Mode = 0x00;
				PinMode->rw_Pin1_Mode = modeType;
			}
			break;
		case 2 :
			if (modeType != IN && modeType != OUT && modeType != ANALOG) {
				
				PinMode->rw_Pin2_Mode = 0x00;
				PinMode->rw_Pin2_Mode = AF;
				Pin_AltFunc(port, pinNum, modeType);
			}
			else if (modeType >= 0x10){
				
				modeType = modeType - 0x10;
				PinMode->rw_Pin2_Mode = 0x00;
				PinMode->rw_Pin2_Mode = modeType;
			}
			break;
		case 3 :
			if (modeType != IN && modeType != OUT && modeType != ANALOG) {
				
				PinMode->rw_Pin3_Mode = 0x00;
				PinMode->rw_Pin3_Mode = AF;
				Pin_AltFunc(port, pinNum, modeType);
			}
			else if (modeType >= 0x10){
				
				modeType = modeType - 0x10;
				PinMode->rw_Pin3_Mode = 0x00;
				PinMode->rw_Pin3_Mode = modeType;
			}
			break;
		case 4 :
			if (modeType != IN && modeType != OUT && modeType != ANALOG) {
				
				PinMode->rw_Pin4_Mode = 0x00;
				PinMode->rw_Pin4_Mode = AF;
				Pin_AltFunc(port, pinNum, modeType);
			}
			else if (modeType >= 0x10){
				
				modeType = modeType - 0x10;
				PinMode->rw_Pin4_Mode = 0x00;
				PinMode->rw_Pin4_Mode = modeType;
			}
			break;
		case 5 :
			if (modeType != IN && modeType != OUT && modeType != ANALOG) {
				
				PinMode->rw_Pin5_Mode = 0x00;
				PinMode->rw_Pin5_Mode = AF;
				Pin_AltFunc(port, pinNum, modeType);
			}
			else if (modeType >= 0x10){
				
				modeType = modeType - 0x10;
				PinMode->rw_Pin5_Mode = 0x00;
				PinMode->rw_Pin5_Mode = modeType;
			}
			break;
		case 6 :
			if (modeType != IN && modeType != OUT && modeType != ANALOG) {
				
				PinMode->rw_Pin6_Mode = 0x00;
				PinMode->rw_Pin6_Mode = AF;
				Pin_AltFunc(port, pinNum, modeType);
			}
			else if (modeType >= 0x10){
				
				modeType = modeType - 0x10;
				PinMode->rw_Pin6_Mode = 0x00;
				PinMode->rw_Pin6_Mode = modeType;
			}
			break;
		case 7 :
			if (modeType != IN && modeType != OUT && modeType != ANALOG) {
				
				PinMode->rw_Pin7_Mode = 0x00;
				PinMode->rw_Pin7_Mode = AF;
				Pin_AltFunc(port, pinNum, modeType);
			}
			else if (modeType >= 0x10){
				
				modeType = modeType - 0x10;
				PinMode->rw_Pin7_Mode = 0x00;
				PinMode->rw_Pin7_Mode = modeType;
			}
			break;
		case 8 :
			if (modeType != IN && modeType != OUT && modeType != ANALOG) {
				
				PinMode->rw_Pin8_Mode = 0x00;
				PinMode->rw_Pin8_Mode = AF;
				Pin_AltFunc(port, pinNum, modeType);
			}
			else if (modeType >= 0x10){
				
				modeType = modeType - 0x10;
				PinMode->rw_Pin8_Mode = 0x00;
				PinMode->rw_Pin8_Mode = modeType;
			}
			break;
		case 9 :
			if (modeType != IN && modeType != OUT && modeType != ANALOG) {
				
				PinMode->rw_Pin9_Mode = 0x00;
				PinMode->rw_Pin9_Mode = AF;
				Pin_AltFunc(port, pinNum, modeType);
			}
			else if (modeType >= 0x10){
				
				modeType = modeType - 0x10;
				PinMode->rw_Pin9_Mode = 0x00;
				PinMode->rw_Pin9_Mode = modeType;
			}
			break;
		case 10 :
			if (modeType != IN && modeType != OUT && modeType != ANALOG) {
				
				PinMode->rw_Pin10_Mode = 0x00;
				PinMode->rw_Pin10_Mode = AF;
				Pin_AltFunc(port, pinNum, modeType);
			}
			else if (modeType >= 0x10){
				
				modeType = modeType - 0x10;
				PinMode->rw_Pin10_Mode = 0x00;
				PinMode->rw_Pin10_Mode = modeType;
			}
			break;
		case 11 :
			if (modeType != IN && modeType != OUT && modeType != ANALOG) {
				
				PinMode->rw_Pin11_Mode = 0x00;
				PinMode->rw_Pin11_Mode = AF;
				Pin_AltFunc(port, pinNum, modeType);
			}
			else if (modeType >= 0x10){
				
				modeType = modeType - 0x10;
				PinMode->rw_Pin11_Mode = 0x00;
				PinMode->rw_Pin11_Mode = modeType;
			}
			break;
		case 12 :
			if (modeType != IN && modeType != OUT && modeType != ANALOG) {
				
				PinMode->rw_Pin12_Mode = 0x00;
				PinMode->rw_Pin12_Mode = AF;
				Pin_AltFunc(port, pinNum, modeType);
			}
			else if (modeType >= 0x10){
				
				modeType = modeType - 0x10;
				PinMode->rw_Pin12_Mode = 0x00;
				PinMode->rw_Pin12_Mode = modeType;
			}
			break;
		case 13 :
			if (modeType != IN && modeType != OUT && modeType != ANALOG) {
				
				PinMode->rw_Pin13_Mode = 0x00;
				PinMode->rw_Pin13_Mode = AF;
				Pin_AltFunc(port, pinNum, modeType);
			}
			else if (modeType >= 0x10){
				
				modeType = modeType - 0x10;
				PinMode->rw_Pin13_Mode = 0x00;
				PinMode->rw_Pin13_Mode = modeType;
			}
			break;
		case 14 :
			if (modeType != IN && modeType != OUT && modeType != ANALOG) {
				
				PinMode->rw_Pin14_Mode = 0x00;
				PinMode->rw_Pin14_Mode = AF;
				Pin_AltFunc(port, pinNum, modeType);
			}
			else if (modeType >= 0x10){
				
				modeType = modeType - 0x10;
				PinMode->rw_Pin14_Mode = 0x00;
				PinMode->rw_Pin14_Mode = modeType;
			}
			break;
		case 15 :
			if (modeType != IN && modeType != OUT && modeType != ANALOG) {
				
				PinMode->rw_Pin15_Mode = 0x00;
				PinMode->rw_Pin15_Mode = AF;
				Pin_AltFunc(port, pinNum, modeType);
			}
			else if (modeType >= 0x10){
				
				modeType = modeType - 0x10;
				PinMode->rw_Pin15_Mode = 0x00;
				PinMode->rw_Pin15_Mode = modeType;
			}
			break;
	}
}

uint8_t Pin_GetInput(char port, uint8_t pinNum) {
	
	GPIOx_INPUT *const Input = InputReg_Choice(port);
	
	switch(pinNum) {
	
		case 0 :
			return Input->read_Pin0;
		case 1 :
			return Input->read_Pin1;
		case 2 :
			return Input->read_Pin2;
		case 3 :
			return Input->read_Pin3;
		case 4 :
			return Input->read_Pin4;
		case 5 :
			return Input->read_Pin5;
		case 6 :
			return Input->read_Pin6;
		case 7 :
			return Input->read_Pin7;
		case 8 :
			return Input->read_Pin8;
		case 9 :
			return Input->read_Pin9;
		case 10 :
			return Input->read_Pin10;
		case 11 :
			return Input->read_Pin11;
		case 12 :
			return Input->read_Pin12;
		case 13 :
			return Input->read_Pin13;
		case 14 :
			return Input->read_Pin14;
		case 15 :
			return Input->read_Pin15;
		default :
			return 42;
	}
}

void Pin_Out(char port, uint8_t pinNum, uint8_t pinState) {
	
	GPIOx_OUTPUT *const Output = OutputReg_Choice(port);
	
	switch(pinNum) {
	
		case 0 :
			Output->rw_Pin0_Out = pinState;
			break;
		case 1 :
			Output->rw_Pin1_Out = pinState;
			break;
		case 2 :
			Output->rw_Pin2_Out = pinState;
			break;
		case 3 :
			Output->rw_Pin3_Out = pinState;
			break;
		case 4 :
			Output->rw_Pin4_Out = pinState;
			break;
		case 5 :
			Output->rw_Pin5_Out = pinState;
			break;
		case 6 :
			Output->rw_Pin6_Out = pinState;
			break;
		case 7 :
			Output->rw_Pin7_Out = pinState;
			break;
		case 8 :
			Output->rw_Pin8_Out = pinState;
			break;
		case 9 :
			Output->rw_Pin9_Out = pinState;
			break;
		case 10 :
			Output->rw_Pin10_Out = pinState;
			break;
		case 11 :
			Output->rw_Pin11_Out = pinState;
			break;
		case 12 :
			Output->rw_Pin12_Out = pinState;
			break;
		case 13 :
			Output->rw_Pin13_Out = pinState;
			break;
		case 14 :
			Output->rw_Pin14_Out = pinState;
			break;
		case 15 :
			Output->rw_Pin15_Out = pinState;
			break;
	}
}

void Pin_OutputSpeed(char port, uint8_t pinNum, E_OutSpeeds speed) {
	
	GPIOx_OUTPUTSPEED *const OutSpeed = OutSpeedReg_Choice(port);
	
	switch(pinNum) {
	
		case 0 :
			OutSpeed->rw_Pin0_OutSpeed = speed;
			break;
		case 1 :
			OutSpeed->rw_Pin1_OutSpeed = speed;
			break;
		case 2 :
			OutSpeed->rw_Pin2_OutSpeed = speed;
			break;
		case 3 :
			OutSpeed->rw_Pin3_OutSpeed = speed;
			break;
		case 4 :
			OutSpeed->rw_Pin4_OutSpeed = speed;
			break;
		case 5 :
			OutSpeed->rw_Pin5_OutSpeed = speed;
			break;
		case 6 :
			OutSpeed->rw_Pin6_OutSpeed = speed;
			break;
		case 7 :
			OutSpeed->rw_Pin7_OutSpeed = speed;
			break;
		case 8 :
			OutSpeed->rw_Pin8_OutSpeed = speed;
			break;
		case 9 :
			OutSpeed->rw_Pin9_OutSpeed = speed;
			break;
		case 10 :
			OutSpeed->rw_Pin10_OutSpeed = speed;
			break;
		case 11 :
			OutSpeed->rw_Pin11_OutSpeed = speed;
			break;
		case 12 :
			OutSpeed->rw_Pin12_OutSpeed = speed;
			break;
		case 13 :
			OutSpeed->rw_Pin13_OutSpeed = speed;
			break;
		case 14 :
			OutSpeed->rw_Pin14_OutSpeed = speed;
			break;
		case 15 :
			OutSpeed->rw_Pin15_OutSpeed = speed;
			break;
	}
}

void Pin_PullUp_PullDown(char port, uint8_t pinNum, E_PullUpDown upDown) {
	
	GPIOx_PULLUP_PULLDOWN *const PUpPDwn = PUpPDownReg_Choice(port);
	
	switch(pinNum) {
	
		case 0 :
			PUpPDwn->rw_Pin0_PUp_PDwn = upDown;
			break;
		case 1 :
			PUpPDwn->rw_Pin1_PUp_PDwn = upDown;
			break;
		case 2 :
			PUpPDwn->rw_Pin2_PUp_PDwn = upDown;
			break;
		case 3 :
			PUpPDwn->rw_Pin3_PUp_PDwn = upDown;
			break;
		case 4 :
			PUpPDwn->rw_Pin4_PUp_PDwn = upDown;
			break;
		case 5 :
			PUpPDwn->rw_Pin5_PUp_PDwn = upDown;
			break;
		case 6 :
			PUpPDwn->rw_Pin6_PUp_PDwn = upDown;
			break;
		case 7 :
			PUpPDwn->rw_Pin7_PUp_PDwn = upDown;
			break;
		case 8 :
			PUpPDwn->rw_Pin8_PUp_PDwn = upDown;
			break;
		case 9 :
			PUpPDwn->rw_Pin9_PUp_PDwn = upDown;
			break;
		case 10 :
			PUpPDwn->rw_Pin10_PUp_PDwn = upDown;
			break;
		case 11 :
			PUpPDwn->rw_Pin11_PUp_PDwn = upDown;
			break;
		case 12 :
			PUpPDwn->rw_Pin12_PUp_PDwn = upDown;
			break;
		case 13 :
			PUpPDwn->rw_Pin13_PUp_PDwn = upDown;
			break;
		case 14 :
			PUpPDwn->rw_Pin14_PUp_PDwn = upDown;
			break;
		case 15 :
			PUpPDwn->rw_Pin15_PUp_PDwn = upDown;
			break;
	}
}



//Helper Functions---------------------------------------------------------------------------

static void Pin_AltFunc(char port, uint8_t pinNum, E_PinModes altFunction) {
	
	GPIOx_ALTERNATE_FUNCT_LOW *const PinAltFuncLow = AltLowReg_Choice(port);
	GPIOx_ALTERNATE_FUNCT_HIGH *const PinAltFuncHigh = AltHighReg_Choice(port);
	
	switch(pinNum) {
	
		case 0 :
			PinAltFuncLow->rw_Pin0_AltFunction = altFunction;
			break;
		case 1 :
			PinAltFuncLow->rw_Pin1_AltFunction = altFunction;
			break;
		case 2 :
			PinAltFuncLow->rw_Pin2_AltFunction = altFunction;
			break;
		case 3 :
			PinAltFuncLow->rw_Pin3_AltFunction = altFunction;
			break;
		case 4 :
			PinAltFuncLow->rw_Pin4_AltFunction = altFunction;
			break;
		case 5 :
			PinAltFuncLow->rw_Pin5_AltFunction = altFunction;
			break;
		case 6 :
			PinAltFuncLow->rw_Pin6_AltFunction = altFunction;
			break;
		case 7 :
			PinAltFuncLow->rw_Pin7_AltFunction = altFunction;
			break;
		case 8 :
			PinAltFuncHigh->rw_Pin8_AltFunction = altFunction;
			break;
		case 9 :
			PinAltFuncHigh->rw_Pin9_AltFunction = altFunction;
			break;
		case 10 :
			PinAltFuncHigh->rw_Pin10_AltFunction = altFunction;
			break;
		case 11 :
			PinAltFuncHigh->rw_Pin11_AltFunction = altFunction;
			break;
		case 12 :
			PinAltFuncHigh->rw_Pin12_AltFunction = altFunction;
			break;
		case 13 :
			PinAltFuncHigh->rw_Pin13_AltFunction = altFunction;
			break;
		case 14 :
			PinAltFuncHigh->rw_Pin14_AltFunction = altFunction;
			break;
		case 15 :
			PinAltFuncHigh->rw_Pin15_AltFunction = altFunction;
			break;
	}
}


static void ClockStart_Choice(char port) {
	
	switch (port) {
		
		case 'A' :
			GPIOClock->gpioA_StartTick = 1;
			break;
		case 'B' :
			GPIOClock->gpioB_StartTick = 1;
			break;
		case 'C' :
			GPIOClock->gpioC_StartTick = 1;
			break;
		case 'D' :
			GPIOClock->gpioD_StartTick = 1;
			break;
		case 'E' :
			GPIOClock->gpioE_StartTick = 1;
			break;
		case 'F' :
			GPIOClock->gpioF_StartTick = 1;
			break;
		case 'G' :
			GPIOClock->gpioG_StartTick = 1;
			break;
		case 'H' :
			GPIOClock->gpioH_StartTick = 1;
			break;
		case 'I' :
			GPIOClock->gpioI_StartTick = 1;
			break;
	}
}

static GPIOx_MODE* ModeReg_Choice(char port) {
	
	switch (port) {
		
		case 'A' :
			return A_PinMode;
		
		case 'B' :
			return B_PinMode;
			
		case 'C' :
			return C_PinMode;
		
		case 'D' :
			return D_PinMode;
		
		case 'E' :
			return E_PinMode;
			
		case 'F' :
			return F_PinMode;
		
		case 'G' :
			return G_PinMode;
		
		case 'H' :
			return H_PinMode;
			
		case 'I' :
			return I_PinMode;
		default :
			return NULL;
	}
}


static GPIOx_OUTPUTSPEED* OutSpeedReg_Choice(char port) {
	
	switch (port) {
		
		case 'A' :
			return A_OutSpeed;
		
		case 'B' :
			return B_OutSpeed;
			
		case 'C' :
			return C_OutSpeed;
		
		case 'D' :
			return D_OutSpeed;
		
		case 'E' :
			return E_OutSpeed;
			
		case 'F' :
			return F_OutSpeed;
		
		case 'G' :
			return G_OutSpeed;
		
		case 'H' :
			return H_OutSpeed;
			
		case 'I' :
			return I_OutSpeed;
		default :
			return NULL;
	}
}

static GPIOx_PULLUP_PULLDOWN* PUpPDownReg_Choice(char port) {
	
	switch (port) {
		
		case 'A' :
			return A_PUpPDwn;
		
		case 'B' :
			return B_PUpPDwn;
			
		case 'C' :
			return C_PUpPDwn;
		
		case 'D' :
			return D_PUpPDwn;
		
		case 'E' :
			return E_PUpPDwn;
			
		case 'F' :
			return F_PUpPDwn;
		
		case 'G' :
			return G_PUpPDwn;
		
		case 'H' :
			return H_PUpPDwn;
			
		case 'I' :
			return I_PUpPDwn;
		default :
			return NULL;
	}
}

static GPIOx_INPUT* InputReg_Choice(char port) {
	
	switch (port) {
		
		case 'A' :
			return A_Input;
		
		case 'B' :
			return B_Input;
			
		case 'C' :
			return C_Input;
		
		case 'D' :
			return D_Input;
		
		case 'E' :
			return E_Input;
			
		case 'F' :
			return F_Input;
		
		case 'G' :
			return G_Input;
		
		case 'H' :
			return H_Input;
			
		case 'I' :
			return I_Input;
		default :
			return NULL;
	}
}

static GPIOx_OUTPUT* OutputReg_Choice(char port) {
	
	switch (port) {
		
		case 'A' :
			return A_Output;
		
		case 'B' :
			return B_Output;
			
		case 'C' :
			return C_Output;
		
		case 'D' :
			return D_Output;
		
		case 'E' :
			return E_Output;
			
		case 'F' :
			return F_Output;
		
		case 'G' :
			return G_Output;
		
		case 'H' :
			return H_Output;
			
		case 'I' :
			return I_Output;
		default :
			return NULL;
	}
}

static GPIOx_ALTERNATE_FUNCT_LOW* AltLowReg_Choice(char port) {
	
	switch (port) {
		
		case 'A' :
			return A_PinAltFuncLow;
		
		case 'B' :
			return B_PinAltFuncLow;
			
		case 'C' :
			return C_PinAltFuncLow;
		
		case 'D' :
			return D_PinAltFuncLow;
		
		case 'E' :
			return E_PinAltFuncLow;
			
		case 'F' :
			return F_PinAltFuncLow;
		
		case 'G' :
			return G_PinAltFuncLow;
		
		case 'H' :
			return H_PinAltFuncLow;
			
		case 'I' :
			return I_PinAltFuncLow;
		default :
			return NULL;
	}
}

static GPIOx_ALTERNATE_FUNCT_HIGH* AltHighReg_Choice(char port) {
	
	switch (port) {
		
		case 'A' :
			return A_PinAltFuncHigh;
		
		case 'B' :
			return B_PinAltFuncHigh;
			
		case 'C' :
			return C_PinAltFuncHigh;
		
		case 'D' :
			return D_PinAltFuncHigh;
		
		case 'E' :
			return E_PinAltFuncHigh;
			
		case 'F' :
			return F_PinAltFuncHigh;
		
		case 'G' :
			return G_PinAltFuncHigh;
		
		case 'H' :
			return H_PinAltFuncHigh;
			
		case 'I' :
			return I_PinAltFuncHigh;
		default :
			return NULL;
	}
}
