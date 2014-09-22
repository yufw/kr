#include <stdio.h>

#define IN  1
#define OUT 0
#define MAXLENGTH 20

int main(void)
{
    int c, i, state, length;
    int hist[MAXLENGTH];

    state = OUT;
    length = 0;

    for (i = 0; i < MAXLENGTH; ++i)
        hist[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                ++hist[length-1];
                length = 0;
                state = OUT;
            }
        } else {
            ++length;
            state = IN;
        }
    }

    for (i = 0; i < MAXLENGTH; ++i) {
        if (hist[i] != 0) {
            printf("%2d|", i+1);
            int j;
            for (j = 0; j < hist[i]; ++j)
                putchar('*');
            putchar('\n');
        }            
    }
    return 0;
}
