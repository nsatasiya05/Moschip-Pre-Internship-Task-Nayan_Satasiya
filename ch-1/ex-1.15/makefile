# Makefile for Celsius to Fahrenheit Conversion using Function

CC = gcc
CFLAGS = -Wall
TARGET = ex-1.15
SRC = ex-1.15.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	del $(TARGET).exe 2>nul || rm -f $(TARGET)
