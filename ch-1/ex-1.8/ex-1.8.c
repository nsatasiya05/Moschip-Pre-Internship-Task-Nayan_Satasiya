#include <stdio.h>

int main(void)
{
    int c;              // Variable to store each character
    int blanks = 0;     // Counter for spaces
    int tabs = 0;       // Counter for tabs
    int newlines = 0;   // Counter for newlines

    // Read input until EOF (Ctrl + Z on Windows, Ctrl + D on Linux)
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++blanks;
        else if (c == '\t')
            ++tabs;
        else if (c == '\n')
            ++newlines;
    }

    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);

    return 0;
}
