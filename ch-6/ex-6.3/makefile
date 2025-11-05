CC = gcc
SRC = ex-6.3.c
OBJ = ex-6.3.o
OUT = ex-6.3

all: $(OUT)

$(OUT): $(OBJ)
	@echo "Building cross-referencer..."
	$(CC) -o $@ $^

%.o: %.c
	@echo "Compiling $<"
	$(CC) -c -o $@ $<

clean:
	rm -f $(OBJ) $(OUT)
