# Simple Makefile for Hello World program

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -mconsole

# Target executable name
TARGET = ex1_1.exe

# Source file
SRC = ex1_1.c

# Build rule
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	del $(TARGET)
