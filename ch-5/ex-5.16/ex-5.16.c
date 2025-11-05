#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort_custom(void *v[], int left, int right,
                  int (*comp)(void *, void *));
int dircmp(char *s1, char *s2);

int main(int argc, char *argv[])
{
    int nlines;
    int directory = 0;

    if (argc > 1 && strcmp(argv[1], "-d") == 0)
        directory = 1;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort_custom((void **)lineptr, 0, nlines - 1,
                     (int (*)(void *, void *))(directory ? dircmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("Input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000
int getline_custom(char *, int);

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines = 0;
    char *p, line[MAXLEN];
    while ((len = getline_custom(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
        line[len - 1] = '\0';
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    for (int i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

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

int dircmp(char *s1, char *s2)
{
    for (;; s1++, s2++)
    {
        while (*s1 && !isalnum(*s1) && *s1 != ' ')
            s1++;
        while (*s2 && !isalnum(*s2) && *s2 != ' ')
            s2++;
        if (tolower(*s1) != tolower(*s2))
            return tolower(*s1) - tolower(*s2);
        if (*s1 == '\0')
            return 0;
    }
}

void swap(void *v[], int i, int j)
{
    void *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort_custom(void *v[], int left, int right,
                  int (*comp)(void *, void *))
{
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort_custom(v, left, last - 1, comp);
    qsort_custom(v, last + 1, right, comp);
}
