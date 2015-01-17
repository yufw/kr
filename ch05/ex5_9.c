#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int i, leap;
    char *p;
    
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = daytab[leap];
    while (--month)
        day += *++p;
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    char *p;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = daytab[leap];
    while (yearday > *++p)
        yearday -= *p;
    *pmonth = p - daytab[leap];
    *pday = yearday;
}

int main()
{
    int x, pm, pd;

    x = day_of_year(2015, 3, 1);
    printf("%d\n", x);
    x = day_of_year(2012, 3, 1);
    printf("%d\n", x);

    month_day(2015, 60, &pm, &pd);
    printf("%d %d\n", pm, pd);
    month_day(2012, 60, &pm, &pd);
    printf("%d %d\n", pm, pd);
    
    return 0;
}
