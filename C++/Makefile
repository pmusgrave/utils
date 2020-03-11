CC=g++
OPT=-Og -std=c++17
BUILD_DIR=build

CPP_SOURCES= \
$(FFT_SOURCES) \
$(LINKED_LIST_SOURCES)

FFT_SOURCES = \
fft/src/*.cpp \
fft/test/*.cpp

LINKED_LIST_SOURCES= \
linked-list/src/doubly_linked_list.cpp \
linked-list/src/node.cpp

GRAPHS_SOURCES = \
graphs/src/*.cpp \
graphs/test/*.cpp

DEPS= \
linked-list/inc/*.hpp \
fft/inc/*.hpp \
graphs/inc/*.hpp

CPP_INCLUDES= \
-Ilinked-list/inc \
-Ifft/inc \
-Igraphs/inc

LIBS=
CFLAGS = $(OPT) $(CPP_INCLUDES) $(LIBS) -Wall

all: linked-list fft graphs test

$(BUILD_DIR)%.o: $(CPP_SOURCES) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

linked-list: $(DEPS) $(BUILD_DIR)/linked-list-test.o $(BUILD_DIR)/doubly_linked_list.o $(BUILD_DIR)/node.o
	$(CC) $(CFLAGS) $(BUILD_DIR)/linked-list-test.o $(BUILD_DIR)/doubly_linked_list.o $(BUILD_DIR)/node.o -o linked-list/test/linked-list-test
	ar rvs linked-list/lib/doubly_linked_list.a $(BUILD_DIR)/doubly_linked_list.o
	ar rvs linked-list/lib/node.a $(BUILD_DIR)/node.o
	linked-list/test/linked-list-test

$(BUILD_DIR)/linked-list-test.o: linked-list/test/test_doubly_linked_list.cpp
	$(CC) $(CFLAGS) -c linked-list/test/test_doubly_linked_list.cpp -o $(BUILD_DIR)/linked-list-test.o

$(BUILD_DIR)/doubly_linked_list.o: linked-list/src/doubly_linked_list.cpp
	$(CC) $(CFLAGS) -c linked-list/src/doubly_linked_list.cpp -o $(BUILD_DIR)/doubly_linked_list.o

$(BUILD_DIR)/node.o: linked-list/src/node.cpp
	$(CC) $(CFLAGS) -c linked-list/src/node.cpp -o $(BUILD_DIR)/node.o

fft: $(FFT_SOURCES)
	$(CC) $(CFLAGS) $(FFT_SOURCES) -o fft/test/test_fft
	fft/test/test_fft

graphs: $(GRAPHS_SOURCES)
	$(CC) $(CFLAGS) $(GRAPHS_SOURCES) -o graphs/test/test_graphs
	graphs/test/test_graphs

.PHONY: all test clean fft linked-list
clean:
	rm -f $(BUILD_DIR)/*
	rm -f test/*.o
	rm -f linked-list/lib/*
	rm -f linked-list/test/linked-list-test
