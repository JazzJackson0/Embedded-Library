#include "STM32F407.NVIC.h"

//Static Prototypes---------------------------------------------
static uint8_t SetInterruptBit(NVIC_GENERIC *generic, E_NVICRegs regType, uint8_t offset, uint8_t vecTablePos, E_Bit bit);
static uint8_t EditInterrupt(uint8_t vecTablePos, E_NVICRegs regType);
static void SetInterruptPriority(uint8_t vecTablePos, uint8_t priority);

//Global Variables------------------------------------------------
NVIC_GENERIC* addresses[5][8] = {{(NVIC_GENERIC*)0x100, (NVIC_GENERIC*)0x104, (NVIC_GENERIC*)0x108, (NVIC_GENERIC*)0x10C, 
                            (NVIC_GENERIC*)0x110, (NVIC_GENERIC*)0x114, (NVIC_GENERIC*)0x118, (NVIC_GENERIC*)0x11C}, // ISER0 - ISER7
                            {(NVIC_GENERIC*)0x180, (NVIC_GENERIC*)0x184, (NVIC_GENERIC*)0x188, (NVIC_GENERIC*)0x18C, 
                            (NVIC_GENERIC*)0x190, (NVIC_GENERIC*)0x194, (NVIC_GENERIC*)0x198, (NVIC_GENERIC*)0x19C}, // ICER0 - ICER7
                            {(NVIC_GENERIC*)0x200, (NVIC_GENERIC*)0x204, (NVIC_GENERIC*)0x208, (NVIC_GENERIC*)0x20C, 
                            (NVIC_GENERIC*)0x210, (NVIC_GENERIC*)0x214, (NVIC_GENERIC*)0x218, (NVIC_GENERIC*)0x21C}, // ISPR0 - ISPR7
                            {(NVIC_GENERIC*)0x280, (NVIC_GENERIC*)0x284, (NVIC_GENERIC*)0x288, (NVIC_GENERIC*)0x28C, 
                            (NVIC_GENERIC*)0x290, (NVIC_GENERIC*)0x294, (NVIC_GENERIC*)0x298, (NVIC_GENERIC*)0x29C}, // ICPR0 - ICPR7
                            {(NVIC_GENERIC*)0x300, (NVIC_GENERIC*)0x304, (NVIC_GENERIC*)0x308, (NVIC_GENERIC*)0x30C, 
                            (NVIC_GENERIC*)0x310, (NVIC_GENERIC*)0x314, (NVIC_GENERIC*)0x318, (NVIC_GENERIC*)0x31C}}; // IABR0 - IABR7

SET_PRIORITY_X* priority_addresses[60] ={ // IPR0 - IPR59 (4 Interrupts per Register)
(SET_PRIORITY_X*)0x400, (SET_PRIORITY_X*)0x404, (SET_PRIORITY_X*)0x408, (SET_PRIORITY_X*)0x40C, (SET_PRIORITY_X*)0x410, 
(SET_PRIORITY_X*)0x414, (SET_PRIORITY_X*)0x418, (SET_PRIORITY_X*)0x41C, (SET_PRIORITY_X*)0x420, (SET_PRIORITY_X*)0x424, 
(SET_PRIORITY_X*)0x428, (SET_PRIORITY_X*)0x42C, (SET_PRIORITY_X*)0x430, (SET_PRIORITY_X*)0x434, (SET_PRIORITY_X*)0x438,
(SET_PRIORITY_X*)0x43C, (SET_PRIORITY_X*)0x440, (SET_PRIORITY_X*)0x444, (SET_PRIORITY_X*)0x448, (SET_PRIORITY_X*)0x44C, 
(SET_PRIORITY_X*)0x450, (SET_PRIORITY_X*)0x454, (SET_PRIORITY_X*)0x458, (SET_PRIORITY_X*)0x45C, (SET_PRIORITY_X*)0x460, 
(SET_PRIORITY_X*)0x464, (SET_PRIORITY_X*)0x468, (SET_PRIORITY_X*)0x46C, (SET_PRIORITY_X*)0x470, (SET_PRIORITY_X*)0x474,
(SET_PRIORITY_X*)0x478, (SET_PRIORITY_X*)0x47C, (SET_PRIORITY_X*)0x480, (SET_PRIORITY_X*)0x484, (SET_PRIORITY_X*)0x488, 
(SET_PRIORITY_X*)0x48C, (SET_PRIORITY_X*)0x490, (SET_PRIORITY_X*)0x494, (SET_PRIORITY_X*)0x498, (SET_PRIORITY_X*)0x49C, 
(SET_PRIORITY_X*)0x4A0, (SET_PRIORITY_X*)0x4A4, (SET_PRIORITY_X*)0x4A8, (SET_PRIORITY_X*)0x4AC, (SET_PRIORITY_X*)0x4B0,
(SET_PRIORITY_X*)0x4B4, (SET_PRIORITY_X*)0x4B8, (SET_PRIORITY_X*)0x4BC, (SET_PRIORITY_X*)0x4C0, (SET_PRIORITY_X*)0x4C4, 
(SET_PRIORITY_X*)0x4C8, (SET_PRIORITY_X*)0x4CC, (SET_PRIORITY_X*)0x4D0, (SET_PRIORITY_X*)0x4D4, (SET_PRIORITY_X*)0x4D8, 
(SET_PRIORITY_X*)0x4DC, (SET_PRIORITY_X*)0x4E0, (SET_PRIORITY_X*)0x4E4, (SET_PRIORITY_X*)0x4E8, (SET_PRIORITY_X*)0x4EC};

