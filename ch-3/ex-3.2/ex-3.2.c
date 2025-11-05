#include <stdio.h>

/* escape(s, t): converts special characters in t into visible escape sequences in s */
void escape(char s[], const char t[]) {
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\b':
                s[j++] = '\\';
                s[j++] = 'b';
                break;
            case '\r':
                s[j++] = '\\';
                s[j++] = 'r';
                break;
            case '\f':
                s[j++] = '\\';
                s[j++] = 'f';
                break;
            case '\\':
                s[j++] = '\\';
                s[j++] = '\\';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

/* unescape(s, t): converts visible escape sequences in t into the real characters in s */
void unescape(char s[], const char t[]) {
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++) {
        if (t[i] == '\\') {
            switch (t[++i]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                case 'b':
                    s[j++] = '\b';
                    break;
                case 'r':
                    s[j++] = '\r';
                    break;
                case 'f':
                    s[j++] = '\f';
                    break;
                case '\\':
                    s[j++] = '\\';
                    break;
                default:
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
            }
        } else {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

int main(void) {
    char t[] = "Hello\tWorld!\nThis is a test.\n";
    char s[100], u[100];

    printf("Original string:\n%s\n", t);

    escape(s, t);
    printf("Escaped string:\n%s\n", s);

    unescape(u, s);
    printf("Unescaped string:\n%s\n", u);

    return 0;
}
