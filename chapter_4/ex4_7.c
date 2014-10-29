#include <stdio.h>

#define BUFSIZE 100

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

void ungets(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        ungetch(s[i]);
    }
}

int main()
{
    int c;
    
    ungets("hello, world\n");
    while ((c = getch()) != EOF)
        putchar(c);
    return 0;
}
