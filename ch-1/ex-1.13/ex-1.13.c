#include <stdio.h>

#define MAXWORDLEN 15   // maximum word length we care about

int main() {
    int c, i, j, choice;
    int wordlen = 0;
    int wl[MAXWORDLEN + 1];
    int max = 0;

    // Initialize all counts to 0
    for (i = 0; i <= MAXWORDLEN; i++)
        wl[i] = 0;

    printf("Enter text (Ctrl+Z in Windows or Ctrl+D in Linux to end input):\n\n");

    // Read input and count word lengths
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (wordlen > 0) {
                if (wordlen <= MAXWORDLEN)
                    wl[wordlen]++;
                else
                    wl[MAXWORDLEN]++;
                wordlen = 0;
            }
        } else {
            wordlen++;
        }
    }

    // Find maximum frequency for vertical histogram
    for (i = 1; i <= MAXWORDLEN; i++)
        if (wl[i] > max)
            max = wl[i];

    // Ask user choice
    printf("\nChoose Histogram Type:\n");
    printf("1. Horizontal Histogram\n");
    printf("2. Vertical Histogram\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("\n");

    // Horizontal Histogram
    if (choice == 1) {
        printf("Word Length Histogram (Horizontal):\n");
        for (i = 1; i <= MAXWORDLEN; i++) {
            printf("%2d | ", i);
            for (j = 0; j < wl[i]; j++)
                printf("*");
            printf("\n");
        }
    }
    // Vertical Histogram
    else if (choice == 2) {
        printf("Word Length Histogram (Vertical):\n\n");
        for (i = max; i > 0; i--) {
            for (j = 1; j <= MAXWORDLEN; j++) {
                if (wl[j] >= i)
                    printf("  *  ");
                else
                    printf("     ");
            }
            printf("\n");
        }
        for (i = 1; i <= MAXWORDLEN; i++)
            printf(" %2d  ", i);
        printf("\n");
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
