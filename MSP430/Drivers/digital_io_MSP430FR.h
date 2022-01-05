//MSP430FR59xx Driver
#ifndef DIGITAL_IO_H_
#define DIGITAL_IO_H_
//x69 Series only uses Ports 1,2,3,4 & J

#include <stdint.h>

typedef enum _PinType E_PinType;
typedef enum _FunctionType E_FunctionType;
typedef enum _PullUpDown E_PullUpDown;

void Pin_Init(char port, uint8_t pinNum, E_PinType direction, E_FunctionType function, E_PullUpDown pUppDwn);
uint8_t Pin_GetInput(char port, uint8_t pinNum);
void Pin_Out(char port, uint8_t pinNum, uint8_t pinState);
void Watchdog_Off(void);

#define POWER_MANAGE 0x0120
#define PORT1_2 0x0200
#define PORT3_4 0x0220
#define PORTJ 0x0320

#define WATCHDG 0x15C
#define ADDR_WATCHDOG_CONTROL ( (WATCHDOG_CONTROL*) ((WATCHDG) + 0x00) )

#define ADDR_PORT_UNLOCK ( (PORT_UNLOCK*) ((POWER_MANAGE) + 0x10) ) //Power Management Register

#define ADDR_PORT1_INTERRUPT_VECTOR ( (PORTx_INTERRUPT_VECTOR*) ((PORT1_2) + 0x0E) )
#define ADDR_PORT2_INTERRUPT_VECTOR ( (PORTx_INTERRUPT_VECTOR*) ((PORT1_2) + 0x1E) )
#define ADDR_PORT3_INTERRUPT_VECTOR ( (PORTx_INTERRUPT_VECTOR*) ((PORT3_4) + 0x2E) )
#define ADDR_PORT4_INTERRUPT_VECTOR ( (PORTx_INTERRUPT_VECTOR*) ((PORT3_4) + 0x3E) )
#define ADDR_PORT5_INTERRUPT_VECTOR ( (PORTx_INTERRUPT_VECTOR*) (() + 0x4E) )
#define ADDR_PORT6_INTERRUPT_VECTOR ( (PORTx_INTERRUPT_VECTOR*) (() + 0x5E) )
#define ADDR_PORT7_INTERRUPT_VECTOR ( (PORTx_INTERRUPT_VECTOR*) (() + 0x6E) )
#define ADDR_PORT8_INTERRUPT_VECTOR ( (PORTx_INTERRUPT_VECTOR*) (() + 0x7E) )
#define ADDR_PORT9_INTERRUPT_VECTOR ( (PORTx_INTERRUPT_VECTOR*) (() + 0x8E) )

#define ADDR_PORT1_INPUT ( (PORTx_INPUT*) ((PORT1_2) + 0x00) )
#define ADDR_PORT1_OUTPUT ( (PORTx_OUTPUT*) ((PORT1_2) + 0x02) )
#define ADDR_PORT1_DIRECTION ( (PORTx_DIRECTION*) ((PORT1_2) + 0x04) )
#define ADDR_PORT1_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) ((PORT1_2) + 0x06) )
#define ADDR_PORT1_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) ((PORT1_2) + 0x0A) )
#define ADDR_PORT1_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) ((PORT1_2) + 0x0E) )
#define ADDR_PORT1_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) ((PORT1_2) + 0x16) )
#define ADDR_PORT1_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) ((PORT1_2) + 0x18) )
#define ADDR_PORT1_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) ((PORT1_2) + 0x1A) )
#define ADDR_PORT1_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) ((PORT1_2) + 0x1C) )

#define ADDR_PORT2_INPUT ( (PORTx_INPUT*) ((PORT1_2) + 0x01) )
#define ADDR_PORT2_OUTPUT ( (PORTx_OUTPUT*) ((PORT1_2) + 0x03) )
#define ADDR_PORT2_DIRECTION ( (PORTx_DIRECTION*) ((PORT1_2) + 0x05) )
#define ADDR_PORT2_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) ((PORT1_2) + 0x07) )
#define ADDR_PORT2_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) ((PORT1_2) + 0x0B) )
#define ADDR_PORT2_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) ((PORT1_2) + 0x0D) )
#define ADDR_PORT2_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) ((PORT1_2) + 0x17) )
#define ADDR_PORT2_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) ((PORT1_2) + 0x19) )
#define ADDR_PORT2_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) ((PORT1_2) + 0x1B) )
#define ADDR_PORT2_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) ((PORT1_2) + 0x1D) )

