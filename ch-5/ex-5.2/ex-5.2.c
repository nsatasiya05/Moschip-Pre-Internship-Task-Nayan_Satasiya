#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getfloat(float *pn)
{
    int c, sign;
    float power;

    while (isspace(c = getch())) // skip whitespace
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int d = getch();
        if (!isdigit(d) && d != '.') {
            ungetch(d);
            ungetch(c);
            return 0;
        }
        c = d;
    }

    for (*pn = 0; isdigit(c); c = getch())  // integer part
        *pn = 10 * (*pn) + (c - '0');

    if (c == '.')  // fractional part
        c = getch();

    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10 * (*pn) + (c - '0');
        power *= 10;
    }

    *pn = sign * (*pn) / power;

    if (c != EOF)
        ungetch(c);

    return c;
}

/* getch/ungetch */
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
    float f;
    while (getfloat(&f) != EOF)
        printf("Got float: %f\n", f);
    return 0;
}
