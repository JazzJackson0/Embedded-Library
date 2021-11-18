//STM32F446 Driver
#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>

typedef enum _PinModes E_PinModes;
typedef enum _OutSpeeds E_OutSpeeds;
typedef enum _PullUpDown E_PullUpDown;

void Pin_Init(char port, uint8_t pinNum, E_PinModes modeType);
uint8_t Pin_GetInput(char port, uint8_t pinNum);
void Pin_Out(char port, uint8_t pinNum, uint8_t pinState);
void Pin_OutputSpeed(char port, uint8_t pinNum, E_OutSpeeds speed);
void Pin_PullUp_PullDown(char port, uint8_t pinNum, E_PullUpDown upDown);

#define CLOCK 0x40023800
#define AHB1 0x30
#define GPIOA 0x40020000
#define GPIOB 0x40020400
#define GPIOC 0x40020800
#define GPIOD 0x40020C00
#define GPIOE 0x40021000
#define GPIOF 0x40021400
#define GPIOG 0x40021800
#define GPIOH 0x40021C00

//CLOCK
#define ADDR_GPIOx_CLOCK ( (GPIOx_CLOCK*) ((CLOCK) + AHB1) )

//GPIO A
#define ADDR_GPIOA_MODE ( (GPIOx_MODE*) ((GPIOA) + 0x00) )
#define ADDR_GPIOA_OUTPUTTYPE ( (GPIOx_OUTPUTTYPE*) ((GPIOA) + 0x04) )
#define ADDR_GPIOA_OUTPUTSPEED ( (GPIOx_OUTPUTSPEED*) ((GPIOA) + 0x08) )
#define ADDR_GPIOA_PULLUP_PULLDOWN ( (GPIOx_PULLUP_PULLDOWN*) ((GPIOA) + 0x0C) )
#define ADDR_GPIOA_INPUT ( (GPIOx_INPUT*) ((GPIOA) + 0x10) )
#define ADDR_GPIOA_OUTPUT ( (GPIOx_OUTPUT*) ((GPIOA) + 0x14) )
#define ADDR_GPIOA_BIT_SETRESET ( (GPIOx_BIT_SETRESET*) ((GPIOA) + 0x18) )
#define ADDR_GPIOA_CONFIG_LOCK ( (GPIOx_CONFIG_LOCK*) ((GPIOA) + 0x1C) )
#define ADDR_GPIOA_ALTERNATE_FUNCT_LOW ( (GPIOx_ALTERNATE_FUNCT_LOW*) ((GPIOA) + 0x20) )
#define ADDR_GPIOA_ALTERNATE_FUNCT_HIGH ( (GPIOx_ALTERNATE_FUNCT_HIGH*) ((GPIOA) + 0x24) )

//GPIO B
#define ADDR_GPIOB_MODE ( (GPIOx_MODE*) ((GPIOB) + 0x00) )
#define ADDR_GPIOB_OUTPUTTYPE ( (GPIOx_OUTPUTTYPE*) ((GPIOB) + 0x04) )
#define ADDR_GPIOB_OUTPUTSPEED ( (GPIOx_OUTPUTSPEED*) ((GPIOB) + 0x08) )
#define ADDR_GPIOB_PULLUP_PULLDOWN ( (GPIOx_PULLUP_PULLDOWN*) ((GPIOB) + 0x0C) )
#define ADDR_GPIOB_INPUT ( (GPIOx_INPUT*) ((GPIOB) + 0x10) )
#define ADDR_GPIOB_OUTPUT ( (GPIOx_OUTPUT*) ((GPIOB) + 0x14) )
#define ADDR_GPIOB_BIT_SETRESET ( (GPIOx_BIT_SETRESET*) ((GPIOB) + 0x18) )
#define ADDR_GPIOB_CONFIG_LOCK ( (GPIOx_CONFIG_LOCK*) ((GPIOB) + 0x1C) )
#define ADDR_GPIOB_ALTERNATE_FUNCT_LOW ( (GPIOx_ALTERNATE_FUNCT_LOW*) ((GPIOB) + 0x20) )
#define ADDR_GPIOB_ALTERNATE_FUNCT_HIGH ( (GPIOx_ALTERNATE_FUNCT_HIGH*) ((GPIOB) + 0x24) )

