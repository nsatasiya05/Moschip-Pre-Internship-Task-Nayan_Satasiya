CC = gcc
SRC = ex-4.10.c
OBJ = ex-4.10.o
OUT = ex-4.10

all: $(OUT)

$(OUT): $(OBJ)
	@echo "Building the file..."
	$(CC) -o $@ $^ -lm

%.o: %.c
	@echo "Compiling the file..."
	$(CC) -c -o $@ $^

clean:
	@echo "Cleaning up..."
	rm -f $(OBJ) $(OUT)
