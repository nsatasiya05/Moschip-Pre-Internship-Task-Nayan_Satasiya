CC = gcc
SRC = ex-4.7.c
OBJ = ex-4.7.o
OUT = ex-4.7

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
