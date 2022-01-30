/* Exercise 1-13. Write a program to print a histogram of the lengths of words
    in its input. It is easy to draw the histogram with the bars horizontal...
*/
#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if ((c == ' ' || c == '\n' || c == '\t') && state == IN) {
            putchar('\n');
            state = OUT;
        } else {
            putchar('-');
            state = IN;
        }
    }
}
