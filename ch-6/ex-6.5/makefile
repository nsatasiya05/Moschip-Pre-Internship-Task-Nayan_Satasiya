CC = gcc
SRC = ex-6.5.c
OBJ = ex-6.5.o
OUT = ex-6.5

all: $(OUT)

$(OUT): $(OBJ)
	@echo "Building undef() program..."
	$(CC) -o $@ $^

%.o: %.c
	@echo "Compiling $<"
	$(CC) -c -o $@ $<

clean:
	rm -f $(OBJ) $(OUT)
