CC = g++
CFLAGS = -Wall -g

LIBS = SDL2main SDL2
TARGET = main
TEST = test
SRCS=$(wildcard *.cpp)
SRCS := $(filter-out test.cpp, $(SRCS))
TEST_SRCS=$(wildcard *test.cpp)
HDRS=$(wildcard *.hpp)
LDFLAGS += $(foreach library,$(LIBS),-l$(library))

all: $(SRCS)
	$(CC) -o $(TARGET) $(SRCS) $(HDRS) $(CFLAGS) $(LDFLAGS)

test: $(TEST_SRCS)
	$(CC) -o $(TEST) $(TEST_SRCS) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGET) $(TARGET).o
	rm -f $(TEST) $(TEST).o
