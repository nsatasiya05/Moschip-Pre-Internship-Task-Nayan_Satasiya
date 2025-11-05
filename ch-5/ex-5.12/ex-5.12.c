#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TABINC 8
#define MAXLINE 1000

int m = 0, n = TABINC;

void setargs(int argc, char *argv[]) {
    while (--argc > 0) {
        char *arg = *++argv;
        if (*arg == '-')
            m = atoi(arg + 1);
        else if (*arg == '+')
            n = atoi(arg + 1);
    }
}

void detab(void) {
    int c, pos = 1;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            do {
                putchar(' ');
                pos++;
            } while ((pos - m - 1) % n != 0);
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            pos++;
        }
    }
}

int main(int argc, char *argv[]) {
    setargs(argc, argv);
    detab();
    return 0;
}
