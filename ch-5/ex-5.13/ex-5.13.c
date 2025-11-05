#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 1000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines, int n);
int getline_custom(char *, int);

int main(int argc, char *argv[]) {
    int n = 10;
    if (argc == 2 && (*argv[1] == '-'))
        n = atoi(argv[1] + 1);

    int nlines = readlines(lineptr, MAXLINES);
    if (nlines < 0) {
        printf("error: input too big\n");
        return 1;
    }
    writelines(lineptr, nlines, n);
    return 0;
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines = 0;
    char *p, line[MAXLEN];

    while ((len = getline_custom(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
        else {
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines, int n) {
    int start = nlines - n;
    if (start < 0) start = 0;

    for (int i = start; i < nlines; i++)
        printf("%s", lineptr[i]);
}

int getline_custom(char *s, int lim) {
    int c, i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n') s[i++] = c;
    s[i] = '\0';
    return i;
}
