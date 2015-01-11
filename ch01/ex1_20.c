#include <stdio.h>

#define MAXLINE 1000
#define TABSIZE 3

int my_getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int tab_to_spaces(int offset, int tabsize)
{
    return tabsize - (offset % tabsize);
}

int main()
{
    char line[MAXLINE];
    int i, j, k, l;

    while (my_getline(line, MAXLINE) > 0) {
        for (i = 0, j = 0; line[i] != '\0'; i++) {
            if (line[i] == '\t') {
                k = tab_to_spaces(j, TABSIZE);
                for (l = 0; l < k; l++) {
                    putchar(' ');
                    j++;
                }
            } else {
                putchar(line[i]);
                j++;
            }
        }
    }
    return 0;
}
