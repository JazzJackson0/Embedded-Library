#ifndef NVIC_H_
#define NVIC_H_

#include <stdint.h>
#include <stdlib.h>

typedef enum _NVICRegs  E_NVICRegs;
typedef enum _bit E_Bit;
typedef enum _interruptType E_InterruptType;

typedef struct nvic_generic NVIC_GENERIC; // Can represent ISER, ICER, ISPER, ICPR & IABR


// DECLARATIONS-------------------------------------------------------------------------------------
/**
 * @brief The AUTOMATIC Process: 
 * After The Interrupt is Initialized by the user in the NVIC (i.e. NVICInterruptInit()),
 * When Trigger occurs on given EXTI line and NVIC sees the interrupt is NOT active (from the CHECK_ACTIVE register)
 * The NVIC will set the Interrupt as Pending
 * The Interrupt stays Pending until the processor enters the desired ISR, & Interrupt's state is moved from Pending to Active.
 * 
 * Write the code for the given Interrupt Handler (e.g. EXTI15_10_IRQHandler, USART2_IRQHandler) inside the 'startup.c' file
 * 
 * Important Document for NVIC Info: See 1-Datasheets/STM32/'STM32 M4 Programming Manual.pdf'
 */


/**
 * @brief Check that the given interrupt is active
 * 
 * @param vecTablePos The Vector Table Index of your desired Interrupt
 * @return uint8_t Returns 1 if Active, else 0
 */
uint8_t NVIC_InterruptIsActive(uint8_t vecTablePos);
/**
 * @brief Initialize the desired Interrupt
 * 
 * @param vecTablePos 
 * @param priority 
 * @param type 
 */
void NVICInterruptInit(uint8_t vecTablePos, uint8_t priority, E_InterruptType type);


// NVIC
// // Add (IPR## x 4) to the interrupt# number specified in the struct fields
typedef struct nvic_set_priority SET_PRIORITY_X;

typedef struct _set_as_software SET_AS_SOFTWARE;
#define ADDR_STIR ((SET_AS_SOFTWARE*) 0xE00)

// Needed for SET_SOFTWARE_TRIGGER_X to work
typedef struct _config_ctrl CONFIG_CTRL;
#define ADDR_SCR ((CONFIG_CTRL*) 0x10)


//Enums----------------------------------------------------------------------
enum _NVICRegs {
	ENABLE = 0, DISABLE = 1, SET_PENDING = 2, CLEAR_PENDING = 3, CHECK_ACTIVE = 4
};

enum _bit {
    LOW_BIT = 0, HIGH_BIT = 1
};

enum _interruptType {
    HARDWARE = 0, SOFTWARE = 1
};


//Registers----------------------------------------------------------------------
// NVIC Registers------------------------------------------------------------
struct __attribute__((__packed__)) nvic_generic { // Generic Register that can represent 5 different NVIC regs
	volatile uint32_t interrupt0:1;
	volatile uint32_t interrupt1:1;
	volatile uint32_t interrupt2:1;
	volatile uint32_t interrupt3:1;
	volatile uint32_t interrupt4:1;
	volatile uint32_t interrupt5:1;
	volatile uint32_t interrupt6:1;
	volatile uint32_t interrupt7:1;
	volatile uint32_t interrupt8:1;
	volatile uint32_t interrupt9:1;
	volatile uint32_t interrupt10:1;
	volatile uint32_t interrupt11:1;
	volatile uint32_t interrupt12:1;
	volatile uint32_t interrupt13:1;
	volatile uint32_t interrupt14:1;
	volatile uint32_t interrupt15:1;
	volatile uint32_t interrupt16:1;
	volatile uint32_t interrupt17:1;
	volatile uint32_t interrupt18:1;
	volatile uint32_t interrupt19:1;
	volatile uint32_t interrupt20:1;
	volatile uint32_t interrupt21:1;
	volatile uint32_t interrupt22:1;
	volatile uint32_t interrupt23:1;
	volatile uint32_t interrupt24:1;
	volatile uint32_t interrupt25:1;
	volatile uint32_t interrupt26:1;
	volatile uint32_t interrupt27:1;
	volatile uint32_t interrupt28:1;
	volatile uint32_t interrupt29:1;
	volatile uint32_t interrupt30:1;
	volatile uint32_t interrupt31:1;
};



