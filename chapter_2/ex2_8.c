#include <stdio.h>

unsigned rightrot(unsigned x, int n)
{
    return (x & ~(~0 << n)) << (wordlength() - n) | (x >> n);
}

int wordlength()
{
    int i;
    unsigned x = ~0;

    for (i = 1; x >>= 1; i++)
        ;
    return i;
}

int main()
{
    printf("%d\n", wordlength());
    printf("%u\n", rightrot(141, 3));
    return 0;
}
