/* Exercise 3-6. Write a version of itoa that accepts three arguments instead
    of two. The third argument is a minimum field width; the converted number
    must be padded with blanks on the left if necessary to make it wide enough.
    */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 33   /* maximum input number length */

int my_getline(char s[], int lim);
int atoi(char s[]);
void reverse(char s[]);
void itoa(int n, char s[], int min);

/* testing code */
main()
{
    int c, i;
    int min;    /* minimum field width */
    char s[MAXLEN];

    printf("Enter the minimum field width: ");
    for (i = 0; (c = getchar()) != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    min = atoi(s);
    while (my_getline(s, MAXLEN) > 0) {
        itoa(atoi(s), s, min);
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

/* itoa:  convert n to characters in s */
void itoa(int n, char s[], int min)
{
    int i, sign;

    sign = (n >= 0) ? 1 : -1;
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 * sign + '0';   /* get next digit */
    } while (sign * (n /= 10) > 0);     /* delete it */
    if (sign == -1)
        s[i++] = '-';
    for (; i < min; ++i)
        s[i] = ' ';
    s[i] = '\0';
    reverse(s);
}
