//MSP430FR59xx Driver
#ifndef DIGITAL_IO_H_
#define DIGITAL_IO_H_
//x69 Series only uses Ports 1,2,3,4 & J

#include <stdint.h>

typedef enum _PinType E_PinType;
typedef enum _FunctionType E_FunctionType;
typedef enum _PullUpDown E_PullUpDown;

 //DECLARATIONS
/**
 * @brief 
 * 
 * @param port 
 * @param pinNum 
 * @param direction 
 * @param function 
 * @param pUppDwn 
 * @return ** void 
 */
void Pin_Init(char port, uint8_t pinNum, E_PinType direction, E_FunctionType function, E_PullUpDown pUppDwn);
/**
 * @brief 
 * 
 * @param port 
 * @param pinNum 
 * @return ** uint8_t 
 */
uint8_t Pin_GetInput(char port, uint8_t pinNum);
/**
 * @brief 
 * 
 * @param port 
 * @param pinNum 
 * @param pinState 
 * @return ** void 
 */
void Pin_Out(char port, uint8_t pinNum, uint8_t pinState);

//IO PORTS
typedef struct _ports PORTSx;
typedef struct _int_vectors INTERRUPT_VECTORS;
#define POWER_MANAGE 0x0120
#define WATCHDG 0x15C
#define INT_VECTORS_BASE 0x0 //	WHAT IS THE BASE ADDRESS FOR THIS???	
#define PORT_BASES1_4 0x200 //Not actually sure which ports 0x200 covers
#define PORT_BASESA_J 0x300 //Not actually sure which ports 0x300 covers
//-----------------
#define ADDR_PORT1 ( (PORTSx*) ((PORT_BASES1_4) + 0x00) )
#define ADDR_PORT2 ( (PORTSx*) ((PORT_BASES1_4) + 0x01) )
#define ADDR_PORT3 ( (PORTSx*) ((PORT_BASES1_4) + 0x20) )
#define ADDR_PORT4 ( (PORTSx*) ((PORT_BASES1_4) + 0x21) )
#define ADDR_PORTJ ( (PORTSx*) ((PORT_BASESA_J) + 0x20) )
/*
#define ADDR_PORT5 ( (ODD_PORTSx*) ((PORT_BASES1_4) + 0x00) )
#define ADDR_PORT6 ( (EVEN_PORTSx*) ((PORT_BASES1_4) + 0x01) )
#define ADDR_PORT7 ( (ODD_PORTSx*) ((PORT_BASES1_4) + 0x00) )
#define ADDR_PORT8 ( (EVEN_PORTSx*) ((PORT_BASES1_4) + 0x01) )
#define ADDR_PORT9 ( (ODD_PORTSx*) ((PORT_BASES1_4) + 0x00) )
#define ADDR_PORT10 ( (EVEN_PORTSx*) ((PORT_BASES1_4) + 0x01) )
#define ADDR_PORT11 ( (ODD_PORTSx*) ((PORT_BASES1_4) + 0x00) )
#define ADDR_PORTA ( (EVEN_PORTSx*) ((PORT_BASES1_4) + 0x00) )
#define ADDR_PORTB ( (EVEN_PORTSx*) ((PORT_BASES1_4) + 0x00) )
#define ADDR_PORTC ( (EVEN_PORTSx*) ((PORT_BASES1_4) + 0x00) )
#define ADDR_PORTD ( (EVEN_PORTSx*) ((PORT_BASES1_4) + 0x00) )
#define ADDR_PORTE ( (EVEN_PORTSx*) ((PORT_BASES1_4) + 0x00) )
#define ADDR_PORTF ( (EVEN_PORTSx*) ((PORT_BASES1_4) + 0x00) )
#define ADDR_PORTG ( (EVEN_PORTSx*) ((PORT_BASES1_4) + 0x00) )
#define ADDR_PORTH ( (EVEN_PORTSx*) ((PORT_BASES1_4) + 0x00) )
#define ADDR_PORTI ( (EVEN_PORTSx*) ((PORT_BASES1_4) + 0x00) )*/
#define ADDR_WATCHDOG_CONTROL ( (WATCHDOG_CONTROL*) ((WATCHDG) + 0x00) )
#define ADDR_PORT_UNLOCK ( (PORT_UNLOCK*) ((POWER_MANAGE) + 0x10) ) //Power Management Register
#define ADDR_INT_VECTORS ( (INTERRUPT_VECTORS*) ((INT_VECTORS_BASE) + 0x0E) )

