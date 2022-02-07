/* Exercise 1-20. Write a program detab that replaces tabs in the input with
    the proper number of blanks to space to the next tab stop. Assume a fixed
    set of tab stops, say every n columns. Should n be a variable or a symbolic
    parameter? */
#include <stdio.h>

#define TABWIDTH 4  /* columns between tap stops */

/* detab:  replace tabs with spaces */
main()
{
    int c;
    int col;    /* current column */

    col = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            if (col % TABWIDTH == 0) {  /* already at start of tab stop */
                putchar(' ');
                ++col;
            }
            for (; col % TABWIDTH != 0; ++col)
                putchar(' ');
        } else {
            putchar(c);
            ++col;
        }
        if (c == '\n')
            col = 0;
    }
    return 0;
}
