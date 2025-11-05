CC = gcc
CFLAGS = -Wall -g

OBJ = main.o getop.o stack.o
TARGET = calc

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
