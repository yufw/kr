#include <stdio.h>

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= x-1)
        b++;
    return b;
}

int main()
{
    unsigned x = 13;

    printf("%d\n", bitcount(x));
    return 0;    
}

