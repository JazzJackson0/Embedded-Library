CC=gcc
CFLAGS= -Wall -Werror -ggdb
LDFLAGS=

# All A-Files
FILES_A= ComplementaryFilter.c
TARGET_A= ComplementaryFilter
TESTFILES_A= ComplementaryFilterTest.c
TESTTARGET_A= ComplementaryFilterTest

# All B-Files
FILES_B= KalmanFilter.c
TARGET_B= KalmanFilter
TESTFILES_B= KalmanFilterTest.c
TESTTARGET_B= KalmanFilterTest

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





