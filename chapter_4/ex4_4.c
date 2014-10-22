#include <stdio.h>

#define MAXVAL	100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double top(void)
{
    if (sp > 0)
        return val[sp-1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void duplicate(void)
{
    double t = top();
    push(t);
}

void swap(void)
{
    double op1 = pop();
    double op2 = pop();
    push(op1);
    push(op2);
}

void clear(void)
{
    sp = 0;
}

int main(void)
{
    int i;
    double d;
    
    push(3.5);
    push(4.7);
    printf("%f\n", top());
    swap();
    duplicate();
    for (i = 0; i < 3; i++)
        printf("%f\n", val[i]);
    clear();
    d = pop();
    return 0;
}
