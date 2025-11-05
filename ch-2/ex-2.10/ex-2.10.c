#include <stdio.h>

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

int main()
{
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    printf("Lowercase version: %c\n", lower(ch));

    return 0;
}