//GPIO C
#define ADDR_GPIOC_MODE ( (GPIOx_MODE*) ((GPIOC) + 0x00) )
#define ADDR_GPIOC_OUTPUTTYPE ( (GPIOx_OUTPUTTYPE*) ((GPIOC) + 0x04) )
#define ADDR_GPIOC_OUTPUTSPEED ( (GPIOx_OUTPUTSPEED*) ((GPIOC) + 0x08) )
#define ADDR_GPIOC_PULLUP_PULLDOWN ( (GPIOx_PULLUP_PULLDOWN*) ((GPIOC) + 0x0C) )
#define ADDR_GPIOC_INPUT ( (GPIOx_INPUT*) ((GPIOC) + 0x10) )
#define ADDR_GPIOC_OUTPUT ( (GPIOx_OUTPUT*) ((GPIOC) + 0x14) )
#define ADDR_GPIOC_BIT_SETRESET ( (GPIOx_BIT_SETRESET*) ((GPIOC) + 0x18) )
#define ADDR_GPIOC_CONFIG_LOCK ( (GPIOx_CONFIG_LOCK*) ((GPIOC) + 0x1C) )
#define ADDR_GPIOC_ALTERNATE_FUNCT_LOW ( (GPIOx_ALTERNATE_FUNCT_LOW*) ((GPIOC) + 0x20) )
#define ADDR_GPIOC_ALTERNATE_FUNCT_HIGH ( (GPIOx_ALTERNATE_FUNCT_HIGH*) ((GPIOC) + 0x24) )

//GPIO D
#define ADDR_GPIOD_MODE ( (GPIOx_MODE*) ((GPIOD) + 0x00) )
#define ADDR_GPIOD_OUTPUTTYPE ( (GPIOx_OUTPUTTYPE*) ((GPIOD) + 0x04) )
#define ADDR_GPIOD_OUTPUTSPEED ( (GPIOx_OUTPUTSPEED*) ((GPIOD) + 0x08) )
#define ADDR_GPIOD_PULLUP_PULLDOWN ( (GPIOx_PULLUP_PULLDOWN*) ((GPIOD) + 0x0C) )
#define ADDR_GPIOD_INPUT ( (GPIOx_INPUT*) ((GPIOD) + 0x10) )
#define ADDR_GPIOD_OUTPUT ( (GPIOx_OUTPUT*) ((GPIOD) + 0x14) )
#define ADDR_GPIOD_BIT_SETRESET ( (GPIOx_BIT_SETRESET*) ((GPIOD) + 0x18) )
#define ADDR_GPIOD_CONFIG_LOCK ( (GPIOx_CONFIG_LOCK*) ((GPIOD) + 0x1C) )
#define ADDR_GPIOD_ALTERNATE_FUNCT_LOW ( (GPIOx_ALTERNATE_FUNCT_LOW*) ((GPIOD) + 0x20) )
#define ADDR_GPIOD_ALTERNATE_FUNCT_HIGH ( (GPIOx_ALTERNATE_FUNCT_HIGH*) ((GPIOD) + 0x24) )

//GPIO E
#define ADDR_GPIOE_MODE ( (GPIOx_MODE*) ((GPIOE) + 0x00) )
#define ADDR_GPIOE_OUTPUTTYPE ( (GPIOx_OUTPUTTYPE*) ((GPIOE) + 0x04) )
#define ADDR_GPIOE_OUTPUTSPEED ( (GPIOx_OUTPUTSPEED*) ((GPIOE) + 0x08) )
#define ADDR_GPIOE_PULLUP_PULLDOWN ( (GPIOx_PULLUP_PULLDOWN*) ((GPIOE) + 0x0C) )
#define ADDR_GPIOE_INPUT ( (GPIOx_INPUT*) ((GPIOE) + 0x10) )
#define ADDR_GPIOE_OUTPUT ( (GPIOx_OUTPUT*) ((GPIOE) + 0x14) )
#define ADDR_GPIOE_BIT_SETRESET ( (GPIOx_BIT_SETRESET*) ((GPIOE) + 0x18) )
#define ADDR_GPIOE_CONFIG_LOCK ( (GPIOx_CONFIG_LOCK*) ((GPIOE) + 0x1C) )
#define ADDR_GPIOE_ALTERNATE_FUNCT_LOW ( (GPIOx_ALTERNATE_FUNCT_LOW*) ((GPIOE) + 0x20) )
#define ADDR_GPIOE_ALTERNATE_FUNCT_HIGH ( (GPIOx_ALTERNATE_FUNCT_HIGH*) ((GPIOE) + 0x24) )

