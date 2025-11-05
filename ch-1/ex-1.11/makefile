# Makefile for ex-1.11 (Word Count Program)

CC = gcc
CFLAGS = -Wall
TARGET = ex-1.11
SRC = ex-1.11.c

# Default: compile program
all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Run program manually (type input or redirect from file)
run: all
	./$(TARGET)

# Clean up build files
clean:
	del $(TARGET).exe 2>nul || true
