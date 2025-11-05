# Makefile for Exercise 1-16: Longest Line Program

CC = gcc
CFLAGS = -Wall
TARGET = ex-1.23
SRC = ex-1.23.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	del $(TARGET).exe 2>nul || rm -f $(TARGET)
