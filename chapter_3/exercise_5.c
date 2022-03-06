/* Exercise 3-5. Write the function itob(n,s,b) that converts the integer n
    into a base b character representation in the string s. In particular,
    itob(n,s,16) formats n as a hexadecimal integer in s. */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 33   /* maximum input number length */

int my_getline(char s[], int lim);
int atoi(char s[]);
void reverse(char s[]);
void itob(int n, char s[], int b);

/* testing code */
main()
{
    int c, i;
    int base;   /* base number will be converted to */
    char s[MAXLEN];

    printf("Convert to base ");
    for (i = 0; (c = getchar()) != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    base = atoi(s);
    while (my_getline(s, MAXLEN) > 0) {
        itob(atoi(s), s, base);
        printf("%s\n", s);
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

/* atoi:  convert s to integer */
int atoi(char s[])
{
    int i, n;

    n = 0;
    for (i = 0; isdigit(s[i]); ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itob:  convert integer n into base b representation in string s */
void itob(int n, char s[], int b)
{
    int i, sign, digit;

    sign = (n >= 0) ? 1 : -1;
    i = 0;
    do {    /* generate digits in reverse order */
        digit = n % b * sign;
        /* use letters to depict digits greater than 9 */
        s[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'A';
    } while (sign * (n /= b) > 0);
    if (sign == -1)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