//GPIO F
#define ADDR_GPIOF_MODE ( (GPIOx_MODE*) ((GPIOF) + 0x00) )
#define ADDR_GPIOF_OUTPUTTYPE ( (GPIOx_OUTPUTTYPE*) ((GPIOF) + 0x04) )
#define ADDR_GPIOF_OUTPUTSPEED ( (GPIOx_OUTPUTSPEED*) ((GPIOF) + 0x08) )
#define ADDR_GPIOF_PULLUP_PULLDOWN ( (GPIOx_PULLUP_PULLDOWN*) ((GPIOF) + 0x0C) )
#define ADDR_GPIOF_INPUT ( (GPIOx_INPUT*) ((GPIOF) + 0x10) )
#define ADDR_GPIOF_OUTPUT ( (GPIOx_OUTPUT*) ((GPIOF) + 0x14) )
#define ADDR_GPIOF_BIT_SETRESET ( (GPIOx_BIT_SETRESET*) ((GPIOF) + 0x18) )
#define ADDR_GPIOF_CONFIG_LOCK ( (GPIOx_CONFIG_LOCK*) ((GPIOF) + 0x1C) )
#define ADDR_GPIOF_ALTERNATE_FUNCT_LOW ( (GPIOx_ALTERNATE_FUNCT_LOW*) ((GPIOF) + 0x20) )
#define ADDR_GPIOF_ALTERNATE_FUNCT_HIGH ( (GPIOx_ALTERNATE_FUNCT_HIGH*) ((GPIOF) + 0x24) )

//GPIO G
#define ADDR_GPIOG_MODE ( (GPIOx_MODE*) ((GPIOG) + 0x00) )
#define ADDR_GPIOG_OUTPUTTYPE ( (GPIOx_OUTPUTTYPE*) ((GPIOG) + 0x04) )
#define ADDR_GPIOG_OUTPUTSPEED ( (GPIOx_OUTPUTSPEED*) ((GPIOG) + 0x08) )
#define ADDR_GPIOG_PULLUP_PULLDOWN ( (GPIOx_PULLUP_PULLDOWN*) ((GPIOG) + 0x0C) )
#define ADDR_GPIOG_INPUT ( (GPIOx_INPUT*) ((GPIOG) + 0x10) )
#define ADDR_GPIOG_OUTPUT ( (GPIOx_OUTPUT*) ((GPIOG) + 0x14) )
#define ADDR_GPIOG_BIT_SETRESET ( (GPIOx_BIT_SETRESET*) ((GPIOG) + 0x18) )
#define ADDR_GPIOG_CONFIG_LOCK ( (GPIOx_CONFIG_LOCK*) ((GPIOG) + 0x1C) )
#define ADDR_GPIOG_ALTERNATE_FUNCT_LOW ( (GPIOx_ALTERNATE_FUNCT_LOW*) ((GPIOG) + 0x20) )
#define ADDR_GPIOG_ALTERNATE_FUNCT_HIGH ( (GPIOx_ALTERNATE_FUNCT_HIGH*) ((GPIOG) + 0x24) )

