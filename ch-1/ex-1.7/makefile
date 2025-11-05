# Simple Makefile for ex-1.7

CC = gcc
CFLAGS = -Wall
TARGET = ex-1.7
SRC = ex-1.7.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	del $(TARGET).exe 2>nul || true
