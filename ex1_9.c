#include <stdio.h>

int main(void)
{
    int c, inspace = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
            inspace = 0;
        } else if (inspace == 0) {
            putchar(c);
            inspace = 1;
        }
    }
    return 0;
}
