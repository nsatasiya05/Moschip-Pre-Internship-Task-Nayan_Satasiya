#include <stdio.h>
#include <string.h>

#define MAXLINES 5000   /* max number of lines to be sorted */
#define MAXLEN   1000   /* max length of any input line */
#define MAXSTORAGE 10000 /* total storage for all lines */

int readlines(char *lineptr[], char *linestor, int maxlines);
void writelines(char *lineptr[], int nlines);
int getline_custom(char *s, int lim);
void my_qsort(char *v[], int left, int right);

int main(void)
{
    char *lineptr[MAXLINES];      /* pointers to text lines */
    char linestor[MAXSTORAGE];    /* storage for all lines */
    int nlines;                   /* number of input lines read */

    if ((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0) {
        my_qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* readlines: read input lines into array supplied by main */
int readlines(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines;
    char line[MAXLEN];
    char *p = linestor;      /* next free position */
    char *linestop = linestor + MAXSTORAGE; /* end of storage */

    nlines = 0;
    while ((len = getline_custom(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || p + len > linestop)
            return -1;  /* not enough room */
        line[len - 1] = '\0';    /* delete newline */
        strcpy(p, line);
        lineptr[nlines++] = p;
        p += len;
    }
    return nlines;
}

/* getline_custom: read a line into s, return length */
int getline_custom(char *s, int lim)
{
    int c;
    char *start = s;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - start;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* my_qsort: sort v[left]...v[right] into increasing order */
void my_qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    my_qsort(v, left, last - 1);
    my_qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
