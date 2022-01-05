//STM32F407 Driver
#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>

typedef enum _ReadWrite E_ReadWrite;

//DECLARATIONS
void I2C_Init(uint8_t i2cNumber, uint8_t apbClockFreqMHz, uint8_t desiredI2CFrequencykHz);
uint8_t I2C_StartMaster_SendAddress(uint8_t i2cNumber, uint8_t slaveAddress, E_ReadWrite readWrite);
uint8_t I2C_Receive(uint8_t i2cNumber);
uint8_t I2C_Transmit(uint8_t i2cNumber, uint8_t data);
void I2C_Stop(uint8_t i2cNumber);


#define CLOCK 0x40023800
#define APB1 0x40
#define I2C1 0x40005400
#define I2C2 0x40005800
#define I2C3 0x40005C00

//CLOCK
#define ADDR_I2C_CLOCK ( (I2C_CLOCK*) ((CLOCK) + APB1) )

//I2C 1
#define ADDR_I2C1_CONTROL1 ( (I2C_CONTROL1*) ((I2C1) + 0x00) )
#define ADDR_I2C1_CONTROL2 ( (I2C_CONTROL2*) ((I2C1) + 0x04) )
#define ADDR_I2C1_OWNADDRESS1 ( (I2C_OWNADDRESS1*) ((I2C1) + 0x08) )
#define ADDR_I2C1_OWNADDRESS2 ( (I2C_OWNADDRESS2*) ((I2C1) + 0x0C) )
#define ADDR_I2C1_DATA ( (I2C_DATA*) ((I2C1) + 0x10) )
#define ADDR_I2C1_STATUS1 ( (I2C_STATUS1*) ((I2C1) + 0x14) )
#define ADDR_I2C1_STATUS2 ( (I2C_STATUS2*) ((I2C1) + 0x18) )
#define ADDR_I2C1_CLOCKCONTROL ( (I2C_CLOCKCONTROL*) ((I2C1) + 0x1C) )
#define ADDR_I2C1_RISETIME ( (I2C_RISETIME*) ((I2C1) + 0x20) )
#define ADDR_I2C1_NOISEFILTER ( (I2C_NOISEFILTER*) ((I2C1) + 0x24) )


//I2C 2
#define ADDR_I2C2_CONTROL1 ( (I2C_CONTROL1*) ((I2C2) + 0x00) )
#define ADDR_I2C2_CONTROL2 ( (I2C_CONTROL2*) ((I2C2) + 0x04) )
#define ADDR_I2C2_OWNADDRESS1 ( (I2C_OWNADDRESS1*) ((I2C2) + 0x08) )
#define ADDR_I2C2_OWNADDRESS2 ( (I2C_OWNADDRESS2*) ((I2C2) + 0x0C) )
#define ADDR_I2C2_DATA ( (I2C_DATA*) ((I2C2) + 0x10) )
#define ADDR_I2C2_STATUS1 ( (I2C_STATUS1*) ((I2C2) + 0x14) )
#define ADDR_I2C2_STATUS2 ( (I2C_STATUS2*) ((I2C2) + 0x18) )
#define ADDR_I2C2_CLOCKCONTROL ( (I2C_CLOCKCONTROL*) ((I2C2) + 0x1C) )
#define ADDR_I2C2_RISETIME ( (I2C_RISETIME*) ((I2C2) + 0x20) )
#define ADDR_I2C2_NOISEFILTER ( (I2C_NOISEFILTER*) ((I2C2) + 0x24) )

//I2C 3
#define ADDR_I2C3_CONTROL1 ( (I2C_CONTROL1*) ((I2C3) + 0x00) )
#define ADDR_I2C3_CONTROL2 ( (I2C_CONTROL2*) ((I2C3) + 0x04) )
#define ADDR_I2C3_OWNADDRESS1 ( (I2C_OWNADDRESS1*) ((I2C3) + 0x08) )
#define ADDR_I2C3_OWNADDRESS2 ( (I2C_OWNADDRESS2*) ((I2C3) + 0x0C) )
#define ADDR_I2C3_DATA ( (I2C_DATA*) ((I2C3) + 0x10) )
#define ADDR_I2C3_STATUS1 ( (I2C_STATUS1*) ((I2C3) + 0x14) )
#define ADDR_I2C3_STATUS2 ( (I2C_STATUS2*) ((I2C3) + 0x18) )
#define ADDR_I2C3_CLOCKCONTROL ( (I2C_CLOCKCONTROL*) ((I2C3) + 0x1C) )
#define ADDR_I2C3_RISETIME ( (I2C_RISETIME*) ((I2C3) + 0x20) )
#define ADDR_I2C3_NOISEFILTER ( (I2C_NOISEFILTER*) ((I2C3) + 0x24) )

//I2C_CONTROL1
/*SMBus Type*/
#define SMBUS_DEVICE 0x00
#define SMBUS_HOST 0x01

