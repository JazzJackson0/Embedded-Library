#MSPDebug Makefile
FILENAME = moduleTest
ifndef $(MSPGCCDIR)
	MSPGCCDIR=C:/ti/msp430-gcc
endif
INCLUDES_DIRECTORY = $(MSPGCCDIR)\include
MY_INCLUDES = -I./
DEVICE = msp430fr5869

#compiler options
CC=$(MSPGCCDIR)/bin/msp430-elf-gcc

#To use gdb correctly
#--------------------
#-O0: turn off optimizations
#-g3: debugging level 3, All debugging info
#-ggdb
#-gdwarf-2: Use dwarf2 style debug info (What's expected by gdb for the msp430)

CFLAGS = -I . -I $(INCLUDES_DIRECTORY) -mmcu=$(DEVICE) $(MY_INCLUDES) -mhwmult=f5series -O0 -g3 -ggdb -gdwarf-2
LFLAGS = -L . -L $(INCLUDES_DIRECTORY) $(MY_INCLUDES)

#mspdebug driver -- used for installation
#tilib: The library Texas Instruments provides for installing new code
DRIVER:= tilib 

#Compiling
all: $(FILENAME).elf

%.elf : %.c
	$(CC) $(CFLAGS) $(LFLAGS) $< -o $@
	
clean:
	rm -f *.o *.elf
	
#MSPDebug: Upload to board
install.%: %.elf
	mspdebug $(DRIVER) "prog $<" --allow-fw-update 
	#--allow-fw-update: Update the Programmer's firmware if it needs to be updated

#MSP430Flasher: Upload to board
hex:
	msp430-elf-objcopy -O ihex $(FILENAME).elf $(FILENAME).hex

msp430flasher:
	MSP430Flasher.exe -e ERASE_ALL -w $(FILENAME).hex -v -g -z [VCC]
