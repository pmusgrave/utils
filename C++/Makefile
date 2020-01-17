CC=g++
OPT=-Og -std=c++11
BUILD_DIR=build

CPP_SOURCES= \
$(FFT_SOURCES) \
$(LINKED_LIST_SOURCES)

FFT_SOURCES = \
fft/src/*.cpp \

LINKED_LIST_SOURCES= \
linked-list/src/*.cpp \
linked-list/test/*.cpp

DEPS= \
hello_world/inc/*.hpp \
fft/int/*.hpp

CPP_INCLUDES= \
-Ifft/inc \
-Ilinked-list/inc

LIBS=
CFLAGS = $(OPT) $(CPP_INCLUDES) $(LIBS) -Wall

all: linked-list fft test

$(BUILD_DIR)%.o: $(CPP_SOURCES) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

linked-list: $(LINKED_LIST_SOURCES)
	$(CC) $(CFLAGS) $(LINKED_LIST_SOURCES) -o linked-list/test/linked-list-test
	linked-list/test/linked-list-test

fft: $(FFT_SOURCES)
	$(CC) $(CFLAGS) $(FFT_SOURCES) -o fft/test/fft_test
	fft/test/test

.PHONY: all test clean fft linked-list
clean:
	rm -f $(BUILD_DIR)/*
	rm -f test/*.o
