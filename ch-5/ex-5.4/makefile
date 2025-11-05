CC = gcc
SRC = ex-5.4.c
OBJ = ex-5.4.o
OUT = ex-5.4

all: $(OUT)

$(OUT): $(OBJ)
	@echo "Building the file..."
	$(CC) -o $@ $^

%.o: %.c
	@echo "Compiling the file..."
	$(CC) -c -o $@ $^

clean:
	rm -f $(OBJ) $(OUT)
