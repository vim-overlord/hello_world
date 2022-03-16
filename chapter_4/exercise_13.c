/* Exercise 4-13. Write a recursive version of the function reverse(s), which
    reverses the string s in place. */
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000    /* maximum input line size */

int my_getline(char line[], int maxline);
void reverse(char s[]);

main()
{
    char line[MAXLINE];

    while (my_getline(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s\n", line);
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

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int c, j;
    static int i = 0;

    j = strlen(s)-1-i;
    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        ++i;
        reverse(s);
    }
}
