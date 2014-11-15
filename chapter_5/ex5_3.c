#include <stdio.h>

void my_strcat(char *s, char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}

int main()
{
    char s[80] = "hello";
    char t[80] = "world";
    my_strcat(s, t);
    printf("%s\n", s);
    return 0;
}
