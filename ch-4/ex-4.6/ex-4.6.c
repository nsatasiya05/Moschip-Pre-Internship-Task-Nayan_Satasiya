#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];
double vars[26];
double last = 0.0;

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Error: stack full\n");
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}

int main(void) {
    char s[100];
    double op2;
    while (scanf("%s", s) != EOF) {
        if (isupper(s[0])) push(vars[s[0] - 'A']);
        else if (s[0] == '=') vars[s[1] - 'A'] = pop();
        else if (s[0] == '+') push(pop() + pop());
        else if (s[0] == '-') { op2 = pop(); push(pop() - op2); }
        else if (s[0] == '*') push(pop() * pop());
        else if (s[0] == '/') { op2 = pop(); if (op2 != 0.0) push(pop() / op2); else printf("Error: zero divisor\n"); }
        else if (s[0] == 'p') printf("Top: %.8g\n", last = pop());
        else push(atof(s));
    }
    return 0;
}
