#include "isr_handlers.h"


volatile uint8_t exti1_triggered = 0;



void EXTI1_IRQHandler(void) {

    exti1_triggered = 1;
	
}
