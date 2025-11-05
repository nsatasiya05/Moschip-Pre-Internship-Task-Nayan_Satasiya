#include <stdio.h>

// Function to find first location in s1 where any character from s2 occurs
int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
                return i; // return index as soon as match found
        }
    }
    return -1; // no match found
}

int main()
{
    char s1[] = "hello world";
    char s2[] = "ow"; // look for first 'o' or 'w' in s1

    int pos = any(s1, s2);

    if (pos != -1)
        printf("First match at position: %d (character '%c')\n", pos, s1[pos]);
    else
        printf("No character from \"%s\" found in \"%s\"\n", s2, s1);

    return 0;
}
