/* Exercise 5-6. Rewrite appropriate programs from earlier chapters and
    exercises with pointers instead of array indexing. Good possibilities
    include... strindex... (Chapter 4). */
#include <stdio.h>
#define MAXLINE 1000    /* maximum input line length */

int my_getline(char line[], int max);
int strindex(char *source, char *searchfor);

char pattern[] = "ould";    /* pattern to search for */

/* find all lines matching pattern */
main()
{
    char line[MAXLINE];
    int index, found = 0;

    while (my_getline(line, MAXLINE) > 0)
        if ((index = strindex(line, pattern)) >= 0) {
            printf("%s%d\n", line, index);
            found++;
        }
    return found;
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

/* strindex:  return index of t in s, -1 if none */
int strindex(char *s, char *t)
{
    char *p;
    char *sp = s;
    char *tp = t;

    for (; *s != '\0'; ++s, t = tp) {
        for (p = s; *t != '\0' && *p == *t; ++p, ++t)
            ;
        if (*t == '\0')
            return s - sp;
    }
    return -1;
}
