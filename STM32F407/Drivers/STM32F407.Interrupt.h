//STM32F407 Driver
#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include <stdint.h>
/*Interrupt Pins ---------------------------
		+ No Alternate Function Assignments Needed
			(Just use the Registers)
		------------------------------------*/

#include <stdint.h>
//Do Interrupts Even Need a Clock Source? There is Nothing in APB2
//#define CLOCK 0x40023800
//#define APB2 0x44
//#define INTERRUPT_CLOCK ( (INTERRUPT_CLOCK*) ((CLOCK) + APB2) )
/*
typedef struct {
	volatile uint32_t :1;
	const uint32_t reserved1:2;
}INTERRUPT_CLOCK;
*/

//INTERRUPTS
typedef struct _exti EXTIx;
#define EXTI_BASE 0x40013C00
#define ADDR_EXTI ( (EXTIx*) (EXTI_BASE) )




//Registers----------------------------------------------------------------------
typedef struct {
	volatile uint32_t unmask_Line0InterruptRequest:1;
	volatile uint32_t unmask_Line1InterruptRequest:1;
	volatile uint32_t unmask_Line2InterruptRequest:1;
	volatile uint32_t unmask_Line3InterruptRequest:1;
	volatile uint32_t unmask_Line4InterruptRequest:1;
	volatile uint32_t unmask_Line5InterruptRequest:1;
	volatile uint32_t unmask_Line6InterruptRequest:1;
	volatile uint32_t unmask_Line7InterruptRequest:1;
	volatile uint32_t unmask_Line8InterruptRequest:1;
	volatile uint32_t unmask_Line9InterruptRequest:1;
	volatile uint32_t unmask_Line10InterruptRequest:1;
	volatile uint32_t unmask_Line11InterruptRequest:1;
	volatile uint32_t unmask_Line12InterruptRequest:1;
	volatile uint32_t unmask_Line13InterruptRequest:1;
	volatile uint32_t unmask_Line14InterruptRequest:1;
	volatile uint32_t unmask_Line15InterruptRequest:1;
	volatile uint32_t unmask_Line16InterruptRequest:1;
	volatile uint32_t unmask_Line17InterruptRequest:1;
	volatile uint32_t unmask_Line18InterruptRequest:1;
	volatile uint32_t unmask_Line19InterruptRequest:1;
	volatile uint32_t unmask_Line20InterruptRequest:1;
	volatile uint32_t unmask_Line21InterruptRequest:1;
	volatile uint32_t unmask_Line22InterruptRequest:1;
	const uint32_t reserved:9;
}INTERRUPT_MASK;


typedef struct {
	volatile uint32_t unmask_Line0EventRequest:1;
	volatile uint32_t unmask_Line1EventRequest:1;
	volatile uint32_t unmask_Line2EventRequest:1;
	volatile uint32_t unmask_Line3EventRequest:1;
	volatile uint32_t unmask_Line4EventRequest:1;
	volatile uint32_t unmask_Line5EventRequest:1;
	volatile uint32_t unmask_Line6EventRequest:1;
	volatile uint32_t unmask_Line7EventRequest:1;
	volatile uint32_t unmask_Line8EventRequest:1;
	volatile uint32_t unmask_Line9EventRequest:1;
	volatile uint32_t unmask_Line10EventRequest:1;
	volatile uint32_t unmask_Line11EventRequest:1;
	volatile uint32_t unmask_Line12EventRequest:1;
	volatile uint32_t unmask_Line13EventRequest:1;
	volatile uint32_t unmask_Line14EventRequest:1;
	volatile uint32_t unmask_Line15EventRequest:1;
	volatile uint32_t unmask_Line16EventRequest:1;
	volatile uint32_t unmask_Line17EventRequest:1;
	volatile uint32_t unmask_Line18EventRequest:1;
	volatile uint32_t unmask_Line19EventRequest:1;
	volatile uint32_t unmask_Line20EventRequest:1;
	volatile uint32_t unmask_Line21EventRequest:1;
	volatile uint32_t unmask_Line22EventRequest:1;
	const uint32_t reserved:9;
}INTERRUPT_EVENTMASK;


typedef struct {
	volatile uint32_t enable_RisingTriggerInputLine0:1;
	volatile uint32_t enable_RisingTriggerInputLine1:1;
	volatile uint32_t enable_RisingTriggerInputLine2:1;
	volatile uint32_t enable_RisingTriggerInputLine3:1;
	volatile uint32_t enable_RisingTriggerInputLine4:1;
	volatile uint32_t enable_RisingTriggerInputLine5:1;
	volatile uint32_t enable_RisingTriggerInputLine6:1;
	volatile uint32_t enable_RisingTriggerInputLine7:1;
	volatile uint32_t enable_RisingTriggerInputLine8:1;
	volatile uint32_t enable_RisingTriggerInputLine9:1;
	volatile uint32_t enable_RisingTriggerInputLine10:1;
	volatile uint32_t enable_RisingTriggerInputLine11:1;
	volatile uint32_t enable_RisingTriggerInputLine12:1;
	volatile uint32_t enable_RisingTriggerInputLine13:1;
	volatile uint32_t enable_RisingTriggerInputLine14:1;
	volatile uint32_t enable_RisingTriggerInputLine15:1;
	volatile uint32_t enable_RisingTriggerInputLine16:1;
	volatile uint32_t enable_RisingTriggerInputLine17:1;
	volatile uint32_t enable_RisingTriggerInputLine18:1;
	volatile uint32_t enable_RisingTriggerInputLine19:1;
	volatile uint32_t enable_RisingTriggerInputLine20:1;
	volatile uint32_t enable_RisingTriggerInputLine21:1;
	volatile uint32_t enable_RisingTriggerInputLine22:1;
	const uint32_t reserved:9;
}INTERRUPT_RISING_TRIGGER_SELECTION;


