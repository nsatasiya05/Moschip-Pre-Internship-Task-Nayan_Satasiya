#include <stdio.h>

int main()
{
    int c;
    int paren = 0, bracket = 0, brace = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '(')
            paren++;
        if (c == ')')
            paren--;
        if (c == '[')
            bracket++;
        if (c == ']')
            bracket--;
        if (c == '{')
            brace++;
        if (c == '}')
            brace--;
    }

    if (paren == 0 && bracket == 0 && brace == 0)
        printf("No syntax errors.\n");
    else
    {
        if (paren != 0)
            printf("Unmatched parentheses.\n");
        if (bracket != 0)
            printf("Unmatched brackets.\n");
        if (brace != 0)
            printf("Unmatched braces.\n");
    }

    return 0;
}
