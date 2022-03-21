/* Exercise 5-6. Rewrite appropriate programs from earlier chapters and
    exercises with pointers instead of array indexing. Good possibilities
    include getline (Chapters 1 and 4), atoi... */
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000    /* maximum input line length */

int my_getline(char *, int);
double atof(char *);

main()
{
    int len;
    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE)) > 0)
        printf("%f\n%d\n", atof(line), len);
    return 0;
}

/* getline:  get line into s, return length */
int my_getline(char *s, int lim)
{
    int c;
    char *p = s;

    for (; lim > 0 && (c = getchar()) != EOF && c != '\n'; ++s, --lim)
        *s = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - p;
}

/* atof:  convert string s to double */
double atof(char *s)
{
    double val, power;
    int sign;

    while (isspace(*s)) /* skip white space */
        ++s;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        ++s;
    for (val = 0.0; isdigit(*s); ++s)
        val = 10.0 * val + (*s - '0');
    if (*s == '.')
        ++s;
    for (power = 1.0; isdigit(*s); ++s) {
        val = 10.0 * val + (*s - '0');
        power *= 10.0;
    }
    return sign * val / power;
}
