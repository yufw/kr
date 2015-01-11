#include <stdio.h>
#include <stdlib.h>
#include <math.h>               /* compile with -lm */

#define MAXOP	100
#define NUMBER	'0'

int getop(char []);
void push(double);
double pop(void);

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknow command %s\n", s);
            break;
        }
    }
    return 0;
}

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

#include <ctype.h>
#define MAXLINE 100

char line[MAXLINE];
int line_index = 0;

int my_getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int getop(char s[])
{
    int i, c;

    if (line[line_index] == '\0')
        if (my_getline(line, MAXLINE) == 0)
            return EOF;
        else
            line_index = 0;    
    
    while ((s[0] = c = line[line_index++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    i = 0;
    if (c == '-') {
        if (isdigit(c = line[line_index++]) || c == '.')
            s[++i] = c;
        else {
            if (c != EOF)
                line_index--;
            return '-';
        }
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = line[line_index++]))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = line[line_index++]))
            ;
    s[i] = '\0';
    if (c != EOF)
        line_index--;
    return NUMBER;
}
