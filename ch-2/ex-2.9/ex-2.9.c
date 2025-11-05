#include <stdio.h>

/*
 * Function: bitcount
 * ------------------
 * Counts the number of 1-bits (set bits) in an unsigned integer.
 * Uses the trick: x &= (x - 1) to remove the rightmost 1-bit each time.
 */
int bitcount(unsigned x) {
    int count = 0;
    while (x) {
        x &= (x - 1);  // delete rightmost 1-bit
        count++;
    }
    return count;
}

int main() {
    unsigned x = 29; // Binary: 11101 → 4 bits set
    printf("Number: %u\n", x);
    printf("Number of 1-bits = %d\n", bitcount(x));
    return 0;
}
