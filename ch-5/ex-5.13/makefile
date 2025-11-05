CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = ex-5.13
SRC = ex-5.13.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
