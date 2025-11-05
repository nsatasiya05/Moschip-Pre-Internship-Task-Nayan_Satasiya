#include<stdio.h>

#define FOLD_COL 20

int main(void) {
    int c, col = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            col = 0;
        } else if (col >= FOLD_COL) {
            putchar('\n');
            putchar(c);
            col = 1;
        } else {
            putchar(c);
            col++;
        }
    }

    return 0;
}
