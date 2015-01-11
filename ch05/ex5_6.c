/* getline */
#include <stdio.h>

int my_getline(char *s, int lim)
{
    int c;
    char *t = s;
    
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

/* atoi */
#include <ctype.h>
int atoi(char *s)
{
    int n, sign;

    while (isspace(*s))
        s++;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    for (n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    return sign * n;
}

/* reverse */
#include <string.h>

void reverse(char *s)
{
    int c;
    char *t;

    for (t = s + (strlen(s)-1); s < t; s++, t--) {
        c = *s;
        *s = *t;
        *t = c;
    }
}

/* itoa */
void itoa(int n, char *s)
{
    int sign;
    char *t = s;

    if ((sign = n) < 0)
        n = -n;
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(t);
}

/* strindex */
int strindex(char *s, char *t)
{
    char *b = s;
    char *p, *r;

    for (; *s != '\0'; s++) {
        for (p=s, r=t; *r != '\0' && *p == *r; p++, r++)
            ;
        if (r > t && *r == '\0')
            return s - b;
    }
    return -1;
}

/* getop */
#define NUMBER '0'
int getch(void);
void ungetch(int);

int getop(char *s)
{
    int c;

    while ((*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s+1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    if (isdigit(c))
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.')
        while (isdigit(*++s = c = getch()))
            ;
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;    
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
    char s[80];
    int length = my_getline(s, 10);
    printf("%s", s);
    printf("%d\n", length);

    printf("%d\n", atoi("12"));
    printf("%d\n", atoi("+12"));
    printf("%d\n", atoi("-123"));
    printf("%d\n", atoi("  -12"));

    char t[] = "hello, world";
    reverse(t);
    printf("%s\n", t);

    itoa(-123, t);
    printf("%s\n", t);

    printf("%d\n", strindex("hello", "ll"));

    char p[20];
    getop(p);
    printf("%s\n", p);
    return 0;
}
