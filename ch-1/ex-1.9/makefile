# Makefile for ex-1.9

CC = gcc
CFLAGS = -Wall
TARGET = ex-1.9
SRC = ex-1.9.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	del $(TARGET).exe 2>nul || true
