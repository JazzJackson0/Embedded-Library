CC=arm-none-eabi-gcc
MACH=cortex-m4

#CONFIGURE FILENAME:
FILENAME = filename

SRCS=$(wildcard *.c)
L=$(wildcard $(LOGIC_FILES)*.c)
C=$(wildcard $(COMPILATION_FILES)*.c)
LL=$(wildcard $(LOW_LEVEL_FILES)*.c)

SRC_OBJS=$(patsubst $(SRC)%.c, $(SRC)%.o, $(SRCS))
L_OBJS=$(patsubst $(LOGIC_FILES)%.c, $(LOGIC_FILES)%.o, $(L))
LL_OBJS=$(patsubst $(LOW_LEVEL_FILES)%.c, $(LOW_LEVEL_FILES)%.o, $(LL))
C_OBJS=$(patsubst $(COMPILATION_FILES)%.c, $(COMPILATION_FILES)%.o, $(C))

OBJS = $(SRC_OBJS) $(L_OBJS) $(LL_OBJS) $(C_OBJS)


SRC = ./
COMPILATION_FILES = inc/comp_files/
LOW_LEVEL_FILES = inc/low_level/
LOGIC_FILES = inc/logic/
MY_INCLUDES = -I $(COMPILATION_FILES) -I $(LOW_LEVEL_FILES) -I $(LOGIC_FILES)

CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -g $(MY_INCLUDES) -std=gnu11 -Wall 
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T $(COMPILATION_FILES)stm32f446_ls.ld -Wl,-Map=final.map $(MY_INCLUDES)

all: $(FILENAME) final.elf

$(FILENAME) : $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
	
final.elf: $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -rf *.o $(COMPILATION_FILES)*.o $(LOW_LEVEL_FILES)*.o  $(LOGIC_FILES)*.o *.elf *.map

load:
	openocd -f board/stm32f4discovery.cfg
