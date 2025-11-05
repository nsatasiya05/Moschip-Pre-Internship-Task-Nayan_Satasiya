#include <stdio.h>
#include <string.h>

void reverse(char *s);

int main() {
    char str[] = "Hello, Pointer World!";
    reverse(str);
    printf("Reversed string: %s\n", str);
    return 0;
}

void reverse(char *s) {
    char *t;
    char temp;

    for (t = s + strlen(s) - 1; s < t; s++, t--) {
        temp = *s;
        *s = *t;
        *t = temp;
    }
}
