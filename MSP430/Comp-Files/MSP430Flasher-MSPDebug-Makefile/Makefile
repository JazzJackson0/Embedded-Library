#MSPDebug Makefile
FILENAME = filename
ifndef $(MSPGCCDIR)
	MSPGCCDIR=C:\ti\msp430-gcc
endif
#Paths
SRC = ./
INCLUDES_DIRECTORY = $(MSPGCCDIR)\include/
LOW_LEVEL_FILES = inc/low_level/
LOGIC_FILES = inc/logic/
MY_INCLUDES = -I$(LOW_LEVEL_FILES) -I$(LOGIC_FILES)

DEVICE = msp430fr5869

#compiler options
CC=$(MSPGCCDIR)\bin\msp430-elf-gcc

#Get all .c files in working directory
SRCS=$(wildcard *.c)
L=$(wildcard $(LOGIC_FILES)*.c)
LL=$(wildcard $(LOW_LEVEL_FILES)*.c)

#Convert all .c files to .o files
#If you see anything in the 3rd arg that looks like the 1st arg, replace it w/ the second arg
SRC_OBJS=$(patsubst $(SRC)%.c, $(SRC)%.o, $(SRCS))
L_OBJS=$(patsubst $(LOGIC_FILES)%.c, $(LOGIC_FILES)%.o, $(L))
LL_OBJS=$(patsubst $(LOW_LEVEL_FILES)%.c, $(LOW_LEVEL_FILES)%.o, $(LL))

OBJS = $(SRC_OBJS) $(LL_OBJS) $(L_OBJS)


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
all: $(FILENAME) $(FILENAME).elf

$(FILENAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -o $@

$(FILENAME).elf : $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -o $@
		
clean:
	rm -f *.o $(LOGIC_FILES)*.o $(LOW_LEVEL_FILES)*.o *.elf *.hex
	
#MSPDebug: Upload to board
install.%: %.elf
	mspdebug $(DRIVER) "prog $<" --allow-fw-update 
	#--allow-fw-update: Update the Programmer's firmware if it needs to be updated

#MSP430Flasher: Upload to board
hex:
	msp430-elf-objcopy -O ihex $(FILENAME).elf $(FILENAME).hex

msp430flasher:
	MSP430Flasher.exe -e ERASE_ALL -w $(FILENAME).hex -v -g -z [VCC]
