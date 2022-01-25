/*For use with the STM32F407. 
Can be tweaked to fit other microcontrollers.
...probably.*/
#ifndef LCD_1602A_H_
#define LCD_1602A_H_

#include <stdint.h>

//DECLARATIONS
/**
 * @brief 
 * 
 * @return ** void 
 */
void LCD_Init(void);
/**
 * @brief 
 * 
 * @param instruct 
 * @return ** void 
 */
void LCD_Instruct(uint8_t instruct);
/**
 * @brief 
 * 
 * @param data 
 * @return ** void 
 */
void LCD_Display(uint16_t data);

//LCD
#define ADDR_LCD_CNTRL ( (LCD_Cntrl*) 0X40021018 ) //GPIOE_BSRR
#define ADDR_LCD_DATA ( (LCD_Data_Out*) 0X40020C14 )

//LCD INSTRUCTIONS
#define INIT_CODE 0x30

#define DISPLAY_OFF 0x08
#define DISPLAY_ON_CURSOR_OFF_BLINK_ON 0x0D
#define DISPLAY_ON_CURSOR_ON_BLINK_OFF 0x0E
#define DISPLAY_ON_CURSOR_ON_BLINK_ON 0x0F
#define DISPLAY_ON_CURSOR_OFF_BLINK_OFF 0x0C

#define BIT8_1LINE_5x8FONT 0x30
#define BIT8_1LINE_5x11FONT 0x34

#define BIT8_2LINE_5x8FONT 0x38
#define BIT8_2LINE_5x11FONT 0x3C

#define BIT4_1LINE_5x8FONT 0x20
#define BIT4_1LINE_5x11FONT 0x21

#define BIT4_2LINE_5x8FONT 0x28
#define BIT4_2LINE_5x11FONT 0x2C

#define CURSOR_GORIGHT_NO_DISPLAYSHIFT 0x06
#define CURSOR_GOLEFT_NO_DISPLAYSHIFT 0x04

#define CURSOR_GORIGHT_DISPLAYSHIFT 0x07
#define CURSOR_GOLEFT_DISPLAYSHIFT 0x05

#define DISPLAY_SHIFT_RIGHT 0x1C
#define DISPLAY_SHIFT_LEFT 0x18

#define CLEAR_DISPLAY 0x01
#define RETURN_CURSOR_HOME 0x02

//Structs-----------------------------------------------------
typedef struct {
	volatile uint32_t dataMode:1;
	volatile uint32_t read:1;
	volatile uint32_t chipEnable:1;
	const uint32_t reserved0:13;
	volatile uint32_t instructionMode:1;
	volatile uint32_t write:1;
	volatile uint32_t chipDisable:1;
	const uint32_t reserved1:13;
}LCD_Cntrl;


typedef struct {
	volatile uint32_t data:8;
	const uint32_t reserved:24;
}LCD_Data_Out;


#endif
