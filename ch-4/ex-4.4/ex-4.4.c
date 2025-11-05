#include <stdio.h>
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f){ if(sp<MAXVAL) val[sp++]=f; else printf("stack full\n"); }
double pop(void){ return sp>0?val[--sp]:(printf("stack empty\n"),0.0); }
void printTop(void){ if(sp>0) printf("Top: %.8g\n",val[sp-1]); }
void duplicate(void){ if(sp>0 && sp<MAXVAL) val[sp]=val[sp-1],sp++; }
void swap(void){ if(sp>1){ double t=val[sp-1]; val[sp-1]=val[sp-2]; val[sp-2]=t; } }
void clear(void){ sp=0; }

int main(void){
    push(5); push(10); printTop();
    duplicate(); swap(); clear(); printTop();
    return 0;
}
