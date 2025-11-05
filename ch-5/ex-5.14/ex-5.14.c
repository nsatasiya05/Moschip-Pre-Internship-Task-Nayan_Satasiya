#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort_custom(void *v[], int left, int right,
                  int (*comp)(void *, void *), int reverse);
int numcmp(char *, char *);

int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    int reverse = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
    {
        char c;
        while ((c = *++argv[0]))
        {
            if (c == 'n')
                numeric = 1;
            else if (c == 'r')
                reverse = 1;
            else
                printf("Invalid option: %c\n", c);
        }
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort_custom((void **)lineptr, 0, nlines - 1,
                     (int (*)(void *, void *))(numeric ? numcmp : strcmp),
                     reverse);
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
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
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

int numcmp(char *s1, char *s2)
{
    double v1 = atof(s1), v2 = atof(s2);
    return (v1 < v2) ? -1 : (v1 > v2);
}

void swap(void *v[], int i, int j)
{
    void *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort_custom(void *v[], int left, int right,
                  int (*comp)(void *, void *), int reverse)
{
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        int cmp = (*comp)(v[i], v[left]);
        if ((reverse && cmp > 0) || (!reverse && cmp < 0))
            swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort_custom(v, left, last - 1, comp, reverse);
    qsort_custom(v, last + 1, right, comp, reverse);
}
