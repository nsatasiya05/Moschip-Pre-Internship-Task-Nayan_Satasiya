#include <stdio.h>

int main(void)
{
    int c;
    int last_char = 0;  // Stores the last character read

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (last_char != ' ')   // Print only the first space
                putchar(c);
        }
        else
        {
            putchar(c);             // Print all non-space characters
        }

        last_char = c;              // Update last character
    }

    return 0;
}
