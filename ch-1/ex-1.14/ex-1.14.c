#include <stdio.h>

int main() {
    int c, i;
    int freq[256];  // Array to hold frequency of all ASCII characters

    // Initialize all frequencies to 0
    for (i = 0; i < 256; ++i)
        freq[i] = 0;

    // Read characters until EOF and count them
    while ((c = getchar()) != EOF)
        ++freq[c];

    printf("\nCharacter Frequency Histogram:\n");
    printf("--------------------------------\n");

    // Print histogram for printable characters
    for (i = 32; i < 127; ++i) {  // Printable ASCII range
        if (freq[i] > 0) {
            printf("%c | ", i);
            for (int j = 0; j < freq[i]; ++j)
                printf("*");
            printf(" (%d)\n", freq[i]); // show count
        }
    }

    return 0;
}
