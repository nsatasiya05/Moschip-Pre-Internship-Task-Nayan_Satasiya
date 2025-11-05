#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f) { if (sp < MAXVAL) val[sp++] = f; else printf("Error: stack full\n"); }
double pop(void) { return sp > 0 ? val[--sp] : (printf("Error: stack empty\n"), 0.0); }

int main(void) {
    double op2;
    char s[100];
    while (scanf("%s", s) != EOF) {
        switch (s[0]) {
        case '+': push(pop() + pop()); break;
        case '*': push(pop() * pop()); break;
        case '-': op2 = pop(); push(pop() - op2); break;
        case '/': op2 = pop(); push(op2 != 0.0 ? pop() / op2 : (printf("zero divisor\n"), 0.0)); break;
        case '%': op2 = pop(); push(fmod(pop(), op2)); break;
        default: push(atof(s)); break;
        }
    }
    printf("Result: %.8g\n", pop());
    return 0;
}
