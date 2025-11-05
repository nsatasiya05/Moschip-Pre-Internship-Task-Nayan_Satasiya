#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n')
            putchar('\n');  // print newline for word separation
        else
            putchar(c);     // print the character
    }

    return 0;
}
