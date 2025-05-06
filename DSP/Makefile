CC=gcc
CFLAGS= -Wall -Werror -ggdb
LDFLAGS=

# All A-Files
FILES_A= FFT.c
TARGET_A= fft
TESTFILES_A= FFTTest.c
TESTTARGET_A= fftTest

# All B-Files
FILES_B= FIR.c
TARGET_B= fir
TESTFILES_B= FIRTest.c
TESTTARGET_B= firTest

# All C-Files
FILES_C= FourierTransform.c
TARGET_C= fourierTransform
TESTFILES_C= FourierTransformTest.c
TESTTARGET_C= fourierTransformTest

# All D-Files
FILES_D= IIR.c
TARGET_D= iir
TESTFILES_D= IIRTest.c
TESTTARGET_D= iirTest

# All Targets
#TARGETS= $(TARGET_A) 
TESTTARGETS= $(TESTTARGET_A) $(TESTTARGET_B) $(TESTTARGET_C) $(TESTTARGET_D)

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

# D-Test Files
$(TESTTARGET_D): $(TESTFILES_D)
	$(CC) $(CFLAGS) $(TESTFILES_D) $(FILES_D) $(LDFLAGS) -o $(TESTTARGET_D)

make clean:
	rm -f $(wildcard *.o) $(TESTTARGETS)





