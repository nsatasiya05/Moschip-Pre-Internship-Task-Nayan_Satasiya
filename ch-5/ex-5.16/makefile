CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = ex-5.16

$(TARGET): ex-5.16.c
	$(CC) $(CFLAGS) -o $(TARGET) ex-5.16.c

run:
	./$(TARGET) -d < input.txt

clean:
	rm -f $(TARGET)
