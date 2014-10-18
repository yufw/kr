#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return ((y & ~(~0 << n)) << (p+1-n)) | (x & ~(~(~0 << n) << (p+1-n)));
}

int main()
{
    unsigned x = 54, y = 14;

    x = setbits(x, 4, 3, y);
    printf("%u\n", x);
    return 0;
}
