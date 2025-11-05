#include <stdio.h>
#define MAXLINE 1000

int getline_custom(char s[], int lim);
void remove_trailing(char s[]);

int main() {
    char line[MAXLINE];
    while (getline_custom(line, MAXLINE) > 0) {
        remove_trailing(line);
        if (line[0] != '\0')
            printf("%s\n", line);
    }
    return 0;
}

/* Read a line */
int getline_custom(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    return i;
}

/* Remove trailing blanks and tabs */
void remove_trailing(char s[]) {
    int i = 0;
    while (s[i] != '\0')
        ++i;
    --i;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;
    s[i + 1] = '\0';
}
