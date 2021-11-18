CC = avr-gcc
#CONFIGURE BINS
BINS = moduleTest


MY_INCLUDES = ./

CFLAGS = -Os -DF_CPU=16000000UL -mmcu=atmega328p -I $(MY_INCLUDES)

all: $(BINS)

MCU = ATMEGA328P
USBPORT = com4
AVRDUDE_WRITE_FLASH = -U flash:w:$<
BAUD_RATE = -b 115200

%.out: %.c
	$(CC) $(CFLAGS) $< -o $@

#Extract the EEPROM segment out of the .o file and convert it to .hex
%.hex: %.out
	avr-objcopy -O ihex -R .eeprom $< $@

install.%: %.hex
	avrdude -F -V -c arduino -p $(MCU) -P $(USBPORT) $(BAUD_RATE) $(AVRDUDE_WRITE_FLASH)

clean:
	rm -f *.hex *.out $(BINS)


#to install > make install.filename