//GPIO H
#define ADDR_GPIOH_MODE ( (GPIOx_MODE*) ((GPIOH) + 0x00) )
#define ADDR_GPIOH_OUTPUTTYPE ( (GPIOx_OUTPUTTYPE*) ((GPIOH) + 0x04) )
#define ADDR_GPIOH_OUTPUTSPEED ( (GPIOx_OUTPUTSPEED*) ((GPIOH) + 0x08) )
#define ADDR_GPIOH_PULLUP_PULLDOWN ( (GPIOx_PULLUP_PULLDOWN*) ((GPIOH) + 0x0C) )
#define ADDR_GPIOH_INPUT ( (GPIOx_INPUT*) ((GPIOH) + 0x10) )
#define ADDR_GPIOH_OUTPUT ( (GPIOx_OUTPUT*) ((GPIOH) + 0x14) )
#define ADDR_GPIOH_BIT_SETRESET ( (GPIOx_BIT_SETRESET*) ((GPIOH) + 0x18) )
#define ADDR_GPIOH_CONFIG_LOCK ( (GPIOx_CONFIG_LOCK*) ((GPIOH) + 0x1C) )
#define ADDR_GPIOH_ALTERNATE_FUNCT_LOW ( (GPIOx_ALTERNATE_FUNCT_LOW*) ((GPIOH) + 0x20) )
#define ADDR_GPIOH_ALTERNATE_FUNCT_HIGH ( (GPIOx_ALTERNATE_FUNCT_HIGH*) ((GPIOH) + 0x24) )

//Enums----------------------------------------------------------------------
//GPIOx_MODE Register & GPIOx_ALTERNATE_FUNCT Registers
/*Pin Modes & Alternate Functions*/
enum _PinModes {
	IN = 0x10,
	OUT = 0x11,
	ANALOG = 0x13,
	AF = 0x02, //DO NOT USE
	AF0 = 0x00,
	AF1 = 0x01,
	AF2 = 0x02,
	AF3 = 0x03,
	AF4 = 0x04,
	AF5 = 0x05,
	AF6 = 0x06,
	AF7 = 0x07,
	AF8 = 0x08,
	AF9 = 0x09,
	AF10 = 0x0A,
	AF11 = 0x0B,
	AF12 = 0x0C,
	AF13 = 0x0D,
	AF14 = 0x0E,
	AF15 = 0x0F
};

//GPIOx_OUTPUTSPEED Register
/*Pin Out Speeds*/
enum _OutSpeeds {
	LOW = 0x00,
	MED = 0x01,
	HIGH = 0x02,
	VERY_HIGH = 0x03
};

//GPIOx_PULLUP_PULLDOWN Register
/*PullUP PullDown Settings*/
enum _PullUpDown {
	NONE = 0x00,
	UP = 0x01,
	DOWN = 0x02
};

//Registers------------------------------------------------------------------
typedef struct {
	volatile uint32_t gpioA_StartTick:1;
	volatile uint32_t gpioB_StartTick:1;
	volatile uint32_t gpioC_StartTick:1;
	volatile uint32_t gpioD_StartTick:1;
	volatile uint32_t gpioE_StartTick:1;
	volatile uint32_t gpioF_StartTick:1;
	volatile uint32_t gpioG_StartTick:1;
	volatile uint32_t gpioH_StartTick:1;
	volatile uint32_t gpioI_StartTick:1;
	const uint32_t reserved:23;
}GPIOx_CLOCK;

typedef volatile struct {
	uint32_t rw_Pin0_Mode:2;
	uint32_t rw_Pin1_Mode:2;
	uint32_t rw_Pin2_Mode:2;
	uint32_t rw_Pin3_Mode:2;
	uint32_t rw_Pin4_Mode:2;
	uint32_t rw_Pin5_Mode:2;
	uint32_t rw_Pin6_Mode:2;
	uint32_t rw_Pin7_Mode:2;
	uint32_t rw_Pin8_Mode:2;
	uint32_t rw_Pin9_Mode:2;
	uint32_t rw_Pin10_Mode:2;
	uint32_t rw_Pin11_Mode:2;
	uint32_t rw_Pin12_Mode:2;
	uint32_t rw_Pin13_Mode:2;
	uint32_t rw_Pin14_Mode:2;
	uint32_t rw_Pin15_Mode:2;
}GPIOx_MODE;


