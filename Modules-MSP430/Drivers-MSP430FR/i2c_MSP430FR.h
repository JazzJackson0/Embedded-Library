//MSP430FR59xx Driver
#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>

typedef enum _I2CClockSource E_I2CClockSource;
typedef enum _I2CMode E_I2CMode;
typedef enum _AddressSize E_AddressSize;

//DECLARATIONS
void I2C_Init(E_I2CClockSource clockSrc, uint16_t clockDivide, E_I2CMode mode, E_AddressSize ownSize);
void I2C_SetSlaveAddress(uint16_t slaveAddrs, E_AddressSize slaveSize);
void Start_RX_Mode(void);
void Start_TX_Mode(void);
uint8_t I2C_Receive(void);
uint8_t I2C_Transmit(uint8_t data);
void I2C_Stop(void);

#define I2C 0x0640

#define ADDR_I2C_CONTROL_WORD0 ( (I2C_CONTROL_WORD0*) ((I2C) + 0x00) )
#define ADDR_I2C_CONTROL_WORD1 ( (I2C_CONTROL_WORD1*) ((I2C) + 0x02) )
#define ADDR_I2C_BITRATE_CONTROL_WORD ( (I2C_BITRATE_CONTROL_WORD*) ((I2C) + 0x06) )
#define ADDR_I2C_STATUS_WORD ( (I2C_STATUS_WORD*) ((I2C) + 0x08) )
#define ADDR_I2C_BYTE_COUNTER_THRESHOLD ( (I2C_BYTE_COUNTER_THRESHOLD*) ((I2C) + 0x0A) )
#define ADDR_I2C_RECEIVE_BUFFER ( (I2C_RECEIVE_BUFFER*) ((I2C) + 0x0C) )
#define ADDR_I2C_TRANSMIT_BUFFER ( (I2C_TRANSMIT_BUFFER*) ((I2C) + 0x0E) )
#define ADDR_I2C_OWN_ADDRESS0 ( (I2C_OWN_ADDRESS0*) ((I2C) + 0x14) )
#define ADDR_I2C_OWN_ADDRESS1 ( (I2C_OWN_ADDRESS1*) ((I2C) + 0x16) )
#define ADDR_I2C_OWN_ADDRESS2 ( (I2C_OWN_ADDRESS2*) ((I2C) + 0x18) )
#define ADDR_I2C_OWN_ADDRESS3 ( (I2C_OWN_ADDRESS3*) ((I2C) + 0x1A) )
#define ADDR_I2C_RECEIVED_ADDRESS ( (I2C_RECEIVED_ADDRESS*) ((I2C) + 0x1C) )
#define ADDR_I2C_ADDRESS_MASK ( (I2C_ADDRESS_MASK*) ((I2C) + 0x1E) )
#define ADDR_I2C_SLAVE_ADDRESS ( (I2C_SLAVE_ADDRESS*) ((I2C) + 0x20) )
#define ADDR_I2C_INTERRUPT_ENABLE ( (I2C_INTERRUPT_ENABLE*) ((I2C) + 0x2A) )
#define ADDR_I2C_INTERRUPT_FLAG ( (I2C_INTERRUPT_FLAG*) ((I2C) + 0x2C) )
#define ADDR_I2C_INTERRUPT_VECTOR ( (I2C_INTERRUPT_VECTOR*) ((I2C) + 0x2E) )

//I2C_CONTROL_WORD0 Register
/*Synchronous Mode Type*/
#define SPI_3PIN 0x00
#define SPI_4PIN_SS_HIGH 0x01
#define SPI_4PIN_SS_LOW 0x02
#define I2C_MODE 0x03

//I2C_CONTROL_WORD0 Register
/*Deglitch Time*/
#define NS_2 0x00
#define NS_50 0x01
#define NS_100 0x02
#define NS_200 0x03

//I2C_CONTROL_WORD1 Register
/*Auto Stop Condition Type*/
#define NO_STOP 0x00
#define STOPON_BYTECOUNTER_INTERRUPT 0x01
#define STOPAFTER_BYTECOUNTER_INTERRUPT 0x02

/*Clock Low Timeout Values*/
#define DISABLE 0x00
#define MS_28 0x01
#define MS_31 0x02
#define MS_34 0x03

//Enums----------------------------------------------------------------------
//I2C_CONTROL_WORD0 Register
/*Clock Source*/
enum _I2CClockSource {
	SLAVE_UCxCLK_I2C = 0x00,
	MASTER_ACLK_I2C = 0x01,
	MASTER_SMCLK_I2C = 0x02
};

enum _I2CMode {
	I2C_SLAVE = 0,
	I2C_MASTER = 1
};

enum _AddressSize {
	_7BIT_I2C = 0,
	_10BIT_I2C = 1
};

//Registers------------------------------------------------------------------
typedef struct {
	volatile uint16_t enable_SoftwareReset:1;
	volatile uint16_t send_StartCondition:1;
	volatile uint16_t send_StopCondition:1;
	volatile uint16_t send_NACK:1;
	volatile uint16_t receiver0_transmitter1:1;
	volatile uint16_t send_ACK:1;
	volatile uint16_t select_ClockSource:2;
	volatile uint16_t enable_SynchronousMode:1;
	volatile uint16_t rw_SynchronousModeType:2;
	volatile uint16_t slaveMode0_masterMode1:1;
	const uint16_t reserved:1;
	volatile uint16_t enable_MultimasterMode:1;
	volatile uint16_t slaveAddrss7Bit0_slaveAddrss10Bit1:1;
	volatile uint16_t ownAddrss7Bit0_ownAddrss10Bit1:1;
}I2C_CONTROL_WORD0;

