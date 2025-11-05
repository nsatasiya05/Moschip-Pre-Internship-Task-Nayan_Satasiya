CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = ex-5.11
SRC = ex-5.11.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
