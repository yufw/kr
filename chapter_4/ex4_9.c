#include <stdio.h>

#define BUFSIZE 100

int buf[BUFSIZE];               /* use int instead of char */
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
    int i;
    
    ungetch(EOF);
    i = getch();
    printf("%d\n", i);
    return 0;
}
