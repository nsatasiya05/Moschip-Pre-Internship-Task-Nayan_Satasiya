CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = ex-5.17

$(TARGET): ex-5.17.c
	$(CC) $(CFLAGS) -o $(TARGET) ex-5.17.c

run:
	./$(TARGET) 2 < input.txt   # sort by 2nd field

clean:
	rm -f $(TARGET)
