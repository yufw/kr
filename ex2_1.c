#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("Minimum value of signed char: %d\n", SCHAR_MIN);
    printf("Maximum value of signed char: %d\n", SCHAR_MAX);
    printf("Maximum value of unsigned char: %u\n", UCHAR_MAX);

    printf("Minimum value of signed short: %d\n", SHRT_MIN);
    printf("Maximum value of signed short: %d\n", SHRT_MAX);
    printf("Maximum value of unsigned short: %u\n", USHRT_MAX);

    printf("Minimum value of signed int: %d\n", INT_MIN);
    printf("Maximum value of signed int: %d\n", INT_MAX);
    printf("Maximum value of unsigned int: %u\n", UINT_MAX);

    printf("Minimum value of signed long: %ld\n", LONG_MIN);
    printf("Maximum value of signed long: %ld\n", LONG_MAX);
    printf("Maximum value of unsigned long: %lu\n", ULONG_MAX);

    /* determine the range by direct computation, type char only. */
    unsigned char c;
    c = ~0;
    c >>= 1;
    printf("%d\n", -c-1);
    printf("%d\n", c);
    printf("%u\n", 2*c + 1);
    return 0;
}
