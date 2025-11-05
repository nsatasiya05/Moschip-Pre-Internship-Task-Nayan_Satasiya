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

/* itoa: convert n to string s, pad with spaces to width w */
void itoa(int n, char s[], int w) {
    int i = 0, sign = n;

    if (n < 0)
        n = -n;

    do {
        s[i++] = (char)(n % 10 + '0');
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    while (i < w)  // pad with spaces
        s[i++] = ' ';

    s[i] = '\0';
    reverse(s);
}

int main(void) {
    char s[50];
    int num, width;

    printf("Enter number and minimum field width: ");
    scanf("%d %d", &num, &width);

    itoa(num, s, width);
    printf("Result: '%s'\n", s);

    return 0;
}
