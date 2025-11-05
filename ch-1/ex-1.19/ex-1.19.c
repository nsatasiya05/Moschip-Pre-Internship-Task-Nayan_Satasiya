#include <stdio.h>
#define MAXLINE 1000

int getline_custom(char s[], int lim);
void reverse(char s[]);

int main()
{
    char line[MAXLINE];

    while (getline_custom(line, MAXLINE) > 0)
    {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

/* Read a line into s, return length */
int getline_custom(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* Reverse string s in place */
void reverse(char s[])
{
    int i, j;
    char temp;
    for (j = 0; s[j] != '\0'; ++j)
        ;
    j--;
    if (s[j] == '\n')
        j--;
    for (i = 0; i < j; ++i, --j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