// Priority range 0-255
struct nvic_set_priority {
	volatile uint32_t interrupt0PriorityByte:8;
	volatile uint32_t interrupt1PriorityByte:8;
	volatile uint32_t interrupt2PriorityByte:8;
	volatile uint32_t interrupt3PriorityByte:8;
};


// Required privilege: When the USERSETMPEND bit in the SCR (i.e. CONFIG_CTRL) is set to 1, unprivileged software can access the STIR
struct _set_as_software {
	volatile uint32_t vecTablePos:8;
	const uint32_t reserved:23;
};

// CONFIG_CTRL Register (Needed for Software Interrupt)--------------------------------------------------------------------------------
struct _config_ctrl {
	const uint32_t threadModeEntranceMethod:1;
	volatile uint32_t enableSoftwareAccessToSTIR:1; // The only Bit that matters here
	const uint32_t reserved0:1;
	volatile uint32_t enableUnalignedAccessTraps:1;
	volatile uint32_t enableFaulting:1;
	const uint32_t reserved1:3;
	volatile uint32_t ignoreDatbusFaults:1;
	volatile uint32_t stackAlignConfig:1;
	const uint32_t reserved2:22;
};





// Old Version---------------------------------------------------------------------------------------------
// typedef struct nvic_set_enable SET_ENABLE_X;
// #define ADDR_NVIC_ISER0 0x100 // Vec Table Pos 0 - 31
// #define ADDR_NVIC_ISER1 0x104 // Vec Table Pos 32 - 63 
// #define ADDR_NVIC_ISER2 0x108
// #define ADDR_NVIC_ISER3 0x10C
// #define ADDR_NVIC_ISER4 0x110
// #define ADDR_NVIC_ISER5 0x114
// #define ADDR_NVIC_ISER6 0x118
// #define ADDR_NVIC_ISER7 0x11C

// typedef struct nvic_clear_enable CLEAR_ENABLE_X;
// #define ADDR_NVIC_ICER0 0x180 // Vec Table Pos 0 - 31
// #define ADDR_NVIC_ICER1 0x184 // Vec Table Pos 32 - 63 
// #define ADDR_NVIC_ICER2 0x188
// #define ADDR_NVIC_ICER3 0x18C
// #define ADDR_NVIC_ICER4 0x190
// #define ADDR_NVIC_ICER5 0x194
// #define ADDR_NVIC_ICER6 0x198
// #define ADDR_NVIC_ICER7 0x19C

// typedef struct nvic_set_pending SET_PENDING_X;
// #define ADDR_NVIC_ISPR0 0x200 // Vec Table Pos 0 - 31
// #define ADDR_NVIC_ISPR1 0x204 // Vec Table Pos 32 - 63 
// #define ADDR_NVIC_ISPR2 0x208
// #define ADDR_NVIC_ISPR3 0x20C
// #define ADDR_NVIC_ISPR4 0x210
// #define ADDR_NVIC_ISPR5 0x214
// #define ADDR_NVIC_ISPR6 0x218
// #define ADDR_NVIC_ISPR7 0x21C

// typedef struct nvic_clear_pending CLEAR_PENDING_X;
// #define ADDR_NVIC_ICPR0 0x280 // Vec Table Pos 0 - 31
// #define ADDR_NVIC_ICPR1 0x284 // Vec Table Pos 32 - 63 
// #define ADDR_NVIC_ICPR2 0x288
// #define ADDR_NVIC_ICPR3 0x28C
// #define ADDR_NVIC_ICPR4 0x290
// #define ADDR_NVIC_ICPR5 0x294
// #define ADDR_NVIC_ICPR6 0x298
// #define ADDR_NVIC_ICPR7 0x29C

// typedef struct nvic_check_active CHECK_ACTIVE_X;
// #define ADDR_NVIC_IABR0 0x300 // Vec Table Pos 0 - 31
// #define ADDR_NVIC_IABR1 0x304 // Vec Table Pos 32 - 63 
// #define ADDR_NVIC_IABR2 0x308
// #define ADDR_NVIC_IABR3 0x30C
// #define ADDR_NVIC_IABR4 0x310
// #define ADDR_NVIC_IABR5 0x314
// #define ADDR_NVIC_IABR6 0x318
// #define ADDR_NVIC_IABR7 0x31C


