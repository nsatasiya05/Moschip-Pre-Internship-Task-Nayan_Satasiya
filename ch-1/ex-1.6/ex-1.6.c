#include <stdio.h>

int main(void)
{
    int c;

    printf("Enter a character (press Ctrl+Z or Ctrl+D to end):\n");

    c = getchar() != EOF;

    printf("The expression getchar() != EOF evaluates to: %d\n", c);

    return 0;
}