#define ADDR_PORT3_INPUT ( (PORTx_INPUT*) ((PORT3_4) + 0x00) )
#define ADDR_PORT3_OUTPUT ( (PORTx_OUTPUT*) ((PORT3_4) + 0x02) )
#define ADDR_PORT3_DIRECTION ( (PORTx_DIRECTION*) ((PORT3_4) + 0x04) )
#define ADDR_PORT3_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) ((PORT3_4) + 0x06) )
#define ADDR_PORT3_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) ((PORT3_4) + 0x0A) )
#define ADDR_PORT3_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) ((PORT3_4) + 0x0E) )
#define ADDR_PORT3_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) ((PORT3_4) + 0x16) )
#define ADDR_PORT3_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) ((PORT3_4) + 0x18) )
#define ADDR_PORT3_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) ((PORT3_4) + 0x1A) )
#define ADDR_PORT3_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) ((PORT3_4) + 0x1C) )

#define ADDR_PORT4_INPUT ( (PORTx_INPUT*) ((PORT3_4) + 0x01) )
#define ADDR_PORT4_OUTPUT ( (PORTx_OUTPUT*) ((PORT3_4) + 0x03) )
#define ADDR_PORT4_DIRECTION ( (PORTx_DIRECTION*) ((PORT3_4) + 0x05) )
#define ADDR_PORT4_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) ((PORT3_4) + 0x07) )
#define ADDR_PORT4_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) ((PORT3_4) + 0x0B) )
#define ADDR_PORT4_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) ((PORT3_4) + 0x0D) )
#define ADDR_PORT4_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) ((PORT3_4) + 0x17) )
#define ADDR_PORT4_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) ((PORT3_4) + 0x19) )
#define ADDR_PORT4_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) ((PORT3_4) + 0x1B) )
#define ADDR_PORT4_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) ((PORT3_4) + 0x1D) )