// #define ADDR_NVIC_IPR0 0x400 // (0 -> 0x0)
// #define ADDR_NVIC_IPR1 0x404 // (4), (5), EXTI0 (Vec Table Pos: 6), EXTI1 (Vec Table Pos: 7)
// #define ADDR_NVIC_IPR2 0x408 // EXTI2 (Vec Table Pos: 8), EXTI3 (Vec Table Pos: 9) EXTI4 (Vec Table Pos: 10)
// #define ADDR_NVIC_IPR3 0x40C
// #define ADDR_NVIC_IPR4 0x410
// #define ADDR_NVIC_IPR5 0x414 // EXTI9_5 (Vec Table Pos: 23)
// #define ADDR_NVIC_IPR6 0x418 
// #define ADDR_NVIC_IPR7 0x41C 
// #define ADDR_NVIC_IPR8 0x420 
// #define ADDR_NVIC_IPR9 0x424 
// #define ADDR_NVIC_IPR10 0x428 // EXT15_10 (Vec Table Pos: 40) (10 -> 0xA)
// #define ADDR_NVIC_IPR11 0x42C
// #define ADDR_NVIC_IPR12 0x430
// #define ADDR_NVIC_IPR13 0x434
// #define ADDR_NVIC_IPR14 0x438
// #define ADDR_NVIC_IPR15 0x43C
// #define ADDR_NVIC_IPR16 0x440
// #define ADDR_NVIC_IPR17 0x444
// #define ADDR_NVIC_IPR18 0x448
// #define ADDR_NVIC_IPR19 0x44C
// #define ADDR_NVIC_IPR20 0x450 // (20 -> 0x14)
// #define ADDR_NVIC_IPR21 0x454
// #define ADDR_NVIC_IPR22 0x458
// #define ADDR_NVIC_IPR23 0x45C
// #define ADDR_NVIC_IPR24 0x460
// #define ADDR_NVIC_IPR25 0x464
// #define ADDR_NVIC_IPR26 0x468
// #define ADDR_NVIC_IPR27 0x46C
// #define ADDR_NVIC_IPR28 0x470
// #define ADDR_NVIC_IPR29 0x474
// #define ADDR_NVIC_IPR30 0x478 // (30 -> 0x1E)
// #define ADDR_NVIC_IPR31 0x47C
// #define ADDR_NVIC_IPR32 0x480
// #define ADDR_NVIC_IPR33 0x484
// #define ADDR_NVIC_IPR34 0x488
// #define ADDR_NVIC_IPR35 0x48C
// #define ADDR_NVIC_IPR36 0x490
// #define ADDR_NVIC_IPR37 0x494
// #define ADDR_NVIC_IPR38 0x498
// #define ADDR_NVIC_IPR39 0x49C
// #define ADDR_NVIC_IPR40 0x4A0  // (40 -> 0x28)
// #define ADDR_NVIC_IPR41 0x4A4
// #define ADDR_NVIC_IPR42 0x4A8
// #define ADDR_NVIC_IPR43 0x4AC
// #define ADDR_NVIC_IPR44 0x4B0
// #define ADDR_NVIC_IPR45 0x4B4
// #define ADDR_NVIC_IPR46 0x4B8
// #define ADDR_NVIC_IPR47 0x4BC
// #define ADDR_NVIC_IPR48 0x4C0
// #define ADDR_NVIC_IPR49 0x4C4
// #define ADDR_NVIC_IPR50 0x4C8 // (50 -> 0x32)
// #define ADDR_NVIC_IPR51 0x4CC
// #define ADDR_NVIC_IPR52 0x4D0
// #define ADDR_NVIC_IPR53 0x4D4
// #define ADDR_NVIC_IPR54 0x4D8
// #define ADDR_NVIC_IPR55 0x4DC
// #define ADDR_NVIC_IPR56 0x4E0
// #define ADDR_NVIC_IPR57 0x4E4
// #define ADDR_NVIC_IPR58 0x4E8
// #define ADDR_NVIC_IPR59 0x4EC


