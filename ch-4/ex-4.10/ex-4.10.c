#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXVAL 100
#define MAXLINE 1000

int sp = 0;
double val[MAXVAL];

void push(double f) { if (sp < MAXVAL) val[sp++] = f; else printf("stack full\n"); }
double pop(void) { return (sp > 0) ? val[--sp] : (printf("stack empty\n"), 0.0); }

int main(void) {
    char line[MAXLINE];
    double op2;
    while (fgets(line, MAXLINE, stdin) != NULL) {
        if (line[0] == '+') push(pop() + pop());
        else if (line[0] == '-') { op2 = pop(); push(pop() - op2); }
        else if (line[0] == '*') push(pop() * pop());
        else if (line[0] == '/') { op2 = pop(); if (op2 != 0.0) push(pop() / op2); else printf("zero divisor\n"); }
        else push(atof(line));
    }
    printf("Result: %.8g\n", pop());
    return 0;
}
