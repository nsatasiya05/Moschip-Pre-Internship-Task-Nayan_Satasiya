#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define TABINC 8

void detab(int tabstops[], int n);
void entab(int tabstops[], int n);

int main(int argc, char *argv[]) {
    int tabstops[MAXLINE];
    int n = 0;

    for (int i = 1; i < argc; i++)
        tabstops[n++] = atoi(argv[i]);

    printf("Detab output:\n");
    detab(tabstops, n);

    printf("\nEntab output:\n");
    entab(tabstops, n);

    return 0;
}

void detab(int tabstops[], int n) {
    int c, pos = 1, nexttab = TABINC;
    int i = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = nexttab - (pos - 1);
            while (spaces-- > 0) {
                putchar(' ');
                pos++;
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            pos++;
        }
        if (n > 0 && i < n) nexttab = tabstops[i++];
        else nexttab += TABINC;
    }
}

void entab(int tabstops[], int n) {
    int c, pos = 1;
    int nb = 0, nt = 0;
    int nexttab = TABINC, i = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (pos == nexttab) {
                nt++;
                nb = 0;
                if (n > 0 && i < n) nexttab = tabstops[i++];
                else nexttab += TABINC;
            } else
                nb++;
            pos++;
        } else {
            while (nt-- > 0)
                putchar('\t');
            while (nb-- > 0)
                putchar(' ');

            if (c == '\n') pos = 1;
            else pos++;

            putchar(c);
        }
    }
}
