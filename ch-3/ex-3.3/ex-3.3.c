#include <stdio.h>
#include <ctype.h>

/* expand: expands shorthand notations like a-z in s1 into full list in s2 */
void expand(const char s1[], char s2[]) {
    int i, j;
    char c;

    i = j = 0;
    while ((c = s1[i++]) != '\0') {
        if (s1[i] == '-' && s1[i + 1] != '\0') {
            char start = c;
            char end = s1[i + 1];

            // Check for valid range (both are letters or both are digits)
            if ((islower(start) && islower(end)) ||
                (isupper(start) && isupper(end)) ||
                (isdigit(start) && isdigit(end))) {

                for (char k = start; k <= end; k++)
                    s2[j++] = k;
                i += 2;  // Skip over the '-' and end character
                continue;
            }
        }
        // If not a valid range, just copy the character
        s2[j++] = c;
    }
    s2[j] = '\0';
}

int main(void) {
    char s1[100], s2[100];

    printf("Enter a string with shorthand notation (e.g., a-z or A-Z0-9):\n");
    scanf("%99s", s1);

    expand(s1, s2);

    printf("Expanded string:\n%s\n", s2);

    return 0;
}
