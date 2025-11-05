#include <stdio.h>

/*
 * Function: rightrot
 * ------------------
 * Returns the value of x rotated to the right by n bit positions.
 */
unsigned rightrot(unsigned x, int n) {
    int bits = sizeof(x) * 8;
    n = n % bits;
    return (x >> n) | (x << (bits - n));
}

int main() {
    unsigned x = 170; // 10101010 in binary
    int n = 3;
    unsigned result = rightrot(x, n);

    printf("x = %u\n", x);
    printf("Result after rotating right by %d bits = %u\n", n, result);
    return 0;
}
