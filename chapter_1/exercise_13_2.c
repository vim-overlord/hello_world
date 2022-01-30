/* Exercise 1-13. Write a program to print a histogram of the lengths of words
    in its input... a vertical orientation is more challenging. */
#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */
#define MAX 100 /* maximum number of words */

main()
{
    int c, i, state;
    int longest;    /* longest word length */
    int len[MAX];   /* lengths of words */

    for (i = 0; i < MAX; ++i)
        len[i] = 0;
    i = -1;
    state = OUT;
    longest = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (i >= 0 && len[i] > longest)
                longest = len[i];
            state = OUT;
        } else if (state == OUT) {
            ++i;
            state = IN;
        }
        if (state == IN)
            ++len[i];
    }
    /* print the histogram */
    while (longest > 0) {
        for (i = 0; len[i] > 0; ++i) {
            if (len[i] >= longest)
                putchar('|');
            else
                putchar(' ');
        }
        putchar('\n');
        --longest;
    }
}
