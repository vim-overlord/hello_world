/* Exercise 1-12. Write a program that prints its input one word per line. */
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
            putchar(c);
            state = IN;
        }
    }
}
