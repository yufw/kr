#include <stdio.h>

#define swap(t, x, y) {                         \
        t _z;                                   \
        _z = y;                                 \
        y = x;                                  \
        x = _z;                                 \
    }

int main()
{
    int x = 3, y = 4;
    swap(int, x, y);
    printf("%d\t%d\n", x, y);
    return 0;
}
