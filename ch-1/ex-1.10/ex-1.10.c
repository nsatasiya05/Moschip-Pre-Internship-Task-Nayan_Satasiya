#include <stdio.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')          // When tab is found
            printf("\\t");      // Print visible \t
        else if (c == '\b')     // When backspace is found
            printf("\\b");      // Print visible \b
        else if (c == '\\')     // When backslash is found
            printf("\\\\");     // Print visible \\
        else
            putchar(c);         // Otherwise print the character itself
    }

    return 0;
}
