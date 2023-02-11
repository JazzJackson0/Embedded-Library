#include "BBBDebian.I2C.hpp"
#include <bits/stdint-intn.h>
#include <bits/stdint-uintn.h>
#include <sys/ioctl.h>
// i2cget -y [i2cnum, e.g. 3] CHIP-ADDDRESS DATA-ADDRESS
// i2cget -y 3 0x40 05 (0x40 + 5 = 0x45)

//i2cset -y 3 0x40 255 ...

int8_t I2CInit(uint8_t i2cNum, uint8_t I2CSlaveAddress) {

    char path[BUFFER_SIZE];
    FILE *file;

    snprintf(path, sizeof(path), "/dev/i2c-%d", i2cNum);
    file = fopen(path, "w");

    if (file == ((void*)0)) {
        perror("Unable to open file. Cannot initialize i2c %d", i2cNum);
        return -1;
    }
	
	// Set Slave Address
	if (ioctl(file, I2C_SLAVE, I2CSlaveAddress) < 0) {
		// Print Error Mesage
	}

    fclose(file);
    return 1;
}

int8_t I2C() {


}


