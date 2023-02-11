CC=gcc
CFLAGS= -Wall -Werror -ggdb
LDFLAGS=

# All A-Files
FILES_A= Odometry2Wheel.c
TARGET_A= odometry2Wheel
TESTFILES_A= Odometry2WheelTest.c
TESTTARGET_A= odometry2WheelTest

# All Targets
#TARGETS= $(TARGET_A) 
TESTTARGETS= $(TESTTARGET_A)

#make all: $(TARGETS)

# A-Files
#$(TARGET_A): $(FILES_A)
#	$(CC) $(CFLAGS) $(FILES_A) $(LDFLAGS) -o $(TARGET_A)

make tests: $(TESTTARGETS)

# A-Test Files
$(TESTTARGET_A): $(TESTFILES_A)
	$(CC) $(CFLAGS) $(TESTFILES_A) $(FILES_A) $(LDFLAGS) -o $(TESTTARGET_A)

make clean:
	rm -f $(wildcard *.o) $(TESTTARGETS)





