#include <stdio.h>
#include <ctype.h>  // for tolower()

// Function to convert hexadecimal string to integer
int htoi(char s[]) {
    int i = 0, n = 0;
    int value;

    // Skip optional '0x' or '0X' prefix
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;

    for (; s[i] != '\0'; i++) {
        char c = tolower(s[i]); // handle both 'A-F' and 'a-f'

        if (c >= '0' && c <= '9')
            value = c - '0';
        else if (c >= 'a' && c <= 'f')
            value = 10 + (c - 'a');
        else
            break; // stop if invalid character

        n = 16 * n + value;
    }

    return n;
}

int main() {
    char hex1[] = "0x2F";
    char hex2[] = "7B";
    char hex3[] = "0X10A";

    printf("%s = %d\n", hex1, htoi(hex1));
    printf("%s = %d\n", hex2, htoi(hex2));
    printf("%s = %d\n", hex3, htoi(hex3));

    return 0;
}
