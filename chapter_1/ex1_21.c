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

int main()
{
    char line[MAXLINE];
    int i, j, k;
    int space_depth;
    int len;

    while ((len = my_getline(line, MAXLINE)) > 0) {
        j = 0;
        space_depth = 0;
        
        for (i = 0; i < len; i++) {
            if (line[i] == ' ') {
                j++;
                space_depth += 1;
                if (j % TABSIZE == 0) {
                    putchar('\t');
                    space_depth = 0;
                }
            } else if (line[i] = '\t') {
                space_depth = 0;
                j = j + (4 - j%TABSIZE);
                putchar(line[i]);
            } else {
                for (k = 0; k < space_depth; k++)
                    putchar(' ');
                space_depth = 0;
                j++;
                putchar(line[i]);
            }
        }
    }
    return 0;
}
