CC = gcc
SRC = ex-6.6.c
OBJ = ex-6.6.o
OUT = ex-6.6

all: $(OUT)

$(OUT): $(OBJ)
	@echo "Building #define processor..."
	$(CC) -o $@ $^

%.o: %.c
	@echo "Compiling $<"
	$(CC) -c -o $@ $<

clean:
	rm -f $(OBJ) $(OUT)
