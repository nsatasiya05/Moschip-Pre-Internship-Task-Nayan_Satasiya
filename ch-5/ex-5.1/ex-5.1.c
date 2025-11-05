#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))  // skip white space
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);   // not a number
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int d = getch();
        if (!isdigit(d)) {  // if next is not digit
            ungetch(d);
            ungetch(c);
            return 0;
        }
        c = d;
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * (*pn) + (c - '0');

    *pn *= sign;
    if (c != EOF)
        ungetch(c);

    return c;
}

/* Simple getch/ungetch */
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* Test main */
int main(void)
{
    int n, result;
    while ((result = getint(&n)) != EOF)
        printf("Got integer: %d\n", n);
    return 0;
}
