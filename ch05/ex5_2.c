#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getfloat(double *pn)
{
    int c, sign, power;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return c;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
        power *= 10;
    }
    *pn = *pn / power * sign;
    if (c != EOF)
        ungetch(c);
    return c;    
}

#define BUFSIZE	100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int main()
{
    double a;
    getfloat(&a);
    printf("%g\n", a);
    return 0;
}