typedef struct {
	volatile uint32_t enable_FallingTriggerInputLine0:1;
	volatile uint32_t enable_FallingTriggerInputLine1:1;
	volatile uint32_t enable_FallingTriggerInputLine2:1;
	volatile uint32_t enable_FallingTriggerInputLine3:1;
	volatile uint32_t enable_FallingTriggerInputLine4:1;
	volatile uint32_t enable_FallingTriggerInputLine5:1;
	volatile uint32_t enable_FallingTriggerInputLine6:1;
	volatile uint32_t enable_FallingTriggerInputLine7:1;
	volatile uint32_t enable_FallingTriggerInputLine8:1;
	volatile uint32_t enable_FallingTriggerInputLine9:1;
	volatile uint32_t enable_FallingTriggerInputLine10:1;
	volatile uint32_t enable_FallingTriggerInputLine11:1;
	volatile uint32_t enable_FallingTriggerInputLine12:1;
	volatile uint32_t enable_FallingTriggerInputLine13:1;
	volatile uint32_t enable_FallingTriggerInputLine14:1;
	volatile uint32_t enable_FallingTriggerInputLine15:1;
	volatile uint32_t enable_FallingTriggerInputLine16:1;
	volatile uint32_t enable_FallingTriggerInputLine17:1;
	volatile uint32_t enable_FallingTriggerInputLine18:1;
	volatile uint32_t enable_FallingTriggerInputLine19:1;
	volatile uint32_t enable_FallingTriggerInputLine20:1;
	volatile uint32_t enable_FallingTriggerInputLine21:1;
	volatile uint32_t enable_FallingTriggerInputLine22:1;
	const uint32_t reserved:9;
}INTERRUPT_FALLING_TRIGGER_SELECTION;


typedef struct {
	volatile uint32_t enable_SoftwareInterruptLine0:1;
	volatile uint32_t enable_SoftwareInterruptLine1:1;
	volatile uint32_t enable_SoftwareInterruptLine2:1;
	volatile uint32_t enable_SoftwareInterruptLine3:1;
	volatile uint32_t enable_SoftwareInterruptLine4:1;
	volatile uint32_t enable_SoftwareInterruptLine5:1;
	volatile uint32_t enable_SoftwareInterruptLine6:1;
	volatile uint32_t enable_SoftwareInterruptLine7:1;
	volatile uint32_t enable_SoftwareInterruptLine8:1;
	volatile uint32_t enable_SoftwareInterruptLine9:1;
	volatile uint32_t enable_SoftwareInterruptLine10:1;
	volatile uint32_t enable_SoftwareInterruptLine11:1;
	volatile uint32_t enable_SoftwareInterruptLine12:1;
	volatile uint32_t enable_SoftwareInterruptLine13:1;
	volatile uint32_t enable_SoftwareInterruptLine14:1;
	volatile uint32_t enable_SoftwareInterruptLine15:1;
	volatile uint32_t enable_SoftwareInterruptLine16:1;
	volatile uint32_t enable_SoftwareInterruptLine17:1;
	volatile uint32_t enable_SoftwareInterruptLine18:1;
	volatile uint32_t enable_SoftwareInterruptLine19:1;
	volatile uint32_t enable_SoftwareInterruptLine20:1;
	volatile uint32_t enable_SoftwareInterruptLine21:1;
	volatile uint32_t enable_SoftwareInterruptLine22:1;
	const uint32_t reserved:9;
}SOFTWARE_INTERRUPT_EVENT;


typedef struct {
	volatile uint32_t triggerOccurredLine0:1;
	volatile uint32_t triggerOccurredLine1:1;
	volatile uint32_t triggerOccurredLine2:1;
	volatile uint32_t triggerOccurredLine3:1;
	volatile uint32_t triggerOccurredLine4:1;
	volatile uint32_t triggerOccurredLine5:1;
	volatile uint32_t triggerOccurredLine6:1;
	volatile uint32_t triggerOccurredLine7:1;
	volatile uint32_t triggerOccurredLine8:1;
	volatile uint32_t triggerOccurredLine9:1;
	volatile uint32_t triggerOccurredLine10:1;
	volatile uint32_t triggerOccurredLine11:1;
	volatile uint32_t triggerOccurredLine12:1;
	volatile uint32_t triggerOccurredLine13:1;
	volatile uint32_t triggerOccurredLine14:1;
	volatile uint32_t triggerOccurredLine15:1;
	volatile uint32_t triggerOccurredLine16:1;
	volatile uint32_t triggerOccurredLine17:1;
	volatile uint32_t triggerOccurredLine18:1;
	volatile uint32_t triggerOccurredLine19:1;
	volatile uint32_t triggerOccurredLine20:1;
	volatile uint32_t triggerOccurredLine21:1;
	volatile uint32_t triggerOccurredLine22:1;
	const uint32_t reserved:9;
}PENDING;


struct _exti {
	INTERRUPT_MASK MaskReg; // 0x00
	INTERRUPT_EVENTMASK EventMaskReg; // 0x04
	INTERRUPT_RISING_TRIGGER_SELECTION RisingTrigSelectReg; // 0x08
	INTERRUPT_FALLING_TRIGGER_SELECTION FallingTrigSelectReg; // 0x0C
	SOFTWARE_INTERRUPT_EVENT SoftwareInterruptEventReg; // 0x10
	PENDING PendingReg; // 0x14
};

#endif
