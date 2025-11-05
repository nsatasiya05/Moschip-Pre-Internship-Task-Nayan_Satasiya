#include <stdio.h>

int buf = 0;       // holds one pushed-back character
int buf_full = 0;  // 1 if buf is full

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
    int c;
    c = getchar();
    ungetch(c);
    printf("Got back: %c\n", getch());
    return 0;
}
