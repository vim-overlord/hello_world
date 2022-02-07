/* Exercise 1-21. Write a program entab that replaces strings of blanks by the
    minimum number of tabs and blanks to achieve the same spacing. Use the same
    tab stops as for detab. When either a tab or a single blank would suffice
    to reach a tab stop, which should be given preference? */
#include <stdio.h>

#define TABWIDTH 4  /* columns between tab stops */

/* entab:  replace strings of spaces with tabs */
main()
{
    int c;
    int col;    /* current column */
    int blanks; /* number of consecutive blanks */

    col = blanks = 0;
    while ((c = getchar()) != EOF) {
        while (c == ' ' || c == '\t') {
            /* account for previously skipped single blanks */
            if ((col + blanks) % TABWIDTH == 0 && blanks == 1) {
                putchar('\t');
                ++col;
                blanks = 0;
            }
            ++blanks;
            /* do not print tab character in place of single blank */
            if (((col + blanks) % TABWIDTH == 0 && blanks > 1) || c == '\t') {
                putchar('\t');
                col = col + (TABWIDTH - col % TABWIDTH);
                blanks = 0;
            }
            c = getchar();
        }
        while (blanks > 0) {
            putchar(' ');
            --blanks;
        }
        putchar(c);
        ++col;
        if (c == '\n')
            col = 0;
    }
    return 0;
}
