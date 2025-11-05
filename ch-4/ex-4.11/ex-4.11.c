#include <stdio.h>
#include <ctype.h>

int getop(char s[]) {
    static int last = ' ';
    int i, c;

    while ((s[0] = c = last) == ' ' || c == '\t')
        c = getchar();
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;  // not a number
    i = 0;
    if (isdigit(c) || c == '-') // collect integer part
        while (isdigit(s[++i] = c = getchar()));
    if (c == '.') // collect fraction part
        while (isdigit(s[++i] = c = getchar()));
    s[i] = '\0';
    last = c;  // save last read char for next call
    return '0'; // number signal
}
