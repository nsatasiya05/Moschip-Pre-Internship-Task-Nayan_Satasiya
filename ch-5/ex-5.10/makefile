#include <stdio.h>
#include <stdlib.h>   /* for atof() */
#include <math.h>     /* for fmod() */

#define MAXVAL 100

double val[MAXVAL];
int sp = 0;

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* expr: evaluate reverse Polish expression from command line */
int main(int argc, char *argv[]) {
    double op2;

    if (argc < 2) {
        printf("Usage: expr <expression>\n");
        return 1;
    }

    while (--argc > 0) {
        char *s = *++argv;

        if (*s == '+' && s[1] == '\0')
            push(pop() + pop());
        else if (*s == '*' && s[1] == '\0')
            push(pop() * pop());
        else if (*s == '-' && s[1] == '\0') {
            op2 = pop();
            push(pop() - op2);
        } else if (*s == '/' && s[1] == '\0') {
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
        } else if (*s == '%' && s[1] == '\0') {
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor for %%\n");
        } else
            push(atof(s));
    }

    printf("Result: %.8g\n", pop());
    return 0;
}
