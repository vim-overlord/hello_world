/* Exercise 4-2. Extend atof to handle scientific notation of the form
    123.45e-6 where a floating-point number may be followed by e or E and an
    optionally signed exponent. */
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000    /* maximum input line length */

int my_getline(char line[], int max);
double atof(char s[]);

/* testing code */
main()
{
    char line[MAXLINE];

    my_getline(line, MAXLINE);
    printf("%f\n", atof(line));
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

/* atof:  convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign, exp, exp_sign;

    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (tolower(s[i]) == 'e') {
        ++i;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            ++i;
        for (exp = 0; isdigit(s[i]); ++i)
            exp = 10 * exp + (s[i] - '0');
        exp *= exp_sign;
        for (; exp < 0; ++exp)
            power *= 10.0;
        for (; exp > 0; --exp)
            power /= 10.0;
    }
    return sign * val / power;
}
