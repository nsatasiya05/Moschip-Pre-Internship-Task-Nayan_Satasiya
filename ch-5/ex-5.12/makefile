CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = ex-5.12
SRC = ex-5.12.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