// Set-Software-Trigger Register
SET_AS_SOFTWARE *const SOFTWARE_SET = ADDR_STIR;
CONFIG_CTRL *const CONFIG_CONTROL = ADDR_SCR;

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
//------------------------------------------------------------------------------------------

uint8_t NVIC_InterruptIsActive(uint8_t vecTablePos) {
    return EditInterrupt(vecTablePos, CHECK_ACTIVE);
}

void NVICInterruptInit(uint8_t vecTablePos, uint8_t priority, E_InterruptType type) {

    if (type == SOFTWARE) {
        CONFIG_CONTROL->enableSoftwareAccessToSTIR = 1;
        SOFTWARE_SET->vecTablePos = vecTablePos;
    }

    EditInterrupt(vecTablePos, ENABLE); // Enable Interrupt
    SetInterruptPriority(vecTablePos, priority); 
    EditInterrupt(vecTablePos, CLEAR_PENDING); // To ignore any previous events 
}


// Helpers---------------------------------------------------------------------------------------
/**
 * @brief Handles 5 main Interrupt Registers
 * 
 * @param generic One of the register address
 * @param regType The type of register
 * @param offset 
 * @param vecTablePos The interrupt's position on the vector table
 * @param bit bit to be written to the given register
 * @return uint8_t 
 */
static uint8_t SetInterruptBit(NVIC_GENERIC *generic, E_NVICRegs regType, uint8_t offset, uint8_t vecTablePos, E_Bit bit) {


    switch ((vecTablePos - offset)) {
        case 0:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt0;
            return generic->interrupt0 = bit;
        case 1:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt1;
            return generic->interrupt1 = bit;
        case 2:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt2;
            return generic->interrupt2 = bit;
        case 3:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt3;
            return generic->interrupt3 = bit;
        case 4:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt4;
            return generic->interrupt4 = bit;
        case 5:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt5;
            return generic->interrupt5 = bit;
        case 6:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt6;
            return generic->interrupt6 = bit;
        case 7:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt7;
            return generic->interrupt7 = bit;
        case 8:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt8;
            return generic->interrupt8 = bit;
        case 9:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt9;
            return generic->interrupt9 = bit;
        case 10:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt10;
            return generic->interrupt10 = bit;
        case 11:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt11;
            return generic->interrupt11 = bit;
        case 12:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt12;
            return generic->interrupt12 = bit;
        case 13:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt13;
            return generic->interrupt13 = bit;
        case 14:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt14;
            return generic->interrupt14 = bit;
        case 15:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt15;
            return generic->interrupt15 = bit;
        case 16:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt16;
            return generic->interrupt16 = bit;
        case 17:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt17;
            return generic->interrupt17 = bit;
        case 18:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt18;
            return generic->interrupt18 = bit;
        case 19:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt19;
            return generic->interrupt19 = bit;
        case 20:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt20;
            return generic->interrupt20 = bit;
        case 21:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt21;
            return generic->interrupt21 = bit;
        case 22:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt22;
            return generic->interrupt22 = bit;
        case 23:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt23;
            return generic->interrupt23 = bit;
        case 24:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt24;
            return generic->interrupt24 = bit;
        case 25:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt25;
            return generic->interrupt25 = bit;
        case 26:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt26;
            return generic->interrupt26 = bit;
        case 27:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt27;
            return generic->interrupt27 = bit;
        case 28:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt28;
            return generic->interrupt28 = bit;
        case 29:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt29;
            return generic->interrupt29 = bit;
        case 30:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt30;
            return generic->interrupt30 = bit;
        case 31:
            if (regType == CHECK_ACTIVE)
                return generic->interrupt31;
            return generic->interrupt31 = bit;   
        default:
            break;
    }
}


