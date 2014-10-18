#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low+high) / 2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid]) 
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (x == v[mid])
        return mid;
    else
        return -1;
}

int main()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int x = binsearch(3, v, 8);
    printf("%d\n", x);
    return 0;    
}
