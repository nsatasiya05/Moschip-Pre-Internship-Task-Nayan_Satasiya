#include <stdio.h>

int strend(char *s, char *t);

int main() {
    char s[] = "hello world";
    char t[] = "world";
    if (strend(s, t))
        printf("'%s' occurs at the end of '%s'\n", t, s);
    else
        printf("'%s' does not occur at the end of '%s'\n", t, s);
    return 0;
}

int strend(char *s, char *t) {
    char *bs = s;
    char *bt = t;

    while (*s)
        s++;
    while (*t)
        t++;

    while (t > bt && s > bs)
        if (*--s != *--t)
            return 0;

    return (t == bt);
}
