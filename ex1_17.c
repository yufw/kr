#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);

int main(void)
{
    int length;
    char line[MAXLINE];
    length = getline(line, MAXLINE);
    if (length > 10) {
        printf("%s", line);
    }
    return 0;
}

int getline(char line[], int maxline)
{
    int c, i;

    for (i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
