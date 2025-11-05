#include <stdio.h>
#include <string.h>
#include <limits.h>

/* reverse: reverse string s in place */
void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

/* itoa: convert n to characters in s — handles largest negative number correctly */
void itoa(int n, char s[]) {
    int i = 0;
    int sign = n;

    do {
        s[i++] = (char)(abs(n % 10) + '0');
    } while (n /= 10);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

int main(void) {
    char s[50];
    int num = INT_MIN;

    itoa(num, s);
    printf("Number: %d\nString: %s\n", num, s);

    return 0;
}
