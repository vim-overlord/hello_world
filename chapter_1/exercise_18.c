/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each
    line of input, and to delete entirely blank lines. */
#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int my_getline(char line[], int maxline);

main()
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = my_getline(line, MAXLINE)) > 0) {
        while (len > 1 && (line[len-2] == ' ' || line[len-2] == '\t')) {
            line[len-1] = '\0';
            line[len-2] = '\n';
            --len;
        }
        if (len > 1)    /* ignore entirely blank lines */
            printf("%s", line);
    }
    return 0;
}

/* getline:  read a line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
