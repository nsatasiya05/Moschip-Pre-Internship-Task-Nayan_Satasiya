# Makefile for Exercise 5.9 - Pointer version of day_of_year and month_day

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

TARGET = ex-5.9
SRC = ex-5.9.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)
