CC = avr-gcc
#CONFIGURE BINS
BINS = filename

SRC = ./
LOW_LEVEL_FILES = inc/low_level/
LOGIC_FILES = inc/logic/
MY_INCLUDES = -I$(LOW_LEVEL_FILES) -I$(LOGIC_FILES)

CFLAGS = -Os -DF_CPU=16000000UL -mmcu=atmega328p $(MY_INCLUDES)
MCU = ATMEGA328P
USBPORT = com4
AVRDUDE_WRITE_FLASH = -U flash:w:$<
BAUD_RATE = -b 115200

SRCS=$(wildcard *.c)
L=$(wildcard $(LOW_LEVEL_FILES)*.c)
LL=$(wildcard $(LOGIC_FILES)*.c)

SRC_OBJS=$(patsubst $(SRC)%.c, $(SRC)%.o, $(SRCS))
L_OBJS=$(patsubst $(LOGIC_FILES)%.c, $(LOGIC_FILES)%.o, $(L))
LL_OBJS=$(patsubst $(LOW_LEVEL_FILES)%.c, $(LOW_LEVEL_FILES)%.o, $(LL))

OBJS = $(SRC_OBJS) $(LL_OBJS) $(L_OBJS)

all: $(BINS) $(BINS).out

$(BINS) : $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -o $@

#Used for the .hex extraction
$(BINS).out : $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -o $@

#Extract the EEPROM segment out of the .o file and convert it to .hex
%.hex: $(BINS)
	avr-objcopy -O ihex -R .eeprom $< $@

install.%: %.hex
	avrdude -F -V -c arduino -p $(MCU) -P $(USBPORT) $(BAUD_RATE) $(AVRDUDE_WRITE_FLASH)

clean:
	rm -f *.hex *.out $(LOW_LEVEL_FILES)*.o $(LOGIC_FILES)*.o $(BINS)


#to install > make install.filename