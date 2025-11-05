#include <stdio.h>
#include <string.h>

/* reverse string in place */
void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

/* itob: convert integer n into base b representation in string s */
void itob(int n, char s[], int b) {
    int i = 0;
    int sign = n;

    if (n < 0)
        n = -n;

    do {
        int digit = n % b;
        s[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'A';
    } while ((n /= b) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

int main(void) {
    char s[50];
    int num, base;

    printf("Enter number and base (2-16): ");
    scanf("%d %d", &num, &base);

    itob(num, s, base);
    printf("Number %d in base %d: %s\n", num, base, s);

    return 0;
}