// struct __attribute__((__packed__)) nvic_set_enable { // Interrupt Numbers correspond to Vector Table positions
// 	volatile uint32_t enableInterrupt0:1;
// 	volatile uint32_t enableInterrupt1:1;
// 	volatile uint32_t enableInterrupt2:1;
// 	volatile uint32_t enableInterrupt3:1;
// 	volatile uint32_t enableInterrupt4:1;
// 	volatile uint32_t enableInterrupt5:1;
// 	volatile uint32_t enableInterrupt6:1;
// 	volatile uint32_t enableInterrupt7:1;
// 	volatile uint32_t enableInterrupt8:1;
// 	volatile uint32_t enableInterrupt9:1;
// 	volatile uint32_t enableInterrupt10:1;
// 	volatile uint32_t enableInterrupt11:1;
// 	volatile uint32_t enableInterrupt12:1;
// 	volatile uint32_t enableInterrupt13:1;
// 	volatile uint32_t enableInterrupt14:1;
// 	volatile uint32_t enableInterrupt15:1;
// 	volatile uint32_t enableInterrupt16:1;
// 	volatile uint32_t enableInterrupt17:1;
// 	volatile uint32_t enableInterrupt18:1;
// 	volatile uint32_t enableInterrupt19:1;
// 	volatile uint32_t enableInterrupt20:1;
// 	volatile uint32_t enableInterrupt21:1;
// 	volatile uint32_t enableInterrupt22:1;
// 	volatile uint32_t enableInterrupt23:1;
// 	volatile uint32_t enableInterrupt24:1;
// 	volatile uint32_t enableInterrupt25:1;
// 	volatile uint32_t enableInterrupt26:1;
// 	volatile uint32_t enableInterrupt27:1;
// 	volatile uint32_t enableInterrupt28:1;
// 	volatile uint32_t enableInterrupt29:1;
// 	volatile uint32_t enableInterrupt30:1;
// 	volatile uint32_t enableInterrupt31:1;
// };


// struct __attribute__((__packed__)) nvic_clear_enable {
// 	volatile uint32_t disableInterrupt0:1;
// 	volatile uint32_t disableInterrupt1:1;
// 	volatile uint32_t disableInterrupt2:1;
// 	volatile uint32_t disableInterrupt3:1;
// 	volatile uint32_t disableInterrupt4:1;
// 	volatile uint32_t disableInterrupt5:1;
// 	volatile uint32_t disableInterrupt6:1;
// 	volatile uint32_t disableInterrupt7:1;
// 	volatile uint32_t disableInterrupt8:1;
// 	volatile uint32_t disableInterrupt9:1;
// 	volatile uint32_t disableInterrupt10:1;
// 	volatile uint32_t disableInterrupt11:1;
// 	volatile uint32_t disableInterrupt12:1;
// 	volatile uint32_t disableInterrupt13:1;
// 	volatile uint32_t disableInterrupt14:1;
// 	volatile uint32_t disableInterrupt15:1;
// 	volatile uint32_t disableInterrupt16:1;
// 	volatile uint32_t disableInterrupt17:1;
// 	volatile uint32_t disableInterrupt18:1;
// 	volatile uint32_t disableInterrupt19:1;
// 	volatile uint32_t disableInterrupt20:1;
// 	volatile uint32_t disableInterrupt21:1;
// 	volatile uint32_t disableInterrupt22:1;
// 	volatile uint32_t disableInterrupt23:1;
// 	volatile uint32_t disableInterrupt24:1;
// 	volatile uint32_t disableInterrupt25:1;
// 	volatile uint32_t disableInterrupt26:1;
// 	volatile uint32_t disableInterrupt27:1;
// 	volatile uint32_t disableInterrupt28:1;
// 	volatile uint32_t disableInterrupt29:1;
// 	volatile uint32_t disableInterrupt30:1;
// 	volatile uint32_t disableInterrupt31:1;
// };


// struct __attribute__((__packed__)) nvic_set_pending {
// 	volatile uint32_t setAsPending0:1;
// 	volatile uint32_t setAsPending1:1;
// 	volatile uint32_t setAsPending2:1;
// 	volatile uint32_t setAsPending3:1;
// 	volatile uint32_t setAsPending4:1;
// 	volatile uint32_t setAsPending5:1;
// 	volatile uint32_t setAsPending6:1;
// 	volatile uint32_t setAsPending7:1;
// 	volatile uint32_t setAsPending8:1;
// 	volatile uint32_t setAsPending9:1;
// 	volatile uint32_t setAsPending10:1;
// 	volatile uint32_t setAsPending11:1;
// 	volatile uint32_t setAsPending12:1;
// 	volatile uint32_t setAsPending13:1;
// 	volatile uint32_t setAsPending14:1;
// 	volatile uint32_t setAsPending15:1;
// 	volatile uint32_t setAsPending16:1;
// 	volatile uint32_t setAsPending17:1;
// 	volatile uint32_t setAsPending18:1;
// 	volatile uint32_t setAsPending19:1;
// 	volatile uint32_t setAsPending20:1;
// 	volatile uint32_t setAsPending21:1;
// 	volatile uint32_t setAsPending22:1;
// 	volatile uint32_t setAsPending23:1;
// 	volatile uint32_t setAsPending24:1;
// 	volatile uint32_t setAsPending25:1;
// 	volatile uint32_t setAsPending26:1;
// 	volatile uint32_t setAsPending27:1;
// 	volatile uint32_t setAsPending28:1;
// 	volatile uint32_t setAsPending29:1;
// 	volatile uint32_t setAsPending30:1;
// 	volatile uint32_t setAsPending31:1;
// };


