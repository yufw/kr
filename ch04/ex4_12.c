#include <stdio.h>

void itoa(int n, char s[])
{
    static int i;
    if (n/10)
        itoa(n/10, s);
    else {
        i = 0;
        if (n < 0)
            s[i++] = '-';            
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}

int main()
{
    char s[10];
    itoa(-123456, s);
    printf("%s\n", s);
    return 0;
}
