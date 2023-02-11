CC=gcc
CFLAGS= -Wall -Werror -ggdb
LDFLAGS=

# All A-Files
FILES_A= ComplexNums.c
TARGET_A= complexNums
TESTFILES_A= ComplexNumsTest.c
TESTTARGET_A= complexNumsTest

# All B-Files
FILES_B= MatrixDisplay.c
TARGET_B= matrixDisplay
TESTFILES_B= MatrixDisplayTest.c
TESTTARGET_B= matrixDisplayTest

# All C-Files
FILES_C= MatrixMath.c
TARGET_C= matrixMath
TESTFILES_C= MatrixMathTest.c
TESTTARGET_C= matrixMathTest

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





