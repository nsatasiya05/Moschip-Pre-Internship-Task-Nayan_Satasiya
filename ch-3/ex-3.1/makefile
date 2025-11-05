CC = gcc
CFLAGS = -Wall -O2

all: binary_search

binary_search: binary_search.o
	$(CC) $(CFLAGS) -o binary_search binary_search.o

binary_search.o: binary_search.c

clean:
	rm -f *.o binary_search
