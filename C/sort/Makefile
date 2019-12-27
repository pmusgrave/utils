CC=gcc
OPT=-Og
BUILD_DIR=build

C_SOURCES= \
src/insertionsort.c \
src/mergesort.c \
src/quicksort.c \

TEST_SOURCES= \
test/test_sort.c \
src/insertionsort.c \
src/mergesort.c \
src/quicksort.c \
/usr/local/include/unity/unity.c

DEPS= \
/usr/local/include/unity/unity.h \
/usr/local/include/unity/unity_internals.h
#inc/chapter1.h \

C_INCLUDES= \
-Iinc \
-I/usr/local/include/unity

LIBS=
CFLAGS = $(OPT) $(C_INCLUDES) $(LIBS) -Wall

$(BUILD_DIR)%.o: $(C_SOURCES) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(TEST_SOURCES)
	$(CC) $(CFLAGS) $(TEST_SOURCES) -o test/test_sort
	test/test_sort

.PHONY: all test clean
clean:
	rm -f $(BUILD_DIR)/*
	rm -f test/*.o
