#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXVAL 100
int sp=0; double val[MAXVAL];
void push(double f)
        { if(sp<MAXVAL) 
            val[sp++]=f; 
        else
             printf("stack full\n"); }
double pop(void){ return sp>0?val[--sp]:(printf("stack empty\n"),0.0); }

int main(void){
    char s[100]; double op2;
    while(scanf("%s",s)!=EOF){
        switch(s[0]){
        case 's': push(sin(pop())); break;
        case 'e': push(exp(pop())); break;
        case 'p': op2=pop(); push(pow(pop(),op2)); break;
        default: push(atof(s)); break;
        }
    }
    printf("Result: %.8g\n", pop());
    return 0;
}
