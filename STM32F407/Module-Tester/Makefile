CC=arm-none-eabi-gcc
MACH=cortex-m4

#CONFIGURE FILENAME:
FILENAME = moduleTest

SRCS=$(wildcard *.c)
L=$(wildcard $(LOGIC_FILES)*.c)
C=$(wildcard $(COMPILATION_FILES)*.c)
LL=$(wildcard $(LOW_LEVEL_FILES)*.c)

SRC_OBJS=$(patsubst $(SRC)%.c, $(SRC)%.o, $(SRCS))
C_OBJS=$(patsubst $(COMPILATION_FILES)%.c, $(COMPILATION_FILES)%.o, $(C))

OBJS = $(SRC_OBJS) $(C_OBJS)


SRC = ./
COMPILATION_FILES = inc/comp_files/
MY_INCLUDES = -I $(COMPILATION_FILES)

CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -g $(MY_INCLUDES) -std=gnu11 -Wall 
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T $(COMPILATION_FILES)stm32f407_ls.ld -Wl,-Map=final.map $(MY_INCLUDES)

all: $(FILENAME)

$(FILENAME) : $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
	
final.elf: $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -rf *.o $(COMPILATION_FILES)*.o *.elf *.map

load:
	openocd -f board/stm32f4discovery.cfg
