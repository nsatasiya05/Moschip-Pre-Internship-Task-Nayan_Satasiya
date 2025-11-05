CC = gcc
CFLAGS = -Wall -O2

all: escape

escape: escape.o
	$(CC) $(CFLAGS) -o escape escape.o

escape.o: escape.c

clean:
	rm -f *.o escape
