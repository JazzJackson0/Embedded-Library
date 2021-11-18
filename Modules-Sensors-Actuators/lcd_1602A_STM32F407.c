#include <stdint.h>
#include "gpio_STM32F407.h"
#include "lcd_1602A_STM32F407.h"

// Static Prototypes------------------------------------------------
static void LCD_DataOut(int num);
static void LCD_SendNum(int num);

// Global Variables------------------------------------------------
LCD_Cntrl *const lcdCntrl = ADDR_LCD_CNTRL;
LCD_Data_Out *const lcdData = ADDR_LCD_DATA;


static void msDelay(int delay) {
	
	for (; delay > 0; delay--) {

		for (int i = 0; i < 3195; i++);
	}
}

void LCD_Init(void) {
	
	//LCD Init Sequence
	msDelay(30);
	LCD_Instruct(INIT_CODE);
	msDelay(10);
	LCD_Instruct(INIT_CODE);
	msDelay(1);
	LCD_Instruct(INIT_CODE);
	LCD_Instruct(DISPLAY_OFF);
	LCD_Instruct(BIT8_1LINE_5x8FONT);
	LCD_Instruct(CURSOR_GORIGHT_NO_DISPLAYSHIFT);	
	LCD_Instruct(CLEAR_DISPLAY);
	LCD_Instruct(DISPLAY_ON_CURSOR_ON_BLINK_ON);
	LCD_Instruct(CLEAR_DISPLAY);
}

void LCD_Instruct(uint8_t instruct) {
	
	lcdCntrl->instructionMode = 1;
	//lcdCntrl->write = 1; Pin being pulled to GND, so no need.
	lcdData->data = instruct;
	lcdCntrl->chipEnable = 1;
	msDelay(0);
	lcdCntrl->chipDisable = 1;
}

void LCD_Display(uint16_t data) {
	
	//char warning[] = "OOR";
	data = (int) data;	
	lcdCntrl->dataMode = 1;
	
	if (data == 0) {

		//lcdData->data = warning[0];
		LCD_DataOut(0);
	}

	else { LCD_DataOut(data); }

	//Add centimeter value.
}

// Helper Functions------------------------------------------------------------------------------------------

static void LCD_DataOut(int num) {
	
	int stack[4];
	if (num < 10) {

		LCD_SendNum(num);
	}

	else {
		int stack_size = 0;
			
		while (num > 0) {
				
			int r = num % 10;
			num = num / 10;
			stack[stack_size] = r;
			stack_size++;
		}

		int stack_index = stack_size - 1;
			
		for (int i = 0; i < stack_size; i++) {
				
			LCD_SendNum(stack[stack_index]);
			stack_index--;
		}
	}
}

static void LCD_SendNum(int num) {
	
	num = num + 48;
	lcdData->data = num;
	lcdCntrl->chipEnable = 1;
	msDelay(1);
	lcdCntrl->chipDisable = 1;
}