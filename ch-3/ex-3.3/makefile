CC = gcc
CFLAGS = -Wall -O2

all: expand

expand: expand.o
	$(CC) $(CFLAGS) -o expand expand.o

expand.o: expand.c

clean:
	rm -f *.o expand
