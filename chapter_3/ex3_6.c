#include <stdio.h>
#include <string.h>

void reverse(char s[]);

void itoa(int n, char s[], int width)
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < width)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main()
{
    int n = -234;
    char s[10];
    
    itoa(n, s, 8);
    printf("%s\n", s);
    return 0;
}