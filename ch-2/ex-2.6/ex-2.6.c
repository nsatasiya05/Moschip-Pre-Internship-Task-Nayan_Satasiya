#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // Step 1: Create mask for n bits
    unsigned mask = ~(~0 << n);

    // Step 2: Take rightmost n bits of y
    unsigned y_bits = y & mask;

    // Step 3: Clear n bits in x starting from position p
    x = x & ~(mask << (p + 1 - n));

    // Step 4: Insert y_bits into x
    x = x | (y_bits << (p + 1 - n));

    return x;
}

int main() {
    unsigned x = 0b10101010;  // 170 in decimal
    unsigned y = 0b00001111;  // 15 in decimal
    int p = 5, n = 3;
    printf("Result = %u\n", setbits(x, p, n, y));
    return 0;
}