/*
#define ADDR_PORT5_INPUT ( (PORTx_INPUT*) (() + 0x00) )
#define ADDR_PORT5_OUTPUT ( (PORTx_OUTPUT*) (() + 0x02) )
#define ADDR_PORT5_DIRECTION ( (PORTx_DIRECTION*) (() + 0x04) )
#define ADDR_PORT5_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) (() + 0x06) )
#define ADDR_PORT5_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) (() + 0x0A) )
#define ADDR_PORT5_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) (() + 0x0E) )
#define ADDR_PORT5_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) (() + 0x16) )
#define ADDR_PORT5_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) (() + 0x18) )
#define ADDR_PORT5_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) (() + 0x1A) )
#define ADDR_PORT5_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) (() + 0x1C) )

#define ADDR_PORT6_INPUT ( (PORTx_INPUT*) (() + 0x01) )
#define ADDR_PORT6_OUTPUT ( (PORTx_OUTPUT*) (() + 0x03) )
#define ADDR_PORT6_DIRECTION ( (PORTx_DIRECTION*) (() + 0x05) )
#define ADDR_PORT6_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) (() + 0x07) )
#define ADDR_PORT6_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) (() + 0x0B) )
#define ADDR_PORT6_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) (() + 0x0D) )
#define ADDR_PORT6_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) (() + 0x17) )
#define ADDR_PORT6_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) (() + 0x19) )
#define ADDR_PORT6_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) (() + 0x1B) )
#define ADDR_PORT6_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) (() + 0x1D) )

#define ADDR_PORT7_INPUT ( (PORTx_INPUT*) (() + 0x00) )
#define ADDR_PORT7_OUTPUT ( (PORTx_OUTPUT*) (() + 0x02) )
#define ADDR_PORT7_DIRECTION ( (PORTx_DIRECTION*) (() + 0x04) )
#define ADDR_PORT7_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) (() + 0x06) )
#define ADDR_PORT7_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) (() + 0x0A) )
#define ADDR_PORT7_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) (() + 0x0E) )
#define ADDR_PORT7_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) (() + 0x16) )
#define ADDR_PORT7_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) (() + 0x18) )
#define ADDR_PORT7_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) (() + 0x1A) )
#define ADDR_PORT7_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) (() + 0x1C) )

#define ADDR_PORT8_INPUT ( (PORTx_INPUT*) (() + 0x01) )
#define ADDR_PORT8_OUTPUT ( (PORTx_OUTPUT*) (() + 0x03) )
#define ADDR_PORT8_DIRECTION ( (PORTx_DIRECTION*) (() + 0x05) )
#define ADDR_PORT8_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) (() + 0x07) )
#define ADDR_PORT8_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) (() + 0x0B) )
#define ADDR_PORT8_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) (() + 0x0D) )
#define ADDR_PORT8_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) (() + 0x17) )
#define ADDR_PORT8_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) (() + 0x19) )
#define ADDR_PORT8_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) (() + 0x1B) )
#define ADDR_PORT8_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) (() + 0x1D) )

#define ADDR_PORT9_INPUT ( (PORTx_INPUT*) (() + 0x00) )
#define ADDR_PORT9_OUTPUT ( (PORTx_OUTPUT*) (() + 0x02) )
#define ADDR_PORT9_DIRECTION ( (PORTx_DIRECTION*) (() + 0x04) )
#define ADDR_PORT9_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) (() + 0x06) )
#define ADDR_PORT9_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) (() + 0x0A) )
#define ADDR_PORT9_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) (() + 0x0E) )
#define ADDR_PORT9_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) (() + 0x16) )
#define ADDR_PORT9_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) (() + 0x18) )
#define ADDR_PORT9_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) (() + 0x1A) )
#define ADDR_PORT9_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) (() + 0x1C) )

#define ADDR_PORT10_INPUT ( (PORTx_INPUT*) (() + 0x01) )
#define ADDR_PORT10_OUTPUT ( (PORTx_OUTPUT*) (() + 0x03) )
#define ADDR_PORT10_DIRECTION ( (PORTx_DIRECTION*) (() + 0x05) )
#define ADDR_PORT10_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) (() + 0x07) )
#define ADDR_PORT10_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) (() + 0x0B) )
#define ADDR_PORT10_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) (() + 0x0D) )
#define ADDR_PORT10_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) (() + 0x17) )
#define ADDR_PORT10_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) (() + 0x19) )
#define ADDR_PORT10_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) (() + 0x1B) )
#define ADDR_PORT10_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) (() + 0x1D) )

#define ADDR_PORT11_INPUT ( (PORTx_INPUT*) (() + 0x00) )
#define ADDR_PORT11_OUTPUT ( (PORTx_OUTPUT*) (() + 0x02) )
#define ADDR_PORT11_DIRECTION ( (PORTx_DIRECTION*) (() + 0x04) )
#define ADDR_PORT11_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) (() + 0x06) )
#define ADDR_PORT11_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) (() + 0x0A) )
#define ADDR_PORT11_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) (() + 0x0E) )
#define ADDR_PORT11_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) (() + 0x16) )
#define ADDR_PORT11_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) (() + 0x18) )
#define ADDR_PORT11_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) (() + 0x1A) )
#define ADDR_PORT11_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) (() + 0x1C) )

#define ADDR_PORTA_INPUT ( (PORTx_INPUT*) (() + 0x00) )
#define ADDR_PORTA_OUTPUT ( (PORTx_OUTPUT*) (() + 0x02) )
#define ADDR_PORTA_DIRECTION ( (PORTx_DIRECTION*) (() + 0x04) )
#define ADDR_PORTA_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) (() + 0x06) )
#define ADDR_PORTA_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) (() + 0x0A) )
#define ADDR_PORTA_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) (() + 0x0E) )
#define ADDR_PORTA_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) (() + 0x16) )
#define ADDR_PORTA_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) (() + 0x18) )
#define ADDR_PORTA_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) (() + 0x1A) )
#define ADDR_PORTA_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) (() + 0x1C) )

#define ADDR_PORTB_INPUT ( (PORTx_INPUT*) (() + 0x00) )
#define ADDR_PORTB_OUTPUT ( (PORTx_OUTPUT*) (() + 0x02) )
#define ADDR_PORTB_DIRECTION ( (PORTx_DIRECTION*) (() + 0x04) )
#define ADDR_PORTB_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) (() + 0x06) )
#define ADDR_PORTB_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) (() + 0x0A) )
#define ADDR_PORTB_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) (() + 0x0E) )
#define ADDR_PORTB_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) (() + 0x16) )
#define ADDR_PORTB_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) (() + 0x18) )
#define ADDR_PORTB_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) (() + 0x1A) )
#define ADDR_PORTB_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) (() + 0x1C) )

#define ADDR_PORTC_INPUT ( (PORTx_INPUT*) (() + 0x00) )
#define ADDR_PORTC_OUTPUT ( (PORTx_OUTPUT*) (() + 0x02) )
#define ADDR_PORTC_DIRECTION ( (PORTx_DIRECTION*) (() + 0x04) )
#define ADDR_PORTC_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) (() + 0x06) )
#define ADDR_PORTC_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) (() + 0x0A) )
#define ADDR_PORTC_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) (() + 0x0E) )
#define ADDR_PORTC_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) (() + 0x16) )
#define ADDR_PORTC_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) (() + 0x18) )
#define ADDR_PORTC_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) (() + 0x1A) )
#define ADDR_PORTC_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) (() + 0x1C) )

#define ADDR_PORTD_INPUT ( (PORTx_INPUT*) (() + 0x00) )
#define ADDR_PORTD_OUTPUT ( (PORTx_OUTPUT*) (() + 0x02) )
#define ADDR_PORTD_DIRECTION ( (PORTx_DIRECTION*) (() + 0x04) )
#define ADDR_PORTD_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) (() + 0x06) )
#define ADDR_PORTD_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) (() + 0x0A) )
#define ADDR_PORTD_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) (() + 0x0E) )
#define ADDR_PORTD_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) (() + 0x16) )
#define ADDR_PORTD_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) (() + 0x18) )
#define ADDR_PORTD_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) (() + 0x1A) )
#define ADDR_PORTD_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) (() + 0x1C) )

#define ADDR_PORTE_INPUT ( (PORTx_INPUT*) (() + 0x00) )
#define ADDR_PORTE_OUTPUT ( (PORTx_OUTPUT*) (() + 0x02) )
#define ADDR_PORTE_DIRECTION ( (PORTx_DIRECTION*) (() + 0x04) )
#define ADDR_PORTE_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) (() + 0x06) )
#define ADDR_PORTE_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) (() + 0x0A) )
#define ADDR_PORTE_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) (() + 0x0E) )
#define ADDR_PORTE_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) (() + 0x16) )
#define ADDR_PORTE_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) (() + 0x18) )
#define ADDR_PORTE_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) (() + 0x1A) )
#define ADDR_PORTE_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) (() + 0x1C) )

#define ADDR_PORTF_INPUT ( (PORTx_INPUT*) (() + 0x00) )
#define ADDR_PORTF_OUTPUT ( (PORTx_OUTPUT*) (() + 0x02) )
#define ADDR_PORTF_DIRECTION ( (PORTx_DIRECTION*) (() + 0x04) )
#define ADDR_PORTF_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) (() + 0x06) )
#define ADDR_PORTF_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) (() + 0x0A) )
#define ADDR_PORTF_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) (() + 0x0E) )
#define ADDR_PORTF_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) (() + 0x16) )
#define ADDR_PORTF_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) (() + 0x18) )
#define ADDR_PORTF_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) (() + 0x1A) )
#define ADDR_PORTF_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) (() + 0x1C) )
*/

