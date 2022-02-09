/* Exercise 1-22. Write a program to “fold” long input lines into two or more
    shorter lines after the last non-blank character that occurs before the
    n-th column of input. Make sure your program does something intelligent
    with very long lines, and if there are no blanks or tabs before the
    specified column. */
#include <stdio.h>

#define MAXLEN 80   /* column limit for output lines */
#define TABWIDTH 4  /* indent size */

main()
{
    int c;
    int col;                /* current column */
    char word[MAXLEN + 1];  /* current word */
    int len;                /* current word length */

    col = 0;
    c = getchar();
    while (c != EOF) {
        for (len = 0; c != ' ' && c != '\t' && c != '\n' && len < MAXLEN;
            ++len) {
            word[len] = c;
            c = getchar();
        }
        word[len] = '\0';
        if (col + len > MAXLEN) {
            putchar('\n');
            col = 0;
        }
        printf("%s", word);
        col = col + len;
        for (len = 0; (c == ' ' || c == '\t') && col <= MAXLEN; ++len) {
            if (c == ' ')
                ++col;
            else if (c == '\t')
                col = col + (TABWIDTH - col % TABWIDTH);
            putchar(c);
            c = getchar();
        }
        if (col > MAXLEN || c == '\n') {
            /* read in remaining whitespace if column limit is reached */
            while (c == ' ' || c == '\t')
                c = getchar();
            putchar('\n');
            col = 0;
            if (c == '\n')
                c = getchar();  /* c carries over to next iteration */
        }
    }
    return 0;
}
