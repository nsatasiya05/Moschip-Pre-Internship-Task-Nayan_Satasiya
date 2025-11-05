# Makefile for Word Histogram Program

CC = gcc
CFLAGS = -Wall
TARGET = ex-1.13
SRC = ex-1.13.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	del $(TARGET).exe 2>nul || rm -f $(TARGET)