//Enums----------------------------------------------------------------------
enum _PinType {
	IN = 0, OUT = 1, NONE = 0
};

enum _FunctionType {
	PRIMARY_F = 1, SECONDARY_F = 2, TERTIARY_F = 3,
	NO_F = 4
};

enum _PullUpDown {
	P_UP = 1, P_DOWN = 2, NO_PULL = 4
};

//Registers------------------------------------------------------------------
typedef struct {
	const uint16_t reserved:16;
}IO_RESERVED;

typedef struct {
	const uint8_t reserved:8;
}IO_RESERVED_8;

typedef struct {
	volatile uint16_t select_TimerInterval:3;
	volatile uint16_t clear_CountValue:1;
	volatile uint16_t watchdogMode0_intervalTimerMode1:1;
	volatile uint16_t select_ClockSource:2;
	volatile uint16_t stop_WatchdogTimer:1;
	volatile uint16_t rw_WatchdogTimerPassword:8;
}WATCHDOG_CONTROL;


typedef struct {
	volatile uint16_t clearBitToUnlockIOPorts:1;
    const uint16_t reserved:15;
}PORT_UNLOCK;


typedef struct {
	volatile uint16_t read_HighestPriorityInterruptPending:1;
}PORTx_INTERRUPT_VECTOR;

typedef struct {
	volatile uint8_t read_Pin0:1;
	volatile uint8_t read_Pin1:1;
	volatile uint8_t read_Pin2:1;
	volatile uint8_t read_Pin3:1;
	volatile uint8_t read_Pin4:1;
	volatile uint8_t read_Pin5:1;
	volatile uint8_t read_Pin6:1;
	volatile uint8_t read_Pin7:1;
}PORTx_INPUT;

typedef struct {
	volatile uint8_t p0_LowOrPullDwn0_HighOrPullUp1:1;
	volatile uint8_t p1_LowOrPullDwn0_HighOrPullUp1:1;
	volatile uint8_t p2_LowOrPullDwn0_HighOrPullUp1:1;
	volatile uint8_t p3_LowOrPullDwn0_HighOrPullUp1:1;
	volatile uint8_t p4_LowOrPullDwn0_HighOrPullUp1:1;
	volatile uint8_t p5_LowOrPullDwn0_HighOrPullUp1:1;
	volatile uint8_t p6_LowOrPullDwn0_HighOrPullUp1:1;
	volatile uint8_t p7_LowOrPullDwn0_HighOrPullUp1:1;
}PORTx_OUTPUT;

typedef struct {
	volatile uint8_t p0_InMode0_OutMode1:1;
	volatile uint8_t p1_InMode0_OutMode1:1;
	volatile uint8_t p2_InMode0_OutMode1:1;
	volatile uint8_t p3_InMode0_OutMode1:1;
	volatile uint8_t p4_InMode0_OutMode1:1;
	volatile uint8_t p5_InMode0_OutMode1:1;
	volatile uint8_t p6_InMode0_OutMode1:1;
	volatile uint8_t p7_InMode0_OutMode1:1;
}PORTx_DIRECTION;

typedef struct {
	volatile uint8_t enable_PullUpPullDwnPin0:1;
	volatile uint8_t enable_PullUpPullDwnPin1:1;
	volatile uint8_t enable_PullUpPullDwnPin2:1;
	volatile uint8_t enable_PullUpPullDwnPin3:1;
	volatile uint8_t enable_PullUpPullDwnPin4:1;
	volatile uint8_t enable_PullUpPullDwnPin5:1;
	volatile uint8_t enable_PullUpPullDwnPin6:1;
	volatile uint8_t enable_PullUpPullDwnPin7:1;
}PORTx_PULLUP_PULLDOWN;

