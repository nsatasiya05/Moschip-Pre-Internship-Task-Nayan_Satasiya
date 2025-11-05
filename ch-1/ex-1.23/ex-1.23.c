#include <stdio.h>

int main(void) {
    int c, d;
    while ((c = getchar()) != EOF) {
        if (c == '/') {
            d = getchar();
            if (d == '*') {  // comment start
                int e;
                while ((e = getchar()) != EOF) {
                    if (e == '*' && (d = getchar()) == '/')
                        break; // end comment
                }
            } else {
                putchar(c);
                putchar(d);
            }
        } else {
            putchar(c);
        }
    }
    return 0;
}
