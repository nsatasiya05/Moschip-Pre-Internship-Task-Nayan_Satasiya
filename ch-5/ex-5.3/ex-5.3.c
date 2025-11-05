#include <stdio.h>

void my_strcat(char *s, char *t);

int main() {
    char s[100] = "Hello";
    char t[] = " World!";
    my_strcat(s, t);
    printf("Concatenated string: %s\n", s);
    return 0;
}

void my_strcat(char *s, char *t) {
    while (*s)      // Move s to end of the first string
        s++;
    while ((*s++ = *t++))   // Copy t to end of s
        ;
}
