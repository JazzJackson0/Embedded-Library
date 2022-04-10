//ATmega328/P Driver
//Two Wire Interface: Atmel's version of I2C (Avoids trademark issues)
#ifndef TWI_H_
#define TWI_H_
#include <stdint.h>
/*TWI Pins ---------------------------
		+ SDA 0: PC4
		+ SCL 0: PC5
		------------------------------------*/

typedef enum _TWIClockDivide E_TWIClockDivide;
typedef enum _Read_Write E_Read_Write;

//DECLARATIONS
/**
 * @brief Initialize Two Wire Interface
 * 
 * @param clockDivider TWI Clock Speed Divider (DIV_x: Where x = 1, 4, 16, 64)
 * 						|||  ATmega defaults to 8MHz RC Prescaled to 1MHz
 * 						|||  Arduino Uno Board overrides ATmega and defaults to 16MHz external 
 * 							xtal oscillator
 * @param bitRatekHz Bit Rate in KHz |||  Ex: 500 for 500KHz
 * @return ** void 
 */
void TWI_Init(E_TWIClockDivide clockDivider, uint8_t bitRatekHz);
/**
 * @brief Start TWI as Master
 * 
 * @param slaveAddress Address of Slave Device
 * @param readWrite READ or WRITE Bit
 * @return ** uint8_t 
 */
uint8_t TWIMasterStart(uint8_t slaveAddress, E_Read_Write readWrite);
/**
 * @brief Transmit data from TWI Master Device.
 * 
 * @param data Data to transmit.
 * @return ** uint8_t 
 */
uint8_t TWIMaster_Transmit(uint8_t data);
/**
 * @brief Receive data to Master Device via TWI 
 * 
 * @return ** uint8_t Data Received
 */
uint8_t TWIMaster_Receive(void);
/**
 * @brief Send 'Stop Condition' to end current transmission.
 * 
 * @return ** void 
 */
void TWI_Stop(void);


//TWI (Powered by AVR Clock Control Unit)
typedef struct _twi TWIx;
#define ATMEGA_BASEADDRESS 0x0000
#define ADDR_POWER_REDUCTION_TWI ( (POWER_REDUCTION_TWI*) ((ATMEGA_BASEADDRESS) + 0x64) ) //Found in Power Management Section
#define ADDR_TWI ( (TWIx*) ((ATMEGA_BASEADDRESS) + 0xB8) )


/*Status Codes: Master Transmitter*/
#define START_CONDITION_TRANSMITTED 0x08
#define REPEATED_START_CONDITION_TRANSMITTED 0x10
#define SLA_AND_W_TRANSMITTED_ACK_RECEIVED 0x18
#define SLA_AND_W_TRANSMITTED_NACK_RECEIVED 0x20
#define MASTER_DATA_BYTE_TRANSMITTED_ACK_RECEIVED 0x28
#define MASTER_DATA_BYTE_TRANSMITTED_NACK_RECEIVED 0x30
#define ARBITRATION_LOST_IN_SLA_AND_W_OR_DATABYTE 0x38
/*Status Codes: Master Receiver*/
#define START_CONDITION_TRANSMITTED 0x08
#define REPEATED_START_CONDITION_TRANSMITTED 0x10
#define ARBITRATION_LOST_IN_SLA_AND_W_OR_NACK 0x38
#define SLA_AND_R_TRANSMITTED_ACK_RECEIVED 0x40
#define SLA_AND_R_TRANSMITTED_NACK_RECEIVED 0x48
#define DATA_BYTE_RECEIVED_ACK_RETURNED 0x50
#define DATA_BYTE_RECEIVED_NACK_RETURNED 0x58
/*Status Codes: Slave Transmitter*/
#define OWN_SLA_AND_R_RECEIVED_ACK_RETURNED 0xA8
#define DONT_KNOW0 0xB0
#define SLAVE_DATA_BYTE_TRANSMITTED_ACK_RECEIVED 0xB8
#define SLAVE_DATA_BYTE_TRANSMITTED_NACK_RECEIVED 0xC0
#define LAST_DATA_BYTE_TRANSMITTED_ACK_RECEIVED 0xC8
/*Status Codes: Slave Receiver*/
#define OWN_SLA_AND_W_RECEIVED_ACK_RETURNED 0x60
#define DONT_KNOW1 0x68
#define GENERALCALL_ADDRSS_RECEIVED_ACK_RETURNED 0x70
#define DONT_KNOW2 0x78
#define PREV_SLAW_DATA_BYTE_RECEIVED_ACK_RETURNED 0x80
#define PREV_SLAW_DATA_BYTE_RECEIVED_NACK_RETURNED 0x88
#define PREV_GENCALL_DATA_BYTE_RECEIVED_ACK_RECEIVED 0x90
#define PREV_GENCALL_DATA_BYTE_RECEIVED_NACK_RECEIVED 0x98
#define STOP_OR_REPEATED_START_RECEIVED 0xA0
/*Status Codes: Misc*/
#define NO_RELEVANT_STATE_INFO_GIVEN 0xF8
#define BUSERROR_ILLEGAL_START_OR_STOP 0x00

//Enums----------------------------------------------------------------------
//TWI_STATUS Register
/*Prescaler Values*/
enum _TWIClockDivide {
	DIV_1 = 0x00, DIV_4 = 0x01,
	DIV_16 = 0x02, DIV_64 = 0x03
};

enum _Read_Write {
	READ = 1, WRITE = 0
};

//Registers------------------------------------------------------------------
typedef struct {
    const uint8_t reserved:7;
    volatile uint8_t twiOn0_twiOff1:1;
}POWER_REDUCTION_TWI;

typedef struct {
	volatile uint8_t rw_BitRate:8;
}TWI_BITRATE;

typedef struct {
	volatile uint8_t rw_Prescaler:2;
	const uint8_t reserved:1;
	volatile uint8_t read_TWIStatus:5;
}TWI_STATUS;

typedef struct {
	volatile uint8_t enable_GeneralCallRecognition:1;
	volatile uint8_t rw_SlaveAddress:7;
}TWI_OWN_SLAVE_ADDRESS;

typedef struct {
	volatile uint8_t readData0_writeData1:8;
}TWI_DATA;

typedef struct {
	volatile uint8_t enable_TWIEventInterrupt:1;
	const uint8_t reserved:1;
	volatile uint8_t enable_TWI:1;
	volatile uint8_t writeCollisionOccurred:1;
	volatile uint8_t send_StopConditionORErrorRecover:1;
	volatile uint8_t send_StartCondition:1;
	volatile uint8_t send_ACK:1;
	volatile uint8_t twiEventInterruptOccurred:1;
}TWI_CONTROL;

typedef struct {
	const uint8_t reserved:1;
	volatile uint8_t mask_Bit0:1;
	volatile uint8_t mask_Bit1:1;
	volatile uint8_t mask_Bit2:1;
	volatile uint8_t mask_Bit3:1;
	volatile uint8_t mask_Bit4:1;
	volatile uint8_t mask_Bit5:1;
	volatile uint8_t mask_Bit6:1;
}TWI_OWN_SLAVE_ADDRESS_MASK;


struct _twi {
	TWI_BITRATE BitRateReg; // 0xB8
	TWI_STATUS StatusReg; // 0xB9
	TWI_OWN_SLAVE_ADDRESS OwnSlaveAddressReg; // 0xBA
	TWI_DATA DataReg; // 0xBB
	TWI_CONTROL ControlReg; // 0xBC
	TWI_OWN_SLAVE_ADDRESS_MASK OwnSlaveAddressMaskReg; // 0xBD
};

#endif

