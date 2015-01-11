/* This program can not handle quotes and comments correctly. */

#include <stdio.h>

#define MAXLINE 1000

char line[MAXLINE];
int my_getline(void);

int main()
{
    int len = 0;
    int t = 0;
    int brace = 0, bracket = 0, parenthesis = 0;
    int s_quote = 1, d_quote = 1;

    while ((len = my_getline()) > 0) {
        t = 0;
        while (t < len) {
            if (line[t] == '[')
                brace++;
            if (line[t] == ']')
                brace--;
            if (line[t] == '(')
                parenthesis++;
            if (line[t] == ')')
                parenthesis--;
            if (line[t] == '\'')
                s_quote *= -1;
            if (line[t] == '"')
                d_quote *= -1;
            t++;
        }
    }
    if (d_quote != 1)
        printf("unbalanced double quotes\n");
    if (s_quote != 1)
        printf("unbalanced single quotes\n");
    if (brace != 0)
        printf("unbalanced braces\n");
    if (bracket != 0)
        printf("unbalanced brackets\n");
    if (parenthesis != 0)
        printf("unbalanced parenthesis");
    return 0;
}

int my_getline(void)
{
    int c, i;
    extern char line[];

    for (i = 0; i < MAXLINE-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
