CC=g++
OPT=-Og -std=c++11
BUILD_DIR=build
LIBS=
INCLUDES= \
-Ilinked-list/inc

CFLAGS = $(OPT) $(INCLUDES) $(LIBS) -Wall

linked_list: $(BUILD_DIR)/test.o $(BUILD_DIR)/doubly_linked_list.o $(BUILD_DIR)/node.o
	$(CC) $(CFLAGS) $(BUILD_DIR)/test.o $(BUILD_DIR)/doubly_linked_list.o $(BUILD_DIR)/node.o -o $(BUILD_DIR)/test
	$(BUILD_DIR)/test

$(BUILD_DIR)/test.o: linked-list/test/test_doubly_linked_list.cpp
	$(CC) $(CFLAGS) -c linked-list/test/test_doubly_linked_list.cpp -o $(BUILD_DIR)/test.o

$(BUILD_DIR)/doubly_linked_list.o: linked-list/src/doubly_linked_list.cpp
	$(CC) $(CFLAGS) -c linked-list/src/doubly_linked_list.cpp -o $(BUILD_DIR)/doubly_linked_list.o

$(BUILD_DIR)/node.o: linked-list/src/node.cpp
	$(CC) $(CFLAGS) -c linked-list/src/node.cpp -o $(BUILD_DIR)/node.o

.PHONY: all test clean
clean:
	rm -f $(BUILD_DIR)/*
	rm -f test/*.o
