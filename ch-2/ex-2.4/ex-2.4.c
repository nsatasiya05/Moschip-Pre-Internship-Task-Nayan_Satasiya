#include <stdio.h>

// Function to delete characters in s1 that appear in s2
void squeeze(char s1[], char s2[]) {
    int i, j, k;
    int found;

    for (i = j = 0; s1[i] != '\0'; i++) {
        found = 0; // assume not found
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                found = 1; // match found, mark it
                break;
            }
        }
        if (!found) // copy only if not found in s2
            s1[j++] = s1[i];
    }
    s1[j] = '\0'; // terminate final string
}

int main() {
    char s1[] = "hello world";
    char s2[] = "ole";

    printf("Before: %s\n", s1);
    squeeze(s1, s2);
    printf("After : %s\n", s1);

    return 0;
}
