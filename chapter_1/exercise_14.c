/* Exercise 1-14. Write a program to print a histogram of the frequencies of
    different characters in its input. */
#include <stdio.h>

#define SIZE 128    /* number of chars in the ASCII char set */

main()
{
    int c, i, j;
    int freq[SIZE]; /* frequencies of characters */

    for (i = 0; i < SIZE; ++i)
        freq[i] = 0;
    while ((c = getchar()) != EOF)
        ++freq[c];
    /* print the histogram */
    for (i = 0; i < SIZE; ++i) {
        if (freq[i] > 0) {
            if (i == ' ')
                printf("\\ : ");
            else if (i == '\n')
                printf("\\n: ");
            else if (i == '\t')
                printf("\\t: ");
            else if (i == '\\')
                printf("\\\\: ");
            else
                printf("%2c: ", i);
            for (j = 0; j < freq[i]; ++j)
                putchar('-');
            putchar('\n');
        }
    }
}
