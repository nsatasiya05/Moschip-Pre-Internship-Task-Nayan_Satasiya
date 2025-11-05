CC = gcc
SRC = ex-4.6.c
OBJ = ex-4.6.o
OUT = ex-4.6

all: $(OUT)

$(OUT): $(OBJ)
	@echo "Building the file..."
	$(CC) -o $@ $^

%.o: %.c
	@echo "Compiling the file..."
	$(CC) -c -o $@ $^

clean:
	@echo "Cleaning up..."
	rm -f $(OBJ) $(OUT)