// struct __attribute__((__packed__)) nvic_clear_pending {
// 	volatile uint32_t clearPendingState0:1;
// 	volatile uint32_t clearPendingState1:1;
// 	volatile uint32_t clearPendingState2:1;
// 	volatile uint32_t clearPendingState3:1;
// 	volatile uint32_t clearPendingState4:1;
// 	volatile uint32_t clearPendingState5:1;
// 	volatile uint32_t clearPendingState6:1;
// 	volatile uint32_t clearPendingState7:1;
// 	volatile uint32_t clearPendingState8:1;
// 	volatile uint32_t clearPendingState9:1;
// 	volatile uint32_t clearPendingState10:1;
// 	volatile uint32_t clearPendingState11:1;
// 	volatile uint32_t clearPendingState12:1;
// 	volatile uint32_t clearPendingState13:1;
// 	volatile uint32_t clearPendingState14:1;
// 	volatile uint32_t clearPendingState15:1;
// 	volatile uint32_t clearPendingState16:1;
// 	volatile uint32_t clearPendingState17:1;
// 	volatile uint32_t clearPendingState18:1;
// 	volatile uint32_t clearPendingState19:1;
// 	volatile uint32_t clearPendingState20:1;
// 	volatile uint32_t clearPendingState21:1;
// 	volatile uint32_t clearPendingState22:1;
// 	volatile uint32_t clearPendingState23:1;
// 	volatile uint32_t clearPendingState24:1;
// 	volatile uint32_t clearPendingState25:1;
// 	volatile uint32_t clearPendingState26:1;
// 	volatile uint32_t clearPendingState27:1;
// 	volatile uint32_t clearPendingState28:1;
// 	volatile uint32_t clearPendingState29:1;
// 	volatile uint32_t clearPendingState30:1;
// 	volatile uint32_t clearPendingState31:1;
// };


// struct __attribute__((__packed__)) nvic_check_active {
// 	volatile uint32_t _0isActive:1;
// 	volatile uint32_t _1isActive:1;
// 	volatile uint32_t _2isActive:1;
// 	volatile uint32_t _3isActive:1;
// 	volatile uint32_t _4isActive:1;
// 	volatile uint32_t _5isActive:1;
// 	volatile uint32_t _6isActive:1;
// 	volatile uint32_t _7isActive:1;
// 	volatile uint32_t _8isActive:1;
// 	volatile uint32_t _9isActive:1;
// 	volatile uint32_t _10isActive:1;
// 	volatile uint32_t _11isActive:1;
// 	volatile uint32_t _12isActive:1;
// 	volatile uint32_t _13isActive:1;
// 	volatile uint32_t _14isActive:1;
// 	volatile uint32_t _15isActive:1;
// 	volatile uint32_t _16isActive:1;
// 	volatile uint32_t _17isActive:1;
// 	volatile uint32_t _18isActive:1;
// 	volatile uint32_t _19isActive:1;
// 	volatile uint32_t _20isActive:1;
// 	volatile uint32_t _21isActive:1;
// 	volatile uint32_t _22isActive:1;
// 	volatile uint32_t _23isActive:1;
// 	volatile uint32_t _24isActive:1;
// 	volatile uint32_t _25isActive:1;
// 	volatile uint32_t _26isActive:1;
// 	volatile uint32_t _27isActive:1;
// 	volatile uint32_t _28isActive:1;
// 	volatile uint32_t _29isActive:1;
// 	volatile uint32_t _30isActive:1;
// 	volatile uint32_t _31isActive:1;
// };

#endif