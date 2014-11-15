#include <stdio.h>

int strend(char *s, char *t)
{
    char *s_begin = s;
    char *t_begin = t;

    while (*s)
        s++;
    while (*t)
        t++;
    while (s > s_begin && t > t_begin)
        if (*--s != *--t)
            break;
    if (t == t_begin && *s == *t)
        return 1;
    return 0;
}

int main()
{
    printf("%d\n", strend("hello", "lo"));
    printf("%d\n", strend("", ""));
    printf("%d\n", strend("hello", "wlo"));
    printf("%d\n", strend("lo", "hello"));
    return 0;
}
