/* Exercise 2-3. Write the function htoi(s), which converts a string of
    hexadecimal digits (including an optional 0x or 0X) into its equivalent
    integer value. The allowable digits are 0 through 9, a through f, and A
    through F. */
#include <stdio.h>
#include <ctype.h>

#define MAXLEN 11   /* maximum number length */

int my_getline(char line[], int maxline);
int htoi(char s[]);

/* testing code */
main()
{
    int c, i;
    char digits[MAXLEN];    /* string of hex digits */

    while (my_getline(digits, MAXLEN) > 0)
        printf("%d\n", htoi(digits));
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

/* htoi:  convert a string of hex digits into an int */
int htoi(char s[])
{
    int i, n;

    for (i = n = 0; (s[i] = tolower(s[i])) != '\0'; ++i) {
        if (isdigit(s[i]))
            n = 16 * n + (s[i] - '0');
        else if (s[i] >= 'a' && s[i] <= 'f')
            n = 16 * n + (s[i] - 'a' + 10);
    }
    if (s[0] == '-')
        return -n;
    else
        return n;
}
