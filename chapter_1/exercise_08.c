/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */
#include <stdio.h>

main()
{
    int c, blanks, tabs, lines;

    blanks = 0;
    tabs = 0;
    lines = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        if (c == '\t')
            ++tabs;
        if (c == '\n')
            ++lines;
    }
    printf("blanks: %d, tabs: %d, lines: %d\n", blanks, tabs, lines);
}
