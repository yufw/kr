#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p+1-n));
}

int main()
{
    unsigned x = 54;
    
    printf("%u\n", invert(x, 4, 3));
    return 0;
}
