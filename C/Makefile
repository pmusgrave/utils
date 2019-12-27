CC=gcc
OPT=-Og
BUILD_DIR=build

C_SOURCES= \
sort/src/*.c \
search/src/*.c \

SORT_SOURCES= \
sort/test/test_sort.c \
sort/src/*.c \
/usr/local/include/unity/unity.c

SEARCH_SOURCES= \
search/test/test_search.c \
search/src/*.c \
/usr/local/include/unity/unity.c

DEPS= \
sort/inc/*.h \
search/inc/*.h \
/usr/local/include/unity/unity.h \
/usr/local/include/unity/unity_internals.h

C_INCLUDES= \
-Isort/inc \
-Isearch/inc \
-I/usr/local/include/unity

LIBS=
CFLAGS = $(OPT) $(C_INCLUDES) $(LIBS) -Wall

$(BUILD_DIR)%.o: $(C_SOURCES) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(TEST_SOURCES)
	$(CC) $(CFLAGS) $(SORT_SOURCES) -o sort/test/test_sort
	sort/test/test_sort
	$(CC) $(CFLAGS) $(SEARCH_SOURCES) -o search/test/test_search
	search/test/test_search

.PHONY: all test clean
clean:
	rm -f $(BUILD_DIR)/*
	rm -f test/*.o
