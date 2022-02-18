/* Exercise 2-2. Write a loop equivalent to the for loop above without using &&
    or ||. */
#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

enum boolean { NO, YES };

int my_getline(char line[], int maxline);

/* testing code */
main()
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = my_getline(line, MAXLINE)) > 0) {
        printf("%s", line);
        printf("length: %d\n", len);
    }
    return 0;
}

/* getline:  read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c;
    int i = 0;
    int finished = NO;

    while (!finished) {
        if (i < lim - 1) {
            if ((c = getchar()) != EOF) {
                if (c != '\n') {
                    s[i] = c;
                    ++i;
                } else
                    finished = YES;
            } else
                finished = YES;
        } else
            finished = YES;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
