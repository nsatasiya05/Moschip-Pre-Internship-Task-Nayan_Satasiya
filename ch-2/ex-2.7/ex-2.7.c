#include <stdio.h>

unsigned invert(unsigned x, int p, int n) {
    return x ^ (~(~0 << n) << (p + 1 - n));
}

int main() {
    unsigned x = 170; // 10101010
    int p = 5, n = 3;
    unsigned result = invert(x, p, n);

    printf("x = %u\n", x);
    printf("Result = %u\n", result);
    return 0;
}