//Enums----------------------------------------------------------------------
enum _ReadWrite {
	WRITE_BIT = 0,
	READ_BIT = 1
};

//Registers------------------------------------------------------------------
typedef struct {
	const uint32_t reserved0:21;
	volatile uint32_t i2c1_StartTick:1;
	volatile uint32_t i2c2_StartTick:1;
	volatile uint32_t i2c3_StartTick:1;
	const uint32_t reserved1:8;
}I2C_CLOCK;


typedef struct {

	volatile uint16_t enable_I2C:1;
	volatile uint16_t i2cMode0_SMBusMode1:1;
	const uint16_t reserved0:1;
	volatile uint16_t rw_SMBusType:1;
	volatile uint16_t enable_AddressResolutionProtocol:1;
	volatile uint16_t enable_PacketErrorCheck:1;
	volatile uint16_t enable_GeneralCall:1;
	volatile uint16_t disable_ClockStetchSlave:1;
	volatile uint16_t enable_StartGeneration:1;
	volatile uint16_t enable_StopGeneration:1;
	volatile uint16_t enable_ACK:1;
	volatile uint16_t currentACKPEC0_nextACKPEC1:1;
	volatile uint16_t enable_PECTransfer:1;
	volatile uint16_t enable_SMBusAlert:1;
	const uint16_t reserved1:1;
	volatile uint16_t reset_I2C:1;
}I2C_CONTROL1;


typedef struct {
	volatile uint16_t rw_APBClockFrequency:6;
	const uint16_t reserved0:2;
	volatile uint16_t enable_ErrorInterrupt:1;
	volatile uint16_t enable_EventInterrupt:1;
	volatile uint16_t enable_BufferInterrupt:1;
	volatile uint16_t enable_DMARequests:1;
	volatile uint16_t enable_DMALastTransfer:1;
	const uint16_t reserved1:3;
}I2C_CONTROL2;


typedef union {
	struct {
		volatile uint16_t rw_address10:10;
		const uint16_t reserved0:5;
		volatile uint16_t addrss7Bit0_addrss10Bit1:1;
	}Address10;
	
	struct {
		const uint16_t reserved0:1;
		volatile uint16_t rw_address7:7;
		const uint16_t reserved1:7;
		volatile uint16_t addrss7Bit0_addrss10Bit1:1;
	}Address7;
}I2C_OWNADDRESS1;


typedef struct {
	volatile uint16_t enable_DualAddressing:1;
	volatile uint16_t rw_InterfaceAddress:7;
	const uint16_t reserved:8;
}I2C_OWNADDRESS2;


typedef struct {
	volatile uint16_t rw_Data:8;
	const uint16_t reserved:8;
}I2C_DATA;

typedef struct {
	volatile uint16_t masterStartBitSet:1;
	volatile uint16_t addressSentOrMatched:1;
	volatile uint16_t byteTransferFinished:1;
	volatile uint16_t master10BitHeaderSent:1;
	volatile uint16_t slaveStopConditionDetected:1;
	const uint16_t reserved0:1;
	volatile uint16_t dataReadyToRead:1;
	volatile uint16_t transferRegisterOpen:1;
	volatile uint16_t busError:1;
	volatile uint16_t masterArbitrationLost:1;
	volatile uint16_t ackFailure:1;
	volatile uint16_t overrunUnderrun:1;
	volatile uint16_t receiverPECError:1;
	const uint16_t reserved1:1;
	volatile uint16_t TimeoutTLowError:1;
	volatile uint16_t smBusAlert:1;
}I2C_STATUS1;


typedef struct {
	volatile uint16_t masterMode1_slaveMode0:1;
	volatile uint16_t busBusy:1;
	volatile uint16_t transmitter1_receiver0:1;
	const uint16_t reserved:1;
	volatile uint16_t generalCallAddressReceived:1;
	volatile uint16_t smBusDefaultAddressReceived:1;
	volatile uint16_t smBusHostAddressReceived:1;
	volatile uint16_t addrssMatchOwn2nd1_addrssMatchOwn1st0:1;
	volatile uint16_t set_PacketErrorCheckValue:8;
}I2C_STATUS2;

typedef struct {
	volatile uint16_t rw_ClockValue:12;
	const uint16_t reserved:2;
	volatile uint16_t rw_FMDutyCycle:1;
	volatile uint16_t smMode0_fmMode1:1;
}I2C_CLOCKCONTROL;

typedef struct {
	volatile uint16_t rw_MaxRiseTime:6;
	const uint16_t reserved:10;
}I2C_RISETIME;

typedef struct {
	volatile uint16_t rw_DigitalNoiseFilterValue:4;
	volatile uint16_t disable_AnalogNoiseFilter:1;
	const uint16_t reserved:11;
}I2C_NOISEFILTER;


#endif
