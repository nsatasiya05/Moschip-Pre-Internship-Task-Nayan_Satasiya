# Makefile to compile word_per_line.c

CC = gcc
CFLAGS = -Wall
TARGET = word_per_line

all: $(TARGET)

$(TARGET): word_per_line.c
	$(CC) $(CFLAGS) -o $(TARGET) word_per_line.c

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