typedef struct {
	volatile uint8_t pin0_ModuleFunctionSelectBit0:1;
	volatile uint8_t pin1_ModuleFunctionSelectBit0:1;
	volatile uint8_t pin2_ModuleFunctionSelectBit0:1;
	volatile uint8_t pin3_ModuleFunctionSelectBit0:1;
	volatile uint8_t pin4_ModuleFunctionSelectBit0:1;
	volatile uint8_t pin5_ModuleFunctionSelectBit0:1;
	volatile uint8_t pin6_ModuleFunctionSelectBit0:1;
	volatile uint8_t pin7_ModuleFunctionSelectBit0:1;
}PORTx_FUNCTION_SELECT0;

typedef struct {
	volatile uint8_t pin0_ModuleFunctionSelectBit1:1;
	volatile uint8_t pin1_ModuleFunctionSelectBit1:1;
	volatile uint8_t pin2_ModuleFunctionSelectBit1:1;
	volatile uint8_t pin3_ModuleFunctionSelectBit1:1;
	volatile uint8_t pin4_ModuleFunctionSelectBit1:1;
	volatile uint8_t pin5_ModuleFunctionSelectBit1:1;
	volatile uint8_t pin6_ModuleFunctionSelectBit1:1;
	volatile uint8_t pin7_ModuleFunctionSelectBit1:1;
}PORTx_FUNCTION_SELECT1;

typedef struct {
	volatile uint8_t p0_SetSelect0AndSelect1:1;
	volatile uint8_t p1_SetSelect0AndSelect1:1;
	volatile uint8_t p2_SetSelect0AndSelect1:1;
	volatile uint8_t p3_SetSelect0AndSelect1:1;
	volatile uint8_t p4_SetSelect0AndSelect1:1;
	volatile uint8_t p5_SetSelect0AndSelect1:1;
	volatile uint8_t p6_SetSelect0AndSelect1:1;
	volatile uint8_t p7_SetSelect0AndSelect1:1;
}PORTx_FUNCTION_SELECT_COMPLEMENT;

typedef struct {
	volatile uint8_t p0_interruptRiseEdge0_interruptFallEdge1:1;
	volatile uint8_t p1_interruptRiseEdge0_interruptFallEdge1:1;
	volatile uint8_t p2_interruptRiseEdge0_interruptFallEdge1:1;
	volatile uint8_t p3_interruptRiseEdge0_interruptFallEdge1:1;
	volatile uint8_t p4_interruptRiseEdge0_interruptFallEdge1:1;
	volatile uint8_t p5_interruptRiseEdge0_interruptFallEdge1:1;
	volatile uint8_t p6_interruptRiseEdge0_interruptFallEdge1:1;
	volatile uint8_t p7_interruptRiseEdge0_interruptFallEdge1:1;
}PORTx_INTERRUPT_EDGE_SELECT;

typedef struct {
	volatile uint8_t enable_InterruptPin0:1;
	volatile uint8_t enable_InterruptPin1:1;
	volatile uint8_t enable_InterruptPin2:1;
	volatile uint8_t enable_InterruptPin3:1;
	volatile uint8_t enable_InterruptPin4:1;
	volatile uint8_t enable_InterruptPin5:1;
	volatile uint8_t enable_InterruptPin6:1;
	volatile uint8_t enable_InterruptPin7:1;
}PORTx_INTERRUPT_ENABLE;

typedef struct {
	volatile uint8_t p0_InterruptOccurred:1;
	volatile uint8_t p1_InterruptOccurred:1;
	volatile uint8_t p2_InterruptOccurred:1;
	volatile uint8_t p3_InterruptOccurred:1;
	volatile uint8_t p4_InterruptOccurred:1;
	volatile uint8_t p5_InterruptOccurred:1;
	volatile uint8_t p6_InterruptOccurred:1;
	volatile uint8_t p7_InterruptOccurred:1;
}PORTx_INTERRUPT_FLAG;

