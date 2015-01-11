#include <stdio.h>

void escape(char s[], char t[])
{
    int i, j;
    int c;

    i = j = 0;
    while ((c = t[i++]) != '\0') {
        switch (c) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = c;
            break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[])
{
    int i, j;
    int c;

    i = j = 0;
    while ((c = t[i++]) != '\0') {
        if (c == '\\') {
            switch (t[i++]) {
            case 'n':
                s[j++] = '\n';
                break;
            case 't':
                s[j++] = '\t';
                break;
            default:
                s[j++] = c;
                s[j++] = t[i];
                break;
            }
        } else {
            s[j++] = c;
        }
            
    }
    s[j] = '\0';
}

int main(void)
{
    char s[20];
    char t[] = "h\neworld";
    escape(s, t);
    printf("%s\n", s);
    char t2[] = "h\\nworld";
    unescape(s, t2);
    printf("%s\n", s);
    return 0;
}