typedef struct {
	volatile uint32_t rw_Pin0_OutType:1;
	volatile uint32_t rw_Pin1_OutType:1;
	volatile uint32_t rw_Pin2_OutType:1;
	volatile uint32_t rw_Pin3_OutType:1;
	volatile uint32_t rw_Pin4_OutType:1;
	volatile uint32_t rw_Pin5_OutType:1;
	volatile uint32_t rw_Pin6_OutType:1;
	volatile uint32_t rw_Pin7_OutType:1;
	volatile uint32_t rw_Pin8_OutType:1;
	volatile uint32_t rw_Pin9_OutType:1;
	volatile uint32_t rw_Pin10_OutType:1;
	volatile uint32_t rw_Pin11_OutType:1;
	volatile uint32_t rw_Pin12_OutType:1;
	volatile uint32_t rw_Pin13_OutType:1;
	volatile uint32_t rw_Pin14_OutType:1;
	volatile uint32_t rw_Pin15_OutType:1;
	const uint32_t reserved:16;
}GPIOx_OUTPUTTYPE;


typedef volatile struct {	
	uint32_t rw_Pin0_OutSpeed:2;
	uint32_t rw_Pin1_OutSpeed:2;
	uint32_t rw_Pin2_OutSpeed:2;
	uint32_t rw_Pin3_OutSpeed:2;
	uint32_t rw_Pin4_OutSpeed:2;
	uint32_t rw_Pin5_OutSpeed:2;
	uint32_t rw_Pin6_OutSpeed:2;
	uint32_t rw_Pin7_OutSpeed:2;
	uint32_t rw_Pin8_OutSpeed:2;
	uint32_t rw_Pin9_OutSpeed:2;
	uint32_t rw_Pin10_OutSpeed:2;
	uint32_t rw_Pin11_OutSpeed:2;
	uint32_t rw_Pin12_OutSpeed:2;
	uint32_t rw_Pin13_OutSpeed:2;
	uint32_t rw_Pin14_OutSpeed:2;
	uint32_t rw_Pin15_OutSpeed:2;
}GPIOx_OUTPUTSPEED;


typedef volatile struct {
	uint32_t rw_Pin0_PUp_PDwn:2;
	uint32_t rw_Pin1_PUp_PDwn:2;
	uint32_t rw_Pin2_PUp_PDwn:2;
	uint32_t rw_Pin3_PUp_PDwn:2;
	uint32_t rw_Pin4_PUp_PDwn:2;
	uint32_t rw_Pin5_PUp_PDwn:2;
	uint32_t rw_Pin6_PUp_PDwn:2;
	uint32_t rw_Pin7_PUp_PDwn:2;
	uint32_t rw_Pin8_PUp_PDwn:2;
	uint32_t rw_Pin9_PUp_PDwn:2;
	uint32_t rw_Pin10_PUp_PDwn:2;
	uint32_t rw_Pin11_PUp_PDwn:2;
	uint32_t rw_Pin12_PUp_PDwn:2;
	uint32_t rw_Pin13_PUp_PDwn:2;
	uint32_t rw_Pin14_PUp_PDwn:2;
	uint32_t rw_Pin15_PUp_PDwn:2;
}GPIOx_PULLUP_PULLDOWN;


typedef struct {
	volatile uint32_t read_Pin0:1;
	volatile uint32_t read_Pin1:1;
	volatile uint32_t read_Pin2:1;
	volatile uint32_t read_Pin3:1;
	volatile uint32_t read_Pin4:1;
	volatile uint32_t read_Pin5:1;
	volatile uint32_t read_Pin6:1;
	volatile uint32_t read_Pin7:1;
	volatile uint32_t read_Pin8:1;
	volatile uint32_t read_Pin9:1;
	volatile uint32_t read_Pin10:1;
	volatile uint32_t read_Pin11:1;
	volatile uint32_t read_Pin12:1;
	volatile uint32_t read_Pin13:1;
	volatile uint32_t read_Pin14:1;
	volatile uint32_t read_Pin15:1;
	const uint32_t reserved:16;
}GPIOx_INPUT;


typedef struct {
	volatile uint32_t rw_Pin0_Out:1;
	volatile uint32_t rw_Pin1_Out:1;
	volatile uint32_t rw_Pin2_Out:1;
	volatile uint32_t rw_Pin3_Out:1;
	volatile uint32_t rw_Pin4_Out:1;
	volatile uint32_t rw_Pin5_Out:1;
	volatile uint32_t rw_Pin6_Out:1;
	volatile uint32_t rw_Pin7_Out:1;
	volatile uint32_t rw_Pin8_Out:1;
	volatile uint32_t rw_Pin9_Out:1;
	volatile uint32_t rw_Pin10_Out:1;
	volatile uint32_t rw_Pin11_Out:1;
	volatile uint32_t rw_Pin12_Out:1;
	volatile uint32_t rw_Pin13_Out:1;
	volatile uint32_t rw_Pin14_Out:1;
	volatile uint32_t rw_Pin15_Out:1;
	const uint32_t reserved:16;
}GPIOx_OUTPUT;

