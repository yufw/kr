#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);

int main()
{
    int length;
    char line[MAXLINE];
    
    while ((length = my_getline(line, MAXLINE)) > 0) {
        int i;
        if (line[length-1] == '\n') {
            for (i = length-2; i >= 0 && (line[i] == ' ' || line[i] == '\t'); i-- ) {
                line[i] = '\n';
            }
            if (i == -1)
                line[0] = '\0';
            else
                line[i+2] = '\0';
        }
        printf("%s", line);
    }
}

int my_getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i; 
}