typedef struct {
	volatile uint16_t rw_DeglitchTime:2;
	volatile uint16_t rw_AutoStopConditionType:2;
	volatile uint16_t hardwareAddrssACK0_softwareAddrssACK1:1;
	volatile uint16_t enable_AllBytesACKed:1;
	volatile uint16_t rw_ClockLowTimeout:2;
	volatile uint16_t txInterruptPerAddrssMatch0_txInterruptPerStartCondition1:1;
	const uint16_t reserved:8;
}I2C_CONTROL_WORD1;

typedef struct {
	volatile uint16_t rw_BitClockPrescaler:16;
}I2C_BITRATE_CONTROL_WORD;

typedef struct {
	const uint16_t reserved0:3;
	volatile uint16_t busBusy:1;
	volatile uint16_t generalCallAddrssReceived:1;
	volatile uint16_t sclHeldLow:1;
	const uint16_t reserved1:1;
	volatile uint16_t rw_NumofBytesRXTXSinceStart:8;
}I2C_STATUS_WORD;

typedef struct {
	volatile uint16_t rw_NumOfDataBytesBeforeStop:8;
	const uint16_t reserved:8;
}I2C_BYTE_COUNTER_THRESHOLD;

typedef struct {
	volatile uint16_t read_DataReceived:8;
	const uint16_t reserved:8;
}I2C_RECEIVE_BUFFER;

typedef struct {
	volatile uint16_t rw_DataToTransmit:8;
	const uint16_t reserved:8;
}I2C_TRANSMIT_BUFFER;

typedef struct {
	volatile uint16_t rw_OwnAddress:10;
	volatile uint16_t enableAddress:1;
	const uint16_t reserved:4;
	volatile uint16_t enable_ResponseToGeneralCalls:1;
}I2C_OWN_ADDRESS0;

typedef struct {
	volatile uint16_t rw_OwnAddress:10;
	volatile uint16_t enableAddress:1;
	const uint16_t reserved:5;
}I2C_OWN_ADDRESS1;

typedef struct {
	volatile uint16_t rw_OwnAddress:10;
	volatile uint16_t enableAddress:1;
	const uint16_t reserved:5;
}I2C_OWN_ADDRESS2;

typedef struct {
	volatile uint16_t rw_OwnAddress:10;
	volatile uint16_t enableAddress:1;
	const uint16_t reserved:5;
}I2C_OWN_ADDRESS3;

typedef struct {
	volatile uint16_t :1;
	const uint16_t reserved:1;
}I2C_RECEIVED_ADDRESS;

typedef struct {
	volatile uint16_t read_LastReceivedAddress:10;
	const uint16_t reserved:6;
}I2C_ADDRESS_MASK;

typedef struct {
	volatile uint16_t rw_SlaveAddress:10;
	const uint16_t reserved:6;
}I2C_SLAVE_ADDRESS;

typedef struct {
	volatile uint16_t enable_ReceiveInterrupt0:1;
	volatile uint16_t enable_TransmitInterrupt0:1;
	volatile uint16_t enable_StartConditionInterrupt:1;
	volatile uint16_t enable_StopConditionInterrupt:1;
	volatile uint16_t enable_ArbitrationLostInterrupt:1;
	volatile uint16_t enable_NACKInterrupt:1;
	volatile uint16_t enable_ByteCounterInterrupt:1;
	volatile uint16_t enable_ClockLowTimeoutInterrupt:1;
	volatile uint16_t enable_ReceiveInterrupt1:1;
	volatile uint16_t enable_TransmitInterrupt1:1;
	volatile uint16_t enable_ReceiveInterrupt2:1;
	volatile uint16_t enable_TransmitInterrupt2:1;
	volatile uint16_t enable_ReceiveInterrupt3:1;
	volatile uint16_t enable_TransmitInterrupt3:1;
	volatile uint16_t enable_BitPosition9Interrupt:1;
	const uint16_t reserved:1;
}I2C_INTERRUPT_ENABLE;

typedef struct {
	volatile uint16_t receiveInterrupt0Occurred:1;
	volatile uint16_t transmitInterrupt0Occurred:1;
	volatile uint16_t startConditionInterruptOccurred:1;
	volatile uint16_t stopConditionInterruptOccurred:1;
	volatile uint16_t arbitrationLostInterruptOccurred:1;
	volatile uint16_t nACKInterruptOccurred:1;
	volatile uint16_t byteCounterInterruptOccurred:1;
	volatile uint16_t clockLowTimeoutInterruptOccurred:1;
	volatile uint16_t receiveInterrupt1Occurred:1;
	volatile uint16_t transmitInterrupt1Occurred:1;
	volatile uint16_t receiveInterrupt2Occurred:1;
	volatile uint16_t transmitInterrupt2Occurred:1;
	volatile uint16_t receiveInterrupt3Occurred:1;
	volatile uint16_t transmitInterrupt3Occurred:1;
	volatile uint16_t bitPosition9InterruptOccurred:1;
	const uint16_t reserved:1;
}I2C_INTERRUPT_FLAG;

typedef struct {
	volatile uint16_t read_HighestPriorityInterruptPending:16;
}I2C_INTERRUPT_VECTOR;

#endif