typedef struct {
	volatile uint32_t set_Pin0:1;
	volatile uint32_t set_Pin1:1;
	volatile uint32_t set_Pin2:1;
	volatile uint32_t set_Pin3:1;
	volatile uint32_t set_Pin4:1;
	volatile uint32_t set_Pin5:1;
	volatile uint32_t set_Pin6:1;
	volatile uint32_t set_Pin7:1;
	volatile uint32_t set_Pin8:1;
	volatile uint32_t set_Pin9:1;
	volatile uint32_t set_Pin10:1;
	volatile uint32_t set_Pin11:1;
	volatile uint32_t set_Pin12:1;
	volatile uint32_t set_Pin13:1;
	volatile uint32_t set_Pin14:1;
	volatile uint32_t set_Pin15:1;
	volatile uint32_t reset_Pin0:1;
	volatile uint32_t reset_Pin1:1;
	volatile uint32_t reset_Pin2:1;
	volatile uint32_t reset_Pin3:1;
	volatile uint32_t reset_Pin4:1;
	volatile uint32_t reset_Pin5:1;
	volatile uint32_t reset_Pin6:1;
	volatile uint32_t reset_Pin7:1;
	volatile uint32_t reset_Pin8:1;
	volatile uint32_t reset_Pin9:1;
	volatile uint32_t reset_Pin10:1;
	volatile uint32_t reset_Pin11:1;
	volatile uint32_t reset_Pin12:1;
	volatile uint32_t reset_Pin13:1;
	volatile uint32_t reset_Pin14:1;
	volatile uint32_t reset_Pin15:1;
}GPIOx_BIT_SETRESET;

typedef struct {
	volatile uint32_t rw_Pin0_Locked:1;
	volatile uint32_t rw_Pin1_Locked:1;
	volatile uint32_t rw_Pin2_Locked:1;
	volatile uint32_t rw_Pin3_Locked:1;
	volatile uint32_t rw_Pin4_Locked:1;
	volatile uint32_t rw_Pin5_Locked:1;
	volatile uint32_t rw_Pin6_Locked:1;
	volatile uint32_t rw_Pin7_Locked:1;
	volatile uint32_t rw_Pin8_Locked:1;
	volatile uint32_t rw_Pin9_Locked:1;
	volatile uint32_t rw_Pin10_Locked:1;
	volatile uint32_t rw_Pin11_Locked:1;
	volatile uint32_t rw_Pin12_Locked:1;
	volatile uint32_t rw_Pin13_Locked:1;
	volatile uint32_t rw_Pin14_Locked:1;
	volatile uint32_t rw_Pin15_Locked:1;
	const uint32_t reserved:16;
}GPIOx_CONFIG_LOCK;

typedef volatile struct {
	uint32_t rw_Pin0_AltFunction:4;
	uint32_t rw_Pin1_AltFunction:4;
	uint32_t rw_Pin2_AltFunction:4;
	uint32_t rw_Pin3_AltFunction:4;
	uint32_t rw_Pin4_AltFunction:4;
	uint32_t rw_Pin5_AltFunction:4;
	uint32_t rw_Pin6_AltFunction:4;
	uint32_t rw_Pin7_AltFunction:4;
}GPIOx_ALTERNATE_FUNCT_LOW;


typedef volatile struct {
	uint32_t rw_Pin8_AltFunction:4;
	uint32_t rw_Pin9_AltFunction:4;
	uint32_t rw_Pin10_AltFunction:4;
	uint32_t rw_Pin11_AltFunction:4;
	uint32_t rw_Pin12_AltFunction:4;
	uint32_t rw_Pin13_AltFunction:4;
	uint32_t rw_Pin14_AltFunction:4;
	uint32_t rw_Pin15_AltFunction:4;
}GPIOx_ALTERNATE_FUNCT_HIGH;


#endif
