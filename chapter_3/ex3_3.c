#include <stdio.h>

void expand(char s1[], char s2[])
{
    int c;
    int i, j;

    i = j = 0;
    while ((c = s1[i++]) != '\0') {
        if (s1[i] == '-' && s1[i+1] > c) {
            while ((s2[j++] = c++) < s1[i+1])
                ;
            i += 2;
        } else
            s2[j++] = c;
    }
    s2[j] = '\0';
}

int main()
{
    char s1[] = "helloa-z0-9";
    char s2[1000];

    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}
