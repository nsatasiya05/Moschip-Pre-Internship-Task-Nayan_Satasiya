#include <stdio.h>

int buf;
int buf_full = 0;

int getch(void) {
    if (buf_full) {
        buf_full = 0;
        return buf;
    } else
        return getchar();
}

void ungetch(int c) {
    if (buf_full)
        printf("ungetch: buffer full\n");
    else {
        buf = c;
        buf_full = 1;
    }
}

int main(void) {
    ungetch(EOF);
    int c = getch();
    if (c == EOF)
        printf("EOF correctly handled\n");
    else
        printf("Character: %c\n", c);
    return 0;
}
