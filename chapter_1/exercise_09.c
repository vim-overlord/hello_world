/* Exercise 1-9. Write a program to copy its input to its output, replacing
    each string of one or more blanks by a single blank. */
#include <stdio.h>

#define BLANK 1     /* previous character was a blank */
#define NOTBLANK 0  /* previous character was not a blank */

main()
{
    int c;
    int prev;   /* whether the previous character was a blank */

    prev = NOTBLANK;
    while ((c = getchar()) != EOF) {
        if (prev == NOTBLANK) {
            if (c == ' ') {
                putchar(c);
                prev = BLANK;
            }
            if (c == '\t') {
                putchar(c);
                prev = BLANK;
            }
        }
        if (c != ' ') {
            if (c != '\t') {
                putchar(c);
                prev = NOTBLANK;
            }
        }
    }
}