typedef struct {
	IO_RESERVED reserved0; //Hex Size 0x02
	IO_RESERVED reserved1; //Hex Size 0x02
	IO_RESERVED reserved2; //...etc
	IO_RESERVED reserved3; 
	IO_RESERVED reserved4; 
	IO_RESERVED reserved5;
	IO_RESERVED reserved6; 
	IO_RESERVED reserved7; 
	IO_RESERVED reserved8; 
}RESERVED_HEFTY;

struct _ports {
	PORTx_INPUT InputReg; // Odd Ports: 0x00 | Even Ports: 0x01
	IO_RESERVED_8 reserved0; // 0x01 | 0x02
	PORTx_OUTPUT OutputReg; // Odd Ports: 0x02 | Even Ports: 0x03
	IO_RESERVED_8 reserved1; // 0x03 | 0x04
	PORTx_DIRECTION DirectionReg; // Odd Ports: 0x04 | Even Ports: 0x05
	IO_RESERVED_8 reserved2; // 0x05 | 0x06
	PORTx_PULLUP_PULLDOWN PullUpPullDownReg; // Odd Ports: 0x06 | Even Ports: 0x07
	IO_RESERVED_8 reserved3; // 0x07 | 0x08
	IO_RESERVED reserved4; // 0x08 | 0x09
	PORTx_FUNCTION_SELECT0 FunctionSelect0Reg; // Odd Ports: 0x0A | Even Ports: 0x0B
	IO_RESERVED_8 reserved5; // 0x0B | 0x0C
	PORTx_FUNCTION_SELECT1 FunctionSelect1Reg; // Odd Ports: 0x0C | Even Ports: 0xD
	IO_RESERVED reserved6; // 0x0E | 0x0F
	IO_RESERVED reserved7; // 0x10 | 0x11
	IO_RESERVED reserved8; // 0x12 | 0x13
	IO_RESERVED reserved9; // 0x14 | 0x15
	PORTx_FUNCTION_SELECT_COMPLEMENT FunctionSelectComplementReg; // Odd Ports: 0x16 | Even Ports: 0x17
	IO_RESERVED_8 reserved10; // 0x17 | 0x18
	PORTx_INTERRUPT_EDGE_SELECT EdgeSelectReg; // Odd Ports: 0x18 | Even Ports: 0x19
	PORTx_INTERRUPT_ENABLE InterruptEnableReg; // Odd Ports: 0x1A | Even Ports: 0x1B
	PORTx_INTERRUPT_FLAG InterruptFlagReg; // Odd Ports: 0x1C | Even Ports: 0x1D
};


struct _int_vectors {
	PORTx_INTERRUPT_VECTOR Port1InterruptVectorReg; // 0x0E
	RESERVED_HEFTY reserved0;
	PORTx_INTERRUPT_VECTOR Port2InterruptVectorReg; // 0x1E
	RESERVED_HEFTY reserved1;
	PORTx_INTERRUPT_VECTOR Port3InterruptVectorReg; // 0x2E
	RESERVED_HEFTY reserved2;
	PORTx_INTERRUPT_VECTOR Port4InterruptVectorReg; // 0x3E
	RESERVED_HEFTY reserved3;
	PORTx_INTERRUPT_VECTOR Port5InterruptVectorReg; // 0x4E
	RESERVED_HEFTY reserved4;
	PORTx_INTERRUPT_VECTOR Port6InterruptVectorReg; // 0x5E
	RESERVED_HEFTY reserved5;
	PORTx_INTERRUPT_VECTOR Port7InterruptVectorReg; // 0x6E
	RESERVED_HEFTY reserved6;
	PORTx_INTERRUPT_VECTOR Port8InterruptVectorReg; // 0x7E
	RESERVED_HEFTY reserved7;
	PORTx_INTERRUPT_VECTOR Port9InterruptVectorReg; // 0x8E
};



#endif
