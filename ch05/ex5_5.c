#include <stdio.h>

void my_strncpy(char *s, char *t, int n)
{
    while (n-- > 0 && *t)
        *s++ = *t++;
    while (n-- > 0)
        *s++ = '\0';        
}

void my_strncat(char *s, char *t, int n)
{
    while (*s)
        s++;
    while (n-- > 0 && *t)
        *s++ = *t++;
    *s = '\0';
}

int my_strncmp(char *s, char *t, int n)
{
    while (n-- > 0 && *s) {
        if (*s != *t)
            break;
        s++;
        t++;
    }
    if (n == -1 || *s == '\0')
        return 0;
    return *s - *t;
}

int main()
{
    char s1[80];
    char *t1 = "helloworld";
    my_strncpy(s1, t1, 7);
    printf("%s\n", s1);

    char s2[80] = "good";
    char *t2 = "helloworld";
    my_strncat(s2, t2, 6);
    printf("%s\n", s2);    

    printf("%d\n", my_strncmp("hela", "hello", 3));
    printf("%d\n", my_strncmp("hela", "hello", 4));
    printf("%d\n", my_strncmp("hell", "hello", 5));
    printf("%d\n", my_strncmp("abcd", "bcdef", 2));
    
    return 0;
}
