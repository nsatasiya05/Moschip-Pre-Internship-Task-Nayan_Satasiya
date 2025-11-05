CC = gcc
SRC = ex-4.5.c
OBJ = ex-4.5.o
OUT = ex-4.5

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
