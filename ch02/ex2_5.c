#include <stdio.h>

int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0'; ++j)
            if (s2[j] == s1[i])
                return i;
    }
    if (s1[i] == '\0')
        return -1;
}

int main(void)
{
    char s1[] = "hello";
    char s2[] = "world";
    printf("%d\n", any(s1, s2));
    printf("%d\n", any("foo", "bar"));
    return 0;
}
