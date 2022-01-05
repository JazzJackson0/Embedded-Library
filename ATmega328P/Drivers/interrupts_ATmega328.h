//ATmega328/P Driver
#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

/*INTERRUPT Pins ---------------------------
		+ INT0: PD2
		+ INT1: PD3
		+ PCINT0: PB0
		+ PCINT1: PB1
		+ PCINT2: PB2
		+ PCINT3: PB3
		+ PCINT4: PB4
		+ PCINT5: PB5
		+ PCINT6: PB6
		+ PCINT7: PB7
		+ PCINT8: PC0
		+ PCINT9: PC1
		+ PCINT10: PC2
		+ PCINT11: PC3
		+ PCINT12: PC4
		+ PCINT13: PC5
		+ PCINT14: PC6
		+ PCINT16: PD0
		+ PCINT17: PD1
		+ PCINT18: PD2
		+ PCINT19: PD3
		+ PCINT20: PD4
		+ PCINT21: PD5
		+ PCINT22: PD6
		+ PCINT23: PD7
		------------------------------------*/
		
#include <stdint.h>
//Powered by AVR Clock Control Unit
#define ATMEGA_BASEADDRESS 0x0000

#define ADDR_MCU_CONTROL_INTERRUPT ( (MCU_CONTROL_INTERRUPT*) ((ATMEGA_BASEADDRESS) + 0x35) ) //In 'Interrupt' Section, Not 'External Interrupt' Section
#define ADDR_INTERRUPT_CONTROL_A ( (INTERRUPT_CONTROL_A*) ((ATMEGA_BASEADDRESS) + 0x69) )
#define ADDR_INTERRUPT_MASK ( (INTERRUPT_MASK*) ((ATMEGA_BASEADDRESS) + 0x3D) )
#define ADDR_INTERRUPT_FLAG ( (INTERRUPT_FLAG*) ((ATMEGA_BASEADDRESS) + 0x3C) )
#define ADDR_PIN_CHANGE_CONTROL ( (PIN_CHANGE_CONTROL*) ((ATMEGA_BASEADDRESS) + 0x68) )
#define ADDR_PIN_CHANGE_CONTROL_INTERRUPT_FLAG ( (PIN_CHANGE_CONTROL_INTERRUPT_FLAG*) ((ATMEGA_BASEADDRESS) + 0x3B) )
#define ADDR_PIN_CHANGE_MASK2 ( (PIN_CHANGE_MASK2*) ((ATMEGA_BASEADDRESS) + 0x6D) )
#define ADDR_PIN_CHANGE_MASK1 ( (PIN_CHANGE_MASK1*) ((ATMEGA_BASEADDRESS) + 0x6C) )
#define ADDR_PIN_CHANGE_MASK0 ( (PIN_CHANGE_MASK0*) ((ATMEGA_BASEADDRESS) + 0x6B) )

//INTERRUPT_CONTROL_A
/*Interrupt Activation Types*/
#define LOWLEVEL_GEN 0x00
#define LOGIC_CHANGE_GEN 0x01
#define FALL_EDGE_GEN 0x02
#define RISE_EDGE_GEN 0x03


typedef struct {
	volatile uint8_t enable_InterruptVectorChange:1;
	volatile uint8_t interruptVectorChange:1;
	const uint8_t reserved0:2;
	volatile uint8_t disable_PullUps:1;
	volatile uint8_t enable_BrownOutDetectionSleep:1;
	volatile uint8_t start_BrownOutDetectionSleep:1;
	const uint8_t reserved1:1;
}MCU_CONTROL_INTERRUPT;

typedef struct {
	volatile uint8_t int0_InterruptActivationType:2;
	volatile uint8_t int1_InterruptActivationType:2;
	const uint8_t reserved:4;
}INTERRUPT_CONTROL_A;

typedef struct {
	volatile uint8_t enable_EXTI0:1;
	volatile uint8_t enable_EXTI1:1;
	const uint8_t reserved:6;
}INTERRUPT_MASK;

typedef struct {
	volatile uint8_t exti0_InterruptOccurred:1;
	volatile uint8_t exti1_InterruptOccurred:1;
	const uint8_t reserved:6;
}INTERRUPT_FLAG;

typedef struct {
	volatile uint8_t enable_PinChangeInterrupt0:1;
	volatile uint8_t enable_PinChangeInterrupt1:1;
	volatile uint8_t enable_PinChangeInterrupt2:1;
	const uint8_t reserved:5;
}PIN_CHANGE_CONTROL;

typedef struct {
	volatile uint8_t pinChangeInterrupt0Occurred:1;
	volatile uint8_t pinChangeInterrupt1Occurred:1;
	volatile uint8_t pinChangeInterrupt2Occurred:1;
	const uint8_t reserved:5;
}PIN_CHANGE_CONTROL_INTERRUPT_FLAG;

typedef struct {
	volatile uint8_t pin15_EnablePinChangeInterrupt:1;
	volatile uint8_t pin16_EnablePinChangeInterrupt:1;
	volatile uint8_t pin17_EnablePinChangeInterrupt:1;
	volatile uint8_t pin18_EnablePinChangeInterrupt:1;
	volatile uint8_t pin19_EnablePinChangeInterrupt:1;
	volatile uint8_t pin20_EnablePinChangeInterrupt:1;
	volatile uint8_t pin21_EnablePinChangeInterrupt:1;
	volatile uint8_t pin22_EnablePinChangeInterrupt:1;
	volatile uint8_t pin23_EnablePinChangeInterrupt:1;
}PIN_CHANGE_MASK2;

typedef struct {
	volatile uint8_t pin8_EnablePinChangeInterrupt:1;
	volatile uint8_t pin9_EnablePinChangeInterrupt:1;
	volatile uint8_t pin10_EnablePinChangeInterrupt:1;
	volatile uint8_t pin11_EnablePinChangeInterrupt:1;
	volatile uint8_t pin12_EnablePinChangeInterrupt:1;
	volatile uint8_t pin13_EnablePinChangeInterrupt:1;
	volatile uint8_t pin14_EnablePinChangeInterrupt:1;
	const uint8_t reserved:1;
}PIN_CHANGE_MASK1;

typedef struct {
	volatile uint8_t pin0_EnablePinChangeInterrupt:1;
	volatile uint8_t pin1_EnablePinChangeInterrupt:1;
	volatile uint8_t pin2_EnablePinChangeInterrupt:1;
	volatile uint8_t pin3_EnablePinChangeInterrupt:1;
	volatile uint8_t pin4_EnablePinChangeInterrupt:1;
	volatile uint8_t pin5_EnablePinChangeInterrupt:1;
	volatile uint8_t pin6_EnablePinChangeInterrupt:1;
	volatile uint8_t pin7_EnablePinChangeInterrupt:1;
}PIN_CHANGE_MASK0;

#endif
