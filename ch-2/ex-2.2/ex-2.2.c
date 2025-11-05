#include <stdio.h>

int main(void)
{
    int i, c;
    int lim = 100;
    char s[100];

    for (i = 0; i < lim - 1; ++i) {
        c = getchar();
        if (c == '\n')
            break;
        if (c == EOF)
            break;
        s[i] = c;
    }
    s[i] = '\0';

    printf("\nYou entered: %s\n", s);
    return 0;
}