#define ADDR_PORTJ_INPUT ( (PORTx_INPUT*) ((PORTJ) + 0x00) )
#define ADDR_PORTJ_OUTPUT ( (PORTx_OUTPUT*) ((PORTJ) + 0x02) )
#define ADDR_PORTJ_DIRECTION ( (PORTx_DIRECTION*) ((PORTJ) + 0x04) )
#define ADDR_PORTJ_PULLUP_PULLDOWN ( (PORTx_PULLUP_PULLDOWN*) ((PORTJ) + 0x06) )
#define ADDR_PORTJ_FUNCTION_SELECT0 ( (PORTx_FUNCTION_SELECT0*) ((PORTJ) + 0x0A) )
#define ADDR_PORTJ_FUNCTION_SELECT1 ( (PORTx_FUNCTION_SELECT1*) ((PORTJ) + 0x0E) )
#define ADDR_PORTJ_FUNCTION_SELECT_COMPLEMENT ( (PORTx_FUNCTION_SELECT_COMPLEMENT*) ((PORTJ) + 0x16) )
#define ADDR_PORTJ_INTERRUPT_EDGE_SELECT ( (PORTx_INTERRUPT_EDGE_SELECT*) ((PORTJ) + 0x18) )
#define ADDR_PORTJ_INTERRUPT_ENABLE ( (PORTx_INTERRUPT_ENABLE*) ((PORTJ) + 0x1A) )
#define ADDR_PORTJ_INTERRUPT_FLAG ( (PORTx_INTERRUPT_FLAG*) ((PORTJ) + 0x1C) )

//Enums----------------------------------------------------------------------
enum _PinType {
	IN = 0,
	OUT = 1,
	NONE = 0
};

enum _FunctionType {
	PRIMARY_F = 1,
	SECONDARY_F = 2,
	TERTIARY_F = 3,
	NO_F = 4
};

enum _PullUpDown {
	P_UP = 1,
	P_DOWN = 2,
	NO_PULL = 4
};

//Registers------------------------------------------------------------------

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

#endif
