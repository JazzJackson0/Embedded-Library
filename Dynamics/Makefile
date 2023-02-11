CC=gcc
CFLAGS= -Wall -Werror -ggdb
LDFLAGS=

# All A-Files
FILES_A= EulerAngles.c
TARGET_A= eulerAngles
TESTFILES_A= EulerAnglesTest.c
TESTTARGET_A= eulerAnglesTest

# All B-Files
FILES_B= Quaternions.c
TARGET_B= quaternions
TESTFILES_B= QuaternionsTest.c
TESTTARGET_B= quaternionsTest

# All C-Files
FILES_C= RotationMatrix.c
TARGET_C= rotationMatrix
TESTFILES_C= RotationMatrixTest.c
TESTTARGET_C= rotationMatrixTest

# All Targets
#TARGETS= $(TARGET_A) 
TESTTARGETS= $(TESTTARGET_A) $(TESTTARGET_B) $(TESTTARGET_C)

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

# C-Test Files
$(TESTTARGET_C): $(TESTFILES_C)
	$(CC) $(CFLAGS) $(TESTFILES_C) $(FILES_C) $(LDFLAGS) -o $(TESTTARGET_C)

make clean:
	rm -f $(wildcard *.o) $(TESTTARGETS)





