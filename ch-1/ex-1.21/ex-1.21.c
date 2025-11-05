#include <stdio.h>

#define TABSTOP 8

int main(void) {
    int c, space_count = 0, pos = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            space_count++;
            if (pos % TABSTOP == TABSTOP - 1) {
                putchar('\t');
                space_count = 0;
            }
            pos++;
        } else {
            while (space_count > 0) {
                putchar(' ');
                space_count--;
            }
            putchar(c);
            pos++;

            if (c == '\n')
                pos = 0;
        }
    }

    return 0;
}
