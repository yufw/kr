#include <stdio.h>

int main(void)
{
    int freq[256];
    int c, i, j;

    for (i = 0; i < 256; ++i)
        freq[i] = 0;
    
    while ((c = getchar()) != EOF) {
        ++freq[c];
    }

    for (i = 0; i < 256; ++i) {
        if (freq[i] != 0) {
            printf("%3d|", i);
            for (j = 0; j < freq[i]; ++j)
                putchar('*');
            putchar('\n');
        }
    }
    return 0;
}
