CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = ex-5.15

$(TARGET): ex-5.15.c
	$(CC) $(CFLAGS) -o $(TARGET) ex-5.15.c

run:
	./$(TARGET) -f < input.txt

clean:
	rm -f $(TARGET)
