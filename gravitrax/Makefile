# Define the compiler
CC = gcc

# Define the compiler flags
CFLAGS = `pkg-config --cflags gtk+-3.0`

# Define the linker flags
LDFLAGS = `pkg-config --libs gtk+-3.0`

# Define the target executable
TARGET = gui

# Define the source file
SRCS = gui.c

# Define the object files (by replacing .c with .o)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Rule to link the target executable
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Rule to compile the source files
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
