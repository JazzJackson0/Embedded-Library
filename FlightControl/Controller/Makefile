CC=gcc
CFLAGS= -Wall -Werror -ggdb
LDFLAGS=

# All A-Files
FILES_A= MotorMixAlgo.c
TARGET_A= motorMixAlgo
TESTFILES_A= MotorMixAlgoTest.c
TESTTARGET_A= motorMixAlgoTest

# All B-Files
FILES_B= Thrust.c
TARGET_B= thrust
TESTFILES_B= ThrustTest.c
TESTTARGET_B= thrustTest

# All Targets
#TARGETS= $(TARGET_A) 
TESTTARGETS= $(TESTTARGET_A) $(TESTTARGET_B)

#make all: $(TARGETS)

# A-Files
#$(TARGET_A): $(FILES_A)
#	$(CC) $(CFLAGS) $(FILES_A) $(LDFLAGS) -o $(TARGET_A)

make tests: $(TESTTARGETS)

# A-Test Files
$(TESTTARGET_A): $(TESTFILES_A)
	$(CC) $(CFLAGS) $(TESTFILES_A) $(FILES_A) $(LDFLAGS) -o $(TESTTARGET_A)

# B-Test Files
$(TESTTARGET_B): $(TESTFILES_B)
	$(CC) $(CFLAGS) $(TESTFILES_B) $(FILES_B) $(LDFLAGS) -o $(TESTTARGET_B)

make clean:
	rm -f $(wildcard *.o) $(TESTTARGETS)