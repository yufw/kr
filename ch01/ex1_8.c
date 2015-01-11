#include <stdio.h>

int main(void)
{
    int c;
    int blanks, tabs, newlines;

    blanks = tabs = newlines = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        if (c == '\t')
            ++tabs;
        if (c == '\n')
            ++newlines;
    }
    printf("blanks: %d\n", blanks);
    printf("tabs: %d\n", tabs);
    printf("newlines: %d\n", newlines);

    return 0;
}
