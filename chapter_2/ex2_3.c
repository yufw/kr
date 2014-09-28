#include <stdio.h>

int hexval(char c)
{
    if (c >= '0'&& c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'f')
        return 10 + c - 'a';
    else if (c >= 'A' && c <= 'F')
        return 10 + c - 'A';
}

int htoi(char s[])
{
    int i, n;

    i = 0;
    if (s[i] == '0') {
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
            ++i;
    }
    n = 0;
    for ( ; s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'f' || s[i] >= 'A' && s[i] <= 'F'; ++i)
        n = n * 16 + hexval(s[i]);

    return n;
}

int main(void)
{
    printf("%d\n", htoi("0xfa"));
    return 0;
}
