#include <stdio.h>

char buf = 0;

int getch(void)
{
    int c;
    
    if (buf != 0) {
        c = buf;
        buf = 0;
    }
    else
        c = getch();
    return c;
}

void ungetch(int c)
{
    if (buf != 0)
        printf("ungetch: too many characters\n");
    else
        buf = c;
}

int main()
{
    int c;
    
    ungetch('o');
    ungetch('p');
    c = getch();
    putchar(c);
    ungetch('p');
    c = getch();
    putchar(c);
    return 0;
}
