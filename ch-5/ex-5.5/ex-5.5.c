#include <stdio.h>

void my_strncpy(char *s, const char *t, int n);
void my_strncat(char *s, const char *t, int n);
int my_strncmp(const char *s, const char *t, int n);

int main() {
    char s1[100] = "Hello";
    char s2[100] = "World";
    char s3[100] = "HelloEarth";

    my_strncpy(s1, s2, 3);
    printf("After strncpy: %s\n", s1);

    my_strncat(s1, s2, 2);
    printf("After strncat: %s\n", s1);

    printf("strncmp result: %d\n", my_strncmp(s1, s3, 5));
    return 0;
}

void my_strncpy(char *s, const char *t, int n) {
    while (n-- > 0 && (*s++ = *t++))
        ;
    if (n >= 0)
        *s = '\0';
}

void my_strncat(char *s, const char *t, int n) {
    while (*s)
        s++;
    while (n-- > 0 && (*s++ = *t++))
        ;
    *s = '\0';
}

int my_strncmp(const char *s, const char *t, int n) {
    for (; n > 0; s++, t++, n--)
        if (*s != *t || *s == '\0' || *t == '\0')
            return *s - *t;
    return 0;
}
