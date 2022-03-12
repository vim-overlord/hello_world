/* Exercise 4-1. Write the function strrindex(s,t), which returns the position
    of the rightmost occurrence of t in s, or −1 if there is none. */
#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int my_getline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";    /* pattern to search for */

/* testing code */
main()
{
    char line[MAXLINE];

    while (my_getline(line, MAXLINE) > 0)
        printf("%d\n", strrindex(line, pattern));
    return 0;
}

/* getline:  get line into s, return length */
int my_getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strrindex:  return rightmost index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
        ;
    while (--i >= 0) {
        for (j=i, k=0; s[j]!='\0' && t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