static uint8_t EditInterrupt(uint8_t vecTablePos, E_NVICRegs regType) {
    
    int col = 0; // Default: ENABLE (ISER) reg

    if (regType == DISABLE) {
        col = 1;
    }
    else if (regType == SET_PENDING) {
        col = 2;
    }
    else if (regType == CLEAR_PENDING) {
        col = 3;
    }
    else if (regType == CHECK_ACTIVE) {
        col = 4;
    }

    // NOTE: PLUS_x: Means -> Interrupt Number = (Register bit number + x) 

    if (vecTablePos >= 0 && vecTablePos < 32) {
        NVIC_GENERIC *const PLUS_0 = addresses[col][0]; 
        return SetInterruptBit(PLUS_0, ENABLE, 0, vecTablePos, HIGH_BIT);
    }
        
    else if (vecTablePos >= 32 && vecTablePos < 64) {
        NVIC_GENERIC *const PLUS_32 = addresses[col][1];
        return SetInterruptBit(PLUS_32, ENABLE, 32, vecTablePos, HIGH_BIT);
    }
        
    else if (vecTablePos >= 64 && vecTablePos < 96) {
        NVIC_GENERIC *const PLUS_64 = addresses[col][2];
        return SetInterruptBit(PLUS_64, ENABLE, 64, vecTablePos, HIGH_BIT);
    }
        
    else if (vecTablePos >= 96 && vecTablePos < 128) {
        NVIC_GENERIC *const PLUS_96 = addresses[col][3];
        return SetInterruptBit(PLUS_96, ENABLE, 96, vecTablePos, HIGH_BIT);
    }
        
    else if (vecTablePos >= 128 && vecTablePos < 160) {
        NVIC_GENERIC *const PLUS_128 = addresses[col][4];
        return SetInterruptBit(PLUS_128, ENABLE, 128, vecTablePos, HIGH_BIT);
    }
        
    else if (vecTablePos >= 160 && vecTablePos < 192) {
        NVIC_GENERIC *const PLUS_160 = addresses[col][5];
        return SetInterruptBit(PLUS_160, ENABLE, 160, vecTablePos, HIGH_BIT);
    }
        
    else if (vecTablePos >= 192 && vecTablePos < 224) {
        NVIC_GENERIC *const PLUS_192 = addresses[col][6];
        return SetInterruptBit(PLUS_192, ENABLE, 192, vecTablePos, HIGH_BIT);
    }
        
    else if (vecTablePos >= 224 && vecTablePos < 256) {
        NVIC_GENERIC *const PLUS_224 = addresses[col][7];
        return SetInterruptBit(PLUS_224, ENABLE, 224, vecTablePos, HIGH_BIT);
    }
        
    return -1;
}


static void SetInterruptPriority(uint8_t vecTablePos, uint8_t priority) {
    
    // Obtain corect Priority Register (0 - 59)
    SET_PRIORITY_X * priorityReg = priority_addresses[(vecTablePos / 4)];

    switch((vecTablePos % 4)) {
        case 0:
            priorityReg->interrupt0PriorityByte = priority;
        case 1:
            priorityReg->interrupt1PriorityByte = priority;
        case 2:
            priorityReg->interrupt2PriorityByte = priority;
        case 3:
            priorityReg->interrupt3PriorityByte = priority;
    }
}




