#include <stdio.h>
#define MAXLINE 10

int my_getline(char line[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

void reverse(char line[], int len)
{
    int i, j, temp;

    if (line[len-1] == '\n') {
        for (i=0, j=len-2; i < j; i++, j-- ) {
            temp = line[i];
            line[i] = line[j];
            line[j] = temp;
        }
    } else {
        for (i=0, j=len-1; i < j; i++, j-- ) {
            temp = line[i];
            line[i] = line[j];
            line[j] = temp;
        }
    }
    return;
}

int main()
{
    char line[MAXLINE];
    int len;
    
    while ((len=my_getline(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s", line);
    }
    return 0;
}
