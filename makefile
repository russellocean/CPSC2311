# Compiler and flags definition
CC=gcc
CFLAGS=-Wall -g
LFLAGS=-lm
TARGET=out

# Collect all C source files and header files from the root and src directories
C_SRCS := \
  $(wildcard *.c) \
  $(wildcard src/*.c) \
  $(wildcard src/**/*.c)
HDRS := \
  $(wildcard *.h) \
  $(wildcard src/*.h) \
  $(wildcard src/**/*.h)

# Generate list of object files from source files, stored in bin/ directory
OBJS := $(patsubst %.c, bin/%.o, $(wildcard *.c))
OBJS += $(filter %.o, $(patsubst src/%.c, bin/%.o, $(C_SRCS)))

# Default target, builds the project
all: build
		@echo "All Done"

# Link all object files into the final executable
build: $(OBJS)
		$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

# Compile root directory source files into object files, stored in bin/ directory
bin/%.o: %.c $(HDRS)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

# Compile nested directory source files into object files, stored in bin/ directory
bin/%.o: src/%.c $(HDRS)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

# Clean up the project by removing the executable and the bin/ directory
clean:
		rm -f $(TARGET)
		rm -rf bin

# Build and run the project with input.txt and output.txt, then with input2.txt and output2.txt
run: build
		./$(TARGET) input.txt output.txt
		./$(TARGET) input2.txt output2.txt

# Display the source files, header files, and object files used in the project
which:
		@echo "FOUND SOURCES: ${C_SRCS}"
		@echo "FOUND HEADERS: ${HDRS}"
		@echo "TARGET OBJS: ${OBJS}"