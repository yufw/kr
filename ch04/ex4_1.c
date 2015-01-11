#include <stdio.h>

int main()
{
    //    int i = strindex("heorlworld", "or");
    int i = strindex("helworldel", "el");
    printf("%d\n", i);
    return 0;
}

int strindex(char s[], char t[])
{
    int i, j, k, final;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            final = i;
    }
    return (final >= 0) ? final : -1;
}
