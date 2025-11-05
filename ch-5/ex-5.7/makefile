CC = gcc
SRC = ex-5.7.c
OBJ = ex-5.7.o
OUT = ex-5.7

all: $(OUT)

$(OUT): $(OBJ)
	@echo "Building the file..."
	$(CC) -o $@ $^

%.o: %.c
	@echo "Compiling the file..."
	$(CC) -c -o $@ $^

clean:
	rm -f $(OBJ) $(OUT)
