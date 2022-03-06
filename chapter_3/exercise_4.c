/* Exercise 3-4. In a two’s complement number representation, our version of
    itoa does not handle the largest negative number, that is, the value of n
    equal to −(2^(wordsize−1)). Explain why not. Modify it to print that value
    correctly, regardless of the machine on which it runs. */
#include <stdio.h>
#include <limits.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[]);

/* testing code */
main()
{
    char s[12];

    itoa(INT_MIN, s);
    printf("%s\n", s);
    return 0;
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
void itoa(int n, char s[])
{
    int i, sign;

    sign = (n >= 0) ? 1 : -1;
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 * sign + '0';   /* get next digit */
    } while (sign * (n /= 10) > 0);     /* delete it */
    if (sign == -1)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
